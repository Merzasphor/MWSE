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
#include "TES3Reference.h"

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

		TES3::Reference* reference = nullptr;
		TES3::DataHandler* dataHandler = TES3::DataHandler::get();
		if (dataHandler->currentInteriorCell != nullptr) {
			reference = static_cast<TES3::Reference*>(dataHandler->currentInteriorCell->statics.head->skipDeletedObjects());
		}
		else {
			auto cellPointer = dataHandler->exteriorCellData[TES3::CellGrid::Center];
			if (cellPointer->size >= 1) {
				// Get the start of the list for the center cell. We'll check that it's valid later.
				reference = static_cast<TES3::Reference*>(cellPointer->cell->statics.head->skipDeletedObjects());
				int exteriorCount = 0;
				for (int i = 0; i < 9; i++) {
					if (i == TES3::CellGrid::Center) {
						continue;
					}

					cellPointer = dataHandler->exteriorCellData[i];
					if (cellPointer->size >= 1) {
						TES3::Reference* tempReference = static_cast<TES3::Reference*>(cellPointer->cell->statics.head->skipDeletedObjects());
						if (tempReference != nullptr) {
							mwse::tes3::exteriorRefs[exteriorCount] = tempReference;
							exteriorCount++;
						}
					}
					else {
						mwse::log::getLog() << "xFirstItem: Exterior size is " << cellPointer->size << ". Skipping exterior " << i << "." << std::endl;
					}
				}

				// Make sure that we end our list with a NULL, so we know we're done.
				mwse::tes3::exteriorRefs[exteriorCount] = nullptr;

				// Make sure the reference in the center cell is valid.
				// If not, use the reference from another exterior cell.
				if (reference == nullptr && exteriorCount > 0) {
					exteriorCount--;
					reference = mwse::tes3::exteriorRefs[exteriorCount];
					mwse::tes3::exteriorRefs[exteriorCount] = nullptr;
				}
			}
		}

		mwse::Stack::getInstance().pushLong((long)reference);

		return 0.0f;
	}
}