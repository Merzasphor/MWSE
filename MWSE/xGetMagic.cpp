/************************************************************************
	
	xGetMagic.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3MobileNPC.h"
#include "TES3Enchantment.h"
#include "TES3Reference.h"
#include "TES3Spell.h"

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

	static xGetMagic xGetMagicInstance;

	xGetMagic::xGetMagic() : mwse::InstructionInterface_t(OpCode::xGetMagic) {}

	void xGetMagic::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMagic::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Return values.
		long type = 0;
		char* id = NULL;

		// Get reference to what we're finding enchantment information for.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference) {
			TES3::ObjectType::ObjectType recordType = reference->baseObject->objectType;
			if (recordType == TES3::ObjectType::Creature || recordType == TES3::ObjectType::NPC) {
				auto mobileObject = tes3::getAttachedMobileNPC(reference);
				if (mobileObject) {
					if (mobileObject->currentSpell) {
						type = mobileObject->currentSpell->objectType;
						if (type == TES3::ObjectType::Spell) {
							TES3::Spell* spell = reinterpret_cast<TES3::Spell*>(mobileObject->currentSpell);
							id = spell->objectID;
						}
						else if (type == TES3::ObjectType::Enchantment) {
							TES3::Enchantment* enchantment = reinterpret_cast<TES3::Enchantment*>(mobileObject->currentSpell);
							id = enchantment->objectID;
						}
						else {
#if _DEBUG
							log::getLog() << "xGetMagic: Unsupported current spell type: " << type << std::endl;
#endif
							type = 0;
						}
					}
				}
				else {
#if _DEBUG
					log::getLog() << "xGetMagic: Could not obtain MACP record for reference." << std::endl;
#endif
				}
			}
			else {
#if _DEBUG
				log::getLog() << "xGetMagic: Invalid reference type:" << recordType << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			log::getLog() << "xGetMagic: Could not obtain reference." << std::endl;
#endif
		}

		// Return type/id.
		Stack::getInstance().pushString(id);
		Stack::getInstance().pushLong(type);

		return 0.0f;
	}
}