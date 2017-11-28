/************************************************************************
	
	xFileReadText.cpp - Copyright (c) 2008 The MWSE Project
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
#include "FileUtil.h"
#include "StringUtil.h"

#include <vector>

using namespace mwse;

namespace mwse
{
	class xFileReadText : mwse::InstructionInterface_t
	{
	public:
		xFileReadText();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xFileReadTextOpcode = 0x3F08;
	static xFileReadText xFileReadTextInstance;

	xFileReadText::xFileReadText() : mwse::InstructionInterface_t(xFileReadTextOpcode) {}

	void xFileReadText::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xFileReadText::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 2) {
			mwse::log::getLog() << "xFileReadText: Function called with too few arguments." << std::endl;
			return 0.0f;
		}

		mwseString_t fileName = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		mwseString_t format = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Count how many results there should be based on the format string
		bool stopAtEndOfLine = false;
		int maxResults = 0;
		mwse::string::enumerate(format.c_str(), maxResults, stopAtEndOfLine);
		maxResults++;

		// Store results so we can push them on in reverse.
		mwLong_t* results = new mwLong_t[maxResults];

		// Read the string from the file.
		mwseString_t readString;
		std::tie(readString, results[0]) = mwse::FileSystem::getInstance().readString(fileName.c_str(), stopAtEndOfLine);

		if (results[0]) {
			mwse::string::secernate(format.c_str(), readString.c_str(), results, maxResults);
		}

		while (maxResults--) {
			mwse::Stack::getInstance().pushLong(results[maxResults]);
		}

		return 0.0f;
	}
}