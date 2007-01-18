#ifndef _ERR_CMAILSERVER
#define _ERR_CMAILSERVER
/****************************************\
* 1/8/07 AnthonyG                        *
* This is what allows the MWSE DLL       *
* To send messages to the loader         *
* In turn outputting them to the console *
\****************************************/
#include<windows.h>
#include<StdIO.h>

class cMailServer
{
private:
	//----------------------
	const char* vServerName;
	HANDLE vMailHandle;
	//----------------------
	DWORD vMsgWaiting,vBytesRead,vBytesToRead;
	char vMail[1000];
public:
	//Create the server
	void mCreateServer();
	//Write a message
	void mWriteMail(char msg[]);
	//Check the mail and write it to the console
	void mReadMail();
	//Shutdown the server
	void mShutdownServer();

	cMailServer();
	~cMailServer();
};

#endif