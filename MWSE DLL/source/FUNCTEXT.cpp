//FuncText.cpp

#include "FUNCTEXT.h"
#include "REFERENCE.h"
#include "TES3MEMMAP.h"
#include "TES3OPCODES.h"
#include "DEBUGGING.h"
#include "cLog.h"
#include <string.h>
// 22-08-2006 Tp21
#include "warnings.h"

#include <boost/regex.hpp>

#include <iomanip>
#include <sstream>
#include <string>

#ifndef ULONG
#define ULONG unsigned long int
#endif
	
#define LONGOFFSET(a,b) (VPVOID)(ULONG)( ((ULONG*)(a)) + b)

#define OFFSET_SCDT		0x16

int FUNCMESSAGEFIX::GetOperands(OPCODE opcode, VPVOID operanddata)
{
	scriptoffset = operanddata;
	return 0;
}

bool FUNCMESSAGEFIX::execute(void)
{
	VPVOID scriptaddr;
	VMREGTYPE addr;
	const char* str;
	USHORT mboxhdr[2];
	int len = 0;
	unsigned char buttonlen = 0;
	unsigned char buttoncount = 0;
	// we want to modify the real script SCDT info
	scriptaddr = (VPVOID)machine.GetScript();
	if (!GetOffsetData(machine, scriptaddr, OFFSET_SCDT, (ULONG*)&scriptaddr)) return false;
	scriptoffset += (ULONG)scriptaddr;
	// must be followed by messagebox opcode and length
	machine.ReadMem(scriptoffset,(VPVOID)mboxhdr,sizeof(mboxhdr));
	scriptoffset += sizeof(mboxhdr);
	if ( mboxhdr[0] != ORIG_MESSAGEBOX ) return false;	
	// get the parameter matching the main message string
    if (!machine.pop(addr)) return false;
	str = machine.GetString((VPVOID)addr);
	if ( str && *str )	{ // can skip the substitution if the string is empty or nonexistant
		bool suppress_null = false;
		std::string bad_codes;
		std::string const new_string = interpolate(str, &machine,
			&suppress_null, &bad_codes);
		if (bad_codes != "") {
			cLog::mLogMessage(
				"xMessageFix: bad format \"%s\" in \"%s\"\n",
				bad_codes.c_str(), str);
		}
		if (mboxhdr[1] < new_string.length()) {
			len = mboxhdr[1];
		}
		else {
			len = new_string.length() + 1;
		}
		if (suppress_null) --len;
		machine.WriteMem(scriptoffset,(VPVOID)new_string.c_str(), len);
	}
	scriptoffset += mboxhdr[1];
	// find the null after the orignal message string
	// (the "%.0f" style formatting is not allowed for the MessageBox, xMessageFix handles it here)
	machine.ReadMem(scriptoffset,(VPVOID)&buttoncount,1);	// using buttoncount as a temporary
	scriptoffset += 1;
    if (buttoncount != 0) return false;
    // next is the number of buttons to replace
	machine.ReadMem(scriptoffset,(VPVOID)&buttoncount,1);
	scriptoffset += 1;
	// for each button, replace it with string from the stack
	while (buttoncount != 0) {
		// find the amount of space available
		machine.ReadMem(scriptoffset,(VPVOID)&buttonlen,1);
		scriptoffset += 1;
		// get the replacement string
        if (!machine.pop(addr)) return false;
        str = machine.GetString((VPVOID)addr);
		if ( str && *str )	{ // can skip the substitution if the string is empty or nonexistant
			bool suppress_null = false;
			std::string bad_codes;
			std::string const new_string = interpolate(str, &machine, &suppress_null,
				&bad_codes);
			if (bad_codes != "") {
				cLog::mLogMessage(
					"xMessageFix: bad format \"%s\" in \"%s\"\n",
					bad_codes.c_str(), str);
			}
			if (buttonlen < new_string.length()) {
				len = buttonlen - 1;
			}
			else {
				len = new_string.length() + 1;
			}
			if (suppress_null) --len;
			machine.WriteMem(scriptoffset,(VPVOID)new_string.c_str(), len);
		}
		scriptoffset += buttonlen;
		// next button
		buttoncount--;
	}
	return true;
}

