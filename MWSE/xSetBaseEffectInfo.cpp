/************************************************************************
	
	xSetBaseEffectInfo.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3DataHandler.h"
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
		long id = Stack::getInstance().popLong();
		long school = Stack::getInstance().popLong();
		float baseMagickaCost = Stack::getInstance().popFloat();
		long flags = Stack::getInstance().popLong();

		// Validate id.
		if (id < TES3::EffectID::FirstEffect || id > TES3::EffectID::LastEffect) {
#if _DEBUG
			log::getLog() << "xSetBaseEffectInfo: Effect ID out of range." << std::endl;
#endif
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate school.
		if (school < TES3::MagicSchool::FirstMagicSchool || school > TES3::MagicSchool::LastMagicSchool) {
#if _DEBUG
			log::getLog() << "xSetBaseEffectInfo: School ID out of range." << std::endl;
#endif
			Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		TES3::MagicEffect& effect = TES3::DataHandler::get()->nonDynamicData->magicEffects[id];
		effect.school = school;
		effect.baseMagickaCost = baseMagickaCost;

		// Flags are a unique case. We added extra information in xGetBaseEffectInfo. We
		// need to strip that back out here, and make sure only the right bits are set.
		// TODO: Programmatically allow setting/getting these normally hard-coded values.
		effect.flags = (flags & (TES3::EffectFlag::AllowSpellmaking | TES3::EffectFlag::AllowEnchanting | TES3::EffectFlag::NegativeLighting));

		Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}