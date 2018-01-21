/************************************************************************
	
	xSetSpellInfo.cpp - Copyright (c) 2008 The MWSE Project
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
	class xSetSpellInfo : mwse::InstructionInterface_t
	{
	public:
		xSetSpellInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetSpellInfo xSetSpellInfoInstance;

	xSetSpellInfo::xSetSpellInfo() : mwse::InstructionInterface_t(OpCode::xSetSpellInfo) {}

	void xSetSpellInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetSpellInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString_t& spellId = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		mwLong_t nameId = mwse::Stack::getInstance().popLong();
		mwLong_t type = mwse::Stack::getInstance().popLong();
		mwLong_t cost = mwse::Stack::getInstance().popLong();
		mwLong_t flags = mwse::Stack::getInstance().popLong();
		mwLong_t origin = mwse::Stack::getInstance().popLong();

		// Validate spell type.
		if (type < FirstSpellType || type > LastSpellType) {
			mwse::log::getLog() << "xSetSpellInfo: Spell type out of range: " << type << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate spell flags.
		if (flags < NoSpellFlags || flags > AllSpellFlags) {
			mwse::log::getLog() << "xSetSpellInfo: Spell flags out of range: " << flags << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate spell origin.
		if (origin != 0 && (origin < SpellOriginsFirst || origin > SpellOriginsLast)) {
			mwse::log::getLog() << "xSetSpellInfo: Spell origin out of range: " << origin << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get spell data by id.
		SPELRecord_t* spell = tes3::getSpellRecordById(spellId);
		if (spell == NULL) {
			mwse::log::getLog() << "xSetSpellInfo: Could not find spell of id '" << spellId << "'" << std::endl;
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set spell name if one is provided.
		if (nameId) {
			mwseString_t& name = virtualMachine.getString(nameId);
			if (name.length() > 31) {
				mwse::log::getLog() << "xSetSpellInfo: Given name must be 31 characters or less." << std::endl;
				mwse::Stack::getInstance().pushLong(false);
				return 0.0f;
			}
			
			// Expand name length if needed.
			if (name.length() > strlen(spell->friendlyName)) {
				spell->friendlyName = reinterpret_cast<char*>(tes3::realloc(spell->friendlyName, 32));
			}

			// Copy name over.
			strcpy(spell->friendlyName, name.c_str());
		}

		// Set cost.
		if (flags & AutoCalculateCost && !(spell->flags & AutoCalculateCost)) {
			//! TODO: Recalculate spell cost.
		}
		else if (!(flags & AutoCalculateCost)) {
			spell->cost = cost;
		}

		// Set other information.
		spell->type = type;
		spell->flags = flags;
		if (origin != 0) {
			spell->origin = origin;
		}

		// Report success.
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}