# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-control-center
PORTVERSION=	1.6.0
CATEGORIES=	sysutils mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Control center for MATE project

LIB_DEPENDS=	libcanberra-gtk.so:${PORTSDIR}/audio/libcanberra \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
		libxklavier.so:${PORTSDIR}/x11/libxklavier \
		libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit

USES=		desktop-file-utils gettext gmake pathfix pkgconfig \
		shared-mime-info
USE_XZ=		yes
USE_MATE=	autogen common:build desktop docutils intlhack \
		ltverhack libmatekbd marco menus settingsdaemon
USE_XORG=	x11 xcursor xext xxf86misc xft xi xrandr xscrnsaver
USE_GNOME=	dconf glib20 gnomehier gtk20 libxml2 librsvg2 pango
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-appindicator=no
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PATHFIX_MAKEFILEIN=	Makefile.*

GLIB_SCHEMAS=	org.mate.control-center.gschema.xml \
		org.mate.control-center.keybinding.gschema.xml

FIX_FILES=	capplets/accessibility/at-properties \
		capplets/default-applications capplets/display \
		capplets/keyboard capplets/windows

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
	    	${WRKSRC}/capplets/common/mate-theme-info.c
	@${REINPLACE_CMD} -e 's|/usr/sbin|${PREFIX}/sbin|g' \
		${WRKSRC}/capplets/display/org.mate.randr.policy.in
.for dir in ${FIX_FILES}
	@${REINPLACE_CMD} -e 's|Desktop_in_files = |Desktop_in_files = mate-|g' \
		${WRKSRC}/${dir}/Makefile.am
.endfor
	@${MV} ${WRKSRC}/capplets/accessibility/at-properties/at-properties.desktop.in.in \
		${WRKSRC}/capplets/accessibility/at-properties/mate-at-properties.desktop.in.in
	@${MV} ${WRKSRC}/capplets/default-applications/default-applications.desktop.in.in \
		${WRKSRC}/capplets/default-applications/mate-default-applications.desktop.in.in
	@${MV} ${WRKSRC}/capplets/display/display-properties.desktop.in.in \
		${WRKSRC}/capplets/display/mate-display-properties.desktop.in.in
	@${MV} ${WRKSRC}/capplets/keyboard/keyboard.desktop.in.in \
		${WRKSRC}/capplets/keyboard/mate-keyboard.desktop.in.in
	@${MV} ${WRKSRC}/capplets/windows/window-properties.desktop.in.in \
		${WRKSRC}/capplets/windows/mate-window-properties.desktop.in.in

.include <bsd.port.mk>
