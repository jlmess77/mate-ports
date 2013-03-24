# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-backgrounds
PORTVERSION=	1.5.0
CATEGORIES=	x11-themes graphics mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of backgrounds for MATE

USE_XZ=		yes
USE_MATE=	autogen common:build intlhack matehack
USE_GNOME=	glib20
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
