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


import std.outbuffer;
import std.stdio;
import compiler;


class Bytefield
{

	OutBuffer data;
	int currentIndex;

	this()
	{
		currentIndex = 0;
		data = new OutBuffer();
	}

	void add(int x)
	{
		data.write(x);
		currentIndex+=4;
	}


	void add(float x)
	{
		data.write(x);
		currentIndex+=4;
	}

	void add(Bytefield x)
	{
		data.write(x.data);
		currentIndex = currentIndex+x.currentIndex;
	}

	void add(char x)
	{
		data.write(x);
		currentIndex+=1;
	}

	void add(char[] x)
	{

    	data.write(x);
		currentIndex += x.length;
	}
	
	void addLabel(char[] x)
	{
		data.write(x);
		currentIndex += 4;
	}



	void add(Parameter p)
	{
		data.write(p.type);
		data.write(p.value.intVal);
		currentIndex+=8;
	}

	void align4()
	{
		data.align4();
		currentIndex = data.toString().length;
	}


   void addWithDelimeter(char[] string)
   {
		char[] newString = string;
  		newString ~="\0";

		data.write(newString);
  		currentIndex+=newString.length;
	}

	void addStringLiteral(char[] stringLiteral)
	{
		char[] withoutQuotes;

		//set the string length of the new string so that there is only room for the actual string, plus
		//one space for a string delimeter.
		withoutQuotes.length = stringLiteral.length-1;


		//eliminate the first quote mark
		withoutQuotes[0..stringLiteral.length-1] = stringLiteral[1..stringLiteral.length];

		//replace the second quote mark with a string delimeter
		withoutQuotes[withoutQuotes.length-1] = 0;

	    data.write(withoutQuotes);
	    currentIndex+=withoutQuotes.length;
		this.align4();
	}
	
	
	void replace(char[] toReplace, int replacement)
	{
		char[] dataString = this.toString();
		char[] newDataString;
		char[] byteString;
		OutBuffer newData = new OutBuffer();

		OutBuffer intAsBytes = new OutBuffer();
		intAsBytes.write(replacement);
		byteString = intAsBytes.toString();


		newDataString = std.string.replace(dataString,toReplace,byteString);

		newData.write(newDataString);

		//replace the outbuffer with the new one
		data = newData;
		currentIndex = newDataString.length;
	}
	
	
	void fill0(int n)
	{
    	data.fill0(n);
    	currentIndex+=n;
    }
    

	char[] toString()
	{
		return data.toString();
	}

	
	void reserve(uint nbytes)
	{
		data.reserve(nbytes);
		currentIndex+=nbytes;
	}
	
	void set(int index, int value)
	{
		ubyte[] byteData = data.toBytes();

		byteData[index] = value&255;
		byteData[index+1] = value>>8&255;
		byteData[index+2] = value>>16&255;
		byteData[index+3] = value>>24&255;
	
		OutBuffer newData = new OutBuffer();
		newData.write(byteData);
		data = newData;
	}
	





}