# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-media
PORTVERSION=	1.6.0
CATEGORIES=	audio mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the MATE desktop

LIB_DEPENDS=	canberra-gtk:${PORTSDIR}/audio/libcanberra

USE_XZ=		yes
USE_MATE=	autogen common:build desktop docutils intlhack ltverhack \
		matehack panel
USE_GMAKE=	yes
USE_GNOME=	gnomehier glib20 gnomehier gtk20 libxml2
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_GSTREAMER=	good
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-pulseaudio \
		--enable-gst-mixer-applet
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.panel.applet.mixer.gschema.xml \
		org.mate.volume-control.gschema.xml

.include <bsd.port.mk>
