# Makefile for program source directory in GNU NLS utilities package.
# Copyright (C) 1995, 1996, 1997 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
# Copyright (C) 2004-2008 Rodney Dawes <dobey.pwns@gmail.com>
#
# This file may be copied and used freely without restrictions.  It may
# be used in projects which are not available under a GNU Public License,
# but which still want to provide support for the GNU gettext functionality.
#
# - Modified by Owen Taylor <otaylor@redhat.com> to use GETTEXT_PACKAGE
#   instead of PACKAGE and to look for po2tbl in ./ not in intl/
#
# - Modified by jacob berkman <jacob@ximian.com> to install
#   Makefile.in.in and po2tbl.sed.in for use with glib-gettextize
#
# - Modified by Rodney Dawes <dobey.pwns@gmail.com> for use with intltool
#
# We have the following line for use by intltoolize:
# INTLTOOL_MAKEFILE

GETTEXT_PACKAGE = mate-control-center
PACKAGE = mate-control-center
VERSION = 1.8.1

SHELL = /bin/sh

srcdir = .
top_srcdir = ..
top_builddir = ..


prefix = /usr/local
exec_prefix = ${prefix}
datadir = ${datarootdir}
datarootdir = ${prefix}/share
libdir = ${exec_prefix}/lib
DATADIRNAME = share
itlocaledir = $(prefix)/$(DATADIRNAME)/locale
subdir = po
install_sh = ${SHELL} /usr/home/ericbsd/mate-ports/sysutils/mate-control-center/work/mate-control-center-1.8.1/install-sh
# Automake >= 1.8 provides $(MKDIR_P).
# Until it can be supposed, use the safe fallback:
mkdir_p = $(install_sh) -d

INSTALL = /usr/bin/install -c -o root -g wheel
INSTALL_DATA = install  -o root -g wheel -m 444

GMSGFMT = /usr/local/bin/msgfmt
MSGFMT = /usr/local/bin/msgfmt
XGETTEXT = /usr/local/bin/xgettext
INTLTOOL_UPDATE = /usr/local/bin/intltool-update
INTLTOOL_EXTRACT = /usr/local/bin/intltool-extract
MSGMERGE = INTLTOOL_EXTRACT="$(INTLTOOL_EXTRACT)" XGETTEXT="$(XGETTEXT)" srcdir=$(srcdir) $(INTLTOOL_UPDATE) --gettext-package $(GETTEXT_PACKAGE) --dist
GENPOT   = INTLTOOL_EXTRACT="$(INTLTOOL_EXTRACT)" XGETTEXT="$(XGETTEXT)" srcdir=$(srcdir) $(INTLTOOL_UPDATE) --gettext-package $(GETTEXT_PACKAGE) --pot

ALL_LINGUAS = 

PO_LINGUAS=$(shell if test -r $(srcdir)/LINGUAS; then grep -v "^\#" $(srcdir)/LINGUAS; else echo "$(ALL_LINGUAS)"; fi)

USER_LINGUAS=$(shell if test -n "$(LINGUAS)"; then LLINGUAS="$(LINGUAS)"; ALINGUAS="$(ALL_LINGUAS)"; for lang in $$LLINGUAS; do if test -n "`grep \^$$lang$$ $(srcdir)/LINGUAS 2>/dev/null`" -o -n "`echo $$ALINGUAS|tr ' ' '\n'|grep \^$$lang$$`"; then printf "$$lang "; fi; done; fi)

USE_LINGUAS=$(shell if test -n "$(USER_LINGUAS)" -o -n "$(LINGUAS)"; then LLINGUAS="$(USER_LINGUAS)"; else if test -n "$(PO_LINGUAS)"; then LLINGUAS="$(PO_LINGUAS)"; else LLINGUAS="$(ALL_LINGUAS)"; fi; fi; for lang in $$LLINGUAS; do printf "$$lang "; done)

POFILES=$(shell LINGUAS="$(PO_LINGUAS)"; for lang in $$LINGUAS; do printf "$$lang.po "; done)

DISTFILES = Makefile.in.in POTFILES.in $(POFILES)
EXTRA_DISTFILES = ChangeLog POTFILES.skip Makevars LINGUAS