bool FUNCKEYPRESSED::execute(void) 
{
	static VMREGTYPE lastcode = 0;
	int i;
	VMREGTYPE code;
	
	if (!machine.pop(code)) code = 0;
	if ( code > 0 && code < 256 )		// a particular key, based on virtual key codes
	{
		i = GetAsyncKeyState(code & 0xFF);
		if ( i/2 )  i = 2 + i%2;
		return machine.push((VMREGTYPE)i);
	}
	else 			 		// any key will do, cycles through the list
	{
		i = lastcode;
		do {
			if ( i <= 0 || i >= 255 ) i = 254;
			else i--;
			if ( GetAsyncKeyState(i)/2 )	// currently down
			{
				// Generic Shift, Ctrl, and Alt only used if Left/Right versions aren't available
				if ( i==16 && (GetAsyncKeyState(160)/2 || GetAsyncKeyState(161)/2) ) continue;
				if ( i==17 && (GetAsyncKeyState(162)/2 || GetAsyncKeyState(163)/2) ) continue;
				if ( i==18 && (GetAsyncKeyState(164)/2 || GetAsyncKeyState(164)/2) ) continue;
				machine.push((VMREGTYPE)i);
				lastcode = i;
				return true;
			}
		} while ( i != lastcode );
		return machine.push((VMREGTYPE)0);
	}
	return true;
}

bool FUNCTEXTINPUT::execute(void) 
{
	static char buffer[BUFSIZ*4+1] = ""; 	// Only 2K?
	static char key[768] = { 1 };
	static char *string = buffer;
	char *str = buffer;
	int i, t;
	VMREGTYPE pstr, stopcode;
	
	if (!machine.pop(pstr) || pstr < 32768) return false;
	// String editing mode needs a string variable
	str=(char*)machine.GetString((VPVOID)pstr);
	if (!machine.pop(stopcode)) stopcode = 13;	// RETURN is default end of string
	if ( str && (str!=buffer) )
	{
		strcpy(buffer,str);
		string = buffer + strlen(buffer);	// position on the null
		machine.push((VMREGTYPE)buffer);
		machine.push((VMREGTYPE)0);
		return true;
	}
	if ( key[0] )	// Initialize the key database if needed
	{
		for (i=0;i<768;i++) key[i]=0;
		for (i=' ';i<='~';i++) 
			if (t = VkKeyScan(i))
			{
				key[t%256] = 1;
				key[t+256] = i;
			}
	}
	GetAsyncKeyState(VK_SHIFT);
	while (1) 
	{
		if ( (string >= (buffer+BUFSIZ*4)) || ((t=GetAsyncKeyState(stopcode)) && t%2 && t/2) )
		{
			machine.push((VMREGTYPE)strings.add(buffer));	// make it permanent
			machine.push((VMREGTYPE)(string-buffer+1));	// length includes the null
			return true;
		}
		if ( (t=GetAsyncKeyState(VK_BACK)) && t%2 && t/2 && string > buffer ) 
		{
			if ( *(string-1) == '\n' )
				*(--string) = 0;
			*(--string) = 0;
			machine.push((VMREGTYPE)buffer);
			machine.push((VMREGTYPE)0);
			return true;
		}
		if ( (t=GetAsyncKeyState(VK_RETURN)) && t%2 && t/2 && (string < (buffer+BUFSIZ*4-2)) ) 
		{
			*string++ = '\r';
			*string++ = '\n';
			machine.push((VMREGTYPE)buffer);
			machine.push((VMREGTYPE)0);
			return true;
		}
		for (i=32; i<255; i++)
			if ( key[i] && (t=GetAsyncKeyState(i)) && t%2 && t/2 )
			{
				if (GetAsyncKeyState(VK_SHIFT))
					*string++ = key[i+512];
				else
					*string++ = key[i+256];
				*string = 0;
				machine.push((VMREGTYPE)buffer);
				machine.push((VMREGTYPE)0);
				return true;
			}
	}
	return true;
}

