/************************************************************************

	xGetBaseID.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetBaseID : mwse::InstructionInterface_t
	{
	public:
		xGetBaseID();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetBaseID xGetBaseIDInstance;

	xGetBaseID::xGetBaseID() : mwse::InstructionInterface_t(OpCode::xGetBaseID) {}

	void xGetBaseID::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseID::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetBaseID: Called without reference." << std::endl;
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		char* objectId = NULL;

		// Try to get the data base record objectId first, and fall back to the copy object.
		TES3DefaultTemplate_t* data = reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer);
		TES3DefaultTemplate_t* base = mwse::tes3::getBaseRecord(data);
		if (base && base->objectId) {
			objectId = base->objectId;
		}
		else if (data && data->objectId) {
			objectId = data->objectId;
		}

		// Push the found objectId.
		if (objectId) {
			mwse::Stack::getInstance().pushString(objectId);
		}
		else {
			mwse::Stack::getInstance().pushString("unknown");
		}

		return 0.0f;
	}
}