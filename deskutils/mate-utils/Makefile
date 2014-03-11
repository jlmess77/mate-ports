# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-utils
PORTVERSION=	1.8.0
CATEGORIES=	deskutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE support utilities

BUILD_DEPENDS=	itstool:${PORTSDIR}/textproc/itstool
LIB_DEPENDS=	libgtop-2.0.so:${PORTSDIR}/devel/libgtop \
		libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra

PORTSCOUT=	limitw:1,even

USES=		gettext gmake libtool pathfix pkgconfig
USE_XZ=		yes
USE_MATE=	panel
USE_XORG=	x11 xext
USE_GNOME=	gnomehier gtk20 intlhack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-maintainer-flags=no \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.dictionary.gschema.xml \
		org.mate.disk-usage-analyzer.gschema.xml \
		org.mate.screenshot.gschema.xml \
		org.mate.search-tool.gschema.xml \
		org.mate.system-log.gschema.xml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmatedict.so.*

.include <bsd.port.mk>
