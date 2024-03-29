#
# Makefile for the common code library project. 
# This probably requires GNU make.
#

SUBDIRS=src tests examples 

all: all-recursive

install: install-recursive

all-recursive:
	for s in $(SUBDIRS) ; do (cd $$s && $(MAKE)) || exit 1 ; done
	@echo ""
	@echo "*** run \"tests/test-libcommon\" to run the test suite"
	@echo ""

install-recursive: all
	for s in $(SUBDIRS) ; do (cd $$s && $(MAKE) install) || exit 1 ; done

clean: clean-recursive

clean-recursive:
	for s in $(SUBDIRS) ; do (cd $$s && $(MAKE) clean) ; done

distclean: distclean-recursive
	rm -f Makefile config.cache config.log config.status libtool
	rm -rf autom4te.cache

distclean-recursive:
	for s in $(SUBDIRS) ; do (cd $$s && $(MAKE) distclean) ; done

LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck

.PHONY: all install all-recursive install-recursive \
	clean clean-recursive distclean distclean-recursive
