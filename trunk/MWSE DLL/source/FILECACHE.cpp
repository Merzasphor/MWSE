//FileCache.cpp

#include "FILECACHE.h"
#include <stdio.h>
#include <ctype.h>

// 22-08-2006 Tp21
#include "warnings.h"

#ifndef NELEM
#define NELEM(a) (sizeof(a)/sizeof(a[0]))
#endif

FILESYS filesys;	// A common file system cache

bool FILECACHE::validfilename(const char* filename)
{
	// 2005-02-12  CDC  More secure and yet permissive names.
	// Allow _ and . in filenames but limit their length.
	// Files 4 characters and under might be special
	// like the CON, PRN, COM1, etc. DOS device files.
	// By forcing at least 5 characters, we don't have
	// to worry about someone opening the .. or . files.
	// 2005-07-01  CDC Allow for a named pipe (I'm not sure it's wise, but it's requested enough.)
	if ( *filename == '|' )
		filename++;
        int len = 0;
	while(*filename)
	{
		if (len++ >= 61) 
			return false;
		if(!isalnum(*filename) && *filename != '_' && *filename !='.')
			return false;
		filename++;
	}
	if (len < 5)
		return false;
	return true;
}

HANDLE FILECACHE::getfile(const char* filename)
{
	HANDLE result = 0;
	
	STRING str(filename);
	FILEMAP::iterator it = filemap.find(str);
	if(it != filemap.end())
	{
		FILESTATE& state = it->second;
		if((result = state.file) == INVALID_HANDLE_VALUE)
			result = state.file = openfileat(filename, state.position);
	}
	else
	{
		FILESTATE state = {openfileat(filename, 0), 0};
		filemap[str] = state;
		result = state.file;
	}
	
	return result;
}
	
FILECACHE::~FILECACHE(void)
{
	FILEMAP::iterator it = filemap.begin();
	while(it != filemap.end())
	{
		FILESTATE& state = it->second;
		if(state.file != INVALID_HANDLE_VALUE)
			CloseHandle(state.file);
		it++;
	}
}
	
HANDLE FILECACHE::openfileat(const char* filename, long position)
{
	if(!validfilename(filename)) return INVALID_HANDLE_VALUE;
	
	char realname[BUFSIZ] = "Data Files\\MWSE\\";
	// 2005-02-12  CDC Create the file storage area if it doesn't already exist
	CreateDirectory("Data Files\\MWSE", NULL);
	// 2005-07-01  CDC Allow connection to named pipes one the local machine
	if ( *filename == '|' ) 
	{
		strcpy(realname, "\\\\.\\pipe\\MWSE");
		filename++;
	}

	strncpy(&realname[strlen(realname)], filename,NELEM(realname)-strlen(realname));
	HANDLE result = CreateFile(
		 realname
		,GENERIC_READ|GENERIC_WRITE
		,FILE_SHARE_READ|FILE_SHARE_WRITE
		,NULL
		,OPEN_ALWAYS
		,FILE_ATTRIBUTE_NORMAL|FILE_FLAG_SEQUENTIAL_SCAN
		,NULL
		);
	if(result != INVALID_HANDLE_VALUE && SetFilePointer(result, position, 0, FILE_BEGIN) < 0)
	{
		CloseHandle(result);
		result = INVALID_HANDLE_VALUE;
	}
	
	return result;
}

FILECACHE FILESYS::cache;

int FILESYS::read(const char* filename, VOID* pdata, int size)
{
	int result = 0;
	HANDLE file = cache.getfile(filename);
	if(file != INVALID_HANDLE_VALUE)
	{
		//Tp21 2006-06-21: Stop MWSE getting stuck if there's no data available to be read (original code from timeslip)
		if( *filename == '|' ) { //check if it's an pipe
			DWORD toread;
			PeekNamedPipe(file, NULL, 0, NULL, &toread, NULL); //look if there is something to read
			if(!toread) return 0; //if not, return
		}

		DWORD red = 0;
		ReadFile(file, pdata, size, &red, 0);
		result = (int)red;
	}

	return result;
}

// 2005-06-28  CDC  Need to distinguish between reading an empty string and failed reads
// Now this function will return the number of bytes read, including the null!
// 2005-07-03  CDC  If bufsize is negative, allow read to stop at end of line (CR/LF)
int FILESYS::readcstring(const char* filename, char* string, int bufsize)
{
	HANDLE file = cache.getfile(filename);
	DWORD numread = 0;
	char *firstpos = string;
	bool eolcheck = (bufsize < 0);
	
	if ( file == INVALID_HANDLE_VALUE )
		return -1;
	
	if ( eolcheck ) 
		bufsize = -bufsize;
	
	while ( bufsize > 0 )
	{
		ReadFile(file,string,1,&numread,0);
		if ( numread == 0 )			// eof, count it as a null
			*string = 0;
		if ( *string == '\n' && eolcheck )	// LF in eol mode, count as a null
			*string = 0;
		if ( !*string )				// end of string found
			bufsize = 0;
		string++;
		bufsize--;
	}

	numread = string - firstpos;
	if ( eolcheck && (*(string-2) == '\r') )
	{
		*(string-2) = 0;
		string--;
	}
		
	return numread;
}

int FILESYS::write(const char* filename, const VOID* pdata, int size)
{
	int result = 0;
	HANDLE file = cache.getfile(filename);
	if(file != INVALID_HANDLE_VALUE)
	{
		DWORD red = 0;
		WriteFile(file, pdata, size, &red, 0);
		SetEndOfFile(file);
		result = (int)red;
	}

	return result;
}

bool FILESYS::seek(const char* filename, long absolute)
{
	bool result = false;
	HANDLE file = cache.getfile(filename);
	if(file != INVALID_HANDLE_VALUE)
		result = SetFilePointer(file, absolute, 0, FILE_BEGIN) >= 0;

	return result;
}
