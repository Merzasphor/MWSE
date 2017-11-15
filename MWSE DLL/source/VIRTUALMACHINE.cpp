//VirtualMachine.cpp

#include "VIRTUALMACHINE.h"
#include "MEMACCESSORS.h"
#include <algorithm>
using namespace std;
// 22-08-2006 Tp21
#include "warnings.h"

#include "cLog.h"

VIRTUALMACHINE::~VIRTUALMACHINE(void)
{
	{
		INSTRUCTIONMAP::iterator it= instructions.begin();
		INSTRUCTIONMAP::iterator lim= instructions.end();
		while(it!=lim)
		{
			INSTRUCTION* inst= it->second;
			delete inst;
			it++;
		}
	}
	{
		ADDRESSSPACEMAP::iterator it= memory.begin();
		ADDRESSSPACEMAP::iterator lim= memory.end();
		while(it!=lim)
		{
			ADDRESSSPACE* mem= it->second;
			delete mem;
			it++;
		}
	}
}

bool VIRTUALMACHINE::AddAddressSpace(VPVOID position, ADDRESSSPACE* space)
{
	bool result= true;
	if(space && space->size())
	{
		VMSIZE pos= (VMSIZE)position;
		LONGLONG newend= (LONGLONG)pos+space->size();
		ADDRESSSPACEMAP::iterator it= memory.begin();
		ADDRESSSPACEMAP::iterator lim= memory.end();
		while(result && it!=lim)
		{
			VMSIZE memstart= (VMSIZE)it->first;
			ADDRESSSPACE* mem= it->second;
			LONGLONG memend= (LONGLONG)memstart+mem->size();
			if((memstart<=pos && pos<memend)
				|| (memstart<newend && newend<=memend)
				|| (pos<=memstart && memend<=newend))
				result= false;
			it++;
		}
		if(result)
			memory[position]= space;
	}
	else
		result= false;
		
	return result;
}

bool VIRTUALMACHINE::AddInstruction(OPCODE opcode, INSTRUCTION* instruction) //to add an extended function to morrowind, so it can be used
{
	bool result= false;
	if(instruction)
	{
		if(instructions.find(opcode)==instructions.end())
		{
			instructions[opcode]= instruction;
			result= true;
        } else {
			cLog::mLogMessage("Possible duplicate opcode 0x%x\n", opcode);
        }
	}
	
	return result;			
}

//function to access memory to read or write to it
bool VIRTUALMACHINE::AccessMem(MEMACCESSOR& access, VPVOID addr, VOID* buf, VMSIZE size)
{
	bool result= true;
	VMSIZE start= (VMSIZE)addr;
	LONGLONG end= (LONGLONG)start+size;
	int loop= 0;
//	LOG::log("VIRTUALMACHINE::AccessMem(xxx,%lx,%lx)\n",addr,size);
	
	ADDRESSSPACEMAP::iterator it= memory.begin();
	ADDRESSSPACEMAP::iterator lim= memory.end();
	while(result && size>0 && it!=lim)
	{
//		LOG::log("VIRTUALMACHINE::AccessMem loop %d, size %lx\n",++loop,size);
		ADDRESSSPACE* mem= it->second;
		if(!mem)
		{
//			LOG::log("VIRTUALMACHINE::AccessMem: bad mem\n");
			result= false;
			continue;
		}
		VMSIZE memstart= (VMSIZE)it->first;
		VMSIZE memsize= mem->size();
		LONGLONG memend= (LONGLONG)memstart+memsize;
		if(memstart<=start && start<memend)
		{
			VMSIZE memoffset= start-memstart;
			VMSIZE memlen= min((VMSIZE)(memend-start),size);

			if(access.access(*mem,(VPVOID)memoffset,buf,memlen))
				size-= memlen;
			else
				result= false;
		}
		else if(memstart<end && end<=memend)
		{
			int bufoffset= memstart-start;
			VMSIZE memlen= end-memstart;
			VOID* bufpart= (VOID*)((BYTE*)buf+bufoffset);
			if(access.access(*mem,0,bufpart,memlen))
				size-= memlen;
			else
				result= false;
		}
		else if(start<=memstart && memend<=end)
		{
			int bufoffset= memstart-start;
			VOID* bufpart= (VOID*)((BYTE*)buf+bufoffset);
			if(access.access(*mem,0,bufpart,memsize))
				size-= memsize;
			else
				result= false;
		}
		++it;
	}
	if(size!=0)
		result= false;
			
	return result;
}

