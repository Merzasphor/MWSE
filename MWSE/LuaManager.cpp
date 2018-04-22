#include "LuaManager.h"

#include "mwOffsets.h"
#include "Log.h"
#include "TES3Util.h"
#include "MemoryUtil.h"
#include "ScriptUtil.h"

#include "LuaUnifiedHeader.h"

#include "LuaScript.h"

// Lua binding files. These are split out rather than kept here to help with compile times.
#include "StackLua.h"
#include "ScriptUtilLua.h"
#include "StringUtilLua.h"
#include "TES3UtilLua.h"
#include "TES3ActionDataLua.h"
#include "TES3ActivatorLua.h"
#include "TES3AlchemyLua.h"
#include "TES3ApparatusLua.h"
#include "TES3ArmorLua.h"
#include "TES3BookLua.h"
#include "TES3CellLua.h"
#include "TES3ClassLua.h"
#include "TES3ClothingLua.h"
#include "TES3CollectionsLua.h"
#include "TES3ContainerLua.h"
#include "TES3CreatureLua.h"
#include "TES3DataHandlerLua.h"
#include "TES3DoorLua.h"
#include "TES3EnchantmentLua.h"
#include "TES3FactionLua.h"
#include "TES3GameLua.h"
#include "TES3GameSettingLua.h"
#include "TES3IngredientLua.h"
#include "TES3InventoryLua.h"
#include "TES3LightLua.h"
#include "TES3LockpickLua.h"
#include "TES3MagicEffectLua.h"
#include "TES3MiscLua.h"
#include "TES3MobileCreatureLua.h"
#include "TES3MobileNPCLua.h"
#include "TES3MobilePlayerLua.h"
#include "TES3MoonLua.h"
#include "TES3NPCLua.h"
#include "TES3ProbeLua.h"
#include "TES3RaceLua.h"
#include "TES3ReferenceLua.h"
#include "TES3ReferenceListLua.h"
#include "TES3RegionLua.h"
#include "TES3RepairToolLua.h"
#include "TES3ScriptLua.h"
#include "TES3SkillLua.h"
#include "TES3SpellLua.h"
#include "TES3StaticLua.h"
#include "TES3StatisticLua.h"
#include "TES3VectorsLua.h"
#include "TES3WeaponLua.h"
#include "TES3WeatherControllerLua.h"
#include "TES3WeatherLua.h"
#include "TES3WorldControllerLua.h"

#include <filesystem>

#define TES3_HOOK_RUNSCRIPT_LUACHECK 0x5029A4
#define TES3_HOOK_RUNSCRIPT_LUACHECK_SIZE 0x6
#define TES3_HOOK_RUNSCRIPT_LUACHECK_RETURN (TES3_HOOK_RUNSCRIPT_LUACHECK + TES3_HOOK_RUNSCRIPT_LUACHECK_SIZE)

#define TES3_HOOK_SAVE_REFERENCE 0x4E1C95
#define TES3_HOOK_SAVE_REFERENCE_SIZE 0x6
#define TES3_HOOK_SAVE_REFERENCE_RETURN (TES3_HOOK_SAVE_REFERENCE + TES3_HOOK_SAVE_REFERENCE_SIZE)

#define TES3_HOOK_LOAD_REFERENCE 0x4DE532
#define TES3_HOOK_LOAD_REFERENCE_SIZE 0x5
#define TES3_HOOK_LOAD_REFERENCE_RETURN (TES3_HOOK_LOAD_REFERENCE + TES3_HOOK_LOAD_REFERENCE_SIZE)
#define TES3_HOOK_LOAD_REFERENCE_RETURN_SUCCESS 0x4DE406

#define TES3_HOOK_FINISH_INITIALIZATION 0x4BBC0C
#define TES3_HOOK_FINISH_INITIALIZATION_SIZE 0x5
#define TES3_HOOK_FINISH_INITIALIZATION_RETURN (TES3_HOOK_FINISH_INITIALIZATION + TES3_HOOK_FINISH_INITIALIZATION_SIZE)

