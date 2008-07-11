/************************************************************************
               mwseString.cpp - Copyright (c) 2008 The MWSE Project
                http://www.sourceforge.net/projects/mwse

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#include "VirtualMachine.h"
#include "InstructionStore.h"
#include "InstructionInterface.h"
#include "mwseString.h"

using namespace mwse;

VirtualMachine::VirtualMachine()
: 
context()	//initialize context
{
	//TODO: add scriptIP in some way (maybe a pointer to the morrowinds' scriptIP?)
	//TODO: make it all working ;-)
	//TODO: implement VMExecuteInterface
	mwScriptIP = reinterpret_cast<long*>(0x7CEBB0);	//make mwScriptIP a pointer to morrowinds' script instruction pointer. it holds the current location in the script. when you read parameters from the script stream, you need to add the number of bytes read to this.
}

void VirtualMachine::loadParametersForOperation(mwOpcode_t opcode, mwAdapter::Context_t &context, SCPTRecord_t &script)
{
	InstructionInterface_t * instruction = InstructionStore::getInstance().get(opcode);
	setContext(context);
	setScript(script);
	if(oldscript != NULL && oldscript != &script)	//first time don't execute (when oldscript is empty)
		OnScriptChange();
	oldscript = &script;

	instruction->loadParameters(*this);	//what else does 'loadParameters' need?

	context = getContext();		//because the context parameter is a reference, and set/getContext isn't we have to read the context again, (maybe it's changed)
}

float VirtualMachine::executeOperation(mwOpcode_t opcode, mwAdapter::Context_t &context, SCPTRecord_t &script)
{
	InstructionInterface_t * instruction = InstructionStore::getInstance().get(opcode);
	setContext(context);
	setScript(script);

	float returnvalue = instruction->execute(*this);	//what else does 'execute' need?
	
	context = getContext();
	return returnvalue;
}

void VirtualMachine::OnScriptChange()
{
	mwseString_t::clearStore();
}

bool VirtualMachine::isOpcode(const mwOpcode_t opcode)
{
	return InstructionStore::getInstance().isOpcode(opcode);
}

void VirtualMachine::setContext(mwAdapter::Context_t context)
{
	this->context = context;
}

mwAdapter::Context_t VirtualMachine::getContext()
{
	return this->context;
}

void VirtualMachine::setScript(mwse::SCPTRecord_t &script)
{
	this->script = &script;
}

SCPTRecord_t& VirtualMachine::getScript()
{
	return *this->script;
}

REFRRecord_t * VirtualMachine::getReference()
{
	REFRRecord_t ** currentreference = reinterpret_cast<REFRRecord_t**>(0x7CEBEC);	//0x7CEBEC == ScriptRunner::Reference
	return *currentreference;
}

REFRRecord_t * VirtualMachine::getReference(const char *id)
{
	size_t strLength = strlen(id);

	size_t ** secondobject_image_length = reinterpret_cast<size_t**>(0x7CEBB8);	//0x7CEBB8 = SECONDOBJECT_IMAGE_LENGTH
	*secondobject_image_length = &strLength;

	const char ** secondobject_image = reinterpret_cast<const char**>(0x7CE6F8);		//0x7CE6F8 = ScriptRunner::ItemTemplate;
	*secondobject_image = id;

	long returnreference;

	bool isplayer= !_stricmp(id,"player") || !_stricmp(id,"playersavegame");
	if(isplayer)
	{
		//fixupplayer
		static int getMACP = 0x40ff20;
		_asm
		{
			mov ecx,dword ptr ds:[0x7c67dc]; //masterImage
			call getMACP;
			mov edx, [eax+0x14];
			mov returnreference, edx;
		}
	}
	else
	{
		static int fixupInstanceFunction = 0x4B8F50;
		//fixupinstance
		_asm
		{
			mov ecx, dword ptr ds:[0x7c67e0];	//masterCellImage
			mov ecx, [ecx];
			push 0x7CE6F8;					//'id' aka ScriptRunner::ItemTemplate
			call fixupInstanceFunction;
			mov returnreference, eax;
		}
	}

	REFRRecord_t * reference = reinterpret_cast<REFRRecord_t*>(returnreference);
	return reference;
}

void VirtualMachine::setReference(REFRRecord_t *reference)
{
	mwOpcode_t opcode = 0x010C;	//'->'
	unsigned char inref = 1;
	mwAdapter::Context_t context = getContext();

	mwOpcode_t * currentOpcode = reinterpret_cast<mwOpcode_t*>(0x7A91C4);	//ScriptRunner::Opcode
	*currentOpcode = opcode;

	REFRRecord_t ** currentReference = reinterpret_cast<REFRRecord_t**>(0x7CEBEC);	//ScriptRunner::Reference
	*currentReference = reference;

	void ** currentTemplate = reinterpret_cast<void**>(0x7CEBF4);	//ScriptRunner::Template
	*currentTemplate = reference->recordPointer;

	unsigned char * currentInref = reinterpret_cast<unsigned char*>(context.ebp + 0x23);	//inref apparently
	*currentInref = inref;

	//this should be it. a lot of testing is needed of course ;)
}

mwLong_t VirtualMachine::getLongVariable(int index)
{
	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);	//get a pointer to the localVariables, it contains 3 arrays, (see data structure)
	if( index <= (getScript().numLongs) )	//maybe this should be '<' not '<=' ???
		return localVariables->longVarValues[index];
	//else error, the index is bigger than the number of variables
}

mwLong_t VirtualMachine::getLongVariable(const char *id)
{
	/*
	
findScriptVariablePosition = 0x50E7B0
int * valuePtr
char * variableName

mov ecx, SCPTRecord_t * script
push "int * index"
push "char * variableToFind"
call findScriptVariablePosition
return = EAX = type of variable
index will be filled with index of variable
*/

	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;		//address of a native morrowind function,
													//that gives the index of a given variable name
	SCPTRecord_t* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( *indexPtr <= (getScript().numLongs) )
		return localVariables->longVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

