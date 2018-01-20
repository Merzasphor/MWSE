/************************************************************************
	
	xStringMatch.cpp - Copyright (c) 2008 The MWSE Project
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
#include "Log.h"
#include "StringUtil.h"

#include <regex>

using namespace mwse;

namespace mwse
{
	class xStringMatch : mwse::InstructionInterface_t
	{
	public:
		xStringMatch();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xStringMatchOpcode = 0x3e68;
	static xStringMatch xStringMatchInstance;

	xStringMatch::xStringMatch() : mwse::InstructionInterface_t(xStringMatchOpcode) {}

	void xStringMatch::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xStringMatch::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwseString_t& string = virtualMachine.getString(Stack::getInstance().popLong());
		mwseString_t& pattern = virtualMachine.getString(Stack::getInstance().popLong());

		mwLong_t result = std::regex_search(string, std::regex(pattern));

		mwse::Stack::getInstance().pushLong(result);

		return 0.0;
	}
}