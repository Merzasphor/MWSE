/************************************************************************
	
	xFirstItem.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3DataHandler.h"
#include "TES3Cell.h"

using namespace mwse;

namespace mwse
{
	class xFirstItem : mwse::InstructionInterface_t
	{
	public:
		xFirstItem();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xFirstItem xFirstItemInstance;

	xFirstItem::xFirstItem() : mwse::InstructionInterface_t(OpCode::xFirstItem) {}

	void xFirstItem::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xFirstItem::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Clear elements in our stored exterior ref list.
		mwse::tes3::clearExteriorRefs();

		TES3::Reference* reference = NULL;
		TES3::DataHandler* dataHandler = mwse::tes3::getDataHandler();
		if (dataHandler->currentInteriorCell != NULL) {
			reference = mwse::tes3::skipRemovedReferences(dataHandler->currentInteriorCell->statics.head);
		}
		else {
			auto cellPointer = dataHandler->exteriorCellData[TES3::CellGrid::Center];
			if (cellPointer->size >= 1) {
				// Get the start of the list for the center cell. We'll check that it's valid later.
				reference = mwse::tes3::skipRemovedReferences(cellPointer->cell->statics.head);
				int exteriorCount = 0;
				for (int i = 0; i < 9; i++) {
					if (i == TES3::CellGrid::Center) {
						continue;
					}

					cellPointer = dataHandler->exteriorCellData[i];
					if (cellPointer->size >= 1) {
						TES3::Reference* tempReference = mwse::tes3::skipRemovedReferences(cellPointer->cell->statics.head);
						if (tempReference != NULL) {
							mwse::tes3::exteriorRefs[exteriorCount] = tempReference;
							exteriorCount++;
						}
					}
					else {
						mwse::log::getLog() << "xFirstItem: Exterior size is " << cellPointer->size << ". Skipping exterior " << i << "." << std::endl;
					}
				}

				// Make sure that we end our list with a NULL, so we know we're done.
				mwse::tes3::exteriorRefs[exteriorCount] = NULL;

				// Make sure the reference in the center cell is valid.
				// If not, use the reference from another exterior cell.
				if (reference == NULL && exteriorCount > 0) {
					exteriorCount--;
					reference = mwse::tes3::exteriorRefs[exteriorCount];
					mwse::tes3::exteriorRefs[exteriorCount] = NULL;
				}
			}
		}

		mwse::Stack::getInstance().pushLong((long)reference);

		return 0.0f;
	}
}