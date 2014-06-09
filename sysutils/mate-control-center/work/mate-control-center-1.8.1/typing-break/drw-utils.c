/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 * Copyright (C) 2003 Richard Hult <richard@imendio.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <config.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>
#include "drw-utils.h"

static GdkPixbuf *
create_tile_pixbuf (GdkPixbuf    *dest_pixbuf,
		    GdkPixbuf    *src_pixbuf,
		    GdkRectangle *field_geom,
		    guint         alpha,
		    GdkColor     *bg_color) 
{
	gboolean need_composite;
	gboolean use_simple;
	gdouble  cx, cy;
	gdouble  colorv;
	gint     pwidth, pheight;

	need_composite = (alpha < 255 || gdk_pixbuf_get_has_alpha (src_pixbuf));
	use_simple = (dest_pixbuf == NULL);

	if (dest_pixbuf == NULL)
		dest_pixbuf = gdk_pixbuf_new (GDK_COLORSPACE_RGB,
					      FALSE, 8,
					      field_geom->width, field_geom->height);

	if (need_composite && use_simple)
		colorv = ((bg_color->red & 0xff00) << 8) |
			(bg_color->green & 0xff00) |
			((bg_color->blue & 0xff00) >> 8);
	else
		colorv = 0;

	pwidth = gdk_pixbuf_get_width (src_pixbuf);
	pheight = gdk_pixbuf_get_height (src_pixbuf);

	for (cy = 0; cy < field_geom->height; cy += pheight) {
		for (cx = 0; cx < field_geom->width; cx += pwidth) {
			if (need_composite && !use_simple)
				gdk_pixbuf_composite (src_pixbuf, dest_pixbuf,
						      cx, cy,
						      MIN (pwidth, field_geom->width - cx), 
						      MIN (pheight, field_geom->height - cy),
						      cx, cy,
						      1.0, 1.0,
						      GDK_INTERP_BILINEAR,
						      alpha);
			else if (need_composite && use_simple)
				gdk_pixbuf_composite_color (src_pixbuf, dest_pixbuf,
							    cx, cy,
							    MIN (pwidth, field_geom->width - cx), 
							    MIN (pheight, field_geom->height - cy),
							    cx, cy,
							    1.0, 1.0,
							    GDK_INTERP_BILINEAR,
							    alpha,
							    65536, 65536, 65536,
							    colorv, colorv);
			else
				gdk_pixbuf_copy_area (src_pixbuf,
						      0, 0,
						      MIN (pwidth, field_geom->width - cx),
						      MIN (pheight, field_geom->height - cy),
						      dest_pixbuf,
						      cx, cy);
		}
	}

	return dest_pixbuf;
}

