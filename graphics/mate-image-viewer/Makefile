# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-image-viewer
PORTVERSION=	1.5.1
CATEGORIES=	graphics mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The Eye of MATE image viewer

BUILD_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

USE_XZ=		yes
USE_MATE=	autogen common:build desktop docutils icontheme matehack
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils gdkpixbuf2 glib20 gnomehier gtk20 \
		librsvg2 libxml2
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		--disable-python \
		--without-cms
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.eom.gschema.xml

_WITH_EXIF=	no
_WITH_EXEMPI=	no

.if !defined(WITHOUT_EXIF) || (exists(${LOCALBASE}/lib/libexif.so) || \
	defined(WITH_EXIF))
LIB_DEPENDS+=	exif:${PORTSDIR}/graphics/libexif
PLIST_SUB+=	EXIF=""
_WITH_EXIF=	yes
.else
PLIST_SUB+=	EXIF="@comment "
.endif

.if !defined(WITHOUT_EXEMPI) || (exists(${LOCALBASE}/lib/libexempi.so)) || \
    	defined(WITH_EXEMPI)
LIB_DEPENDS+=	exempi:${PORTSDIR}/textproc/exempi
_WITH_EXEMPI=	yes
.endif

.if ${_WITH_EXIF}=="yes" || ${_WITH_EXEMPI}=="yes"
PLIST_SUB+=	EXIFEXEMPI=""
.else
PLIST_SUB+=	EXIFEXEMPI="@comment "
.endif

post-install:
	@-update-desktop-database > /dev/null

.include <bsd.port.mk>
