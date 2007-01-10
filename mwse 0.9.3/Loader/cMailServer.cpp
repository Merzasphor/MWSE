#include"cMailServer.h"

void cMailServer::mCreateServer()
{
	vMailHandle=CreateMailslot(vServerName,1000,MAILSLOT_WAIT_FOREVER,0);
	if(vMailHandle!=INVALID_HANDLE_VALUE)
		iAction.mConsolePut("Created MailSlot Server");
	else
		iAction.mConsolePut("Could Not Create Mailslot server!!!");
}

void cMailServer::mWriteMail(char msg[])
{
	if(!WriteFile(vMailHandle,msg,1000,&vBytesToRead,0))
		iAction.mConsolePut("Failed to write mail!");
}

void cMailServer::mReadMail()
{
	if(!GetMailslotInfo(vMailHandle,&vBytesToRead,&vMsgWaiting,0,0))
		iAction.mConsolePut("Could not read mail!");

	if(vMsgWaiting!=MAILSLOT_NO_MESSAGE)
	{
		if(!ReadFile(vMailHandle,vMail,1000,&vBytesToRead,0))
		{
			iAction.mConsolePut("Could not read mail");
		}
		else
			iAction.mConsolePut(vMail);
	}
}

void cMailServer::mShutdownServer()
{
	if(CloseHandle(vMailHandle)!=0)
		iAction.mConsolePut("Shutdown Mailslot Server");
	else
		iAction.mConsolePut("Couldn't Shutdown Server!");
}

cMailServer::cMailServer()
{
	vServerName="\\\\.\\mailslot\\MorrowindScriptExtenderMailslot";
	vBytesToRead=1000;
}

cMailServer::~cMailServer()
{
}