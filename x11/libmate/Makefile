# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$
#   $MCom: ports-experimental/x11/libmate/Makefile,v 1.6 2013/03/09 09:44:23 kwm Exp $

PORTNAME=	libmate
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Libraries for MATE, a GNU desktop environment

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	canberra-gtk:${PORTSDIR}/audio/libcanberra \
		popt:${PORTSDIR}/devel/popt
RUN_DEPENDS=	${LOCALBASE}/share/sounds/freedesktop/index.theme:${PORTSDIR}/audio/freedesktop-sound-theme

USE_XZ=		yes
USE_MATE=	autogen common:build component conf intlhack ltverhack \
		matehack vfs
USE_XORG=	xpm
USES=		bison
USE_GMAKE=	yes
USE_GNOME=	glib20
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${MATECONF_PREFIX} \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-deinstall

MAN7=		mate-options.7

MATECONF_SCHEMAS=desktop_mate_accessibility_keyboard.schemas \
		 desktop_mate_accessibility_startup.schemas \
		 desktop_mate_applications_at_mobility.schemas \
		 desktop_mate_applications_at_visual.schemas \
		 desktop_mate_applications_browser.schemas \
		 desktop_mate_applications_office.schemas \
		 desktop_mate_applications_terminal.schemas \
		 desktop_mate_applications_window_manager.schemas \
		 desktop_mate_background.schemas \
		 desktop_mate_file_views.schemas \
		 desktop_mate_interface.schemas \
		 desktop_mate_lockdown.schemas \
		 desktop_mate_peripherals_keyboard.schemas \
		 desktop_mate_peripherals_mouse.schemas \
		 desktop_mate_sound.schemas \
		 desktop_mate_thumbnail_cache.schemas \
		 desktop_mate_thumbnailers.schemas \
		 desktop_mate_typing_break.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/libmate/libmate-2.0.pc.in
	@${REINPLACE_CMD} -e '/^$$/d' ${WRKSRC}/po/POTFILES.in

.include <bsd.port.mk>
