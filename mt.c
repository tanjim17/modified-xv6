// #include "types.h"
// #include "stat.h"
// #include "user.h"
// #include "param.h"
// #include "mmu.h"
// #include "proc.h"

// void memtest(){
// 	int currsize = (uint)sbrk(0);
// 	printf(1, "starting addr: %d\n", currsize);
// 	for (int i = currsize; i < MAX_TOTAL_PAGES * PGSIZE; i += PGSIZE) {
// 		sbrk(PGSIZE);
// 	}
// 	if((uint)sbrk(0) != MAX_TOTAL_PAGES * PGSIZE) {
// 		printf(1, "error!");
// 		return;
// 	}
// }

// int main(int argc, char *argv[]){
// 	memtest();
// 	exit();
// }

#include "types.h"
#include "stat.h"
#include "user.h"

void try1()
{
    int sz = 4096 * 17;
    char *a = (char *)malloc(sz);

    for (int i = 0; i < sz - 1; i++)
    {
        char ch = (i % 26) + 'a';
        a[i] = ch;
    }
    sleep(250);
    int flag = 1;

    for (int i = 0; i < sz - 1; i++)
    {
        if (a[i] - 'a' != (i % 26))
        {
            printf(2, "Index i = %d , Failed\n", i);
            flag = 0;
            break;
        }
    }
    if (!flag)
    {
        printf(2, "Failed!!!\n");
    }
    else
    {
        printf(2, "Success!!!\n");
    }
    free((void *)a);
}

void try2()
{
    int sz = 4096 * 17;
    int *a = (int *)malloc(sz);
    int pid = fork();
    int x;
    int y;
    if (pid == 0)
    {
        x = 21;
        y = 30;
    }
    else
    {
        x = 11;
        y = 20;
    }

    for (int i = 0; i < sz / 4; i++)
    {
        a[i] = (x ^ i) * y;
    }
    sleep(250);
    int flag = 1;
    for (int i = 0; i < sz / 4; i++)
    {
        if (a[i] != (x ^ i) * y)
        {
            printf(2, "%d %d %d\n", i, (x ^ i) * y, a[i]);
            flag = 0;
            break;
        }
    }
    // sleep(250);
    if (!flag)
    {
        printf(2, "Failed!!!\n");
    }
    else
    {
        printf(2, "Success!!!\n");
    }
    free((void *)a);
    if (pid != 0)
    {
        wait();
    }
}
int main(int argc, char *argv[])
{
    try1();
    //try2();
    exit();
}



