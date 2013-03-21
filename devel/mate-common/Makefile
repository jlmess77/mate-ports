# New ports collection makefile for:	gnomecommon
# Date created:				04 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/devel/mate-common/Makefile,v 1.3 2012/07/27 01:34:25 mezz Exp $
#

PORTNAME=	mate-common
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Common automake macros for MATE

USE_XZ=		yes
USE_MATE=	autogen
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
USE_PKGCONFIG=	both
GNU_CONFIGURE=	yes

MAN1=		mate-autogen.1 mate-doc-common.1

.include <bsd.port.mk>
