#
# Makefile for the common code library project. 
#

top_builddir=..
prefix=/usr/local
exec_prefix=${prefix}
libdir=${exec_prefix}/lib
includedir=${prefix}/include

DEFS   = -DHAVE_CONFIG_H
CFLAGS = -g -O2 -W -Wall -Wwrite-strings -Wbad-function-cast -Wmissing-prototypes -Wcast-qual -Wmissing-declarations $(DEFS)
LIBS   = 
CC     = gcc
LDFLAGS= 
RANLIB = ranlib
LIBTOOL= $(SHELL) $(top_builddir)/libtool
INSTALL= /usr/bin/install -c
SHELL  = /bin/bash
EXTRAOBJS= 

LT_OBJS = asarray.lo base64.lo btree.lo crypt_random.lo debug.lo \
          drand48.lo hmac.lo mbus_addr.lo mbus_config.lo mbus.lo \
          mbus_parser.lo md5.lo memory.lo net_udp.lo ntp.lo \
          qfDES.lo rijndael-alg-fst.lo rijndael-api-fst.lo rtp.lo \
          sap.lo sdp.lo util.lo $(EXTRAOBJS)

all: version.h libuclmmbase.la

CCLD = $(CC)
libuclmmbase.la: $(LT_OBJS)
	$(LIBTOOL) --tag=CC --mode=link $(CCLD) $(LT_OBJS) -o libuclmmbase.a
	$(LIBTOOL) --tag=CC --mode=link $(CCLD) $(LDFLAGS)-rpath $(libdir) -version-info 1 -shared $(LT_OBJS) -o $@

version.h: ../VERSION
	sed -e 's/.*/#define CCL_VERSION "v&"/' $? > version.h

install: all
	test -d $(DESTDIR)$(includedir)/uclmmbase || \
		$(INSTALL) -d $(DESTDIR)$(includedir)/uclmmbase
	test -d "$(DESTDIR)$(libdir)" || \
		$(INSTALL) -d "$(DESTDIR)$(libdir)"
	$(LIBTOOL) --mode=install $(INSTALL) libuclmmbase.la $(DESTDIR)$(libdir)
	for header in *.h; do $(INSTALL) $$header $(DESTDIR)$(includedir)/uclmmbase/$(header); done

.SUFFIXES:
.SUFFIXES: .c .o .lo

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $<

.c.lo:
	$(LIBTOOL) --tag=CC --mode=compile $(CC)  $(CFLAGS) $(INC) -c $<

clean:
	-rm -f *.o *.lo version.h libuclmmbase.la libuclmmbase.a
	-rm -rf .libs

distclean:	clean
	-rm -f Makefile config.status config.cache uclconf.h

depend:
	if grep '^# DO NOT DELETE' Makefile >/dev/null; \
	then \
		sed -e '/^# DO NOT DELETE/,$$ d' Makefile > Makefile.$$$$ && \
		mv Makefile.$$$$ Makefile; \
	fi
	echo '# DO NOT DELETE THIS LINE -- make depend depends on it.' \
		>> Makefile; \
	for src in $(LT_OBJS); do \
	    $(CC) -S -MM -MT $$src $(CFLAGS) $(INC) `basename $$src .lo`.c \
	        >> Makefile; \
	done

# DO NOT DELETE THIS LINE -- make depend depends on it.
