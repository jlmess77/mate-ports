# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-applets
PORTVERSION=	1.6.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the MATE Desktop Environment

BUILD_DEPENDS=	g-ir-scanner:${PORTSDIR}/devel/gobject-introspection
LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop \
		xklavier:${PORTSDIR}/x11/libxklavier \
		dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		polkit-gobject-1:${PORTSDIR}/sysutils/polkit \
		hal:${PORTSDIR}/sysutils/hal \
		upower-glib:${PORTSDIR}/sysutils/upower \
		notify:${PORTSDIR}/devel/libnotify

USE_XZ=		yes
USE_MATE=	autogen common:build desktop docutils icontheme intlhack \
		libmateweather libmatewnck matehack mucharmap panel \
		polkit settingsdaemon
USE_XORG=	x11
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf2 glib20 gnomehier gtk20 libxml2 libxslt pygobject \
		pygtk2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--enable-mixer-applet \
		--disable-networkmanager
CONFIGURE_ENV=	OS_SYS="/usr/include"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

GLIB_SCHEMAS=	org.mate.panel.applet.charpick.gschema.xml \
		org.mate.panel.applet.geyes.gschema.xml \
		org.mate.panel.applet.multiload.gschema.xml \
		org.mate.stickynotes.gschema.xml

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CFLAGS+=	-fPIC
PLIST_SUB+=	BATTERY="@comment "
.else
GLIB_SCHEMAS+=	org.mate.panel.applet.battstat.gschema.xml
PLIST_SUB+=	BATTERY=""
.endif

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
PLIST_SUB+=	CPUFREQ="@comment "
.else
PLIST_SUB+=	CPUFREQ=""
GLIB_SCHEMAS+=	org.mate.panel.applet.cpufreq.gschema.xml
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} ${REINPLACE_CMD} -e \
	    	's|" == "|" = "|g'

.include <bsd.port.post.mk>
