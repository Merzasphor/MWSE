#include "TES3UtilLua.h"

#include <algorithm>
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
#include "NINode.h"
#include "NIPick.h"
#include "NIRTTI.h"
#include "NIStream.h"

#include "TES3Actor.h"
#include "TES3AudioController.h"
#include "TES3Cell.h"
#include "TES3Class.h"
#include "TES3CrimeTree.h"
#include "TES3DataHandler.h"
#include "TES3Dialogue.h"
#include "TES3DialogueInfo.h"
#include "TES3Door.h"
#include "TES3Fader.h"
#include "TES3Game.h"
#include "TES3GameSetting.h"
#include "TES3GlobalVariable.h"
#include "TES3InputController.h"
#include "TES3MobController.h"
#include "TES3MobileCreature.h"
#include "TES3MobilePlayer.h"
#include "TES3NPC.h"
#include "TES3Reference.h"
#include "TES3Region.h"
#include "TES3Script.h"
#include "TES3ScriptCompiler.h"
#include "TES3Sound.h"
#include "TES3SoundGenerator.h"
#include "TES3Spell.h"
#include "TES3SpellInstanceController.h"
#include "TES3UIElement.h"
#include "TES3UIMenuController.h"
#include "TES3Weather.h"
#include "TES3WeatherController.h"
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
			state["tes3"]["getPlayerRef"] = []() -> sol::object {
				TES3::WorldController* worldController = tes3::getWorldController();
				if (worldController) {
					TES3::MobilePlayer* mobilePlayer = worldController->getMobilePlayer();
					if (mobilePlayer) {
						return makeLuaObject(mobilePlayer->reference);
					}
				}
				return sol::nil;
			};

			// Bind function: tes3.getMobilePlayer
			state["tes3"]["getMobilePlayer"] = []() -> sol::object {
				TES3::WorldController* worldController = tes3::getWorldController();
				if (worldController) {
					return makeLuaObject(worldController->getMobilePlayer());
				}
				return sol::nil;
			};

			// Bind function: tes3.getPlayerCell()
			state["tes3"]["getPlayerCell"] = []() -> sol::object {
				TES3::DataHandler* dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					return makeLuaObject(dataHandler->currentCell);
				}
				return sol::nil;
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
			state["tes3"]["getPlayerTarget"] = []() -> sol::object {
				TES3::Game * game = tes3::getGame();
				if (game) {
					return makeLuaObject(game->playerTarget);
				}
				return sol::nil;
			};

			// Bind function: tes3.getReference
			state["tes3"]["getReference"] = [](sol::optional<const char*> id) {
				if (id) {
					return makeLuaObject(tes3::getReference(id.value()));
				}
				else {
					return makeLuaObject(LuaManager::getInstance().getCurrentReference());
				}
			};

			// Bind function: tes3.getObject
			state["tes3"]["getObject"] = [](const char* id) -> sol::object {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					return makeLuaObject(dataHandler->nonDynamicData->resolveObject(id));
				}
				return sol::nil;
			};

			state["tes3"]["deleteObject"] = [](sol::object maybe) {
				TES3::BaseObject* object = maybe.as<TES3::BaseObject*>();
				if (object) {
					tes3::getDataHandler()->nonDynamicData->deleteObject(object);
					object->vTable.base->destructor(object, true);
					return true;
				}
				return false;
			};

			// Bind function: tes3.getScript
			state["tes3"]["getScript"] = [](const char* id) -> sol::object {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					return makeLuaObject(dataHandler->nonDynamicData->findScriptByName(id));
				}
				return sol::nil;
			};

			// Bind function: tes3.getGlobal
			state["tes3"]["getGlobal"] = [](const char* id) -> sol::optional<float> {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					TES3::GlobalVariable * global = dataHandler->nonDynamicData->findGlobalVariable(id);
					if (global) {
						return global->value;
					}
				}
				return sol::optional<float>();
			};

			// Bind function: tes3.setGlobal
			state["tes3"]["setGlobal"] = [](std::string& id, double value) {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					TES3::GlobalVariable * global = dataHandler->nonDynamicData->findGlobalVariable(id.c_str());
					if (global) {
						global->value = value;
						return true;
					}
				}
				return false;
			};

			// Bind function: tes3.findGlobal
			state["tes3"]["findGlobal"] = [](const char* id) -> sol::object {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					return makeLuaObject(dataHandler->nonDynamicData->findGlobalVariable(id));
				}
				return sol::nil;
			};

			// Bind function: tes3.findGMST
			state["tes3"]["findGMST"] = [](sol::object key) -> sol::object {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler == nullptr) {
					return sol::nil;
				}

				if (key.is<double>()) {
					int index = key.as<double>();
					if (index >= TES3::GMST::sMonthMorningstar && index <= TES3::GMST::sWitchhunter) {
						return makeLuaObject(dataHandler->nonDynamicData->GMSTs[index]);
					}
				}
				else if (key.is<const char*>()) {
					int index = -1;
					const char* keyStr = key.as<const char*>();
					for (int i = 0; i <= TES3::GMST::sWitchhunter; i++) {
						if (strcmp(tes3::getGMSTInfo(i)->name, keyStr) == 0) {
							return makeLuaObject(dataHandler->nonDynamicData->GMSTs[i]);
						}
					}
				}

				return sol::nil;
			};

			// DEPRECATED: To be eventually redone after mods have transitioned away from it.
			state["tes3"]["getGMST"] = [](sol::object key) -> sol::object {
				mwse::log::getLog() << "WARNING: Use of deprecated function tes3.getGMST. Use tes3.findGMST instead." << std::endl;

				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler == nullptr) {
					return sol::nil;
				}

				sol::state& state = LuaManager::getInstance().getState();
				if (key.is<double>()) {
					int index = key.as<double>();
					if (index >= TES3::GMST::sMonthMorningstar && index <= TES3::GMST::sWitchhunter) {
						return makeLuaObject(dataHandler->nonDynamicData->GMSTs[index]);
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
						return makeLuaObject(dataHandler->nonDynamicData->GMSTs[index]);
					}
				}

				return sol::nil;
			};

			// Bind function: tes3.playSound
			state["tes3"]["playSound"] = [](sol::optional<sol::table> params) {
				// Get parameters.
				TES3::Sound* sound = getOptionalParamSound(params, "sound");
				TES3::Reference* reference = getOptionalParamReference(params, "reference");
				bool loop = getOptionalParam<bool>(params, "loop", false);
				int mix = getOptionalParam<int>(params, "mixChannel", int(TES3::AudioMixType::Effects));
				double volume = getOptionalParam<double>(params, "volume", 1.0);
				float pitch = getOptionalParam<double>(params, "pitch", 1.0);

				if (sound == nullptr) {
					log::getLog() << "tes3.playSound: Could not locate sound." << std::endl;
					return false;
				}

				// Clamp volume. RIP no std::clamp.
				volume = std::max(0.0, volume);
				volume = std::min(volume, 1.0);

				// Apply mix and rescale to 0-250
				volume *= 250.0 * tes3::getWorldController()->audioController->getMixVolume(TES3::AudioMixType(mix));

				tes3::getDataHandler()->addSound(sound, reference, loop ? TES3::SoundPlayFlags::Loop : 0, volume, pitch);
				return true;
			};

			// Bind function: tes3.getSoundPlaying
			state["tes3"]["getSoundPlaying"] = [](sol::optional<sol::table> params) {
				// Get parameters.
				TES3::Sound* sound = getOptionalParamSound(params, "sound");
				TES3::Reference* reference = getOptionalParamReference(params, "reference");

				if (sound == nullptr) {
					log::getLog() << "tes3.getSoundPlaying: Could not locate sound." << std::endl;
					return false;
				}

				return bool(tes3::getDataHandler()->getSoundPlaying(sound, reference));
			};

			// Bind function: tes3.adjustSoundVolume
			state["tes3"]["adjustSoundVolume"] = [](sol::optional<sol::table> params) {
				// Get parameters.
				TES3::Sound* sound = getOptionalParamSound(params, "sound");
				TES3::Reference* reference = getOptionalParamReference(params, "reference");
				int mix = getOptionalParam<int>(params, "mixChannel", int(TES3::AudioMixType::Effects));
				double volume = getOptionalParam<double>(params, "volume", 1.0);

				if (!sound || !reference) {
					log::getLog() << "tes3.adjustSoundVolume: Valid sound and reference required." << std::endl;
					return;
				}

				// Clamp volume.
				volume = std::max(0.0, volume);
				volume = std::min(volume, 1.0);

				// Apply mix and rescale to 0-250
				volume *= 250.0 * tes3::getWorldController()->audioController->getMixVolume(TES3::AudioMixType(mix));

				tes3::getDataHandler()->adjustSoundVolume(sound, reference, volume);
			};
			// Bind function: tes3.removeSound
			state["tes3"]["removeSound"] = [](sol::optional<sol::table> params) {
				// Get parameters.
				TES3::Sound* sound = getOptionalParamSound(params, "sound");
				TES3::Reference* reference = getOptionalParamReference(params, "reference");

				tes3::getDataHandler()->removeSound(sound, reference);
			};

			// Bind function: tes3.streamMusic
			state["tes3"]["streamMusic"] = [](sol::optional<sol::table> params) {
				// Get parameters.
				const char* relativePath = getOptionalParam<const char*>(params, "path", nullptr);
				int situation = getOptionalParam<int>(params, "situation", int(TES3::MusicSituation::Uninterruptible));
				double crossfade = getOptionalParam<double>(params, "crossfade", 1.0);

				if (relativePath) {
					auto w = tes3::getWorldController();
					char path[260];

					std::snprintf(path, sizeof(path), "Data Files/music/%s", relativePath);
					w->audioController->changeMusicTrack(path, 1000 * crossfade, 1.0);
					w->musicSituation = TES3::MusicSituation(situation);
				}
			};

			// Bind function: tes3.messageBox
			state["tes3"]["messageBox"] = [](sol::object param, sol::optional<sol::variadic_args> va) {
				if (param.is<std::string>()) {
					sol::state& state = LuaManager::getInstance().getState();
					std::string message = state["string"]["format"](param, va);
					return tes3::ui::messagePlayer(message.c_str());
				}
				else if (param.is<sol::table>()) {
					sol::table params = param;

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
						size_t size = std::min(buttons.size(), size_t(32));
						for (size_t i = 0; i < size; i++) {
							std::string result = buttons[i + 1];
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
				}

				return 0;
			};

			// Bind function: tes3.saveGame
			state["tes3"]["saveGame"] = [](sol::optional<sol::table> params) {
				const char* fileName = getOptionalParam<const char*>(params, "file", "quiksave");
				const char* saveName = getOptionalParam<const char*>(params, "name", "Quicksave");

				tes3::getDataHandler()->nonDynamicData->saveGame(fileName, saveName);
			};

			// Bind function: tes3.loadGame and tes3.loadGameMainMenu
			state["tes3"]["loadGame"] = [](const char* fileName) {
				// Char Gen State will equal 0 in the menu.
				if (tes3::getWorldController()->gvarCharGenState->value == 0)
				{
					tes3::getDataHandler()->nonDynamicData->loadGameMainMenu(fileName);
				}
				else
				{
					tes3::getDataHandler()->nonDynamicData->loadGame(fileName);
				}
			};

			// Bind function: tes3.isModActive
			state["tes3"]["isModActive"] = [](const char* modName) {
				TES3::DataHandler* dataHandler = tes3::getDataHandler();
				if (dataHandler == nullptr) {
					return false;
				}

				for (int i = 0; i < 256; i++) {
					TES3::GameFile* gameFile = dataHandler->nonDynamicData->activeMods[i];
					if (gameFile == nullptr) {
						return false;
					}

					// Compare mod name with this active mod.
					if (_stricmp(gameFile->filename, modName) == 0) {
						return true;
					}
				}

				return false;
			};

			// Bind function: tes3.getModList
			state["tes3"]["getModList"] = []() -> sol::object {
				sol::state& state = LuaManager::getInstance().getState();

				TES3::DataHandler* dataHandler = tes3::getDataHandler();
				if (dataHandler == nullptr) {
					return sol::nil;
				}

				sol::table mods = state.create_table();
				for (int i = 0; i < 256; i++) {
					TES3::GameFile* gameFile = dataHandler->nonDynamicData->activeMods[i];
					if (gameFile == nullptr) {
						break;
					}
					mods[i + 1] = static_cast<const char*>(gameFile->filename);
				}

				return mods;
			};

			// Bind function: tes3.playItemPickupSound
			state["tes3"]["playItemPickupSound"] = [](sol::optional<sol::table> params) {
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Item* item = getOptionalParamObject<TES3::Item>(params, "item");
				bool pickup = getOptionalParam<bool>(params, "pickup", true);
				if (item == NULL) {
					return;
				}

				tes3::getWorldController()->playItemUpDownSound(item, pickup, reference);
			};

			// Bind function: tes3.iterateList
			state["tes3"]["iterateObjects"] = sol::overload(&iterateObjects, &iterateObjectsFiltered);

			// Bind function: tes3.getSound
			state["tes3"]["getSound"] = [](const char* id) -> sol::object {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					return makeLuaObject(tes3::getDataHandler()->nonDynamicData->findSound(id));
				}
				else {
					sol::state& state = LuaManager::getInstance().getState();
					state["error"]("Function called before Data Handler was initialized.");
					return sol::nil;
				}
			};

			// Bind function: tes3.getSoundGenerator
			state["tes3"]["getSoundGenerator"] = [](std::string creatureId, unsigned int type) -> sol::object {
				auto soundGenerators = tes3::getDataHandler()->nonDynamicData->soundGenerators;
				const char* creatureIdCstr = creatureId.c_str();
				for (auto itt = soundGenerators->head; itt != NULL; itt = itt->next) {
					if (itt->data->soundType != static_cast<TES3::SoundType>(type)) {
						continue;
					}

					if (strncmp(creatureIdCstr, itt->data->name, creatureId.length()) == 0) {
						return makeLuaObject(itt->data);
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
			state["tes3"]["getCameraVector"] = []() {
				Stack& stack = Stack::getInstance();
				mwscript::RunOriginalOpCode(NULL, NULL, OpCode::MGEGetEyeVec);

				// Get the results from the MWSE stack.
				float x = stack.popFloat();
				float y = stack.popFloat();
				float z = stack.popFloat();

				return std::make_shared<TES3::Vector3>(x, y, z);
			};

			// Bind function: tes3.getCameraPosition
			state["tes3"]["getCameraPosition"] = [](sol::optional<sol::table> params) -> sol::optional<TES3::Vector3> {
				TES3::WorldController * worldController = tes3::getWorldController();
				if (worldController) {
					return worldController->worldCamera.camera->worldBoundOrigin;
				}
				return sol::optional<TES3::Vector3>();
			};

			// Bind function: tes3.getCameraPosition
			static NI::Pick* rayTestCache = nullptr;
			state["tes3"]["rayTest"] = [](sol::optional<sol::table> params) -> sol::object {
				// Make sure we got our required position.
				sol::optional<TES3::Vector3> position = getOptionalParamVector3(params, "position");
				if (!position) {
					return false;
				}

				// Make sure we got our required direction.
				sol::optional<TES3::Vector3> direction = getOptionalParamVector3(params, "direction");
				if (!direction) {
					return false;
				}

				// Create our pick if it doesn't exist.
				if (rayTestCache == nullptr) {
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
				rayTestCache->pickObjects(&position.value(), &direction.value());

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

			state["tes3"]["getDaysInMonth"] = [](int month) -> sol::object {
				TES3::WorldController * worldController = tes3::getWorldController();
				if (worldController) {
					return sol::make_object(LuaManager::getInstance().getState(), worldController->getDaysInMonth(month));
				}
				return sol::nil;
			};

			state["tes3"]["getSimulationTimestamp"] = []() -> sol::object {
				TES3::WorldController * worldController = tes3::getWorldController();
				if (worldController) {
					return sol::make_object(LuaManager::getInstance().getState(), worldController->getHighPrecisionSimulationTimestamp());
				}
				return sol::nil;
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
				sol::optional<int> filterObjectType;
				sol::optional<int> filterSlot;
				if (params["objectType"].valid()) {
					filterObjectType = (int)params["objectType"];

					// Get filter: Item Slot/Type
					if (params["slot"].valid()) {
						filterSlot = (int)params["slot"];
					}
					else if (params["type"].valid()) {
						filterSlot = (int)params["type"];
					}
				}

				// Get filter: Item Enchanted
				sol::optional<bool> filterEnchanted;
				if (params["enchanted"].valid()) {
					filterEnchanted = (bool)params["enchanted"];
				}

				// Loop through the items and pick the first one that matches our filters.
				for (auto itt = equipment->head; itt != nullptr; itt = itt->next) {
					TES3::Object * object = itt->data->object;

					// Filter object type.
					if (filterObjectType && filterObjectType.value() != object->objectType) {
						continue;
					}

					// Filter slot/type.
					if (filterSlot && filterSlot.value() != object->getType()) {
						continue;
					}

					// Filter enchanted.
					if (filterEnchanted) {
						TES3::Enchantment * enchantment = object->getEnchantment();
						if (filterEnchanted.value() == true && enchantment == nullptr) {
							continue;
						}
						else if (filterEnchanted.value() == false && enchantment != nullptr) {
							continue;
						}
					}

					// If we got this far we match all filters. Return the object.
					return sol::make_object(state, itt->data);
				}

				return sol::nil;
			};

			state["tes3"]["getInputBinding"] = [](int code) -> TES3::InputConfig* {
				if (code < TES3::KeyBind::FirstKey || code > TES3::KeyBind::LastKey) {
					return NULL;
				}

				TES3::WorldController * worldController = tes3::getWorldController();
				if (worldController) {
					TES3::InputController * inputController = worldController->inputController;
					if (inputController) {
						return &inputController->inputMaps[code];
					}
				}
				return NULL;
			};

			state["tes3"]["getRegion"] = []() -> sol::object {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					// Try to get the current cell's region first.
					if (dataHandler->currentCell) {
						TES3::Region * region = dataHandler->currentCell->getRegion();
						if (region) {
							return makeLuaObject(region);
						}
					}
					
					// Otherwise fall back to the last exterior cell's region.
					if (dataHandler->lastExteriorCell) {
						return makeLuaObject(dataHandler->lastExteriorCell->getRegion());
					}
				}

				return sol::nil;
			};

			state["tes3"]["getCurrentWeather"] = []() -> sol::object {
				TES3::WorldController * worldController = tes3::getWorldController();
				if (worldController) {
					return makeLuaObject(worldController->weatherController->currentWeather);
				}

				return sol::nil;
			};

			state["tes3"]["getCursorPosition"] = []() -> sol::object {
				TES3::WorldController * worldController = tes3::getWorldController();
				if (worldController) {
					sol::table results = LuaManager::getInstance().getState().create_table();
					results["x"] = worldController->mouseController->position.x;
					results["y"] = worldController->mouseController->position.z;
					return results;
				}

				return sol::nil;
			};

			state["tes3"]["getSkill"] = [](int skillID) -> sol::object {
				TES3::DataHandler * dataHandler = tes3::getDataHandler();
				if (dataHandler) {
					return makeLuaObject(&dataHandler->nonDynamicData->skills[skillID]);
				}

				return sol::nil;
			};

			state["tes3"]["removeEffects"] = [](sol::table params) {
				sol::state& state = LuaManager::getInstance().getState();
				
				TES3::Reference * reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					state["error"]("tes3.removeEffects: No reference parameter provided.");
					return;
				}
				
				int effect = getOptionalParam<int>(params, "effect", -1);
				int castType = getOptionalParam<int>(params, "castType", -1);
				int chance = getOptionalParam<int>(params, "chance", 100);
				if (chance > 100) {
					chance = 100;
				}
				else if (chance < 0) {
					chance = 0;
				}

				if (effect != -1) {
					tes3::getWorldController()->spellInstanceController->removeSpellsByEffect(reference, effect, chance);
				}
				else if (castType != -1) {
					bool removeSpell = getOptionalParam<bool>(params, "removeSpell", castType != int(TES3::SpellCastType::Spell));
					tes3::getWorldController()->spellInstanceController->clearSpellEffect(reference, castType, chance, removeSpell);
				}
				else {
					state["error"]("tes3.removeEffects: Must pass either 'effect' or 'castType' parameter!");
				}
			};

			state["tes3"]["getPlayerGold"] = []() -> int {
				auto player = tes3::getWorldController()->getMobilePlayer();
				return player->getGold();
			};

			state["tes3"]["triggerCrime"] = [](sol::table params) {
				sol::state& state = LuaManager::getInstance().getState();

				TES3::CrimeEvent crimeEvent;

				// Look at the given type.
				int crimeType = getOptionalParam<int>(params, "type", 3);
				if (crimeType < 1 || crimeType > 7) {
					state["error"]("Invalid type given. Value must be between 1 and 7.");
					return false;
				}
				crimeEvent.type = crimeType;

				// Also set the type string based on the crime committed.
				switch (crimeType) {
				case 1:
					crimeEvent.typeString = "attack";
					break;
				case 2:
					crimeEvent.typeString = "killing";
					break;
				case 3:
					crimeEvent.typeString = "stealing";
					break;
				case 4:
					crimeEvent.typeString = "pickpocket";
					crimeEvent.penalty = 25;
					break;
				case 5:
					crimeEvent.typeString = "theft";
					break;
				case 6:
					crimeEvent.typeString = "trespass";
					break;
				case 7:
					crimeEvent.typeString = "werewolf";
					break;
				}

				// Criminal is assumed to be the player if no value is supplied.
				TES3::MobileActor * criminal = getOptionalParamMobileActor(params, "criminal");
				if (criminal == nullptr) {
					criminal = tes3::getWorldController()->getMobilePlayer();
				}
				crimeEvent.criminal = criminal;

				// Set some basic crime event data.
				crimeEvent.timestamp = timeGetTime();
				crimeEvent.position = criminal->position;
				crimeEvent.penalty = getOptionalParam<int>(params, "value", crimeEvent.penalty);

				// Victim can be more complicated.
				sol::object victim = params["victim"];
				crimeEvent.victim = tes3::getWorldController()->getMobilePlayer();
				if (victim.is<TES3::Faction>()) {
					crimeEvent.victimFaction = victim.as<TES3::Faction*>();
				}
				else if (victim.is<TES3::Actor>()) {
					crimeEvent.victim = tes3::getWorldController()->getMobilePlayer();
					crimeEvent.victimFaction = victim.as<TES3::Actor*>()->getFaction();
					if (victim.is<TES3::NPC>()) {
						crimeEvent.victimBaseActor = victim.as<TES3::NPC*>();
					}
					else if (victim.is<TES3::NPCInstance>()) {
						crimeEvent.victimBaseActor = victim.as<TES3::NPCInstance*>()->baseNPC;
					}
				}
				else if (victim.is<TES3::MobileNPC>()) {
					TES3::MobileNPC * mach = victim.as<TES3::MobileNPC*>();
					crimeEvent.victim = mach;
					crimeEvent.victimFaction = mach->npcInstance->getFaction();
					crimeEvent.victimBaseActor = mach->npcInstance;
				}

				// Do detection and the like.
				bool forceDetection = getOptionalParam<bool>(params, "forceDetection", false);
				auto controller = tes3::getWorldController()->mobController->unknown_0x24;
				if (!forceDetection && controller->detectPresence(crimeEvent.criminal)) {
					controller->checkRadius(crimeEvent.victim, crimeEvent.unknown_0x34);
				}

				// If we were detected, add it to the list.
				if (forceDetection || crimeEvent.unknown_0x34->size) {
					auto v167 = crimeEvent.victim->unknown_0x1B0;
					auto v168 = v167->b;
					auto v169 = tes3::_new<TES3::CrimeTree>();
					auto v170 = v167;
					if (!v167) {
						v170 = v169;
					}
					v169->a = v170;
					auto v171 = v168;
					if (!v168) {
						v171 = v169;
					}
					v169->b = v171;
					v167->b = v169;
					v169->b->a = v169;
					auto v172 = &v169->data;
					if (v172) {
						v172->copy(&crimeEvent);
					}
					crimeEvent.victim->unknown_0x1B4++;
				}

				return true;
			};

			state["tes3"]["loadMesh"] = [](const char* relativePath) -> sol::object {
				std::string path = "Meshes\\";
				path += relativePath;

				return makeLuaNiPointer(tes3::getDataHandler()->nonDynamicData->loadMesh(path.c_str()));
			};

			state["tes3"]["playVoiceover"] = [](sol::table params) -> bool {
				sol::state& state = LuaManager::getInstance().getState();

				// Get the actor that we're going to make say something.
				auto actor = getOptionalParamMobileActor(params, "actor");
				if (actor == nullptr) {
					return false;
				}

				// Accept either a string or a number as the voiceover id.
				int voiceover = -1;
				sol::object voiceoverObject = params["voiceover"];
				if (voiceoverObject.is<const char*>()) {
					sol::object result = state["tes3"]["voiceover"][voiceoverObject.as<const char*>()];
					if (result.is<int>()) {
						voiceover = result.as<int>();
					}
				}
				else if (voiceoverObject.is<int>()) {
					voiceover = voiceoverObject.as<int>();
				}

				// Validate the input.
				if (voiceover < TES3::Voiceover::First || voiceover > TES3::Voiceover::Last) {
					return false;
				}

				actor->playVoiceover(voiceover);
				return true;
			};

			state["tes3"]["getLocked"] = [](sol::table params) -> bool {
				TES3::Reference * reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					return false;
				}

				auto node = tes3::getAttachedLockNode(reference);
				if (node == nullptr) {
					return false;
				}

				return node->locked;
			};

			state["tes3"]["setLockLevel"] = [](sol::table params) -> bool {
				TES3::Reference * reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					return false;
				}

				auto node = reference->getOrCreateLockNode();
				if (node == nullptr) {
					return false;
				}

				int level = getOptionalParam<int>(params, "level", -1);
				if (level >= 0) {
					node->lockLevel = level;
					return true;
				}

				return false;
			};

			state["tes3"]["getLockLevel"] = [](sol::table params) -> sol::optional<int> {
				TES3::Reference * reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					return sol::optional<int>();
				}

				auto node = tes3::getAttachedLockNode(reference);
				if (node == nullptr) {
					return sol::optional<int>();
				}

				return node->lockLevel;
			};

			state["tes3"]["lock"] = [](sol::table params) -> bool {
				auto reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					return false;
				}

				// Manage state for doors.
				if (reference->baseObject->objectType == TES3::ObjectType::Door) {
					// Clear door opening/closing flags.
					reference->clearActionFlag(TES3::ActionFlags::DoorOpening | TES3::ActionFlags::DoorClosing | TES3::ActionFlags::DoorJammedOpening | TES3::ActionFlags::DoorJammedClosing);

					// Reset orientation.
					auto orientationAttachment = tes3::getAttachment<TES3::NewOrientationAttachment>(reference, TES3::AttachmentType::NewOrientation);
					if (orientationAttachment) {
						orientationAttachment->orientation.z = reference->orientation.z;
					}

					// Update the scene graph with the new orientation.
					if (reference->sceneNode) {
						TES3::Matrix33 tempOutArg;
						reference->sceneNode->setLocalRotationMatrix(reference->updateSceneMatrix(&tempOutArg));
						reference->sceneNode->propagatePositionChange();
					}
				}

				// Get or create our lock node.
				auto lockNode = reference->getOrCreateLockNode();
				if (lockNode == nullptr) {
					return false;
				}

				// Set the lock level if one was provided.
				int lockLevel = getOptionalParam<int>(params, "level", -1);
				if (lockLevel >= 0) {
					lockNode->lockLevel = lockLevel;
				}

				// Set the locked state, and return true if it changed.
				reference->setObjectModified(true);
				if (!lockNode->locked) {
					lockNode->locked = true;
					return true;
				}
				else {
					return false;
				}
			};

			state["tes3"]["unlock"] = [](sol::table params) -> bool {
				TES3::Reference * reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					return false;
				}

				auto node = tes3::getAttachedLockNode(reference);
				if (node == nullptr) {
					return false;
				}

				if (node->locked) {
					node->locked = false;
					return true;
				}
				else {
					return false;
				}
			};

			state["tes3"]["getTrap"] = [](sol::table params) -> TES3::Spell* {
				TES3::Reference * reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					return nullptr;
				}

				auto node = tes3::getAttachedLockNode(reference);
				if (node == nullptr) {
					return nullptr;
				}

				return node->trap;
			};

			state["tes3"]["setTrap"] = [](sol::table params) -> bool {
				auto reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					return false;
				}

				// Only accept doors.
				TES3::Door* door = reinterpret_cast<TES3::Door*>(reference->baseObject);
				if (door->objectType != TES3::ObjectType::Door) {
					return false;
				}

				// Get or create our lock node.
				auto lockNode = reference->getOrCreateLockNode();
				if (lockNode == nullptr) {
					return false;
				}

				lockNode->trap = getOptionalParamSpell(params, "spell");
				return true;
			};

			state["tes3"]["checkMerchantTradesItem"] = [](sol::table params) -> bool {
				auto reference = getOptionalParamExecutionReference(params);
				if (reference == nullptr) {
					return false;
				}

				TES3::Item* item = getOptionalParamObject<TES3::Item>(params, "item");
				if (item == nullptr) {
					return false;
				}

				auto enchantment = item->getEnchantment();
				if (enchantment) {
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersEnchantedItems);
				}

				switch (item->objectType) {
				case TES3::ObjectType::Alchemy:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersAlchemy);
				case TES3::ObjectType::Apparatus:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersApparatus);
				case TES3::ObjectType::Armor:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersArmor);
				case TES3::ObjectType::Book:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersBooks);
				case TES3::ObjectType::Clothing:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersClothing);
				case TES3::ObjectType::Ingredient:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersIngredients);
				case TES3::ObjectType::Light:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersLights);
				case TES3::ObjectType::Lockpick:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersLockpicks);
				case TES3::ObjectType::Misc:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersMiscItems);
				case TES3::ObjectType::Probe:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersProbes);
				case TES3::ObjectType::Repair:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersRepairTools);
				case TES3::ObjectType::Weapon:
				case TES3::ObjectType::Ammo:
					return (reference->getAIConfig()->merchantFlags & TES3::ServiceFlag::BartersWeapons);
				}

				return false;
			};

			state["tes3"]["getJournalIndex"] = [](sol::table params) -> sol::optional<int> {
				TES3::Dialogue * journal = getOptionalParamDialogue(params, "id");
				if (journal == nullptr || journal->type != TES3::DialogueType::Journal) {
					return sol::optional<int>();
				}

				return journal->journalIndex;
			};

			state["tes3"]["setJournalIndex"] = [](sol::table params) -> bool {
				TES3::Dialogue * journal = getOptionalParamDialogue(params, "id");
				if (journal == nullptr || journal->type != TES3::DialogueType::Journal) {
					return false;
				}

				sol::optional<int> index = params["index"];
				if (!index) {
					return false;
				}

				if (!journal->setJournalIndex(index.value())) {
					return false;
				}

				sol::optional<bool> showMessage = params["showMessage"];
				if (showMessage.value_or(false) && tes3::ui::getMenuNode(*reinterpret_cast<short*>(0x7D3442)) == nullptr) {
					tes3::ui::messagePlayer(tes3::getDataHandler()->nonDynamicData->GMSTs[TES3::GMST::sJournalEntry]->value.asString);
				}

				return true;
			};

			state["tes3"]["updateJournal"] = [](sol::table params) -> bool {
				TES3::Dialogue * journal = getOptionalParamDialogue(params, "id");
				if (journal == nullptr || journal->type != TES3::DialogueType::Journal) {
					return false;
				}

				sol::optional<int> index = params["index"];
				if (!index) {
					return false;
				}

				TES3::MobileActor * actor = getOptionalParamMobileActor(params, "speaker");
				if (actor == nullptr) {
					actor = tes3::getWorldController()->getMobilePlayer();
				}

				if (!journal->addToJournal(index.value(), actor)) {
					return false;
				}

				sol::optional<bool> showMessage = params["showMessage"];
				if (showMessage.value_or(true) && tes3::ui::getMenuNode(*reinterpret_cast<short*>(0x7D3442)) == nullptr) {
					tes3::ui::messagePlayer(tes3::getDataHandler()->nonDynamicData->GMSTs[TES3::GMST::sJournalEntry]->value.asString);
				}

				return true;
			};

			state["tes3"]["getFileExists"] = [](const char* path) {
				return tes3::resolveAssetPath(path) != 0;
			};

			state["tes3"]["getFileSource"] = [](const char* path) -> sol::optional<std::tuple<std::string, std::string>> {
				char buffer[512];
				int result = tes3::resolveAssetPath(path, buffer);

				if (result == 1) {
					return std::make_tuple("file", buffer);
				}
				else if (result == 2) {
					return std::make_tuple("bsa", buffer);
				}

				return sol::optional<std::tuple<std::string, std::string>>();
			};

			// Very slow method to get an INFO record by its ID.
			state["tes3"]["getDialogueInfo"] = [](sol::table params) -> sol::object {
				TES3::Dialogue * dialogue = getOptionalParamDialogue(params, "dialogue");
				const char * id = getOptionalParam<const char*>(params, "id", nullptr);
				if (dialogue == nullptr || id == nullptr) {
					return sol::nil;
				}

				for (auto itt = dialogue->info.head; itt; itt = itt->next) {
					auto dialogueInfo = itt->data;
					if (!dialogueInfo->loadId()) {
						continue;
					}

					if (_strcmpi(id, dialogueInfo->loadLinkNode->name) == 0) {
						dialogueInfo->unloadId();
						return makeLuaObject(dialogueInfo);
					}

					dialogueInfo->unloadId();
				}

				return sol::nil;
			};

			// Very slow method to get an INFO record by its ID.
			state["tes3"]["getCell"] = [](sol::table params) -> sol::object {
				// If we were given a name, try that.
				sol::optional<const char*> cellId = params["id"];
				if (cellId) {
					return makeLuaObject(tes3::getDataHandler()->nonDynamicData->getCellByName(cellId.value()));
				}

				// Otherwise try to use X/Y.
				return makeLuaObject(tes3::getDataHandler()->nonDynamicData->getCellByGrid(params["x"], params["y"]));
			};

			state["tes3"]["fadeIn"] = [](sol::optional<sol::table> params) {
				TES3::Fader * fader = getOptionalParam(params, "fader", tes3::getWorldController()->transitionFader);
				if (fader == nullptr) {
					return;
				}

				float duration = getOptionalParam(params, "duration", 1.0f);
				fader->fadeTo(0.0f, duration);
			};

			state["tes3"]["fadeOut"] = [](sol::optional<sol::table> params) {
				TES3::Fader * fader = getOptionalParam(params, "fader", tes3::getWorldController()->transitionFader);
				if (fader == nullptr) {
					return;
				}

				float duration = getOptionalParam(params, "duration", 1.0f);
				fader->fadeTo(1.0f, duration);
			};

			state["tes3"]["fadeTo"] = [](sol::optional<sol::table> params) {
				TES3::Fader * fader = getOptionalParam(params, "fader", tes3::getWorldController()->transitionFader);
				if (fader == nullptr) {
					return;
				}

				float value = getOptionalParam(params, "value", 1.0f);
				float duration = getOptionalParam(params, "duration", 1.0f);
				fader->fadeTo(value, duration);
			};

			state["tes3"]["setStatistic"] = [](sol::table params) {
				sol::state& state = LuaManager::getInstance().getState();

				// Figure out our mobile object, in case someone gives us a reference instead.
				sol::userdata maybeMobile = params["reference"];
				if (maybeMobile.is<TES3::Reference>()) {
					maybeMobile = maybeMobile["mobile"];
				}

				// Make sure our object is of the right type.
				if (!maybeMobile.is<TES3::MobileActor>()) {
					mwse::log::getLog() << "tes3.setStatistic: Could not resolve parameter 'reference'." << std::endl;
					state["debug"]["traceback"]();
					return;
				}

				// Try to get our statistic.
				TES3::MobileActor * mobile = maybeMobile.as<TES3::MobileActor*>();
				TES3::Statistic * statistic = nullptr;
				sol::optional<const char*> statisticName = params["name"];
				sol::optional<int> statisticSkill = params["skill"];
				sol::optional<int> statisticAttribute = params["attribute"];
				if (statisticSkill) {
					if (mobile->actorType == TES3::MobileActorType::Creature) {
						if (statisticSkill.value() >= TES3::CreatureSkillID::FirstSkill && statisticSkill.value() <= TES3::CreatureSkillID::LastSkill) {
							statistic = &static_cast<TES3::MobileCreature*>(mobile)->skills[statisticSkill.value()];
						}
						else {
							mwse::log::getLog() << "tes3.setStatistic: Invalid skill index " << std::dec << statisticSkill.value() << " for creature." << std::endl;
							state["debug"]["traceback"]();
							return;
						}
					}
					else {
						if (statisticSkill.value() >= TES3::SkillID::FirstSkill && statisticSkill.value() <= TES3::SkillID::LastSkill) {
							statistic = &static_cast<TES3::MobileNPC*>(mobile)->skills[statisticSkill.value()];
						}
						else {
							mwse::log::getLog() << "tes3.setStatistic: Invalid skill index " << std::dec << statisticSkill.value() << " for NPC." << std::endl;
							state["debug"]["traceback"]();
							return;
						}
					}
				}
				else if (statisticAttribute) {
					if (statisticAttribute.value() >= TES3::Attribute::FirstAttribute && statisticAttribute.value() <= TES3::Attribute::LastAttribute) {
						statistic = &mobile->attributes[statisticAttribute.value()];
					}
					else {
						mwse::log::getLog() << "tes3.setStatistic: Invalid attribute index " << std::dec << statisticSkill.value() << "." << std::endl;
						state["debug"]["traceback"]();
						return;
					}
				}
				else if (statisticName) {
					sol::optional<TES3::Statistic*> maybeStatistic = maybeMobile[statisticName.value()];
					if (maybeStatistic) {
						statistic = maybeStatistic.value();
					}
					else {
						mwse::log::getLog() << "tes3.setStatistic: No statistic with the given criteria could be found." << std::endl;
						state["debug"]["traceback"]();
						return;
					}
				}

				// This case shouldn't be hit.
				if (statistic == nullptr) {
					mwse::log::getLog() << "tes3.setStatistic: No statistic resolved." << std::endl;
					state["debug"]["traceback"]();
					return;
				}

				// Retype our variables to something more friendly, and get additional params.
				sol::optional<bool> limit = params["limit"];

				sol::optional<float> current = params["current"];
				sol::optional<float> base = params["base"];
				sol::optional<float> value = params["value"];

				// Edit both.
				if (value) {
					statistic->setBaseAndCurrent(value.value());
				}
				// If we're given a current value, modify it.
				else if (current) {
					statistic->setCurrentCapped(current.value(), limit.value_or(false));
				}
				// If we're given a base value, modify it.
				else if (base) {
					statistic->setBase(base.value());
				}
				else {
					mwse::log::getLog() << "tes3.setStatistic: No edit mode provided, missing parameter 'current' or 'base' or 'value'." << std::endl;
					state["debug"]["traceback"]();
					return;
				}

				// Update any derived statistics.
				mobile->updateDerivedStatistics(statistic);

				// If this was on the player update any associated GUI widgets.
				if (mobile->actorType == TES3::MobileActorType::Player) {
					// Update main HUD elements.
					if (statistic == &mobile->health) {
						reinterpret_cast<void(__cdecl*)(float, float)>(0x50FBB0)(statistic->current, statistic->base);
					}
					else if (statistic == &mobile->magicka) {
						reinterpret_cast<void(__cdecl*)(float, float)>(0x50FBD0)(statistic->current, statistic->base);
					}
					else if (statistic == &mobile->fatigue) {
						reinterpret_cast<void(__cdecl*)(float, float)>(0x50FBF0)(statistic->current, statistic->base);
					}

					tes3::ui::updateStatsPane();
				}
			};

			state["tes3"]["modStatistic"] = [](sol::table params) {
				sol::state& state = LuaManager::getInstance().getState();

				// Figure out our mobile object, in case someone gives us a reference instead.
				sol::userdata maybeMobile = params["reference"];
				if (maybeMobile.is<TES3::Reference>()) {
					maybeMobile = maybeMobile["mobile"];
				}

				// Make sure our object is of the right type.
				if (!maybeMobile.is<TES3::MobileActor>()) {
					mwse::log::getLog() << "tes3.modStatistic: Could not resolve parameter 'reference'." << std::endl;
					state["debug"]["traceback"]();
					return;
				}

				// Try to get our statistic.
				TES3::MobileActor * mobile = maybeMobile.as<TES3::MobileActor*>();
				TES3::Statistic * statistic = nullptr;
				sol::optional<const char*> statisticName = params["name"];
				sol::optional<int> statisticSkill = params["skill"];
				sol::optional<int> statisticAttribute = params["attribute"];
				if (statisticSkill) {
					if (mobile->actorType == TES3::MobileActorType::Creature) {
						if (statisticSkill.value() >= TES3::CreatureSkillID::FirstSkill && statisticSkill.value() <= TES3::CreatureSkillID::LastSkill) {
							statistic = &static_cast<TES3::MobileCreature*>(mobile)->skills[statisticSkill.value()];
						}
						else {
							mwse::log::getLog() << "tes3.modStatistic: Invalid skill index " << std::dec << statisticSkill.value() << " for creature." << std::endl;
							state["debug"]["traceback"]();
							return;
						}
					}
					else {
						if (statisticSkill.value() >= TES3::SkillID::FirstSkill && statisticSkill.value() <= TES3::SkillID::LastSkill) {
							statistic = &static_cast<TES3::MobileNPC*>(mobile)->skills[statisticSkill.value()];
						}
						else {
							mwse::log::getLog() << "tes3.modStatistic: Invalid skill index " << std::dec << statisticSkill.value() << " for NPC." << std::endl;
							state["debug"]["traceback"]();
							return;
						}
					}
				}
				else if (statisticAttribute) {
					if (statisticAttribute.value() >= TES3::Attribute::FirstAttribute && statisticAttribute.value() <= TES3::Attribute::LastAttribute) {
						statistic = &mobile->attributes[statisticAttribute.value()];
					}
					else {
						mwse::log::getLog() << "tes3.modStatistic: Invalid attribute index " << std::dec << statisticSkill.value() << "." << std::endl;
						state["debug"]["traceback"]();
						return;
					}
				}
				else if (statisticName) {
					sol::optional<TES3::Statistic*> maybeStatistic = maybeMobile[statisticName.value()];
					if (maybeStatistic) {
						statistic = maybeStatistic.value();
					}
					else {
						mwse::log::getLog() << "tes3.modStatistic: No statistic with the given criteria could be found." << std::endl;
						state["debug"]["traceback"]();
						return;
					}
				}

				// This case shouldn't be hit.
				if (statistic == nullptr) {
					mwse::log::getLog() << "tes3.modStatistic: No statistic resolved." << std::endl;
					state["debug"]["traceback"]();
					return;
				}

				// Retype our variables to something more friendly, and get additional params.
				sol::optional<bool> limit = params["limit"];

				sol::optional<float> current = params["current"];
				sol::optional<float> base = params["base"];
				sol::optional<float> value = params["value"];

				// Edit both.
				if (value) {
					statistic->modBaseCapped(value.value(), limit.value_or(false), limit.value_or(false));
					statistic->modCurrentCapped(value.value(), limit.value_or(false), limit.value_or(false), limit.value_or(false));
				}
				// If we're given a current value, modify it.
				else if (current) {
					statistic->modCurrentCapped(current.value(), limit.value_or(false), limit.value_or(false), limit.value_or(false));
				}
				// If we're given a base value, modify it.
				else if (base) {
					statistic->modBaseCapped(base.value(), limit.value_or(false), limit.value_or(false));
				}
				else {
					mwse::log::getLog() << "tes3.modStatistic: No edit mode provided, missing parameter 'current' or 'base' or 'value'." << std::endl;
					state["debug"]["traceback"]();
					return;
				}

				// Update any derived statistics.
				mobile->updateDerivedStatistics(statistic);

				// If this was on the player update any associated GUI widgets.
				if (mobile->actorType == TES3::MobileActorType::Player) {
					if (statistic == &mobile->health) {
						reinterpret_cast<void(__cdecl*)(float, float)>(0x50FBB0)(statistic->current, statistic->base);
					}
					else if (statistic == &mobile->magicka) {
						reinterpret_cast<void(__cdecl*)(float, float)>(0x50FBD0)(statistic->current, statistic->base);
					}
					else if (statistic == &mobile->fatigue) {
						reinterpret_cast<void(__cdecl*)(float, float)>(0x50FBF0)(statistic->current, statistic->base);
					}

					tes3::ui::updateStatsPane();
				}
			};

			state["tes3"]["runLegacyScript"] = [](sol::table params) {
				TES3::Script * script = getOptionalParamScript(params, "script");
				if (script == nullptr) {
					script = tes3::getWorldController()->scriptGlobals;
				}

				TES3::ScriptCompiler * compiler = tes3::getWorldController()->menuController->scriptCompiler;
				int source = getOptionalParam<int>(params, "source", TES3::CompilerSource::Default);
				if (source < TES3::CompilerSource::FirstSource || source > TES3::CompilerSource::LastSource) {
					return false;
				}

				const char* command = getOptionalParam<const char*>(params, "command", nullptr);
				if (command == nullptr) {
					return false;
				}

				TES3::ScriptVariables * variables = getOptionalParam<TES3::ScriptVariables*>(params, "variables", nullptr);

				TES3::Reference * reference = getOptionalParamExecutionReference(params);
				if (reference && variables == nullptr) {
					variables = reference->getScriptVariables();
				}

				TES3::Dialogue * dialogue = getOptionalParamDialogue(params, "dialogue");
				TES3::DialogueInfo * dialogueInfo = getOptionalParam< TES3::DialogueInfo*>(params, "info", nullptr);
				if (dialogue == nullptr || dialogueInfo == nullptr) {
					dialogue = nullptr;
					dialogueInfo = nullptr;
					source = TES3::CompilerSource::Default;
				}
				else {
					source = TES3::CompilerSource::Dialogue;
				}

				script->doCommand(compiler, command, source, reference, variables, dialogueInfo, dialogue);
				return true;
			};

			state["tes3"]["getActiveCells"] = []() -> sol::object {
				auto dataHandler = tes3::getDataHandler();
				if (dataHandler == nullptr) {
					return sol::nil;
				}

				sol::state& state = LuaManager::getInstance().getState();
				sol::table result = state.create_table();

				if (dataHandler->currentInteriorCell) {
					result[1] = makeLuaObject(dataHandler->currentInteriorCell);
				}
				else {
					int exteriorCount = 0;
					for (size_t i = 0; i < 9; i++) {
						auto cellDataPointer = dataHandler->exteriorCellData[i];
						if (cellDataPointer && cellDataPointer->size >= 1) {
							exteriorCount++;
							result[exteriorCount] = makeLuaObject(cellDataPointer->cell);
						}
					}
				}

				return result;
			};

			state["tes3"]["positionCell"] = [](sol::table params) {
				auto worldController = tes3::getWorldController();
				auto macp = worldController->getMobilePlayer();

				// Get the target that we're working with.
				TES3::MobileActor * mobile = getOptionalParamMobileActor(params, "reference");
				if (mobile == nullptr) {
					mobile = macp;
				}

				// Get the position.
				sol::optional<TES3::Vector3> position = getOptionalParamVector3(params, "position");
				if (!position) {
					return false;
				}

				// Get the orientation.
				sol::optional<TES3::Vector3> orientation = getOptionalParamVector3(params, "orientation");
				if (!orientation) {
					return false;
				}

				// Get the cell.
				TES3::Cell * cell = getOptionalParamCell(params, "cell");
				if (cell == nullptr) {
					return false;
				}

				// Are we dealing with the player? If so, use the special functions.
				if (mobile == macp) {
					sol::optional<bool> teleportCompanions = params["teleportCompanions"];
					if (teleportCompanions.value_or(true) && macp->listFriendlyActors.size > 0) {
						reinterpret_cast<void(__cdecl*)(TES3::Vector3, TES3::Vector3, TES3::Cell*)>(0x45C9B0)(position.value(), orientation.value(), cell);
					}
					else {
						sol::optional<bool> flag = params["flag"];
						reinterpret_cast<void(__cdecl*)(TES3::Vector3, TES3::Vector3, TES3::Cell*, int)>(0x45CEF0)(position.value(), orientation.value(), cell, flag.value());
					}
				}
				else {
					reinterpret_cast<void(__cdecl*)(TES3::Reference*, TES3::Cell*, TES3::Vector3*, float)>(0x50EDD0)(mobile->reference, cell, &position.value(), orientation.value().z);
				}

				return true;
			};

			state["tes3"]["getLanguageCode"] = []() {
				return reinterpret_cast<int(__stdcall*)()>(0x4678F0)();
			};

			state["tes3"]["getLanguage"] = []() -> sol::optional<std::string> {
				int language = reinterpret_cast<int(__stdcall*)()>(0x4678F0)();

				switch (language) {
				case 0:
					return "eng";
				case 1:
					return "fra";
				case 2:
					return "deu";
				case 3:
					return "rus";
				}

				return sol::optional<std::string>();
			};

			state["tes3"]["addSoulGem"] = [](sol::table params) {
				TES3::Misc * item = getOptionalParamObject<TES3::Misc>(params, "item");
				if (item == nullptr) {
					return false;
				}

				auto data = mwse::tes3::addCustomSoulGem(item);
				if (data == nullptr) {
					return false;
				}

				return true;
			};
		}
	}
}
