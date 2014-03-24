# Created by: Koop Mast<kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-polkit
PORTVERSION=	1.8.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE frontend to the PolicKit framework

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig
USE_XZ=		yes
USE_GNOME=	gnomehier gtk20 intlhack introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--localstatedir=/var
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libpolkit-gtk-mate-1.so.0.0.0

.include <bsd.port.mk>
