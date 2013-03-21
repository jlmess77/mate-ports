# New ports collection makefile for:	gnome-settings-daemon
# Date created:				14 Jan 2008
# Whom:					Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/sysutils/mate-settings-daemon/Makefile,v 1.3 2012/07/27 01:34:26 mezz Exp $
#

PORTNAME=	mate-settings-daemon
PORTVERSION=	1.4.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE settings daemon

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		xklavier:${PORTSDIR}/x11/libxklavier \
		nss3:${PORTSDIR}/security/nss \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit
RUN_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

USE_XZ=		yes
USE_MATE=	autogen common:build conf desktop intlhack libmatekbd \
		libmatenotify matehack
USE_XORG=	xxf86misc
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
USE_GSTREAMER=	good
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services \
		${MATECONF_PREFIX} \
		--disable-pulse
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MATECONF_SCHEMAS=apps_mate_settings_daemon_housekeeping.schemas \
		 apps_mate_settings_daemon_keybindings.schemas \
		 apps_mate_settings_daemon_xrandr.schemas \
		 desktop_mate_font_rendering.schemas \
		 desktop_mate_keybindings.schemas \
		 desktop_mate_peripherals_smartcard.schemas \
		 desktop_mate_peripherals_touchpad.schemas \
		 mate-settings-daemon.schemas

.include <bsd.port.mk>
