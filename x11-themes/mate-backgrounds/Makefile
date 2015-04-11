# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD: head/x11-themes/mate-backgrounds/Makefile 367830 2014-09-10 13:11:28Z bapt $

PORTNAME=	mate-backgrounds
PORTVERSION=	1.8.0
CATEGORIES=	x11-themes graphics mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Collection of backgrounds for MATE

PORTSCOUT=	limitw:1,even

USES=		gettext gmake pathfix tar:xz
USE_GNOME=	glib20 intlhack
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
