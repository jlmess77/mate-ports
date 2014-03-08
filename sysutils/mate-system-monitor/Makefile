# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-system-monitor
PORTVERSION=	1.8.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE system monitor program

LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	docutils icontheme libmatewnck
USE_GNOME=	gnomehier gtk20 librsvg2 intlhack libxml2 gtkmm24
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lutil"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.system-monitor.enums.xml \
		org.mate.system-monitor.gschema.xml

.include <bsd.port.mk>
