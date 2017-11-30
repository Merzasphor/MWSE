/************************************************************************
	
	xGetSpellEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetSpellEffectInfo : mwse::InstructionInterface_t
	{
	public:
		xGetSpellEffectInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xGetSpellEffectInfoOpcode = 0x3925;
	static xGetSpellEffectInfo xGetSpellEffectInfoInstance;

	xGetSpellEffectInfo::xGetSpellEffectInfo() : mwse::InstructionInterface_t(xGetSpellEffectInfoOpcode) {}

	void xGetSpellEffectInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetSpellEffectInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString_t effectId = virtualMachine.getString(Stack::getInstance().popLong());
		mwShort_t effectIndex = Stack::getInstance().popShort();

		// Return values.
		mwLong_t effectEnumId = Effects::NoEffect;
		mwLong_t rangeType = 0;
		mwLong_t area = 0;
		mwLong_t duration = 0;
		mwLong_t magMin = 0;
		mwLong_t magMax = 0;

		// Validate effect index.
		if (effectIndex >= 1 && effectIndex <= 8) {
			// Get the desired effect.
			SPELRecord_t* spell = tes3::getSpellRecordById(effectId);
			if (spell) {
				Effect_t* effect = &spell->effects[effectIndex - 1];
				// If we found an effect, set the values.
				if (effect && effect->effectId != Effects::NoEffect) {
					effectEnumId = effect->effectId;
					rangeType = effect->rangeType;
					area = effect->area;
					duration = effect->duration;
					magMin = effect->magMin;
					magMax = effect->magMax;
				}
			}
			else {
				mwse::log::getLog() << "xGetSpellEffectInfo: No spell found with id '" << effectId << "'." << std::endl;
			}
		}
		else {
			mwse::log::getLog() << "xGetSpellEffectInfo: Invalid effect index. Value must be between 1 and 8." << std::endl;
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