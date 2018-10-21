#include "TES3DataHandlerLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Cell.h"
#include "TES3DataHandler.h"
#include "TES3DialogueInfo.h"
#include "TES3GlobalVariable.h"
#include "TES3Reference.h"
#include "TES3Script.h"
#include "TES3Sound.h"

#include "NISourceTexture.h"

#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3DataHandler() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::NonDynamicData
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::NonDynamicData>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("cells", sol::readonly_property(&TES3::NonDynamicData::cells));
				usertypeDefinition.set("classes", sol::readonly_property(&TES3::NonDynamicData::classes));
				usertypeDefinition.set("dialogues", sol::readonly_property(&TES3::NonDynamicData::dialogues));
				usertypeDefinition.set("factions", sol::readonly_property(&TES3::NonDynamicData::factions));
				usertypeDefinition.set("globals", sol::readonly_property(&TES3::NonDynamicData::globals));
				usertypeDefinition.set("magicEffects", sol::readonly_property([](TES3::NonDynamicData& self) { return std::ref(self.magicEffects); }));
				usertypeDefinition.set("objects", sol::readonly_property(&TES3::NonDynamicData::list));
				usertypeDefinition.set("races", sol::readonly_property(&TES3::NonDynamicData::races));
				usertypeDefinition.set("regions", sol::readonly_property(&TES3::NonDynamicData::regions));
				usertypeDefinition.set("scripts", sol::readonly_property(&TES3::NonDynamicData::scripts));
				usertypeDefinition.set("skills", sol::readonly_property([](TES3::NonDynamicData& self) { return std::ref(self.skills); }));
				usertypeDefinition.set("soundGenerators", sol::readonly_property(&TES3::NonDynamicData::soundGenerators));
				usertypeDefinition.set("sounds", sol::readonly_property(&TES3::NonDynamicData::sounds));
				usertypeDefinition.set("spells", sol::readonly_property(&TES3::NonDynamicData::spellsList));
				usertypeDefinition.set("startScripts", sol::readonly_property(&TES3::NonDynamicData::startScripts));

				// Basic function binding.
				usertypeDefinition.set("addNewObject", &TES3::NonDynamicData::addNewObject);
				usertypeDefinition.set("deleteObject", &TES3::NonDynamicData::deleteObject);

				// Functions that need to be wrapped.
				usertypeDefinition.set("findDialogue", [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findDialogue(id)); });
				usertypeDefinition.set("findFirstCloneOfActor", [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findFirstCloneOfActor(id)); });
				usertypeDefinition.set("findGlobalVariable", [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findGlobalVariable(id)); });
				usertypeDefinition.set("findScript", [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findScriptByName(id)); });
				usertypeDefinition.set("findSound", [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findSound(id)); });
				usertypeDefinition.set("resolveObject", [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.resolveObject(id)); });

				// Deprecated functions. TODO: Remove before 2.1 final.
				usertypeDefinition.set("findDialogInfo", &TES3::NonDynamicData::findDialogue); // Badly named. Actually gives DIAL, not INFO.

				// Finish up our usertype.
				state.set_usertype("tes3nonDynamicData", usertypeDefinition);
			}

			// Binding for TES3::DataHandler
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::DataHandler>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("backgroundThread", sol::readonly_property(&TES3::DataHandler::backgroundThread));
				usertypeDefinition.set("backgroundThreadId", sol::readonly_property(&TES3::DataHandler::backgroundThreadID));
				usertypeDefinition.set("backgroundThreadRunning", sol::readonly_property(&TES3::DataHandler::backgroundThreadRunning));
				usertypeDefinition.set("cellChanged", sol::readonly_property(&TES3::DataHandler::cellChanged));
				usertypeDefinition.set("centralGridX", sol::readonly_property(&TES3::DataHandler::centralGridX));
				usertypeDefinition.set("centralGridY", sol::readonly_property(&TES3::DataHandler::centralGridY));
				usertypeDefinition.set("currentCell", sol::readonly_property(&TES3::DataHandler::currentCell));
				usertypeDefinition.set("currentInteriorCell", sol::readonly_property(&TES3::DataHandler::currentInteriorCell));
				usertypeDefinition.set("lastExteriorCell", sol::readonly_property(&TES3::DataHandler::lastExteriorCell));
				usertypeDefinition.set("mainThread", sol::readonly_property(&TES3::DataHandler::mainThread));
				usertypeDefinition.set("mainThreadId", sol::readonly_property(&TES3::DataHandler::mainThreadID));
				usertypeDefinition.set("nonDynamicData", sol::readonly_property(&TES3::DataHandler::nonDynamicData));
				usertypeDefinition.set("threadSleepTime", sol::readonly_property(&TES3::DataHandler::threadSleepTime));

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("exteriorCells", sol::readonly_property([](TES3::DataHandler& self) { return std::ref(self.exteriorCellData); }));

				// Finish up our usertype.
				state.set_usertype("tes3dataHandler", usertypeDefinition);
			}
		}
	}
}
