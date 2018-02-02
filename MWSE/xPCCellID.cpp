/************************************************************************
	
	xPCCellID.cpp - Copyright (c) 2008 The MWSE Project
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
	class xPCCellID : mwse::InstructionInterface_t
	{
	public:
		xPCCellID();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xPCCellID xPCCellIDInstance;

	xPCCellID::xPCCellID() : mwse::InstructionInterface_t(OpCode::xPCCellID) {}

	void xPCCellID::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xPCCellID::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		REFRRecord_t* reference = virtualMachine.getReference();

		TES3CellMaster_t* masterCell = tes3::getCellMaster();
		if (masterCell == NULL) {
			mwse::log::getLog() << "xPCCellID: Cell master could not be found." << std::endl;
			Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Determine the PC cell -- either the interior cell if we have one, or the center cell.
		TES3Cell_t* cell = masterCell->interiorCell;
		if (!cell) {
			cell = masterCell->exteriorCells[CENTER]->first;
		}

		// If the cell has a name, use it. If not we want to use the literal
		// "Wilderness" so that PositionCell behaves properly.
		if (cell->cellname) {
			mwse::Stack::getInstance().pushString(cell->cellname);
		}
		else {
			mwse::Stack::getInstance().pushString("Wilderness");
		}

		return 0.0f;
	}
}