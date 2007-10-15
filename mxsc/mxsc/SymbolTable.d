/*
	Copyright Ryan Kluzak

	This file is part of mxsc

    mxsc is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    mxsc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with mxsc; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/


class SymbolTable
{

	int STRING = 0;
	int LONG = 1;
	int FLOAT  = 2;

	int offset;

	struct Symbol
	{
		char[] name;
		int type;
		int address;
	};

	Symbol table[char[]];

	this(int offset)
	{
		this.offset = offset;
	}

	int getSymbolAddress(char[] name)
	{
		Symbol *test = name in table;
		if(test == null)
		{
			return -1;
		}
		else
		{
			return test.address;
		}
	}

	//create a new table of symbols, with the old offset subtracted from the address, and the new offset
	//added to it.
	void updateOffset(int newOffset)
	{
		Symbol newTable[char[]];
		foreach(symbol;table)
		{
			newTable[symbol.name] = Symbol(symbol.name,symbol.type,symbol.address-this.offset+newOffset);
		}
		this.table = newTable;

	}


	int getSymbolType(char[] name)
	{
		Symbol *test = name in table;
		if(test == null)
		{
			return -1;
		}
		else
		{
			return test.type;
		}
	}


	int addSymbol(char[] name, int type, int address)
	{
		if(name in table)
		{
			return -1;
		}
		else
		{
			table[name] = Symbol(name,type,address+this.offset);
			return 1;
		}
	}
}
