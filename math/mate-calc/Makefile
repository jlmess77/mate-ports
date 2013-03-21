# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports-experimental/math/mate-calc/Makefile,v 1.3 2013/03/09 09:44:23 kwm Exp $

PORTNAME=	mate-calc
PORTVERSION=	1.4.0
CATEGORIES=	math mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A MATE calculator tool based on the old calctool for OpenWindows

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack matehack
USES=		bison
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 libxml2
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libtool
USE_PKGCONFIG=	build
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mate-calc.1
GLIB_SCHEMAS=	org.mate.mate-calc.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e 's|$$(LEX)|${LOCALBASE}/bin/flex|g' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
