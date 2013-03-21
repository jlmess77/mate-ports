# New ports collection makefile for:	gnometerminal
# Date created:				1 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/mate-terminal/Makefile,v 1.1 2012/07/28 02:49:42 mezz Exp $
#

PORTNAME=	mate-terminal
PORTVERSION=	1.4.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the MATE Desktop

USE_XZ=		yes
USE_MATE=	autogen common:build conf docutils intlhack matehack
USE_XORG=	sm x11
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 vte
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		${MATECONF_PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MATECONF_SCHEMAS=mate-terminal.schemas

.include <bsd.port.mk>
