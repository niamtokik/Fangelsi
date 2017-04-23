/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 * 
 */

#include <atf-c.h>
#include "jail.h"

/* helper function */
ATF_TC(_lastjid);
ATF_TC_HEAD(_lastjid, tc){}
ATF_TC_BODY(_lastjid, tc){}

ATF_TC(_name);
ATF_TC(_jid);
ATF_TC(_parameter);

/* main get function */
ATF_TC(get_first_jail);
ATF_TC(get_next_jail);
ATF_TC(get_name);
ATF_TC(get_jid);
ATF_TC(get_all_jid);
ATF_TC(get_running_jails);
ATF_TC(get_parameter_with_jid);
ATF_TC(get_parameter_with_name);
ATF_TC(get_parameters_with_jid);
ATF_TC(get_parameters_with_name);
