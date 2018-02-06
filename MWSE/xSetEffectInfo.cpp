/************************************************************************
	
	xSetEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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
		mwLong_t targetType = Stack::getInstance().popLong();
		mwseString_t& targetId = virtualMachine.getString(Stack::getInstance().popLong());
		mwLong_t effectIndex = Stack::getInstance().popLong();
		mwLong_t effectId = Stack::getInstance().popLong();
		mwLong_t effectSkillAttributeId = Stack::getInstance().popLong();
		mwLong_t effectRange = Stack::getInstance().popLong();
		mwLong_t effectArea = Stack::getInstance().popLong();
		mwLong_t effectDuration = Stack::getInstance().popLong();
		mwLong_t effectMagMin = Stack::getInstance().popLong();
		mwLong_t effectMagMax = Stack::getInstance().popLong();

		bool result = false;

		// Validate effect index.
		if (effectIndex >= 1 && effectIndex <= 8) {
			// Get the desired effect.
			Effect_t* effects = NULL;
			if (targetType == RecordTypes::SPELL) {
				SPELRecord_t* spell = tes3::getSpellRecordById(targetId);
				if (spell) {
					effects = spell->effects;
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xSetEffectInfo: No spell record found with id '" << targetId << "'." << std::endl;
#endif
				}
			}
			else if (targetType == RecordTypes::ENCH) {
				ENCHRecord_t* enchant = tes3::getEnchantRecordById(targetId);
				if (enchant) {
					effects = enchant->effects;
				}
				else {
#if _DEBUG
					mwse::log::getLog() << "xSetEffectInfo: No enchant record found with id '" << targetId << "'." << std::endl;
#endif
				}
			}
			else if (targetType == RecordTypes::ALCHEMY) {
				ALCHRecord_t* alchemy = tes3::getAlchemyRecordById(targetId);
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