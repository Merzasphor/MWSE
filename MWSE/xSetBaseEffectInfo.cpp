/************************************************************************
	
	xSetBaseEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetBaseEffectInfo : mwse::InstructionInterface_t
	{
	public:
		xSetBaseEffectInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetBaseEffectInfo xSetBaseEffectInfoInstance;

	xSetBaseEffectInfo::xSetBaseEffectInfo() : mwse::InstructionInterface_t(OpCode::xSetBaseEffectInfo) {}

	void xSetBaseEffectInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetBaseEffectInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwLong_t id = Stack::getInstance().popLong();
		mwLong_t school = Stack::getInstance().popLong();
		mwFloat_t baseMagickaCost = Stack::getInstance().popFloat();
		mwLong_t flags = Stack::getInstance().popLong();

		// Validate id.
		if (id < Effects::FirstMagicEffect || id > Effects::LastMagicEffect) {
			log::getLog() << "xSetBaseEffectInfo: Effect ID out of range." << std::endl;
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate school.
		if (school < FirstMagicSchool || school > LastMagicSchool) {
			log::getLog() << "xSetBaseEffectInfo: School ID out of range." << std::endl;
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		MGEFRecord_t& effect = tes3::getCellMaster()->recordLists->magic_effects[id];
		effect.school = (MagicSchools)school;
		effect.base_magicka_cost = baseMagickaCost;
		effect.flags = flags;

		Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}