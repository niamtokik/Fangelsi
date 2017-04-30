/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 * 
 */

#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/param.h>
#include "iovec.h"

/** \brief initialize iovec datastructure on the stack.
 * 
 */
struct iovec *
iovec_init(void) {
  static struct iovec io;
  io.iov_base = NULL;
  io.iov_len = 0;
  return &io;
}

/** \brief push data on iovec datastructure.
 *
 */
void
iovec_push(struct iovec *io, void *base, size_t len) {
  io->iov_base = base;
  io->iov_len = len;
}

/** \brief initialize and return a tuple with key/value pair.
 * 
 */
struct tuple *
iovec_tuple(void *key, size_t key_len
	    ,void *value, size_t value_len) {
  static struct tuple tu;
  iovec_push(&tu.key, key, key_len);
  iovec_push(&tu.value, value, value_len);
  return &tu;
}
/* \brief
 *
 */
struct tuple *
iovec_tuples(struct tuple *tu1, struct tuple *tu2) {
  (void)tu1;
  (void)tu2;
  return tu1;
}


/** \brief explicit conversion from tuple structure to
 *         iovec structure.
 */
struct iovec *
tuple_to_iovec(struct tuple *tu) {
  return (struct iovec*)tu;
}
