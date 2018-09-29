#pragma once

#include "NIObjectLua.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::AVObject.
		template <typename T>
		void setUserdataForNINode(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIAVObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("children", sol::readonly_property(&NI::Node::children));

			// Basic function binding.
			usertypeDefinition.set("attachChild", [](NI::Node& self, NI::AVObject * child, sol::optional<bool> useFirstAvailable) {
				self.attachChild(child, useFirstAvailable.value_or(false));
				self.updateTextureProperties();
			});
			usertypeDefinition.set("detachChild", [](NI::Node& self, NI::AVObject * child) {
				NI::AVObject * returnedChild = nullptr;
				self.detachChild(&returnedChild, child);
				return makeLuaNiPointer(returnedChild);
			});
			usertypeDefinition.set("detachChildAt", [](NI::Node& self, unsigned int index) -> sol::object {
				if (--index < 0) {
					return sol::nil;
				}

				NI::AVObject * returnedChild = nullptr;
				self.detachChildAt(&returnedChild, index);
				return makeLuaNiPointer(returnedChild);
			});
		}

		void bindNINode();
	}
}
