#include "LuaManager.h"

#include "mwOffsets.h"
#include "Log.h"
#include "TES3Util.h"
#include "TES3Game.h"
#include "TES3Reference.h"
#include "LuaUtil.h"
#include "MemoryUtil.h"
#include "ScriptUtil.h"

#include "TES3Cell.h"
#include "TES3DataHandler.h"
#include "TES3Script.h"
#include "TES3MobilePlayer.h"
#include "TES3WorldController.h"

// Lua binding files. These are split out rather than kept here to help with compile times.
#include "StackLua.h"
#include "ScriptUtilLua.h"
#include "TES3ActionDataLua.h"
#include "TES3ActivatorLua.h"
#include "TES3AlchemyLua.h"
#include "TES3ApparatusLua.h"
#include "TES3ArmorLua.h"
#include "TES3BookLua.h"
#include "TES3CellLua.h"
#include "TES3ClassLua.h"
#include "TES3ClothingLua.h"
#include "TES3ContainerLua.h"
#include "TES3CreatureLua.h"
#include "TES3DataHandlerLua.h"
#include "TES3DoorLua.h"
#include "TES3EnchantmentLua.h"
#include "TES3FactionLua.h"
#include "TES3GameLua.h"
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
#include "TES3RegionLua.h"
#include "TES3RepairToolLua.h"
#include "TES3ScriptLua.h"
#include "TES3SkillLua.h"
#include "TES3SpellLua.h"
#include "TES3StatisticLua.h"
#include "TES3VectorsLua.h"
#include "TES3WeaponLua.h"
#include "TES3WeatherControllerLua.h"
#include "TES3WeatherLua.h"
#include "TES3WorldControllerLua.h"

