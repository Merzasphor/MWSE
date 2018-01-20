/************************************************************************
	
	xGetEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetEffectInfo : mwse::InstructionInterface_t
	{
	public:
		xGetEffectInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xGetEffectInfoOpcode = 0x3943;
	static xGetEffectInfo xGetEffectInfoInstance;

	xGetEffectInfo::xGetEffectInfo() : mwse::InstructionInterface_t(xGetEffectInfoOpcode) {}

	void xGetEffectInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetEffectInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwLong_t effectType = Stack::getInstance().popLong();
		mwseString_t& effectId = virtualMachine.getString(Stack::getInstance().popLong());
		mwLong_t effectIndex = Stack::getInstance().popLong();

		// Return values.
		mwLong_t effectEnumId = Effects::NoEffect;
		mwLong_t skillAttributeId = 0;
		mwLong_t rangeType = 0;
		mwLong_t area = 0;
		mwLong_t duration = 0;
		mwLong_t magMin = 0;
		mwLong_t magMax = 0;

		// Validate effect index.
		if (effectIndex >= 1 && effectIndex <= 8) {
			// Get the desired effect.
			Effect_t* effect = NULL;
			if (effectType == RecordTypes::SPELL) {
				SPELRecord_t* spell = tes3::getSpellRecordById(effectId);
				if (spell) {
					effect = &spell->effects[effectIndex - 1];
				}
				else {
					mwse::log::getLog() << "xGetEffectInfo: No spell found with id '" << effectId << "'." << std::endl;
				}
			}
			else if (effectType == RecordTypes::ENCH) {
				ENCHRecord_t* enchant = tes3::getEnchantRecordById(effectId);
				if (enchant) {
					effect = &enchant->effects[effectIndex - 1];
				}
				else {
					mwse::log::getLog() << "xGetEffectInfo: No spell found with id '" << effectId << "'." << std::endl;
				}
			}
			else {
				mwse::log::getLog() << "xGetEffectInfo: Record type of " << effectType << " is not supported." << std::endl;
			}

			// If we found an effect, set the values.
			if (effect && effect->effectId != Effects::NoEffect) {
				effectEnumId = effect->effectId;
				int effectFlags = Effects::MagicEffectFlagMap[effectEnumId];
				if (effectFlags & Effects::TargetSkill) {
					skillAttributeId = effect->skillId;
				}
				else if (effectFlags & Effects::TargetAttribute) {
					skillAttributeId = effect->attributeId;
				}
				else {
					skillAttributeId = NoSkill;
				}
				rangeType = effect->rangeType;
				area = effect->area;
				duration = effect->duration;
				magMin = effect->magMin;
				magMax = effect->magMax;
			}
		}
		else {
			mwse::log::getLog() << "xGetEffectInfo: Invalid effect index. Value must be between 1 and 8." << std::endl;
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