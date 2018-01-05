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
#include "mwOffsets.h"
#include "Log.h"

using namespace mwse;

VirtualMachine::VirtualMachine()
: 
context()	//initialize context
{
	//TODO: add scriptIP in some way (maybe a pointer to the morrowinds' scriptIP?)
	//TODO: make it all working ;-)
	//TODO: implement VMExecuteInterface
	mwScriptIP = reinterpret_cast<long*>(TES3_IP_IMAGE);	//make mwScriptIP a pointer to morrowinds' script instruction pointer. it holds the current location in the script. when you read parameters from the script stream, you need to add the number of bytes read to this.
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
	// Disable clearing the string store for now, until we can make cleanup work like in 0.9.
	// mwseString_t::clearStore();
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

void * VirtualMachine::getTemplate(const char *id)
{
	size_t * secondobject_image_length = reinterpret_cast<size_t*>(TES3_SECONDOBJECT_LENGTH_IMAGE);
	*secondobject_image_length = strlen(id);

	char * secondobject_image = reinterpret_cast<char*>(TES3_SECONDOBJECT_IMAGE);
	strcpy(secondobject_image, id);

	long returnreference;

	static int fixupTemplateFunction = TES3_FUNC_FIXUP_TEMPLATE;
	_asm
	{
		mov edx, TES3_MASTER_IMAGE;
		mov ecx, [edx];
		push TES3_SECONDOBJECT_IMAGE;
		call fixupTemplateFunction;
		mov returnreference, eax;
	}

	void * reference = reinterpret_cast<void*>(returnreference);
	return reference;
}

REFRRecord_t * VirtualMachine::getReference()
{
	return *reinterpret_cast<REFRRecord_t**>(TES3_SCRIPTTARGETREF_IMAGE);
}

REFRRecord_t * VirtualMachine::getReference(const char *id)
{
	size_t * secondobject_image_length = reinterpret_cast<size_t*>(TES3_SECONDOBJECT_LENGTH_IMAGE);
	*secondobject_image_length = strlen(id);

	char * secondobject_image = reinterpret_cast<char*>(TES3_SECONDOBJECT_IMAGE);
	strcpy(secondobject_image, id);

	long returnreference;

	bool isplayer= !_stricmp(id,"player") || !_stricmp(id,"playersavegame");
	if(isplayer)
	{
		//fixupplayer
		static int getMACP = TES3_FUNC_GET_MACP;
		_asm
		{
			mov ecx,dword ptr ds:[TES3_MASTER_IMAGE];
			call getMACP;
			mov edx, [eax+0x14];
			mov returnreference, edx;
		}
	}
	else
	{
		static int fixupInstanceFunction = TES3_FUNC_FIXUP_INSTANCE;
		//fixupinstance
		_asm
		{
			mov ecx, dword ptr ds:[TES3_MASTERCELL_IMAGE];
			mov ecx, [ecx];
			push TES3_SECONDOBJECT_IMAGE;
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

	mwOpcode_t * currentOpcode = reinterpret_cast<mwOpcode_t*>(TES3_OP_IMAGE);
	*currentOpcode = opcode;

	REFRRecord_t ** currentReference = reinterpret_cast<REFRRecord_t**>(TES3_SCRIPTTARGETREF_IMAGE);
	*currentReference = reference;

	void ** currentTemplate = reinterpret_cast<void**>(TES3_SCRIPTTARGETTEMPL_IMAGE);
	*currentTemplate = reference->recordPointer;

	unsigned char * currentInref = reinterpret_cast<unsigned char*>(context.ebp + 0x23);	//inref apparently
	*currentInref = inref;

	//this should be it. a lot of testing is needed of course ;)
}

REFRRecord_t * VirtualMachine::getCurrentTarget()
{
	TES3ViewMaster_t * viewmaster = *(reinterpret_cast<TES3ViewMaster_t**>(TES3_MASTER2_IMAGE));
	return viewmaster->target;
}

mwLong_t VirtualMachine::getLongVariable(int index)
{
	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( index < (getScript().numLongs) )	//maybe this should be '<' not '<=' ???
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

	static int findScriptVariable = TES3_FUNC_FIND_SCRIPT_VARIABLE;

	SCPTRecord_t* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( *indexPtr < (getScript().numLongs) )
		return localVariables->longVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

mwLong_t VirtualMachine::getLongVariable(int index, REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t<BaseRecord_t> * pnode = reference.attachments;
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
		mwVarHolderNode_t* varholder = reinterpret_cast<mwVarHolderNode_t*>(pnode->dataPtr);
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(varholder->vars);
		return foreignVariables->longVarValues[index];
	}
	//else throw error
}

void VirtualMachine::setLongVariable(int index, mwse::mwLong_t value)
{
	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( index < (getScript().numLongs) )
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

	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( *indexPtr < (getScript().numLongs) )
		localVariables->longVarValues[*indexPtr] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setLongVariable(int index, mwse::mwLong_t value, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t<BaseRecord_t> * pnode = reference.attachments;
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
		mwVarHolderNode_t* varholder = reinterpret_cast<mwVarHolderNode_t*>(pnode->dataPtr);
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(varholder->vars);
		foreignVariables->longVarValues[index] = value;
	}
	//else throw error
}

mwShort_t VirtualMachine::getShortVariable(int index)
{
	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( index < (getScript().numShorts) )
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

	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( *indexPtr < (getScript().numShorts) )
		return localVariables->shortVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

mwShort_t VirtualMachine::getShortVariable(int index, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t<BaseRecord_t> * pnode = reference.attachments;
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
		mwVarHolderNode_t* varholder = reinterpret_cast<mwVarHolderNode_t*>(pnode->dataPtr);
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(varholder->vars);
		return foreignVariables->shortVarValues[index];
	}
	//else throw error
}

void VirtualMachine::setShortVariable(int index, mwse::mwShort_t value)
{
	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( index < (getScript().numShorts) )
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

	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( *indexPtr < (getScript().numShorts) )
		localVariables->shortVarValues[*indexPtr] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setShortVariable(int index, mwse::mwShort_t value, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t<BaseRecord_t> * pnode = reference.attachments;
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
		mwVarHolderNode_t* varholder = reinterpret_cast<mwVarHolderNode_t*>(pnode->dataPtr);
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(varholder->vars);
		foreignVariables->shortVarValues[index] = value;
	}
	//else throw error
}

mwFloat_t VirtualMachine::getFloatVariable(int index)
{
	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( index < (getScript().numFloats) )
		return localVariables->floatVarValues[index];
	//else error, the index is bigger than the number of variables
}

mwFloat_t VirtualMachine::getFloatVariable(const char *id)
{
	long * indexPtr;

	static int findScriptVariable = TES3_FUNC_FIND_SCRIPT_VARIABLE;
	SCPTRecord_t* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( *indexPtr < (getScript().numFloats) )
		return localVariables->floatVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

mwFloat_t VirtualMachine::getFloatVariable(int index, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t<BaseRecord_t> * pnode = reference.attachments;
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
		mwVarHolderNode_t* varholder = reinterpret_cast<mwVarHolderNode_t*>(pnode->dataPtr);
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(varholder->vars);
		return foreignVariables->floatVarValues[index];
	}
	//else throw error
}

void VirtualMachine::setFloatVariable(int index, mwse::mwFloat_t value)
{
	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( index < (getScript().numFloats) )
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

	mwVariablesNode_t * localVariables = *(reinterpret_cast<mwVariablesNode_t**>(TES3_LOCALVARIABLES_IMAGE));
	if( *indexPtr < (getScript().numFloats) )
		localVariables->floatVarValues[*indexPtr] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setFloatVariable(int index, mwse::mwFloat_t value, mwse::REFRRecord_t &reference)
{
	bool found = false;
	ListNode_t<BaseRecord_t> * pnode = reference.attachments;
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
		mwVarHolderNode_t* varholder = reinterpret_cast<mwVarHolderNode_t*>(pnode->dataPtr);
		mwVariablesNode_t* foreignVariables = reinterpret_cast<mwVariablesNode_t*>(varholder->vars);
		foreignVariables->floatVarValues[index] = value;
	}
	//else throw error
}

mwLong_t VirtualMachine::getLongGlobal(const char *id)
{
	/*
	masterCellImage = TES3_MASTERCELL_IMAGE
findGLOB = TES3_FUNC_FIND_GLOBAL

mov eax, masterCellImage
mov ecx, [eax]
push "char * globalToFind"
call findGLOB
return = EAX = GLOBRecord
*/

	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[TES3_MASTERCELL_IMAGE]; //masterCellImage
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
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[TES3_MASTERCELL_IMAGE];
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
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[TES3_MASTERCELL_IMAGE];
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
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[TES3_MASTERCELL_IMAGE];
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
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[TES3_MASTERCELL_IMAGE];
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
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	GLOBRecord_t * foundRecord;
	__asm
	{
		mov ecx,dword ptr ds:[TES3_MASTERCELL_IMAGE];
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
	int * scriptIP = reinterpret_cast<int*>(TES3_IP_IMAGE);

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
	int * scriptIP = reinterpret_cast<int*>(TES3_IP_IMAGE);

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
	int * scriptIP = reinterpret_cast<int*>(TES3_IP_IMAGE);

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
	int * scriptIP = reinterpret_cast<int*>(TES3_IP_IMAGE);

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
	if(fromStack == 0x0)
	{
		return mwseString_t();
	}

	if(mwseString_t::exists(fromStack))
	{
		//if it's a variable string
		return mwseString_t::lookup(fromStack);
	}
	else if (fromStack < 32767)
	{
		//if it's a litteral string
		void * scriptstream = getScript().machineCode;
		scriptstream = reinterpret_cast<void*>( reinterpret_cast<char*>(scriptstream) + fromStack);	//go to address in script stream

		char blen = *(reinterpret_cast<char*>(scriptstream));	//get length i guess...

		long strlen = static_cast<long>(blen);

		scriptstream = reinterpret_cast<void*>( reinterpret_cast<char*>(scriptstream) + sizeof(blen) );
		
		char * string = reinterpret_cast<char*>(scriptstream);

		return mwseString_t(string, strlen);
	}
	else
	{
		const char* string = reinterpret_cast<char*>(fromStack);
		return mwseString_t(string);
	}
}

void VirtualMachine::dumpScriptVariables()
{
	if (!script) {
		mwse::log::getLog() << __FUNCTION__ << " - No script found." << std::endl;
		return;
	}

	mwse::log::getLog() << __FUNCTION__ << " - Variable dump for '" << script->scriptName << "'" << std::endl;

	mwse::log::getLog() << "  Longs (" << script->numLongs << "):" << std::endl;
	for (int i = 0; i < script->numLongs; i++) {
		mwse::log::getLog() << "    " << script->longVarNamePointers[i] << " = " << std::dec << script->longVarValues[i] << std::endl;
	}

	mwse::log::getLog() << "  Floats (" << script->numFloats << "):" << std::endl;
	for (int i = 0; i < script->numFloats; i++) {
		mwse::log::getLog() << "    " << script->floatVarNamePointers[i] << " = " << std::dec << script->floatVarValues[i] << std::endl;
	}

	mwse::log::getLog() << "  Shorts (" << script->numShorts << "):" << std::endl;
	for (int i = 0; i < script->numShorts; i++) {
		mwse::log::getLog() << "    " << script->shortVarNamePointers[i] << " = " << std::dec << script->shortVarValues[i] << std::endl;
	}
}

long* VirtualMachine::getScriptIP()
{
	return mwScriptIP;
}