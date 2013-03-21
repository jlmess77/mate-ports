MATE ports for FreeBSD
======================

Overview
--------
MATE is a fork of GNOME 2. More information can be found at http://mate-desktop.org/. This is a place where you can get MATE ports development for FreeBSD. When the MATE ports are stable and it will be merged into FreeBSD ports tree.

**Keep in mind, the README is kind of incomplete and untest. I am just throwing what's in my mind right now for I don't lose anything if I write it later.**

Get mate-ports and install MATE (untest)
-------------------------------
You will need to make sure you have latest ports tree before you grab MATE. I am not going to give you a baby step of how to update FreeBSD ports tree or install other apps if your command line doesn't work. The FreeBSD Handbook (http://www.freebsd.org/) is a place where you need to visit and read. Anyway, let's get start.

	# git clone https://github.com/jlmess77/mate-ports.git
	# rm -rf mate-ports/.git

I know that it's ugly to remove the ".git" directory, but you don't have to do it if you don't mind to put it in the /usr/ports/ by marcusmerge script. When I create a fork of marcusmerge script and it won't be copied in the /usr/ports/. Let's fetch marcusmerge script.

	# fetch http://www.marcuscom.com/downloads/marcusmerge

You will need to edit in the marcusmerge in your editor. Although, you can use the flag options instead of edit it but it's much easier if you edit it. The two variables, `SRCDIR` and `DESTDIR` are what you need to change it. You may skip `DESTDIR` if it's same default in your FreeBSD. To merge mate-ports into FreeBSD ports:

	# sh ./marcusmerge -m mate-ports

There are two different choices of mate ports, `x11/mate-base` or `x11/mate`, to install MATE desktop. The `x11/mate-base` is a bare desktop without any of extra MATE applications such as editor, terminal, calculator and other. It only has file manager and panel. The `x11/mate` is a full desktop with editor, terminal, calculator and other applications.

Update mate-ports and installed MATE ports (untest)
------------------------------------------
It is recommend to unmerge the mate-ports first before you update your FreeBSD ports tree.

	# sh ./marcusmerge -U

After that, follow the same steps in the **"Get mate-ports and install MATE"**, but skip the fetch marcusmerge script part. I am not sure if you have to remove the mate-ports because of removed the ".git" directory. Hences for the README is untest and it's what in my mind.

TODO
----
Please see the `TODO-mate` file.