static gboolean
#if GTK_CHECK_VERSION (3, 0, 0)
window_draw_event   (GtkWidget      *widget,
		     cairo_t        *cr,
#else
window_expose_event (GtkWidget      *widget,
		     GdkEventExpose *event,
#endif
		     gpointer        data)
{
#if !GTK_CHECK_VERSION (3, 0, 0)
	cairo_t         *context;
	cairo_t         *cr;
	cairo_surface_t *surface;
#endif
	int              width;
	int              height;

	gtk_window_get_size (GTK_WINDOW (widget), &width, &height);

#if !GTK_CHECK_VERSION (3, 0, 0)
	context = gdk_cairo_create (gtk_widget_get_window (widget));

	cairo_set_operator (context, CAIRO_OPERATOR_SOURCE);

	surface = cairo_surface_create_similar (cairo_get_target (context),
						CAIRO_CONTENT_COLOR_ALPHA,
						width,
						height);

	if (cairo_surface_status (surface) != CAIRO_STATUS_SUCCESS) {
		goto done;
	}

	cr = cairo_create (surface);
	if (cairo_status (cr) != CAIRO_STATUS_SUCCESS) {
		goto done;
	}
#endif
	cairo_set_source_rgba (cr, 1.0, 1.0, 1.0, 0.0);
	cairo_set_operator (cr, CAIRO_OPERATOR_OVER);
	cairo_paint (cr);

	/* draw a box */
	cairo_rectangle (cr, 0, 0, width, height);
	cairo_set_source_rgba (cr, 0.2, 0.2, 0.2, 0.5);
	cairo_fill (cr);

#if !GTK_CHECK_VERSION (3, 0, 0)
	cairo_destroy (cr);

	cairo_set_source_surface (context, surface, 0, 0);
	cairo_paint (context);
 done:
	if (surface != NULL) {
		cairo_surface_destroy (surface);
	}
	cairo_destroy (context);
#endif

	return FALSE;
}

static void
set_pixmap_background (GtkWidget *window)
{
	GdkScreen    *screen;
	GdkPixbuf    *tmp_pixbuf, *pixbuf, *tile_pixbuf;
#if GTK_CHECK_VERSION (3, 0, 0)
	cairo_t      *cr;
#else
	GdkPixmap    *pixmap;
#endif
	GdkRectangle  rect;
	GdkColor      color;
	gint          width, height;

	gtk_widget_realize (window);

	screen = gtk_widget_get_screen (window);
	width = gdk_screen_get_width (screen);
	height = gdk_screen_get_height (screen);

#if GTK_CHECK_VERSION (3, 0, 0)
	tmp_pixbuf = gdk_pixbuf_get_from_window (gdk_screen_get_root_window (screen),
						 0,
						 0,
						 width, height);
#else
	tmp_pixbuf = gdk_pixbuf_get_from_drawable (NULL,
						   gdk_screen_get_root_window (screen),
						   gdk_screen_get_system_colormap (screen),
						   0,
						   0,
						   0,
						   0,
						   width, height);
#endif

	pixbuf = gdk_pixbuf_new_from_file (IMAGEDIR "/ocean-stripes.png", NULL);

	rect.x = 0;
	rect.y = 0;
	rect.width = width;
	rect.height = height;

	color.red = 0;
	color.blue = 0;
	color.green = 0;

	tile_pixbuf = create_tile_pixbuf (NULL,
					  pixbuf,
					  &rect,
					  155,
					  &color);

	g_object_unref (pixbuf);

	gdk_pixbuf_composite (tile_pixbuf,
			      tmp_pixbuf,
			      0,
			      0,
			      width,
			      height,
			      0,
			      0,
			      1,
			      1,
			      GDK_INTERP_NEAREST,
			      225);

	g_object_unref (tile_pixbuf);

#if GTK_CHECK_VERSION (3, 0, 0)
	cr = gdk_cairo_create (gtk_widget_get_window (window));
	gdk_cairo_set_source_pixbuf (cr, tmp_pixbuf, 0, 0);
	cairo_paint (cr);
#else
	pixmap = gdk_pixmap_new (gtk_widget_get_window (window),
				 width,
				 height,
				 -1);

	gdk_draw_pixbuf (pixmap,
                         NULL, 
                         tmp_pixbuf,
                         0,
                         0,
                         0,
                         0,
                         width,
                         height,
                         GDK_RGB_DITHER_NONE,
                         0,
                         0);
#endif

	g_object_unref (tmp_pixbuf);

#if GTK_CHECK_VERSION (3, 0, 0)
	cairo_destroy (cr);
#else
	gdk_window_set_back_pixmap (gtk_widget_get_window (window), pixmap, FALSE);
	g_object_unref (pixmap);
#endif
}

void
drw_setup_background (GtkWidget *window)
{
	GdkScreen    *screen;
#if !GTK_CHECK_VERSION (3, 0, 0)
	GdkColormap  *colormap;
#endif
	gboolean      is_composited;

	screen = gtk_widget_get_screen (window);
#if GTK_CHECK_VERSION (3, 0, 0)
	is_composited = gdk_screen_is_composited (screen);
#else
	colormap = gdk_screen_get_rgba_colormap (screen);

	if (colormap != NULL && gdk_screen_is_composited (screen)) {
		gtk_widget_set_colormap (GTK_WIDGET (window), colormap);
		is_composited = TRUE;
	} else {
		is_composited = FALSE;
	}
#endif

	if (is_composited) {
#if GTK_CHECK_VERSION (3, 0, 0)
		g_signal_connect (window, "draw", G_CALLBACK (window_draw_event), window);
#else
		g_signal_connect (window, "expose-event", G_CALLBACK (window_expose_event), window);
#endif
	} else {
		set_pixmap_background (window);
	}
}

