#ifndef _MEMACCESSORS_H_NEGTNFGBDFVNSFGN
#define _MEMACCESSORS_H_NEGTNFGBDFVNSFGN

#include "MEMACCESSOR.h"

struct MEMREADER : public MEMACCESSOR
{
	virtual bool access(ADDRESSSPACE& mem,VPVOID reladdr,VOID* buf,VMSIZE size)
	{
		return mem.Read(reladdr,buf,size);
	}
};

struct MEMWRITER : public MEMACCESSOR
{
	virtual bool access(ADDRESSSPACE& mem,VPVOID reladdr,VOID* buf,VMSIZE size)
	{
		return mem.Write(reladdr,buf,size);
	}
};

#endif
