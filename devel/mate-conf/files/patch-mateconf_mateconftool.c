--- mateconf/mateconftool.c.orig	2012-07-31 18:18:59.000000000 -0500
+++ mateconf/mateconftool.c	2012-07-31 18:19:33.000000000 -0500
@@ -1041,7 +1041,7 @@
       mateconf_engine_unref (conf);
       
       /* http://projects.archlinux.org/svntogit/packages.git/plain/gconf/trunk/gconf-reload.patch */
-      g_spawn_command_line_sync ("/usr/bin/killall -q -TERM " MATECONF_SERVERDIR "/" MATECONFD, NULL, NULL, NULL, NULL);
+      g_spawn_command_line_sync ("/usr/bin/killall -TERM " MATECONF_SERVERDIR "/" MATECONFD, NULL, NULL, NULL, NULL);
 
       return retval;
     }
@@ -1056,7 +1056,7 @@
       mateconf_engine_unref (conf);
       
       /* http://projects.archlinux.org/svntogit/packages.git/plain/gconf/trunk/gconf-reload.patch */
-      g_spawn_command_line_sync ("/usr/bin/killall -q -TERM " MATECONF_SERVERDIR "/" MATECONFD, NULL, NULL, NULL, NULL);
+      g_spawn_command_line_sync ("/usr/bin/killall -TERM " MATECONF_SERVERDIR "/" MATECONFD, NULL, NULL, NULL, NULL);
 
       return retval;
     }
