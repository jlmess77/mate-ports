# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-icon-theme
PORTVERSION=	1.6.0
CATEGORIES=	x11-themes mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of icons for the MATE desktop

BUILD_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		icon-naming-utils>=0.8.7:${PORTSDIR}/x11-themes/icon-naming-utils
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_XZ=		yes
USE_MATE=	autogen common:build intlhack matehack
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

pre-install:
	@${REINPLACE_CMD} -e 's|install: install-data|install:|g' \
		${WRKSRC}/po/Makefile

.include <bsd.port.mk>
