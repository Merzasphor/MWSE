/************************************************************************

	xRefType.cpp - Copyright (c) 2008 The MWSE Project
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

using namespace mwse;

namespace mwse
{
	class xRefType : InstructionInterface_t
	{
	public:
		xRefType();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xRefType xRefTypeInstance;

	xRefType::xRefType() : InstructionInterface_t(OpCode::xRefType) {}

	void xRefType::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xRefType::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		TES3::Reference * refr = virtualMachine.getReference();
		if (refr == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xRefType: Called on invalid reference." << std::endl;
#endif
			Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		TES3::BaseObject * temp = reinterpret_cast<TES3::BaseObject*>(refr->objectPointer);

		mwLong type = static_cast<mwLong>(temp->objectType);

		Stack::getInstance().pushLong(type);

		return 0.0f;
	}
}