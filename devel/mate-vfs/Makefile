# New ports collection makefile for:	gnomevfs2
# Date created:				28th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-experimental/devel/mate-vfs/Makefile,v 1.4 2012/07/27 01:34:25 mezz Exp $
#

PORTNAME=	mate-vfs
PORTVERSION=	1.4.0
CATEGORIES=	devel mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE Virtual File System

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	dbus-glib-1:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info

USE_XZ=		yes
USE_MATE=	autogen common:build conf intlhack ltverhack matehack mimedata
USE_GMAKE=	yes
USE_GNOME=	glib20 libxml2
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
USE_PKGCONFIG=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-openssl \
		--disable-gnutls \
		--disable-howl \
		--with-hal-mount=/sbin/mount \
		--with-hal-umount=/sbin/umount \
		--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc \
		${MATECONF_PREFIX}
CPPFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include \
		-DPTHREAD_LIB="${PTHREAD_LIBS}"
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

MATECONF_SCHEMAS=desktop_default_applications.schemas \
		 desktop_mate_url_handlers.schemas system_dns_sd.schemas \
		 system_http_proxy.schemas system_smb.schemas

OPTIONS=	SAMBA "Enable SMB volume support" on \
		MDNS "Enable Bonjour/Rendezvous support" on \
		HAL "Enable HAL support" on \
		FAM "Enable FAM support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FAM)
CONFIGURE_ARGS+=--enable-fam=yes
USE_FAM=	yes
.else
CONFIGURE_ARGS+=--disable-fam
.endif

.if exists(${LOCALBASE}/lib/libkrb5.so)
LIB_DEPENDS+=	krb5.26:${PORTSDIR}/security/heimdal
.endif

.if !defined(WITHOUT_HAL)
CONFIGURE_ARGS+=--enable-hal
LIB_DEPENDS+=	hal:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=--disable-hal
.endif

.if !defined(WITHOUT_SAMBA)
LIB_DEPENDS+=	smbclient:${PORTSDIR}/net/samba-libsmbclient
PLIST_SUB+=	SAMBA=""
.else
PLIST_SUB+=	SAMBA="@comment "
CONFIGURE_ARGS+=--disable-samba
.endif

.if !defined(WITHOUT_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.else
CONFIGURE_ARGS+=--disable-avahi
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@PTHREAD_LIB@|${PTHREAD_LIBS}|' \
		${WRKSRC}/mate-vfs-2.0.pc.in ${WRKSRC}/mate-vfs-module-2.0.pc.in
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/mate-vfs-2.0/include|(includedir)/mate-vfs-2.0/include|g' \
		${WRKSRC}/libmatevfs/Makefile.am
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/libmatevfs/xdgmime.c \
		${WRKSRC}/libmatevfs/mate-vfs-hal-mounts.c
	@${REINPLACE_CMD} -e '/module_flags/s|-module -no-undefined|-module -no-undefined ${PTHREAD_LIB}|g' \
		${WRKSRC}/modules/Makefile.am
	@${REINPLACE_CMD} -e 's|-lacl||g ; s|-ldl||g' \
		${WRKSRC}/configure.in
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		< ${MASTERDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		< ${MASTERDIR}/pkg-deinstall.in > ${PKGDEINSTALL}

pre-configure:
.if defined(WITHOUT_KERBEROS)
	@${ECHO_CMD} "${PKGNAME}: KERBEROS is required."
	@${FALSE}
.endif

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} \
		${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
