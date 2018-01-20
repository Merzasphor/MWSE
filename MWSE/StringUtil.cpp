#include "StringUtil.h"

#include "Stack.h"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <iomanip>

namespace mwse {
	namespace string {
		namespace store {
			mwLong_t nextId = 0;

			// Static storage for strings, indexed by id.
			StringMap_t store;

			mwseString_t& create(const std::string& value) {
				mwLong_t id = nextId++;
				store.insert(StringMap_t::value_type(id, mwseString_t(id, value)));
				return get(id);
			}

			mwseString_t& create(const char* value) {
				mwLong_t id = nextId++;
				store.insert(StringMap_t::value_type(id, mwseString_t(id, value)));
				return get(id);
			}

			mwseString_t& create(const char* value, size_t length) {
				mwLong_t id = nextId++;
				store.insert(StringMap_t::value_type(id, mwseString_t(id, value, length)));
				return get(id);
			}

			bool clear() {
				bool cleared = true;
				if (nextId == 0) {
					cleared = false;
				}

				nextId = 0;
				store.clear();

				return cleared;
			}

			bool exists(const mwLong_t id) {
				return store.find(id) != store.end();
			}

			bool exists(const char* value) {
				for (StringMap_t::iterator it = store.begin(); it != store.end(); it++) {
					if (it->second.compare(value) == 0) {
						return true;
					}
				}

				return false;
			}

			bool exists(const std::string& value) {
				for (StringMap_t::iterator it = store.begin(); it != store.end(); it++) {
					if (it->second.compare(value) == 0) {
						return true;
					}
				}

				return false;
			}

			mwseString_t& get(const mwLong_t id) {
				auto it = store.find(id);
				if (it == store.end()) {
					return mwseString_t();
				}

				return it->second;
			}

			mwseString_t& get(const std::string& value) {
				for (StringMap_t::iterator it = store.begin(); it != store.end(); it++) {
					if (it->second.compare(value) == 0) {
						return it->second;
					}
				}

				return mwseString_t();
			}

			mwseString_t& getOrCreate(const char* value) {
				if (exists(value)) {
					return get(value);
				}

				return create(value);
			}

			mwseString_t& getOrCreate(const char* value, size_t length) {
				if (exists(value)) {
					return get(value);
				}

				return create(value, length);
			}

			mwseString_t& getOrCreate(const std::string& value) {
				if (exists(value)) {
					return get(value);
				}

				return create(value);
			}
		}

