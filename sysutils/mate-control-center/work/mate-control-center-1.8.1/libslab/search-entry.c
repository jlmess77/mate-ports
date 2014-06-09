/*
 * This file is part of libslab.
 *
 * Copyright (c) 2006 Novell, Inc.
 *
 * Libslab is free software; you can redistribute it and/or modify it under the
 * terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * Libslab is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libslab; if not, write to the Free Software Foundation, Inc., 51
 * Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "search-entry.h"
#include "search-entry-watermark.h"

#include <librsvg/rsvg.h>
#include <string.h>

typedef struct
{
	GdkPixbuf *watermark;
	int width, height;
} NldSearchEntryPrivate;

#define NLD_SEARCH_ENTRY_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), NLD_TYPE_SEARCH_ENTRY, NldSearchEntryPrivate))

static void nld_search_entry_class_init (NldSearchEntryClass *);
static void nld_search_entry_init (NldSearchEntry *);
static void nld_search_entry_finalize (GObject *);

static void nld_search_entry_realize (GtkWidget * widget);
#if GTK_CHECK_VERSION (3, 0, 0)
static gboolean nld_search_entry_draw (GtkWidget * widget, cairo_t * cr);
#else
static gboolean nld_search_entry_expose_event (GtkWidget * widget, GdkEventExpose * event);
#endif

G_DEFINE_TYPE (NldSearchEntry, nld_search_entry, GTK_TYPE_ENTRY)

static void nld_search_entry_class_init (NldSearchEntryClass * nld_search_entry_class)
{
	GObjectClass *g_obj_class = G_OBJECT_CLASS (nld_search_entry_class);
	GtkWidgetClass *widget_class = GTK_WIDGET_CLASS (nld_search_entry_class);

	g_type_class_add_private (nld_search_entry_class, sizeof (NldSearchEntryPrivate));

	widget_class->realize = nld_search_entry_realize;
#if GTK_CHECK_VERSION (3, 0, 0)
	widget_class->draw = nld_search_entry_draw;
#else
	widget_class->expose_event = nld_search_entry_expose_event;
#endif

	g_obj_class->finalize = nld_search_entry_finalize;
}

static void
nld_search_entry_init (NldSearchEntry * entry)
{
}

static void
nld_search_entry_finalize (GObject * object)
{
	NldSearchEntryPrivate *priv = NLD_SEARCH_ENTRY_GET_PRIVATE (object);

	if (priv->watermark)
		g_object_unref (priv->watermark);

	G_OBJECT_CLASS (nld_search_entry_parent_class)->finalize (object);
}

static void
rsvg_size_callback (int *width, int *height, gpointer user_data)
{
	NldSearchEntryPrivate *priv = user_data;

	*width = priv->width = priv->height * (double) *width / (double) *height;
	*height = priv->height;
}

static void
nld_search_entry_realize (GtkWidget * widget)
{
	NldSearchEntryPrivate *priv = NLD_SEARCH_ENTRY_GET_PRIVATE (widget);
	int height;
	GdkColor *gdkcolor;
	char *svg, color[7];
	RsvgHandle *rsvg;
#if GTK_CHECK_VERSION (3, 0, 0)
	GdkRectangle text_area;
#endif

	GTK_WIDGET_CLASS (nld_search_entry_parent_class)->realize (widget);

#if GTK_CHECK_VERSION (3, 0, 0)
	gtk_entry_get_text_area (GTK_ENTRY (widget), &text_area);
	height = text_area.height;
#else
	gdk_window_get_geometry (GTK_ENTRY (widget)->text_area, NULL, NULL, NULL, &height, NULL);
#endif

	if (height - 2 == priv->height)
		return;
	priv->height = height - 2;

	gdkcolor = &gtk_widget_get_style (widget)->fg[gtk_widget_get_state (widget)];
	snprintf (color, 6, "%02x%02x%02x", gdkcolor->red >> 8, gdkcolor->green >> 8,
		gdkcolor->blue >> 8);
	svg = g_strdup_printf (SEARCH_ENTRY_WATERMARK_SVG, color, color);

	rsvg = rsvg_handle_new ();
	rsvg_handle_set_size_callback (rsvg, rsvg_size_callback, priv, NULL);
	rsvg_handle_write (rsvg, (const guchar *) svg, strlen (svg), NULL);
	rsvg_handle_close (rsvg, NULL);
	g_free (svg);

	if (priv->watermark)
		g_object_unref (priv->watermark);
	priv->watermark = rsvg_handle_get_pixbuf (rsvg);
	rsvg_handle_free (rsvg);
}

static gboolean
#if GTK_CHECK_VERSION (3, 0, 0)
nld_search_entry_draw (GtkWidget * widget, cairo_t * cr)
#else
nld_search_entry_expose_event (GtkWidget * widget, GdkEventExpose * event)
#endif
{
	NldSearchEntryPrivate *priv = NLD_SEARCH_ENTRY_GET_PRIVATE (widget);
#if GTK_CHECK_VERSION (3, 0, 0)
	GdkRectangle text_area;

	gtk_entry_get_text_area (GTK_ENTRY (widget), &text_area);
	GTK_WIDGET_CLASS (nld_search_entry_parent_class)->draw (widget, cr);
#else
	GTK_WIDGET_CLASS (nld_search_entry_parent_class)->expose_event (widget, event);
#endif

#if !GTK_CHECK_VERSION (3, 0, 0)
	if (event->window == GTK_ENTRY (widget)->text_area)
	{
#endif
		int width, height, x;

		if (gtk_widget_get_direction (widget) == GTK_TEXT_DIR_LTR)
		{
#if GTK_CHECK_VERSION(3, 0, 0)
			width = text_area.width;
			height = text_area.height;
#else
			gdk_drawable_get_size(event->window, &width, &height);
#endif
			x = width - priv->width - 1;
		}
		else
			x = 1;
#if GTK_CHECK_VERSION (3, 0, 0)
		gdk_cairo_set_source_pixbuf (cr, priv->watermark, x, 1);
		cairo_paint (cr);
#else
		gdk_draw_pixbuf (event->window, widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
			priv->watermark, 0, 0, x, 1, priv->width, priv->height,
			GDK_RGB_DITHER_NORMAL, 0, 0);
#endif

#if !GTK_CHECK_VERSION (3, 0, 0)
	}
#endif

	return FALSE;
}

GtkWidget *
nld_search_entry_new (void)
{
	return g_object_new (NLD_TYPE_SEARCH_ENTRY, NULL);
}
