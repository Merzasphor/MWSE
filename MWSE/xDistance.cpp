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
		// Get target reference
		Reference ref(mwse::Stack::getInstance().popLong());
		REFRRecord_t * targetref = reinterpret_cast<mwse::REFRRecord_t*>(ref.getAddress());
		if (targetref == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xModProgressSkill: Target reference is invalid." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		// Get script reference.
		REFRRecord_t * thisref = virtualMachine.getReference();
		if (thisref == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xModProgressSkill: Script reference is invalid." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}

		mwFloat_t dx = targetref->x - thisref->x;
		mwFloat_t dy = targetref->y - thisref->y;
		mwFloat_t dz = targetref->z - thisref->z;
		mwFloat_t xDistance = std::sqrt(dx*dx + dy*dy + dz*dz);

		mwse::Stack::getInstance().pushFloat(xDistance);

		return 0.0f;
	}
}