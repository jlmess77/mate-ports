--- activation-server/activation-server-main.c.orig	2012-07-04 23:17:22.000000000 -0500
+++ activation-server/activation-server-main.c	2012-07-04 23:17:42.000000000 -0500
@@ -239,7 +239,7 @@
                         g_string_append (mate_od_source_dir,
                                          mate_dirs[i]);
                         g_string_append (mate_od_source_dir,
-                                         "/lib/matecomponent/servers" G_SEARCHPATH_SEPARATOR_S);
+                                         "/libdata/matecomponent/servers" G_SEARCHPATH_SEPARATOR_S);
                 }
                 g_strfreev (mate_dirs);
                 g_string_append (real_od_source_dir,
