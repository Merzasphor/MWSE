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

#include "TES3Effect.h"
#include "TES3CellMaster.h"
#include "TES3MagicEffect.h"

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
		mwLong id = Stack::getInstance().popLong();
		mwLong school = Stack::getInstance().popLong();
		mwFloat baseMagickaCost = Stack::getInstance().popFloat();
		mwLong flags = Stack::getInstance().popLong();

		// Validate id.
		if (id < TES3::EffectFirst || id > TES3::EffectLast) {
#if _DEBUG
			log::getLog() << "xSetBaseEffectInfo: Effect ID out of range." << std::endl;
#endif
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate school.
		if (school < TES3::FirstMagicSchool || school > TES3::LastMagicSchool) {
#if _DEBUG
			log::getLog() << "xSetBaseEffectInfo: School ID out of range." << std::endl;
#endif
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		TES3::MagicEffect& effect = tes3::getCellMaster()->recordLists->magicEffects[id];
		effect.school = (TES3::MagicSchools)school;
		effect.baseMagickaCost = baseMagickaCost;

		// Flags are a unique case. We added extra information in xGetBaseEffectInfo. We
		// need to strip that back out here, and make sure only the right bits are set.
		// TODO: Programmatically allow setting/getting these normally hard-coded values.
		effect.flags = (flags & (TES3::Spellmaking | TES3::Enchanting | TES3::NegativeLighting));

		Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}