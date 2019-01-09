/************************************************************************
	
	xSetEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetEffectInfo : mwse::InstructionInterface_t
	{
	public:
		xSetEffectInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetEffectInfo xSetEffectInfoInstance;

	xSetEffectInfo::xSetEffectInfo() : mwse::InstructionInterface_t(OpCode::xSetEffectInfo) {}

	void xSetEffectInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetEffectInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		long targetType = Stack::getInstance().popLong();
		mwseString& targetId = virtualMachine.getString(Stack::getInstance().popLong());
		long effectIndex = Stack::getInstance().popLong();
		long effectId = Stack::getInstance().popLong();
		long effectSkillAttributeId = Stack::getInstance().popLong();
		long effectRange = Stack::getInstance().popLong();
		long effectArea = Stack::getInstance().popLong();
		long effectDuration = Stack::getInstance().popLong();
		long effectMagMin = Stack::getInstance().popLong();
		long effectMagMax = Stack::getInstance().popLong();

		bool result = false;

		// Validate effect index.
		if (effectIndex >= 1 && effectIndex <= 8) {
			// Get the desired effect.
			TES3::Effect* effects = NULL;
			if (targetType == TES3::ObjectType::Spell) {
				TES3::Spell* spell = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Spell>(targetId, TES3::ObjectType::Spell);
				if (spell) {
					effects = spell->effects;
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xSetEffectInfo: No spell record found with id '" << targetId << "'." << std::endl;
#endif
				}
			}
			else if (targetType == TES3::ObjectType::Enchantment) {
				TES3::Enchantment* enchant = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Enchantment>(targetId, TES3::ObjectType::Enchantment);
				if (enchant) {
					effects = enchant->effects;
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xSetEffectInfo: No enchant record found with id '" << targetId << "'." << std::endl;
#endif
				}
			}
			else if (targetType == TES3::ObjectType::Alchemy) {
				TES3::Alchemy* alchemy = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Alchemy>(targetId, TES3::ObjectType::Alchemy);
				if (alchemy) {
					effects = alchemy->effects;
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xSetEffectInfo: No alchemy record found with id '" << targetId << "'." << std::endl;
#endif
				}
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xSetEffectInfo: Record type of " << targetType << " is not supported." << std::endl;
#endif
			}

			// If we found an effect, set the values.
			if (effects) {
				result = tes3::setEffect(effects, effectIndex, effectId, effectSkillAttributeId, effectRange, effectArea, effectDuration, effectMagMin, effectMagMax);
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xSetEffectInfo: Invalid effect index. Value must be between 1 and 8." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(result);
		return 0.0f;
	}
}