/** copyright (c) 2017, Mathieu Kerjouan <mk [at] steepath.eu>
 * 
 */

#include <erl_nif.h>
#include <sys/param.h>
#define NAME_SIZE 1024

extern int getid(char *);
extern char * getname(int);
extern int next_jail(unsigned int);

static ERL_NIF_TERM
getid_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  char *name = enif_alloc(MAXHOSTNAMELEN);
  int ret;
  if (!enif_get_string(env, argv[0], name, NAME_SIZE, ERL_NIF_LATIN1)) {
    return enif_make_badarg(env);
  }
  ret = getid(name);
  return enif_make_int(env, ret);
}

static ERL_NIF_TERM
getname_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  int id;
  char *ret;

  if (!enif_get_int(env, argv[0], &id)) {
    return enif_make_badarg(env);
  }
  ret = getname(id);
  return enif_make_string(env, ret, ERL_NIF_LATIN1);
}

static ERL_NIF_TERM
next_jail_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
  int jid;
  if (!enif_get_int(env, argv[0], &jid)) {
    return enif_make_badarg(env);
  }
  int ret = next_jail(jid);
  return enif_make_int(env, ret);
}

static ErlNifFunc nif_funcs[] = {
  {"getid", 1, getid_nif},
  {"getname", 1, getname_nif},
  {"next_jail", 1, next_jail_nif}
};

ERL_NIF_INIT(jail, nif_funcs, NULL, NULL, NULL, NULL)
