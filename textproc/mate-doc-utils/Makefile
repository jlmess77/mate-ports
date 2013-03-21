# New ports collection makefile for:	gnome-doc-utils
# Date created:				11 November 2004
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/textproc/mate-doc-utils/Makefile,v 1.5 2012/07/28 05:23:52 mezz Exp $
#

PORTNAME=	mate-doc-utils
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	textproc mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE doc utils

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian \
		${PYTHON_SITELIBDIR}/libxml2mod.so:${PORTSDIR}/textproc/py-libxml2 \
    		gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian \
		${LOCALBASE}/share/xml/docbook/4.3/catalog.xml:${PORTSDIR}/textproc/docbook-xml-430 \
		${LOCALBASE}/share/xml/docbook/4.4/catalog.xml:${PORTSDIR}/textproc/docbook-xml-440 \
		xml2po:${PORTSDIR}/textproc/gnome-doc-utils

USE_XZ=		yes
USE_MATE=	autogen common:build matehack intlhack
USE_GMAKE=	yes
USE_GNOME=	libxml2 libxslt
USE_PYTHON=	build
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-omf-dir=${PREFIX}/share/omf
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|-W compat|--traditional|g' \
		${WRKSRC}/configure.in

pre-install:
	@${REINPLACE_CMD} -e 's|build_SUBDIRS = xml2po|build_SUBDIRS =|g ; \
		s|po rng xslt|po xslt|g' \
			${WRKSRC}/Makefile

.include <bsd.port.mk>
