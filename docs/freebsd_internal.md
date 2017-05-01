# FreeBSD Internals

Here some answers to lot of questions I have about FreeBSD internals

## How create iovec structure?

```
// iovec on stack, with a key and value
static struct iovec io[2] = NULL;

// iovec on heap, with a key and value
struct iovec *io = calloc(0, 2*sizeof(struct iovec));
// don't forget to free it after allocation
free(io);
```

## How to add elements in iovec structure?

```
io.iov_base = &data; // data address
io.iov_len = sizeof(data); // sizeof data
```

## How FreeBSD kernel interpret parameters?

FreeBSD  kernel use  iovec  as  key/value pair,  like  a tuple.  First
element is the key, and the next element is the value.

You can define a new structure as tuple to match parameter easily:

```
struct tuple {
  iovec key = NULL;
  iovec value = NULL;
};

tuple.key.iov_base = key_content; // pointer
tuple.key.iov_len = key_length; // integer

tuple.value.iov_base = value_content; // pointer
tuple.value.iov_len = value_length; //integer

```

If  you have  multiple parameter  to pass,  you can  create a  list of
tuple, in this case, your list will be ever even.

Your tuples will be interpret directly in `sys/kern/kern_jail.c`.

## How FreeBSD kernel parse parameter?

see `sys/kern/kern_jail.c`.

## How to list all available parameter?

In C, you'll need `sys/sysctl.h`.

In CLI, you can use `sysctl security.jail.param`.

## How to check if my pid run in a jail?

`sysctl security.jail.jailed` will  return 1 if you are  in jail else,
this MIB will return 0.

## How to find jail param?

All jail params  can be found in  `sys/kern/kern_jail.c:4410`. A macro
named  SYSCTL_JAIL_PARAM (defined  in `sys/sys/jail.h`)  will generate
all available parameters. You can use it like that:

```
SYSCTL_JAIL_PARAM(Module, Name, Type, Format, Descr)
```

Module: Module Name.

name: Param Name.

Format: Type of parameter:

 * "I": Integer
 * "B": Boolean
 * "S": String
 * "S,Struct,Var": Structure.

Descr: Description about parameter.

## How to add vnet to a jail?

In C:

## How to add epair interface to a jail?

In C:

## How to check if I can use vnet?

You can check that with `sysctl security.jail.vnet`

## How to allocate defined ressource to jail?

This feature require  RACCT options in kernel. You'll need  to build a
new one.

CLI   interface   can  be   read   in   `usr.bin/rctl`,  kernel   side
implementation is available in `sys/kern/kern_rctl.c`.
