/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 * 
 */

#include <sys/types.h>
#include <sys/uio.h>

/*
 * tuple datastructure is a key/value
 * datastructure inspired from jail.c
 */
struct tuple {
  struct iovec key;
  struct iovec value;
};

/*
 * interface
 */
struct iovec *iovec_init(void);
void iovec_push(struct iovec *, void *, size_t);
struct tuple *iovec_tuple(void *, size_t, void *, size_t);
struct tuple *iovec_tuples(struct tuple *, struct tuple *);
struct iovec *tuple_to_iovec(struct tuple *);
