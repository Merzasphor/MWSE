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



import std.stdio;
import std.string;
import std.file;
import Bytefield;
import SCPT;
import compiler;

int main(char[][] argv)
{
	int debugSwitch = 0;
	char[32] authorName = 0;
	char[260] description = 0;
	int arguments = argv.length;
	char[] outputFile;
	Bytefield ESPData = new Bytefield();

    if(arguments < 4)
	{
		writef("%s\n","Usage: mxsc -o [-d] <outfile.esp> <scriptname.mxs> <scriptname2.mxs>...<scriptname100.mxs>");
		return -1;
	}

	if(cmp(argv[2],"-d") == 0)
	{
		debugSwitch = 1;
	   	if(arguments < 5)
		{
			writef("%s\n","Usage: mxsc -o [-d] <outfile.esp> <scriptname.mxs> <scriptname2.mxs>...<scriptname100.mxs>");
			return -1;
		}
	}



	outputFile = argv[2+debugSwitch];

	ESPData.add("TES3");
	ESPData.add(0x134);
	ESPData.add(0);
	ESPData.add(0);
	ESPData.add("HEDR");
	ESPData.add(0x12c);
	ESPData.add(1.2);
	ESPData.add(0);
	ESPData.add(authorName);
	ESPData.add(description);

    for(int i = 3+debugSwitch; i < arguments; i++)
	{
 		Bytefield script = compileScript(argv[i],debugSwitch);
		ESPData.add(script);
	}

	 write(outputFile,ESPData.toString());


	return 1;
}

