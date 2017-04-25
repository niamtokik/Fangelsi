######################################################################
# copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
# Makefile
######################################################################

ERLANG_PATH ?= /usr/local/lib/erlang

CC ?= cc
CC_ERLANG = -fpic -shared
CC_INCLUDES += -I$(ERLANG_PATH)/usr/include
CC_INCLUDES += -I/usr/local/include

# CC_LIBRARIES = -ljail -L. 

CC_WARNINGS = -Wall -Wextra -Werror 
CC_WARNINGS += -Wformat -Wformat-security -Werror=format-security

CC_SECURITY += -D_FORTIFY_SOURCE=2 
CC_SECURITY += -fstack-protector

CC_OPTS = $(CC_WARNINGS) $(CC_ERLANG) $(CC_LIBRARIES) $(CC_INCLUDES)
CC_OPTS += $(CC_SECURITY)

CC_TEST_LIBRARIES = -latf-c -L.

CC_TEST_OPTS = -L/usr/local/lib -latf-c
CC_TEST_OPTS += $(CC_LIBRARIES) $(CC_INCLUDES)
CC_TEST_OPTS += $(CC_SECURITY)

KYUAFILE_TEMPLATE = ../priv/Kyuafile

.ifdef DESTDIR
	mkdir $(DESTDIR)
.endif

.ifdef PROD
	# security features from
	# http://blog.quarkslab.com/clang-hardening-cheat-sheet.html
	CC_OPTS += -Wl --strip-debug  --strip-all -z,relro
	CC_OPTS += -D_FORTIFY_SOURCE=2
	CC_OPTS += -fPIC
	CC_OPTS += -fstack-protector -fsanitize=safe-stack
	CC_OPTS += -fsanitize=cfi
.endif

.ifdef DEBUG
	CC_OPTS += -g -fdebug-macro
.endif

TEST_DIR = _test

CLEAN  = iovec_test
CLEAN += get_jail_test set_jail_test
CLEAN += jail_port_test jail_nif_test

######################################################################
#
######################################################################
all: clean jail_nif.so jail_port

run-test: iovec_test get_jail_test set_jail_test
	cd _test && \
	for dir in *; do \
		cd $${dir} && kyua test; done

$(TEST_DIR):
	mkdir $@

######################################################################
# iovec helpers functions
######################################################################
$(TEST_DIR)/iovec: $(TEST_DIR)
	mkdir $@
	cat ../priv/Kyuafile \
		| sed -Ee 's/<%TEST_NAME%>/iovec/' \
		      -e 's/<%TEST_PROGRAM%>/iovec_test/' \
		> $@/Kyuafile

iovec_test: $(TEST_DIR)/iovec
	$(CC) $(CC_TEST_OPTS) -o$(TEST_DIR)/iovec/$@ \
		iovec_test.c iovec.c

iovec.o:
	$(CC) $(CC_OPTS) -o$@ iovec.c

######################################################################
# Jail API Test (ATF)
######################################################################
$(TEST_DIR)/get_jail: $(TEST_DIR)
	mkdir $@
	cat ../priv/Kyuafile \
		| sed -Ee 's/<%TEST_NAME%>/get_jail/' \
		      -e 's/<%TEST_PROGRAM%>/get_jail_test/' \
		> $@/Kyuafile

get_jail_test: $(TEST_DIR)/get_jail
	$(CC) $(CC_TEST_OPTS) -o$(TEST_DIR)/get_jail/$@ \
		iovec.c get_jail_test.c get_jail.c

$(TEST_DIR)/set_jail: $(TEST_DIR)
	mkdir $@
	touch $@/Kyuafile
	cat ../priv/Kyuafile \
		| sed -Ee 's/<%TEST_NAME%>/set_jail/' \
		      -e 's/<%TEST_PROGRAM%>/set_jail_test/' \
		> $@/Kyuafile

set_jail_test: $(TEST_DIR)/set_jail
	$(CC) $(CC_TEST_OPTS) -o$(TEST_DIR)/set_jail/$@ \
	iovec.c set_jail_test.c set_jail.c

######################################################################
# Jail API
######################################################################
get_jail.o:
	$(CC) $(CC_OPTS) -o$@ get_jail.c

set_jail.o:
	$(CC) $(CC_OPTS) -o$@ set_jail.c


######################################################################
# Erlang Jail Interface (NIF)
######################################################################
$(TEST_DIR)/jail_nif: $(TEST_DIR)
	mkdir $@
	touch $@/Kyuafile

jail_nif_test:
	$(CC) $(CC_TEST_OPTS) -o$(TEST_DIR)/jail_nif/$@ \
		jail_nif_test.c get_jail.c set_jail.c

jail_nif.so: get_jail.o set_jail.o jail_nif_test
	$(CC) $(CC_OPTS) -o$@ get_jail.o set_jail.o jail_nif.c

jail_nif.erl:
	@echo Work in progress...

######################################################################
# Erlang Jail Interface (Port)
######################################################################
$(TEST_DIR)/jail_port: $(TEST_DIR)
	mkdir $@
	touch $@/Kyuafile

jail_port_test:
	$(CC) $(CC_TEST_OPTS) -o$(TEST_DIR)/jail_port/$@ \
		jail_port_test.c get_jail.c set_jail.c

jail_port: get_jail.o set_jail.o test
	$(CC) $(CC_OPTS) -o$@ get_jail.o set_jail.o jail_port.c

jail_port.erl:
	@echo Work in progress...

######################################################################
# remove all compiled files
######################################################################
clean:
	-rm -rf _test
	-rm *~
	-rm *.core
	-rm *.o *.so
	-rm test

######################################################################
# help
######################################################################
help:
	@echo "make [all|test|clean]"
