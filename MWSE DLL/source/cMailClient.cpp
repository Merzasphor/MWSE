#include"cMailClient.h"

void cMailClient::mOpenMailConnection(char serverName[])
{
	if(vSlotHandle == INVALID_HANDLE_VALUE)
	{
		vServerName = serverName;
		vSlotHandle=CreateFile(vServerName,GENERIC_WRITE,FILE_SHARE_READ,0,OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,0);
        if (vSlotHandle == INVALID_HANDLE_VALUE) {
            MessageBox(NULL, "Unable to open mail slot", "MWSE Initialization Failure", 0);
        }
	}
}

void cMailClient::mWriteMail(char mail[])
{
	if(vSlotHandle != INVALID_HANDLE_VALUE)
		WriteFile(vSlotHandle,mail,vBytes2Write,&vBytesWritten,0);
}

void cMailClient::mCloseMailConnection()
{
	if(vSlotHandle != INVALID_HANDLE_VALUE)
	{
		CloseHandle(vSlotHandle);
		vSlotHandle = INVALID_HANDLE_VALUE;
	}
}

cMailClient::cMailClient()
{
	vSlotHandle = INVALID_HANDLE_VALUE;
	vBytes2Write = 1000;
}

cMailClient::~cMailClient()
{
	mCloseMailConnection();
}