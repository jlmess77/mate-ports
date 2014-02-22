MATE ports for FreeBSD
======================

MATE 1.6 was committed to FreeBSD ports on 23 November 2013. Get it there.

Overview
--------
MATE is a fork of GNOME 2. More information can be found at http://mate-desktop.org/. This is a place where you can get MATE ports development for FreeBSD. When the MATE ports are stable and it will be merged into FreeBSD ports tree.

Get mate-ports and install MATE
-------------------------------
You will need to make sure you have latest ports tree before you grab MATE. I am not going to give you a baby step of how to update FreeBSD ports tree or install other apps if your command line doesn't work. The FreeBSD Handbook (http://www.freebsd.org/) is a place where you need to visit and read. You will need to install the `devel/git` as matemerge.sh depends on it to fetch mate-ports from GitHub. Anyway, let's get start to grab matemerge.sh script that will allow merge the mate-ports into your /usr/ports.

	# fetch http://people.freebsd.org/~mezz/script/matemerge.sh

You will need to edit in the marcusmerge in your editor. The two variables, `SRCDIR` and `DESTDIR` are what you need to change it. You may skip `DESTDIR` if it's same default in your FreeBSD. To merge mate-ports into FreeBSD ports:

	# sh matemerge.sh

There are two different choices of mate ports, `x11/mate-base` or `x11/mate`, to install MATE desktop. The `x11/mate-base` is a bare desktop without any of extra MATE applications such as editor, terminal, calculator and other. It only has file manager and panel. The `x11/mate` is a full desktop with editor, terminal, calculator and other applications.

Update mate-ports and installed MATE ports
------------------------------------------
It is recommend to unmerge the mate-ports first before you update your FreeBSD ports tree.

	# sh ./matemerge.sh -U

After that, update your ports tree by either svn, portsnap or other methods then use the matemerge.sh to update it.

	# sh ./matemerge.sh -u

TODO
----
Please see the `TODO-mate` file.
