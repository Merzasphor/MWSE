/************************************************************************

	mwseString.cpp - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

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
#include "TES3Util.h"
#include "StringUtil.h"
#include "Stack.h"

#include "TES3DataHandler.h"
#include "TES3GlobalVariable.h"
#include "TES3Game.h"

using namespace mwse;

VirtualMachine::VirtualMachine()
	: context(),
	oldscript(NULL)
{
	// Holds the current location in the script. when you read parameters from the script stream, you need to add the number of bytes read to this.
	mwScriptIP = reinterpret_cast<long*>(TES3_IP_IMAGE);
}

void VirtualMachine::loadParametersForOperation(OpCode::OpCode_t opcode, RegistryContext &context, TES3::Script* script)
{
	InstructionInterface_t * instruction = InstructionStore::getInstance().get(opcode);

	setRegistryContext(context);
	setScript(script);

	// Call OnScriptChange if we're running a different script.
	if (oldscript != NULL && oldscript != script) {
		OnScriptChange();
	}
	oldscript = script;

	instruction->loadParameters(*this);

	// Feed up any changes to the context to the hook.
	context = getRegistryContext();
}

float VirtualMachine::executeOperation(OpCode::OpCode_t opcode, RegistryContext &context, TES3::Script* script)
{
	InstructionInterface_t * instruction = InstructionStore::getInstance().get(opcode);

	setRegistryContext(context);
	setScript(script);

	float returnvalue = instruction->execute(*this);	//what else does 'execute' need?

	context = getRegistryContext();

	return returnvalue;
}

void VirtualMachine::OnScriptChange()
{
	// When a script changes, we can clear our stack.
	mwse::Stack::getInstance().clear();
}

bool VirtualMachine::isOpcode(const OpCode::OpCode_t opcode)
{
	return InstructionStore::getInstance().isOpcode(opcode);
}

void VirtualMachine::setRegistryContext(RegistryContext context)
{
	this->context = context;
}

RegistryContext VirtualMachine::getRegistryContext()
{
	return this->context;
}

void VirtualMachine::setScript(TES3::Script* script)
{
	this->script = script;
}

TES3::Script& VirtualMachine::getScript()
{
	return *this->script;
}

TES3::BaseObject * VirtualMachine::getTemplate(const char *id)
{
	TES3::RecordLists* recordLists = tes3::getDataHandler()->recordLists;

	TES3::BaseObject * foundTemplate = NULL;

	static int fixupTemplateFunction = TES3_FUNC_FIXUP_TEMPLATE;
	_asm
	{
		mov ecx, recordLists;
		push id;
		call fixupTemplateFunction;
		mov foundTemplate, eax;
	}

	return foundTemplate;
}

TES3::Reference * VirtualMachine::getReference()
{
	return *reinterpret_cast<TES3::Reference**>(TES3_SCRIPTTARGETREF_IMAGE);
}

TES3::Reference * VirtualMachine::getReference(const char *id)
{
	size_t * secondobject_image_length = reinterpret_cast<size_t*>(TES3_SECONDOBJECT_LENGTH_IMAGE);
	*secondobject_image_length = strlen(id);

	char * secondobject_image = reinterpret_cast<char*>(TES3_SECONDOBJECT_IMAGE);
	strcpy(secondobject_image, id);

	long returnreference;

	bool isplayer = !_stricmp(id, "player") || !_stricmp(id, "playersavegame");
	if (isplayer)
	{
		//fixupplayer
		static int getMACP = TES3_FUNC_GET_MACP;
		_asm
		{
			mov ecx, dword ptr ds : [TES3_WORLD_CONTROLLER_IMAGE];
			call getMACP;
			mov edx, [eax + 0x14];
			mov returnreference, edx;
		}
	}
	else
	{
		static int fixupInstanceFunction = TES3_FUNC_FIXUP_INSTANCE;
		//fixupinstance
		_asm
		{
			mov ecx, dword ptr ds : [TES3_DATA_HANDLER_IMAGE];
			mov ecx, [ecx];
			push TES3_SECONDOBJECT_IMAGE;
			call fixupInstanceFunction;
			mov returnreference, eax;
		}
	}

	TES3::Reference * reference = reinterpret_cast<TES3::Reference*>(returnreference);
	return reference;
}

void VirtualMachine::setReference(TES3::Reference *reference)
{
	if (reference == NULL || reference->baseObject == NULL) {
#if _DEBUG
		mwse::log::getLog() << __FUNCTION__ << ": Attempted to set to invalid reference." << std::endl;
#endif
		return;
	}

	OpCode::OpCode_t opcode = OpCode::_SetReference;	//'->'
	unsigned char inref = 1;
	RegistryContext context = getRegistryContext();

	OpCode::OpCode_t * currentOpcode = reinterpret_cast<OpCode::OpCode_t*>(TES3_OP_IMAGE);
	*currentOpcode = opcode;

	TES3::Reference ** currentReference = reinterpret_cast<TES3::Reference**>(TES3_SCRIPTTARGETREF_IMAGE);
	*currentReference = reference;

	void ** currentTemplate = reinterpret_cast<void**>(TES3_SCRIPTTARGETTEMPL_IMAGE);
	*currentTemplate = reference->baseObject;

	unsigned char * currentInref = reinterpret_cast<unsigned char*>(context.ebp + 0x23);	//inref apparently
	*currentInref = inref;

	//this should be it. a lot of testing is needed of course ;)
}

TES3::Reference * VirtualMachine::getCurrentTarget()
{
	return tes3::getGame()->playerTarget;
}

long VirtualMachine::getLongVariable(int index)
{
	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (index < (getScript().longCount))	//maybe this should be '<' not '<=' ???
		return localVariables->longVarValues[index];
	//else error, the index is bigger than the number of variables
}

long VirtualMachine::getLongVariable(const char *id)
{
	/*

findScriptVariablePosition = 0x50E7B0
int * valuePtr
char * variableName

mov ecx, TES3::Script * script
push "int * index"
push "char * variableToFind"
call findScriptVariablePosition
return = EAX = type of variable
index will be filled with index of variable
*/

	long * indexPtr;

	static int findScriptVariable = TES3_FUNC_FIND_SCRIPT_VARIABLE;

	TES3::Script* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (*indexPtr < (getScript().longCount))
		return localVariables->longVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

