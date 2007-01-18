#include"cMailServer.h"

void cMailServer::mCreateServer()
{
	vMailHandle=CreateMailslot(vServerName,1000,MAILSLOT_WAIT_FOREVER,0);
	if(vMailHandle!=INVALID_HANDLE_VALUE)
		printf("Created MailSlot Server");
	else
		printf("Could Not Create Mailslot server!!!");
}

void cMailServer::mWriteMail(char msg[])
{
	if(!WriteFile(vMailHandle,msg,1000,&vBytesToRead,0))
		printf("Failed to write mail!");
}

void cMailServer::mReadMail()
{
	if(!GetMailslotInfo(vMailHandle,&vBytesToRead,&vMsgWaiting,0,0))
		printf("Could not read mail!");

	if(vMsgWaiting!=MAILSLOT_NO_MESSAGE)
	{
		if(!ReadFile(vMailHandle,vMail,1000,&vBytesToRead,0))
		{
			printf("Could not read mail");
		}
		else
		{
			printf(vMail);
		}
	}
}

void cMailServer::mShutdownServer()
{
	if(CloseHandle(vMailHandle)!=0)
		printf("Shutdown Mailslot Server");
	else
		printf("Couldn't Shutdown Server!");
}

cMailServer::cMailServer()
{
	vServerName="\\\\.\\mailslot\\MorrowindScriptExtenderMailslot";
	vBytesToRead=1000;
}

cMailServer::~cMailServer()
{
}