# fangelsi

Yet another FreeBSD/DragonFlyBSD jail manager

## Project goals

 * Easy way to interconnect jails with network feature
 * Easy way to learn commands from scratch
 * Highly compatible with FreeBSD generic tools

## Proof of Concept

First PoC was made in shell, long time ago. Next in Perl,
and finaly... In shell.

This project try to use some concept from functional programming,
we share data from output and get it from input. This make code
like elixir or F# first argument.

This method is slow but work pretty well.

### Usage

    fang start ${jail1} ${jail2}
    fang connect ${jail1} to ${jail2} with ${epair}
    fang connect ${jail1} to ${jail2} with ${bridge}
    fang stop ${jail1}
    fang clear # remove all epair/bridge interface

    # not working yet
    # fang connect ${jail1} to ${jail2} with ${vlan}
    # fang connect ${jail1} to ${jail2} with ${vxlan}

### Functionality

 * start/restart/stop jails
 * deploy jails
 * list jails
 * console
 * install package into jails
 * create epair/bridge and connect it to jails
 * clear all epair/bridge created
 * work on FreeBSD10 and FreeBSD11

## Final version?

I need something more efficient and low level. I was thinking
to make different jail library for:

 * Perl
 * Erlang/Elixir
 * Ocaml
 * Go

Each one in C or C++. Another alternative is to copy this 
functionality into an active project like ezjail, cbsd, or iocage.

## State

Doesn't have time to make this project alive. So. Only testing
branch!

