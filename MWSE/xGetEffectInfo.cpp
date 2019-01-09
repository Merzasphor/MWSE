/************************************************************************
	
	xGetEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3MagicEffect.h"
#include "TES3Skill.h"
#include "TES3Spell.h"

using namespace mwse;

namespace mwse
{
	class xGetEffectInfo : mwse::InstructionInterface_t
	{
	public:
		xGetEffectInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetEffectInfo xGetEffectInfoInstance;

	xGetEffectInfo::xGetEffectInfo() : mwse::InstructionInterface_t(OpCode::xGetEffectInfo) {}

	void xGetEffectInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetEffectInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		long effectType = Stack::getInstance().popLong();
		mwseString& effectId = virtualMachine.getString(Stack::getInstance().popLong());
		long effectIndex = Stack::getInstance().popLong();

		// Return values.
		long effectEnumId = TES3::EffectID::None;
		long skillAttributeId = 0;
		long rangeType = 0;
		long area = 0;
		long duration = 0;
		long magMin = 0;
		long magMax = 0;

		// Validate effect index.
		if (effectIndex >= 1 && effectIndex <= 8) {
			// Get the desired effect.
			TES3::Effect* effect = NULL;
			if (effectType == TES3::ObjectType::Spell) {
				TES3::Spell* spell = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Spell>(effectId.c_str(), TES3::ObjectType::Spell);
				if (spell) {
					effect = &spell->effects[effectIndex - 1];
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xGetEffectInfo: No spell record found with id '" << effectId << "'." << std::endl;
#endif
				}
			}
			else if (effectType == TES3::ObjectType::Enchantment) {
				TES3::Enchantment* enchant = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Enchantment>(effectId.c_str(), TES3::ObjectType::Enchantment);
				if (enchant) {
					effect = &enchant->effects[effectIndex - 1];
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xGetEffectInfo: No enchant record found with id '" << effectId << "'." << std::endl;
#endif
				}
			}
			else if (effectType == TES3::ObjectType::Alchemy) {
				TES3::Alchemy* alchemy = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Alchemy>(effectId.c_str(), TES3::ObjectType::Alchemy);
				if (alchemy) {
					effect = &alchemy->effects[effectIndex - 1];
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xGetEffectInfo: No alchemy record found with id '" << effectId << "'." << std::endl;
#endif
				}
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetEffectInfo: Record type of " << effectType << " is not supported." << std::endl;
#endif
			}

			// If we found an effect, set the values.
			if (effect && effect->effectID != TES3::EffectID::None) {
				effectEnumId = effect->effectID;
				int effectFlags = tes3::getBaseEffectFlags()[effectEnumId];
				if (effectFlags & TES3::EffectFlag::TargetSkill) {
					skillAttributeId = effect->skillID;
				}
				else if (effectFlags & TES3::EffectFlag::TargetAttribute) {
					skillAttributeId = effect->attributeID;
				}
				else {
					skillAttributeId = TES3::SkillID::Invalid;
				}
				rangeType = int(effect->rangeType);
				area = effect->radius;
				duration = effect->duration;
				magMin = effect->magnitudeMin;
				magMax = effect->magnitudeMax;
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetEffectInfo: Invalid effect index. Value must be between 1 and 8." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(magMax);
		mwse::Stack::getInstance().pushLong(magMin);
		mwse::Stack::getInstance().pushLong(duration);
		mwse::Stack::getInstance().pushLong(area);
		mwse::Stack::getInstance().pushLong(rangeType);
		mwse::Stack::getInstance().pushLong(skillAttributeId);
		mwse::Stack::getInstance().pushLong(effectEnumId);

		return 0.0f;
	}
}