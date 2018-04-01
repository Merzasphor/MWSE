/************************************************************************

	xModService.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3NPC.h"
#include "TES3Reference.h"
#include "TES3Class.h"

using namespace mwse;

namespace mwse
{
	class xModService : mwse::InstructionInterface_t
	{
	public:
		xModService();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xModService xModServiceInstance;

	xModService::xModService() : mwse::InstructionInterface_t(OpCode::xModService) {}

	void xModService::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xModService::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
#if _DEBUG
			mwse::log::getLog() << "xModService: Function called with too few arguments." << std::endl;
#endif
			return 0.0f;
		}

		unsigned long data = Stack::getInstance().popLong();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xModService: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get AI configuration.
		TES3::AIConfig* aiConfig = reference->baseObject->vTable.object->getAIConfig(reference->baseObject);
		if (!aiConfig) {
#if _DEBUG
			mwse::log::getLog() << "xModService: Called on non-NPC reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the NPC's class.
		TES3::Class* classRecord = reference->baseObject->vTable.object->getClass(reference->baseObject);
		if (!classRecord) {
#if _DEBUG
			mwse::log::getLog() << "xModService: Failed to obtain NPC's class." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		long services = aiConfig->merchantFlags | classRecord->services;

		// Want to remove services.
		if (data < 0) {
			services = services & (~(0 - data));
		}
		// Want to add services.
		else {
			services = services | (data & 0x0003FFFF);
		}

		aiConfig->merchantFlags = services;

		return 0.0f;
	}
}