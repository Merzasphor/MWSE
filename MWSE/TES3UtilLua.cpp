#include "TES3UtilLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

#include "TES3GameFile.h"

#include "TES3Util.h"
#include "UIUtil.h"
#include "LuaUtil.h"
#include "Log.h"

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
			state["tes3"]["getPlayerRef"] = []() {
				return tes3::getWorldController()->getMobilePlayer()->reference;
			};

			// Bind function: tes3.getMobilePlayer
			state["tes3"]["getMobilePlayer"] = []() {
				return tes3::getWorldController()->getMobilePlayer();
			};

			// Bind function: tes3.getPlayerCell()
			state["tes3"]["getPlayerCell"] = []() {
				return tes3::getDataHandler()->currentCell;
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
			state["tes3"]["getGlobal"] = [](std::string& id) {
				return tes3::getDataHandler()->nonDynamicData->findGlobalVariable(id.c_str())->value;
			};

			// Bind function: tes3.setGlobal
			state["tes3"]["setGlobal"] = [](std::string& id, double value) {
				tes3::getDataHandler()->nonDynamicData->findGlobalVariable(id.c_str())->value = value;
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
				TES3::BaseObject* item = getOptionalParamObject<TES3::BaseObject>(params, "item");
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
		}
	}
}
