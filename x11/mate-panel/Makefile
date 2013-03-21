# New ports collection makefile for:	gnomepanel
# Date created:				27 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/mate-panel/Makefile,v 1.5 2012/10/25 09:14:40 kwm Exp $
#

PORTNAME=	mate-panel
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the MATE Desktop

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		canberra-gtk:${PORTSDIR}/audio/libcanberra \
		cairo:${PORTSDIR}/graphics/cairo

CONFLICT=	gnome-panel-*

USE_XZ=		yes
USE_MATE=	autogen common:build componentui conf corba desktop docutils \
		intlhack libmateweather libmatewnck ltverhack matehack menus
USE_XORG=	ice sm x11 xau xrandr
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gtk20 librsvg2 pango
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-network-manager \
		--disable-eds \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		${MATECONF_PREFIX}
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		mate-panel.1
MATECONF_SCHEMAS=clock.schemas fish.schemas panel-compatibility.schemas \
		 panel-general.schemas panel-global.schemas \
		 panel-object.schemas panel-toplevel.schemas \
		 window-list.schemas workspace-switcher.schemas

post-install:
	@${MKDIR} ${PREFIX}/lib/mate-panel/modules
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/mate-panel/modules

.include <bsd.port.mk>
