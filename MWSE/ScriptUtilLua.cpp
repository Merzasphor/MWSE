#include "ScriptUtilLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Util.h"
#include "ScriptUtil.h"

#include "TES3Script.h"
#include "TES3Reference.h"

namespace mwse {
	namespace lua {
		TES3::Script* getScriptParam(sol::table params) {
			TES3::Script* script = NULL;
			sol::object maybeScript = params["_script"];
			if (maybeScript.valid() && maybeScript.is<TES3::Script*>()) {
				script = maybeScript.as<TES3::Script*>();
			}
			else {
				script = LuaManager::getInstance().getCurrentScript();
			}
			return script;
		}

		TES3::Reference* getReferenceParam(sol::table params) {
			TES3::Reference* reference = NULL;
			sol::object maybe = params["reference"];
			if (maybe.valid() && maybe.is<TES3::Reference*>()) {
				reference = maybe.as<TES3::Reference*>();
			}
			else {
				reference = LuaManager::getInstance().getCurrentReference();
			}
			return reference;
		}

		void bindScriptUtil() {
			sol::state& state = LuaManager::getInstance().getState();

			//
			// Get context on the current execution.
			//

			state["mwscript"]["getScript"] = []() {
				return LuaManager::getInstance().getCurrentScript();
			};

			state["mwscript"]["getReference"] = []() {
				return LuaManager::getInstance().getCurrentReference();
			};

			//
			// Expose base game opcodes.
			//

			state["mwscript"]["activate"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = NULL;
				TES3::Reference* reference = NULL;

				// Resolve our optional parameters.
				if (params) {
					script = getScriptParam(params.value());
					reference = getReferenceParam(params.value());
				}
				else {
					LuaManager& manager = LuaManager::getInstance();
					script = manager.getCurrentScript();
					reference = manager.getCurrentReference();
				}

				mwscript::Activate(script, reference);
			};

			state["mwscript"]["addItem"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve item.
				sol::object itemParam = params["item"];
				TES3::BaseObject* item = NULL;
				if (itemParam.is<std::string>()) {
					item = tes3::getTemplate(itemParam.as<std::string>());
				}
				else if (itemParam.is<TES3::BaseObject*>()) {
					item = itemParam.as<TES3::BaseObject*>();
				}

				if (item == NULL) {
					return false;
				}

				// Resolve count.
				sol::object countParam = params["count"];
				long count = 1;
				if (countParam.is<double>()) {
					count = countParam.as<double>();
				}

				mwscript::AddItem(script, reference, item, count);
				return true;
			};

			state["mwscript"]["addSpell"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve spell.
				sol::object spellParam = params["spell"];
				TES3::Spell* spell = NULL;
				if (spellParam.is<std::string>()) {
					spell = tes3::getObjectByID<TES3::Spell>(spellParam.as<std::string>(), TES3::ObjectType::Spell);
				}
				else if (spellParam.is<TES3::Spell*>()) {
					spell = spellParam.as<TES3::Spell*>();
				}

				if (spell == NULL) {
					return false;
				}

				mwscript::AddSpell(script, reference, spell);
				return true;
			};

			state["mwscript"]["aiTravel"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve X.
				sol::object xParam = params["x"];
				float x = 0.0f;
				if (xParam.is<double>()) {
					x = xParam.as<double>();
				}

				// Resolve Y.
				sol::object yParam = params["y"];
				float y = 0.0f;
				if (yParam.is<double>()) {
					y = yParam.as<double>();
				}

				// Resolve Z.
				sol::object zParam = params["z"];
				float z = 0.0f;
				if (zParam.is<double>()) {
					z = zParam.as<double>();
				}

				mwscript::AITravel(script, reference, x, y, z);
				return true;
			};

			state["mwscript"]["drop"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve item.
				sol::object itemParam = params["item"];
				TES3::BaseObject* item = NULL;
				if (itemParam.is<std::string>()) {
					item = tes3::getTemplate(itemParam.as<std::string>());
				}
				else if (itemParam.is<TES3::BaseObject*>()) {
					item = itemParam.as<TES3::BaseObject*>();
				}

				if (item == NULL) {
					return false;
				}

				// Resolve count.
				sol::object countParam = params["count"];
				long count = 1;
				if (countParam.is<double>()) {
					count = countParam.as<double>();
				}

				mwscript::Drop(script, reference, item, count);
				return true;
			};

			state["mwscript"]["equip"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve item.
				sol::object itemParam = params["item"];
				TES3::BaseObject* item = NULL;
				if (itemParam.is<std::string>()) {
					item = tes3::getTemplate(itemParam.as<std::string>());
				}
				else if (itemParam.is<TES3::BaseObject*>()) {
					item = itemParam.as<TES3::BaseObject*>();
				}

				if (item == NULL) {
					return false;
				}

				mwscript::Equip(script, reference, item);
				return true;
			};

			state["mwscript"]["explodeSpell"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve spell.
				sol::object spellParam = params["spell"];
				TES3::Spell* spell = NULL;
				if (spellParam.is<std::string>()) {
					spell = tes3::getObjectByID<TES3::Spell>(spellParam.as<std::string>(), TES3::ObjectType::Spell);
				}
				else if (spellParam.is<TES3::Spell*>()) {
					spell = spellParam.as<TES3::Spell*>();
				}

				if (spell == NULL) {
					return false;
				}

				mwscript::ExplodeSpell(script, reference, spell);
				return true;
			};

			state["mwscript"]["hasItemEquipped"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve item.
				sol::object itemParam = params["item"];
				TES3::BaseObject* item = NULL;
				if (itemParam.is<std::string>()) {
					item = tes3::getTemplate(itemParam.as<std::string>());
				}
				else if (itemParam.is<TES3::BaseObject*>()) {
					item = itemParam.as<TES3::BaseObject*>();
				}

				if (item == NULL) {
					return false;
				}

				mwscript::HasItemEquipped(script, reference, item);
				return true;
			};

			state["mwscript"]["getItemCount"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve item.
				sol::object itemParam = params["item"];
				TES3::BaseObject* item = NULL;
				if (itemParam.is<std::string>()) {
					item = tes3::getTemplate(itemParam.as<std::string>());
				}
				else if (itemParam.is<TES3::BaseObject*>()) {
					item = itemParam.as<TES3::BaseObject*>();
				}

				if (item == NULL) {
					return false;
				}

				mwscript::GetItemCount(script, reference, item);
				return true;
			};

			state["mwscript"]["getSpellEffects"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve spell.
				sol::object spellParam = params["spell"];
				TES3::Spell* spell = NULL;
				if (spellParam.is<std::string>()) {
					spell = tes3::getObjectByID<TES3::Spell>(spellParam.as<std::string>(), TES3::ObjectType::Spell);
				}
				else if (spellParam.is<TES3::Spell*>()) {
					spell = spellParam.as<TES3::Spell*>();
				}

				if (spell == NULL) {
					return false;
				}

				mwscript::GetSpellEffects(script, reference, spell);
				return true;
			};

			state["mwscript"]["placeAtPC"] = [](sol::table params) -> TES3::Reference* {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve item.
				sol::object objectParam = params["object"];
				TES3::BaseObject* object = NULL;
				if (objectParam.is<std::string>()) {
					object = tes3::getTemplate(objectParam.as<std::string>());
				}
				else if (objectParam.is<TES3::BaseObject*>()) {
					object = objectParam.as<TES3::BaseObject*>();
				}

				if (object == NULL) {
					return NULL;
				}

				// Resolve count.
				sol::object countParam = params["count"];
				long count = 1;
				if (countParam.is<double>()) {
					count = countParam.as<double>();
				}

				// Resolve count.
				sol::object distanceParam = params["distance"];
				float distance = 256.0f;
				if (distanceParam.is<double>()) {
					distance = distanceParam.as<double>();
				}

				// Resolve count.
				sol::object directionParam = params["direction"];
				float direction = 1;
				if (directionParam.is<double>()) {
					direction = directionParam.as<double>();
				}

				mwscript::PlaceAtPC(script, reference, object, count, distance, direction);
				return mwscript::lastCreatedPlaceAtPCReference;
			};

			state["mwscript"]["position"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve X.
				sol::object xParam = params["x"];
				float x = 0.0f;
				if (xParam.is<double>()) {
					x = xParam.as<double>();
				}

				// Resolve Y.
				sol::object yParam = params["y"];
				float y = 0.0f;
				if (yParam.is<double>()) {
					y = yParam.as<double>();
				}

				// Resolve Z.
				sol::object zParam = params["z"];
				float z = 0.0f;
				if (zParam.is<double>()) {
					z = zParam.as<double>();
				}

				// Resolve rotation.
				sol::object rotationParam = params["rotation"];
				float rotation = 0.0f;
				if (rotationParam.is<double>()) {
					rotation = rotationParam.as<double>();
				}

				mwscript::Position(script, reference, x, y, z, rotation);
				return true;
			};

			state["mwscript"]["positionCell"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve cell.
				sol::object cellParam = params["cell"];
				std::string cell;
				if (cellParam.is<std::string>()) {
					cell = cellParam.as<std::string>();
				}

				// Resolve X.
				sol::object xParam = params["x"];
				float x = 0.0f;
				if (xParam.is<double>()) {
					x = xParam.as<double>();
				}

				// Resolve Y.
				sol::object yParam = params["y"];
				float y = 0.0f;
				if (yParam.is<double>()) {
					y = yParam.as<double>();
				}

				// Resolve Z.
				sol::object zParam = params["z"];
				float z = 0.0f;
				if (zParam.is<double>()) {
					z = zParam.as<double>();
				}

				// Resolve rotation.
				sol::object rotationParam = params["rotation"];
				float rotation = 0.0f;
				if (rotationParam.is<double>()) {
					rotation = rotationParam.as<double>();
				}

				// Verify that we were given a cell.
				if (cell.empty()) {
					return false;
				}

				mwscript::PositionCell(script, reference, x, y, z, rotation, cell.c_str());
				return true;
			};

			state["mwscript"]["removeItem"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve item.
				sol::object itemParam = params["item"];
				TES3::BaseObject* item = NULL;
				if (itemParam.is<std::string>()) {
					item = tes3::getTemplate(itemParam.as<std::string>());
				}
				else if (itemParam.is<TES3::BaseObject*>()) {
					item = itemParam.as<TES3::BaseObject*>();
				}

				if (item == NULL) {
					return false;
				}

				// Resolve count.
				sol::object countParam = params["count"];
				long count = 1;
				if (countParam.is<double>()) {
					count = countParam.as<double>();
				}

				mwscript::RemoveItem(script, reference, item, count);
			};

			state["mwscript"]["removeSpell"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve spell.
				sol::object spellParam = params["spell"];
				TES3::Spell* spell = NULL;
				if (spellParam.is<std::string>()) {
					spell = tes3::getObjectByID<TES3::Spell>(spellParam.as<std::string>(), TES3::ObjectType::Spell);
				}
				else if (spellParam.is<TES3::Spell*>()) {
					spell = spellParam.as<TES3::Spell*>();
				}

				if (spell == NULL) {
					return false;
				}

				mwscript::RemoveSpell(script, reference, spell);
				return true;
			};

			state["mwscript"]["scriptRunning"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve script.
				sol::object scriptParam = params["script"];
				TES3::Script* targetScript = NULL;
				if (scriptParam.is<std::string>()) {
					targetScript = tes3::getScript(scriptParam.as<std::string>().c_str());
				}
				else if (scriptParam.is<TES3::Script*>()) {
					targetScript = scriptParam.as<TES3::Script*>();
				}

				if (targetScript == NULL) {
					return false;
				}

				return mwscript::ScriptRunning(script, targetScript);
			};

			state["mwscript"]["setLevel"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve level.
				sol::object levelParam = params["level"];
				short level = 0;
				if (levelParam.is<double>()) {
					level = levelParam.as<double>();
				}
				else {
					return false;
				}

				mwscript::SetLevel(script, reference, level);
				return true;
			};

			state["mwscript"]["startCombat"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve target.
				sol::object targetParam = params["target"];
				TES3::Reference* target = NULL;
				if (targetParam.is<std::string>()) {
					target = tes3::getReference(targetParam.as<std::string>().c_str());
				}
				else if (targetParam.is<TES3::Reference*>()) {
					target = targetParam.as<TES3::Reference*>();
				}

				if (target == NULL) {
					return false;
				}

				mwscript::StartCombat(script, reference, target);
				return true;
			};

			state["mwscript"]["startScript"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve script.
				sol::object scriptParam = params["script"];
				TES3::Script* targetScript = NULL;
				if (scriptParam.is<std::string>()) {
					targetScript = tes3::getScript(scriptParam.as<std::string>().c_str());
				}
				else if (scriptParam.is<TES3::Script*>()) {
					targetScript = scriptParam.as<TES3::Script*>();
				}

				if (targetScript == NULL) {
					return false;
				}

				mwscript::StartScript(script, reference, targetScript);
				return true;
			};

			state["mwscript"]["stopScript"] = [](sol::table params) {
				TES3::Script* script = getScriptParam(params);
				TES3::Reference* reference = getReferenceParam(params);

				// Resolve script.
				sol::object scriptParam = params["script"];
				TES3::Script* targetScript = NULL;
				if (scriptParam.is<std::string>()) {
					targetScript = tes3::getScript(scriptParam.as<std::string>().c_str());
				}
				else if (scriptParam.is<TES3::Script*>()) {
					targetScript = scriptParam.as<TES3::Script*>();
				}

				if (targetScript == NULL) {
					return false;
				}

				mwscript::StartScript(script, reference, targetScript);
				return true;
			};

		}
	}
}
