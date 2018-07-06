#include "TES3UIBlock.h"
#include "TES3UIManager.h"
#include "TES3UIMenuController.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "Log.h"

namespace mwse {
	namespace lua {
		using TES3::UI::Block;
		using TES3::UI::UI_ID;

		void bindTES3UIManager() {
			sol::state& state = LuaManager::getInstance().getState();

			auto tes3ui = state.create_named_table("tes3ui");

			tes3ui["registerID"] = TES3::UI::registerID;
			tes3ui["registerProperty"] = TES3::UI::registerProperty;
			tes3ui.set_function("createMenu", [](sol::table args) {
				auto id = args.get<sol::optional<UI_ID>>("id");
				if (!id) {
					log::getLog() << "createMenu: id argument is required." << std::endl;
					return static_cast<Block*>(nullptr);
				}

				Block* menu = TES3::UI::createMenu(id.value());

				if (args.get<bool>("fixedFrame")) {
					menu->createFixedFrame(id.value(), 1);
					TES3::UI::preventInventoryMenuToggle(menu);
				}
				else if (args.get<bool>("dragFrame")) {
					menu->createDragFrame(id.value(), 1);
				}

				return menu;
			});
			tes3ui["findMenu"] = TES3::UI::findMenu;
			tes3ui["enterMenuMode"] = TES3::UI::enterMenuMode;
			tes3ui["leaveMenuMode"] = TES3::UI::leaveMenuMode;
			tes3ui["acquireTextInput"] = TES3::UI::acquireTextInput;
		}

	}
}
