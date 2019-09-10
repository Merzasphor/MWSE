#include "TES3DataHandlerLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Cell.h"
#include "TES3DataHandler.h"
#include "TES3DialogueInfo.h"
#include "TES3GlobalVariable.h"
#include "TES3MagicEffectController.h"
#include "TES3Reference.h"
#include "TES3Script.h"
#include "TES3Sound.h"

#include "NINode.h"
#include "NISourceTexture.h"

#include "LuaUtil.h"

namespace mwse {
	namespace lua {
		void bindTES3DataHandler() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::NonDynamicData
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::NonDynamicData>("tes3nonDynamicData");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["cells"] = sol::readonly_property(&TES3::NonDynamicData::cells);
				usertypeDefinition["classes"] = sol::readonly_property(&TES3::NonDynamicData::classes);
				usertypeDefinition["dialogues"] = sol::readonly_property(&TES3::NonDynamicData::dialogues);
				usertypeDefinition["factions"] = sol::readonly_property(&TES3::NonDynamicData::factions);
				usertypeDefinition["globals"] = sol::readonly_property(&TES3::NonDynamicData::globals);
				usertypeDefinition["objects"] = sol::readonly_property(&TES3::NonDynamicData::list);
				usertypeDefinition["races"] = sol::readonly_property(&TES3::NonDynamicData::races);
				usertypeDefinition["regions"] = sol::readonly_property(&TES3::NonDynamicData::regions);
				usertypeDefinition["scripts"] = sol::readonly_property(&TES3::NonDynamicData::scripts);
				usertypeDefinition["skills"] = sol::readonly_property([](TES3::NonDynamicData& self) { return std::ref(self.skills); });
				usertypeDefinition["soundGenerators"] = sol::readonly_property(&TES3::NonDynamicData::soundGenerators);
				usertypeDefinition["sounds"] = sol::readonly_property(&TES3::NonDynamicData::sounds);
				usertypeDefinition["spells"] = sol::readonly_property(&TES3::NonDynamicData::spellsList);
				usertypeDefinition["startScripts"] = sol::readonly_property(&TES3::NonDynamicData::startScripts);

				// Basic function binding.
				usertypeDefinition["addNewObject"] = &TES3::NonDynamicData::addNewObject;
				usertypeDefinition["deleteObject"] = &TES3::NonDynamicData::deleteObject;

				// Functions that need to be wrapped.
				usertypeDefinition["findDialogue"] = [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findDialogue(id)); };
				usertypeDefinition["findFirstCloneOfActor"] = [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findFirstCloneOfActor(id)); };
				usertypeDefinition["findGlobalVariable"] = [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findGlobalVariable(id)); };
				usertypeDefinition["findScript"] = [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findScriptByName(id)); };
				usertypeDefinition["findSound"] = [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.findSound(id)); };
				usertypeDefinition["resolveObject"] = [](TES3::NonDynamicData& self, const char* id) { return makeLuaObject(self.resolveObject(id)); };

				// Provide legacy access to magic effects table.
				usertypeDefinition["magicEffects"] = sol::readonly_property(
					[](TES3::NonDynamicData& self, sol::this_state s) {
						sol::state_view state = s;
						sol::table results = state.create_table();
						for (auto itt : self.magicEffects->effectObjects) {
							results.add(itt.second);
						}
						return results;
					}
				);

				// Deprecated functions. TODO: Remove before 2.1 final.
				usertypeDefinition["findDialogInfo"] = &TES3::NonDynamicData::findDialogue; // Badly named. Actually gives DIAL, not INFO.
			}

			// Binding for TES3::DataHandler::ExteriorCellData
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::DataHandler::ExteriorCellData>("tes3dataHandlerExteriorCellData");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["cell"] = sol::readonly_property(&TES3::DataHandler::ExteriorCellData::cell);
				usertypeDefinition["loadingFlags"] = sol::readonly_property(&TES3::DataHandler::ExteriorCellData::loadingFlags);
			}

			// Binding for TES3::DataHandler
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::DataHandler>("tes3dataHandler");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["backgroundThread"] = sol::readonly_property(&TES3::DataHandler::backgroundThread);
				usertypeDefinition["backgroundThreadId"] = sol::readonly_property(&TES3::DataHandler::backgroundThreadID);
				usertypeDefinition["backgroundThreadRunning"] = sol::readonly_property(&TES3::DataHandler::backgroundThreadRunning);
				usertypeDefinition["cellChanged"] = sol::readonly_property(&TES3::DataHandler::cellChanged);
				usertypeDefinition["centralGridX"] = sol::readonly_property(&TES3::DataHandler::centralGridX);
				usertypeDefinition["centralGridY"] = sol::readonly_property(&TES3::DataHandler::centralGridY);
				usertypeDefinition["currentCell"] = sol::readonly_property(&TES3::DataHandler::currentCell);
				usertypeDefinition["currentInteriorCell"] = sol::readonly_property(&TES3::DataHandler::currentInteriorCell);
				usertypeDefinition["lastExteriorCell"] = sol::readonly_property(&TES3::DataHandler::lastExteriorCell);
				usertypeDefinition["mainThread"] = sol::readonly_property(&TES3::DataHandler::mainThread);
				usertypeDefinition["mainThreadId"] = sol::readonly_property(&TES3::DataHandler::mainThreadID);
				usertypeDefinition["nonDynamicData"] = sol::readonly_property(&TES3::DataHandler::nonDynamicData);
				usertypeDefinition["threadSleepTime"] = sol::readonly_property(&TES3::DataHandler::threadSleepTime);
				usertypeDefinition["useCellTransitionFader"] = &TES3::DataHandler::useCellTransitionFader;
				usertypeDefinition["worldObjectRoot"] = sol::readonly_property(&TES3::DataHandler::worldObjectRoot);
				usertypeDefinition["worldPickObjectRoot"] = sol::readonly_property(&TES3::DataHandler::worldPickObjectRoot);
				usertypeDefinition["worldLandscapeRoot"] = sol::readonly_property(&TES3::DataHandler::worldLandscapeRoot);

				// Indirect bindings to unions and arrays.
				usertypeDefinition["exteriorCells"] = sol::readonly_property([](TES3::DataHandler& self) { return std::ref(self.exteriorCellData); });

				// Basic function binding.
				usertypeDefinition["updateCollisionGroupsForActiveCells"] = &TES3::DataHandler::updateCollisionGroupsForActiveCells;
			}
		}
	}
}
