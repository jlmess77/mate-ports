# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-screensaver
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE screen saver and locker

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		dbus-glib-1:${PORTSDIR}/devel/dbus-glib \
		notify:${PORTSDIR}/devel/libnotify
RUN_DEPENDS=	xscreensaver-gl-helper:${PORTSDIR}/x11/xscreensaver-gnome-hacks

USES=		gettext pkgconfig
USE_GL=		gl
USE_XZ=		yes
USE_MATE=	autogen common:build desktop intlhack libmatekbd \
		matehack menus
USE_XORG=	ice sm x11 xext xtst xxf86misc xxf86vm
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
CONFIGURE_ARGS=	--with-xscreensaverdir=${XSCREENSAVER_DIR} \
		--with-xscreensaverhackdir=${LOCALBASE}/bin/xscreensaver-hacks \
		--with-console-kit=yes \
		--with-systemd=no
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GLIB_SCHEMAS=	org.mate.screensaver.gschema.xml
MAN1=		mate-screensaver-command.1 mate-screensaver-preferences.1 \
		mate-screensaver.1

PLIST=		${WRKDIR}/pkg-plist
SUB_FILES+=	mate-screensaver.pam

XSCREENSAVER_DIR=	${LOCALBASE}/share/xscreensaver/config
SCREENSAVER_DIR=	share/applications/screensavers

XSCREENSAVER_EXCLUDE=	"(popsquares.xml)"

OPTIONS_DEFINE=	PAM KEYRING
OPTIONS_DEFAULT=PAM KEYRING
PAM_DESC=	Pluggable Authentication Module support
KEYRING_DESC=	GnomeKeyring integration (needs PAM)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAM}
RUN_DEPENDS+=	pam_helper:${PORTSDIR}/security/pam_helper
CONFIGURE_ARGS+=--enable-authentication-scheme=helper \
		--with-passwd-helper=${LOCALBASE}/bin/pam_helper
PLIST_SUB+=	PAM=""
.else
CONFIGURE_ARGS+=--disable-pam
PLIST_SUB+=	PAM="@comment "
.endif

.if ${PORT_OPTIONS:MKEYRING} && ${PORT_OPTIONS:MPAM}
SUB_LIST+=	PAM_KEYRING=
USE_MATE+=	keyring:run
.else
SUB_LIST+=	PAM_KEYRING=\#
.endif

pre-everything::
.if !${PORT_OPTIONS:MPAM} && ${PORT_OPTIONS:MKEYRING}
	@${ECHO_MSG} "Keyring integration is disabled because it needs PAM."
.endif

post-patch:
.if ${PORT_OPTIONS:MPAM}
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c
.endif

pre-install:
	@${CAT} ${.CURDIR}/pkg-plist > ${PLIST}
	@cd ${XSCREENSAVER_DIR} && ${FIND} -s * -maxdepth 1 -type f -name "*.xml" | \
		${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
		${SED} -e 's:^:${SCREENSAVER_DIR}/:' | \
		${SED} -e 's:[.]xml$$:.desktop:' >> ${PLIST}
	@${ECHO_CMD} @dirrm ${SCREENSAVER_DIR} >> ${PLIST}

post-install:
	${CHOWN} root ${PREFIX}/libexec/mate-screensaver-dialog
	${CHMOD} +s ${PREFIX}/libexec/mate-screensaver-dialog
	${MKDIR} ${PREFIX}/${SCREENSAVER_DIR}
	cd ${PREFIX}/${SCREENSAVER_DIR} && \
		${FIND} -s ${XSCREENSAVER_DIR} -maxdepth 1 -type f -name "*.xml" | \
			${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
			${XARGS} ${WRKSRC}/data/migrate-xscreensaver-config.sh
.if ${PORT_OPTIONS:MPAM}
	${INSTALL_DATA} ${WRKDIR}/mate-screensaver.pam ${PREFIX}/etc/pam.d/mate-screensaver
.endif

.include <bsd.port.mk>
