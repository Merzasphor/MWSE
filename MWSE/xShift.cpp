/************************************************************************
	
	xShift.cpp - Copyright (c) 2008 The MWSE Project
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

using namespace mwse;

namespace mwse
{
	class xShift : mwse::InstructionInterface_t
	{
	public:
		xShift();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xShift xShiftInstance;

	xShift::xShift() : mwse::InstructionInterface_t(OpCode::xShift) {}

	void xShift::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xShift::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwLong value = mwse::Stack::getInstance().popLong();
		mwLong magnitude = mwse::Stack::getInstance().popLong();

		if (magnitude < 0) {
			mwse::Stack::getInstance().pushLong(value >> abs(magnitude));
		} else {
			mwse::Stack::getInstance().pushLong(value << magnitude);
		}

		return 0.0f;
	}
}