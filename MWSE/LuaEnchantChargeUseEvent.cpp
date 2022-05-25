#include "LuaEnchantChargeUseEvent.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Enchantment.h"
#include "TES3MobileActor.h"
#include "TES3Reference.h"

namespace mwse::lua::event {
	EnchantChargeUseEvent::EnchantChargeUseEvent(TES3::Enchantment* enchant, TES3::MobileActor* caster, float chargeRequired, bool isCast) :
		GenericEvent("enchantChargeUse"),
		m_Enchant(enchant),
		m_Caster(caster),
		m_ChargeRequired(chargeRequired),
		m_IsCast(isCast)
	{

	}

	sol::table EnchantChargeUseEvent::createEventTable() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		auto& state = stateHandle.state;
		auto eventData = state.create_table();

		eventData["caster"] = m_Caster->reference;
		eventData["source"] = m_Enchant;
		eventData["charge"] = m_ChargeRequired;
		eventData["isCast"] = m_IsCast;

		return eventData;
	}

	sol::object EnchantChargeUseEvent::getEventOptions() {
		auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
		auto& state = stateHandle.state;
		auto options = state.create_table();

		options["filter"] = m_Caster->reference;

		return options;
	}

	bool EnchantChargeUseEvent::m_EventEnabled = false;
}
