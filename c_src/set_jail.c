/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *  1. Redistributions of source code  must retain the above copyright
 *  notice, this list of conditions and the following disclaimer.
 *
 *  2.  Redistributions  in  binary  form  must  reproduce  the  above
 *  copyright  notice,  this  list  of conditions  and  the  following
 *  disclaimer in  the documentation  and/or other  materials provided
 *  with the distribution.
 *
 *  3. Neither the  name of the copyright holder nor  the names of its
 *  contributors may  be used to  endorse or promote  products derived
 *  from this software without specific prior written permission.
 * 
 *  THIS   SOFTWARE  IS   PROVIDED  BY   THE  COPYRIGHT   HOLDERS  AND
 *  CONTRIBUTORS  "AS  IS"  AND  ANY EXPRESS  OR  IMPLIED  WARRANTIES,
 *  INCLUDING,  BUT   NOT  LIMITED  TO,  THE   IMPLIED  WARRANTIES  OF
 *  MERCHANTABILITY  AND   FITNESS  FOR   A  PARTICULAR   PURPOSE  ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS
 *  BE  LIABLE   FOR  ANY   DIRECT,  INDIRECT,   INCIDENTAL,  SPECIAL,
 *  EXEMPLARY, OR  CONSEQUENTIAL DAMAGES  (INCLUDING, BUT  NOT LIMITED
 *  TO,  PROCUREMENT OF  SUBSTITUTE GOODS  OR SERVICES;  LOSS OF  USE,
 *  DATA, OR PROFITS; OR BUSINESS  INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 *  TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 *  THE USE  OF THIS SOFTWARE, EVEN  IF ADVISED OF THE  POSSIBILITY OF
 *  SUCH DAMAGE.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "iovec.h"
#include <jail.h>
#include <sys/jail.h>
#include "jail.h"

void
init_struct_jail(struct jail *j) {
  j = memset(j, 0, sizeof(struct jail));
}

void
set_struct_jail_with_version(struct jail *j, uint32_t version) {
  j->version = version;
}

void
set_struct_jail_with_path(struct jail *j, char *path) {
  j->path = path;
}

void
set_struct_jail_with_hostname(struct jail *j, char *hostname) {
  j->path = hostname;
}

void
set_struct_jail_with_jailname(struct jail *j, char *jailname) {
  j->jailname = jailname;
}

void
set_struct_jail_with_ip4(struct jail *j,
			 unsigned int nip4,
			 struct in_addr *ip4) {
  j->ip4s = nip4;
  j->ip4 = ip4;
}

void
set_struct_jail_with_ip6(struct jail *j,
			 unsigned int nip6,
			 struct in_addr *ip6) {
  j->ip6s = nip6;
  j->ip6 = ip6;
}

int
new_jail(struct *iovec, u_int niov) {
  return jail_set(iovec, niov, JAIL_CREATE);
}

int
update_jail(struct *iovec, u_int niov) {
  return jail_set(iovec, niov, JAIL_UPDATE);
}

int
attach_current_process_to_jail(struct *iovec, u_int niov) {
  return jail_set(iovec, niov, JAIL_ATTACH);
}

int
remove_jail(int jid) {
  return jail_remove(jid);
}
