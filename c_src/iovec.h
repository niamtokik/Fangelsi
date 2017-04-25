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

/** \brief new interfaces
 *
 * create a datastructure on stack or heap.
 *   iovec *iovec_create(int, int);
 *   tuple *tuple_create(int, int);
 *
 * datastructure initialization, agnostic interface
 * can use heap or stack. set by default all to NULL,
 * clean all memory:
 *   void iovec_init(struct iovec*);
 *   void tuple_init(struct tuple*);
 *   void iovecs_init(struct iovec*, size_t);
 *   void tuples_init(struct tuple*, size_t);
 *
 * set value.
 *   void iovec_set(struct iovec*, void *, size_t);
 *   void tuple_set(struct tuple*, int, void *, size_t);
 *   iovec *tuple_get(struct tuple *, int);
 *
 * convert iovec/tuple datastructure structure
 *   struct iovec *tuple_to_iovec(struct tuple*);
 *   struct tuple *iovec_to_tuple(struct iovec*);
 */
