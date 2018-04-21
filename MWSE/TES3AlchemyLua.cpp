#include "TES3AlchemyLua.h"

#include "TES3Util.h"

#include "LuaUnifiedHeader.h"
#include "LuaUtil.h"
#include "LuaManager.h"

#define TES3_Alchemy_ctor 0x4ABA40

namespace mwse {
	namespace lua {
		TES3::Alchemy* createAlchemy(sol::table params) {
			sol::state& state = LuaManager::getInstance().getState();

			// Do we already have an object of this ID?
			std::string id = getOptionalParam<std::string>(params, "id", "");
			if (!id.empty() && tes3::getDataHandler()->nonDynamicData->resolveObject(id.c_str()) != NULL) {
				return NULL;
			}

			// Create new alchemy object.
			TES3::Alchemy* alchemy = tes3::malloc<TES3::Alchemy>();
			reinterpret_cast<void(__thiscall *)(TES3::Alchemy*)>(TES3_Alchemy_ctor)(alchemy);

			// Set ID. It isn't required.
			if (!id.empty()) {
				alchemy->setID(id.c_str());
			}

			// Set name. Defaults to "Potion"
			std::string name = getOptionalParam<std::string>(params, "name", "Potion");
			alchemy->setName(name.c_str());

			// Set script.
			TES3::Script* script = getOptionalParamScript(params, "script");
			if (script != NULL) {
				alchemy->script = script;
			}

			// Set model.
			std::string model = getOptionalParam<std::string>(params, "model", "m\\Misc_Potion_Bargain_01.nif");
			alchemy->setModelPath(model.c_str());

			// Set texture.
			std::string icon = getOptionalParam<std::string>(params, "icon", "m\\Tx_potion_bargain_01.tga");
			tes3::setDataString(&alchemy->icon, icon.c_str());

			// Get other simple values.
			alchemy->objectFlags = getOptionalParam<double>(params, "objectFlags", 0.0);
			alchemy->weight = getOptionalParam<double>(params, "weight", 0.0);
			alchemy->value = getOptionalParam<double>(params, "value", 0.0);
			alchemy->flags = getOptionalParam<double>(params, "flags", 0.0);

			// Flag the object as modified.
			alchemy->objectFlags |= TES3::ObjectFlag::Modified;

			// Assign effects.
			sol::optional<sol::table> effects = params["effects"];
			if (effects) {
				for (int i = 1; i <= 8; i++) {
					sol::optional<sol::table> effectParams = effects.value()[i];
					if (!effectParams) {
						break;
					}

					TES3::Effect* effect = &alchemy->effects[i-1];
					effect->effectID = getOptionalParam<double>(effectParams, "id", -1);
					effect->skillID = getOptionalParam<double>(effectParams, "skill", -1);
					effect->attributeID = getOptionalParam<double>(effectParams, "attribute", -1);
					effect->rangeType = getOptionalParam<double>(effectParams, "range", TES3::EffectRange::Self);
					effect->radius = getOptionalParam<double>(effectParams, "radius", 0);
					effect->duration = getOptionalParam<double>(effectParams, "duration", 0);
					effect->magnitudeMin = getOptionalParam<double>(effectParams, "min", 0);
					effect->magnitudeMax = getOptionalParam<double>(effectParams, "max", 0);
				}
			}

			// If we don't have an effect, fill in the first one.
			if (alchemy->effects[0].effectID == TES3::EffectID::None) {
				alchemy->effects[0].effectID = TES3::EffectID::WaterBreathing;
			}

			// We have our alchemy object. But is it unique?
			for (TES3::Alchemy* testObject = reinterpret_cast<TES3::Alchemy*>(tes3::getDataHandler()->nonDynamicData->list->head);
				testObject != NULL;
				testObject = reinterpret_cast<TES3::Alchemy*>(testObject->nextInCollection)) {
				// We only care about alchemy objects.
				if (testObject->objectType != TES3::ObjectType::Alchemy) {
					continue;
				}

				// Check object flags.
				if (alchemy->objectFlags != testObject->objectFlags) {
					continue;
				}

				// Check basic values.
				if (alchemy->weight != testObject->weight || alchemy->value != testObject->value ||
					alchemy->flags != alchemy->flags) {
					continue;
				}

				// Check effects.
				if (!tes3::effectsMatch(alchemy->effects, testObject->effects)) {
					continue;
				}

				// Check script.
				if (alchemy->script != testObject->script) {
					continue;
				}

				// Check name.
				if (strcmp(alchemy->name, testObject->name) != 0) {
					continue;
				}

				// Check model.
				if (strcmp(alchemy->model, testObject->model) != 0) {
					continue;
				}

				// Check icon.
				if (strcmp(alchemy->icon, testObject->icon) != 0) {
					continue;
				}

				// If we've gotten this far, objects are almost the same. Let's use the one that already exists.
				alchemy->vTable.base->destructor(alchemy, true);
				return testObject;
			}

			// All good? Add and return the object.
			if (!tes3::getDataHandler()->nonDynamicData->addNewObject(alchemy)) {
				return NULL;
			}
			return alchemy;
		}

		void bindTES3Alchemy() {
			LuaManager::getInstance().getState().new_usertype<TES3::Alchemy>("TES3Alchemy",
				// Disable construction of this type.
				"new", sol::no_constructor,

				"create", &createAlchemy,

				//
				// Properties.
				//

				"objectType", &TES3::Alchemy::objectType,

				"id", sol::readonly_property(&TES3::Alchemy::getObjectID),
				"name", sol::property(&TES3::Alchemy::getName, &TES3::Alchemy::setName),

				"icon", sol::property(&TES3::Alchemy::getIconPath, [](TES3::Alchemy& self, std::string value) { tes3::setDataString(&self.icon, value.c_str()); }),
				"model", sol::property( &TES3::Alchemy::getModelPath, [](TES3::Alchemy& self, std::string value) { self.setModelPath(value.c_str()); } ),

				"flags", &TES3::Alchemy::flags,
				"autoCalc", sol::property(&TES3::Alchemy::getAutoCalc, &TES3::Alchemy::setAutoCalc),

				"value", sol::readonly_property(&TES3::Alchemy::getValue),
				"weight", sol::readonly_property(&TES3::Alchemy::getWeight),

				"effects", sol::readonly_property([](TES3::Alchemy& self) { return std::ref(self.effects); }),

				"script", sol::readonly_property(&TES3::Alchemy::getScript)

				);
		}
	}
}
