#include "FUNCEXTENDER.h"
#include "TES3MEMMAP.h"

bool FUNCEXTENDER::CallOriginalFunction(TES3MACHINE& machine, OPCODE originalopcode)
{
	CONTEXT context= machine.GetFlow();
	context.Edx= originalopcode;
	context.Eip= (DWORD)machine.reltolinear(RUNFUNCOPCODETEST);
	machine.SetFlow(context);
	
	return true;
}
