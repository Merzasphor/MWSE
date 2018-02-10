/************************************************************************
	
	xMyCellID.cpp - Copyright (c) 2008 The MWSE Project
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
	class xMyCellID : mwse::InstructionInterface_t
	{
	public:
		xMyCellID();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xMyCellID xMyCellIDInstance;

	xMyCellID::xMyCellID() : mwse::InstructionInterface_t(OpCode::xMyCellID) {}

	void xMyCellID::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xMyCellID::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xMyCellID: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// This data structure hasn't been fully mapped out.
		if (reference && reference->unknown_0x14 && reference->unknown_0x14->cell) {
			mwse::Stack::getInstance().pushString(reference->unknown_0x14->cell->name);
		}
		else {
			mwse::Stack::getInstance().pushLong(0);
		}

		return 0.0f;
	}
}