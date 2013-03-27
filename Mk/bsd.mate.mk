#-*- tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#	$NetBSD$
#     $MCom: ports-experimental/Mk/bsd.mate.mk,v 1.13 2012/09/03 17:02:31 mezz Exp $
#
# Please view me with 4 column tabs!

#######################################################
#
# *** WARNING: Disable MARCUSCOM before merge in FreeBSD!
#     Please also remove this section before merging into FreeBSD.
#
#MARCUSCOM_CVS=yes

# ======================= USERS =================================
#
# There are no significant user-definable settings in here.
# This file is a framework to make it easier to create MATE ports.
#
# ======================= /USERS ================================

.if !defined(_POSTMKINCLUDED) && !defined(Mate_Pre_Include)

# Please make sure all changes to this file are passed through the maintainer.
# Do not commit them yourself (unless of course you're the Port's Wraith ;).
Mate_Include_MAINTAINER=	gnome@FreeBSD.org
Mate_Pre_Include=			bsd.mate.mk

# This section defines possible names of MATE components and all information
# necessary for ports to use those components.

# Ports can use this as follows:
#
# USE_MATE=	gnomeprint bonobo
#
# .include <bsd.port.mk>
#
# As a result proper LIB_DEPENDS/RUN_DEPENDS will be added and CONFIGURE_ENV
# and MAKE_ENV defined.
#

# non-version specific components. Do not use :build/:run on those.
_USE_MATE_ALL=	autogen intlhack intltool ltasneededhack lthack ltverhack \
				matehack

# MATE components, you can use the :build or :run if need. Without the :build
# and :run, it will be added in both build and run dependency. It will check
# for the library dependency first. If not exists then do the build/run on
# the *.pc file instead.
_USE_MATE_ALL+=	caja canvas common component componentui conf controlcenter \
				corba desktop dialogs docutils icontheme keyring libmate \
				libmatekbd libmatekeyring libmatenotify libmateui \
				libmateweather libmatewnck marco menus mimedata mucharmap \
				notificationdaemon panel polkit pluma pycorba pymate \
				settingsdaemon vfs

