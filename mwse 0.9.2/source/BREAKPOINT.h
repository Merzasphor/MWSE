#ifndef _BREAKPOINT_H_SFGBSFGBASDRTYNRTYUSAFRVRRYGHAWR
#define _BREAKPOINT_H_SFGBSFGBASDRTYNRTYUSAFRVRRYGHAWR

#include <wtypes.h>

struct HWBREAKPOINT
{
	virtual LPVOID getaddress()= 0;
	virtual bool breakpoint()= 0;
};


#endif