bool FUNCTEXTINPUTALT::execute(void) 
{
	static char buffer[BUFSIZ*4+1] = ""; 	// Only 2K?
	static char key[768] = { 1 };
	static char *string = buffer;
	char *str = buffer;
	int i, t;
	VMREGTYPE pstr, stopcode;
	
	if (!machine.pop(pstr) || pstr < 32768) return false;
	// String editing mode needs a string variable
	str=(char*)machine.GetString((VPVOID)pstr);
	if (!machine.pop(stopcode)) stopcode = 13;	// RETURN is default end of string
	if ( str && (str!=buffer) )
	{
		strcpy(buffer,str);
		string = buffer + strlen(buffer);	// position on the null
		machine.push((VMREGTYPE)buffer);
		machine.push((VMREGTYPE)0);
		return true;
	}
	if ( key[0] )	// Initialize the key database if needed
	{
		for (i=0;i<768;i++) key[i]=0;
		for (i=' ';i<='~';i++) 
			if (t = VkKeyScan(i))
			{
				key[t%256] = 1;
				key[t+256] = i;
			}
	}
	GetAsyncKeyState(VK_SHIFT);
	if (1) 
	{
		if ( (string >= (buffer+BUFSIZ*4)) || ((t=GetAsyncKeyState(stopcode)) && t%2 && t/2) )
		{
			machine.push((VMREGTYPE)strings.add(buffer));	// make it permanent
			machine.push((VMREGTYPE)(string-buffer+1));	// length includes the null
			return true;
		}
		if ( (t=GetAsyncKeyState(VK_BACK)) && t%2 && t/2 && string > buffer ) 
		{
			if ( *(string-1) == '\n' )
				*(--string) = 0;
			*(--string) = 0;
			machine.push((VMREGTYPE)buffer);
			machine.push((VMREGTYPE)0);
			return true;
		}
		if ( (t=GetAsyncKeyState(VK_RETURN)) && t%2 && t/2 && (string < (buffer+BUFSIZ*4-2)) ) 
		{
			*string++ = '\r';
			*string++ = '\n';
			machine.push((VMREGTYPE)buffer);
			machine.push((VMREGTYPE)0);
			return true;
		}
		for (i=32; i<255; i++)
			if ( key[i] && (t=GetAsyncKeyState(i)) && t%2 && t/2 )
			{
				if (GetAsyncKeyState(VK_SHIFT))
					*string++ = key[i+512];
				else
					*string++ = key[i+256];
				*string = 0;
				machine.push((VMREGTYPE)buffer);
				machine.push((VMREGTYPE)0);
				return true;
			}
	}
	machine.push((VMREGTYPE)buffer);
	machine.push((VMREGTYPE)0);
	return true;
}

// 2005-07-10  CDC  Separate formatted string functions from the file I/O routines

// 2005-07-10  CDC   This just returns returns the string now, but there's a length function too.
bool FUNCSTRINGBUILD::execute(void)
{
	bool result = false;
	VMREGTYPE pstr = 0;
	const char* str;
	if (machine.pop(pstr) && ((str = machine.GetString((VPVOID)pstr)) != 0)) {
		bool suppress_null = false;
		std::string bad_codes;
		std::string new_string = interpolate(str, &machine, &suppress_null,
			&bad_codes);
		if (bad_codes != "") {
			cLog::mLogMessage(
				"xStringBuild: bad format \"%s\" in \"%s\"\n",
				bad_codes.c_str(), str);
		}
		if (new_string == "") {
			new_string = "null";
		}
		result = machine.push((VMREGTYPE)strings.add(new_string.c_str()));
	}
#ifdef DEBUGGING
	cLog::mLogMessage("FUNCSTRINGBUILD(%x,%s,%d) %s\n",str,str,result,result?"succeeded":"failed");
#endif
	return result;
}

