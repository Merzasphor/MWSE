/************************************************************************
	
	xPositionCell.cpp - Copyright (c) 2008 The MWSE Project
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
#include "mwAdapter.h"
#include "VirtualMachine.h"
#include "ScriptUtil.h"

using namespace mwse;

namespace mwse
{
	class xPositionCell : mwse::InstructionInterface_t
	{
	public:
		xPositionCell();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xPositionCell xPositionCellInstance;

	xPositionCell::xPositionCell() : mwse::InstructionInterface_t(OpCode::xPositionCell) {}

	void xPositionCell::loadParameters(mwse::VMExecuteInterface &virtualMachine) {
	}

	float xPositionCell::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		float x = mwse::Stack::getInstance().popFloat();
		float y = mwse::Stack::getInstance().popFloat();
		float z = mwse::Stack::getInstance().popFloat();
		float rotation = mwse::Stack::getInstance().popFloat();
		mwseString& cell = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get other context information for original opcode.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xPositionCell: Called on invalid reference." << std::endl;
#endif
			return 0.0f;
		}

		// Call the original function.
		TES3::Script* script = virtualMachine.getScript();
		mwse::mwscript::PositionCell(script, reference, x, y, z, rotation, cell.c_str());

		return 0.0f;
	}
}