#pragma once

#include <stdio.h>  // cannot use 'class FILE';

class cLog
{
private:
	static FILE *logFile;
    static const char *defaultLogFilename;
public:
	//Open the log
	static void mOpenLog();

	//Log message to console
	static void mLogMessage(const char* fmt, ...);

	//Logs error to console, and optionally shows an MessageBox
	static void mLogError(const char *message, bool ShowMessageBox);

	//Log binary message to console
	static void mLogBinaryMessage(void* addr, int size);


	//close the log
	static void mCloseLog();

	~cLog();
};