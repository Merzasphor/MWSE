/************************************************************************

	xLogMessage.cpp - Copyright (c) 2008 The MWSE Project
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

#include "Log.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>

using namespace mwse;

namespace mwse
{
	// Provides an interface to mwse::log, allowing scripts to write to the default MWSELog.txt file.
	// 
	// MWScript Usage:
	//	<none> xLogMessage sFormat ...
	//
	// MWEdit definition:
	//	Name = XLogMessage
	//	Options = MWSE | AllowGlobal | ShortVar | AllowVar
	//	Return = None
	//	Param1 = Long | String
	//	Param2 = Short | Long | Float | String | Many | Optional
	//	Opcode = 0x3c09
	class xLogMessage : mwse::InstructionInterface_t
	{
	public:
		xLogMessage();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static const mwse::mwOpcode_t xLogMessageOpcode = 0x3c09;
	static xLogMessage xLogMessageInstance;

	xLogMessage::xLogMessage() : mwse::InstructionInterface_t(xLogMessageOpcode) {}

	void xLogMessage::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xLogMessage::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		Stack::getInstance().dump();

		mwseString_t format = virtualMachine.getString(Stack::getInstance().popLong());
		
		bool suppress_null = false;

		size_t start = 0;
		std::string result;
		std::string current_code;
		std::string number;
		std::string bad_codes;
		std::ostringstream convert;
		while (start < format.length()) {
			size_t end = format.find('%', start);
			if (end == std::string::npos) {
				result += format.substr(start);
				break;
			}
			result += format.substr(start, end - start);
			end++;
			if (end == format.length()) { // single trailing %
				suppress_null = true;
				break;
			}
			current_code = "%";
			int skip = 0;
			bool skip_set = false;
			int precision = 0;
			bool precision_set = false;
			bool done = false;
			bool parse_success = false;
			while (!done) {
				char current_char = tolower(format.at(end));
				if (current_char == '%' && current_code == "%") {
					result += current_char;
					end++;
					parse_success = true;
				} else if (std::isdigit(current_char)) {
					number = current_char;
					end++;
					while (end < format.length()) {
						current_char = format.at(end);
						if (std::isdigit(current_char)) {
							number += current_char;
							end++;
						} else {
							break;
						}
					}
					if (current_code.at(current_code.length() - 1) == '.') {
						precision = atoi(number.c_str());
						precision_set = true;
					} else {
						skip = atoi(number.c_str());
						skip_set = true;
					}
					current_code += number;
				} else if (current_char == '.') {
					current_code += current_char;
					end++;
				} else if (current_char == 'n' && current_code == "%") {
					result += "\r\n";
					end++;
					parse_success = true;
				} else if (current_char == 'q' && current_code == "%") {
					result += '"';
					end++;
					parse_success = true;
				} else if (current_char == 'l' && current_code == "%") {
					mwLong_t value = Stack::getInstance().popLong();
					convert.str("");
					convert << std::dec << value;
					result += convert.str();
					end++;
					parse_success = true;
				} else if (current_char == 'd' && current_code == "%") {
					mwLong_t value = Stack::getInstance().popLong();
					convert.str("");
					convert << std::dec << value;
					result += convert.str();
					end++;
					parse_success = true;
				} else if (current_char == 'h' && current_code == "%") {
					mwLong_t value = Stack::getInstance().popLong();
					convert.str("");
					convert << std::hex << value;
					result += convert.str();
					end++;
					parse_success = true;
				} else if (current_char == 'f') {
					if (!skip_set) {
						float value = Stack::getInstance().popFloat();
						// 6 = vsprintf default precision - mimic old version
						if (!precision_set) precision = 6;
						convert.str("");
						convert << std::fixed << std::setprecision(precision) << value;
						result += convert.str();
						parse_success = true;
					} else {
						current_code += current_char;
					}
					done = true;
					end++;
				} else if (current_char == 's') {
					result += virtualMachine.getString(Stack::getInstance().popLong()).c_str();
					end++;
					parse_success = true;
				} else {
					done = true;
					if (!std::isspace(current_char)) {
						current_code += current_char;
						end++;
					}
				}
				if (parse_success || end >= format.length()) done = true;
				if (done && !parse_success) {
					if (bad_codes != "") bad_codes += " ";
					bad_codes += current_code;
				}
			}
			start = end;
		}

		mwse::log::getLog() << result << std::endl;
		if (!bad_codes.empty()) {
			mwse::log::getLog() << "xMessageFix: bad format \"" << bad_codes << "\" in \"" << format << "\" generating \"" << result << "\"" << bad_codes << std::endl;
		}

		return 0.0;
	}
}