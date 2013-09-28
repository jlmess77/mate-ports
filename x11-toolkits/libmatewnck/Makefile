# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmatewnck
PORTVERSION=	1.6.0
CATEGORIES=	x11-toolkits mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library used for writing pagers and taskslists

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc

USES=		bison gettext gmake pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build intlhack ltverhack matehack
USE_XORG=	x11 xres
USE_GNOME=	gdkpixbuf2 glib20 gnomehier gtk20 introspection
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	STARTUP
OPTIONS_DEFAULT=STARTUP
STARTUP_DESC=	Startup notification support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTARTUP}
LIB_DEPENDS+=	libstartup-notification-1.so:${PORTSDIR}/x11/startup-notification
CONFIGURE_ARGS+=--enable-startup-notification
.else
CONFIGURE_ARGS+=--disable-startup-notification
.endif

.include <bsd.port.mk>
