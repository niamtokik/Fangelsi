/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
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
struct_jail_init(struct jail *j) {
  j = memset(j, 0, sizeof(struct jail));
}

void struct_jail_set_version(struct jail *j, uint32_t version) {
  j->version = version;
}

void struct_jail_set_path(struct jail *j, char *path) {
  j->path = path;
}

void struct_jail_set_hostname(struct jail *j, char *hostname) {
  j->path = hostname;
}

void struct_jail_set_jailname(struct jail *j, char *jailname) {
  j->jailname = jailname;
}

void
struct_jail_set_ip4_address(struct jail *j,
			    unsigned int nip4,
			    struct in_addr *ip4) {
  j->ip4s = nip4;
  j->ip4 = ip4;
}

void struct_jail_set_ip6_address(struct jail *j,
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
