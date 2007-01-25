#include <stdio.h>
#include <stdarg.h>

#include <windows.h>

#include "cLog.h"

FILE *cLog::logFile = NULL;
const char *cLog::defaultLogFilename = "MWSELog.txt";

void cLog::mOpenLog()
{
    if (logFile == NULL) {
        logFile = fopen(defaultLogFilename, "w");
        // disable buffering
        setvbuf(logFile, NULL, _IONBF, 0);
    }
}

void cLog::mLogMessage(const char* fmt, ...)
{
	char buf[1024] = "\0";

	va_list args;
	va_start(args, fmt);
    if (fmt) {
        vfprintf(logFile, fmt, args);
    } else {
        fprintf(logFile, "DLL:log(null)\n");
    }
	va_end(args);
}

void cLog::mLogError(const char *message, bool ShowMessageBox)
{
    fputs(message, logFile);
    if(ShowMessageBox) {
        MessageBox(0, message, "MWSE Error", MB_OK|MB_ICONERROR);
    }
}

void cLog::mLogBinaryMessage(void *addr, int size)
{
	BYTE *ptr = (BYTE*)addr;
    int y;
	for (y = 0;y < size;y += 16)
	{
        int x;
		mLogMessage("\t");
		for (x = 0;x < 16 && (x+y) < size; x++)
			mLogMessage("%02X ", ((int)ptr[y+x])&0xFF);
		mLogMessage("\t");

		for (x = 0;x < 16 && (x+y) < size; x++)
			if(isprint(ptr[y+x]))
				mLogMessage("%c", ptr[y+x]);
			else
				mLogMessage(".");
		mLogMessage("\n");
	}
}

void cLog::mCloseLog()
{
    fclose(logFile);
    logFile = NULL;
}

cLog::~cLog()
{
	mCloseLog();
}