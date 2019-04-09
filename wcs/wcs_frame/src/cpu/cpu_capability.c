#include <stdio.h>
#include <stdlib.h>
#include "cpu_capability.h"
#include <sys/sysinfo.h>



int CpuGetCoreNum(void)
{

	return get_nprocs();

}