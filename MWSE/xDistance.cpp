/************************************************************************

	xDistance.cpp - Copyright (c) 2008 The MWSE Project
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
#include <cmath>

using namespace mwse;

namespace mwse
{
	class xDistance : mwse::InstructionInterface_t
	{
	public:
		xDistance();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xDistance xDistanceInstance;

	xDistance::xDistance() : mwse::InstructionInterface_t(OpCode::xDistance) {}

	void xDistance::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xDistance::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwse::Reference ref(mwse::Stack::getInstance().popLong());	//get the reference
		mwse::REFRRecord_t * targetref = reinterpret_cast<mwse::REFRRecord_t*>(ref.getAddress());		//cast it to a pointer

		mwse::REFRRecord_t * thisref = virtualMachine.getReference();

		mwse::mwFloat_t dx = targetref->x - thisref->x;
		mwse::mwFloat_t dy = targetref->y - thisref->y;
		mwse::mwFloat_t dz = targetref->z - thisref->z;
		mwse::mwFloat_t xDistance = std::sqrt(dx*dx + dy*dy + dz*dz);

		mwse::Stack::getInstance().pushFloat(xDistance);

		return 0.0f;
	}
}