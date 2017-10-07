#ifndef _ERR_CMAILCLIENT
#define _ERR_CMAILCLIENT
/*******************************\
* 1/9/07 AnthonyG:              *
* In this case, The DLL         *
* acts as a client to interface *
* with the mail server AKA      *
* MWSE Loader                   *
\*******************************/
#include<windows.h>

class cMailClient
{
private:
	HANDLE vSlotHandle;
	const char* vServerName;
	DWORD vBytesWritten,vBytes2Write;
public:
	//Open the mailbox
	void mOpenMailConnection(char serverName[]);
	//Write a letter
	void mWriteMail(char mail[]);
	//Shut it
	void mCloseMailConnection();

	cMailClient();
	~cMailClient();
};

#endif