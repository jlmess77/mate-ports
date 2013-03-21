# New ports collection makefile for:	gnome-icon-theme
# Date Created:				05 October 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11-themes/mate-icon-theme-faenza/Makefile,v 1.1 2012/07/26 04:37:55 mezz Exp $
#

PORTNAME=	mate-icon-theme-faenza
PORTVERSION=	1.4.0
CATEGORIES=	x11-themes mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A collection of Faenza and Faience icons for the MATE desktop

USE_XZ=		yes
NO_BUILD=	yes
INSTALLS_ICONS=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/icons
	@(cd ${WRKSRC} && ${FIND} matefaenza -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/icons)
	@(cd ${WRKSRC} && ${FIND} matefaenzadark -name '*[^~]' | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/icons)

.include <bsd.port.mk>
