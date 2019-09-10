#include "TES3ClassLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Class.h"

namespace TES3 {
	sol::table Class::getMajorSkills() {
		auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		sol::table result = state.create_table();
		for (int i = 0; i < 5; i++) {
			result[i + 1] = &skills[i * 2];
		}
		return result;
	}

	sol::table Class::getMinorSkills() {
		auto stateHandle = mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle();
		sol::state& state = stateHandle.state;

		sol::table result = state.create_table();
		for (int i = 0; i < 5; i++) {
			result[i + 1] = &skills[i * 2 + 1];
		}
		return result;
	}
}

namespace mwse {
	namespace lua {
		void bindTES3Class() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::Class>("tes3class");
			usertypeDefinition["new"] = sol::no_constructor;

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
			setUserdataForBaseObject(usertypeDefinition);

			// The vtable gets the name instead of the id. Overwrite this property to get the right value.
			usertypeDefinition["id"] = sol::readonly_property([](TES3::Class& self) { return self.id; });

			// Basic property binding.
			usertypeDefinition["services"] = &TES3::Class::services;
			usertypeDefinition["specialization"] = &TES3::Class::specialization;

			// Indirect bindings to unions and arrays.
			usertypeDefinition["attributes"] = sol::readonly_property([](TES3::Class& self) { return std::ref(self.attributes); });
			usertypeDefinition["skills"] = sol::readonly_property([](TES3::Class& self) { return std::ref(self.skills); });

			// Provide friendly access to service flags.
			usertypeDefinition["bartersAlchemy"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersAlchemy); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersAlchemy, set); }
			);
			usertypeDefinition["bartersApparatus"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersApparatus); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersApparatus, set); }
			);
			usertypeDefinition["bartersArmor"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersArmor); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersArmor, set); }
			);
			usertypeDefinition["bartersBooks"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersBooks); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersBooks, set); }
			);
			usertypeDefinition["bartersClothing"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersClothing); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersClothing, set); }
			);
			usertypeDefinition["bartersEnchantedItems"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersEnchantedItems); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersEnchantedItems, set); }
			);
			usertypeDefinition["bartersIngredients"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersIngredients); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersIngredients, set); }
			);
			usertypeDefinition["bartersLights"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersLights); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersLights, set); }
			);
			usertypeDefinition["bartersLockpicks"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersLockpicks); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersLockpicks, set); }
			);
			usertypeDefinition["bartersMiscItems"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersMiscItems); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersMiscItems, set); }
			);
			usertypeDefinition["bartersProbes"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersProbes); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersProbes, set); }
			);
			usertypeDefinition["bartersRepairTools"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersRepairTools); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersRepairTools, set); }
			);
			usertypeDefinition["bartersWeapons"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::BartersWeapons); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::BartersWeapons, set); }
			);
			usertypeDefinition["offersEnchanting"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::OffersEnchanting); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::OffersEnchanting, set); }
			);
			usertypeDefinition["offersRepairs"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::OffersRepairs); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::OffersRepairs, set); }
			);
			usertypeDefinition["offersSpellmaking"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::OffersSpellmaking); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::OffersSpellmaking, set); }
			);
			usertypeDefinition["offersSpells"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::OffersSpells); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::OffersSpells, set); }
			);
			usertypeDefinition["offersTraining"] = sol::property(
				[](TES3::Class& self) { return self.getServiceFlag(TES3::ServiceFlag::OffersTraining); },
				[](TES3::Class& self, bool set) { self.setServiceFlag(TES3::ServiceFlag::OffersTraining, set); }
			);

			// Properties that have type remapping.
			usertypeDefinition["playable"] = sol::property(
				[](TES3::Class& self) { return self.playable != 0; },
				[](TES3::Class& self, bool value) { self.playable = value; }
			);

			// Functions exposed as properties.
			usertypeDefinition["majorSkills"] = sol::readonly_property(&TES3::Class::getMajorSkills);
			usertypeDefinition["minorSkills"] = sol::readonly_property(&TES3::Class::getMinorSkills);
			usertypeDefinition["name"] = sol::property(
				[](TES3::Class& self) { return self.name; },
				[](TES3::Class& self, const char* value) { if (strlen(value) < 32) strcpy(self.name, value); }
			);

			// Description may need to be loaded from disk, handle it specially.
			usertypeDefinition["description"] = sol::property(
				[](TES3::Class& self) -> sol::object
			{
				auto& luaManager = mwse::lua::LuaManager::getInstance();
				auto stateHandle = luaManager.getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;

				// If the description is already loaded, just return it.
				if (self.description) {
					return sol::make_object(state, self.description);
				}

				// Otherwise we need to load it from disk, then free it.
				else {
					char * description = self.loadDescription();
					if (description) {
						// We loaded successfully, package, free, then return.
						sol::object value = sol::make_object(state, description);
						self.freeDescription();
						return value;
					}
				}

				return sol::nil;
			},
				[](TES3::Class& self, const char* value)
			{
				self.setDescription(value);
				self.setObjectModified(true);
			}
			);
		}
	}
}
