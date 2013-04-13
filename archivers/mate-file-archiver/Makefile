# Created by: Anders Nordby <anders@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-file-archiver
PORTVERSION=	1.6.0
CATEGORIES=	archivers mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An archive manager for zip files, tar, etc

RUN_DEPENDS=	${LOCALBASE}/bin/gtar:${PORTSDIR}/archivers/gtar \
    		${LOCALBASE}/bin/unzip:${PORTSDIR}/archivers/unzip

USE_XZ=		yes
USE_MATE=	autogen caja common:build docutils intlhack matehack
USE_XORG=	sm
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gnomehier gtk20
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
CONFIGURE_ARGS=	--disable-packagekit \
		--with-gtk=2.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.engrampa.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/fr-command-tar.c \
		${WRKSRC}/src/fr-command-zip.c

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
