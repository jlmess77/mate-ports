# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-session-manager
PORTVERSION=	1.6.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Session component for the MATE desktop

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		upower-glib:${PORTSDIR}/sysutils/upower \
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	${LOCALBASE}/sbin/console-kit-daemon:${PORTSDIR}/sysutils/consolekit \
		${LOCALBASE}/bin/xdpyinfo:${PORTSDIR}/x11/xdpyinfo

USES=		gettext pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build intlhack matehack settingsdaemon
USE_XORG=	ice sm xau xext xrandr xrender xtrans xtst
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20 librsvg2 libxslt pango
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs \
		--with-gtk=2.0 \
		--with-systemd=no
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mate-session.1 mate-wm.1 mate-session-properties.1 \
		mate-session-save.1
GLIB_SCHEMAS=	org.mate.session.gschema.xml

.include <bsd.port.mk>
