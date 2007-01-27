//BufSpace.cpp

#include "BUFSPACE.h"

// 22-08-2006 Tp21
#include "warnings.h"

#define SUPER ADDRESSSSPACE

BUFSPACE::BUFSPACE(VMSIZE size) : memsize(size), mem(new BYTE[size])
{
	memset(mem, 0, size);
}

BUFSPACE::~BUFSPACE(void)
{
	delete []mem;
}

bool BUFSPACE::Read(VPVOID addr, VOID* buf, VMSIZE readsize)
{
	bool result = true;
	if((VMSIZE)addr + readsize <= size())
	{
		size_t len = min(readsize, size()-(VMSIZE)addr);
		memcpy(buf, &mem[(int)addr], len);
	}
	else
		result = false;
		
	return result;
}

bool BUFSPACE::Write(VPVOID addr, VOID* buf, VMSIZE writesize)
{
	bool result = true;
	if((VMSIZE)addr + writesize <= size())
	{
		size_t len = min(writesize, size()-(VMSIZE)addr);
		memcpy(&mem[(int)addr], buf, len);
	}
	else
		result = false;
		
	return result;
}

VMSIZE BUFSPACE::size(void)
{
	return memsize;
}
