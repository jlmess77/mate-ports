# New ports collection makefile for:	notification-daemon
# Date created:				2005-08-06
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#   $MCom: ports-experimental/deskutils/mate-notification-daemon/Makefile,v 1.4 2012/07/28 05:20:16 mezz Exp $
#

PORTNAME=	mate-notification-daemon
PORTVERSION=	1.4.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		canberra-gtk:${PORTSDIR}/audio/libcanberra

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XZ=		yes
USE_MATE=	autogen common:build conf intlhack libmatenotify libmatewnck \
		matehack
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 librsvg2
USE_GETTEXT=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services \
		--with-gtk=2.0 \
		${MATECONF_PREFIX}
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MATECONF_SCHEMAS=mate-notification-daemon.schemas

.include <bsd.port.mk>
