# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD: ports/x11/gnome2/Makefile,v 1.172 2012/02/16 15:57:29 ashish Exp $
#   $MCom: ports-experimental/x11/mate-base/Makefile,v 1.3 2012/09/05 22:29:14 mezz Exp $
#

PORTNAME=	mate-base
PORTVERSION=	1.4.0
CATEGORIES=	x11 mate
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the MATE base integrated X11 desktop

RUN_DEPENDS=	${LOCALBASE}/lib/X11/fonts/dejavu/DejaVuSerif.ttf:${PORTSDIR}/x11-fonts/dejavu \
		${LOCALBASE}/share/hal/fdi/information/10freedesktop/10-camera-ptp.fdi:${PORTSDIR}/sysutils/hal-info \
		${LOCALBASE}/share/mate-background-properties/mate-desktop.xml:${PORTSDIR}/x11-themes/mate-backgrounds \
		${LOCALBASE}/bin/mate-session:${PORTSDIR}/x11/mate-session-manager \
		mate-themes>=1.4.0:${PORTSDIR}/x11-themes/mate-themes \
		mate-icon-theme-faenza>=1.4.0:${PORTSDIR}/x11-themes/mate-icon-theme-faenza

USE_MATE=	caja:run controlcenter:run dialogs:run icontheme:run \
		keyring:run marco:run notificationdaemon:run panel:run \
		polkit:run

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
