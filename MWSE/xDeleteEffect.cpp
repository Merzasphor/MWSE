/************************************************************************
	
	xDeleteEffect.cpp - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3Alchemy.h"
#include "TES3DataHandler.h"
#include "TES3Enchantment.h"
#include "TES3Spell.h"

using namespace mwse;

namespace mwse
{
	class xDeleteEffect : mwse::InstructionInterface_t
	{
	public:
		xDeleteEffect();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xDeleteEffect xDeleteEffectInstance;

	xDeleteEffect::xDeleteEffect() : mwse::InstructionInterface_t(OpCode::xDeleteEffect) {}

	void xDeleteEffect::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xDeleteEffect::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		long type = mwse::Stack::getInstance().popLong();
		mwseString& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		long effectIndex = mwse::Stack::getInstance().popLong() - 1; // 0-based index.
		size_t effectCount = 0;
		
		// Get the desired effect.
		TES3::Effect* effects = NULL;
		if (type == TES3::ObjectType::Spell) {
			TES3::Spell* spell = TES3::DataHandler::get()->nonDynamicData->getSpellById(id.c_str());
			if (spell) {
				effects = spell->effects;
				effectCount = spell->getActiveEffectCount();
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xDeleteEffect: No spell found with id '" << id << "'." << std::endl;
#endif
				mwse::Stack::getInstance().pushLong(false);
				return 0.0f;
			}
		}
		else if (type == TES3::ObjectType::Enchantment) {
			TES3::Enchantment* enchant = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Enchantment>(id.c_str(), TES3::ObjectType::Enchantment);
			if (enchant) {
				effects = enchant->effects;
				effectCount = enchant->getActiveEffectCount();
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xDeleteEffect: No spell found with id '" << id << "'." << std::endl;
#endif
				mwse::Stack::getInstance().pushLong(false);
				return 0.0f;
			}
		}
		else if (type == TES3::ObjectType::Alchemy) {
			TES3::Alchemy* alchemy = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Alchemy>(id.c_str(), TES3::ObjectType::Alchemy);
			if (alchemy) {
				effects = alchemy->effects;
				effectCount = alchemy->getActiveEffectCount();
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xDeleteEffect: No alchemy record found with id '" << id << "'." << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xDeleteEffect: Record type of " << type << " is not supported." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Verify that the effect can be deleted.
		if (effectCount == 1) {
#if _DEBUG
			mwse::log::getLog() << "xDeleteEffect: Effect count must be at least one." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}
		else if (effectIndex >= effectCount) {
#if _DEBUG
			mwse::log::getLog() << "xDeleteEffect: Effect index out of range for effect." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Disable the effect.
		effects[effectIndex].effectID = TES3::EffectID::None;

		// Move effects beyond the given index forward to fill the gap.
		for (size_t i = effectIndex + 1; i < effectCount; i++) {
			effects[i - 1] = effects[i];
			effects[i].effectID = TES3::EffectID::None;
		}

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}