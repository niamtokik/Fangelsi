######################################################################
# copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
# Makefile
######################################################################

ERLANG_PATH ?= /usr/local/lib/erlang

CC ?= cc
CC_ERLANG = -fpic -shared
CC_INCLUDES += -I$(ERLANG_PATH)/usr/include
CC_INCLUDES += -I/usr/local/include

CC_LIBRARIES = -ljail

CC_WARNINGS = -Wall -Wextra -Werror 
CC_WARNINGS += -Wformat -Wformat-security -Werror=format-security

CC_SECURITY += -D_FORTIFY_SOURCE=2 
CC_SECURITY += -fstack-protector

CC_OPTS = $(CC_WARNINGS) $(CC_ERLANG) $(CC_LIBRARIES) $(CC_INCLUDES)
CC_OPTS += $(CC_SECURITY)


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

######################################################################
#
######################################################################
all: clean jail_nif.so jail_port

######################################################################
# iovec helpers functions
######################################################################
iovec_test:
	$(CC) $(CC_OPTS) -o$@ iovec_test.c
	./iovec_test

iovec.so: iovec_test
	$(CC) $(CC_OPTS) -o$@ iovec.c

######################################################################
# Jail API
######################################################################
get_jail.o:
	@echo Building @$...
	$(CC) $(CC_OPTS) -o$@ get_jail.c

set_jail.o:
	@echo Building @$...
	$(CC) $(CC_OPTS) -o$@ set_jail.c

######################################################################
# Jail API Test (ATF)
######################################################################
get_jail_test.o: get_jail.o
	@echo Building @$...
	$(CC) $(CC_OPTS) -o$@ get_jail.o get_jail_test.c

set_jail_test.o: set_jail.o
	@echo Building @$...
	$(CC) $(CC_OPTS) -o$@ set_jail.o set_jail_test.c

# run test everytime we rebuild our source
test: get_jail_test.o set_jail_test.o
	@echo Building @$...
	$(CC) $(CC_OPTS) -o$@ get_jail_test.o set_jail_test.o
	@echo Running tests...
	./test

######################################################################
# Erlang Jail Interface (NIF)
######################################################################
jail_nif_test: get_jail.o set_jail.o 
	$(CC) $(CC_OPTS) -o$@ get_jail.o set_jail.o jail_nif_test.c
	./jail_nif_test

jail_nif.so: get_jail.o set_jail.o jail_nif_test
	@echo Building @$...
	$(CC) $(CC_OPTS) -o$@ get_jail.o set_jail.o jail_nif.c

jail_nif.erl:
	@echo Work in progress...

######################################################################
# Erlang Jail Interface (Port)
######################################################################
jail_port_test: get_jail.o set_jail.o 
	$(CC) $(CC_OPTS) -o$@ get_jail.o set_jail.o jail_port_test.c
	./jail_port_test

jail_port: get_jail.o set_jail.o test
	@echo Building @$...
	$(CC) $(CC_OPTS) -o$@ get_jail.o set_jail.o jail_port.c

jail_port.erl:
	@echo Work in progress...

######################################################################
# remove all compiled files
######################################################################
clean:
	-rm *~
	-rm *.core
	-rm *.o *.so
	-rm test

######################################################################
# help
######################################################################
help:
	@echo "make [all|test|clean]"
