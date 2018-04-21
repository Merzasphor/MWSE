#include "LuaUnifiedHeader.h"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "ScriptUtil.h"
#include "ScriptUtilLua.h"

namespace mwse {
	namespace lua {
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
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);

				mwscript::Activate(script, reference);
			};
			state["mwscript"]["addItem"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* item = getOptionalParamObject<TES3::BaseObject>(params, "item");
				int count = getOptionalParam<double>(params, "count", 1.0);
				if (item == NULL || count <= 0) {
					return false;
				}

				mwscript::AddItem(script, reference, item, count);
				return true;
			};
			state["mwscript"]["addSoulGem"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Creature* creature = getOptionalParamObject<TES3::Creature>(params, "creature");
				TES3::Misc* soulGem = getOptionalParamObject<TES3::Misc>(params, "soulgem");
				if (creature == NULL || soulGem == NULL) {
					return false;
				}

				mwscript::AddSoulGem(script, reference, creature, soulGem);
				return true;
			};
			state["mwscript"]["addToLevCreature"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* list = getOptionalParamObject<TES3::BaseObject>(params, "list");
				TES3::Actor* actor = getOptionalParamObject<TES3::Actor>(params, "creature");
				short level = getOptionalParam<double>(params, "level", 0.0);
				if (list == NULL || actor == NULL || level <= 0) {
					return false;
				}

				mwscript::AddToLevCreature(script, reference, list, actor, level);
				return true;
			};
			state["mwscript"]["addSpell"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Spell* spell = getOptionalParamSpell(params, "spell");
				if (spell == NULL) {
					return false;
				}

				mwscript::AddSpell(script, reference, spell);
				return true;
			};
			state["mwscript"]["addToLevItem"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* list = getOptionalParamObject<TES3::BaseObject>(params, "list");
				TES3::PhysicalObject* item = getOptionalParamObject<TES3::PhysicalObject>(params, "item");
				short level = getOptionalParam<double>(params, "level", 0.0);
				if (list == NULL || item == NULL || level <= 0) {
					return false;
				}

				mwscript::AddToLevItem(script, reference, list, item, level);
				return true;
			};
			state["mwscript"]["addTopic"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::DialogueInfo* topic = getOptionalParamTopic(params, "topic");
				if (topic == NULL) {
					return false;
				}

				mwscript::AddTopic(script, reference, topic);
				return true;
			};
			state["mwscript"]["aiTravel"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				double x = getOptionalParam<double>(params, "x", 0.0);
				double y = getOptionalParam<double>(params, "y", 0.0);
				double z = getOptionalParam<double>(params, "z", 0.0);

				mwscript::AITravel(script, reference, x, y, z);
				return true;
			};
			state["mwscript"]["drop"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* item = getOptionalParamObject<TES3::BaseObject>(params, "item");
				int count = getOptionalParam<double>(params, "count", 1.0);
				if (item == NULL) {
					return false;
				}

				mwscript::Drop(script, reference, item, count);
				return true;
			};
			state["mwscript"]["equip"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* item = getOptionalParamObject<TES3::BaseObject>(params, "item");
				if (item == NULL) {
					return false;
				}

				mwscript::Equip(script, reference, item);
				return true;
			};
			state["mwscript"]["explodeSpell"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Spell* spell = getOptionalParamSpell(params, "spell");
				if (spell == NULL) {
					return false;
				}

				mwscript::ExplodeSpell(script, reference, spell);
				return true;
			};
			state["mwscript"]["getButtonPressed"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);

				return mwscript::GetButtonPressed(script, reference);
			};
			state["mwscript"]["hasItemEquipped"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* item = getOptionalParamObject<TES3::BaseObject>(params, "item");
				if (item == NULL) {
					return false;
				}

				mwscript::HasItemEquipped(script, reference, item);
				return true;
			};
			state["mwscript"]["getDistance"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Reference* target = getOptionalParamObject<TES3::Reference>(params, "target");
				if (reference == NULL || target == NULL) {
					return -1.0f;
				}

				return mwscript::GetDistance(script, reference, target);
			};
			state["mwscript"]["getItemCount"] = [](sol::optional<sol::table> params) -> int {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* item = getOptionalParamObject<TES3::BaseObject>(params, "item");
				if (item == NULL) {
					return 0;
				}

				return mwscript::GetItemCount(script, reference, item);
			};
			state["mwscript"]["getSpellEffects"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Spell* spell = getOptionalParamSpell(params, "spell");
				if (spell == NULL) {
					return false;
				}

				return mwscript::GetSpellEffects(script, reference, spell);
			};
			state["mwscript"]["onActivate"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);

				bool result = reference->testActionFlag(TES3::ActionFlags::OnActivate);
				reference->clearActionFlag(TES3::ActionFlags::UseEnabled);
				reference->clearActionFlag(TES3::ActionFlags::OnActivate);
				return result;
			};
			state["mwscript"]["onDeath"] = [](sol::optional<sol::table> params) {
				TES3::Reference* reference = getOptionalParamExecutionReference(params);

				bool result = reference->testActionFlag(TES3::ActionFlags::OnDeath);
				reference->clearActionFlag(TES3::ActionFlags::OnDeath);
				return result;
			};
			state["mwscript"]["onKnockout"] = [](sol::optional<sol::table> params) {
				TES3::Reference* reference = getOptionalParamExecutionReference(params);

				bool result = reference->testActionFlag(TES3::ActionFlags::OnKnockout);
				reference->clearActionFlag(TES3::ActionFlags::OnKnockout);
				return result;
			};
			state["mwscript"]["onMurder"] = [](sol::optional<sol::table> params) {
				TES3::Reference* reference = getOptionalParamExecutionReference(params);

				bool result = reference->testActionFlag(TES3::ActionFlags::OnMurder);
				reference->clearActionFlag(TES3::ActionFlags::OnMurder);
				return result;
			};
			state["mwscript"]["placeAtPC"] = [](sol::optional<sol::table> params) -> TES3::Reference* {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* object = getOptionalParamObject<TES3::BaseObject>(params, "object");
				int count = getOptionalParam<double>(params, "count", 1.0);
				double distance = getOptionalParam<double>(params, "distance", 256.0);
				double direction = getOptionalParam<double>(params, "direction", 1.0);
				if (object == NULL) {
					return NULL;
				}

				mwscript::PlaceAtPC(script, reference, object, count, distance, direction);
				return mwscript::lastCreatedPlaceAtPCReference;
			};
			state["mwscript"]["position"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				double x = getOptionalParam<double>(params, "x", 0.0);
				double y = getOptionalParam<double>(params, "y", 0.0);
				double z = getOptionalParam<double>(params, "z", 0.0);
				double rotation = getOptionalParam<double>(params, "rotation", 0.0);

				mwscript::Position(script, reference, x, y, z, rotation);
				return true;
			};
			state["mwscript"]["positionCell"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				double x = getOptionalParam<double>(params, "x", 0.0);
				double y = getOptionalParam<double>(params, "y", 0.0);
				double z = getOptionalParam<double>(params, "z", 0.0);
				double rotation = getOptionalParam<double>(params, "rotation", 0.0);
				std::string cell = getOptionalParam<std::string>(params, "cell", "");
				if (cell.empty()) {
					return false;
				}

				mwscript::PositionCell(script, reference, x, y, z, rotation, cell.c_str());
				return true;
			};
			state["mwscript"]["removeItem"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::BaseObject* item = getOptionalParamObject<TES3::BaseObject>(params, "item");
				int count = getOptionalParam<double>(params, "count", 1.0);
				if (item == NULL) {
					return false;
				}

				mwscript::RemoveItem(script, reference, item, count);
				return true;
			};
			state["mwscript"]["removeSpell"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Spell* spell = getOptionalParamSpell(params, "spell");
				if (spell == NULL) {
					return false;
				}

				mwscript::RemoveSpell(script, reference, spell);
				return true;
			};
			state["mwscript"]["scriptRunning"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Script* targetScript = getOptionalParamScript(params, "script");
				if (targetScript == NULL) {
					return false;
				}

				return mwscript::ScriptRunning(script, targetScript);
			};
			state["mwscript"]["setLevel"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				short level = getOptionalParam<double>(params, "level", 0);
				if (level <= 0) {
					return false;
				}

				mwscript::SetLevel(script, reference, level);
				return true;
			};
			state["mwscript"]["startCombat"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Reference* target = getOptionalParamReference(params, "target");
				if (target == NULL) {
					return false;
				}

				mwscript::StartCombat(script, reference, target);
				return true;
			};
			state["mwscript"]["startScript"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Script* targetScript = getOptionalParamScript(params, "script");
				if (targetScript == NULL) {
					return false;
				}

				mwscript::StartScript(script, reference, targetScript);
				return true;
			};
			state["mwscript"]["stopScript"] = [](sol::optional<sol::table> params) {
				TES3::Script* script = getOptionalParamExecutionScript(params);
				TES3::Reference* reference = getOptionalParamExecutionReference(params);
				TES3::Script* targetScript = getOptionalParamScript(params, "script");
				if (targetScript == NULL) {
					targetScript = script;
				}

				if (targetScript) {
					mwscript::StopScript(script, targetScript);
					return true;
				}

				return false;
			};

		}
	}
}
