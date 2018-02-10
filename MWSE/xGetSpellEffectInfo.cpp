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

	static xGetSpellEffectInfo xGetSpellEffectInfoInstance;

	xGetSpellEffectInfo::xGetSpellEffectInfo() : mwse::InstructionInterface_t(OpCode::xGetSpellEffectInfo) {}

	void xGetSpellEffectInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetSpellEffectInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString_t& effectId = virtualMachine.getString(Stack::getInstance().popLong());
		mwShort effectIndex = Stack::getInstance().popShort();

		// Return values.
		mwLong effectEnumId = TES3::EffectNone;
		mwLong rangeType = 0;
		mwLong area = 0;
		mwLong duration = 0;
		mwLong magMin = 0;
		mwLong magMax = 0;

		// Validate effect index.
		if (effectIndex >= 1 && effectIndex <= 8) {
			// Get the desired effect.
			TES3::Spell* spell = tes3::getSpellRecordById(effectId);
			if (spell) {
				TES3::Effect* effect = &spell->effects[effectIndex - 1];
				// If we found an effect, set the values.
				if (effect && effect->ID != TES3::EffectNone) {
					effectEnumId = effect->ID;
					rangeType = effect->range;
					area = effect->area;
					duration = effect->duration;
					magMin = effect->magnitudeMin;
					magMax = effect->magnitudeMax;
				}
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetSpellEffectInfo: No spell found with id '" << effectId << "'." << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetSpellEffectInfo: Invalid effect index. Value must be between 1 and 8." << std::endl;
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