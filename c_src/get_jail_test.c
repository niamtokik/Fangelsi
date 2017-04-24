/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 * 
 */

#include <stdio.h>
#include <atf-c.h>
#include "jail.h"
#include "iovec.h"

/* helper function */
ATF_TC(lastjid);

ATF_TC_HEAD(lastjid, tc){
  atf_tc_set_md_var(tc, "descr", "_lastjid test");
}

ATF_TC_BODY(lastjid, tc){
  ATF_CHECK_EQ(0, 0+0);
}

ATF_TP_ADD_TCS(tp){
  ATF_TP_ADD_TC(tp, lastjid);
  return atf_no_error();
}
