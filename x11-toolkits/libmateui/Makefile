# Created by: Joe Marcus Clarke <marcus@FreBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/x11-toolkits/libmateui/Makefile,v 1.6 2013/03/09 09:44:23 kwm Exp $

PORTNAME=	libmateui
PORTVERSION=	1.4.0
CATEGORIES=	x11-toolkits mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for the MATE GUI, a GNU desktop environment

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS+=	popt:${PORTSDIR}/devel/popt

USE_XZ=		yes
USE_MATE=	autogen canvas common:build componentui conf icontheme:run \
		libmate libmatekeyring ltverhack matehack vfs
USE_XORG=	sm
USES=		bison
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gtk20 libglade2 libxml2 pango
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-gtk=2.0 \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include

.include <bsd.port.mk>
