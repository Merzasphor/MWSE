#ifndef _LOG_H_JRYUMNWETYNWRTNJRYU
#define _LOG_H_JRYUMNWETYNWRTNJRYU

#include <wtypes.h>

struct LOG
{
	LOG();
	virtual ~LOG(void);
	static bool open(const char* filename);
	static int log(const char* fmt, ...);
	static int logbinary(VOID* addr, int size);
	static void close(void);
	
private:
	static HANDLE handle;
};

#endif
