--- libmate/mate-util.c.orig	2012-07-05 15:58:15.000000000 -0500
+++ libmate/mate-util.c	2012-07-05 16:00:05.000000000 -0500
@@ -81,11 +81,10 @@
 		const char shells[][14] = {
 			/* Note that on some systems shells can also
 			 * be installed in /usr/bin */
-			"/bin/bash", "/usr/bin/bash",
-			"/bin/zsh", "/usr/bin/zsh",
-			"/bin/tcsh", "/usr/bin/tcsh",
-			"/bin/ksh", "/usr/bin/ksh",
-			"/bin/csh", "/bin/sh"
+			LOCALBASE "/bin/bash",
+			LOCALBASE "/bin/zsh",
+			LOCALBASE "/bin/ksh",
+			0
 		};
 
 		if (geteuid() == getuid() && getegid() == getgid())
