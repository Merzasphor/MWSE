#include "LuaDamagedEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3MagicEffectInstance.h"
#include "TES3MobileActor.h"
#include "TES3MobileProjectile.h"
#include "TES3Reference.h"

#include "LuaDamageEvent.h"

namespace mwse {
	namespace lua {
		namespace event {
			DamagedEvent::DamagedEvent(TES3::MobileActor* mobileActor, float damage, bool checkForKnockdown) :
				ObjectFilteredEvent("damaged", mobileActor->reference),
				m_MobileActor(mobileActor),
				m_Damage(damage),
				m_CheckForKnockdown(checkForKnockdown)
			{

			}

			sol::table DamagedEvent::createEventTable() {
				auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
				sol::state& state = stateHandle.state;
				sol::table eventData = state.create_table();

				if (m_MobileActor) {
					eventData["mobile"] = m_MobileActor;
					eventData["reference"] = m_MobileActor->reference;
				}

				if (DamageEvent::m_Attacker) {
					eventData["attacker"] = DamageEvent::m_Attacker;
					eventData["attackerReference"] = DamageEvent::m_Attacker->reference;
				}

				if (DamageEvent::m_Projectile) {
					eventData["projectile"] = DamageEvent::m_Projectile;
				}

				if (DamageEvent::m_MagicSourceInstance) {
					eventData["magicSourceInstance"] = DamageEvent::m_MagicSourceInstance;

					// Get the attacker as the caster of the spell.
					if (!DamageEvent::m_Attacker) {
						eventData["attackerReference"] = DamageEvent::m_MagicSourceInstance->caster;
						if (DamageEvent::m_MagicSourceInstance->caster) {
							eventData["attacker"] = DamageEvent::m_MagicSourceInstance->caster->getAttachedMobileActor();
						}
					}
				}
				if (DamageEvent::m_MagicEffectInstance) {
					eventData["magicEffectInstance"] = DamageEvent::m_MagicEffectInstance;
				}

				if (DamageEvent::m_Source) {
					eventData["source"] = DamageEvent::m_Source;
				}

				eventData["damage"] = m_Damage;
				eventData["checkForKnockdown"] = m_CheckForKnockdown;

				return eventData;
			}

			bool DamagedEvent::m_EventEnabled = false;
		}
	}
}
