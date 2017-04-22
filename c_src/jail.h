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

/* functions to get essentials values, jid and name */
int get_first_jail(void);
int get_next_jail(int);
int get_jid(char *);
char *get_name(int);
int get_all_jid(int *list, size_t len);

/* functions to get one parameter via name or jid */
struct iovec *get_parameter_with_jid(int, struct iovec*);
struct iovec *get_parameter_with_name(char *, struct iovec*);

/* functions to get all parameters via name or jid */
struct iovec *get_parameters_with_jid(int);
struct iovec *get_parameters_with_name(char *);

/* internal functions helpers*/
struct iovec *_lastjid(void);
struct iovec *_name(char *);
struct iovec *_jid(int);
struct iovec *_parameter(char *, size_t);

/* managing jails */
// int start(struct iovec *);
// int stop(struct iovec *);

