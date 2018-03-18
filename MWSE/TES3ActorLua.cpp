#include "TES3Actor.h"

#include "LuaManager.h"

namespace TES3 {
	sol::object Actor::getInventory() {
		sol::state& state = mwse::lua::LuaManager::getInstance().getState();

		sol::table result = state.create_table(1, inventory.iterator.size);
		unsigned int index = 1;
		for (auto itt = inventory.iterator.head; itt != NULL; itt = itt->next) {
			result[index] = sol::make_object(state, itt->data);
			index++;
		}
		return result;
	}

