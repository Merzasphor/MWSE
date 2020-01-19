#include "TES3AILua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

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

			// Binding for TES3::AIPlanner
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::AIPlanner>("tes3aiPlanner");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["indexActivePackage"] = sol::readonly_property(&TES3::AIPlanner::indexActivePackage);
				usertypeDefinition["countPackages"] = sol::readonly_property(&TES3::AIPlanner::countPackages);

				// Access to other objects that need to be packaged.
				usertypeDefinition["mobile"] = sol::readonly_property([](TES3::AIPlanner& self) { return self.mobileActor; });

				// Basic function binding.
				usertypeDefinition["getActivePackage"] = &TES3::AIPlanner::getActivePackage;

				// Indirect bindings to unions and arrays.
				usertypeDefinition["packages"] = sol::readonly_property([](TES3::AIPlanner& self) { return std::ref(self.packages); });
			}

			// Binding for TES3::AIPackage
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::AIPackage>("tes3aiPackage");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["distance"] = sol::readonly_property(&TES3::AIPackage::distance);
				usertypeDefinition["duration"] = sol::readonly_property(&TES3::AIPackage::duration);
				usertypeDefinition["hourOfDay"] = sol::readonly_property(&TES3::AIPackage::hourOfDay);
				usertypeDefinition["isDone"] = sol::readonly_property(&TES3::AIPackage::done);
				usertypeDefinition["isFinalized"] = sol::readonly_property(&TES3::AIPackage::finalized);
				usertypeDefinition["isMoving"] = sol::readonly_property(&TES3::AIPackage::moving);
				usertypeDefinition["isReset"] = sol::readonly_property(&TES3::AIPackage::reset);
				usertypeDefinition["isStarted"] = sol::readonly_property(&TES3::AIPackage::started);
				usertypeDefinition["targetPosition"] = sol::readonly_property(&TES3::AIPackage::targetPosition);
				usertypeDefinition["type"] = sol::readonly_property(&TES3::AIPackage::packageType);

				// Access to other objects that need to be packaged.
				usertypeDefinition["destinationCell"] = sol::readonly_property([](TES3::AIPackage& self) { return self.destinationCell; });
			}
		}
	}
}

