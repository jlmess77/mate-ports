# New ports collection makefile for:	gnomeutils2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/deskutils/mate-utils/Makefile,v 1.1 2012/07/28 17:38:10 mezz Exp $
#

PORTNAME=	mate-utils
PORTVERSION=	1.4.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE support utilities

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		scrollkeeper-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop \
		canberra-gtk:${PORTSDIR}/audio/libcanberra

USE_XZ=		yes
USE_MATE=	autogen common:build conf docutils intlhack ltverhack \
		matehack panel
USE_XORG=	x11 xext
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
CONFIGURE_ARGS=	--enable-maintainer-flags=no \
		${MATECONF_PREFIX} \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mate-dictionary.1 mate-disk-usage-analyzer.1 \
		mate-screenshot.1 mate-search-tool.1 mate-system-log.1
MATECONF_SCHEMAS=baobab.schemas mate-dictionary.schemas \
		 mate-screenshot.schemas mate-search-tool.schemas \
		 mate-system-log.schemas

.include <bsd.port.mk>
