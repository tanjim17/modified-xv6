#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
    char** argv1 = (char**)malloc((argc - 1)*sizeof(char*));
    for (int i = 1; i < argc; i++) {
        argv1[i - 1] = argv[i];
    }
    int start = uptime();
    int pid = fork();
    if (pid == 0) {
        exec(argv1[0], argv1);
    } else {
        wait();
    }
    int end = uptime();
    printf(1, "time: %d\n", end - start);
    exit();
}