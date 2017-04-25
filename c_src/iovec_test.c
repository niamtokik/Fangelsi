/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 * 
 */

#include <atf-c.h>
#include "iovec.h"

/* iovec_init unit test */
ATF_TC(iovec_init);

ATF_TC_HEAD(iovec_init, tc) {
  atf_tc_set_md_var(tc, "descr", "iovec_init function unit testing");
}

ATF_TC_BODY(iovec_init, tc) {
  struct iovec *io = iovec_init();
  ATF_CHECK_EQ(io->iov_base, 0);
  ATF_CHECK_EQ(io->iov_len, 0);
}

/* iovec_push unit test */
ATF_TC(iovec_push);

ATF_TC_HEAD(iovec_push, tc) {
  atf_tc_set_md_var(tc, "descr", "iovec_push function unit testing");
}
ATF_TC_BODY(iovec_push, tc) {
  ATF_CHECK_EQ(0, 0 + 0);
  ATF_CHECK_EQ(2, 1 + 1);
}

/* iovec_tuple unit test */
ATF_TC(iovec_tuple);

ATF_TC_HEAD(iovec_tuple, tc) {
  atf_tc_set_md_var(tc, "descr", "iovec_tuple function unit testing");
}
ATF_TC_BODY(iovec_tuple, tc) {
  ATF_CHECK_EQ(0, 0 + 0);
  ATF_CHECK_EQ(2, 1 + 1);
}

/* iovec_push unit test */
ATF_TC(iovec_tuples);

ATF_TC_HEAD(iovec_tuples, tc) {
  atf_tc_set_md_var(tc, "descr", "iovec_tuples function unit testing");
}
ATF_TC_BODY(iovec_tuples, tc) {
  ATF_CHECK_EQ(0, 0 + 0);
  ATF_CHECK_EQ(2, 1 + 1);
}

/* iovec_push unit test */
ATF_TC(tuple_to_iovec);

ATF_TC_HEAD(tuple_to_iovec, tc) {
  atf_tc_set_md_var(tc, "descr", "tuple_to_iovec function unit testing");
}
ATF_TC_BODY(tuple_to_iovec, tc) {
  ATF_CHECK_EQ(0, 0 + 0);
  ATF_CHECK_EQ(2, 1 + 1);
}

/* main ATF functions */
ATF_TP_ADD_TCS(tp){
  ATF_TP_ADD_TC(tp, iovec_init);
  ATF_TP_ADD_TC(tp, iovec_tuple);
  ATF_TP_ADD_TC(tp, iovec_tuples);
  ATF_TP_ADD_TC(tp, tuple_to_iovec);
  return atf_no_error();
}         
