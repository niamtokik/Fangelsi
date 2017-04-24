/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 * 
 */

#include <stdio.h>
#include <atf-c.h>
#include "iovec.h"

ATF_TC(iovec);
ATF_TC_HEAD(iovec, tc) {
  atf_tc_set_md_var(tc, "descr", "iovec library test");
}
ATF_TC_BODY(iovec, tc) {
  ATF_CHECK_EQ(0, 0 + 0);
  ATF_CHECK_EQ(2, 1 + 1);
}

ATF_TC(iovec2);
ATF_TC_HEAD(iovec2, tc) {
  atf_tc_set_md_var(tc, "descr", "iovec library test");
}
ATF_TC_BODY(iovec2, tc) {
  ATF_CHECK_EQ(0, 0 + 0);
  ATF_CHECK_EQ(2, 1 + 1);
}

ATF_TP_ADD_TCS(tp){
  ATF_TP_ADD_TC(tp, iovec);
  ATF_TP_ADD_TC(tp, iovec2);
  return atf_no_error();
}         
