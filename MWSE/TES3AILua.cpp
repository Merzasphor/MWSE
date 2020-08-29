#include "TES3AILua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3AIConfig.h"
#include "TES3AIData.h"
#include "TES3AIPackage.h"
#include "TES3Cell.h"
#include "TES3MobileActor.h"

namespace mwse {
	namespace lua {
		void bindTES3AI() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::AIConfig
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::AIConfig>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("hello", &TES3::AIConfig::hello);
				usertypeDefinition.set("fight", &TES3::AIConfig::fight);
				usertypeDefinition.set("flee", &TES3::AIConfig::flee);
				usertypeDefinition.set("alarm", &TES3::AIConfig::alarm);
				usertypeDefinition.set("merchantFlags", &TES3::AIConfig::merchantFlags);

				// Finish up our usertype.
				state.set_usertype("tes3aiConfig", usertypeDefinition);
			}

			// Binding for TES3::AIPlanner
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::AIPlanner>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("indexActivePackage", sol::readonly_property(&TES3::AIPlanner::indexActivePackage));
				usertypeDefinition.set("countPackages", sol::readonly_property(&TES3::AIPlanner::countPackages));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("mobile", sol::readonly_property([](TES3::AIPlanner& self) { return makeLuaObject(self.mobileActor); }));

				// Basic function binding.
				usertypeDefinition.set("getActivePackage", &TES3::AIPlanner::getActivePackage);

				// Indirect bindings to unions and arrays.
				usertypeDefinition.set("packages", sol::readonly_property([](TES3::AIPlanner& self) { return std::ref(self.packages); }));

				// Finish up our usertype.
				state.set_usertype("tes3aiPlanner", usertypeDefinition);
			}

			// Binding for TES3::AIPackage
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::AIPackage>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("distance", sol::readonly_property(&TES3::AIPackage::distance));
				usertypeDefinition.set("duration", sol::readonly_property(&TES3::AIPackage::duration));
				usertypeDefinition.set("hourOfDay", sol::readonly_property(&TES3::AIPackage::hourOfDay));
				usertypeDefinition.set("isDone", sol::readonly_property(&TES3::AIPackage::done));
				usertypeDefinition.set("isFinalized", sol::readonly_property(&TES3::AIPackage::finalized));
				usertypeDefinition.set("isMoving", sol::readonly_property(&TES3::AIPackage::moving));
				usertypeDefinition.set("isReset", sol::readonly_property(&TES3::AIPackage::reset));
				usertypeDefinition.set("isStarted", sol::readonly_property(&TES3::AIPackage::started));
				usertypeDefinition.set("targetPosition", sol::readonly_property(&TES3::AIPackage::targetPosition));
				usertypeDefinition.set("type", sol::readonly_property(&TES3::AIPackage::packageType));

				// Access to other objects that need to be packaged.
				usertypeDefinition.set("destinationCell", sol::readonly_property([](TES3::AIPackage& self) { return makeLuaObject(self.destinationCell); }));

				// Finish up our usertype.
				state.set_usertype("tes3aiPackage", usertypeDefinition);
			}
		}
	}
}

