/************************************************************************
               Pop.cpp - Copyright (c) 2008 The MWSE Project
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
	//----------------------------------------
	class Pop : public InstructionInterface_t
	{
	public:
		Pop();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwShort_t popLength;
	};

	static Pop popInstance;

	Pop::Pop(): InstructionInterface_t(OpCode::_Pop){}

	void Pop::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		popLength = virtualMachine.getShortValue();
	}

	float Pop::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwShort_t items = popLength /4;	//number of items to throw off the stack
		Stack::getInstance().popFrames(items);
		return 0.0;
	}
	//----------------------------------------
}