bool FUNCSTRINGLENGTH::execute(void)
{
	bool result= false;
	VMREGTYPE pstr= 0;
	const char* str= "null";

	if ( machine.pop(pstr) && ( ( str=machine.GetString((VPVOID)pstr) ) !=0 ) )
	{
		result= machine.push((VMREGTYPE)strlen(str));
	}

#ifdef DEBUGGING
	//cLog::mLogMessage("FUNCSTRINGLENGTH(%s,%x,%d) %s\n",filename,str,result,result?"succeeded":"failed");
#endif

	return result;
}

// 2005-06-28  CDC  Not ideal, but this lets you extract data from a text string
bool FUNCSTRINGPARSE::execute(void)
{
	bool result= false;
	VMREGTYPE pFormat = 0;
	const char* format = "null";
	VMREGTYPE pstr = 0;
	const char* str= "null";
	int resultmax = 0;
	bool eolmode = false;

	if ( machine.pop(pFormat) && ( ( format=machine.GetString((VPVOID)pFormat) ) !=0 ) )
	{
		// Count how many results there should be based on the format string
		enumerate(format, resultmax, eolmode);
		resultmax++;		// There's always a status value
		VMREGTYPE* resultset=new VMREGTYPE[resultmax];	// Store results so we can push them on in reverse
		resultset[0] = 0;
		if ( machine.pop(pstr) && (str=(char*)machine.GetString((VPVOID)pstr)) )
			secernate(format, str, resultset, resultmax);
		while ( resultmax-- )
			result= machine.push((VMREGTYPE)resultset[resultmax]);
        delete[] resultset;
	}
#ifdef DEBUGGING
	//cLog::mLogMessage("FUNCSTRINGPARSE(%d,%s,%s) %s\n",resultset[0],format,str,result?"succeeded":"failed");
#endif
	return result;
}

std::string interpolate(std::string const& format, TES3MACHINE* machine,
						bool* suppress_null, std::string* bad_codes) {
	*suppress_null = false;
	*bad_codes = "";
	size_t start = 0;
	std::string result;
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
			*suppress_null = true;
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
			current_code += current_char;
			if (current_code == "%%") {
				result += current_char;
				end++;
				parse_success = true;
				done = true;
			} else if (std::isdigit(current_char)) {
				number = current_char;
				end++;
				while (end < format.length()) {
					current_char = format.at(end);
					if (std::isdigit(current_char)) {
						number += current_char;
						current_code += current_char;
						end++;
					} else {
						break;
					}
				}
				if (!current_code.empty() && 
					current_code.at(current_code.length() - 1) == '.') {
						precision = atoi(number.c_str());
						precision_set = true;
				} else {
					skip = atoi(number.c_str());
					skip_set = true;
				}
			} else if (current_char == '.') {
				end++;
			} else if (current_code == "%n") {
				result += "\r\n";
				end++;
				parse_success = true;
				done = true;
			} else if (current_code == "%q") {
				result += '"';
				end++;
				parse_success = true;
				done = true;
			} else if (current_code == "%l") {
				long argument = 0;
				if (machine->pop(argument)) {
					result.append(reinterpret_cast<char*>(&argument), 4);
				}
				end++;
				parse_success = true;
				done = true;
			} else if (current_code == "%d") {
				long argument = 0;
				if (machine->pop(argument)) {
					convert.str("");
					convert << std::dec << argument;
					result += convert.str();
				}
				end++;
				parse_success = true;
				done = true;
			} else if (current_code == "%h") {
				long argument = 0;
				if (machine->pop(argument)) {
					convert.str("");
					convert << std::hex << argument;
					result += convert.str();
				}
				end++;
				parse_success = true;
				done = true;
			} else if (current_char == 'f') {
				if (!skip_set) {
					float argument = 0;
					if (machine->pop(argument)) {
						convert.str("");
						// 6 = vsprintf default precision - mimic old version
						if (!precision_set) precision = 6;
						convert << std::fixed << std::setprecision(precision)
							<< argument;
						result += convert.str();
					}
					parse_success = true;
				}
				done = true;
				end++;
			} else if (current_char == 's') {
				long argument = 0;
				if (machine->pop(argument) && argument != 0) {
					std::string const substitute(machine->GetString(
						reinterpret_cast<unsigned char*>(argument)));
					size_t substitute_start = min(skip, substitute.length());
					if (!precision_set) precision = substitute.length();
					result += substitute.substr(substitute_start, precision);
				}
				end++;
				parse_success = true;
				done = true;
			} else {
				end++;
				done = true;
			}
			if (!done && end >= format.length()) {
				done = true;
			}
			if (done && !parse_success) {
				if (*bad_codes != "") *bad_codes += " ";
				*bad_codes += current_code;
			}
		}
		start = end;
	}
	return result;
}

