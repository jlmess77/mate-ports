# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mate-text-editor
PORTVERSION=	1.6.0
CATEGORIES=	editors mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A small but powerful text editor for MATE Desktop Environment

BUILD_DEPENDS=	gtkdoc-check:${PORTSDIR}/textproc/gtk-doc \
		${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	enchant:${PORTSDIR}/textproc/enchant \
		soup-2.4:${PORTSDIR}/devel/libsoup
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes

USES=		desktop-file-utils pkgconfig
USE_XZ=		yes
USE_MATE=	autogen common:build docutils intlhack ltasneededhack \
		matehack
USE_XORG=	sm x11
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehier gtk20 gtksourceview2 gvfs libxml2 \
		pygobject pygtk2 pygtksourceview
WANT_GNOME=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:env autoconf:env automake:env libtool libtoolize:env
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-html-dir=${PREFIX}/share/doc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		pluma.1
GLIB_SCHEMAS=	org.mate.pluma.gschema.xml \
		org.mate.pluma.plugins.filebrowser.gschema.xml \
		org.mate.pluma.plugins.time.gschema.xml

.include <bsd.port.mk>
