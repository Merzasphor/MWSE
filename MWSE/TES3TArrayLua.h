#pragma once

#include "TES3Collections.h"

#include "LuaUtil.h"

#include <cstddef>

namespace mwse {
	namespace lua {
		//
		// TES3::TArray<T>
		//

		template <typename T>
		struct TArray_iteratorState {
			TES3::TArray<T> * tarray;
			int index;

			TArray_iteratorState(TES3::TArray<T> * ta) {
				tarray = ta;
				index = 0;
			}
		};

		template <typename T>
		sol::optional<std::tuple<int, sol::object>> bindTArray_pairsIter(sol::user<TArray_iteratorState<T>&> user_state, sol::this_state l) {
			TArray_iteratorState<T>& state = user_state;
			if (state.index >= state.tarray->endIndex) {
				return sol::optional<std::tuple<int, sol::object>>();
			}

			auto values = std::make_tuple(state.index, sol::object(l, sol::in_place, state.tarray->storage[state.index]));
			state.index++;
			return values;
		}

		template <typename T>
		sol::optional<std::tuple<int, sol::object>> bindTArray_ipairsIter(TES3::TArray<T> * tarray, int index, sol::this_state l) {
			if (++index > tarray->endIndex) {
				return sol::optional<std::tuple<int, sol::object>>();
			}

			return std::make_tuple(index, sol::object(l, sol::in_place, tarray->storage[index - 1]));
		}

		template <typename T>
		void bindTArray(const char* name) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::TArray<T>>(name);
			usertypeDefinition["new"] = sol::no_constructor;

			// Metafunction access.
			usertypeDefinition[sol::meta_function::pairs] = [](TES3::TArray<T> * self) {
				TArray_iteratorState<T> it_state(self);
				return std::make_tuple(&bindTArray_pairsIter<T>, sol::user<TArray_iteratorState<T>>(std::move(it_state)), sol::lua_nil);
				};
			usertypeDefinition[sol::meta_function::ipairs] = [](TES3::TArray<T> * self) {
				return std::make_tuple(&bindTArray_ipairsIter<T>, self, 0);
				};
			usertypeDefinition[sol::meta_function::index] = [](TES3::TArray<T>& self, int index) {
				index--;
				if (index < 0 || index >= self.endIndex) {
					throw std::out_of_range("Access index out of bounds.");
				}
				return self.storage[index];
				};
			usertypeDefinition[sol::meta_function::length] = [](TES3::TArray<T>& self) { return self.endIndex; };

			// Function binding.
			usertypeDefinition["getIndexOfValue"] = [](TES3::TArray<T> * self, T * value) {
				return self->getIndexOfValue(value);
				};
			usertypeDefinition["contains"] = [](TES3::TArray<T> * self, T * value) {
				return self->contains(value);
				};
		}

		template <typename T>
		sol::optional<std::tuple<int, sol::object>> bindGenericObjectTArray_pairsIter(sol::user<TArray_iteratorState<T>&> user_state, sol::this_state l) {
			TArray_iteratorState<T>& state = user_state;
			if (state.index >= state.tarray->endIndex) {
				return sol::optional<std::tuple<int, sol::object>>();
			}

			auto values = std::make_tuple(state.index, sol::object(l, sol::in_place, makeLuaObject(state.tarray->storage[state.index])));
			state.index++;
			return values;
		}

		template <typename T>
		sol::optional<std::tuple<int, sol::object>> bindGenericObjectTArray_ipairsIter(TES3::TArray<T> * tarray, int index, sol::this_state l) {
			if (++index > tarray->endIndex) {
				return sol::optional<std::tuple<int, sol::object>>();
			}

			return std::make_tuple(index, sol::object(l, sol::in_place, makeLuaObject(tarray->storage[index - 1])));
		}

		template <typename T>
		void bindGenericObjectTArray(const char* name) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::TArray<T>>(name);
			usertypeDefinition["new"] = sol::no_constructor;

			// Metafunction access.
			usertypeDefinition[sol::meta_function::pairs] = [](TES3::TArray<T> * self) {
				TArray_iteratorState<T> it_state(self);
				return std::make_tuple(&bindGenericObjectTArray_pairsIter<T>, sol::user<TArray_iteratorState<T>>(std::move(it_state)), sol::lua_nil);
				};
			usertypeDefinition[sol::meta_function::ipairs] = [](TES3::TArray<T> * self) {
				return std::make_tuple(&bindGenericObjectTArray_ipairsIter<T>, self, 0);
				};
			usertypeDefinition[sol::meta_function::index] = [](TES3::TArray<T>& self, int index) {
				index--;
				if (index < 0 || index >= self.endIndex) {
					throw std::out_of_range("Access index out of bounds.");
				}
				return makeLuaObject(self.storage[index]);
				};
			usertypeDefinition[sol::meta_function::length] = [](TES3::TArray<T>& self) { return self.endIndex; };

			// Function binding.
			usertypeDefinition["getIndexOfValue"] = [](TES3::TArray<T> * self, T * value) {
				return self->getIndexOfValue(value);
				};
			usertypeDefinition["contains"] = [](TES3::TArray<T> * self, T * value) {
				return self->contains(value);
				};
		}

		//
		//
		//

		void bindTES3TArray();
	}
}
