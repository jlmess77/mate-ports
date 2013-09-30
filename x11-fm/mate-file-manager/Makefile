# Created by: ade, archie
# $FreeBSD$

PORTNAME=	mate-file-manager
PORTVERSION=	1.6.1
CATEGORIES=	x11-fm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT?=	File manager for the MATE desktop

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libexempi.so:${PORTSDIR}/textproc/exempi
RUN_DEPENDS=	${LOCALBASE}/libexec/gvfsd:${PORTSDIR}/devel/gvfs

USES=		desktop-file-utils gettext gmake pkgconfig shared-mime-info
USE_XZ=		yes
USE_MATE=	autogen common:build desktop icontheme:run intlhack \
		ltasneededhack ltverhack matehack
USE_XORG=	ice x11 xrender
USE_GNOME=	glib20 gnomehier gtk20 introspection:build libxml2 pango
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		LIBPNG="-L${LOCALBASE}/lib -lpng -lz"
CONFIGURE_ARGS=	--enable-static \
		--disable-packagekit \
		--with-gtk=2.0 \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include

GLIB_SCHEMAS=	org.mate.caja.gschema.xml \
		org.mate.media-handling.gschema.xml

MAN1=		caja.1 caja-connect-server.1 caja-file-management-properties.1

NO_STAGE=	yes
post-install:
	@${MKDIR} ${PREFIX}/lib/caja/extensions-2.0

.include <bsd.port.mk>
