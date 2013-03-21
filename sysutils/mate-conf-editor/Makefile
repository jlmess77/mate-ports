# New ports collection makefile for:	gconf-editor
# Date created:				12 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/sysutils/mate-conf-editor/Makefile,v 1.1 2012/07/28 17:38:10 mezz Exp $
#

PORTNAME=	mate-conf-editor
PORTVERSION=	1.4.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A mate-conf database editor for the MATE environment

LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib

USE_XZ=		yes
USE_MATE=	autogen common:build conf docutils intlhack matehack
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0 \
		${MATECONF_PREFIX}
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		mateconf-editor.1
MATECONF_SCHEMAS=mateconf-editor.schemas

.include <bsd.port.mk>
