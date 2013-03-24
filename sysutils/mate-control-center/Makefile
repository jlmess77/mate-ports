# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-control-center
PORTVERSION=	1.5.5
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
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit \
		dconf:${PORTSDIR}/devel/dconf

USE_XZ=		yes
USE_MATE=	autogen common:build desktop docutils intlhack \
		ltverhack libmatekbd marco matehack menus settingsdaemon
USE_XORG=	x11 xcursor xext xxf86misc xft xi xrandr xscrnsaver
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gnomehier gtk20 libxml2 librsvg2 pango
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-appindicator=no
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.control-center.gschema.xml \
		org.mate.control-center.keybinding.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    	${WRKSRC}/capplets/common/mate-theme-info.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${PREFIX}/sbin|g' \
		${WRKSRC}/capplets/display/org.mate.randr.policy.in

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
