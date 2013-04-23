# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-power-manager
PORTVERSION=	1.6.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Power management system for the MATE Desktop

LIB_DEPENDS=	canberra-gtk:${PORTSDIR}/audio/libcanberra \
		dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		cairo:${PORTSDIR}/graphics/cairo \
		unique-1.0:${PORTSDIR}/x11-toolkits/unique \
		upower-glib:${PORTSDIR}/sysutils/upower \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		notify:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	pkexec:${PORTSDIR}/sysutils/polkit

USES=		pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack libmatekeyring \
		matehack panel
USE_XORG=	x11 xext xproto xrandr xrender
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--with-gtk=2.0 \
		--with-systemdinhibit=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.power-manager.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e "s|docbook2man|docbook2man_disabled|g" \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