#define TES3_HOOK_BUTTON_PRESSED 0x5F208B
#define TES3_HOOK_BUTTON_PRESSED_SIZE 0x5
#define TES3_HOOK_BUTTON_PRESSED_RETURN (TES3_HOOK_BUTTON_PRESSED + TES3_HOOK_BUTTON_PRESSED_SIZE)

#define DEBUG_LUA_SCRIPT_INJECTION true

#define TES3_load_writeChunk 0x4B6BA0
#define TES3_load_readChunk 0x4B6880

namespace mwse {
	namespace lua {
		// Initialize singleton.
		LuaManager LuaManager::singleton;

		// Fast-access mapping from a TES3::Script* to its associated Lua module.
		static std::unordered_map<unsigned long, sol::table> scriptOverrides;

		// The currently executing overwritten script.
		static LuaScript * currentOverwrittenScript = NULL;

		// We still abort the program if an unprotected lua error happens. Here we at least
		// get it in the log so it can be debugged.
		int panic(lua_State* L) {
			const char* message = lua_tostring(L, -1);
			log::getLog() << (message ? message : "An unexpected error occurred and forced the lua state to call atpanic.") << std::endl;
			return 0;
		}

		// LuaManager constructor. This is private, as a singleton.
		LuaManager::LuaManager() {
			// Open default lua libraries.
			luaState.open_libraries();

			// Override the default atpanic to print to the log.
			luaState.set_panic(panic);

			// Overwrite the default print function to print to the MWSE log.
			luaState["print"] = [](sol::object message) {
				sol::state& state = LuaManager::getInstance().getState();
				std::string result = state["tostring"](message);
				log::getLog() << result << std::endl;
			};

			// Bind our data types.
			bindData();
		}

		void LuaManager::bindData() {
			// Bind our LuaScript type, which is used for holding script contexts.
			luaState.new_usertype<LuaScript>("LuaScript",
				sol::constructors<LuaScript()>(),

				// Implement dynamic object metafunctions.
				sol::meta_function::index, &DynamicLuaObject::dynamic_get,
				sol::meta_function::new_index, &DynamicLuaObject::dynamic_set,
				sol::meta_function::length, [](DynamicLuaObject& d) { return d.entries.size(); },

				// Set up read-only properties.
				"script", sol::readonly(&LuaScript::script),
				"reference", sol::readonly(&LuaScript::reference),
				"context", sol::readonly_property([](LuaScript& self) { return std::shared_ptr<ScriptContext>(new ScriptContext(self.script)); })

				);

			// Create the base of API tables.
			luaState["mwse"] = luaState.create_table();
			luaState["mwscript"] = luaState.create_table();

			// We want to take care of this here rather than in an external file so we have access to scriptOverrides.
			luaState["mwse"]["overrideScript"] = [](std::string scriptId, std::string target) {
				TES3::Script* script = tes3::getDataHandler()->nonDynamicData->findScriptByName(scriptId.c_str());
				if (script != NULL) {
					sol::state& state = LuaManager::getInstance().getState();
					sol::object result = state.safe_script_file("./Data Files/MWSE/lua/" + target + ".lua");
					if (result.is<sol::table>()) {
						scriptOverrides[(unsigned long)script] = result;
						script->dataLength = 0;
						return true;
					}
				}

				return false;
			};

			// Bind data types.
			bindTES3ActionData();
			bindTES3Activator();
			bindTES3Alchemy();
			bindTES3Apparatus();
			bindTES3Armor();
			bindTES3Book();
			bindTES3Cell();
			bindTES3Class();
			bindTES3Clothing();
			bindTES3Collections();
			bindTES3Container();
			bindTES3Creature();
			bindTES3DataHandler();
			bindTES3Door();
			bindTES3Enchantment();
			bindTES3Faction();
			bindTES3Game();
			bindTES3GameSetting();
			bindTES3Ingredient();
			bindTES3Inventory();
			bindTES3Light();
			bindTES3Lockpick();
			bindTES3MagicEffect();
			bindTES3Misc();
			bindTES3MobileCreature();
			bindTES3MobileNPC();
			bindTES3MobilePlayer();
			bindTES3Moon();
			bindTES3NPC();
			bindTES3Probe();
			bindTES3Race();
			bindTES3Reference();
			bindTES3ReferenceList();
			bindTES3Region();
			bindTES3RepairTool();
			bindTES3Script();
			bindTES3Skill();
			bindTES3Spell();
			bindTES3Static();
			bindTES3Statistic();
			bindTES3Vectors();
			bindTES3Weapon();
			bindTES3Weather();
			bindTES3WeatherController();
			bindTES3WorldController();
		}