bool VIRTUALMACHINE::ReadMem(const VPVOID addr, VOID* buf, VMSIZE size) //function to read stuff from memory
{
	MEMREADER reader;
	return AccessMem(reader,const_cast<VPVOID>(addr),buf,size);
}

bool VIRTUALMACHINE::WriteMem(VPVOID addr, const VOID* buf, VMSIZE size) //function to write stuff to memory
{
	MEMWRITER writer;
	return AccessMem(writer,addr,const_cast<VOID*>(buf),size);
}

bool VIRTUALMACHINE::GetInstruction(VPVOID addr, OPCODE& opcode)
{
	return ReadMem(addr,&opcode,sizeof(opcode));
}

bool VIRTUALMACHINE::IsInstruction(OPCODE inst) //see if the given opcode is an extended instruction
{
	return 	instructions.find(inst)!=instructions.end();
}
bool VIRTUALMACHINE::step(bool skip)
{
	bool result= false;
	VMREGTYPE ip= 0;
	OPCODE opcode;
	
	if(GetRegister(IP,ip)
		&& GetInstruction((VPVOID)ip,opcode)
		&& opcode)
	{
		INSTRUCTIONMAP::iterator it= instructions.find(opcode);
		if(it!=instructions.end())
		{
			INSTRUCTION* inst= it->second;
			int operandlength= inst->GetOperands(opcode,(VPVOID)ip+sizeof(opcode));
			if(operandlength>=0)
			{
				ip+= sizeof(opcode)+operandlength;
				if(SetRegister(IP,(VMREGTYPE)ip))
				{
					result= skip || inst->execute();
				}
			}
		}
		else
		{
			BadOpcodeHandler(opcode,(VPVOID)ip);
		}
	}
	
	return result;
}

bool VIRTUALMACHINE::run(void)
{
	bool result= true;
	
	while(result)
		result= step();
	
	return result;
}


bool VIRTUALMACHINE::Interrupt(VMINTERRUPT intnum)
{
// 2005-07-07  CDC  It should return something.  False since it didn't do anything?
	return false;
}

bool VIRTUALMACHINE::push(VMREGTYPE val)
{
	bool result= false;
	VMREGTYPE sp= 0;
	if(GetRegister(SP,sp))
	{
		sp-= sizeof(VMREGTYPE);
		if(SetRegister(SP,sp))
		{
			SetFlags(val);
			result= WriteMem((VPVOID)sp,&val,sizeof(val));
		}
	}
	
	return result;
}

bool VIRTUALMACHINE::push(VMFLOAT val)
{
	bool result= false;
	VMREGTYPE sp= 0;
	if(GetRegister(SP,sp))
	{
		sp-= sizeof(VMREGTYPE);
		if(SetRegister(SP,sp))
		{
			SetFlags(val);
			result= WriteMem((VPVOID)sp,&val,sizeof(val));
		}
	}
	
	return result;
}

bool VIRTUALMACHINE::pop(VMREGTYPE& val)
{
	bool result= false;
	VMREGTYPE sp= 0;
	if(GetRegister(SP,sp))
	{
		if(SetRegister(SP,sp+sizeof(VMREGTYPE)))
			result= ReadMem((VPVOID)sp,&val,sizeof(val));
	}
	
	return result;
}

bool VIRTUALMACHINE::pop(VMFLOAT& val)
{
	bool result= false;
	VMREGTYPE sp= 0;
	if(GetRegister(SP,sp))
	{
		if(SetRegister(SP,sp+sizeof(VMREGTYPE)))
			result= ReadMem((VPVOID)sp,&val,sizeof(val));
	}
	
	return result;
}


void VIRTUALMACHINE::SetFlags(VMREGTYPE value)
{
	if(value)
	{
		if(value>0)
			flags= FPOS;
		else
			flags= 0;
	}
	else
		flags= FZERO|FPOS;
}

void VIRTUALMACHINE::SetFlags(VMFLOAT value)
{
	if(value)
	{
		if(value>0)
			flags= FPOS;
		else
			flags= 0;
	}
	else
		flags= FZERO|FPOS;
}

VMFLAGSTYPE VIRTUALMACHINE::GetFlags(void)
{
	return flags;
}

void VIRTUALMACHINE::BadOpcodeHandler(OPCODE opcode, VPVOID ip)
{
}

