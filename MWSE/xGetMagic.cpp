/************************************************************************
	
	xGetMagic.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetMagic : mwse::InstructionInterface_t
	{
	public:
		xGetMagic();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xGetMagicOpcode = 0x3940;
	static xGetMagic xGetMagicInstance;

	xGetMagic::xGetMagic() : mwse::InstructionInterface_t(xGetMagicOpcode) {}

	void xGetMagic::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMagic::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Return values.
		mwLong_t type = 0;
		mwString_t id = NULL;

		// Get reference to what we're finding enchantment information for.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference) {
			RecordTypes::recordType_t recordType = reference->recordPointer->recordType;
			if (recordType == RecordTypes::CREATURE || recordType == RecordTypes::NPC) {
				MACPRecord_t* macp = tes3::getAttachedMACPRecord(reference);
				if (macp) {
					if (macp->currentSpell) {
						type = macp->currentSpell->recordType;
						if (type == RecordTypes::SPELL) {
							SPELRecord_t* spell = reinterpret_cast<SPELRecord_t*>(macp->currentSpell);
							id = spell->id;
						}
						else if (type == RecordTypes::ENCHANTMENT) {
							ENCHRecord_t* enchantment = reinterpret_cast<ENCHRecord_t*>(macp->currentSpell);
							id = enchantment->id;
						}
						else {
							log::getLog() << "xGetMagic: Unsupported current spell type: " << type << std::endl;
							type = 0;
						}
					}
				}
				else {
					log::getLog() << "xGetMagic: Could not obtain MACP record for reference." << std::endl;
				}
			}
			else {
				log::getLog() << "xGetMagic: Invalid reference type:" << recordType << std::endl;
			}
		}
		else {
			log::getLog() << "xGetMagic: Could not obtain reference." << std::endl;
		}

		// Return type/id.
		Stack::getInstance().pushString(id);
		Stack::getInstance().pushLong(type);

		return 0.0f;
	}
}