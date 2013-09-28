# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmateweather
PORTVERSION=	1.6.1
CATEGORIES=	net mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to accessing online weather informations

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

USES=		gettext gmake pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build intlhack ltverhack matehack
USE_GNOME=	glib20 gtk20 libxml2
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.weather.gschema.xml

NO_STAGE=	yes
.include <bsd.port.mk>
