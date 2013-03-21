# New ports collection makefile for:	gnomesystemmonitor
# Date created:				09 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/sysutils/mate-system-monitor/Makefile,v 1.1 2012/07/28 20:22:47 mezz Exp $
#

PORTNAME=	mate-system-monitor
PORTVERSION=	1.4.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE system monitor program

BUILD_DEPENDS=	
LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USE_XZ=		yes
USE_MATE=	autogen common:build conf docutils icontheme intlhack \
		libmatewnck matehack
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 librsvg2 libxml2
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lutil"
CONFIGURE_ARGS=	${MATECONF_PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include

MATECONF_SCHEMAS=mate-system-monitor.schemas

.include <bsd.port.mk>
