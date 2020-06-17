#include "NITimeControllerLua.h"

#include "NIObjectLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "NIRTTI.h"
#include "NIObjectNET.h"
#include "NITimeController.h"

namespace mwse {
	namespace lua {
		void bindNITimeController() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<NI::TimeController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<NI::Object>());
				setUserdataForNIObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("frequency", &NI::TimeController::frequency);
				usertypeDefinition.set("phase", &NI::TimeController::phase);
				usertypeDefinition.set("lowKeyFrame", &NI::TimeController::lowKeyFrame);
				usertypeDefinition.set("highKeyFrame", &NI::TimeController::highKeyFrame);
				usertypeDefinition.set("startTime", &NI::TimeController::startTime);
				usertypeDefinition.set("lastTime", &NI::TimeController::lastTime);
				usertypeDefinition.set("target", sol::readonly_property([](NI::TimeController& self) { return makeLuaNiPointer(self.target); }));
				usertypeDefinition.set("nextController", sol::readonly_property([](NI::TimeController& self) { return makeLuaNiPointer(self.nextController); }));

				// Basic function binding.
				usertypeDefinition.set("setTarget", &NI::TimeController::setTarget);
				usertypeDefinition.set("start", &NI::TimeController::start);

				// Finish up our usertype.
				state.set_usertype("niTimeController", usertypeDefinition);
			}
		}
	}
}
