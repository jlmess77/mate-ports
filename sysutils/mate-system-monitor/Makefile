# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-system-monitor
PORTVERSION=	1.5.1
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE system monitor program

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USE_XZ=		yes
USE_MATE=	autogen common:build docutils icontheme intlhack \
		libmatewnck matehack
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20 librsvg2 libxml2
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lutil"
CPPFLAGS+=	-I${LOCALBASE}/include

GLIB_SCHEMAS=	org.mate.system-monitor.enums.xml \
		org.mate.system-monitor.gschema.xml

.include <bsd.port.mk>
