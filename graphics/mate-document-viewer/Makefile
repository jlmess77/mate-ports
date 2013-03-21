# New ports collection makefile for:	atril
# Date created:				09 January 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/graphics/mate-document-viewer/Makefile,v 1.4 2012/08/22 13:45:43 kwm Exp $
#

PORTNAME=	mate-document-viewer
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	graphics print mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE multi-format document viewer

BUILD_DEPENDS=	gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	poppler-glib:${PORTSDIR}/graphics/poppler-glib \
		spectre:${PORTSDIR}/print/libspectre \
		cairo:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_XZ=		yes
USE_MATE=	autogen common:build conf docutils icontheme intlhack \
		ltasneededhack ltverhack matehack
USE_XORG=	sm
USE_GMAKE=	yes
USE_GNOME=	desktopfileutils glib20 gtk20 libxml2
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		${MATECONF_PREFIX}
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.Atril.gschema.xml
MATECONF_SCHEMAS=atril-thumbnailer.schemas \
		 atril-thumbnailer-ps.schemas

MAN1=		atril.1

OPTIONS=	DVI	"Enable DVI viewer support"		off \
		T1LIB	"Enable T1LIB for TYPE1 fonts to DVI (Enables DVI)"	off \
		CAJA	"Enable Nautilus plugin"		on  \
		KEYRING	"Enable Gnome-Keyring without Nautilus" on \
		DBUS	"Enable D-BUS support"			on \
		COMICS	"Enable comic book archives support"	on \
		IMPRESS	"Enable Impress presentations support"	off \
		DJVU	"Enable DJVU support"			off

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) || exists(${LOCALBASE}/lib/libdbus-glib-1.so)
WITH_DBUS=	yes
.endif

.if defined(WITH_DVI) || defined(WITH_T1LIB) || exists(${LOCALBASE}/lib/libkpathsea.a)
BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base

CONFIGURE_ARGS+=--enable-dvi
MATECONF_SCHEMAS+=atril-thumbnailer-dvi.schemas
PLIST_SUB+=	DVI=""
. if defined(WITH_T1LIB)
LIB_DEPENDS+=	t15:${PORTSDIR}/devel/t1lib

CONFIGURE_ARGS+=--enable-t1lib
. endif
.else
PLIST_SUB+=	DVI="@comment "
.endif

.if !defined(WITHOUT_CAJA)
USE_MATE+=	caja
CONFIGURE_ARGS+=--enable-caja
PLIST_SUB+=	CAJA=""
.else
CONFIGURE_ARGS+=--disable-caja
PLIST_SUB+=	CAJA="@comment "
.endif

. if !defined(WITHOUT_KEYRING)
USE_MATE+=	libmatekeyring
. else
CONFIGURE_ARGS+=--without-keyring
. endif

.if defined(WITH_IMPRESS)
CONFIGURE_ARGS+=--enable-impress
PLIST_SUB+=	IMPRESS=""
.else
CONFIGURE_ARGS+=--disable-impress
PLIST_SUB+=	IMPRESS="@comment "
.endif

.if defined(WITH_DJVU)
LIB_DEPENDS+=	djvulibre:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=--enable-djvu
MATECONF_SCHEMAS+=atril-thumbnailer-djvu.schemas
PLIST_SUB+=	DJVU=""
.else
CONFIGURE_ARGS+=--disable-djvu
PLIST_SUB+=	DJVU="@comment "
.endif

.if !defined(WITHOUT_DBUS)
LIB_DEPENDS+=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
.endif

.if !defined(WITHOUT_COMICS)
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
CONFIGURE_ARGS+=--enable-comics
MATECONF_SCHEMAS+=atril-thumbnailer-comics.schemas
PLIST_SUB+=	COMICS=""
.else
CONFIGURE_ARGS+=--disable-comics
PLIST_SUB+=	COMICS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|AC_CHECK_HEADERS([execinfo.h])||g' \
		-e 's|" == "|" = "|g' \
			${WRKSRC}/configure.ac

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
