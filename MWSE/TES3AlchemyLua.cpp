#include "TES3AlchemyLua.h"

#include "TES3Util.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Alchemy.h"
#include "TES3DataHandler.h"
#include "TES3Script.h"

#define TES3_Alchemy_ctor 0x4ABA40

namespace mwse {
	namespace lua {
		TES3::Alchemy* createAlchemy(sol::table params) {
			sol::state& state = LuaManager::getInstance().getState();

			// Do we already have an object of this ID?
			std::string id = getOptionalParam<std::string>(params, "id", "");
			if (!id.empty() && TES3::DataHandler::get()->nonDynamicData->resolveObject(id.c_str()) != NULL) {
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
			std::string model = getOptionalParam<std::string>(params, "mesh", "m\\Misc_Potion_Bargain_01.nif");
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
					effect->effectID = getOptionalParam<int>(effectParams, "id", -1);
					effect->skillID = getOptionalParam<int>(effectParams, "skill", -1);
					effect->attributeID = getOptionalParam<int>(effectParams, "attribute", -1);
					effect->rangeType = static_cast<TES3::EffectRange>(getOptionalParam<int>(effectParams, "range", int(TES3::EffectRange::Self)));
					effect->radius = getOptionalParam<int>(effectParams, "radius", 0);
					effect->duration = getOptionalParam<int>(effectParams, "duration", 0);
					effect->magnitudeMin = getOptionalParam<int>(effectParams, "min", 0);
					effect->magnitudeMax = getOptionalParam<int>(effectParams, "max", 0);
				}
			}

			// If we don't have an effect, fill in the first one.
			if (alchemy->effects[0].effectID == TES3::EffectID::None) {
				alchemy->effects[0].effectID = TES3::EffectID::WaterBreathing;
			}

			// We have our alchemy object. But is it unique?
			for (TES3::Alchemy* testObject = reinterpret_cast<TES3::Alchemy*>(TES3::DataHandler::get()->nonDynamicData->list->head);
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
				if (!alchemy->effectsMatchWith(testObject)) {
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
			if (!TES3::DataHandler::get()->nonDynamicData->addNewObject(alchemy)) {
				return NULL;
			}
			return alchemy;
		}

		void bindTES3Alchemy() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Alchemy>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("flags", &TES3::Alchemy::flags);
			usertypeDefinition.set("weight", &TES3::Alchemy::weight);
			usertypeDefinition.set("value", &TES3::Alchemy::value);

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("effects", sol::readonly_property([](TES3::Alchemy& self) { return std::ref(self.effects); }));

			// Basic function binding.
			usertypeDefinition.set("create", &createAlchemy);

			// Functions exposed as properties.
			usertypeDefinition.set("autoCalc", sol::property(&TES3::Alchemy::getAutoCalc, &TES3::Alchemy::setAutoCalc));
			usertypeDefinition.set("icon", sol::property(
				&TES3::Alchemy::getIconPath,
				[](TES3::Alchemy& self, const char* value) { tes3::setDataString(&self.icon, value); }
			));
			usertypeDefinition.set("mesh", sol::property(&TES3::Alchemy::getModelPath, &TES3::Alchemy::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::Alchemy::getName, &TES3::Alchemy::setName));
			usertypeDefinition.set("script", sol::property(&TES3::Alchemy::getScript));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::Alchemy::getModelPath, &TES3::Alchemy::setModelPath));

			// Finish up our usertype.
			state.set_usertype("tes3alchemy", usertypeDefinition);
		}
	}
}
