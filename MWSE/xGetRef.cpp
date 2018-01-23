/************************************************************************

	xGetRef.cpp - Copyright (c) 2008 The MWSE Project
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
#include "Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetRef : InstructionInterface_t
	{
	public:
		xGetRef();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetRef xGetRefInstance;

	xGetRef::xGetRef() : InstructionInterface_t(OpCode::xGetRef) {}

	void xGetRef::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetRef::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwseString_t& referenceId = virtualMachine.getString(Stack::getInstance().popLong());

		REFRRecord_t * ref = virtualMachine.getReference(referenceId.c_str());

		Reference fixed(ref);

		Stack::getInstance().pushLong(fixed);

		return 0.0f;
	}
}