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
	mwVariablesNode_t * localVariables = reinterpret_cast<mwVariablesNode_t*>(0x7CEBF8);
	if( index <= (getScript().numLongs) )
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
		return localVariables->longVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

mwLong_t VirtualMachine::getLongVariable(int index, REFRRecord_t &reference)
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