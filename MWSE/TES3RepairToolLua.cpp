#include "TES3RepairToolLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3RepairTool.h"
#include "TES3Script.h"

namespace mwse {
	namespace lua {
		void bindTES3RepairTool() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.create_simple_usertype<TES3::RepairTool>();
			usertypeDefinition.set("new", sol::no_constructor);

			// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
			usertypeDefinition.set(sol::base_classes, sol::bases<TES3::Item, TES3::PhysicalObject, TES3::Object, TES3::BaseObject>());
			setUserdataForPhysicalObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("condition", &TES3::RepairTool::maxCondition);
			usertypeDefinition.set("quality", &TES3::RepairTool::quality);
			usertypeDefinition.set("value", &TES3::RepairTool::value);
			usertypeDefinition.set("weight", &TES3::RepairTool::weight);

			// Access to other objects that need to be packaged.
			usertypeDefinition.set("script", sol::readonly_property([](TES3::RepairTool& self) { return makeLuaObject(self.getScript()); }));

			// Functions exposed as properties.
			usertypeDefinition.set("icon", sol::property(
				&TES3::RepairTool::getIconPath,
				[](TES3::RepairTool& self, const char* value) { if (strlen(value) < 32) strcpy(self.icon, value); }
			));
			usertypeDefinition.set("mesh", sol::property(&TES3::RepairTool::getModelPath, &TES3::RepairTool::setModelPath));
			usertypeDefinition.set("name", sol::property(&TES3::RepairTool::getName, &TES3::RepairTool::setName));

			// TODO: Deprecated. Remove before 2.1-stable.
			usertypeDefinition.set("model", sol::property(&TES3::RepairTool::getModelPath, &TES3::RepairTool::setModelPath));
			
			// Finish up our usertype.
			state.set_usertype("tes3repairTool", usertypeDefinition);
		}
	}
}
