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

GETTEXT_PACKAGE = pluma
PACKAGE = pluma
VERSION = 1.8.0

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
install_sh = ${SHELL} /usr/home/ericbsd/mate-ports/editors/pluma/work/pluma-1.8.0/install-sh
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
	../data/org.mate.pluma.gschema.xml.in.in \
	../data/pluma.desktop.in.in \
	../pluma/dialogs/pluma-close-confirmation-dialog.c \
	../pluma/dialogs/pluma-encodings-dialog.c \
	../pluma/dialogs/pluma-encodings-dialog.ui \
	../pluma/dialogs/pluma-preferences-dialog.c \
	../pluma/dialogs/pluma-preferences-dialog.ui \
	../pluma/dialogs/pluma-search-dialog.c \
	../pluma/dialogs/pluma-search-dialog.ui \
	../pluma/pluma.c \
	../pluma/pluma-app.c \
	../pluma/pluma-commands-file.c \
	../pluma/pluma-commands-help.c \
	../pluma/pluma-commands-search.c \
	../pluma/pluma-debug.c \
	../pluma/pluma-document.c \
	../pluma/pluma-document-saver.c \
	../pluma/pluma-documents-panel.c \
	../pluma/pluma-encodings.c \
	../pluma/pluma-encodings-combo-box.c \
	../pluma/pluma-file-chooser-dialog.c \
	../pluma/pluma-gio-document-loader.c \
	../pluma/pluma-gio-document-saver.c \
	../pluma/pluma-help.c \
	../pluma/pluma-io-error-message-area.c \
	../pluma/pluma-notebook.c \
	../pluma/pluma-panel.c \
	../pluma/pluma-plugin-manager.c \
	../pluma/pluma-plugins-engine.c \
	../pluma/pluma-prefs-manager.c \
	../pluma/pluma-print-job.c \
	../pluma/pluma-print-preferences.ui \
	../pluma/pluma-print-preview.c \
	../pluma/pluma-smart-charset-converter.c \
	../pluma/pluma-statusbar.c \
	../pluma/pluma-style-scheme-manager.c \
	../pluma/pluma-tab.c \
	../pluma/pluma-tab-label.c \
	../pluma/pluma-ui.h \
	../pluma/pluma-ui.xml \
	../pluma/pluma-utils.c \
	../pluma/pluma-view.c \
	../pluma/pluma-window.c \
	../plugins/changecase/changecase.pluma-plugin.desktop.in \
	../plugins/changecase/pluma-changecase-plugin.c \
	../plugins/checkupdate/checkupdate.pluma-plugin.desktop.in \
	../plugins/checkupdate/pluma-check-update-plugin.c \
	../plugins/checkupdate/org.mate.pluma.plugins.checkupdate.gschema.xml.in.in \
	../plugins/docinfo/docinfo.pluma-plugin.desktop.in \
	../plugins/docinfo/docinfo.ui \
	../plugins/docinfo/pluma-docinfo-plugin.c \
	../plugins/externaltools/data/open-terminal-here-osx.desktop.in \
	../plugins/externaltools/externaltools.pluma-plugin.desktop.in \
	../plugins/externaltools/tools/__init__.py \
	../plugins/externaltools/tools/capture.py \
	../plugins/externaltools/tools/functions.py \
	../plugins/externaltools/tools/manager.py \
	../plugins/externaltools/tools/outputpanel.py \
	../plugins/externaltools/tools/tools.ui \
	../plugins/externaltools/data/build.desktop.in \
	../plugins/externaltools/data/open-terminal-here.desktop.in \
	../plugins/externaltools/data/remove-trailing-spaces.desktop.in \
	../plugins/externaltools/data/run-command.desktop.in \
	../plugins/externaltools/data/search-recursive.desktop.in \
	../plugins/externaltools/data/switch-c.desktop.in \
	../plugins/filebrowser/filebrowser.pluma-plugin.desktop.in \
	../plugins/filebrowser/org.mate.pluma.plugins.filebrowser.gschema.xml.in.in \
	../plugins/filebrowser/pluma-file-bookmarks-store.c \
	../plugins/filebrowser/pluma-file-browser-plugin.c \
	../plugins/filebrowser/pluma-file-browser-store.c \
	../plugins/filebrowser/pluma-file-browser-view.c \
	../plugins/filebrowser/pluma-file-browser-widget.c \
	../plugins/modelines/modelines.pluma-plugin.desktop.in \
	../plugins/pythonconsole/pythonconsole.pluma-plugin.desktop.in \
	../plugins/pythonconsole/pythonconsole/__init__.py \
	../plugins/pythonconsole/pythonconsole/config.ui \
	../plugins/quickopen/quickopen/popup.py \
	../plugins/quickopen/quickopen/windowhelper.py \
	../plugins/quickopen/quickopen.pluma-plugin.desktop.in \
	../plugins/snippets/snippets.pluma-plugin.desktop.in \
	../plugins/snippets/snippets/snippets.ui \
	../plugins/snippets/snippets/Document.py \
	../plugins/snippets/snippets/WindowHelper.py \
	../plugins/snippets/snippets/Manager.py \
	../plugins/snippets/snippets/Exporter.py \
	../plugins/snippets/snippets/Importer.py \
	../plugins/snippets/snippets/Placeholder.py \
	../plugins/sort/pluma-sort-plugin.c \
	../plugins/sort/sort.pluma-plugin.desktop.in \
	../plugins/sort/sort.ui \
	../plugins/spell/pluma-automatic-spell-checker.c \
	../plugins/spell/pluma-spell-checker.c \
	../plugins/spell/pluma-spell-checker-dialog.c \
	../plugins/spell/pluma-spell-checker-language.c \
	../plugins/spell/pluma-spell-language-dialog.c \
	../plugins/spell/pluma-spell-plugin.c \
	../plugins/spell/languages-dialog.ui \
	../plugins/spell/spell-checker.ui \
	../plugins/spell/spell.pluma-plugin.desktop.in \
	../plugins/taglist/pluma-taglist-plugin.c \
	../plugins/taglist/pluma-taglist-plugin-panel.c \
	../plugins/taglist/pluma-taglist-plugin-parser.c \
	../plugins/taglist/HTML.tags.xml.in \
	../plugins/taglist/Latex.tags.xml.in \
	../plugins/taglist/taglist.pluma-plugin.desktop.in \
	../plugins/taglist/XSLT.tags.xml.in \
	../plugins/taglist/XUL.tags.xml.in \
	../plugins/time/org.mate.pluma.plugins.time.gschema.xml.in.in \
	../plugins/time/pluma-time-plugin.c \
	../plugins/time/time.pluma-plugin.desktop.in \
	../plugins/time/pluma-time-dialog.ui \
	../plugins/time/pluma-time-setup-dialog.ui

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
