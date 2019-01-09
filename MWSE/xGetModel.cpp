/************************************************************************
	
	xGetModel.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3Reference.h"

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
		// Get our parameter. 
		long param = Stack::getInstance().popLong();

		char* model = NULL;

		// If we were given a value, it's supposed to be a string, and we'll get a record by this ID.
		if (param) {
			// Get the record by id string.
			mwseString& id = virtualMachine.getString(param);
			TES3::BaseObject* record = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::BaseObject>(id);
			if (record == NULL) {
#if _DEBUG
				log::getLog() << "xGetModel: No record found for id '" << id << "'." << std::endl;
#endif
				mwse::Stack::getInstance().pushLong(0);
				return 0.0f;
			}
			model = record->vTable.object->getModelPath(record);
		}

		// If we were not given a value, we try to use the function's given reference.
		else {
			TES3::Reference* reference = virtualMachine.getReference();
			if (reference == NULL) {
#if _DEBUG
				log::getLog() << "xGetModel: Invalid reference." << std::endl;
#endif
				mwse::Stack::getInstance().pushLong(0);
				return 0.0f;
			}
			model = reference->baseObject->vTable.object->getModelPath(reference->baseObject);
		}

		// Push the model back to the stack.
		Stack::getInstance().pushString(model);

		return 0.0f;
	}
}