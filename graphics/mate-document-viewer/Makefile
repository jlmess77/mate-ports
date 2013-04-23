# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-document-viewer
PORTVERSION=	1.6.0
CATEGORIES=	graphics print mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE multi-format document viewer

BUILD_DEPENDS=	gtkdoc-scan:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	poppler-glib:${PORTSDIR}/graphics/poppler-glib \
		spectre:${PORTSDIR}/print/libspectre \
		cairo:${PORTSDIR}/graphics/cairo \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USES=		desktop-file-utils pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build docutils icontheme intlhack \
		ltasneededhack ltverhack matehack
USE_XORG=	sm
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20 libxml2
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.Atril.gschema.xml
MAN1=		atril.1

OPTIONS_DEFINE=	DVI T1LIB CAJA KEYRING COMICS IMPRESS DJVU
OPTIONS_DEFAULT=CAJA KEYRING COMICS
DVI_DESC=	DVI viewer support
T1LIB_DESC=	T1LIB for TYPE1 fonts to DVI (Enables DVI)
CAJA_DESC=	Caja plugin
KEYRING_DESC=	Gnome-Keyring without Nautilus
COMICS_DESC=	Comic book archives support
IMPRESS_DESC=	Impress presentations support
DJVU_DESC=	DJVU support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVI} || ${PORT_OPTIONS:MT1LIB}
BUILD_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS+=	tex:${PORTSDIR}/print/teTeX-base
CONFIGURE_ARGS+=--enable-dvi
PLIST_SUB+=	DVI=""

. if ${PORT_OPTIONS:MT1LIB}
LIB_DEPENDS+=	t15:${PORTSDIR}/devel/t1lib
CONFIGURE_ARGS+=--enable-t1lib
. endif

.else
PLIST_SUB+=	DVI="@comment "
.endif

.if ${PORT_OPTIONS:MCAJA}
USE_MATE+=	caja
CONFIGURE_ARGS+=--enable-caja
PLIST_SUB+=	CAJA=""
.else
CONFIGURE_ARGS+=--disable-caja
PLIST_SUB+=	CAJA="@comment "
.endif

.if ${PORT_OPTIONS:MKEYRING}
USE_MATE+=	libmatekeyring
. else
CONFIGURE_ARGS+=--without-keyring
. endif

.if ${PORT_OPTIONS:MIMPRESS}
CONFIGURE_ARGS+=--enable-impress
PLIST_SUB+=	IMPRESS=""
.else
CONFIGURE_ARGS+=--disable-impress
PLIST_SUB+=	IMPRESS="@comment "
.endif

.if ${PORT_OPTIONS:MDJVU}
LIB_DEPENDS+=	djvulibre:${PORTSDIR}/graphics/djvulibre
CONFIGURE_ARGS+=--enable-djvu
PLIST_SUB+=	DJVU=""
.else
CONFIGURE_ARGS+=--disable-djvu
PLIST_SUB+=	DJVU="@comment "
.endif

.if ${PORT_OPTIONS:MCOMICS}
RUN_DEPENDS+=	unzip:${PORTSDIR}/archivers/unzip
CONFIGURE_ARGS+=--enable-comics
PLIST_SUB+=	COMICS=""
.else
CONFIGURE_ARGS+=--disable-comics
PLIST_SUB+=	COMICS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|AC_CHECK_HEADERS([execinfo.h])||g' \
		-e 's|" == "|" = "|g' \
			${WRKSRC}/configure.ac

.include <bsd.port.mk>
