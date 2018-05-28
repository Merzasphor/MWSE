#include "TES3SpellLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Util.h"

namespace mwse {
	namespace lua {
		TES3::Spell* createSpell(std::string id, std::string name) {
			// Make sure a spell doesn't already exist with this id.
			if (tes3::getObjectById<TES3::Spell>(id, TES3::ObjectType::Spell) != NULL) {
				return NULL;
			}

			// Get spell list.
			TES3::LinkedList<TES3::Spell>* spellsList = tes3::getDataHandler()->nonDynamicData->spellsList;
			TES3::Spell* spellListHead = spellsList->head;

			// Create new spell.
			TES3::Spell* newSpell = tes3::malloc<TES3::Spell>();
			memset(newSpell, 0, sizeof(TES3::Spell));
			newSpell->vTable = spellListHead->vTable;
			newSpell->objectType = TES3::ObjectType::Spell;
			newSpell->owningCollection.asSpellList = spellsList;
			newSpell->magickaCost = 1;

			// Limit name to 31 characters.
			if (name.length() > 31) {
				return NULL;
			}

			// Set id/name.
			newSpell->setID(id.c_str());
			newSpell->setName(name.c_str());

			// Set effects.
			for (int i = 0; i < 8; i++) {
				newSpell->effects[i].effectID = TES3::EffectID::None;
			}

			// Set the first effect just so that there is something? TODO: Why?
			tes3::setEffect(newSpell->effects, 1, TES3::EffectID::WaterBreathing, TES3::SkillID::Invalid, TES3::EffectRange::Self, 0, 1, 0, 0);

			// Add object to the game.
			tes3::getDataHandler()->nonDynamicData->addNewObject(newSpell);

			// Finally return the spell.
			return newSpell;
		}

		void bindTES3Spell() {
			LuaManager::getInstance().getState().new_usertype<TES3::Spell>("TES3Spell",
				// Disable construction of this type.
				"create", createSpell,

				//
				// Properties.
				//

				"objectType", &TES3::Spell::objectType,

				"id", sol::readonly_property(&TES3::Spell::getObjectID),
				"name", sol::property(&TES3::Spell::getName, &TES3::Spell::setName),

				"flags", &TES3::Spell::spellFlags,
				"autoCalc", sol::property(&TES3::Spell::getAutoCalc, &TES3::Spell::setAutoCalc),

				"effects", sol::readonly_property([](TES3::Spell& self) { return std::ref(self.effects); }),

				"castType", &TES3::Spell::castType,
				"magickaCost", &TES3::Spell::magickaCost,

				//
				// Functions
				//

				"calculateCastChance", [](TES3::Spell& self, sol::table params) -> float
			{
				bool checkMagicka = getOptionalParam<bool>(params, "checkMagicka", true);
				sol::object caster = params["caster"];
				if (caster.is<TES3::Reference>()) {
					return self.calculateCastChance(caster.as<TES3::Reference*>(), checkMagicka);
				}
				else if (caster.is<TES3::MobileActor>()) {
					return self.calculateCastChance(caster.as<TES3::MobileActor*>(), checkMagicka);
				}

				return 0.0f;
			}

				);
		}
	}
}
