#include <stdio.h>
#include <stdlib.h>
#include "cpu_capability.h"
#include <windows.h>


int CpuGetCoreNum(void)
{
	SYSTEM_INFO info;
	memset(&info,0,sizeof(info));
	GetSystemInfo(&info);
	printf("PROCmask= %d\n",info.dwActiveProcessorMask);
	printf("PROCLEVEL= %d\n", info.wProcessorLevel);

	return info.dwNumberOfProcessors;


}