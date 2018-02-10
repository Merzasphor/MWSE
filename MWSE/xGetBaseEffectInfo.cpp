/************************************************************************
	
	xGetBaseEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3CellMaster.h"
#include "TES3MagicEffect.h"

using namespace mwse;

namespace mwse
{
	class xGetBaseEffectInfo : mwse::InstructionInterface_t
	{
	public:
		xGetBaseEffectInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetBaseEffectInfo xGetBaseEffectInfoInstance;

	xGetBaseEffectInfo::xGetBaseEffectInfo() : mwse::InstructionInterface_t(OpCode::xGetBaseEffectInfo) {}

	void xGetBaseEffectInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseEffectInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwLong id = Stack::getInstance().popLong();

		// Validate id.
		if (id < TES3::EffectFirst || id > TES3::EffectLast) {
#if _DEBUG
			log::getLog() << "xGetBaseEffectInfo: Effect ID out of range." << std::endl;
#endif
			Stack::getInstance().pushLong(0);
			Stack::getInstance().pushFloat(0.0f);
			Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the effect.
		TES3::MagicEffect& effect = tes3::getCellMaster()->recordLists->magicEffects[id];

		// Flags are a unique case. There is other data associated with flags that we want
		// to expose, so we will return it here.
		// TODO: Programmatically allow setting/getting these normally hard-coded values.
		Stack::getInstance().pushLong(effect.flags | TES3::MagicEffectFlagMap[id]);

		// Push other results.
		Stack::getInstance().pushFloat(effect.baseMagickaCost);
		Stack::getInstance().pushLong(effect.school);

		return 0.0f;
	}
}