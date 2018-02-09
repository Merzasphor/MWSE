/************************************************************************
	
	xXor.cpp - Copyright (c) 2008 The MWSE Project
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
	class xXor : mwse::InstructionInterface_t
	{
	public:
		xXor();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xXor xXorInstance;

	xXor::xXor() : mwse::InstructionInterface_t(OpCode::xXor) {}

	void xXor::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xXor::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwLong param1 = mwse::Stack::getInstance().popLong();
		mwLong param2 = mwse::Stack::getInstance().popLong();

		mwse::Stack::getInstance().pushLong((param1 || param2) && !(param1 && param2));

		return 0.0f;
	}
}