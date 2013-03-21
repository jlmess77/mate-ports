# New ports collection makefile for:	gnome2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/mate/Makefile,v 1.3 2012/09/05 02:43:27 mezz Exp $
#

PORTNAME=	mate
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	x11 mate
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The "meta-port" for the MATE integrated X11 desktop

RUN_DEPENDS=	mate-base>=1.4.0:${PORTSDIR}/x11/mate-base \
		mate-themes>=1.4.0:${PORTSDIR}/x11-themes/mate-themes \
		mate-icon-theme-faenza>=1.4.0:${PORTSDIR}/x11-themes/mate-icon-theme-faenza \
		mate-terminal:${PORTSDIR}/x11/mate-terminal \
		mate-screensaver:${PORTSDIR}/x11/mate-screensaver \
		mate-calc:${PORTSDIR}/math/mate-calc \
		mateconf-editor:${PORTSDIR}/sysutils/mate-conf-editor \
		mate-screenshot:${PORTSDIR}/deskutils/mate-utils \
		mate-system-monitor:${PORTSDIR}/sysutils/mate-system-monitor \
		eom:${PORTSDIR}/graphics/mate-image-viewer \
		engrampa:${PORTSDIR}/archivers/mate-file-archiver \
		atril:${PORTSDIR}/graphics/mate-document-viewer \
		mate-audio-profiles-properties:${PORTSDIR}/audio/mate-media \
		mate-power-manager:${PORTSDIR}/sysutils/mate-power-manager \
		mozo:${PORTSDIR}/deskutils/mate-menu-editor \
		mate-applets>=1.4.0:${PORTSDIR}/x11/mate-applets

USE_MATE=	pluma:run 

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
