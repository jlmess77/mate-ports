# Created by: ade, archie
# $FreeBSD$

PORTNAME=	mate-file-manager
PORTVERSION=	1.6.1
CATEGORIES=	x11-fm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the MATE desktop

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		g-ir-compiler:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	exif:${PORTSDIR}/graphics/libexif \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		exempi:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/libexec/gvfsd:${PORTSDIR}/devel/gvfs

USES=		desktop-file-utils shared-mime-info
USE_XZ=		yes
USE_MATE=	autogen common:build desktop icontheme:run intlhack \
		ltasneededhack ltverhack matehack
USE_XORG=	ice x11 xrender
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20 libxml2 pango
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -liconv" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--enable-static \
		--disable-packagekit \
		--with-gtk=2.0 \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

GLIB_SCHEMAS=	org.mate.caja.gschema.xml \
		org.mate.media-handling.gschema.xml

MAN1=		caja.1 caja-connect-server.1 caja-file-management-properties.1

post-install:
	@${MKDIR} ${PREFIX}/lib/caja/extensions-2.0

.include <bsd.port.mk>
