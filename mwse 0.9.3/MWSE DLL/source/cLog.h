#pragma once

#include "cMailClient.h"

#include <stdarg.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>

class cLog
{
private:
	static cMailClient *vMail;
public:
	//Open the log
	static void mOpenLog();

	//Log message to console
	static void mLogMessage(const char* fmt, ...);

	//close the log
	static void mCloseLog();

	~cLog();
};