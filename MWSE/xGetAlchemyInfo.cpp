/************************************************************************
	
	xGetAlchemyInfo.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3Alchemy.h"
#include "TES3DataHandler.h"

using namespace mwse;

namespace mwse
{
	class xGetAlchemyInfo : mwse::InstructionInterface_t
	{
	public:
		xGetAlchemyInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetAlchemyInfo xGetAlchemyInfoInstance;

	xGetAlchemyInfo::xGetAlchemyInfo() : mwse::InstructionInterface_t(OpCode::xGetAlchemyInfo) {}

	void xGetAlchemyInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetAlchemyInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& id = virtualMachine.getString(Stack::getInstance().popLong());

		// Get the record by its id.
		TES3::Alchemy* record = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Alchemy>(id);
		if (record == nullptr) {
#if _DEBUG
			mwse::log::getLog() << "xGetAlchemyInfo: No record found by id '" << id << "'." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}
		else if (record->objectType != TES3::ObjectType::Alchemy) {
#if _DEBUG
			mwse::log::getLog() << "xGetAlchemyInfo: Found record by id '" << id << "' of invalid type " << record->objectType << "." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		long flags = record->flags;
		long effectCount = record->getActiveEffectCount();

		mwse::Stack::getInstance().pushLong(flags);
		mwse::Stack::getInstance().pushLong(effectCount);

		return 0.0f;
	}
}