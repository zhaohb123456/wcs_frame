#include <stdio.h>
#include <stdlib.h>
#include "cpu_capability.h"
#include "../system_compatible.h"

#if defined(WINDOWS)
#include <windows.h>

#elif defined(LINUX)
#include <sys/sysinfo.h>

#endif // 


int CpuGetCoreNum(void)
{
#if defined(WINDOWS)
	SYSTEM_INFO info;
	memset(&info,0,sizeof(info));
	GetSystemInfo(&info);
	printf("PROCmask= %d\n",info.dwActiveProcessorMask);
	printf("PROCLEVEL= %d\n", info.wProcessorLevel);

	return info.dwNumberOfProcessors;
#elif defined(LINUX)
	return get_nprocs();

#else
	return UNSUPPORTED_SYSTEM;
#endif // 


}