/************************************************************************
	
	xBitNot.cpp - Copyright (c) 2008 The MWSE Project
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
	class xBitNot : mwse::InstructionInterface_t
	{
	public:
		xBitNot();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xBitNotOpcode = 0x3939;
	static xBitNot xBitNotInstance;

	xBitNot::xBitNot() : mwse::InstructionInterface_t(xBitNotOpcode) {}

	void xBitNot::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xBitNot::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() != 1) {
			return 0;
		}

		mwse::Stack::getInstance().pushLong(~mwse::Stack::getInstance().popLong());

		return 0.0;
	}
}