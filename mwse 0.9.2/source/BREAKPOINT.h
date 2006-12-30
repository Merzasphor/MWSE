//BreakPoint.h
#pragma once

#include <wtypes.h>

struct HWBREAKPOINT
{
	virtual LPVOID getaddress() = 0;
	virtual bool breakpoint() = 0;
};
