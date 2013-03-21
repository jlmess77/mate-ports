--- gsettings/mateconfsettingsbackend.c.orig	2010-11-14 12:54:57.000000000 -0500
+++ gsettings/mateconfsettingsbackend.c	2010-11-14 12:55:08.000000000 -0500
@@ -924,5 +924,5 @@ gconf_settings_backend_register (GIOModu
   g_io_extension_point_implement (G_SETTINGS_BACKEND_EXTENSION_POINT_NAME,
                                   MATECONF_TYPE_SETTINGS_BACKEND,
                                   "mateconf",
-                                  -1);
+                                  10);
 }
