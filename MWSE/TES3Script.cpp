#include "TES3Script.h"

#define TES3_Script_getScriptParams 0x500510
#define TES3_Script_executeScriptOpCode 0x505770

#define TES3_Script_getLocalVarIndexAndType 0x50E7B0

#define TES3_Script_getShortValue 0x4FFB90
#define TES3_Script_getLongValue 0x4FFC00
#define TES3_Script_getFloatValue 0x4FFC70

namespace TES3 {
	void Script::getScriptParams(bool unknown) {
		reinterpret_cast<void(__thiscall *)(Script*, bool)>(TES3_Script_getScriptParams)(this, unknown);
	}

	float Script::executeScriptOpCode(unsigned int opCode, char charParam, BaseObject * objectParam) {
		return reinterpret_cast<float(__thiscall *)(Script*, int, char, BaseObject*)>(TES3_Script_executeScriptOpCode)(this, opCode, charParam, objectParam);
	}

	char Script::getLocalVarIndexAndType(const char* name, unsigned int* out_value) {
		return reinterpret_cast<char(__thiscall *)(Script*, const char*, unsigned int*)>(TES3_Script_getLocalVarIndexAndType)(this, name, out_value);
	}

	short Script::getShortValue(unsigned int index, bool useLocalVars) {
		return reinterpret_cast<short(__thiscall *)(Script*, unsigned int, signed char)>(TES3_Script_getShortValue)(this, index, useLocalVars);
	}

	int Script::getLongValue(unsigned int index, bool useLocalVars) {
		return reinterpret_cast<int(__thiscall *)(Script*, unsigned int, signed char)>(TES3_Script_getLongValue)(this, index, useLocalVars);
	}

	float Script::getFloatValue(unsigned int index, bool useLocalVars) {
		return reinterpret_cast<float(__thiscall *)(Script*, unsigned int, signed char)>(TES3_Script_getFloatValue)(this, index, useLocalVars);
	}

	const auto TES3_Script_DoCommand = reinterpret_cast<void(__thiscall*)(Script*, ScriptCompiler *, const char*, int, Reference *, ScriptVariables *, DialogueInfo *, Dialogue *)>(0x50E5A0);
	void Script::doCommand(ScriptCompiler * compiler, const char* command, int source, Reference * reference, ScriptVariables * variables, DialogueInfo * info, Dialogue * dialogue) {
		TES3_Script_DoCommand(this, compiler, command, source, reference, variables, info, dialogue);
	}
}