		std::string interpolate(const std::string& format, mwse::VMExecuteInterface &virtualMachine, bool* suppressNull, std::string* badCodes) {
			std::string result;

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
							mwseString_t& value = mwse::string::store::get(Stack::getInstance().popLong());
							if (value.isValid()) {
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

		int secernate(const char* format, const char* string, mwLong_t* results, int maxResults) {
			int resultcount = 1;		// count is first and set below
			int sign;
			int ivalue;
			float fvalue;
			char svalbuf[BUFSIZ * 4];
			char* svalue;

			while (format && *format && string && *string)
			{
				if (*format != '%')
				{
					if (*format++ != *string++)	// if not a literal match, quit
						format = 0;
				}
				else		// format symbol in format string found
				{
					int stringskip = 0;
					int stringwidth = -1;
					format++;
					while (*format >= '0' && *format <= '9')
					{
						stringskip = stringskip * 10 + *format - '0';
						format++;
					}
					if (*format == '.')
					{
						format++;
						if (*format < '0' || *format > '9')
						{
							if (*string == '%' && *(string + 1) == '.')
								string += 2;	// literal %. matches
							else
								format = 0;	// no match, so quit.
							continue;
						}
						stringwidth = *format++ - '0';
						while (*format >= '0' && *format <= '9')
						{
							stringwidth = stringwidth * 10 + *format - '0';
							format++;
						}
					}

					if (*format == 'N' || *format == 'n')
					{
						format++;
						if (*string == '\r')
							string++;
						if (*string == '\n')
							string++;
						else
							format = 0;
					}
					else if (*format == 'Q' || *format == 'q')
					{
						format++;
						if (*string == '"')
							string++;
						else
							format = 0;
					}
					else if (*format == 'L' || *format == 'l')
					{
						format++;
						svalue = svalbuf;
						*((mwLong_t*)svalbuf) = 0;
						stringwidth = 4;
						while (stringwidth-- && (*svalue++ = *string++));
						results[resultcount++] = *((mwLong_t*)svalbuf);
					}
					else if (*format == 'D' || *format == 'd')
					{
						format++;
						ivalue = 0;
						sign = 1;
						if (*string == '-')
						{
							string++;
							sign = -1;
						}
						while (*string >= '0' && *string <= '9')
						{
							ivalue = ivalue * 10 + *string - '0';
							string++;
						}
						ivalue *= sign;
						results[resultcount++] = (mwLong_t)ivalue;
					}
					else if (*format == 'H' || *format == 'h')
					{
						format++;
						unsigned long hvalue = 0;
						int length = 0;
						while (length < 8)
						{
							if (*string >= '0' && *string <= '9')
								hvalue = hvalue * 16 + *string - '0';
							else if (*string >= 'a' && *string <= 'f')
								hvalue = hvalue * 16 + *string - 'a' + 10;
							else if (*string >= 'A' && *string <= 'F')
								hvalue = hvalue * 16 + *string - 'A' + 10;
							else
								break;
							string++;
							length++;
						}
						results[resultcount++] = (mwLong_t)hvalue;
					}

					else if (*format == 'F' || *format == 'f')
					{
						format++;
						fvalue = 0.0;
						sign = 1;
						if (*string == '-')
						{
							string++;
							sign = -1;
						}
						while (*string >= '0' && *string <= '9')
						{
							fvalue = fvalue * 10.0f + (*string - '0');
							string++;
						}
						if (*string == '.')
						{
							string++;
							ivalue = 10;
							while (*string >= '0' && *string <= '9')
							{
								fvalue += 1.0f / ivalue * (*string - '0');
								ivalue *= 10;
								string++;
							}
						}
						fvalue *= sign;
						results[resultcount++] = (mwLong_t)(*((mwLong_t*)&fvalue));
					}

					else if (*format == 'S' || *format == 's')
					{
						format++;
						svalue = svalbuf;
						while (stringskip-- && *string++);	// skip some characters
						if (stringwidth)	// standard greedy string mode
							while (stringwidth-- && (*svalue++ = *string++));
						else	// non-greedy string can be used like a "search" function
						{
							int stopsymbol = *format;
							if ((stopsymbol == '%') && (*(format + 1) != '%'))
							{
								stopsymbol = *(format + 1);
								if (stopsymbol == 'N' || stopsymbol == 'n')
									stopsymbol = '\r';
								else if (stopsymbol == 'Q' || stopsymbol == 'q')
									stopsymbol = '"';
								else if (stopsymbol == 'D' || stopsymbol == 'd'
									|| stopsymbol == 'F' || stopsymbol == 'f')
									stopsymbol = 0;
								else
									stopsymbol = *string;
							}
							while (*string)
							{
								if (*string == stopsymbol) break;
								if (!stopsymbol && (*string == '-' ||
									(*string >= '0' && *string <= '9'))) break;
								*svalue++ = *string++;
							}
						}
						*svalue = 0;	// make sure it's null terminated
						results[resultcount++] = mwse::string::store::getOrCreate(svalbuf);
					}

					else if (*format == '%')
					{
						format++;
						if (*string == '%')
							string++;
						else
							format = 0;
					}
					else if (*format)
					{
						if (*string == '%' && *(string + 1) == *format)
						{
							string += 2;	// literal % matches
							format++;
						}
						else
							format = 0;
					}
				}
			}

			results[0] = resultcount - 1;		// assume it's the number of %subs performed
			if (!(*string) && (!format || !(*format)
				|| (*format == '%' && !(*(format + 1)))))	// completed string, so flag an extra
				results[0] = resultcount;

			while (resultcount < maxResults)
				results[resultcount++] = (mwLong_t)0;

			return results[0];
		}
	}
}