/************************************************************************

	xGetName.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetName : mwse::InstructionInterface_t
	{
	public:
		xGetName();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetName xGetNameInstance;

	xGetName::xGetName() : mwse::InstructionInterface_t(OpCode::xGetName) {}

	void xGetName::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetName::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetName: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		mwString_t name = NULL;

		// Get the base record.
		TES3DefaultTemplate_t* record = reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer);
		if (record) {
			RecordTypes::recordType_t type = reference->recordPointer->recordType;
			if (type == RecordTypes::NPC || type == RecordTypes::CREATURE) {
				name = reinterpret_cast<NPCBaseRecord_t*>(tes3::getBaseRecord(record))->name;
			}
			else if (type == RecordTypes::CONTAINER) {
				name = reinterpret_cast<CONTRecord_t*>(record)->name;
			}
			else if (type == RecordTypes::LIGHT) {
				name = reinterpret_cast<LIGHRecord_t*>(record)->name;
			}
			else if (type == RecordTypes::CLOTHING || type == RecordTypes::ARMOR || type == RecordTypes::WEAPON
				|| type == RecordTypes::MISC || type == RecordTypes::BOOK || type == RecordTypes::ALCHEMY
				|| type == RecordTypes::AMMO) {
				// These records happen to use the same offset. We'll be lazy/efficient here.
				name = reinterpret_cast<ARMORecord_t*>(record)->name;
			}
			else if (type == RecordTypes::ACTIVATOR) {
				name = reinterpret_cast<ACTIRecord_t*>(record)->name;
			}
			else if (type == RecordTypes::DOOR) {
				name = reinterpret_cast<char*>(reinterpret_cast<unsigned long*>(record) + 0x0d);
			}
			else if (type == RecordTypes::APPARATUS) {
				name = reinterpret_cast<char*>(reinterpret_cast<unsigned long*>(record) + 0x19);
			}
			else if (type == RecordTypes::INGREDIENT || type == RecordTypes::REPAIR || type == RecordTypes::PROBE || type == RecordTypes::LOCKPICK) {
				name = reinterpret_cast<char*>(reinterpret_cast<unsigned long*>(record) + 0x11);
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetName: Invalid call on record of type " << type << "." << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetName: Could not obtain record from reference." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushString(name);

		return 0.0f;
	}
}