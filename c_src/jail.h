/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 *
 */

/* functions to get essentials values, jid and name */
int get_first_jail(void);
int get_next_jail(unsigned int);
int get_jid(char *);
char *get_name(int);
int *get_all_jid(void);

/* functions to get one parameter via name or jid */
struct iovec *get_parameter_with_jid(int);
struct iovec *get_parameter_with_name(char *);

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

