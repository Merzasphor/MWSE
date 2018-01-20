/************************************************************************
	
	xRandomFloat.cpp - Copyright (c) 2008 The MWSE Project
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
#include "RngUtil.h"

using namespace mwse;

namespace mwse
{
	class xRandomFloat : mwse::InstructionInterface_t
	{
	public:
		xRandomFloat();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xRandomFloat xRandomFloatInstance;

	xRandomFloat::xRandomFloat() : mwse::InstructionInterface_t(OpCode::xRandomFloat) {}

	void xRandomFloat::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xRandomFloat::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() != 2) {
			return 0.0f;
		}

		mwFloat_t min = mwse::Stack::getInstance().popFloat();
		mwFloat_t max = mwse::Stack::getInstance().popFloat();

		mwse::Stack::getInstance().pushFloat(mwse::rng::getRandomFloat(min, max));

		return 0.0f;
	}
}