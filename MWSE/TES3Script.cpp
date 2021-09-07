#include "TES3Script.h"

#include "TES3ScriptLua.h"

#include "TES3ItemData.h"
#include "TES3Reference.h"


namespace TES3 {
	//
	// TES3::GlobalScript
	//

	std::shared_ptr<mwse::lua::ScriptContext> GlobalScript::createContext() const {
		TES3::ItemData* itemData = reference->getAttachedItemData();
		if (itemData) {
			return std::make_shared<mwse::lua::ScriptContext>(script, itemData->scriptData);
		}
		return nullptr;
	}

	//
	// TES3::Script
	//

	Script* Script::currentlyExecutingScript = nullptr;
	Reference* Script::currentlyExecutingScriptReference = nullptr;

	const auto TES3_Script_executeScriptOpCode = reinterpret_cast<float(__thiscall *)(Script*, int, char, BaseObject*)>(0x505770);
	float Script::executeScriptOpCode(unsigned int opCode, char charParam, BaseObject * objectParam) {
		return TES3_Script_executeScriptOpCode(this, opCode, charParam, objectParam);
	}

	const auto TES3_Script_getLocalVarIndexAndType = reinterpret_cast<char(__thiscall *)(Script*, const char*, unsigned int*)>(0x50E7B0);
	char Script::getLocalVarIndexAndType(const char* name, unsigned int* out_index) {
		return TES3_Script_getLocalVarIndexAndType(this, name, out_index);
	}

	sol::optional<unsigned int> Script::getShortVarIndex(const char* name) const {
		for (int i = 0; i < shortCount; i++) {
			const char* varName = shortVarNamePointers[i];
			if (varName && _stricmp(name, varName) == 0) {
				return i;
			}
		}
		return {};
	}

	const auto TES3_Script_getShortValue = reinterpret_cast<short(__thiscall*)(Script*, unsigned int, bool)>(0x4FFB90);
	short Script::getShortValue(unsigned int index, bool useLocalVars) {
		return TES3_Script_getShortValue(this, index, useLocalVars);
	}

	const auto TES3_Script_getLongValue = reinterpret_cast<int(__thiscall*)(Script*, unsigned int, bool)>(0x4FFC00);
	int Script::getLongValue(unsigned int index, bool useLocalVars) {
		return TES3_Script_getLongValue(this, index, useLocalVars);
	}

	const auto TES3_Script_getFloatValue = reinterpret_cast<float(__thiscall*)(Script*, unsigned int, bool)>(0x4FFC70);
	float Script::getFloatValue(unsigned int index, bool useLocalVars) {
		return TES3_Script_getFloatValue(this, index, useLocalVars);
	}

	const auto TES3_Script_DoCommand = reinterpret_cast<void(__thiscall*)(Script*, ScriptCompiler *, const char*, int, Reference *, ScriptVariables *, DialogueInfo *, Dialogue *)>(0x50E5A0);
	void Script::doCommand(ScriptCompiler * compiler, const char* command, int source, Reference * reference, ScriptVariables * variables, DialogueInfo * info, Dialogue * dialogue) {
		TES3_Script_DoCommand(this, compiler, command, source, reference, variables, info, dialogue);
	}

	const auto TES3_Script_execute = reinterpret_cast<void(__thiscall*)(Script*, Reference*, ScriptVariables*, DialogueInfo*, Reference*)>(0x5028A0);
	void Script::execute(Reference* reference, ScriptVariables* data, DialogueInfo* info, Reference* reference2) {
		currentlyExecutingScript = this;
		currentlyExecutingScriptReference = reference;
		TES3_Script_execute(this, reference, data, info, reference2);
		currentlyExecutingScript = nullptr;
		currentlyExecutingScriptReference = nullptr;
	}

	sol::table Script::getLocalVars_lua(sol::this_state ts, sol::optional<bool> useLocals) {
		if (shortCount == 0 && longCount == 0 && floatCount == 0) {
			return sol::nil;
		}

		sol::state_view state = ts;

		sol::table results = state.create_table();

		// Append any short variables.
		for (int i = 0; i < shortCount; i++) {
			const char* varName = shortVarNamePointers[i];
			results[varName] = state.create_table_with("type", 's', "index", i, "value", getShortValue(i, useLocals.value_or(false)));
		}

		// Append any long variables.
		for (int i = 0; i < longCount; i++) {
			const char* varName = longVarNamePointers[i];
			results[varName] = state.create_table_with("type", 'l', "index", i, "value", getLongValue(i, useLocals.value_or(false)));
		}

		// Append any float variables.
		for (int i = 0; i < floatCount; i++) {
			const char* varName = floatVarNamePointers[i];
			results[varName] = state.create_table_with("type", 'f', "index", i, "value", getFloatValue(i, useLocals.value_or(false)));
		}

		return results;
	}

	std::shared_ptr<mwse::lua::ScriptContext> Script::createContext() {
		return std::make_shared<mwse::lua::ScriptContext>(this, &varValues);
	}

}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Script)
