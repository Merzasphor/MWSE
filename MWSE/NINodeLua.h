#pragma once

#include "NIObjectLua.h"
#include "NIDynamicEffect.h"

namespace mwse {
	namespace lua {
		// Speed-optimized binding for NI::Node.
		template <typename T>
		void setUserdataForNINode(T& usertypeDefinition) {
			setUserdataForNIAVObject(usertypeDefinition);

			// Basic property binding.
			usertypeDefinition["children"] = sol::readonly_property(&NI::Node::children);
			usertypeDefinition["effectList"] = sol::readonly_property(&NI::Node::effectList);

			// Basic function binding.
			usertypeDefinition["attachChild"] = [](NI::Node& self, NI::AVObject * child, sol::optional<bool> useFirstAvailable) {
				self.attachChild(child, useFirstAvailable.value_or(false));
				self.updateProperties();
			};
			usertypeDefinition["detachChild"] = [](NI::Node& self, NI::AVObject * child)-> NI::Pointer<NI::AVObject> {
				NI::AVObject * returnedChild = nullptr;
				self.detachChild(&returnedChild, child);
				return returnedChild;
			};
			usertypeDefinition["detachChildAt"] = [](NI::Node& self, unsigned int index) -> NI::Pointer<NI::AVObject> {
				if (--index < 0) {
					return nullptr;
				}

				NI::AVObject * returnedChild = nullptr;
				self.detachChildAt(&returnedChild, index);
				return returnedChild;
			};
			usertypeDefinition["attachEffect"] = &NI::Node::attachEffect;
			usertypeDefinition["detachEffect"] = &NI::Node::detachEffect;

			// Functions that need their results wrapped.
			usertypeDefinition["getEffect"] = [](NI::Node& self, int type) { return self.getEffect(type); };
		}

		void bindNINode();
	}
}