		//
		// Hook: Run script.
		//

		// Determines if a script should be overriden, and executes the module::execute function if so.
		static void _stdcall RunScript(TES3::Script* script) {
			// Determine if we own this script.
			auto searchResult = scriptOverrides.find((unsigned long)script);
			if (searchResult == scriptOverrides.end()) {
				return;
			}

			// Update the LuaManager to reference our current context.
			lua::LuaManager& manager = lua::LuaManager::getInstance();
			manager.setCurrentReference(*reinterpret_cast<TES3::Reference**>(TES3_SCRIPTTARGETREF_IMAGE));
			manager.setCurrentScript(script);

			// Get and run the execute function.
			sol::state& state = manager.getState();
			sol::protected_function execute = searchResult->second["execute"];
			if (execute) {
				auto result = execute();
				if (!result.valid()) {
					sol::error error = result;
					log::getLog() << "Lua error encountered when override of script '" << script->name << "':" << std::endl << error.what() << std::endl;
					mwscript::StopScript(script, script);
				}
			}
			else {
				log::getLog() << "No execute function found for script override of '" << script->name << "'. Script execution stopped." << std::endl;
				mwscript::StopScript(script, script);
			}
		}

		// Hook for HookRunScriptIndirect.
		static DWORD callbackRunScript = TES3_HOOK_RUNSCRIPT_LUACHECK_RETURN;
		static __declspec(naked) void HookRunScript() {
			_asm
			{
				// Save all registers.
				pushad

				// Actually use our hook.
				push ebx
				call RunScript

				// Restore all registers.
				popad

				// Overwritten code.
				mov ecx, dword ptr ds : [TES3_SCRIPTTARGETREF_IMAGE]

				// Resume normal execution.
				jmp callbackRunScript
			}
		}

		//
		// Hook: Load reference.
		//

		static DWORD _stdcall LoadReference(TES3::Reference* reference, DWORD loader, DWORD nextSubrecordTag) {
			if (nextSubrecordTag != 'TAUL') {
				return FALSE;
			}

			// Call original readChunk function.
			char buffer[4096] = {};
			bool success = reinterpret_cast<char*(__thiscall *)(DWORD, char*, DWORD)>(TES3_load_readChunk)(loader, buffer, 0);

			// If we for whatever reason failed to load this chunk, bail.
			if (!success) {
				return FALSE;
			}

			// Get our lua table, and replace it with our new table.
			sol::state& state = LuaManager::getInstance().getState();
			sol::table table = reference->getLuaTable();
			table = state["json"]["decode"](buffer);

			// We successfully read this subrecord, so our jump location is back at the success location.
			return TRUE;
		}

		static DWORD callbackLoadReferenceMiss = TES3_HOOK_LOAD_REFERENCE_RETURN;
		static DWORD callbackLoadReferenceHit = TES3_HOOK_LOAD_REFERENCE_RETURN_SUCCESS;
		static __declspec(naked) void HookLoadReference() {
			_asm
			{
				// Save the registers.
				pushad

				// Actually use our hook.
				push eax
				push ebx
				push esi
				call LoadReference

				// If we returned false, continue normal execution.
				test eax, eax
				jz HookLoadReferenceContinue

				// Otherwise, jump to our success location.
				popad
				cmp eax, 'MANM'
				jmp callbackLoadReferenceHit

		HookLoadReferenceContinue:
				// Return normal execution instead.
				popad
				cmp eax, 'MANM'
				jmp callbackLoadReferenceMiss
			}
		}

