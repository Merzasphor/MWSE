#pragma once

#include "WinHeader.h"

struct LOG
{
	LOG();
	virtual ~LOG();
	static bool open(const char* filename);
	static int log(const char* fmt, ...);
	static int logbinary(void* addr, int size);
	static void close();
private:
	static HANDLE handle;
};
