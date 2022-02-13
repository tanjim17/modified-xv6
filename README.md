## Modified xv6

xv6 is a teaching OS developed in MIT. I did some modifications in it in my undergrad course "CSE 314: Operating System Sessional."

Base repo: https://github.com/mit-pdos/xv6-public

### List of modifications
1. Added a user program `time` which counts the time (number of ticks) taken by the program given as its argument

    ![prompt](/images/time.png)
2. Implemented **lottery scheduling** instead of xv6's default round robin policy
    * Files modified: `proc.c` `proc.h`
    * Run the user program `ps` for testing
3. Created paging system with **FIFO page replacement algorithm** for memory management. Also started to implement NRU algorithm as an alternative but didn't finish :(
    * Files modified: `vm.c` `fs.c` `proc.c` `proc.h` `trap.c` `sysfile.c` `mmu.h` `defs.h`
    * Run the user program `mt` for testing (Before running, uncomment the *cprintf* functions in *vm.c*)
#### Other minor modifications
* Updated xv6's `atoi` function which couldn't handle negative number before
* Utilized `HLT` instruction to decrease CPU usage
    * Files modified: `proc.c` `x86.h`
* Changed the boring default prompt to the cool prompt shown in the above image :3
    * Files modified: `sh.c`
