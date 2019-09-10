#include "TES3GameFileLua.h"

#include "sol.hpp"
#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3GameFile.h"

namespace mwse {
	namespace lua {
		void bindTES3GameFile() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::GameFile>("tes3gameFile");
			usertypeDefinition["new"] = sol::no_constructor;

			// Basic property binding.
			usertypeDefinition["filename"] = sol::readonly_property([](TES3::GameFile& self) -> const char* { return self.filename; });
			usertypeDefinition["path"] = sol::readonly_property([](TES3::GameFile& self) -> const char* { return self.path; });
			usertypeDefinition["author"] = sol::readonly_property([](TES3::GameFile& self) -> const char* { return self.author; });;
			usertypeDefinition["description"] = sol::readonly_property([](TES3::GameFile& self) -> const char* { return self.description; });
			usertypeDefinition["currentHealth"] = sol::readonly_property([](TES3::GameFile& self) { return self.gmdt.currentHealth; });
			usertypeDefinition["maxHealth"] = sol::readonly_property([](TES3::GameFile& self) { return self.gmdt.currentHealth; });
			usertypeDefinition["gameHour"] = sol::readonly_property([](TES3::GameFile& self) { return self.gmdt.gameHour; });
			usertypeDefinition["day"] = sol::readonly_property([](TES3::GameFile& self) { return self.gmdt.day; });
			usertypeDefinition["month"] = sol::readonly_property([](TES3::GameFile& self) { return self.gmdt.month; });
			usertypeDefinition["year"] = sol::readonly_property([](TES3::GameFile& self) { return self.gmdt.year; });
			usertypeDefinition["cellName"] = sol::readonly_property([](TES3::GameFile& self) -> const char* { return self.gmdt.cellName; });
			usertypeDefinition["daysPassed"] = sol::readonly_property([](TES3::GameFile& self) { return self.gmdt.daysPassed; });
			usertypeDefinition["playerName"] = sol::readonly_property([](TES3::GameFile& self) -> const char* { return self.gmdt.playerName; });
			usertypeDefinition["fileSize"] = sol::readonly_property([](TES3::GameFile& self) { return double(self.getFileSize()); });
			usertypeDefinition["modifiedTime"] = sol::readonly_property([](TES3::GameFile& self) { return double(self.getModifiedTime()); });

			// Access to other objects that need to be packaged.
			usertypeDefinition["masters"] = sol::readonly_property([](TES3::GameFile& self) {
				auto& luaManager = mwse::lua::LuaManager::getInstance();
				auto stateHandle = luaManager.getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table t = state.create_table();
				TES3::GameFile* master = self.arrayMasters;
				for (int i = 1, count = self.masterNames->size; i <= count; ++i, ++master) {
					t[i] = master;
				}
				return t;
			});

			// Function bindings.
			usertypeDefinition["deleteFile"] = [](TES3::GameFile& self) { self.deleteFile(); };
		}
	}
}
