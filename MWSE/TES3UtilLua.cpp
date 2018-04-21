#include "TES3UtilLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

#include "TES3Util.h"
#include "LuaUtil.h"
#include "Log.h"

namespace mwse {
	namespace lua {
		void bindTES3Util() {
			sol::state& state = LuaManager::getInstance().getState();

			//
			// Extend tes3 library with extra functions.
			//

			// Bind function: GetPlayerRef
			state["tes3"]["getPlayerRef"] = []() {
				return tes3::getWorldController()->getMobilePlayer()->reference;
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
			state["tes3"]["getObject"] = [](std::string& id) {
				return makeLuaObject(tes3::getDataHandler()->nonDynamicData->resolveObject(id.c_str()));
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

			state["tes3"]["messageBox"] = [](sol::table params) {
				// We need to make sure the strings stay in memory, we can't just snag the c-string in passing.
				std::string buttonText[32];
				struct {
					const char* text[32] = {};
				} buttonTextStruct;

				//  Get the parameters out of the table and into the table.
				std::string message = params["message"];
				sol::table buttons = params["buttons"];
				if (buttons.valid()) {
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

				// Temporary hook into the function that creates message boxes. 
				int result = reinterpret_cast<int(__cdecl *)(const char*, ...)>(0x5F1AA0)(message.c_str(), buttonTextStruct, NULL);
				return result;
			};
		}
	}
}
