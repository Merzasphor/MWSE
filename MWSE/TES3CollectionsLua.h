#pragma once

#include "TES3Collections.h"

#include "LuaUtil.h"

#include <cstddef>

namespace mwse {
	namespace lua {
		template <typename T>
		void bindGenericObjectIterator(const char* name, const char* nodeName = NULL) {
			sol::state& state = LuaManager::getInstance().getState();

			if (nodeName) {
				state.new_usertype<TES3::IteratorNode<T>>(nodeName,
					// Disable construction of this type.
					"new", sol::no_constructor,

					//
					// Properties
					//

					"previousNode", sol::readonly_property(&TES3::IteratorNode<T>::previous),
					"nextNode", sol::readonly_property(&TES3::IteratorNode<T>::next),
					"nodeData", sol::readonly_property([](TES3::IteratorNode<T>& self) { return makeLuaObject(self.data); })

				);
			}

			state.new_usertype<TES3::Iterator<T>>(name,
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Meta functions.
				//

				sol::meta_function::index, [](TES3::Iterator<T>& self, int index)
			{
				TES3::IteratorNode<T>* node = self.head;
				for (int i = 1; i < index; i++) {
					node = node->next;
				}
				return makeLuaObject(node->data);
			},
				sol::meta_function::length, [](TES3::Iterator<T>& self) { return self.size; },

				//
				// Properties
				//

				"size", sol::readonly_property(&TES3::Iterator<T>::size),
				"head", sol::readonly_property(&TES3::Iterator<T>::head),
				"tail", sol::readonly_property(&TES3::Iterator<T>::tail),
				"current", sol::readonly_property(&TES3::Iterator<T>::current)

			);
		}

		template <typename T>
		void bindIterator(const char* name, const char* nodeName = NULL) {
			sol::state& state = LuaManager::getInstance().getState();

			if (nodeName) {
				state.new_usertype<TES3::IteratorNode<T>>(nodeName,
					// Disable construction of this type.
					"new", sol::no_constructor,

					//
					// Properties
					//

					"previousNode", sol::readonly_property(&TES3::IteratorNode<T>::previous),
					"nextNode", sol::readonly_property(&TES3::IteratorNode<T>::next),
					"nodeData", sol::readonly_property([](TES3::IteratorNode<T>& self) { return self.data; })

					);
			}

			state.new_usertype<TES3::Iterator<T>>(name,
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Meta functions.
				//

				sol::meta_function::index, [](TES3::Iterator<T>& self, int index)
			{
				TES3::IteratorNode<T>* node = self.head;
				for (int i = 1; i < index; i++) {
					node = node->next;
				}
				return node->data;
			},
				sol::meta_function::length, [](TES3::Iterator<T>& self) { return self.size; },

				//
				// Properties
				//

				"size", sol::readonly_property(&TES3::Iterator<T>::size),
				"head", sol::readonly_property(&TES3::Iterator<T>::head),
				"tail", sol::readonly_property(&TES3::Iterator<T>::tail),
				"current", sol::readonly_property(&TES3::Iterator<T>::current)

				);
		}

		template <typename T>
		void bindTArray(const char* name) {
			LuaManager::getInstance().getState().new_usertype<TES3::TArray<T>>(name,
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Meta functions.
				//

				sol::meta_function::index, [](TES3::TArray<T>& self, int index) { return self.storage[index - 1]; },
				sol::meta_function::length, [](TES3::TArray<T>& self) { return self.filledCount; }

				);
		}

		void bindTES3Collections();
	}
}
