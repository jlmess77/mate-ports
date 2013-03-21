# New ports collection makefile for:	mate-file-manager-open-terminal
# Date created:				2012-08-17
# Whom:					Nicole Reid <root@cooltrainer.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/deskutils/mate-file-manager-open-terminal/Makefile,v 1.1 2012/08/19 15:21:30 mezz Exp $
#

PORTNAME=	mate-file-manager-open-terminal
PORTVERSION=	1.4.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Caja extension which allows you to open a terminal

USE_XZ=		yes
USE_MATE=	autogen caja common:build conf desktop intlhack matehack
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env \
		autoheader:env
CONFIGURE_ARGS=	${MATECONF_PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MATECONF_SCHEMAS=caja-open-terminal.schemas

.include <bsd.port.mk>
