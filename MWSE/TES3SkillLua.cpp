#include <string>

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3DataHandler.h"
#include "TES3GameSetting.h"
#include "TES3Skill.h"
#include "TES3SkillLua.h"

namespace mwse {
	namespace lua {
		static const auto arraySkillIconPaths = reinterpret_cast<const char**>(0x7BB158);

		void bindTES3Skill() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::Skill>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
			setUserdataForBaseObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("id", sol::readonly_property(&TES3::Skill::skill));
			usertypeDefinition.set("attribute", &TES3::Skill::governingAttribute);
			usertypeDefinition.set("specialization", &TES3::Skill::specialization);

			// Functions as properties.
			usertypeDefinition.set("name", sol::readonly_property(
				[](const TES3::Skill& self) {
					auto dataHandler = TES3::DataHandler::get();
					return dataHandler->nonDynamicData->GMSTs[0x380 + self.skill]->value.asString;
				}
			));
			usertypeDefinition.set("iconPath", sol::readonly_property(
				[](const TES3::Skill& self) {
					std::string path = "icons\\k\\";
					path.append(arraySkillIconPaths[self.skill]);
					return path;
				}
			));

			// Indirect bindings to unions and arrays.
			usertypeDefinition.set("actions", sol::readonly_property([](TES3::Skill& self) { return std::ref(self.progressActions); }));

			// Finish up our usertype.
			state.set_usertype("tes3skill", usertypeDefinition);
		}
	}
}
