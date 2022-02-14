#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

void memtest(){
	int currsize = (uint)sbrk(0);
	printf(1, "starting addr: %d\n", currsize);
	char* a;
	for (int i = currsize; i < MAX_TOTAL_PAGES * PGSIZE; i += PGSIZE) {
		a = sbrk(PGSIZE);
		a[0] = 0; // for setting dirty bit while testing nru algorithm
	}
	if((uint)sbrk(0) != MAX_TOTAL_PAGES * PGSIZE) {
		printf(1, "error!");
		return;
	}
}

int main(int argc, char *argv[]){
	memtest();
	exit();
}