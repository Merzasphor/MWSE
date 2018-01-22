/************************************************************************
	
	xGetModel.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetModel : mwse::InstructionInterface_t
	{
	public:
		xGetModel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetModel xGetModelInstance;

	xGetModel::xGetModel() : mwse::InstructionInterface_t(OpCode::xGetModel) {}

	void xGetModel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetModel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			log::getLog() << "xGetModel: Invalid reference." << std::endl;
			Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the model, and push it back to the stack.
		char* model = tes3::getModel(reference->recordPointer);
		Stack::getInstance().pushString(model);

		return 0.0f;
	}
}