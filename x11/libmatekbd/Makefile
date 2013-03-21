# New ports collection makefile for:	libgnomekbd
# Date created:		2006-11-07
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/libmatekbd/Makefile,v 1.3 2012/07/27 01:34:26 mezz Exp $
#

PORTNAME=	libmatekbd
PORTVERSION=	1.4.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE keyboard shared library

LIB_DEPENDS=	xklavier:${PORTSDIR}/x11/libxklavier

USE_XZ=		yes
USE_MATE=	autogen common:build conf intlhack ltverhack matehack
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		${MATECONF_PREFIX}
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MATECONF_SCHEMAS=desktop_mate_peripherals_keyboard_xkb.schemas

.include <bsd.port.mk>
