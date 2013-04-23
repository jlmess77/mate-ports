# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-terminal
PORTVERSION=	1.6.1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Terminal component for the MATE Desktop

LIB_DEPENDS=	dconf:${PORTSDIR}/devel/dconf

USES=		pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack matehack
USE_XORG=	sm x11
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20 vte
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mate-terminal.1
GLIB_SCHEMAS=	org.mate.terminal.gschema.xml

.include <bsd.port.mk>
