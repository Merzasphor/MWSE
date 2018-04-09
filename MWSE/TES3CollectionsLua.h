#pragma once

namespace mwse {
	namespace lua {
		template <typename T>
		void bindTArray(const char* name) {
			LuaManager::getInstance().getState().new_usertype<TES3::TArray<T>>(name,
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Meta functions.
				//

				sol::meta_function::index, [](TES3::TArray<T>& self, int index) { return self.storage[index]; },
				sol::meta_function::length, [](TES3::TArray<T>& self) { return self.storageCount; }

				);
		}

		void bindTES3Collections();
	}
}
