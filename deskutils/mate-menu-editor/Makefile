# Created by: FreeBSD GNOME Team
# $FreeBSD$

PORTNAME=	mate-menu-editor
PORTVERSION=	1.6.0
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
