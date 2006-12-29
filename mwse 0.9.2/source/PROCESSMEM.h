#ifndef _PROCESSMEM_H_DGHNSWTNYUMESTYNASFGTNDUGTM
#define _PROCESSMEM_H_DGHNSWTNYUMESTYNASFGTNDUGTM

#include "windows.h"
#include "ADDRESSSPACE.h"

struct PROCESSMEM : public ADDRESSSPACE
{
	PROCESSMEM(HANDLE process, LPVOID base, VMSIZE size);
	virtual bool Read(VPVOID addr, VOID* buf, VMSIZE size);
	virtual bool Write(VPVOID addr, VOID* buf, VMSIZE size);
	virtual VMSIZE size(void);
	virtual bool ReBase(LPVOID base);
private:
	HANDLE hProcess;
	LPVOID baseptr;
	VMSIZE memsize;
};

#endif
