# New ports collection makefile for:	gnomecontrolcenter2
# Date created:				04 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/sysutils/mate-control-center/Makefile,v 1.3 2012/07/27 01:34:26 mezz Exp $
#

PORTNAME=	mate-control-center
PORTVERSION=	1.4.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for MATE project

LIB_DEPENDS=	canberra-gtk:${PORTSDIR}/audio/libcanberra \
		dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		xklavier:${PORTSDIR}/x11/libxklavier \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit

USE_XZ=		yes
USE_MATE=	autogen common:build conf desktop docutils intlhack \
		ltverhack libmatekbd marco matehack menus settingsdaemon
USE_XORG=	x11 xcursor xext xxf86misc xft xi xrandr xscrnsaver
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gtk20 libxml2 pango
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-appindicator=no \
		${MATECONF_PREFIX}
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MATECONF_SCHEMAS=control-center.schemas fontilus.schemas \
		 mate-control-center.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    	${WRKSRC}/capplets/common/mate-theme-info.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${PREFIX}/sbin|g' \
		${WRKSRC}/capplets/display/org.mate.randr.policy.in

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
