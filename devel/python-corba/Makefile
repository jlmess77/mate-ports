# New ports collection makefile for:	py-orbit2
# Date created:				04 March 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/devel/python-corba/Makefile,v 1.1 2012/07/29 17:29:11 mezz Exp $
#

PORTNAME=	python-corba
PORTVERSION=	1.4.0
CATEGORIES=	devel python mate
MASTER_SITES=	MATE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python bindings for MateCORBA2

USE_XZ=		yes
USE_MATE=	autogen common:build corba matehack
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
LDFLAGS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|\./libtool|${LIBTOOL}|g' \
		${WRKSRC}/configure.in

.include <bsd.port.mk>
