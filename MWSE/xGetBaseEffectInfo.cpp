/************************************************************************
	
	xGetBaseEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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
		mwLong_t id = Stack::getInstance().popLong();

		// Return values.
		mwLong_t school = 0;
		mwFloat_t baseMagickaCost = 0.0f;
		mwLong_t flags = 0;

		// Validate id.
		if (id < Effects::FirstMagicEffect || id > Effects::LastMagicEffect) {
			log::getLog() << "xGetBaseEffectInfo: Effect ID out of range." << std::endl;
			Stack::getInstance().pushLong(0);
			Stack::getInstance().pushFloat(0.0f);
			Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the effect.
		MGEFRecord_t& effect = tes3::getCellMaster()->recordLists->magic_effects[id];

		// Push results.
		Stack::getInstance().pushLong(effect.flags | Effects::MagicEffectFlagMap[id]);
		Stack::getInstance().pushLong(effect.base_magicka_cost);
		Stack::getInstance().pushLong(effect.school);

		return 0.0f;
	}
}