MATE_MAKEFILEIN?=	Makefile.*
SCROLLKEEPER_DIR=	/var/db/rarian
matehack_PRE_PATCH=	${FIND} ${WRKSRC} -name "${MATE_MAKEFILEIN}*" -type f | ${XARGS} ${REINPLACE_CMD} -e \
				's|[(]libdir[)]/locale|(prefix)/share/locale|g ; \
				 s|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
				 s|[(]datadir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
				 s|[(]prefix[)]/lib/pkgconfig|(prefix)/libdata/pkgconfig|g ; \
				 s|[$$][(]localstatedir[)]/scrollkeeper|${SCROLLKEEPER_DIR}|g ; \
				 s|[(]libdir[)]/matecomponent/servers|(prefix)/libdata/matecomponent/servers|g' ; \
			${FIND} ${WRKSRC} -name "configure" -type f | ${XARGS} ${REINPLACE_CMD} -e \
				's|-lpthread|${PTHREAD_LIBS}|g ; \
				 s|DATADIRNAME=lib|DATADIRNAME=share|g ; \
				 s|{libdir}/locale|{prefix}/share/locale|g'

lthack_PRE_PATCH=	${FIND} ${WRKSRC} -name "configure" -type f | ${XARGS} ${REINPLACE_CMD} -e \
				'/^LIBTOOL_DEPS="$$ac_aux_dir\/ltmain.sh"$$/s|$$|; $$ac_aux_dir/ltconfig $$LIBTOOL_DEPS;|'

caja_DETECT=			${LOCALBASE}/libdata/pkgconfig/libcaja-extension.pc
caja_BUILD_DEPENDS=		${caja_DETECT}:${PORTSDIR}/x11-fm/mate-file-manager
caja_LIB_DEPENDS=		caja-extension:${PORTSDIR}/x11-fm/mate-file-manager
caja_RUN_DEPENDS=		${caja_DETECT}:${PORTSDIR}/x11-fm/mate-file-manager

canvas_DETECT=			${LOCALBASE}/libdata/pkgconfig/libmatecanvas-2.0.pc
canvas_BUILD_DEPENDS=	${canvas_DETECT}:${PORTSDIR}/graphics/libmatecanvas
canvas_LIB_DEPENDS=		matecanvas-2:${PORTSDIR}/graphics/libmatecanvas
canvas_RUN_DEPENDS=		${canvas_DETECT}:${PORTSDIR}/graphics/libmatecanvas

mucharmap_DETECT=		${LOCALBASE}/libdata/pkgconfig/mucharmap-2.pc
mucharmap_BUILD_DEPENDS=${canvas_DETECT}:${PORTSDIR}/deskutils/mate-character-map
mucharmap_LIB_DEPENDS=	mucharmap:${PORTSDIR}/deskutils/mate-character-map
mucharmap_RUN_DEPENDS=	${canvas_DETECT}:${PORTSDIR}/deskutils/mate-character-map

common_DETECT=			${LOCALBASE}/bin/mate-autogen
common_BUILD_DEPENDS=	${common_DETECT}:${PORTSDIR}/devel/mate-common
common_RUN_DEPENDS=		${common_DETECT}:${PORTSDIR}/devel/mate-common

component_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmatecomponent-2.0.pc
component_BUILD_DEPENDS=${component_DETECT}:${PORTSDIR}/devel/libmatecomponent
component_LIB_DEPENDS=	matecomponent-2:${PORTSDIR}/devel/libmatecomponent
component_RUN_DEPENDS=	${component_DETECT}:${PORTSDIR}/devel/libmatecomponent

componentui_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmatecomponentui-2.0.pc
componentui_BUILD_DEPENDS=${componentui_DETECT}:${PORTSDIR}/x11-toolkits/libmatecomponentui
componentui_LIB_DEPENDS=matecomponentui-2:${PORTSDIR}/x11-toolkits/libmatecomponentui
componentui_RUN_DEPENDS=${componentui_DETECT}:${PORTSDIR}/x11-toolkits/libmatecomponentui

conf_DETECT=			${LOCALBASE}/libdata/pkgconfig/mateconf-2.0.pc
conf_BUILD_DEPENDS=		${conf_DETECT}:${PORTSDIR}/devel/mate-conf
conf_LIB_DEPENDS=		mateconf-2:${PORTSDIR}/devel/mate-conf
conf_RUN_DEPENDS=		${conf_DETECT}:${PORTSDIR}/devel/mate-conf
MATECONF_CONFIG_OPTIONS?=merged
MATECONF_CONFIG_DIRECTORY?=etc/mateconf/mateconf.xml.defaults
MATECONF_CONFIG_SOURCE?=xml:${MATECONF_CONFIG_OPTIONS}:${PREFIX}/${MATECONF_CONFIG_DIRECTORY}
MATECONF_PREFIX=		--with-mateconf-source=${MATECONF_CONFIG_SOURCE}

controlcenter_DETECT=	${LOCALBASE}/libdata/pkgconfig/mate-window-settings-2.0.pc
controlcenter_BUILD_DEPENDS=${controlcenter_DETECT}:${PORTSDIR}/sysutils/mate-control-center
controlcenter_LIB_DEPENDS=mate-window-settings:${PORTSDIR}/sysutils/mate-control-center
controlcenter_RUN_DEPENDS=${controlcenter_DETECT}:${PORTSDIR}/sysutils/mate-control-center

corba_DETECT=			${LOCALBASE}/libdata/pkgconfig/MateCORBA-2.0.pc
corba_BUILD_DEPENDS=	${corba_DETECT}:${PORTSDIR}/devel/mate-corba
corba_LIB_DEPENDS=		MateCORBA-2:${PORTSDIR}/devel/mate-corba
corba_RUN_DEPENDS=		${corba_DETECT}:${PORTSDIR}/devel/mate-corba

desktop_DETECT=			${LOCALBASE}/libdata/pkgconfig/mate-desktop-2.0.pc
desktop_BUILD_DEPENDS=	${desktop_DETECT}:${PORTSDIR}/x11/mate-desktop
desktop_LIB_DEPENDS=	mate-desktop-2:${PORTSDIR}/x11/mate-desktop
desktop_RUN_DEPENDS=	${desktop_DETECT}:${PORTSDIR}/x11/mate-desktop

dialogs_DETECT=			${LOCALBASE}/bin/matedialog
dialogs_BUILD_DEPENDS=	${dialogs_DETECT}:${PORTSDIR}/x11/mate-dialogs
dialogs_RUN_DEPENDS=	${dialogs_DETECT}:${PORTSDIR}/x11/mate-dialogs

docutils_DETECT=		${LOCALBASE}/libdata/pkgconfig/mate-doc-utils.pc
docutils_BUILD_DEPENDS=	${docutils_DETECT}:${PORTSDIR}/textproc/mate-doc-utils
docutils_RUN_DEPENDS=	${docutils_DETECT}:${PORTSDIR}/textproc/mate-doc-utils

icontheme_DETECT=		${LOCALBASE}/libdata/pkgconfig/mate-icon-theme.pc
icontheme_BUILD_DEPENDS=${icontheme_DETECT}:${PORTSDIR}/x11-themes/mate-icon-theme
icontheme_RUN_DEPENDS=	${icontheme_DETECT}:${PORTSDIR}/x11-themes/mate-icon-theme

intltool_DETECT=		${LOCALBASE}/bin/intltool-extract
intltool_BUILD_DEPENDS=	${intltool_DETECT}:${PORTSDIR}/textproc/intltool

intlhack_PRE_PATCH=		${FIND} ${WRKSRC} -name "intltool-merge.in" | ${XARGS} ${REINPLACE_CMD} -e \
				's|mkdir $$lang or|mkdir $$lang, 0777 or| ; \
				 s|^push @INC, "/.*|push @INC, "${LOCALBASE}/share/intltool";| ; \
				 s|/usr/bin/iconv|${LOCALBASE}/bin/iconv|g ; \
				 s|unpack *[(]'"'"'U\*'"'"'|unpack ('"'"'C*'"'"'|'
.if ${USE_MATE:Mintlhack}!=""
USE_MATE+=				intltool
.endif

keyring_DETECT=			${LOCALBASE}/libdata/pkgconfig/mate-gcr-0.pc
keyring_BUILD_DEPENDS=	${keyring_DETECT}:${PORTSDIR}/security/mate-keyring
keyring_LIB_DEPENDS=	mategcr:${PORTSDIR}/security/mate-keyring
keyring_RUN_DEPENDS=	${keyring_DETECT}:${PORTSDIR}/security/mate-keyring

libmate_DETECT=			${LOCALBASE}/libdata/pkgconfig/libmate-2.0.pc
libmate_BUILD_DEPENDS=	${libmate_DETECT}:${PORTSDIR}/x11/libmate
libmate_LIB_DEPENDS=	mate-2:${PORTSDIR}/x11/libmate
libmate_RUN_DEPENDS=	${libmate_DETECT}:${PORTSDIR}/x11/libmate

libmatekbd_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmatekbd.pc
libmatekbd_BUILD_DEPENDS=${libmatekbd_DETECT}:${PORTSDIR}/x11/libmatekbd
libmatekbd_LIB_DEPENDS=	matekbd:${PORTSDIR}/x11/libmatekbd
libmatekbd_RUN_DEPENDS=	${libmatekbd_DETECT}:${PORTSDIR}/x11/libmatekbd

libmatekeyring_DETECT=	${LOCALBASE}/libdata/pkgconfig/mate-keyring-1.pc
libmatekeyring_BUILD_DEPENDS=${libmatekeyring_DETECT}:${PORTSDIR}/security/libmatekeyring
libmatekeyring_LIB_DEPENDS=mate-keyring:${PORTSDIR}/security/libmatekeyring
libmatekeyring_RUN_DEPENDS=${libmatekeyring_DETECT}:${PORTSDIR}/security/libmatekeyring

libmatenotify_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmatenotify.pc
libmatenotify_BUILD_DEPENDS=${libmatenotify_DETECT}:${PORTSDIR}/devel/libmatenotify
libmatenotify_LIB_DEPENDS=	matenotify:${PORTSDIR}/devel/libmatenotify
libmatenotify_RUN_DEPENDS=	${libmatenotify_DETECT}:${PORTSDIR}/devel/libmatenotify

libmateui_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmateui-2.0.pc
libmateui_BUILD_DEPENDS=${libmateui_DETECT}:${PORTSDIR}/x11-toolkits/libmateui
libmateui_LIB_DEPENDS=	mateui-2:${PORTSDIR}/x11-toolkits/libmateui
libmateui_RUN_DEPENDS=	${libmateui_DETECT}:${PORTSDIR}/x11-toolkits/libmateui

libmateweather_DETECT=	${LOCALBASE}/libdata/pkgconfig/mateweather.pc
libmateweather_BUILD_DEPENDS=${libmateweather_DETECT}:${PORTSDIR}/net/libmateweather
libmateweather_LIB_DEPENDS=mateweather:${PORTSDIR}/net/libmateweather
libmateweather_RUN_DEPENDS=${libmateweather_DETECT}:${PORTSDIR}/net/libmateweather

libmatewnck_DETECT=		${LOCALBASE}/libdata/pkgconfig/libmatewnck.pc
libmatewnck_BUILD_DEPENDS=${libmatewnck_DETECT}:${PORTSDIR}/x11-toolkits/libmatewnck
libmatewnck_LIB_DEPENDS=matewnck:${PORTSDIR}/x11-toolkits/libmatewnck
libmatewnck_RUN_DEPENDS=${libmatewnck_DETECT}:${PORTSDIR}/x11-toolkits/libmatewnck

marco_DETECT=			${LOCALBASE}/libdata/pkgconfig/libmarco-private.pc
marco_BUILD_DEPENDS=	${marco_DETECT}:${PORTSDIR}/x11-wm/mate-window-manager
marco_LIB_DEPENDS=		marco-private:${PORTSDIR}/x11-wm/mate-window-manager
marco_RUN_DEPENDS=		${marco_DETECT}:${PORTSDIR}/x11-wm/mate-window-manager

menus_DETECT=			${LOCALBASE}/libdata/pkgconfig/libmate-menu.pc
menus_BUILD_DEPENDS=	${menus_DETECT}:${PORTSDIR}/x11/mate-menus
menus_LIB_DEPENDS=		mate-menu:${PORTSDIR}/x11/mate-menus
menus_RUN_DEPENDS=		${menus_DETECT}:${PORTSDIR}/x11/mate-menus

mimedata_DETECT=		${LOCALBASE}/libdata/pkgconfig/mate-mime-data-2.0.pc
mimedata_BUILD_DEPENDS=	${mimedata_DETECT}:${PORTSDIR}/misc/mate-mime-data
mimedata_RUN_DEPENDS=	${mimedata_DETECT}:${PORTSDIR}/misc/mate-mime-data

notificationdaemon_DETECT=${LOCALBASE}/libexec/mate-notification-daemon
notificationdaemon_BUILD_DEPENDS=${notificationdaemon_DETECT}:${PORTSDIR}/deskutils/mate-notification-daemon
notificationdaemon_RUN_DEPENDS=${notificationdaemon_DETECT}:${PORTSDIR}/deskutils/mate-notification-daemon

panel_DETECT=			${LOCALBASE}/libdata/pkgconfig/libmatepanelapplet-4.0.pc
panel_BUILD_DEPENDS=	${panel_DETECT}:${PORTSDIR}/x11/mate-panel
panel_LIB_DEPENDS=		mate-panel-applet-4:${PORTSDIR}/x11/mate-panel
panel_RUN_DEPENDS=		${panel_DETECT}:${PORTSDIR}/x11/mate-panel

polkit_DETECT=			${LOCALBASE}/libdata/pkgconfig/polkit-gtk-mate-1.pc
polkit_BUILD_DEPENDS=	${polkit_DETECT}:${PORTSDIR}/sysutils/mate-polkit
polkit_LIB_DEPENDS=		polkit-gtk-mate:${PORTSDIR}/sysutils/mate-polkit
polkit_RUN_DEPENDS=		${polkit_DETECT}:${PORTSDIR}/sysutils/mate-polkit

pluma_DETECT=			${LOCALBASE}/libdata/pkgconfig/pluma.pc
pluma_BUILD_DEPENDS=	${pluma_DETECT}:${PORTSDIR}/editors/mate-text-editor
pluma_RUN_DEPENDS=		${pluma_DETECT}:${PORTSDIR}/editors/mate-text-editor

pycorba_DETECT=			${LOCALBASE}/libdata/pkgconfig/pymatecorba-2.pc
pycorba_BUILD_DEPENDS=	${pycorba_DETECT}:${PORTSDIR}/devel/python-corba
pycorba_RUN_DEPENDS=	${pycorba_DETECT}:${PORTSDIR}/devel/python-corba

pymate_DETECT=			${LOCALBASE}/libdata/pkgconfig/mate-python-2.0.pc
pymate_BUILD_DEPENDS=	${pymate_DETECT}:${PORTSDIR}/x11-toolkits/python-mate
pymate_RUN_DEPENDS=		${pymate_DETECT}:${PORTSDIR}/x11-toolkits/python-mate

settingsdaemon_DETECT=	${LOCALBASE}/libdata/pkgconfig/mate-settings-daemon.pc
settingsdaemon_BUILD_DEPENDS=${settingsdaemon_DETECT}:${PORTSDIR}/sysutils/mate-settings-daemon
settingsdaemon_RUN_DEPENDS=${settingsdaemon_DETECT}:${PORTSDIR}/sysutils/mate-settings-daemon

vfs_DETECT=				${LOCALBASE}/libdata/pkgconfig/mate-vfs-2.0.pc
vfs_BUILD_DEPENDS=		${vfs_DETECT}:${PORTSDIR}/devel/mate-vfs
vfs_LIB_DEPENDS=		matevfs-2:${PORTSDIR}/devel/mate-vfs
vfs_RUN_DEPENDS=		${vfs_DETECT}:${PORTSDIR}/devel/mate-vfs

# End component definition section

.endif
# End of optional part.

.if defined(_POSTMKINCLUDED) && !defined(Mate_Post_Include)

Mate_Post_Include=		bsd.mate.mk

.if defined(USE_MATE)
# Then handle the ltverhack component (it has to be done here, because
# we rely on some bsd.autotools.mk variables, and bsd.autotools.mk is
# included in the post-makefile section).
.if defined(_AUTOTOOL_libtool)
lthacks_CONFIGURE_ENV=	ac_cv_path_DOLT_BASH=
lthacks_PRE_PATCH=		${CP} -pf ${LTMAIN} ${WRKDIR}/mate-ltmain.sh && \
						${CP} -pf ${LIBTOOL} ${WRKDIR}/mate-libtool && \
						for file in ${LIBTOOLFILES}; do \
							${REINPLACE_CMD} -e \
								'/^ltmain=/!s|$$ac_aux_dir/ltmain\.sh|${LIBTOOLFLAGS} ${WRKDIR}/mate-ltmain.sh|g; \
								 /^LIBTOOL=/s|$$(top_builddir)/libtool|${WRKDIR}/mate-libtool|g' \
								${PATCH_WRKSRC}/$$file; \
						done;
.else
.  if ${USE_MATE:Mltverhack*}!="" || ${USE_MATE:Mltasneededhack}!=""
IGNORE=	cannot install: ${PORTNAME} uses the ltverhack and/or ltasneededhack MATE components but does not use libtool
.  endif
.endif

.if ${USE_MATE:Mltverhack\:*:C/^[^:]+:([^:]+).*/\1/}==""
ltverhack_LIB_VERSION=	major=.`expr $$current - $$age`
.else
ltverhack_LIB_VERSION=	major=".${USE_MATE:Mltverhack\:*:C/^[^:]+:([^:]+).*/\1/}"
.endif
ltverhack_PATCH_DEPENDS=${LIBTOOL_DEPENDS}
ltverhack_PRE_PATCH=	for file in mate-ltmain.sh mate-libtool; do \
							if [ -f ${WRKDIR}/$$file ]; then \
								${REINPLACE_CMD} -e \
									'/freebsd-elf)/,/;;/ s|major="\.$$current"|${ltverhack_LIB_VERSION}|; \
									 /freebsd-elf)/,/;;/ s|versuffix="\.$$current"|versuffix="$$major"|' \
									${WRKDIR}/$$file; \
							fi; \
						done

ltasneededhack_PATCH_DEPENDS=${LIBTOOL_DEPENDS}
ltasneededhack_PRE_PATCH=	if [ -f ${WRKDIR}/mate-libtool ]; then \
								${REINPLACE_CMD} -e \
									'/^archive_cmds=/s/-shared/-shared -Wl,--as-needed/ ; \
									/^archive_expsym_cmds=/s/-shared/-shared -Wl,--as-needed/' \
									${WRKDIR}/mate-libtool; \
							fi


# Comparing between USE_MATE and _USE_MATE_ALL to make sure the component
# exists in _USE_MATE_ALL. If it does not exist then give an error about it.
. for component in ${USE_MATE:O:u:C/^([^:]+).*/\1/}
.  if ${_USE_MATE_ALL:M${component}}==""
.error cannot install: Unknown component USE_MATE=${component}
.  endif
. endfor

. if ${USE_MATE:Mltverhack*}!= "" || ${USE_MATE:Mltasneededhack}!= ""
MATE_PRE_PATCH+=	${lthacks_PRE_PATCH}
CONFIGURE_ENV+=		${lthacks_CONFIGURE_ENV}
. endif

. for component in ${USE_MATE:O:u:C/^([^:]+).*/\1/}
.  if defined(${component}_PATCH_DEPENDS)
PATCH_DEPENDS+=	${${component}_PATCH_DEPENDS}
.  endif

.  if defined(${component}_DETECT)
.   if ${USE_MATE:M${component}\:build}!=""
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
.   elif ${USE_MATE:M${component}\:run}!=""
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.   else
.    if defined(${component}_LIB_DEPENDS)
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
.    else
BUILD_DEPENDS+=	${${component}_BUILD_DEPENDS}
RUN_DEPENDS+=	${${component}_RUN_DEPENDS}
.    endif
.   endif
.  endif

.  if defined(${component}_CONFIGURE_TARGET)
CONFIGURE_ARGS+=${${component}_CONFIGURE_ARGS}
.  endif

.  if defined(${component}_CONFIGURE_ENV)
CONFIGURE_ENV+=	${${component}_CONFIGURE_ENV}
.  endif

.  if defined(${component}_MAKE_ENV)
MAKE_ENV+=	${${component}_MAKE_ENV}
.  endif

.  if !defined(CONFIGURE_TARGET) && defined(${component}_CONFIGURE_TARGET)
CONFIGURE_TARGET=	${${component}_CONFIGURE_TARGET}
.  endif

.  if defined(${component}_PRE_PATCH)
MATE_PRE_PATCH+=	; ${${component}_PRE_PATCH}
.  endif
. endfor
.endif # USE_MATE check

.if ${USE_MATE:Mautogen}!=""

CONFIGURE_ENV+=	NOCONFIGURE=yes

pre-configure: mate-pre-configure

mate-pre-configure:
	@(cd ${CONFIGURE_WRKSRC} ; ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)
.endif

.if defined(MATE_PRE_PATCH)

pre-configure-script: mate-pre-configure-script

mate-pre-configure-script:
	@${MATE_PRE_PATCH:C/^;//1}
.endif

.if ${MAINTAINER}=="gnome@FreeBSD.org"
CONFIGURE_FAIL_MESSAGE= "Please run the gnomelogalyzer, available from \"http://www.freebsd.org/gnome/gnomelogalyzer.sh\", which will diagnose the problem and suggest a solution. If - and only if - the gnomelogalyzer cannot solve the problem, report the build failure to the FreeBSD MATE team at ${MAINTAINER}, and attach (a) \"${CONFIGURE_WRKSRC}/${CONFIGURE_LOG}\", (b) the output of the failed make command, and (c) the gnomelogalyzer output. Also, it might be a good idea to provide an overview of all packages installed on your system (i.e. an \`ls ${PKG_DBDIR}\`). Put your attachment up on any website, copy-and-paste into http://freebsd-gnome.pastebin.com, or use send-pr(1) with the attachment. Try to avoid sending any attachments to the mailing list (${MAINTAINER}), because attachments sent to FreeBSD mailing lists are usually discarded by the mailing list software."
.endif


.if defined(MATECONF_SCHEMAS)
pre-su-install: mate-pre-su-install
post-install: mate-post-install

mate-pre-su-install:
. if defined(MATECONF_SCHEMAS)
	@${MKDIR} ${PREFIX}/etc/mateconf/mateconf.xml.defaults/
. else
	@${DO_NADA}
. endif

mate-post-install:
. if defined(MATECONF_SCHEMAS)
	@for i in ${MATECONF_SCHEMAS}; do \
		${ECHO_CMD} "@unexec env MATECONF_CONFIG_SOURCE=xml:${MATECONF_CONFIG_OPTIONS}:%D/${MATECONF_CONFIG_DIRECTORY} mateconftool-2 --makefile-uninstall-rule %D/etc/mateconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
		${ECHO_CMD} "etc/mateconf/schemas/$${i}" >> ${TMPPLIST}; \
		${ECHO_CMD} "@exec env MATECONF_CONFIG_SOURCE=xml:${MATECONF_CONFIG_OPTIONS}:%D/${MATECONF_CONFIG_DIRECTORY} mateconftool-2 --makefile-install-rule %D/etc/mateconf/schemas/$${i} > /dev/null || /usr/bin/true" \
			>> ${TMPPLIST}; \
	done
. endif
.endif

.endif
# End of use part.
