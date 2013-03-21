# New ports collection makefile for:   metacity
# Date created:        21 May 2002
# Whom:                Garrett Rooney <rooneg@electricjellyfish.net>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11-wm/mate-window-manager/Makefile,v 1.4 2012/07/27 17:45:05 mezz Exp $
#

PORTNAME=	mate-window-manager
PORTVERSION=	1.4.0
CATEGORIES=	x11-wm mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A window manager for the adult in you

LIB_DEPENDS=	startup-notification-1:${PORTSDIR}/x11/startup-notification \
		canberra-gtk:${PORTSDIR}/audio/libcanberra

USE_XZ=		yes
USE_MATE=	autogen common:build conf dialogs docutils intlhack ltverhack \
		matehack
USE_XORG=	x11 xcomposite xcursor xdamage xrandr
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gtk20 pango
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		${MATECONF_PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	G_CHARSET_ALIAS="${LOCALBASE}/libdata/charset.alias"

MATECONF_SCHEMAS=marco.schemas

MAN1=		marco-message.1 marco-theme-viewer.1 marco-window-demo.1 \
		marco.1

.include <bsd.port.mk>
