/************************************************************************
	
	xGetSpellInfo.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3Spell.h"

using namespace mwse;

namespace mwse
{
	class xGetSpellInfo : mwse::InstructionInterface_t
	{
	public:
		xGetSpellInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetSpellInfo xGetSpellInfoInstance;

	xGetSpellInfo::xGetSpellInfo() : mwse::InstructionInterface_t(OpCode::xGetSpellInfo) {}

	void xGetSpellInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetSpellInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& spellId = virtualMachine.getString(Stack::getInstance().popLong());

		// Return values.
		char* name = NULL;
		long type = 0;
		long cost = 0;
		long effects = 0;
		long flags = 0;
		long origin = 0;

		// Get spell data by id.
		TES3::Spell* spell = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Spell>(spellId, TES3::ObjectType::Spell);;
		if (spell != NULL) {
			name = spell->name;
			type = long(spell->castType);
			cost = spell->magickaCost;
			effects = spell->getActiveEffectCount();
			flags = spell->spellFlags;
			origin = spell->objectFlags & 0x3;
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetSpellInfo: Could not find spell of id '" << spellId << "'" << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(origin);
		mwse::Stack::getInstance().pushLong(flags);
		mwse::Stack::getInstance().pushLong(effects);
		mwse::Stack::getInstance().pushLong(cost);
		mwse::Stack::getInstance().pushLong(type);
		mwse::Stack::getInstance().pushString(name);

		return 0.0f;
	}
}