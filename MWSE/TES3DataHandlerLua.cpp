#include "TES3DataHandlerLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Cell.h"
#include "TES3DataHandler.h"
#include "TES3DialogueInfo.h"
#include "TES3GlobalVariable.h"
#include "TES3Reference.h"
#include "TES3Script.h"

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
				usertypeDefinition.set("classes", sol::readonly_property(&TES3::NonDynamicData::classes));
				usertypeDefinition.set("factions", sol::readonly_property(&TES3::NonDynamicData::factions));
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
				usertypeDefinition.set("findDialogInfo", &TES3::NonDynamicData::findDialogInfo);
				usertypeDefinition.set("findFirstCloneOfActor", &TES3::NonDynamicData::findFirstCloneOfActor);
				usertypeDefinition.set("findGlobalVariable", &TES3::NonDynamicData::findGlobalVariable);
				usertypeDefinition.set("findScript", &TES3::NonDynamicData::findScriptByName);
				usertypeDefinition.set("resolveObject", &TES3::NonDynamicData::resolveObject);

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

				// Finish up our usertype.
				state.set_usertype("tes3dataHandler", usertypeDefinition);
			}
		}
	}
}
