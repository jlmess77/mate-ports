# New ports collection makefile for:	gnomemedia2
# Date created:				06 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/audio/mate-media/Makefile,v 1.2 2012/08/23 08:23:12 kwm Exp $
#

PORTNAME=	mate-media
PORTVERSION=	1.4.0
CATEGORIES=	audio mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Multimedia applications for the MATE desktop

LIB_DEPENDS=	canberra-gtk:${PORTSDIR}/audio/libcanberra

USE_XZ=		yes
USE_MATE=	autogen common:build conf docutils intlhack ltverhack matehack
USE_GMAKE=	yes
USE_GNOME=	gnomehier glib20 gtk20 libxml2
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_GSTREAMER=	gconf good
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-pulseaudio \
		${MATECONF_PREFIX}
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MATECONF_SCHEMAS=mate-audio-profiles.schemas \
		 mate-volume-control.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|gladeui-1.0|gladeui-1.0.disable|g' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
