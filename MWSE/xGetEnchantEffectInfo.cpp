/************************************************************************
	
	xGetEnchantEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3DataHandler.h"
#include "TES3Enchantment.h"

using namespace mwse;

namespace mwse
{
	class xGetEnchantEffectInfo : mwse::InstructionInterface_t
	{
	public:
		xGetEnchantEffectInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetEnchantEffectInfo xGetEnchantEffectInfoInstance;

	xGetEnchantEffectInfo::xGetEnchantEffectInfo() : mwse::InstructionInterface_t(OpCode::xGetEnchantEffectInfo) {}

	void xGetEnchantEffectInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetEnchantEffectInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& effectId = virtualMachine.getString(Stack::getInstance().popLong());
		short effectIndex = Stack::getInstance().popShort();

		// Return values.
		long effectEnumId = TES3::EffectID::None;
		long rangeType = 0;
		long area = 0;
		long duration = 0;
		long magMin = 0;
		long magMax = 0;

		// Validate effect index.
		if (effectIndex >= 1 && effectIndex <= 8) {
			// Get the desired effect.
			TES3::Enchantment* enchant = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Enchantment>(effectId, TES3::ObjectType::Enchantment);
			if (enchant) {
				TES3::Effect* effect = &enchant->effects[effectIndex - 1];
				// If we found an effect, set the values.
				if (effect && effect->effectID != TES3::EffectID::None) {
					effectEnumId = effect->effectID;
					rangeType = int(effect->rangeType);
					area = effect->radius;
					duration = effect->duration;
					magMin = effect->magnitudeMin;
					magMax = effect->magnitudeMax;
				}
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetEnchantEffectInfo: No spell found with id '" << effectId << "'." << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetEnchantEffectInfo: Invalid effect index. Value must be between 1 and 8." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(magMax);
		mwse::Stack::getInstance().pushLong(magMin);
		mwse::Stack::getInstance().pushLong(duration);
		mwse::Stack::getInstance().pushLong(area);
		mwse::Stack::getInstance().pushLong(rangeType);
		mwse::Stack::getInstance().pushLong(effectEnumId);

		return 0.0f;
	}
}