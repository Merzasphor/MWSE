/************************************************************************
	
	xFileWriteText.cpp - Copyright (c) 2008 The MWSE Project
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

using namespace mwse;

namespace mwse
{
	class xFileWriteText : mwse::InstructionInterface_t
	{
	public:
		xFileWriteText();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xFileWriteTextOpcode = 0x3F09;
	static xFileWriteText xFileWriteTextInstance;

	xFileWriteText::xFileWriteText() : mwse::InstructionInterface_t(xFileWriteTextOpcode) {}

	void xFileWriteText::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xFileWriteText::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 2) {
			mwse::log::getLog() << "xFileWriteText: Function called with too few arguments." << std::endl;
			return 0.0f;
		}

		mwseString_t& fileName = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		mwseString_t& format = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		bool suppressNull = false;
		std::string badCodes;
		std::string value = mwse::string::interpolate(format, virtualMachine, &suppressNull, &badCodes);
		if (!badCodes.empty()) {
			mwse::log::getLog() << "xFileWriteText: bad format \"" << badCodes << "\" in \"" << format << "\" generating \"" << value << "\"" << badCodes << std::endl;
		}

		mwse::FileSystem::getInstance().writeString(fileName.c_str(), value);

		return 0.0f;
	}
}