
#include "LOG.h"
#include "DEBUGGING.h"

#include <stdarg.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
// 22-08-2006 Tp21
#include "warnings.h"

HANDLE LOG::handle= INVALID_HANDLE_VALUE;

LOG::LOG()
{
}

LOG::~LOG(void)
{
	close();
}

bool LOG::open(const char* filename)
{
	close();
	handle= CreateFile(filename
		,GENERIC_WRITE
		,FILE_SHARE_READ
		,NULL
		,CREATE_ALWAYS //|TRUNCATE_EXISTING
#ifdef DEBUGGING		
		,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_WRITE_THROUGH
#else
		,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN
#endif
		,NULL);

	if(handle==INVALID_HANDLE_VALUE)
	{
		char buffer[512]="\0";
	
		buffer[FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,NULL,GetLastError(),0,buffer,sizeof(buffer)-1,NULL)]='\0';
		printf("LOG: cannot open log file %s: %s\n",filename,buffer);
		fflush(stdout);
	}
		
	return handle!=INVALID_HANDLE_VALUE;
}

int LOG::log(const char* fmt, ...)
{
	char buf[1024]="\0";
	DWORD written;
	
	int result= 0;
	va_list args;
	va_start(args,fmt);
	if(fmt)
		result= vsprintf(buf,fmt,args);
	else
	{
		result= 4;
		strcpy(buf,"LOG::log(null)\n");
	}
	buf[sizeof(buf)-1]= '\0';
//	printf(buf);
//	fflush(stdout);
	if(handle!=INVALID_HANDLE_VALUE)
	{
		DWORD size= strlen(buf);
		BOOL result= WriteFile(handle,buf,size,&written,NULL);
			if(written!=size)
				printf("log error: %d != %d\n",written,size);
		if(!result)
		{
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,0,GetLastError(),0,buf,sizeof(buf),0);
			printf(buf);
		}
		if(!FlushFileBuffers(handle))
		{
			FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,0,GetLastError(),0,buf,sizeof(buf),0);
			printf(buf);
		}
	}
	else
		printf("log failed: invalid file handle\n");
	va_end(args);

	return result;
}

int LOG::logbinary(VOID* addr, int size)
{
	BYTE* ptr= (BYTE*)addr;
	for(int y=0;y<size;y+=16)
	{
		log("\t");
		for(int x=0;x<16 && (x+y)<size;x++)
			log("%02X ",((int)ptr[y+x])&0xFF);
		log("\t");
// 2005-07-07  CDC  Allowing declarations in the start condition was a bad language design decision for C++.
		for(int x=0;x<16 && (x+y)<size;x++)
			if(isprint(ptr[y+x]))
				log("%c",ptr[y+x]);
			else
				log(".");
		log("\n");
	}
	
	return size;
}

void LOG::close(void)
{
	if(handle!=INVALID_HANDLE_VALUE)
		CloseHandle(handle);
	handle= INVALID_HANDLE_VALUE;
}
