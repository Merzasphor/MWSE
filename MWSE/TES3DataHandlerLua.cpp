#include "TES3DataHandlerLua.h"

#include "LuaManager.h"

#include "TES3Cell.h"
#include "TES3DataHandler.h"
#include "TES3Skill.h"
#include "TES3MagicEffect.h"

namespace mwse {
	namespace lua {
		void bindTES3DataHandler() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::NonDynamicData>("TES3RecordLists",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties
				//

				"skills", sol::readonly_property([](TES3::NonDynamicData& self) { return std::ref(self.skills); }),
				"magicEffects", sol::readonly_property([](TES3::NonDynamicData& self) { return std::ref(self.magicEffects); })

				);

			state.new_usertype<TES3::DataHandler>("TES3DataHandler",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties
				//

				"nonDynamicData", sol::readonly_property(&TES3::DataHandler::nonDynamicData),

				"currentCell", sol::readonly_property(&TES3::DataHandler::currentCell),
				"currentInteriorCell", sol::readonly_property(&TES3::DataHandler::currentInteriorCell),
				"lastExteriorCell", sol::readonly_property(&TES3::DataHandler::lastExteriorCell),
				"exteriorCellData", sol::readonly_property([](TES3::DataHandler& self) { return std::ref(self.exteriorCellData); }),
				"centralGridX", &TES3::DataHandler::centralGridX,
				"centralGridY", &TES3::DataHandler::centralGridY,
				"cellChanged", &TES3::DataHandler::cellChanged,

				"mainThread", sol::readonly_property(&TES3::DataHandler::mainThread),
				"mainThreadId", sol::readonly_property(&TES3::DataHandler::mainThreadID),
				"backgroundThread", sol::readonly_property(&TES3::DataHandler::backgroundThread),
				"backgroundThreadId", sol::readonly_property(&TES3::DataHandler::backgroundThreadID),
				"backgroundThreadRunning", sol::readonly_property(&TES3::DataHandler::backgroundThreadRunning),
				"threadSleepTime", sol::readonly_property(&TES3::DataHandler::threadSleepTime)

				);
		}
	}
}
