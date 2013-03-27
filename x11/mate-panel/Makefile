# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-panel
PORTVERSION=	1.5.6
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
		cairo:${PORTSDIR}/graphics/cairo \
		dconf:${PORTSDIR}/devel/dconf

USE_XZ=		yes
USE_MATE=	autogen common:build desktop docutils intlhack \
		libmateweather libmatewnck ltverhack matehack menus
USE_XORG=	ice sm x11 xau xrandr
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gnomehier gtk20 librsvg2 pango
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-network-manager \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		--libexecdir=${PREFIX}/lib/mate-panel
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

MAN1=		mate-panel.1
GLIB_SCHEMAS=	org.mate.panel.applet.clock.gschema.xml \
		org.mate.panel.applet.fish.gschema.xml \
		org.mate.panel.applet.window-list.gschema.xml \
		org.mate.panel.applet.workspace-switcher.gschema.xml \
		org.mate.panel.enums.xml \
		org.mate.panel.gschema.xml \
		org.mate.panel.object.gschema.xml \
		org.mate.panel.toplevel.gschema.xml

post-install:
	@${MKDIR} ${PREFIX}/lib/mate-panel/modules
	-${LOCALBASE}/bin/gio-querymodules ${PREFIX}/lib/mate-panel/modules

.include <bsd.port.mk>
