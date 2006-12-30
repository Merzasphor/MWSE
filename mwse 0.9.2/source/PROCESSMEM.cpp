//ProcessMem.cpp

#include "PROCESSMEM.h"
// 22-08-2006 Tp21
#include "warnings.h"

PROCESSMEM::PROCESSMEM(HANDLE process, LPVOID base, VMSIZE size)
:	hProcess(process), baseptr(base), memsize(size)
{
}

bool PROCESSMEM::Read(VPVOID addr, VOID* buf, VMSIZE size)
{
	return ReadProcessMemory(hProcess,(VPVOID)((VMSIZE)addr+(VMSIZE)baseptr),buf,size,NULL);
}

bool PROCESSMEM::Write(VPVOID addr, VOID* buf, VMSIZE size)
{
	return WriteProcessMemory(hProcess,(VPVOID)((VMSIZE)addr+(VMSIZE)baseptr),buf,size,NULL);
}

VMSIZE PROCESSMEM::size(void)
{
	return memsize;
}

bool PROCESSMEM::ReBase(LPVOID base)
{
	baseptr= base;
	
	return true;
}

