# Createdy by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	mate-notification-daemon
PORTVERSION=	1.6.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Send small notifications to your desktop

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		canberra-gtk:${PORTSDIR}/audio/libcanberra \
		notify:${PORTSDIR}/devel/libnotify

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build intlhack libmatewnck matehack
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20 librsvg2
USE_GETTEXT=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-dbus-services=${PREFIX}/share/dbus-1/services \
		--with-gtk=2.0
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.NotificationDaemon.gschema.xml

.include <bsd.port.mk>
