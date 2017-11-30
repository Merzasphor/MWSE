/************************************************************************
	
	xGetBaseSecurity.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetBaseSecurity : mwse::InstructionInterface_t
	{
	public:
		xGetBaseSecurity();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const mwFloat_t INVALID_VALUE = -1.0f;
	};

	static const mwse::mwOpcode_t xGetBaseSecurityOpcode = 0x3916;
	static xGetBaseSecurity xGetBaseSecurityInstance;

	xGetBaseSecurity::xGetBaseSecurity() : mwse::InstructionInterface_t(xGetBaseSecurityOpcode) {}

	void xGetBaseSecurity::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseSecurity::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get the associated MACP record.
		mwse::REFRRecord_t* reference = virtualMachine.getReference();
		MACPRecord_t* macp = tes3::getAttachedMACPRecord(reference);
		if (macp == NULL) {
			mwse::log::getLog() << "xGetBaseSecurity: Could not find MACP record for reference." << std::endl;
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Push the base value of that skill.
		mwse::Stack::getInstance().pushFloat(macp->skills[Security].base);

		return 0.0f;
	}
}