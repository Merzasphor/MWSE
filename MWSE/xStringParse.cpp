/************************************************************************
	
	xStringParse.cpp - Copyright (c) 2008 The MWSE Project
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
#include "MWSEDefs.h"

namespace mwse
{
	class xStringParse : mwse::InstructionInterface_t
	{
	public:
		xStringParse();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xStringParse xStringParseInstance;

	xStringParse::xStringParse() : mwse::InstructionInterface_t(OpCode::xStringParse) {}

	void xStringParse::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xStringParse::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		mwseString_t& format = virtualMachine.getString(Stack::getInstance().popLong());

		// We have to hijack this function for version checking, to make it backwards-compatible.
		if (format == "MWSE_VERSION") {
			mwLong_t checkVersionAgainst = mwse::Stack::getInstance().popLong();
			mwse::Stack::getInstance().pushLong(MWSE_VERSION_INTEGER >= checkVersionAgainst);
			mwse::Stack::getInstance().pushLong(MWSE_VERSION_INTEGER);
			return 0.0f;
		}

		// If we're not doing an actual version check, we'll want the string.
		mwseString_t& string = virtualMachine.getString(Stack::getInstance().popLong());

		int resultCount = 0;
		bool eolMode = false;
		mwse::string::enumerate(format.c_str(), resultCount, eolMode);
		resultCount++;

		mwLong_t* results = new mwLong_t[resultCount];
		mwse::string::secernate(format.c_str(), string.c_str(), results, resultCount);

		while (resultCount--) {
			mwse::Stack::getInstance().pushLong(results[resultCount]);
		}

		delete[] results;

		return 0.0f;
	}
}