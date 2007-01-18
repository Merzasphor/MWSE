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
		vsprintf(buf, fmt, args);
	else
		strcpy(buf, "DLL:log(null)\n");

	buf[sizeof(buf)-1] = '\0';
	vMail->mWriteMail(buf);
	va_end(args);
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