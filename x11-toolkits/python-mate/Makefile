# New ports collection makefile for:	py-gnome
# Date created:				09 February 2003
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11-toolkits/python-mate/Makefile,v 1.2 2012/08/05 17:04:12 mezz Exp $
#

PORTNAME=	python-mate
PORTVERSION=	1.4.0
CATEGORIES=	x11-toolkits python mate
MASTER_SITES=	MATE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A set of Python bindings for MATE

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc	

USE_XZ=		yes
USE_MATE=	autogen canvas common:build component componentui conf corba \
		libmate libmateui matehack pycorba vfs
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 pygobject pygtk2
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include

EG_SRC_DIR=	${WRKSRC}/examples
EG_DST_DIR=	${EXAMPLESDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|\./libtool|${LIBTOOL}|g' \
		${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|$$(datadir)/gtk-doc/html|${PREFIX}/share/doc|g' \
		${WRKSRC}/docs/pygtk-ref-docs.make

.if !defined(NOPORTEXAMPLES)
post-install:
	${MKDIR} ${EG_DST_DIR}
	${TAR} -C ${EG_SRC_DIR} -cf - . | ${TAR} -C ${EG_DST_DIR} -xf -
	${CHOWN} -R ${BINOWN}:${BINGRP} ${EG_DST_DIR}
	${FIND} ${EG_DST_DIR} -type d -print | ${XARGS} ${CHMOD} 0755
	${FIND} ${EG_DST_DIR} -type f -print | ${XARGS} ${CHMOD} 0444
.endif

.include <bsd.port.mk>
