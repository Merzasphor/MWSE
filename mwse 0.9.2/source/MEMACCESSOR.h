#ifndef _MEMACCESSOR_H_RGYJNWRTBGHMEG
#define _MEMACCESSOR_H_RGYJNWRTBGHMEG

#include "VMTYPES.h"
#include "ADDRESSSPACE.h"

struct MEMACCESSOR
{
	virtual ~MEMACCESSOR(void){};
	virtual bool access(ADDRESSSPACE& mem,VPVOID reladdr,VOID* buf,VMSIZE size)=0;
};

#endif
