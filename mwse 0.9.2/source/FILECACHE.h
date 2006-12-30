//FileCache.h
#pragma once

#include <stdio.h>
#include <map>
#include <string>
#include <wtypes.h>

struct FILESTATE
{
	HANDLE file;
	long position;
};

typedef std::string STRING;
typedef std::map<STRING,FILESTATE> FILEMAP;

struct FILECACHE
{
	HANDLE getfile(const char* filename);
	virtual ~FILECACHE(void);
private:
	HANDLE openfileat(const char* filename, long position);
	bool validfilename(const char* filename);
	
	FILEMAP filemap;	
};

struct FILESYS
{
	virtual int read(const char* filename, VOID* pdata, int size);
	virtual int readcstring(const char* filename, char* string, int bufsize);
	virtual int write(const char* filename, const VOID* pdata, int size);
	virtual bool seek(const char* filename, long absolute);
private:
	static FILECACHE cache;
};

extern FILESYS filesys;		// A common file cache
