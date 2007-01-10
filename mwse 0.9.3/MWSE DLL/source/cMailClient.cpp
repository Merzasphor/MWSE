#include"cMailClient.h"

void cMailClient::mOpenMailConnection()
{
	vSlotHandle=CreateFile(vServerName,GENERIC_WRITE,FILE_SHARE_READ,0,OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,0);
}

void cMailClient::mWriteMail(char mail[])
{
	WriteFile(vSlotHandle,mail,vBytes2Write,&vBytesWritten,0);
}

void cMailClient::mCloseMailConnection()
{
	CloseHandle(vSlotHandle);
}

cMailClient::cMailClient()
{
	vServerName="\\\\.\\mailslot\\MorrowindScriptExtenderMailslot";
	vBytes2Write=1000;
}

cMailClient::~cMailClient()
{
}