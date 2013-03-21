# New ports collection makefile for:   orbit2
# Date Created:			16 Aug 1998
# Whom:				Chia-liang Kao <clkao@CirX.ORG>
#
# $FreeBSD$
#   $MCom: ports-experimental/devel/mate-corba/Makefile,v 1.5 2012/07/27 03:18:08 mezz Exp $
#

PORTNAME=	mate-corba
PORTVERSION=	1.4.0
CATEGORIES=	devel mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	High-performance CORBA ORB with support for the C language

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc

USE_XZ=		yes
USE_MATE=	autogen common:build ltverhack matehack
USE_GMAKE=	yes
USE_GNOME=	glib20 libidl
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-html-dir=${PREFIX}/share/doc \
		--disable-gtk-doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/orb/orb-core/matecorba-typelib.c

post-install:
	@${ECHO_CMD} "ORBIIOPIPv4=0" > ${PREFIX}/etc/matecorbarc.default
	@${ECHO_CMD} "ORBIIOPIPv6=0" >> ${PREFIX}/etc/matecorbarc.default
	@if [ ! -f ${PREFIX}/etc/matecorbarc ]; then \
		${CP} -p ${PREFIX}/etc/matecorbarc.default ${PREFIX}/etc/matecorbarc ; \
	fi
	@${MKDIR} ${PREFIX}/lib/matecorba-2.0/idl-backends

.include <bsd.port.mk>