// Count how many results there should be based on the format string
bool enumerate(const char *format, int& substitutions, bool& eolmode)
{
	eolmode = false;
	substitutions = 0;
	while ( *format )
	{
		if ( *format != '%' )
			format++;
		else
		{
			format++;
			while ( *format >= '0' && *format <= '9' )
				format++;
			if ( *format == '.' ) 
			{
				format++;
				if ( *format < '0' || *format > '9' )
					continue;
				while ( *format >= '0' && *format <= '9' )
					format++;
			}
			switch ( *format )
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



// Extract the values from the string based on the format data and store them in the resultset array
int secernate(const char* format, const char *string, VMREGTYPE* resultset, int resultmax)
{
	int resultcount = 1;		// count is first and set below
	int sign;
	int ivalue;
	float fvalue;
	char svalbuf[BUFSIZ*4];
	char *svalue;

	while ( format && *format && string && *string )
	{
		if ( *format != '%' )
		{
			if ( *format++ != *string++ )	// if not a literal match, quit
				format = 0;
		}
		else		// format symbol in format string found
		{
			int stringskip = 0;
			int stringwidth = -1;
			format++;
			while ( *format >= '0' && *format <= '9' )
			{
				stringskip = stringskip * 10 + *format - '0';
				format++;
			}
			if ( *format == '.' ) 
			{
				format++;
				if ( *format < '0' || *format > '9' ) 
				{
					if ( *string == '%' && *(string+1) == '.' )
						string += 2;	// literal %. matches
					else
						format = 0;	// no match, so quit.
					continue;
				}
				stringwidth = *format++ - '0';
				while ( *format >= '0' && *format <= '9' )
				{
					stringwidth = stringwidth * 10 + *format - '0';
					format++;
				}
			}

			if ( *format == 'N' || *format == 'n' )
			{
				format++;
				if ( *string == '\r' )
					string++;
				if ( *string == '\n' )
					string++;
				else
					format = 0;
			}
			else if ( *format == 'Q' || *format == 'q' )
			{
				format++;
				if ( *string == '"' )
					string++;
				else
					format = 0;
			}
			else if ( *format == 'L' || *format == 'l' )
			{
				format++;
				svalue = svalbuf;
				*((VMREGTYPE*)svalbuf) = 0;
				stringwidth = 4;
				while ( stringwidth-- && (*svalue++ = *string++) );
				resultset[resultcount++] = *((VMREGTYPE*)svalbuf);
			}
			else if ( *format == 'D' || *format == 'd' )
			{
				format++;
				ivalue = 0;
				sign = 1;
				if ( *string == '-' )
				{
					string++;
					sign = -1;
				}
				while ( *string >= '0' && *string <= '9' ) 
				{
					ivalue = ivalue * 10 + *string - '0';
					string++;
				}
				ivalue *= sign;
				resultset[resultcount++] = (VMREGTYPE)ivalue;
			}
			else if ( *format == 'H' || *format == 'h' )
			{
				format++;
				ULONG hvalue = 0;
				int length = 0;
				while ( length < 8 ) 
				{
					if ( *string >= '0' && *string <= '9' ) 
						hvalue = hvalue * 16 + *string - '0';
					else if ( *string >= 'a' && *string <= 'f' ) 
						hvalue = hvalue * 16 + *string - 'a' + 10;
					else if ( *string >= 'A' && *string <= 'F' ) 
						hvalue = hvalue * 16 + *string - 'A' + 10;
					else
						break;
					string++;
					length++;
				}
				resultset[resultcount++] = (VMREGTYPE)hvalue;
			}

			else if ( *format == 'F' || *format == 'f' )
			{
				format++;
				fvalue = 0.0;
				sign = 1;
				if ( *string == '-' )
				{
					string++;
					sign = -1;
				}
				while ( *string >= '0' && *string <= '9' ) 
				{
					fvalue = fvalue * 10.0 + (*string - '0');
					string++;
				}
				if ( *string == '.' )
				{
					string++;
					ivalue = 10;
					while ( *string >= '0' && *string <= '9' )
					{
						fvalue += 1.0 / ivalue * (*string - '0');
						ivalue *= 10;
						string++;
					}
				}
				fvalue *= sign;
				resultset[resultcount++] = (VMREGTYPE)(*((VMREGTYPE*)&fvalue));
			}

			else if ( *format == 'S' || *format == 's' )
			{
				format++;
				svalue = svalbuf;
				while ( stringskip-- && *string++ );	// skip some characters
				if ( stringwidth )	// standard greedy string mode
					while ( stringwidth-- && (*svalue++ = *string++) );
				else	// non-greedy string can be used like a "search" function
				{
					int stopsymbol = *format;
					if ( (stopsymbol == '%') && (*(format+1) != '%') )
					{
						stopsymbol = *(format+1);
						if ( stopsymbol == 'N' || stopsymbol == 'n' )
							stopsymbol = '\r';
						else if ( stopsymbol == 'Q' || stopsymbol == 'q' )
							stopsymbol = '"';
						else if ( stopsymbol == 'D' || stopsymbol == 'd' 
							|| stopsymbol == 'F' || stopsymbol == 'f' )
							stopsymbol = 0;
						else
							stopsymbol = *string;
					}
					while ( *string )
					{
						if ( *string == stopsymbol ) break;
						if ( !stopsymbol && ( *string == '-' || 
							( *string >= '0' && *string <= '9' ) ) ) break;
						*svalue++ = *string++;
					}
				}
				*svalue = 0;	// make sure it's null terminated
				resultset[resultcount++] = (VMREGTYPE)strings.add(svalbuf);
			}

			else if ( *format == '%' )
			{
				format++;
				if ( *string == '%' )
					string++;
				else
					format = 0;
			} 
			else if ( *format )
			{
				if ( *string == '%' && *(string+1) == *format )
				{
					string += 2;	// literal % matches
					format++;
				}
				else
					format = 0;
			}
		}
	}

	resultset[0] = resultcount - 1;		// assume it's the number of %subs performed
	if ( !(*string) && ( !format || !(*format) 
		|| (*format == '%' && !(*(format+1)))))	// completed string, so flag an extra
		resultset[0] = resultcount;

	while ( resultcount < resultmax )
		resultset[resultcount++] = (VMREGTYPE)0;
		
	return resultset[0];
}


// Regular expression string matching. Returns 1 (matches) or 0 (no match).
//   xStringMatch <string>, <string> -> <short>
//
bool FUNCSTRINGMATCH::execute(void)
{
    VMREGTYPE regString = 0;
    VMREGTYPE regPattern = 0;
    const char *string = "";
    const char *pattern = "";
    bool match = false;

	if ( machine.pop(regString) &&
        machine.pop(regPattern) ) {
        string = machine.GetString(reinterpret_cast<VPVOID>(regString));
        pattern = machine.GetString(reinterpret_cast<VPVOID>(regPattern));
        if (string != NULL && pattern != NULL) {
            match = boost::regex_search(string, boost::regex(pattern));
        }
    }
#ifdef DEBUGGING
	//cLog::mLogMessage("FUNCSTRINGPARSE(%d,%s,%s) %s\n",resultset[0],format,str,result?"succeeded":"failed");
#endif
	return machine.push(static_cast<VMREGTYPE>(match));
}

