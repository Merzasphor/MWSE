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