#include "TES3MobileActorLua.h"

#include "LuaManager.h"

#include "TES3MobileActor.h"
#include "TES3SpellInstanceController.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		struct ActiveMagicEffects_IteratorState {
			TES3::MobileActor::ActiveMagicEffect * current;
			TES3::MobileActor::ActiveMagicEffect * end;
		};

		std::tuple<sol::object, sol::object> ActiveMagicEffects_pairs(sol::user<ActiveMagicEffects_IteratorState&> user_it_state, sol::this_state l) {
			ActiveMagicEffects_IteratorState& it_state = user_it_state;
			if (it_state.current == it_state.end) {
				return std::make_tuple(sol::object(sol::lua_nil), sol::object(sol::lua_nil));
			}

			auto values = std::make_tuple(sol::object(l, sol::in_place, it_state.end), sol::object(l, sol::in_place, it_state.current));
			it_state.current = it_state.current->next;
			return values;
		}

		sol::optional<std::tuple<int, sol::object>> ActiveMagicEffects_ipairs(TES3::MobileActor::ActiveMagicEffects * activeMagicEffects, int index, sol::this_state l) {
			index++;

			auto firstEffect = activeMagicEffects->firstEffect;
			auto itt = firstEffect->next;
			for (int i = 1; i < index; i++) {
				itt = itt->next;
				if (itt == firstEffect) {
					return sol::optional<std::tuple<int, sol::object>>();
				}
			}

			return std::make_tuple(index, sol::object(l, sol::in_place, itt));
		}

		void bindTES3MobileActor() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::MobileActor::ActiveMagicEffects
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::MobileActor::ActiveMagicEffects>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Allow the use of # and ipairs.
				usertypeDefinition.set(sol::meta_function::pairs,
					[](TES3::MobileActor::ActiveMagicEffects& self)
					{
						ActiveMagicEffects_IteratorState itt;
						itt.current = self.firstEffect->next;
						itt.end = self.firstEffect;
						return std::make_tuple(&ActiveMagicEffects_pairs, sol::user<ActiveMagicEffects_IteratorState>(std::move(itt)), sol::lua_nil);
					}
				);
				usertypeDefinition.set(sol::meta_function::ipairs, [](TES3::MobileActor::ActiveMagicEffects& self) { return std::make_tuple(&ActiveMagicEffects_ipairs, self, 0); });
				usertypeDefinition.set(sol::meta_function::length, [](TES3::MobileActor::ActiveMagicEffects& self) { return self.count; });

				// Basic property binding.
				usertypeDefinition.set("first", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffects::firstEffect));
				usertypeDefinition.set("count", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffects::count));

				// Finish up our usertype.
				state.set_usertype("tes3activeMagicEffects", usertypeDefinition);
			}

			// Binding for TES3::MobileActor::ActiveMagicEffect
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::MobileActor::ActiveMagicEffect>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("attributeId", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::skillOrAttributeID));
				usertypeDefinition.set("duration", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::duration));
				usertypeDefinition.set("effectId", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magicEffectID));
				usertypeDefinition.set("effectIndex", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magicInstanceEffectIndex));
				usertypeDefinition.set("flag9", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::unknown_0x9));
				usertypeDefinition.set("harmful", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::isHarmful));
				usertypeDefinition.set("magnitudeMin", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magnitudeMin));
				usertypeDefinition.set("next", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::next));
				usertypeDefinition.set("previous", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::prev));
				usertypeDefinition.set("serial", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::magicInstanceSerial));
				usertypeDefinition.set("skillId", sol::readonly_property(&TES3::MobileActor::ActiveMagicEffect::skillOrAttributeID));

				// Expose easy access to the instance's magnitude.
				usertypeDefinition.set("magnitude", sol::readonly_property([](TES3::MobileActor::ActiveMagicEffect& self) {
					return TES3::WorldController::get()->spellInstanceController->getInstanceFromSerial(self.magicInstanceSerial)->getMagnitude(self.magicInstanceEffectIndex);
				}));

				// Expose quick access to the source instance.
				usertypeDefinition.set("instance", sol::readonly_property([](TES3::MobileActor::ActiveMagicEffect& self) {
					return TES3::WorldController::get()->spellInstanceController->getInstanceFromSerial(self.magicInstanceSerial);
				}));

				// Finish up our usertype.
				state.set_usertype("tes3activeMagicEffect", usertypeDefinition);
			}
		}
	}
}