mwLong_t VirtualMachine::getLongVariable(int index, REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t * pnode = reference.attachments;
	//search in attachments for the 'VARNODE' attachment. it contains the variableslist.
	while(pnode && !found)	//make while fail when @ end of nodelist!
	{
		if(pnode->attachType == RecordTypes::attachType_t::VARNODE)
		{
			found = true;
		}
		else
		{
			pnode = pnode->nextNode;
		}
	}
	if(found)
	{
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(pnode->dataPtr);
		return foreignVariables->longVarValues[index];
	}
	//else throw error
}

void VirtualMachine::setLongVariable(int index, mwse::mwLong_t value)
{
	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( index <= (getScript().numLongs) )
		localVariables->longVarValues[index] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setLongVariable(const char *id, mwse::mwLong_t value)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	SCPTRecord_t* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( *indexPtr <= (getScript().numLongs) )
		localVariables->longVarValues[*indexPtr] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setLongVariable(int index, mwse::mwLong_t value, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t * pnode = reference.attachments;
	while(pnode && !found)	//make while fail when @ end of nodelist!
	{
		if(pnode->attachType == RecordTypes::attachType_t::VARNODE)
		{
			found = true;
		}
		else
		{
			pnode = pnode->nextNode;
		}
	}
	if(found)
	{
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(pnode->dataPtr);
		foreignVariables->longVarValues[index] = value;
	}
	//else throw error
}

mwShort_t VirtualMachine::getShortVariable(int index)
{
	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( index <= (getScript().numShorts) )
		return localVariables->shortVarValues[index];
	//else error, the index is bigger than the number of variables
}

mwShort_t VirtualMachine::getShortVariable(const char *id)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	SCPTRecord_t* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( *indexPtr <= (getScript().numShorts) )
		return localVariables->shortVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

mwShort_t VirtualMachine::getShortVariable(int index, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t * pnode = reference.attachments;
	while(pnode && !found)	//make while fail when @ end of nodelist!
	{
		if(pnode->attachType == RecordTypes::attachType_t::VARNODE)
		{
			found = true;
		}
		else
		{
			pnode = pnode->nextNode;
		}
	}
	if(found)
	{
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(pnode->dataPtr);
		return foreignVariables->shortVarValues[index];
	}
	//else throw error
}

void VirtualMachine::setShortVariable(int index, mwse::mwShort_t value)
{
	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( index <= (getScript().numShorts) )
		localVariables->shortVarValues[index] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setShortVariable(const char *id, mwse::mwShort_t value)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	SCPTRecord_t* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( *indexPtr <= (getScript().numShorts) )
		localVariables->shortVarValues[*indexPtr] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setShortVariable(int index, mwse::mwShort_t value, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t * pnode = reference.attachments;
	while(pnode && !found)	//make while fail when @ end of nodelist!
	{
		if(pnode->attachType == RecordTypes::attachType_t::VARNODE)
		{
			found = true;
		}
		else
		{
			pnode = pnode->nextNode;
		}
	}
	if(found)
	{
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(pnode->dataPtr);
		foreignVariables->shortVarValues[index] = value;
	}
	//else throw error
}

mwFloat_t VirtualMachine::getFloatVariable(int index)
{
	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( index <= (getScript().numFloats) )
		return localVariables->floatVarValues[index];
	//else error, the index is bigger than the number of variables
}

mwFloat_t VirtualMachine::getFloatVariable(const char *id)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	SCPTRecord_t* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( *indexPtr <= (getScript().numFloats) )
		return localVariables->floatVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

mwFloat_t VirtualMachine::getFloatVariable(int index, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t * pnode = reference.attachments;
	while(pnode && !found)	//make while fail when @ end of nodelist!
	{
		if(pnode->attachType == RecordTypes::attachType_t::VARNODE)
		{
			found = true;
		}
		else
		{
			pnode = pnode->nextNode;
		}
	}
	if(found)
	{
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(pnode->dataPtr);
		return foreignVariables->floatVarValues[index];
	}
	//else throw error
}

void VirtualMachine::setFloatVariable(int index, mwse::mwFloat_t value)
{
	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( index <= (getScript().numFloats) )
		localVariables->floatVarValues[index] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setFloatVariable(const char *id, mwse::mwFloat_t value)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	SCPTRecord_t* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( *indexPtr <= (getScript().numFloats) )
		localVariables->floatVarValues[*indexPtr] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setFloatVariable(int index, mwse::mwFloat_t value, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t * pnode = reference.attachments;
	while(pnode && !found)	//make while fail when @ end of nodelist!
	{
		if(pnode->attachType == RecordTypes::attachType_t::VARNODE)
		{
			found = true;
		}
		else
		{
			pnode = pnode->nextNode;
		}
	}
	if(found)
	{
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(pnode->dataPtr);
		foreignVariables->floatVarValues[index] = value;
	}
	//else throw error
}

mwLong_t VirtualMachine::getLongGlobal(const char *id)
{
	/*
	masterCellImage = 0x7C67E0
findGLOB = 0x4BA820

mov eax, masterCellImage
mov ecx, [eax]
push "char * globalToFind"
call findGLOB
return = EAX = GLOBRecord
*/

	static int findGLOB = 0x4BA820;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[0x7C67E0]; //masterCellImage
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if(foundRecord->variableType == 'l')
	{
		return static_cast<mwLong_t>(foundRecord->data);
	}
	//else error out!
}

void VirtualMachine::setLongGlobal(const char *id, mwLong_t value)
{
	static int findGLOB = 0x4BA820;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[0x7C67E0]; //masterCellImage
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if(foundRecord->variableType == 'l')
	{
		foundRecord->data = static_cast<mwFloat_t>(value);
	}
	//else error out!
}

mwShort_t VirtualMachine::getShortGlobal(const char *id)
{
	static int findGLOB = 0x4BA820;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[0x7C67E0]; //masterCellImage
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if(foundRecord->variableType == 's')
	{
		return static_cast<mwShort_t>(foundRecord->data);
	}
	//else error out!
}

void VirtualMachine::setShortGlobal(const char *id, mwShort_t value)
{
	static int findGLOB = 0x4BA820;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[0x7C67E0]; //masterCellImage
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if(foundRecord->variableType == 's')
	{
		foundRecord->data = static_cast<mwFloat_t>(value);
	}
	//else error out!
}

mwFloat_t VirtualMachine::getFloatGlobal(const char *id)
{
	static int findGLOB = 0x4BA820;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[0x7C67E0]; //masterCellImage
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if(foundRecord->variableType == 'f')
	{
		return foundRecord->data;
	}
	//else error out!
}

void VirtualMachine::setFloatGlobal(const char *id, mwFloat_t value)
{
	static int findGLOB = 0x4BA820;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[0x7C67E0]; //masterCellImage
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if(foundRecord->variableType == 'f')
	{
		foundRecord->data = value;
	}
	//else error out!
}

char VirtualMachine::getByteValue(bool peek)
{
	int * scriptIP = reinterpret_cast<int*>(0x7CEBB0);		//location the script instruction pointer, or current location in script stream

	SCPTRecord_t script = getScript();			//get current script
	void * scriptstream = script.machineCode;	//get script data stream
	scriptstream = reinterpret_cast<void*>( reinterpret_cast<char*>(scriptstream) + *scriptIP);	//go to current position in script stream

	char returnData = *(reinterpret_cast<char*>(scriptstream));	//<-- change char here! (twice)

	if(!peek)
	{
		*scriptIP += sizeof(char);	//<-- change char here
	}

	return returnData;
}

mwShort_t VirtualMachine::getShortValue(bool peek)
{
	int * scriptIP = reinterpret_cast<int*>(0x7CEBB0);

	SCPTRecord_t script = getScript();
	void * scriptstream = script.machineCode;
	scriptstream = reinterpret_cast<void*>( reinterpret_cast<char*>(scriptstream) + *scriptIP);

	mwShort_t returnData = *(reinterpret_cast<mwShort_t*>(scriptstream));	//<-- change char here! (twice)

	if(!peek)
	{
		*scriptIP += sizeof(mwShort_t);	//<-- change char here
	}

	return returnData;
}

mwLong_t VirtualMachine::getLongValue(bool peek)
{
	int * scriptIP = reinterpret_cast<int*>(0x7CEBB0);

	SCPTRecord_t script = getScript();
	void * scriptstream = script.machineCode;
	scriptstream = reinterpret_cast<void*>( reinterpret_cast<char*>(scriptstream) + *scriptIP);

	mwLong_t returnData = *(reinterpret_cast<mwLong_t*>(scriptstream));	//<-- change char here! (twice)

	if(!peek)
	{
		*scriptIP += sizeof(mwLong_t);	//<-- change char here
	}

	return returnData;
}

mwFloat_t VirtualMachine::getFloatValue(bool peek)
{
	int * scriptIP = reinterpret_cast<int*>(0x7CEBB0);

	SCPTRecord_t script = getScript();
	void * scriptstream = script.machineCode;
	scriptstream = reinterpret_cast<void*>( reinterpret_cast<char*>(scriptstream) + *scriptIP);

	mwFloat_t returnData = *(reinterpret_cast<mwFloat_t*>(scriptstream));	//<-- change char here! (twice)

	if(!peek)
	{
		*scriptIP += sizeof(mwFloat_t);	//<-- change char here
	}

	return returnData;
}

mwseString_t VirtualMachine::getString(mwLong_t fromStack)	//ask grant, need a '*' or a '&' here?? (and in the header files)
{
	if(mwseString_t::exists(fromStack))
	{
		//if it's a variable string
		return mwseString_t::lookup(fromStack);
	}
	else
	{
		//if it's a litteral string
		void * scriptstream = getScript().machineCode;
		scriptstream = reinterpret_cast<void*>( reinterpret_cast<char*>(scriptstream) + fromStack);	//go to address in script stream

		char blen = *(reinterpret_cast<char*>(scriptstream));	//get length i guess...

		scriptstream = reinterpret_cast<void*>( reinterpret_cast<char*>(scriptstream) + sizeof(blen) );
		
		char * string = reinterpret_cast<char*>(scriptstream);

		return mwseString_t(string, blen);
	}
}

long* VirtualMachine::getScriptIP()
{
	return mwScriptIP;
}