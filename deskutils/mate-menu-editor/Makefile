# New ports collection makefile for:	menueditor
# Date created:				22 March 2005
# Whom:					FreeBSD GNOME Team
#
# $FreeBSD$
#    $MCom: ports-experimental/deskutils/mate-menu-editor/Makefile,v 1.1 2012/07/29 17:29:11 mezz Exp $
#

PORTNAME=	mate-menu-editor
PORTVERSION=	1.4.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An editor for the freedesktop.org menu specification

USE_XZ=		yes
USE_MATE=	autogen common:build intlhack matehack menus
USE_GMAKE=	yes
USE_GNOME=	pygobject pygtk2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
	    ${WRKSRC}/Mozo/util.py

.include <bsd.port.mk>