long VirtualMachine::getLongVariable(int index, TES3::Reference& reference)
{
	auto attachment = tes3::getAttachedItemDataNode(&reference);
	if (attachment) {
		return attachment->scriptData->longVarValues[index];
	}

	return 0;
}

void VirtualMachine::setLongVariable(int index, long value)
{
	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (index < (getScript().longCount)) {
		localVariables->longVarValues[index] = value;
	}
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setLongVariable(const char *id, long value)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	TES3::Script* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (*indexPtr < (getScript().longCount)) {
		localVariables->longVarValues[*indexPtr] = value;
	}
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setLongVariable(int index, long value, TES3::Reference &reference)
{
	auto attachment = tes3::getAttachedItemDataNode(&reference);
	if (attachment) {
		attachment->scriptData->longVarValues[index] = value;
	}
	//else throw error
}

short VirtualMachine::getShortVariable(int index)
{
	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (index < (getScript().shortCount))
		return localVariables->shortVarValues[index];
	//else error, the index is bigger than the number of variables
}

short VirtualMachine::getShortVariable(const char *id)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	TES3::Script* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (*indexPtr < (getScript().shortCount))
		return localVariables->shortVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

short VirtualMachine::getShortVariable(int index, TES3::Reference &reference)
{
	auto attachment = tes3::getAttachedItemDataNode(&reference);
	if (attachment) {
		return attachment->scriptData->shortVarValues[index];
	}
	//else throw error
}

void VirtualMachine::setShortVariable(int index, short value)
{
	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (index < (getScript().shortCount))
		localVariables->shortVarValues[index] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setShortVariable(const char *id, short value)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	TES3::Script* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (*indexPtr < (getScript().shortCount))
		localVariables->shortVarValues[*indexPtr] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setShortVariable(int index, short value, TES3::Reference &reference)
{
	auto attachment = tes3::getAttachedItemDataNode(&reference);
	if (attachment) {
		attachment->scriptData->shortVarValues[index] = value;
	}
	//else throw error
}

float VirtualMachine::getFloatVariable(int index)
{
	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (index < (getScript().floatCount))
		return localVariables->floatVarValues[index];
	//else error, the index is bigger than the number of variables
}

float VirtualMachine::getFloatVariable(const char *id)
{
	long * indexPtr;

	static int findScriptVariable = TES3_FUNC_FIND_SCRIPT_VARIABLE;
	TES3::Script* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (*indexPtr < (getScript().floatCount))
		return localVariables->floatVarValues[*indexPtr];
	//else error, the index is bigger than the number of variables
}

float VirtualMachine::getFloatVariable(int index, TES3::Reference &reference)
{
	auto attachment = tes3::getAttachedItemDataNode(&reference);
	if (attachment) {
		return attachment->scriptData->floatVarValues[index];
	}
	//else throw error
}

void VirtualMachine::setFloatVariable(int index, float value)
{
	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (index < (getScript().floatCount))
		localVariables->floatVarValues[index] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setFloatVariable(const char *id, float value)
{
	long * indexPtr;

	static int findScriptVariable = 0x50E7B0;
	TES3::Script* script = &getScript();

	__asm
	{
		mov ecx, script;

		push indexPtr;	//where the index will be in
		push id;		//the name of the variable
		call findScriptVariable;
	}

	auto localVariables = *(reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE));
	if (*indexPtr < (getScript().floatCount))
		localVariables->floatVarValues[*indexPtr] = value;
	//else error, the index is bigger than the number of variables
}

void VirtualMachine::setFloatVariable(int index, float value, TES3::Reference &reference)
{
	auto attachment = tes3::getAttachedItemDataNode(&reference);
	if (attachment) {
		attachment->scriptData->floatVarValues[index] = value;
	}
	//else throw error
}

long VirtualMachine::getLongGlobal(const char *id)
{
	/*
	masterCellImage = TES3_DATA_HANDLER_IMAGE
findGLOB = TES3_FUNC_FIND_GLOBAL

mov eax, masterCellImage
mov ecx, [eax]
push "char * globalToFind"
call findGLOB
return = EAX = GLOBRecord
*/

	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	TES3::GlobalVariable * foundRecord;
	__asm
	{
		mov ecx, dword ptr ds : [TES3_DATA_HANDLER_IMAGE]; //masterCellImage
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if (foundRecord->valueType == 'l')
	{
		return static_cast<long>(foundRecord->value);
	}
	//else error out!
}

void VirtualMachine::setLongGlobal(const char *id, long value)
{
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	TES3::GlobalVariable * foundRecord;
	__asm
	{
		mov ecx, dword ptr ds : [TES3_DATA_HANDLER_IMAGE];
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if (foundRecord->valueType == 'l')
	{
		foundRecord->value = static_cast<float>(value);
	}
	//else error out!
}

short VirtualMachine::getShortGlobal(const char *id)
{
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	TES3::GlobalVariable * foundRecord;
	__asm
	{
		mov ecx, dword ptr ds : [TES3_DATA_HANDLER_IMAGE];
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if (foundRecord->valueType == 's')
	{
		return static_cast<short>(foundRecord->value);
	}
	//else error out!
}

void VirtualMachine::setShortGlobal(const char *id, short value)
{
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	TES3::GlobalVariable * foundRecord;
	__asm
	{
		mov ecx, dword ptr ds : [TES3_DATA_HANDLER_IMAGE];
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if (foundRecord->valueType == 's')
	{
		foundRecord->value = static_cast<float>(value);
	}
	//else error out!
}

float VirtualMachine::getFloatGlobal(const char *id)
{
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	TES3::GlobalVariable * foundRecord;
	__asm
	{
		mov ecx, dword ptr ds : [TES3_DATA_HANDLER_IMAGE];
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if (foundRecord->valueType == 'f')
	{
		return foundRecord->value;
	}
	//else error out!
}

void VirtualMachine::setFloatGlobal(const char *id, float value)
{
	static int findGLOB = TES3_FUNC_FIND_GLOBAL;
	TES3::GlobalVariable * foundRecord;
	__asm
	{
		mov ecx, dword ptr ds : [TES3_DATA_HANDLER_IMAGE];
		push id;
		call findGLOB;
		mov foundRecord, eax;
	}

	//at this point we have the global we are looking for in 'foundRecord'

	if (foundRecord->valueType == 'f')
	{
		foundRecord->value = value;
	}
	//else error out!
}

char VirtualMachine::getByteValue(bool peek)
{
	int * scriptIP = reinterpret_cast<int*>(TES3_IP_IMAGE);

	TES3::Script script = getScript();			//get current script
	void * scriptstream = script.machineCode;	//get script data stream
	scriptstream = reinterpret_cast<void*>(reinterpret_cast<char*>(scriptstream) + *scriptIP);	//go to current position in script stream

	char returnData = *(reinterpret_cast<char*>(scriptstream));	//<-- change char here! (twice)

	if (!peek)
	{
		*scriptIP += sizeof(char);	//<-- change char here
	}

	return returnData;
}

short VirtualMachine::getShortValue(bool peek)
{
	int * scriptIP = reinterpret_cast<int*>(TES3_IP_IMAGE);

	TES3::Script script = getScript();
	void * scriptstream = script.machineCode;
	scriptstream = reinterpret_cast<void*>(reinterpret_cast<char*>(scriptstream) + *scriptIP);

	short returnData = *(reinterpret_cast<short*>(scriptstream));	//<-- change char here! (twice)

	if (!peek)
	{
		*scriptIP += sizeof(short);	//<-- change char here
	}

	return returnData;
}

long VirtualMachine::getLongValue(bool peek)
{
	int * scriptIP = reinterpret_cast<int*>(TES3_IP_IMAGE);

	TES3::Script script = getScript();
	void * scriptstream = script.machineCode;
	scriptstream = reinterpret_cast<void*>(reinterpret_cast<char*>(scriptstream) + *scriptIP);

	long returnData = *(reinterpret_cast<long*>(scriptstream));	//<-- change char here! (twice)

	if (!peek)
	{
		*scriptIP += sizeof(long);	//<-- change char here
	}

	return returnData;
}

float VirtualMachine::getFloatValue(bool peek)
{
	int * scriptIP = reinterpret_cast<int*>(TES3_IP_IMAGE);

	TES3::Script script = getScript();
	void * scriptstream = script.machineCode;
	scriptstream = reinterpret_cast<void*>(reinterpret_cast<char*>(scriptstream) + *scriptIP);

	float returnData = *(reinterpret_cast<float*>(scriptstream));	//<-- change char here! (twice)

	if (!peek)
	{
		*scriptIP += sizeof(float);	//<-- change char here
	}

	return returnData;
}

mwseString& VirtualMachine::getString(long fromStack)	//ask grant, need a '*' or a '&' here?? (and in the header files)
{
	// Invalid ID. Return an empty string.
	if (fromStack == 0x0)
	{
		return mwse::string::store::create("");
	}

	// Small enough to fit in the script as a literal string. Parse it from the script
	// stream.
	else if (fromStack < 32767)
	{
		void * scriptstream = getScript().machineCode;
		scriptstream = reinterpret_cast<void*>(reinterpret_cast<char*>(scriptstream) + fromStack);

		char blen = *(reinterpret_cast<char*>(scriptstream));

		long strlen = static_cast<long>(blen);

		scriptstream = reinterpret_cast<void*>(reinterpret_cast<char*>(scriptstream) + sizeof(blen));

		char * string = reinterpret_cast<char*>(scriptstream);

		return mwse::string::store::getOrCreate(string, strlen);
	}

	// If it's not in the script, it might be in storage.
	else if (mwse::string::store::exists(fromStack))
	{
		return mwse::string::store::get(fromStack);
	}

	// Otherwise, assume it's a char*, though we should never hit this case.
	else
	{
		const char* string = reinterpret_cast<char*>(fromStack);
		return mwse::string::store::getOrCreate(string);
	}
}

void VirtualMachine::dumpScriptVariables()
{
	if (!script) {
		mwse::log::getLog() << __FUNCTION__ << " - No script found." << std::endl;
		return;
	}

	mwse::log::getLog() << __FUNCTION__ << " - Variable dump for '" << script->name << "'" << std::endl;

	mwse::log::getLog() << "  Longs (" << script->longCount << "):" << std::endl;
	for (int i = 0; i < script->longCount; i++) {
		mwse::log::getLog() << "    " << script->longVarNamePointers[i] << " = " << std::dec << script->longVarValues[i] << std::endl;
	}

	mwse::log::getLog() << "  Floats (" << script->floatCount << "):" << std::endl;
	for (int i = 0; i < script->floatCount; i++) {
		mwse::log::getLog() << "    " << script->floatVarNamePointers[i] << " = " << std::dec << script->floatVarValues[i] << std::endl;
	}

	mwse::log::getLog() << "  Shorts (" << script->shortCount << "):" << std::endl;
	for (int i = 0; i < script->shortCount; i++) {
		mwse::log::getLog() << "    " << script->shortVarNamePointers[i] << " = " << std::dec << script->shortVarValues[i] << std::endl;
	}
}

long* VirtualMachine::getScriptIP()
{
	return mwScriptIP;
}