#include "StringUtil.h"

#include "Stack.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>

namespace mwse {
	namespace string {
		mwseString_t interpolate(const mwseString_t& format, mwse::VMExecuteInterface &virtualMachine, bool* suppressNull, std::string* badCodes) {
			mwseString_t result;

			*suppressNull = false;

			size_t start = 0;
			std::string current_code;
			std::string number;
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
					*suppressNull = true;
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
					}
					else if (std::isdigit(current_char)) {
						number = current_char;
						end++;
						while (end < format.length()) {
							current_char = format.at(end);
							if (std::isdigit(current_char)) {
								number += current_char;
								end++;
							}
							else {
								break;
							}
						}
						if (current_code.at(current_code.length() - 1) == '.') {
							precision = atoi(number.c_str());
							precision_set = true;
						}
						else {
							skip = atoi(number.c_str());
							skip_set = true;
						}
						current_code += number;
					}
					else if (current_char == '.') {
						current_code += current_char;
						end++;
					}
					else if (current_char == 'n' && current_code == "%") {
						result += "\r\n";
						end++;
						parse_success = true;
					}
					else if (current_char == 'q' && current_code == "%") {
						result += '"';
						end++;
						parse_success = true;
					}
					else if (current_char == 'l' && current_code == "%") {
						if (!mwse::Stack::getInstance().empty()) {
							long value = mwse::Stack::getInstance().popLong();
							result.append(reinterpret_cast<char*>(&value), 4);
						}
						end++;
						parse_success = true;
					}
					else if (current_char == 'd' && current_code == "%") {
						if (!Stack::getInstance().empty()) {
							mwLong_t value = mwse::Stack::getInstance().popLong();
							convert.str("");
							convert << std::dec << value;
							result += convert.str();
						}
						end++;
						parse_success = true;
					}
					else if (current_char == 'h' && current_code == "%") {
						if (!Stack::getInstance().empty()) {
							mwLong_t value = mwse::Stack::getInstance().popLong();
							convert.str("");
							convert << std::hex << value;
							result += convert.str();
						}
						end++;
						parse_success = true;
					}
					else if (current_char == 'f') {
						if (!skip_set) {
							if (!Stack::getInstance().empty()) {
								mwFloat_t value = mwse::Stack::getInstance().popFloat();
								// 6 = vsprintf default precision - mimic old version
								if (!precision_set) precision = 6;
								convert.str("");
								convert << std::fixed << std::setprecision(precision) << value;
								result += convert.str();
							}
							parse_success = true;
						}
						else {
							current_code += current_char;
						}
						done = true;
						end++;
					}
					else if (current_char == 's') {
						if (!mwse::Stack::getInstance().empty()) {
							mwLong_t argument = Stack::getInstance().popLong();
							if (argument != 0) {
								mwseString_t value = virtualMachine.getString(argument);
								size_t substitute_start = std::min((size_t)skip, value.length());
								if (!precision_set) precision = value.length();
								result += value.substr(substitute_start, precision);
							}
						}
						end++;
						parse_success = true;
					}
					else {
						done = true;
						if (!std::isspace(current_char)) {
							current_code += current_char;
							end++;
						}
					}
					if (parse_success || end >= format.length()) done = true;
					if (done && !parse_success) {
						if (*badCodes != "") *badCodes += " ";
						*badCodes += current_code;
					}
				}
				start = end;
			}

			return result;
		}

		bool enumerate(const char *format, int& substitutions, bool& eolmode) {
			eolmode = false;
			substitutions = 0;
			while (*format)
			{
				if (*format != '%')
					format++;
				else
				{
					format++;
					while (*format >= '0' && *format <= '9')
						format++;
					if (*format == '.')
					{
						format++;
						if (*format < '0' || *format > '9')
							continue;
						while (*format >= '0' && *format <= '9')
							format++;
					}
					switch (*format)
					{
					case 0:
						eolmode = true;
						break;
					case 'N':
					case 'n':
					case 'Q':
					case 'q':
						format++;
						break;
					case 'L':
					case 'l':
					case 'D':
					case 'd':
					case 'H':
					case 'h':
					case 'F':
					case 'f':
					case 'S':
					case 's':
						substitutions++;
						format++;
					}
				}
			}
			return (eolmode || (substitutions > 0));
		}
	}
}