## Tools

 * ~~Memory analysis~~: Valgrind
 * ~~Rest framework~~: ATF
 * ~~Documentation framework~~: Doxygen
 * erlang c testing
 
## C Library

 * make helpers for iovec
 * make dedicated datastructure for iovec
 * protect stack
 * make privilege separation
 * make converter function from C to Erlang
 * make converter function from Erlang to C
 * make unit test
 * make debug mode
 * make prod mode
 * make hardened mode
 * make Erlang Ports version
 * make Erlang NIF version
 
### iovec library

 * create tuple datastructure
 * create list of tuple
 * create converter function (tuple to iovec*)

### Read states (get)

 * ~~get first jail from kernel syscall~~ (PoC)
 * ~~get next jail from kernel syscall~~ (PoC)
 * list all jails from kernel syscall
 * ~~return numbers of running jails~~ (PoC)
 * ~~search name with jid~~ (PoC)
 * ~~search jid with name~~ (PoC)
 * search params from running jails
 * retrieve information for sysctl
 * retrieve kernel capabilities
 
 * retrieve list of pid from running jail
 
### Alter states (set)

 * start an empty jail
 * start a jail with parameter
 * update a current running jail with new parameter
 * stop a jail with jid
 * stop a jail with name
 * stop a jail with specitic parameter
 * stop a jail with list of parameters

### Extra features (Erlang side)

 * spawn erlang pod in jails to control inside processes
 * spawn jail from another nodes

## Future

 * manage network interface (vnet)
   * epair
   * bridge
 * manage ZFS
