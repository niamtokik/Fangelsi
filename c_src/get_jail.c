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

/** \brief get_jail.c
 *
 *  This file contain all functions to retrieve information from
 *  jails, based directly on syscall. This code doesn't use libjail.
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

/** \brief return jid of first started jail from kernel
 *
 *  This function return a positive integer if a jail
 *  is currently running. 0 or -1 is returning in case
 *  of no jails are currently running on the system.
 *
 * @todo check for 0 or -1, need only one value.
 * 
 */
int
get_first_jail(void) {
  //struct iovec io[4] = _lastjid();
  //jail_get(_lastjid(), 2, 0);
  //return io[3].iov_base;
  return -1;
}


/** \brief return the following jail.
 *
 *  This function take jid (integer) as parameter and
 *  will return the following jail from kernel linked
 *  jails list. If jid 1 is given, you can receive any
 *  other integer and probably not 2.
 *
 * @param jid as integer
 * @return integer (running jail)
 * @see sys/kern_jail.c
 * @todo
 */
int
get_next_jail(int jid) {
  printf("%d\n", jid);
  return -1;
}


/** \brief give a name and search associated jid 
 *         if exist
 *
 * @param
 * @return
 * @see
 * @todo
 */
int
get_jid(char *name){
  printf("%s\n", name);
  return -1;
}


/** \brief give a jid and search for associated name if
 *         exist
 *
 * @param
 * @return
 * @see
 * @todo
 */
char *
get_name(int jid){
  printf("%d\n", jid);
  return "";
}


/** \brief return a list of all running jail as jid
 *
 * @param
 * @return
 * @see
 * @todo
 */
int
get_all_jid(int *list, size_t len){
  printf("%p\n", &list);
  printf("%zu\n", len);
  return -1;
}


/** \brief
 *
 * @param
 * @return
 * @see
 * @todo
 */
struct iovec *
get_parameter_with_jid(int jid, struct iovec *param){
  static struct iovec *t;
  printf("%d\n", jid);
  printf("%p\n", &param);
  return t;
}


/** \brief
 *
 * @param
 * @return
 * @see
 * @todo
 */
struct iovec *
get_parameter_with_name(char *name, struct iovec *param){
  static struct iovec *t;
  printf("%s\n", name);
  printf("%p\n", &param);
  return t;
}


/** \brief
 *
 * @param
 * @return
 * @see
 * @todo
 */
struct iovec *
get_parameters_with_jid(int jid){
  static struct iovec *t;
  printf("%d\n", jid);
  return t;
}


/** \brief
 *
 * @param
 * @return
 * @see
 * @todo
 */
struct iovec *
get_parameters_with_name(char *name){
  static struct iovec *t;
  printf("%s\n", name);
  return t;
}


/** \brief return a pointer to iovec set with name
 *
 * @param
 * @return
 * @see
 * @todo we can make things in different ways, we can return
 *       an iovec pointing to a new structure, or we can alter
 *       a created one. The first method give full abstraction
 *       but doesn't give more flexibility. The next one is
 *       more flexible but required more param (sanitizing).
 */
struct iovec *
_lastjid(void){
  int jid = 0;
  static struct tuple *tu;
  tu = iovec_tuple("lastjid", sizeof("lastjid"),
		   &jid, sizeof(jid));
  return tuple_to_iovec(tu);
}


/** \brief return a pointer to iovec set with name
 *
 * @param
 * @return
 * @see
 * @todo
 */
struct iovec *
_name(char *name){
  static struct iovec *t;
  printf("%s\n", name);
  return t;
}


/** \brief return a pointer to iovec set with jid
 *
 * @param
 * @return
 * @see
 * @todo
 */
struct iovec *
_jid(int jid){
  static struct iovec *t;
  printf("%d\n", jid);
  return t;
}


/** \brief return a pointer to iovec with parameter
 *
 * @param
 * @return
 * @see
 * @todo
 */
struct iovec *
_parameter(char *param, size_t param_len){
  static struct iovec *t;
  printf("%s\n", param);
  printf("%zu\n", param_len);
  return t;
}
