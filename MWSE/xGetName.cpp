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
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetName: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		mwString name = NULL;

		// Get the base record.
		TES3::BaseObject* record = reinterpret_cast<TES3::BaseObject*>(reference->objectPointer);
		if (record) {
			TES3::ObjectType::ObjectType type = reference->objectPointer->objectType;
			if (type == TES3::ObjectType::NPC || type == TES3::ObjectType::Creature) {
				name = reinterpret_cast<NPCTES3::BaseObject*>(tes3::getBaseRecord(record))->name;
			}
			else if (type == TES3::ObjectType::CONTAINER) {
				name = reinterpret_cast<CONTRecord_t*>(record)->name;
			}
			else if (type == TES3::ObjectType::LIGHT) {
				name = reinterpret_cast<LIGHRecord_t*>(record)->name;
			}
			else if (type == TES3::ObjectType::CLOTHING || type == TES3::ObjectType::ARMOR || type == TES3::ObjectType::WEAPON
				|| type == TES3::ObjectType::MISC || type == TES3::ObjectType::BOOK || type == TES3::ObjectType::Alchemy
				|| type == TES3::ObjectType::AMMO) {
				// These records happen to use the same offset. We'll be lazy/efficient here.
				name = reinterpret_cast<TES3::Armor*>(record)->name;
			}
			else if (type == TES3::ObjectType::ACTIVATOR) {
				name = reinterpret_cast<ACTIRecord_t*>(record)->name;
			}
			else if (type == TES3::ObjectType::DOOR) {
				name = reinterpret_cast<char*>(reinterpret_cast<unsigned long*>(record) + 0x0d);
			}
			else if (type == TES3::ObjectType::APPARATUS) {
				name = reinterpret_cast<char*>(reinterpret_cast<unsigned long*>(record) + 0x19);
			}
			else if (type == TES3::ObjectType::INGREDIENT || type == TES3::ObjectType::REPAIR || type == TES3::ObjectType::PROBE || type == TES3::ObjectType::LOCKPICK) {
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