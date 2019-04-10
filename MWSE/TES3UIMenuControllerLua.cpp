#pragma once

#include "TES3UIMenuControllerLua.h"

#include "LuaManager.h"

#include "TES3ScriptCompiler.h"

#include "TES3UIElement.h"
#include "TES3UIMenuController.h"

#include "NINode.h"

namespace mwse {
	namespace lua {
		void bindTES3UIMenuController() {
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::UI::FontColor
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::UI::FontColor>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("r", &TES3::UI::FontColor::r);
				usertypeDefinition.set("g", &TES3::UI::FontColor::g);
				usertypeDefinition.set("b", &TES3::UI::FontColor::b);

				// Finish up our usertype.
				state.set_usertype("tes3uiFontColor", usertypeDefinition);
			}

			// Binding for TES3::UI::FontColor
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::UI::MenuController>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("fontColors", sol::readonly_property([](TES3::UI::MenuController& self) { return std::ref(self.fontColors); }));
				usertypeDefinition.set("helpDelay", sol::readonly_property(&TES3::UI::MenuController::helpDelay));
				usertypeDefinition.set("helpRoot", sol::readonly_property(&TES3::UI::MenuController::helpRoot));
				usertypeDefinition.set("inputController", sol::readonly_property(&TES3::UI::MenuController::menuInputController));
				usertypeDefinition.set("mainRoot", sol::readonly_property(&TES3::UI::MenuController::mainRoot));
				usertypeDefinition.set("scriptCompiler", sol::readonly_property(&TES3::UI::MenuController::scriptCompiler));

				// Functions exposed as properties.
				usertypeDefinition.set("inventoryMenuEnabled", sol::property(&TES3::UI::MenuController::getInventoryMenuEnabled, &TES3::UI::MenuController::setInventoryMenuEnabled));
				usertypeDefinition.set("magicMenuEnabled", sol::property(&TES3::UI::MenuController::getMagicMenuEnabled, &TES3::UI::MenuController::setMagicMenuEnabled));
				usertypeDefinition.set("mapMenuEnabled", sol::property(&TES3::UI::MenuController::getMapMenuEnabled, &TES3::UI::MenuController::setMapMenuEnabled));
				usertypeDefinition.set("statsMenuEnabled", sol::property(&TES3::UI::MenuController::getStatsMenuEnabled, &TES3::UI::MenuController::setStatsMenuEnabled));

				// Finish up our usertype.
				state.set_usertype("tes3uiMenuController", usertypeDefinition);
			}
		}
	}
}
