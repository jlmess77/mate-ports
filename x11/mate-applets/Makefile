# New ports collection makefile for:	gnomeapplets2
# Date created:				26th May 2000
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/mate-applets/Makefile,v 1.1 2012/07/29 22:22:19 mezz Exp $
#

PORTNAME=	mate-applets
PORTVERSION=	1.4.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the MATE Desktop Environment

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/rarian
LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop \
		xklavier:${PORTSDIR}/x11/libxklavier \
		dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit \
		hal:${PORTSDIR}/sysutils/hal \
		upower-glib:${PORTSDIR}/sysutils/upower

USE_XZ=		yes
USE_MATE=	autogen common:build conf desktop docutils icontheme intlhack \
		libmatenotify libmateweather libmatewnck matehack panel \
		polkit settingsdaemon
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gtk20 libxml2 libxslt
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_GSTREAMER=	yes
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-mixer-applet \
		--disable-networkmanager \
		--enable-mini-commander \
		${MATECONF_PREFIX}
CONFIGURE_ENV=	OS_SYS="/usr/include"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MATECONF_SCHEMAS=charpick.schemas drivemount.schemas geyes.schemas \
		 mini-commander-global.schemas mini-commander.schemas \
		 mixer.schemas multiload.schemas stickynotes.schemas

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CFLAGS+=	-fPIC
PLIST_SUB=	BATTERY="@comment "
.else
MATECONF_SCHEMAS+=battstat.schemas
PLIST_SUB=	BATTERY=""
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	CPUFREQ="@comment "
.else
PLIST_SUB+=	CPUFREQ=""
MATECONF_SCHEMAS+=cpufreq-applet.schemas
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|" == "|" = "|g'
	@${REINPLACE_CMD} -e 's|pygtk-2|pygtk-2_disabled|' \
		${WRKSRC}/configure.in

.include <bsd.port.post.mk>
