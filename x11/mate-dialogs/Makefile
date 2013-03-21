# New ports collection makefile for:	zenity
# Date created:				01 Mar 2003
# Whom:					Franz Klammer <klammer@webonaut.com>
#
# $FreeBSD$
#   $MCom: ports-experimental/x11/mate-dialogs/Makefile,v 1.3 2012/07/27 01:34:26 mezz Exp $
#

PORTNAME=	mate-dialogs
PORTVERSION=	1.4.0
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Display MATE dialogs from the command line

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack matehack
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-gtk=2.0
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

MAN1=		matedialog.1

OPTIONS=	MATENOTIFY "Enable libnotify support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_MATENOTIFY)
USE_MATE+=	libmatenotify
CONFIGURE_ARGS+=--enable-libmatenotify
.else
CONFIGURE_ARGS+=--disable-libmatenotify
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|bin_SCRIPTS = gdialog||g' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.post.mk>
