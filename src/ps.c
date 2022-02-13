#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define TEST_PROC_COUNT 3

int main(int argc, char *argv[]) {
  int pids[TEST_PROC_COUNT];
  int ticket_count[TEST_PROC_COUNT] = {10, 20, 30};

  for (int i = 0; i < TEST_PROC_COUNT; i++) {
    if ((pids[i] = fork()) == 0) {
      settickets(ticket_count[i]);
      while(1);
    }
  }
  sleep(100);

  int parent_pid = getpid();
  while(1) {
    printf(1,"PID\tTicks\tTickets\n");
    struct pstat pinfo = {0};
    getpinfo(&pinfo);
    for (int i = 0; i < NPROC; i++) {
      if(pinfo.inuse[i] && pinfo.pid[i] > parent_pid) {
        printf(1, "%d\t%d\t%d\n", pinfo.pid[i], pinfo.ticks[i], pinfo.tickets[i]);
      }
    }
    sleep(500);
  }
  exit();
}