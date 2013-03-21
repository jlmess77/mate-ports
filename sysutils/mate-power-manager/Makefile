# New ports collection makefile for:	gnome-power-manager
# Date created:				03 May 2006
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/sysutils/mate-power-manager/Makefile,v 1.1 2012/07/29 04:54:54 mezz Exp $
#

PORTNAME=	mate-power-manager
PORTVERSION=	1.4.0
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
		execinfo:${PORTSDIR}/devel/libexecinfo
RUN_DEPENDS=	pkexec:${PORTSDIR}/sysutils/polkit

USE_XZ=		yes
USE_MATE=	autogen common:build conf docutils intlhack libmatekeyring \
		libmatenotify matehack panel
USE_XORG=	x11 xext xproto xrandr xrender
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--with-doc-dir=${PREFIX}/share/doc \
		--disable-docbook-docs \
		--with-gtk=2.0 \
		${MATECONF_PREFIX}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MATECONF_SCHEMAS=mate-power-manager.schemas

.if !defined(NO_INSTALL_MANPAGES)
BUILD_DEPENDS+=	docbook2html:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/dtd/catalog:${PORTSDIR}/textproc/docbook-410
MAN1=		mate-power-manager.1 mate-power-preferences.1 \
		mate-power-statistics.1
.endif

post-patch:
.if defined(NO_INSTALL_MANPAGES)
	@${REINPLACE_CMD} -e "s|docbook2man|docbook2man_disabled|g" \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
