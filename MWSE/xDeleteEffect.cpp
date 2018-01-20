/************************************************************************
	
	xDeleteEffect.cpp - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

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

	static const mwse::mwOpcode_t xDeleteEffectOpcode = 0x3945;
	static xDeleteEffect xDeleteEffectInstance;

	xDeleteEffect::xDeleteEffect() : mwse::InstructionInterface_t(xDeleteEffectOpcode) {}

	void xDeleteEffect::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xDeleteEffect::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwLong_t type = mwse::Stack::getInstance().popLong();
		mwseString_t& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		mwLong_t effectIndex = mwse::Stack::getInstance().popLong() - 1; // 0-based index.
		
		// Get the desired effect.
		Effect_t* effects = NULL;
		if (type == RecordTypes::SPELL) {
			SPELRecord_t* spell = tes3::getSpellRecordById(id);
			if (spell) {
				effects = spell->effects;
			}
			else {
				mwse::log::getLog() << "xDeleteEffect: No spell found with id '" << id << "'." << std::endl;
				mwse::Stack::getInstance().pushLong(false);
				return 0.0f;
			}
		}
		else if (type == RecordTypes::ENCH) {
			ENCHRecord_t* enchant = tes3::getEnchantRecordById(id);
			if (enchant) {
				effects = enchant->effects;
			}
			else {
				mwse::log::getLog() << "xDeleteEffect: No spell found with id '" << id << "'." << std::endl;
				mwse::Stack::getInstance().pushLong(false);
				return 0.0f;
			}
		}
		else {
			mwse::log::getLog() << "xDeleteEffect: Record type of " << type << " is not supported." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get effect count.
		size_t effectCount = tes3::getEffectCount(effects);
		if (effectCount == 0 || effectIndex >= effectCount) {
			mwse::log::getLog() << "xDeleteEffect: Effect index out of range for effect." << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Disable the effect.
		effects[effectIndex].effectId = Effects::NoEffect;

		// Move effects beyond the given index forward to fill the gap.
		for (size_t i = effectIndex + 1; i < effectCount; i++) {
			effects[i - 1] = effects[i];
			effects[i].effectId = Effects::NoEffect;
		}

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}