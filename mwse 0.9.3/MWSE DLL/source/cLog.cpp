#include "cLog.h"

cMailClient *cLog::vMail;

void cLog::mOpenLog()
{
	vMail = new cMailClient();

	vMail->mOpenMailConnection("\\\\.\\mailslot\\MorrowindScriptExtenderMailslot");
}

void cLog::mLogMessage(const char* fmt, ...)
{
	char buf[1024] = "\0";

	va_list args;
	va_start(args, fmt);
	if (fmt)
		_vsnprintf(buf, sizeof(buf)/sizeof(buf[0])-1, fmt, args);
	else
		strncpy(buf, "DLL:log(null)\n", sizeof(buf)-1);

	buf[sizeof(buf)-1] = '\0';
	vMail->mWriteMail(buf);
	va_end(args);
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
	vMail->mCloseMailConnection();
	delete vMail;
}

cLog::~cLog()
{
	mCloseLog();
}