#define TES3_HOOK_SCRIPT_NEW_LUACHECK 0x4C086D
#define TES3_HOOK_SCRIPT_NEW_LUACHECK_SIZE 0x8
#define TES3_HOOK_SCRIPT_NEW_LUACHECK_RETURN (TES3_HOOK_SCRIPT_NEW_LUACHECK + TES3_HOOK_SCRIPT_NEW_LUACHECK_SIZE)

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

		// Overwrite function for Lua's print(), so that we can get information to the log
		// from lua.
		int printToLog(lua_State* L) {
			log::getLog() << lua_tostring(L, -1) << std::endl;
			lua_pop(L, 1);
			return 0;
		}

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
			luaState["print"] = printToLog;

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

			//
			// Extend mwse library with extra functions to replace %L in MWSE.
			//

			luaState["mwse"]["stringToLong"] = [](std::string value) {
				if (value.length() != 4) {
					return 0;
				}

				return *reinterpret_cast<const int*>(value.c_str());
			};

			luaState["mwse"]["longToString"] = [](int value) {
				return std::string(reinterpret_cast<char*>(&value), 4);
			};

			// Bind data types.
			bindMWSEStack();
			bindScriptUtil();
			bindTES3ActionData();
			bindTES3Activator();
			bindTES3Alchemy();
			bindTES3Apparatus();
			bindTES3Armor();
			bindTES3Book();
			bindTES3Cell();
			bindTES3Class();
			bindTES3Clothing();
			bindTES3Container();
			bindTES3Creature();
			bindTES3DataHandler();
			bindTES3Door();
			bindTES3Enchantment();
			bindTES3Faction();
			bindTES3Game();
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
			bindTES3Region();
			bindTES3RepairTool();
			bindTES3Script();
			bindTES3Skill();
			bindTES3Spell();
			bindTES3Statistic();
			bindTES3Vectors();
			bindTES3Weapon();
			bindTES3Weather();
			bindTES3WeatherController();
			bindTES3WorldController();
		}

		// Locates the file of the script being initialized. If it finds one, it maps this
		// script to the found Lua file. Future executions of this script would then be 
		// handled by Lua.
		// Note that the script is not fully loaded at this state, but its name should be
		// there at least.
		static void _stdcall ScriptNew(TES3::Script* script) {
			// Build up the desired path and check to see if the file exists.
			std::string luaPath = "Data Files\\MWSE\\lua\\overrides\\";
			luaPath.append(script->name, min(strlen(script->name), 32));
			luaPath.append(".lua");
			if (GetFileAttributes(luaPath.c_str()) == INVALID_FILE_ATTRIBUTES) {
				return;
			}

			// Load/execute associated file, and store the returned module into an
			// unordered_map for later lookup.
			try {
				LuaManager& luaManager = LuaManager::getInstance();
				sol::state& state = luaManager.getState();

				// Set lua-side context for script. Reference is null here.
				luaManager.setCurrentScript(script);

				sol::table scriptModule = state.script_file(luaPath);
				if (!scriptModule.valid()) {
#if DEBUG_LUA_SCRIPT_INJECTION
					log::getLog() << "Could not load lua module for " << script->name << std::endl;
#endif
					return;
				}

				// Set the read-only property linking the LuaScript to the TES3::Script.
				LuaScript* luaScript = scriptModule.as<LuaScript*>();
				luaScript->script = script;

				// Link the script into our map so that it is actually used, and prevent the
				// native mwscript code from being run.
#if DEBUG_LUA_SCRIPT_INJECTION
				log::getLog() << "Overwriting script for " << script->name << " -> " << luaPath << std::endl;
#endif
				scriptOverrides[(unsigned long)script] = scriptModule;
				script->dataLength = 0;

				// Call the script's initialize function, if it exists.
				currentOverwrittenScript = luaScript;
				auto initialized = scriptModule["initialized"];
				if (initialized.get_type() == sol::type::function) {
					initialized();
				}
			}
			catch (std::exception& e) {
				log::getLog() << e.what() << std::endl;
			}
		}

		// Hook for ScriptNew.
		DWORD skipped_setEntitySrcMod = 0x4EEE50;
		DWORD callbackScriptNew = TES3_HOOK_SCRIPT_NEW_LUACHECK_RETURN;
		static __declspec(naked) void HookScriptNew() {
			_asm
			{
				// Overwritten code.
				push esi
				mov ecx, edi
				call skipped_setEntitySrcMod

				// Save registers.
				pushad

				// Actually use our hook.
				push edi
				call ScriptNew

				// Restore registers.
				popad

				// Resume normal execution.
				jmp callbackScriptNew
			}
		}

		// Determines if a script should be overriden, and executes the module::execute function if so.
		static void _stdcall RunScript(TES3::Script* script) {
			// Determine if we own this script.
			auto searchResult = scriptOverrides.find((unsigned long)script);
			if (searchResult == scriptOverrides.end()) {
				return;
			}

			// Get and update the script context.
			LuaScript* luaScript = searchResult->second.as<LuaScript*>();
			luaScript->reference = *reinterpret_cast<TES3::Reference**>(TES3_SCRIPTTARGETREF_IMAGE);
			currentOverwrittenScript = luaScript;

			// Update the internal LuaManager script/reference for ambiguous calls.
			LuaManager& luaManager = LuaManager::getInstance();
			luaManager.setCurrentScript(script);
			luaManager.setCurrentReference(luaScript->reference);

			// Call the script in a protected state.
			sol::protected_function execute = searchResult->second["execute"];
			auto result = execute();
			if (result.valid()) {
				// Check the return value. If it is false, stop the script execution.
				sol::object shouldContinue = result;
				if (shouldContinue.is<bool>() && shouldContinue.as<bool>() == false) {
					mwse::mwscript::StopScript(script, script);
				}
			}
			else {
				// Stop script if execution failed.
				mwse::mwscript::StopScript(script, script);

				// Print error to log.
				sol::error error = result;
				log::getLog() << "Lua error in " << script->name << ":execute():\n\t" << error.what() << std::endl;
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

		void LuaManager::hook() {
			// Execute mwse_init.lua
			sol::protected_function_result result = luaState.do_file("Data Files/MWSE/lua/mwse_init.lua");
			if (!result.valid()) {
				sol::error err = result;
				log::getLog() << "ERROR: Failed to initialize MWSE Lua interface. Error encountered when executing mwse_init.lua:\n" << err.what() << std::endl;
			}

			//
			// Extend tes3 library with extra functions.
			//

			// Bind function: GetPlayerRef
			luaState["tes3"]["getPlayerRef"] = []() {
				TES3::MobilePlayer* mobilePlayer = NULL;

				static int getMACP = TES3_FUNC_GET_MACP;
				_asm
				{
					mov ecx, dword ptr ds : [TES3_WORLD_CONTROLLER_IMAGE];
					call getMACP;
					mov mobilePlayer, eax;
				}

				return mobilePlayer->reference;
			};

			// Bind function: tes3.getPlayerCell()
			luaState["tes3"]["getPlayerCell"] = []() {
				return tes3::getDataHandler()->currentCell;
			};

			// Bind function: tes3.getGame
			luaState["tes3"]["getGame"] = []() {
				return tes3::getGame();
			};

			// Bind function: tes3.getDataHandler
			luaState["tes3"]["getDataHandler"] = []() {
				return tes3::getDataHandler();
			};

			// Bind function: tes3.getGame
			luaState["tes3"]["getWorldController"] = []() {
				return tes3::getWorldController();
			};

			// Bind function: tes3.getPlayerTarget
			luaState["tes3"]["getPlayerTarget"] = []() {
				return tes3::getGame()->playerTarget;
			};

			// Bind function: tes3.getReference
			luaState["tes3"]["getReference"] = [](std::string& id) {
				return tes3::getReference(id);
			};

			// Bind function: tes3.getObject
			luaState["tes3"]["getObject"] = [](std::string& id, TES3::ObjectType::ObjectType type) {
				return makeLuaObject(tes3::getObjectByID<TES3::BaseObject>(id, type));
			};

			// Bind function: tes3.getScript
			luaState["tes3"]["getScript"] = [](std::string& id) {
				return tes3::getScript(id);
			};

			DWORD OldProtect;

			// Hook the point where scripts are created so we can determine if it is a lua script.
			// We can't do the script constructor here, because at that time the script's name is not determined.
			VirtualProtect((DWORD*)TES3_HOOK_SCRIPT_NEW_LUACHECK, TES3_HOOK_SCRIPT_NEW_LUACHECK_SIZE, PAGE_READWRITE, &OldProtect);
			genJump(TES3_HOOK_SCRIPT_NEW_LUACHECK, reinterpret_cast<DWORD>(HookScriptNew));
			for (DWORD i = TES3_HOOK_SCRIPT_NEW_LUACHECK + 5; i < TES3_HOOK_SCRIPT_NEW_LUACHECK_RETURN; i++) genNOP(i);
			VirtualProtect((DWORD*)TES3_HOOK_SCRIPT_NEW_LUACHECK, TES3_HOOK_SCRIPT_NEW_LUACHECK_SIZE, OldProtect, &OldProtect);

			// Hook the RunScript function so we can intercept Lua scripts and invoke Lua code if needed.
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