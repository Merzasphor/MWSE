/************************************************************************
	
	xGetOwnerInfo.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetOwnerInfo : mwse::InstructionInterface_t
	{
	public:
		xGetOwnerInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetOwnerInfo xGetOwnerInfoInstance;

	xGetOwnerInfo::xGetOwnerInfo() : mwse::InstructionInterface_t(OpCode::xGetOwnerInfo) {}

	void xGetOwnerInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetOwnerInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwString_t id = NULL;
		mwLong_t rank = 0;
		mwLong_t type = 0;

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference) {
			// Get the attached varnode as owner information.
			mwOwnerInfoNode_t* ownerInfo = reinterpret_cast<mwOwnerInfoNode_t*>(tes3::getAttachedVarHolderNode(reference));
			if (ownerInfo) {
				TES3DefaultTemplate_t* owner = ownerInfo->owner;
				if (owner) {
					type = owner->recordType;
					if (type == RecordTypes::NPC) {
						id = reinterpret_cast<NPCBaseRecord_t*>(owner)->objectId;
						if (ownerInfo->rankVar.variable) {
							rank = mwse::string::store::getOrCreate(reinterpret_cast<GLOBRecord_t*>(ownerInfo->rankVar.variable)->globalName);
						}
					}
					else if (type == RecordTypes::FACTION) {
						FACTRecord_t * faction = reinterpret_cast<FACTRecord_t*>(owner);
						id = faction->id;
						rank = ownerInfo->rankVar.rank;
					}
					else {
#if _DEBUG
						mwse::log::getLog() << "xGetOwnerInfo: Owner was of unhandled type " << type << "." << std::endl;
#endif
					}
				}
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetOwnerInfo: Could not obtain attached VARNODE." << std::endl;
#endif
			}
		} else {
#if _DEBUG
			mwse::log::getLog() << "xGetOwnerInfo: No reference provided." << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(rank);
		mwse::Stack::getInstance().pushString(id);
		mwse::Stack::getInstance().pushLong(type);

		return 0.0f;
	}
}