POTFILES = \
	../org.mate.control-center.gschema.xml.in.in \
	../org.mate.control-center.keybinding.gschema.xml.in.in \
	../capplets/about-me/eel-alert-dialog.c \
	../capplets/about-me/e-image-chooser.c \
	../capplets/about-me/mate-about-me.c \
	../capplets/about-me/mate-about-me-dialog.ui \
	../capplets/about-me/mate-about-me.desktop.in.in \
	../capplets/about-me/mate-about-me-fingerprint.c \
	../capplets/about-me/mate-about-me-fingerprint.ui \
	../capplets/about-me/mate-about-me-password.c \
	../capplets/about-me/mate-about-me-password.ui \
	../capplets/accessibility/at-properties/at-enable-dialog.ui \
	../capplets/accessibility/at-properties/mate-at-properties.desktop.in.in \
	../capplets/accessibility/at-properties/main.c \
	../capplets/appearance/appearance-desktop.c \
	../capplets/appearance/appearance-font.c \
	../capplets/appearance/appearance-main.c \
	../capplets/appearance/appearance-style.c \
	../capplets/appearance/appearance-themes.c \
	../capplets/appearance/data/appearance.ui \
	../capplets/appearance/data/mate-appearance-properties.desktop.in.in \
	../capplets/appearance/data/mate-theme-installer.desktop.in.in \
	../capplets/appearance/data/mate-theme-package.xml.in \
	../capplets/appearance/mate-wp-info.c \
	../capplets/appearance/mate-wp-item.c \
	../capplets/appearance/theme-installer.c \
	../capplets/appearance/theme-save.c \
	../capplets/appearance/theme-util.c \
	../capplets/common/activate-settings-daemon.c \
	../capplets/common/capplet-stock-icons.c \
	../capplets/common/capplet-util.c \
	../capplets/common/file-transfer-dialog.c \
	../capplets/common/mate-theme-info.c \
	../capplets/default-applications/mate-default-applications-properties.desktop.in.in \
	../capplets/default-applications/mate-da-capplet.c \
	../capplets/default-applications/mate-default-applications-properties.ui \
	../capplets/display/display-capplet.ui \
	../capplets/display/mate-display-properties.desktop.in.in \
	../capplets/display/mate-display-properties-install-systemwide.c \
	../capplets/display/org.mate.randr.policy.in \
	../capplets/display/xrandr-capplet.c \
	../capplets/keybindings/00-multimedia-key.xml.in \
	../capplets/keybindings/01-desktop-key.xml.in \
	../capplets/keybindings/eggcellrendererkeys.c \
	../capplets/keybindings/mate-keybinding-properties.c \
	../capplets/keybindings/mate-keybinding-properties.ui \
	../capplets/keybindings/mate-keybinding.desktop.in.in \
	../capplets/keyboard/mate-keyboard-properties.c \
	../capplets/keyboard/mate-keyboard-properties-a11y-notifications.ui \
	../capplets/keyboard/mate-keyboard-properties-dialog.ui \
	../capplets/keyboard/mate-keyboard-properties-layout-chooser.ui \
	../capplets/keyboard/mate-keyboard-properties-model-chooser.ui \
	../capplets/keyboard/mate-keyboard-properties-options-dialog.ui \
	../capplets/keyboard/mate-keyboard-properties-xkb.c \
	../capplets/keyboard/mate-keyboard-properties-xkbltadd.c \
	../capplets/keyboard/mate-keyboard-properties-xkblt.c \
	../capplets/keyboard/mate-keyboard-properties-xkbmc.c \
	../capplets/keyboard/mate-keyboard-properties-xkbot.c \
	../capplets/keyboard/mate-keyboard-properties-xkbpv.c \
	../capplets/keyboard/mate-keyboard.desktop.in.in \
	../capplets/mouse/mate-mouse-properties.c \
	../capplets/mouse/mate-mouse-properties.ui \
	../capplets/mouse/mate-settings-mouse.desktop.in.in \
	../capplets/network/mate-network-properties.c \
	../capplets/network/mate-network-properties.desktop.in.in \
	../capplets/network/mate-network-properties.ui \
	../capplets/windows/mate-metacity-support.c \
	../capplets/windows/mate-window-properties.c \
	../capplets/windows/mate-window-properties.desktop.in.in \
	../libwindow-settings/mate-wm-manager.c \
	../libwindow-settings/marco-window-manager.c \
	../shell/control-center.c \
	../shell/matecc.desktop.in.in \
	../shell/matecc.directory.in \
	../typing-break/drw-break-window.c \
	../typing-break/drwright.c \
	../typing-break/main.c \
	../font-viewer/font-view.c \
	../font-viewer/mate-font-viewer.desktop.in.in \
	../font-viewer/font-thumbnailer.c \
	../libslab/app-shell.c \
	../libslab/application-tile.c \
	../libslab/bookmark-agent.c \
	../libslab/directory-tile.c \
	../libslab/document-tile.c \
	../libslab/search-bar.c \
	../libslab/system-tile.c

CATALOGS=$(shell LINGUAS="$(USE_LINGUAS)"; for lang in $$LINGUAS; do printf "$$lang.gmo "; done)

.SUFFIXES:
.SUFFIXES: .po .pox .gmo .mo .msg .cat

AM_DEFAULT_VERBOSITY = 0
INTLTOOL_V_MSGFMT = $(INTLTOOL__v_MSGFMT_$(V))
INTLTOOL__v_MSGFMT_= $(INTLTOOL__v_MSGFMT_$(AM_DEFAULT_VERBOSITY))
INTLTOOL__v_MSGFMT_0 = @echo "  MSGFMT" $@;

.po.pox:
	$(MAKE) $(GETTEXT_PACKAGE).pot
	$(MSGMERGE) $< $(GETTEXT_PACKAGE).pot -o $*.pox

