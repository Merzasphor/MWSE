#pragma once

#include "NIObjectLua.h"
#include "NIDynamicEffect.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::AVObject.
		template <typename T>
		void setUserdataForNINode(sol::simple_usertype<T>& usertypeDefinition) {
			setUserdataForNIAVObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition.set("children", sol::readonly_property(&NI::Node::children));
			usertypeDefinition.set("effectList", sol::readonly_property(&NI::Node::effectList));

			// Basic function binding.
			usertypeDefinition.set("attachChild", [](NI::Node& self, NI::AVObject * child, sol::optional<bool> useFirstAvailable) {
				self.attachChild(child, useFirstAvailable.value_or(false));
				self.updateProperties();
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

			// Functions that need their results wrapped.
			usertypeDefinition.set("getEffect", [](NI::Node& self, int type) { return makeLuaNiPointer(self.getEffect(type)); });
		}

		void bindNINode();
	}
}