		//
		// Hook: Save reference.
		//

		static void _stdcall SaveReference(TES3::Reference* reference, DWORD loader) {
			// Get the associated table.
			sol::table table = reference->getLuaTable();

			// If it is empty, don't bother saving it.
			if (table.empty()) {
				return;
			}

			// Convert the table to json for storage.
			sol::state& state = LuaManager::getInstance().getState();
			std::string json = state["json"]["encode"](table);

			// Call original writechunk function.
			reinterpret_cast<void*(__thiscall *)(DWORD, DWORD, const char*, DWORD)>(TES3_load_writeChunk)(loader, 'TAUL', json.c_str(), json.length() + 1);
		}

		static DWORD callbackSaveReference = TES3_HOOK_SAVE_REFERENCE_RETURN;
		static __declspec(naked) void HookSaveReference() {
			_asm
			{
				// Save registers.
				pushad

				// Actually use our hook.
				push esi
				push ebp
				call SaveReference

				// Restore registers.
				popad

				// Overwritten code.
				mov eax, [ebp+0x8]
				shr eax, 5

				// Resume normal execution.
				jmp callbackSaveReference
			}
		}

		//
		// Hook: Finished initializing game code.
		//

		static void _stdcall FinishInitialization() {
			// Raise an event about this.
			sol::state& state = LuaManager::getInstance().getState();
			state["event"]["trigger"]("initialized");
		}

		static DWORD callbackFinishedInitialization = TES3_HOOK_FINISH_INITIALIZATION_RETURN;
		static __declspec(naked) void HookFinishInitialization() {
			_asm
			{
				// Save the registers.
				pushad

				// Actually use our hook.
				call FinishInitialization

				// Resume normal execution.
				popad
				mov eax, 1
				jmp callbackFinishedInitialization
			}
		}

		//
		// Hook: Button pressed.
		//

		static void _stdcall ButtonPressed() {
			// Raise an event about this.
			sol::state& state = LuaManager::getInstance().getState();
			sol::table payload = state.create_table();
			payload["button"] = *reinterpret_cast<int*>(0x7B88C0);
			state["event"]["trigger"]("buttonPressed", payload);
			state["event"]["clear"]("buttonPressed");
		}

		static __declspec(naked) void HookButtonPressed() {
			_asm
			{
				// Save the registers.
				pushad

				// Actually use our hook.
				call ButtonPressed

				// Resume normal execution.
				popad
				pop edi
				mov al, 1
				pop esi
				retn
			}
		}