.po.mo:
	$(INTLTOOL_V_MSGFMT)$(MSGFMT) -o $@ $<

.po.gmo:
	$(INTLTOOL_V_MSGFMT)file=`echo $* | sed 's,.*/,,'`.gmo \
	  && rm -f $$file && $(GMSGFMT) -o $$file $<

.po.cat:
	sed -f ../intl/po2msg.sed < $< > $*.msg \
	  && rm -f $@ && gencat $@ $*.msg


all: all-yes

all-yes: $(CATALOGS)
all-no:

$(GETTEXT_PACKAGE).pot: $(POTFILES)
	$(GENPOT)

install: install-data
install-data: install-data-yes
install-data-no: all
install-data-yes: all
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  dir=$(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $$dir; \
	  if test -r $$lang.gmo; then \
	    $(INSTALL_DATA) $$lang.gmo $$dir/$(GETTEXT_PACKAGE).mo; \
	    echo "installing $$lang.gmo as $$dir/$(GETTEXT_PACKAGE).mo"; \
	  else \
	    $(INSTALL_DATA) $(srcdir)/$$lang.gmo $$dir/$(GETTEXT_PACKAGE).mo; \
	    echo "installing $(srcdir)/$$lang.gmo as" \
		 "$$dir/$(GETTEXT_PACKAGE).mo"; \
	  fi; \
	  if test -r $$lang.gmo.m; then \
	    $(INSTALL_DATA) $$lang.gmo.m $$dir/$(GETTEXT_PACKAGE).mo.m; \
	    echo "installing $$lang.gmo.m as $$dir/$(GETTEXT_PACKAGE).mo.m"; \
	  else \
	    if test -r $(srcdir)/$$lang.gmo.m ; then \
	      $(INSTALL_DATA) $(srcdir)/$$lang.gmo.m \
		$$dir/$(GETTEXT_PACKAGE).mo.m; \
	      echo "installing $(srcdir)/$$lang.gmo.m as" \
		   "$$dir/$(GETTEXT_PACKAGE).mo.m"; \
	    else \
	      true; \
	    fi; \
	  fi; \
	done

# Empty stubs to satisfy archaic automake needs
dvi info ctags tags CTAGS TAGS ID:

# Define this as empty until I found a useful application.
install-exec installcheck:

uninstall:
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  rm -f $(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES/$(GETTEXT_PACKAGE).mo; \
	  rm -f $(DESTDIR)$(itlocaledir)/$$lang/LC_MESSAGES/$(GETTEXT_PACKAGE).mo.m; \
	done

check: all $(GETTEXT_PACKAGE).pot
	rm -f missing notexist
	srcdir=$(srcdir) $(INTLTOOL_UPDATE) -m
	if [ -r missing -o -r notexist ]; then \
	  exit 1; \
	fi

mostlyclean:
	rm -f *.pox $(GETTEXT_PACKAGE).pot *.old.po cat-id-tbl.tmp
	rm -f .intltool-merge-cache

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES stamp-it
	rm -f *.mo *.msg *.cat *.cat.m *.gmo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f Makefile.in.in

distdir = ../$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir: $(DISTFILES)
	dists="$(DISTFILES)"; \
	extra_dists="$(EXTRA_DISTFILES)"; \
	for file in $$extra_dists; do \
	  test -f $(srcdir)/$$file && dists="$$dists $(srcdir)/$$file"; \
	done; \
	for file in $$dists; do \
	  test -f $$file || file="$(srcdir)/$$file"; \
	  ln $$file $(distdir) 2> /dev/null \
	    || cp -p $$file $(distdir); \
	done

update-po: Makefile
	$(MAKE) $(GETTEXT_PACKAGE).pot
	tmpdir=`pwd`; \
	linguas="$(USE_LINGUAS)"; \
	for lang in $$linguas; do \
	  echo "$$lang:"; \
	  result="`$(MSGMERGE) -o $$tmpdir/$$lang.new.po $$lang`"; \
	  if $$result; then \
	    if cmp $(srcdir)/$$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	      rm -f $$tmpdir/$$lang.new.po; \
            else \
	      if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	        :; \
	      else \
	        echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	        rm -f $$tmpdir/$$lang.new.po; \
	        exit 1; \
	      fi; \
	    fi; \
	  else \
	    echo "msgmerge for $$lang.gmo failed!"; \
	    rm -f $$tmpdir/$$lang.new.po; \
	  fi; \
	done

Makefile POTFILES: stamp-it
	@if test ! -f $@; then \
	  rm -f stamp-it; \
	  $(MAKE) stamp-it; \
	fi

stamp-it: Makefile.in.in $(top_builddir)/config.status POTFILES.in
	cd $(top_builddir) \
	  && CONFIG_FILES=$(subdir)/Makefile.in CONFIG_HEADERS= CONFIG_LINKS= \
	       $(SHELL) ./config.status

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
