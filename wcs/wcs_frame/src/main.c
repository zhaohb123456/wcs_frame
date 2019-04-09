#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./cpu/cpu_capability.h"

int main()
{
	int num = 0;
	num = CpuGetCoreNum();
	printf("windows C program CPU Core Numbet = %d\n",num);
	return 0;
}