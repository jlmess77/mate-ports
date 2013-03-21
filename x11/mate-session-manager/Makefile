# New ports collection makefile for:	gnomesession
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/mate-session-manager/Makefile,v 1.4 2012/07/27 01:34:27 mezz Exp $
#

PORTNAME=	mate-session-manager
PORTVERSION=	1.4.0
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

USE_XZ=		yes
USE_MATE=	autogen common:build conf intlhack matehack settingsdaemon
USE_XORG=	ice sm xau xext xrandr xrender xtrans xtst
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 librsvg2 libxslt pango
USE_GETTEXT=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook-docs \
		--with-gtk=2.0 \
		${MATECONF_PREFIX}
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mate-session.1 mate-wm.1 mate-session-properties.1 \
		mate-session-save.1
MATECONF_SCHEMAS=mate-session.schemas

.include <bsd.port.mk>
