# Fangelsi

Erlang FreeBSD/DragonFlyBSD jail manager.

## C Library

This project use another version of libjail, builded from scratch and
using only freebsd jail syscall. Two version will be available:

 * Ports version, using strong isolation between Erlang node and C
   library
   
 * NIF version, running directly on the BEAM.

### Coding rules:

 1. KISS (Keep It Simple, Stupid).
 
 2. One function, one action.
 
 3. Don't use HEAP if you can use STACK.
 
 4. Use HEAP only if you can't use STACK.
 
 5. Document everything.
 
 6. Test everything.
 
 7. Don't repeat yourself.

### This library use (or will use):

 * CLANG/LLVM (https://clang.llvm.org/)
 
 * Doxygen (http://www.stack.nl/~dimitri/doxygen/)
 
 * ATF (https://github.com/jmmv/atf)
 
 * Valgrind (http://valgrind.org/)
 
 * Capsicum (https://www.cl.cam.ac.uk/research/security/capsicum/freebsd.html)
 
 * 3-Clause BSD License (https://opensource.org/licenses/BSD-3-Clause)

## Usage

Work in progress.