		void LuaManager::hook() {
			// Execute mwse_init.lua
			sol::protected_function_result result = luaState.do_file("Data Files/MWSE/lua/mwse_init.lua");
			if (!result.valid()) {
				sol::error err = result;
				log::getLog() << "ERROR: Failed to initialize MWSE Lua interface. Error encountered when executing mwse_init.lua:\n" << err.what() << std::endl;
			}

			// Bind libraries.
			bindMWSEStack();
			bindScriptUtil();
			bindStringUtil();
			bindTES3Util();

			// Look through the Data Files/MWSE/lua folder and see if there are any mod_init files.
			std::string path = "Data Files/MWSE/lua/";
			for (auto & p : std::experimental::filesystem::recursive_directory_iterator(path)) {
				if (p.path().filename() == "mod_init.lua") {
					result = luaState.do_file(p.path().generic_string());
					if (!result.valid()) {
						sol::error err = result;
						log::getLog() << "ERROR: Failed to run mod initialization script:\n" << err.what() << std::endl;
					}
				}
			}

			// Hook the RunScript function so we can intercept Lua scripts and invoke Lua code if needed.
			DWORD OldProtect;
			VirtualProtect((DWORD*)TES3_HOOK_RUNSCRIPT_LUACHECK, TES3_HOOK_RUNSCRIPT_LUACHECK_SIZE, PAGE_READWRITE, &OldProtect);
			genJump(TES3_HOOK_RUNSCRIPT_LUACHECK, reinterpret_cast<DWORD>(HookRunScript));
			for (DWORD i = TES3_HOOK_RUNSCRIPT_LUACHECK + 5; i < TES3_HOOK_RUNSCRIPT_LUACHECK_RETURN; i++) genNOP(i);
			VirtualProtect((DWORD*)TES3_HOOK_RUNSCRIPT_LUACHECK, TES3_HOOK_RUNSCRIPT_LUACHECK_SIZE, OldProtect, &OldProtect);

			// Hook the load reference function, so we can fetch attached Lua data.
			VirtualProtect((DWORD*)TES3_HOOK_LOAD_REFERENCE, TES3_HOOK_LOAD_REFERENCE_SIZE, PAGE_READWRITE, &OldProtect);
			genJump(TES3_HOOK_LOAD_REFERENCE, reinterpret_cast<DWORD>(HookLoadReference));
			VirtualProtect((DWORD*)TES3_HOOK_LOAD_REFERENCE, TES3_HOOK_LOAD_REFERENCE_SIZE, OldProtect, &OldProtect);

			// Hook the save reference function, so we can save attached Lua data.
			VirtualProtect((DWORD*)TES3_HOOK_SAVE_REFERENCE, TES3_HOOK_SAVE_REFERENCE_SIZE, PAGE_READWRITE, &OldProtect);
			genJump(TES3_HOOK_SAVE_REFERENCE, reinterpret_cast<DWORD>(HookSaveReference));
			for (DWORD i = TES3_HOOK_SAVE_REFERENCE + 5; i < TES3_HOOK_SAVE_REFERENCE_RETURN; i++) genNOP(i);
			VirtualProtect((DWORD*)TES3_HOOK_SAVE_REFERENCE, TES3_HOOK_SAVE_REFERENCE_SIZE, OldProtect, &OldProtect);

			// Event: initialized. Hook just before we return successfully from where game data is loaded.
			VirtualProtect((DWORD*)TES3_HOOK_FINISH_INITIALIZATION, TES3_HOOK_FINISH_INITIALIZATION_SIZE, PAGE_READWRITE, &OldProtect);
			genJump(TES3_HOOK_FINISH_INITIALIZATION, reinterpret_cast<DWORD>(HookFinishInitialization));
			VirtualProtect((DWORD*)TES3_HOOK_FINISH_INITIALIZATION, TES3_HOOK_FINISH_INITIALIZATION_SIZE, OldProtect, &OldProtect);

			// Event: buttonPressed. Hook after a button has been clicked.
			VirtualProtect((DWORD*)TES3_HOOK_BUTTON_PRESSED, TES3_HOOK_BUTTON_PRESSED_SIZE, PAGE_READWRITE, &OldProtect);
			genJump(TES3_HOOK_BUTTON_PRESSED, reinterpret_cast<DWORD>(HookButtonPressed));
			VirtualProtect((DWORD*)TES3_HOOK_BUTTON_PRESSED, TES3_HOOK_BUTTON_PRESSED_SIZE, OldProtect, &OldProtect);

			// Make magic effects writable.
			VirtualProtect((DWORD*)TES3_DATA_EFFECT_FLAGS, 4 * 143, PAGE_READWRITE, &OldProtect);
		}

		void LuaManager::cleanup() {
			// Clean up our handles to our override tables. Helps to prevent a crash when
			// closing mid-execution.
			scriptOverrides.clear();
		}

		TES3::Script* LuaManager::getCurrentScript() {
			return currentScript;
		}

		void LuaManager::setCurrentScript(TES3::Script* script) {
			currentScript = script;
		}

		TES3::Reference* LuaManager::getCurrentReference() {
			return currentReference;
		}

		void LuaManager::setCurrentReference(TES3::Reference* reference) {
			currentReference = reference;
		}
	}
}