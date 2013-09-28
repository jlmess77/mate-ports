# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-calc
PORTVERSION=	1.6.0
CATEGORIES=	math mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE calculator tool based on the old calctool for OpenWindows

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex

USES=		bison gettext gmake pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack matehack
USE_GNOME=	glib20 gnomehier gtk20 libxml2
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mate-calc.1 mate-calc-cmd.1
GLIB_SCHEMAS=	org.mate.calc.gschema.xml

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|$$(LEX)|${LOCALBASE}/bin/flex|g' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
