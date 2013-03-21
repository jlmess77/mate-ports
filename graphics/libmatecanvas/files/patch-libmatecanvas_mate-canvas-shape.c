--- libmatecanvas/mate-canvas-shape.c.orig	Fri May 20 16:55:35 2005
+++ libmatecanvas/mate-canvas-shape.c	Fri May 20 16:55:41 2005
@@ -1343,7 +1343,7 @@ gcbp_destroy_gdk (MateCanvasShape * sha
 {
 	MateCanvasShapePrivGdk * gdk;
 
-	g_assert (!((MateCanvasItem *)shape)->canvas->aa);
+	/*g_assert (!((MateCanvasItem *)shape)->canvas->aa);*/
 
 	gdk = shape->priv->gdk;
 
