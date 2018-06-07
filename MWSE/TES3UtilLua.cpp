#include "TES3UtilLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3GameFile.h"

#include "TES3Util.h"
#include "UIUtil.h"
#include "LuaUtil.h"
#include "Stack.h"
#include "Log.h"
#include "ScriptUtil.h"
#include "CodePatchUtil.h"

#include "NICamera.h"
#include "NIPick.h"

#include "TES3Actor.h"
#include "TES3Cell.h"
#include "TES3DataHandler.h"
#include "TES3Game.h"
#include "TES3GameSetting.h"
#include "TES3GlobalVariable.h"
#include "TES3InputController.h"
#include "TES3MobilePlayer.h"
#include "TES3Reference.h"
#include "TES3Script.h"
#include "TES3SoundGenerator.h"
#include "TES3UIBlock.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		auto iterateObjectsFiltered(unsigned int desiredType) {
			TES3::Object* object = tes3::getDataHandler()->nonDynamicData->list->head;
			return [object, desiredType]() mutable -> sol::object {
				while (object && desiredType != 0 && object->objectType != desiredType) {
					object = object->nextInCollection;
				}

				if (object == NULL) {
					return sol::nil;
				}

				sol::object ret = makeLuaObject(object);
				object = object->nextInCollection;
				return ret;
			};
		}

		auto iterateObjects() {
			return iterateObjectsFiltered(0);
		}

		void bindTES3Util() {
			sol::state& state = LuaManager::getInstance().getState();

			//
			// Extend tes3 library with extra functions.
			//

			// Bind function: tes3.getPlayerRef
			state["tes3"]["getPlayerRef"] = []() -> TES3::Reference* {
				TES3::WorldController* worldController = tes3::getWorldController();
				if (worldController) {
					TES3::MobilePlayer* mobilePlayer = worldController->getMobilePlayer();
					if (mobilePlayer) {
						return mobilePlayer->reference;
					}
				}
				return NULL;
			};

			// Bind function: tes3.getMobilePlayer
			state["tes3"]["getMobilePlayer"] = []() -> TES3::MobilePlayer* {
				TES3::WorldController* worldController = tes3::getWorldController();
				if (worldController) {
					return worldController->getMobilePlayer();
				}
				return NULL;
			};

			// Bind function: tes3.getPlayerCell()
			state["tes3"]["getPlayerCell"] = []() -> TES3::Cell* {
				TES3::DataHandler* dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					return dataHandler->currentCell;
				}
				return NULL;
			};

			// Bind function: tes3.getGame
			state["tes3"]["getGame"] = []() {
				return tes3::getGame();
			};

			// Bind function: tes3.getDataHandler
			state["tes3"]["getDataHandler"] = []() {
				return tes3::getDataHandler();
			};

			// Bind function: tes3.getGame
			state["tes3"]["getWorldController"] = []() {
				return tes3::getWorldController();
			};

			// Bind function: tes3.getPlayerTarget
			state["tes3"]["getPlayerTarget"] = []() {
				return tes3::getGame()->playerTarget;
			};

			// Bind function: tes3.getReference
			state["tes3"]["getReference"] = [](sol::optional<std::string> id) {
				if (id) {
					return tes3::getReference(id.value());
				}
				else {
					return LuaManager::getInstance().getCurrentReference();
				}
			};

			// Bind function: tes3.getObject
			state["tes3"]["getObject"] = [](std::string& id) -> sol::object {
				auto dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					return makeLuaObject(dataHandler->nonDynamicData->resolveObject(id.c_str()));
				}
				return sol::nil;
			};

			state["tes3"]["deleteObject"] = [](sol::object maybe) {
				TES3::BaseObject* object = maybe.as<TES3::BaseObject*>();
				if (object) {
					tes3::getDataHandler()->nonDynamicData->deleteObject(object);
					object->vTable.base->destructor(object, true);
				}
			};

			// Bind function: tes3.getScript
			state["tes3"]["getScript"] = [](std::string& id) {
				return tes3::getDataHandler()->nonDynamicData->findScriptByName(id.c_str());
			};

			// Bind function: tes3.getGlobal
			state["tes3"]["getGlobal"] = [](std::string& id) -> sol::object {
				TES3::GlobalVariable * global = tes3::getDataHandler()->nonDynamicData->findGlobalVariable(id.c_str());
				if (global != NULL) {
					return sol::make_object(LuaManager::getInstance().getState(), global->value);
				}
				return sol::nil;
			};

			// Bind function: tes3.setGlobal
			state["tes3"]["setGlobal"] = [](std::string& id, double value) {
				TES3::GlobalVariable * global = tes3::getDataHandler()->nonDynamicData->findGlobalVariable(id.c_str());
				if (global != NULL) {
					global->value = value;
				}
			};

			// Bind function: tes3.findGlobal
			state["tes3"]["findGlobal"] = [](std::string& id) {
				return tes3::getDataHandler()->nonDynamicData->findGlobalVariable(id.c_str());
			};

			// Bind function: tes3.getGMST
			state["tes3"]["getGMST"] = [](sol::object key) -> sol::object {
				sol::state& state = LuaManager::getInstance().getState();
				if (key.is<double>()) {
					int index = key.as<double>();
					if (index >= TES3::GMST::sMonthMorningstar && index <= TES3::GMST::sWitchhunter) {
						return sol::make_object(state, tes3::getDataHandler()->nonDynamicData->GMSTs[index]);
					}
				}
				else if (key.is<std::string>()) {
					int index = -1;
					std::string keyStr = key.as<std::string>();
					for (int i = 0; i <= TES3::GMST::sWitchhunter; i++) {
						TES3::GameSettingInfo* info = tes3::getGMSTInfo(i);
						if (strcmp(info->name, keyStr.c_str()) == 0) {
							index = i;
							break;
						}
					}

					if (index != -1) {
						return sol::make_object(state, tes3::getDataHandler()->nonDynamicData->GMSTs[index]);
					}
				}
				return sol::nil;
			};

			// Bind function: tes3.playSound
			state["tes3"]["playSound"] = [](sol::optional<sol::table> params) {
				// Get parameters.
				TES3::Sound* sound = getOptionalParamSound(params, "sound");
				TES3::Reference* reference = getOptionalParamReference(params, "reference");
				double volume = getOptionalParam<double>(params, "volume", 1.0);
				float pitch = getOptionalParam<double>(params, "pitch", 1.0);

				if (sound == NULL) {
					log::getLog() << "tes3.playSound: Could not locate sound." << std::endl;
					return false;
				}

				// Clamp volume. RIP no std::clamp.
				if (volume < 0) {
					volume = 0.0;
				}
				else if (volume > 1.0) {
					volume = 1.0;
				}

				tes3::getDataHandler()->addSound(sound, reference, 0, volume * 250, pitch);
				return true;
			};

			// Bind function: tes3.getSoundPlaying
			state["tes3"]["getSoundPlaying"] = [](sol::optional<sol::table> params) {
				// Get parameters.
				TES3::Sound* sound = getOptionalParamSound(params, "sound");
				TES3::Reference* reference = getOptionalParamReference(params, "reference");

				if (sound == NULL) {
					log::getLog() << "tes3.getSoundPlaying: Could not locate sound." << std::endl;
					return false;
				}

				return tes3::getDataHandler()->getSoundPlaying(sound, reference);
			};

			// Bind function: tes3.messageBox
			state["tes3"]["messageBox"] = [](sol::table params) {
				// We need to make sure the strings stay in memory, we can't just snag the c-string in passing.
				std::string buttonText[32];
				struct {
					const char* text[32] = {};
				} buttonTextStruct;

				//  Get the parameters out of the table and into the table.
				std::string message = params["message"];
				sol::optional<sol::table> maybeButtons = params["buttons"];
				if (maybeButtons && maybeButtons.value().size() > 0) {
					sol::table buttons = maybeButtons.value();
					size_t size = min(buttons.size(), 32);
					for (size_t i = 0; i < size; i++) {
						std::string result = buttons[i+1];
						if (result.empty()) {
							break;
						}

						buttonText[i] = result;
						buttonTextStruct.text[i] = buttonText[i].c_str();
					}
				}

				// No buttons, do a normal popup.
				else {
					return tes3::ui::messagePlayer(message.c_str());
				}

				// Set up our event callback.
				LuaManager::getInstance().setButtonPressedCallback(params["callback"]);

				// Temporary hook into the function that creates message boxes. 
				int result = reinterpret_cast<int(__cdecl *)(const char*, ...)>(0x5F1AA0)(message.c_str(), buttonTextStruct, NULL);
				return result;
			};

			// Bind function: tes3.saveGame
			state["tes3"]["saveGame"] = [](sol::optional<sol::table> params) {
				std::string fileName = getOptionalParam<std::string>(params, "file", "quiksave");
				std::string saveName = getOptionalParam<std::string>(params, "name", "Quicksave");

				tes3::getDataHandler()->nonDynamicData->saveGame(fileName.c_str(), saveName.c_str());
			};

			state["tes3"]["isModActive"] = [](std::string modName) {
				TES3::NonDynamicData* nonDynamicData = tes3::getDataHandler()->nonDynamicData;
				for (int i = 0; i < 256; i++) {
					TES3::GameFile* gameFile = nonDynamicData->activeMods[i];
					if (gameFile == NULL) {
						return false;
					}

					// Compare mod name with this active mod.
					if (_stricmp(gameFile->fileName, modName.c_str()) == 0) {
						return true;
					}
				}

				return false;
			};

			// Bind function: tes3.playItemPickupSound
			state["tes3"]["playItemPickupSound"] = [](sol::optional<sol::table> params) {
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Item* item = getOptionalParamObject<TES3::Item>(params, "item");
				bool pickup = getOptionalParam<bool>(params, "pickup", true);
				TES3::Sound* sound = getOptionalParamSound(params, "sound");
				if (item == NULL) {
					return;
				}

				tes3::getWorldController()->playItemUpDownSound(item, pickup, reference);
			};

			// Bind function: tes3.iterateList
			state["tes3"]["iterateObjects"] = sol::overload(&iterateObjects, &iterateObjectsFiltered);

			// Bind function: tes3.getSoundGenerator
			state["tes3"]["getSoundGenerator"] = [](std::string creatureId, unsigned int type) -> sol::object {
				auto soundGenerators = tes3::getDataHandler()->nonDynamicData->soundGenerators;
				const char* creatureIdCstr = creatureId.c_str();
				for (auto itt = soundGenerators->head; itt != NULL; itt = itt->next) {
					if (itt->data->soundType != type) {
						continue;
					}

					if (strncmp(creatureIdCstr, itt->data->name, creatureId.length()) == 0) {
						return sol::make_object(LuaManager::getInstance().getState(), itt->data);
					}
				}

				return sol::nil;
			};

			// Bind function: tes3.newGame
			state["tes3"]["newGame"] = []() {
				tes3::startNewGame();
			};

			// Bind function: tes3.getCameraVector
			// This function currently calls out to MGE, which should be changed at some point.
			state["tes3"]["getCameraVector"] = [](sol::optional<sol::table> params) {
				Stack& stack = Stack::getInstance();
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGEGetEyeVec);

				// Get the results from the MWSE stack.
				float x = stack.popFloat();
				float y = stack.popFloat();
				float z = stack.popFloat();

				return std::make_shared<TES3::Vector3>(x, y, z);
			};

			// Bind function: tes3.getCameraPosition
			state["tes3"]["getCameraPosition"] = [](sol::optional<sol::table> params) {
				return tes3::getWorldController()->worldCamera.camera->worldBoundOrigin;
			};

			// Bind function: tes3.getCameraPosition
			static NI::Pick* rayTestCache = NULL;
			state["tes3"]["rayTest"] = [](sol::optional<sol::table> params) -> sol::object {
				// Make sure we got our required position.
				TES3::Vector3* position = getOptionalParamVector3(params, "position");
				if (position == NULL) {
					return false;
				}

				// Make sure we got our required direction.
				TES3::Vector3* direction = getOptionalParamVector3(params, "direction");
				if (direction == NULL) {
					return false;
				}

				// Create our pick if it doesn't exist.
				if (rayTestCache == NULL) {
					rayTestCache = NI::Pick::malloc();
				}

				// Or clean up results otherwise.
				else {
					rayTestCache->clearResults();
				}

				// TODO: Allow specifying the root?
				rayTestCache->root = tes3::getGame()->worldRoot;

				// Are we finding all or the first?
				if (getOptionalParam<bool>(params, "findAll", false)) {
					rayTestCache->pickType = NI::PickType::FIND_ALL;
				}
				else {
					rayTestCache->pickType = NI::PickType::FIND_FIRST;
				}

				// Sort results by distance?
				if (getOptionalParam<bool>(params, "sort", true)) {
					rayTestCache->sortType = NI::PickSortType::SORT;
				}
				else {
					rayTestCache->sortType = NI::PickSortType::NO_SORT;
				}

				// Use triangle or model bounds for intersection?
				if (getOptionalParam<bool>(params, "useModelBounds", false)) {
					rayTestCache->intersectType = NI::PickIntersectType::BOUND_INTERSECT;
				}
				else {
					rayTestCache->intersectType = NI::PickIntersectType::TRIANGLE_INTERSECT;
				}

				// Use model coordinates or world coordinates?
				if (getOptionalParam<bool>(params, "useModelCoordinates", false)) {
					rayTestCache->coordinateType = NI::PickCoordinateType::MODEL_COORDINATES;
				}
				else {
					rayTestCache->coordinateType = NI::PickCoordinateType::WORLD_COORDINATES;
				}

				// Use the back side of a triangle? Note: Parameter name flipped!
				rayTestCache->frontOnly = !getOptionalParam<bool>(params, "useBackTriangles", false);

				// Observe app cull flag?
				rayTestCache->observeAppCullFlag = getOptionalParam<bool>(params, "observeAppCullFlag", true);

				// Determine what returned values we care about.
				rayTestCache->returnColor = getOptionalParam<bool>(params, "returnColor", false);
				rayTestCache->returnNormal = getOptionalParam<bool>(params, "returnNormal", true);
				rayTestCache->returnSmoothNormal = getOptionalParam<bool>(params, "returnSmoothNormal", false);
				rayTestCache->returnTexture = getOptionalParam<bool>(params, "returnTexture", false);

				// Our pick is configured. Let's run it!
				rayTestCache->pickObjects(position, direction);

				// Did we get any results?
				if (rayTestCache->results.filledCount == 0) {
					return sol::nil;
				}

				// Are we looking for a single result?
				else if (rayTestCache->pickType == NI::PickType::FIND_FIRST) {
					return sol::make_object(LuaManager::getInstance().getState(), rayTestCache->results.storage[0]);
				}

				// We're now in multi-result mode. We'll store these in a table.
				sol::state& state = LuaManager::getInstance().getState();
				sol::table results = state.create_table();
				
				// Go through and clone the results in a way that will play nice.
				for (int i = 0; i < rayTestCache->results.filledCount; i++) {
					results[i + 1] = rayTestCache->results.storage[i];
				}

				return results;
			};

			// Bind function: tes3.is3rdPerson
			state["tes3"]["is3rdPerson"] = []() {
				return tes3::getWorldController()->getMobilePlayer()->is3rdPerson();
			};

			// Bind function: tes3.tapKey
			state["tes3"]["tapKey"] = [](double key) {
				Stack::getInstance().pushLong(key);
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGETapKey);
			};

			// Bind function: tes3.pushKey
			state["tes3"]["pushKey"] = [](double key) {
				Stack::getInstance().pushLong(key);
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGEPushKey);
			};

			// Bind function: tes3.releaseKey
			state["tes3"]["releaseKey"] = [](double key) {
				Stack::getInstance().pushLong(key);
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGEReleaseKey);
			};

			// Bind function: tes3.hammerKey
			state["tes3"]["hammerKey"] = [](double key) {
				Stack::getInstance().pushLong(key);
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGEHammerKey);
			};

			// Bind function: tes3.unhammerKey
			state["tes3"]["unhammerKey"] = [](double key) {
				Stack::getInstance().pushLong(key);
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGEUnhammerKey);
			};

			// Bind function: tes3.enableKey
			state["tes3"]["enableKey"] = [](double key) {
				Stack::getInstance().pushLong(key);
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGEAllowKey);
			};

			// Bind function: tes3.disableKey
			state["tes3"]["disableKey"] = [](double key) {
				Stack::getInstance().pushLong(key);
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGEDisallowKey);
			};

			// Bind function: tes3.disableKey
			state["tes3"]["getTopMenu"] = []() {
				return tes3::ui::getTopMenu();
			};

			state["tes3"]["hasCodePatchFeature"] = [](int id) -> sol::object {
				if (!mcp::hasFeaturesFound()) {
					return sol::nil;
				}

				return sol::make_object(LuaManager::getInstance().getState(), mcp::getFeatureEnabled(id));
			};

			state["tes3"]["getDaysInMonth"] = [](int month) {
				return tes3::getWorldController()->getDaysInMonth(month);
			};

			state["tes3"]["getSimulationTimestamp"] = []() -> double {
				return tes3::getWorldController()->getHighPrecisionSimulationTimestamp();
			};

			state["tes3"]["getEquippedItem"] = [](sol::table params) -> sol::object {
				sol::state& state = LuaManager::getInstance().getState();

				// Find our equipment based on the object given.
				TES3::Iterator<TES3::EquipmentStack> * equipment = NULL;
				sol::object actor = params["actor"];
				if (actor.valid()) {
					if (actor.is<TES3::Reference*>()) {
						equipment = actor.as<TES3::Reference*>()->getEquipment();
					}
					else if (actor.is<TES3::MobileActor*>()) {
						equipment = actor.as<TES3::MobileActor*>()->reference->getEquipment();
					}
					else if (actor.is<TES3::Actor*>()) {
						equipment = &actor.as<TES3::Actor*>()->equipment;
					}
				}
				else {
					state["error"]("No actor provided.");
					return sol::nil;
				}

				// Make sure we got the equipment.
				if (equipment == NULL) {
					state["error"]("The provided actor's equipment could not be resolved.");
					return sol::nil;
				}

				// Get filter: Item Type
				std::tuple<bool, int> filterObjectType(false, INT_MAX);
				std::tuple<bool, int> filterSlot(false, INT_MAX);
				if (params["objectType"].valid()) {
					std::get<0>(filterObjectType) = true;
					std::get<1>(filterObjectType) = (int)params["objectType"];

					// Get filter: Item Slot/Type
					if (params["slot"].valid()) {
						std::get<0>(filterSlot) = true;
						std::get<1>(filterSlot) = (int)params["slot"];
					}
					else if (params["type"].valid()) {
						std::get<0>(filterSlot) = true;
						std::get<1>(filterSlot) = (int)params["type"];
					}
				}

				// Get filter: Item Enchanted
				std::tuple<bool, bool> filterEnchanted(false, false);
				if (params["enchanted"].valid()) {
					std::get<0>(filterEnchanted) = true;
					std::get<1>(filterEnchanted) = params["enchanted"];
				}

				// Loop through the items and pick the first one that matches our filters.
				for (auto itt = equipment->head; itt != NULL; itt = itt->next) {
					TES3::Object * object = itt->data->object;

					// Filter object type.
					if (std::get<0>(filterObjectType) && std::get<1>(filterObjectType) != object->objectType) {
						continue;
					}

					// Filter slot/type.
					if (std::get<0>(filterSlot) && std::get<1>(filterSlot) != object->getType()) {
						continue;
					}

					// Filter enchanted.
					if (std::get<0>(filterEnchanted)) {
						TES3::Enchantment * enchantment = object->getEnchantment();
						if (std::get<1>(filterEnchanted) == true && enchantment == NULL) {
							continue;
						}
						else if (std::get<1>(filterEnchanted) == false && enchantment != NULL) {
							continue;
						}
					}

					// If we got this far we match all filters. Return the object.
					return makeLuaObject(object);
				}

				return sol::nil;
			};

			state["tes3"]["getInputBinding"] = [](int code) -> TES3::InputConfig* {
				if (code < 0 || code > 33) {
					return NULL;
				}

				TES3::WorldController * worldController = tes3::getWorldController();
				if (worldController) {
					TES3::InputController * inputController = worldController->inputController;
					if (inputController) {
						return &inputController->inputMaps[4];
					}
				}
				return NULL;
			};
		}
	}
}
