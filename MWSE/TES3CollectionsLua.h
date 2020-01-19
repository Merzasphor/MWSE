#pragma once

#include "TES3Collections.h"

#include "LuaUtil.h"

#include <cstddef>

namespace mwse {
	namespace lua {
		//
		// TES3::Iterator<T>
		//

		template <typename T>
		struct Iterator_state {
			TES3::IteratorNode<T> * it;

			Iterator_state(TES3::Iterator<T> * list) {
				it = list->head;
			}
		};

		std::tuple<sol::object, TES3::BaseObject*> bindGenericObjectIterator_pairsNext(sol::user<Iterator_state<TES3::BaseObject>&> user_it_state, sol::this_state l);

		template <typename T>
		std::tuple<sol::object, sol::object> bindIterator_pairsNext(sol::user<Iterator_state<T>&> user_it_state, sol::this_state l) {
			Iterator_state<T>& it_state = user_it_state;
			if (it_state.it == nullptr) {
				return std::make_tuple(sol::object(sol::lua_nil), sol::object(sol::lua_nil));
			}

			auto values = std::make_tuple(sol::object(l, sol::in_place, it_state.it), sol::object(l, sol::in_place, it_state.it->data));
			it_state.it = it_state.it->next;
			return values;
		}

		template <typename T>
		void bindGenericObjectIterator(const char* name, const char* nodeName = NULL) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			if (nodeName) {
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::IteratorNode<T>>(nodeName);
				usertypeDefinition["new"] = sol::no_constructor;

				//
				usertypeDefinition["previousNode"] = sol::readonly_property(&TES3::IteratorNode<T>::previous);
				usertypeDefinition["nextNode"] = sol::readonly_property(&TES3::IteratorNode<T>::next);
				usertypeDefinition["nodeData"] = sol::readonly_property([](TES3::IteratorNode<T>& self) { return self.data; });
			}

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::Iterator<T>>(name);
			usertypeDefinition["new"] = sol::no_constructor;

			// Metamethod binding.
			usertypeDefinition[sol::meta_function::pairs] = [](TES3::Iterator<T> * self) {
				Iterator_state<TES3::BaseObject> it_state(reinterpret_cast<TES3::Iterator<TES3::BaseObject>*>(self));
				return std::make_tuple(&bindGenericObjectIterator_pairsNext, sol::user<Iterator_state<TES3::BaseObject>>(std::move(it_state)), sol::lua_nil);
			};
			usertypeDefinition[sol::meta_function::index] = [](TES3::Iterator<T>& self, int index) {
				TES3::IteratorNode<T>* node = self.head;
				for (int i = 1; i < index; i++) {
					node = node->next;
				}
				return node->data;
			};
			usertypeDefinition[sol::meta_function::length] = [](TES3::Iterator<T>& self) { return self.size; };

			//
			usertypeDefinition["size"] = sol::readonly_property(&TES3::Iterator<T>::size);
			usertypeDefinition["head"] = sol::readonly_property(&TES3::Iterator<T>::head);
			usertypeDefinition["tail"] = sol::readonly_property(&TES3::Iterator<T>::tail);
			usertypeDefinition["current"] = sol::readonly_property(&TES3::Iterator<T>::current);
		}

		template <typename T>
		void bindIterator(const char* name, const char* nodeName = NULL) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			if (nodeName) {
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::IteratorNode<T>>(nodeName);
				usertypeDefinition["new"] = sol::no_constructor;

				//
				usertypeDefinition["previousNode"] = sol::readonly_property(&TES3::IteratorNode<T>::previous);
				usertypeDefinition["nextNode"] = sol::readonly_property(&TES3::IteratorNode<T>::next);
				usertypeDefinition["nodeData"] = sol::readonly_property([](TES3::IteratorNode<T>& self) { return self.data; });
			}

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::Iterator<T>>(name);
			usertypeDefinition["new"] = sol::no_constructor;

			// Metamethod binding.
			usertypeDefinition[sol::meta_function::pairs] = [](TES3::Iterator<T> * self) {
				Iterator_state<T> it_state(self);
				return std::make_tuple(&bindIterator_pairsNext<T>, sol::user<Iterator_state<T>>(std::move(it_state)), sol::lua_nil);
			};
			usertypeDefinition[sol::meta_function::index] = [](TES3::Iterator<T>& self, int index) {
				TES3::IteratorNode<T>* node = self.head;
				for (int i = 1; i < index; i++) {
					node = node->next;
				}
				return node->data;
			};
			usertypeDefinition[sol::meta_function::length] = [](TES3::Iterator<T>& self) { return self.size; };

			//
			usertypeDefinition["size"] = sol::readonly_property(&TES3::Iterator<T>::size);
			usertypeDefinition["head"] = sol::readonly_property(&TES3::Iterator<T>::head);
			usertypeDefinition["tail"] = sol::readonly_property(&TES3::Iterator<T>::tail);
			usertypeDefinition["current"] = sol::readonly_property(&TES3::Iterator<T>::current);
		}

		//
		// TES3::StlList<T>
		//

		struct GenericObjectStlList_iteratorState {
			TES3::StlListNode<TES3::Object> * it;

			GenericObjectStlList_iteratorState(TES3::StlList<TES3::Object> * list) {
				it = list->head;
			}
		};

		std::tuple<sol::object, TES3::BaseObject*> bindGenericObjectStlList_pairsNext(sol::user<GenericObjectStlList_iteratorState&> user_it_state, sol::this_state l);

		template <typename T>
		void bindGenericObjectStlList(const char* name, const char* nodeName = NULL) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			if (nodeName) {
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::StlListNode<T>>(nodeName);
				usertypeDefinition["new"] = sol::no_constructor;

				//
				usertypeDefinition["previousNode"] = sol::readonly_property(&TES3::StlListNode<T>::previous);
				usertypeDefinition["nextNode"] = sol::readonly_property(&TES3::StlListNode<T>::next);
				usertypeDefinition["nodeData"] = sol::readonly_property([](TES3::StlListNode<T>& self) { return self.data; });
			}

			// Start our usertype. We must finish this with state.set_usertype.
			auto usertypeDefinition = state.new_usertype<TES3::StlList<T>>(name);
			usertypeDefinition["new"] = sol::no_constructor;

			// Metamethod binding.
			usertypeDefinition[sol::meta_function::pairs] = [](TES3::StlList<T> * self) {
				GenericObjectStlList_iteratorState it_state(reinterpret_cast<TES3::StlList<TES3::Object>*>(self));
				return std::make_tuple(&bindGenericObjectStlList_pairsNext, sol::user<GenericObjectStlList_iteratorState>(std::move(it_state)), sol::lua_nil);
			};
			usertypeDefinition[sol::meta_function::index] = [](TES3::StlList<T>& self, int index) {
				TES3::StlListNode<T>* node = self.head;
				for (int i = 1; i < index; i++) {
					node = node->next;
				}
				return node->data;
			};
			usertypeDefinition[sol::meta_function::length] = [](TES3::StlList<T>& self, int index) {
				return self.size;
			};

			// Basic property binding.
			usertypeDefinition["size"] = sol::readonly_property(&TES3::StlList<T>::size);
			usertypeDefinition["head"] = sol::readonly_property(&TES3::StlList<T>::head);
			usertypeDefinition["tail"] = sol::readonly_property(&TES3::StlList<T>::tail);
		}

		//
		//
		//

		void bindTES3Collections();
	}
}
