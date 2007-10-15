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

import std.date;
import std.stdio;
import std.file;
import std.math;
import std.string;
import std.conv;
import std.random;
import Bytefield;
import SymbolTable;
import parser;



int PREPROCESS = 0x10E;
int STARTVM = 0x10F;
int JMP = 0x100;
int JNE = 0x101;
int JE = 0x102;
int JG = 0x103;
int JL = 0x104;
int SETVARTOLONG = 0x105;
int SETVARTOFLOAT = 0x106;
int SETVARTOSTRING = 0x107;
int SETVARTOLONGVAR = 0x108;
int SETVARTOFLOATVAR = 0x109;
int SETVARTOSTRINGVAR = 0x10A;

int COMPLONGVARS = 0x10B;
int COMPFLOATVARS = 0x10C;
int COMPSTRINGVARS = 0x10D;
int COMPFLOATTOVAR = 0x10E;
int COMPVARTOSTRING = 0x10F;
int COMPVARTOLONG = 0x110;
int ADDLONGTOVAR = 0x111;
int ADDFLOATTOVAR = 0x112;
int ADDFLOATVARS = 0x113;
int ADDLONGVARS = 0x114;
int MULLONGTOVAR = 0x115;
int MULFLOATTOVAR = 0x116;
int MULFLOATVARS = 0x117;
int MULLONGVARS = 0x118;
int INCVARBYLONG = 0x11A;
int INCVARBYFLOAT = 0x11B;
int INCVARBYFLOATVAR = 0x11C;
int INCVARBYLONGVAR = 0x11D;
int SETVARTOLONGRESULT = 0x119;
int SETVARTOFLOATRESULT = 0x11E;
int SETVARTOSTRINGRESULT = 0x11F;


int DISPLAYMESSAGE  = 0x200;
int GETTEMPLATE     =  0x201;
int CREATEWEAPON    =  0x202;
int GETBUTTONPRESSED = 0x203;
int GETTEXTINPUT = 0x204;
int SHOWINPUTBOX = 0x205;
int GETPCSNEAKING = 0x206;
int ADDITEM = 0x207;
int SETBOOKMULTIPLIER = 0x208;
int SETARMORMULTIPLIER = 0x209;
int SETWEAPONMULTIPLIER = 0x20A;
int SETCLOTHINGMULTIPLIER = 0x20B;
int SETINGREDIENTMULTIPLIER = 0x20C;
int SETMISCMULTIPLIER = 0x20D;
int CREATEARMOR = 0x20E;
int CREATEBOOK  = 0x20F;
int CREATECLOTHING = 0x210;
int SETTEMPLATENAME = 0x211;
int GETSCRIPT = 0x212;
int ISRUNNING = 0x213;
int STARTSCRIPT = 0x214;
int STOPSCRIPT = 0x215;
int KEYPRESSED = 0x216;
int ENTERMENUMODE = 0x217;
int LEAVEMENUMODE = 0x218;
int SETSLASHDAMAGE = 0x219;
int SETSLASHMIN = 0x21A;
int SETSLASHMAX = 0x21B;
int GETSLASHMIN = 0x21C;
int GETSLASHMAX = 0x21D;
int GETWEAPONMULTIPLIER = 0x21E;


int LONG = 0;
int FLOAT  = 1;
int STRING = 2;



//Globals
int GLOBAL_debugSwitch = 0;
Bytefield data;
Bytefield code;
Bytefield SCPTRecord;
Bytefield LongVarNames;
Bytefield FloatVarNames;
SymbolTable identifiers;
SymbolTable labels;
int numLongs;
int numFloats;

//this holds the name of the script currently being compiled.
char[] scriptName;

//this holds the number of scripts so far compiled.  A script is considered all the data between the Begin scriptName
//and End statements, so each file can contain multiple scripts.
int scriptCount;

//If the "start" keyword is encountered after "Begin scriptname", then an SSCR record for that script
//will be inserted right after the script'ss SCPT record.  An SSCR record for a script makes that script a start script,
//which means it is executed at the start of play.
int isStartScript;




int throwError(char[] message)
{
	writef("%s\n",message);
   	return -1;
}




struct Parameter
{
	union Value
	{
		int intVal;
		float floatVal;
	}
	int type;
	Value value;
}


Parameter newLongParameter(char[] funcInput)
{
	Parameter param;

	int symbolAddress = identifiers.getSymbolAddress(funcInput);
	int symbolType = identifiers.getSymbolType(funcInput);


	if(symbolAddress == -1)
    {

       	try
   		{
			int x = toLong(funcInput);
			param.value.intVal = x;
			param.type = 0;
			return param;
		}
   		catch (ConvError error)
   		{
			writef("%s\n","Symbol Undefined, or ill-formed long number");
   			return param;
		}
   	}
   	else if(symbolType != LONG)
   	{
   		throwError("Function parameter variable is of incorrect type");
   	}
    else
	{
		param.value.intVal = symbolAddress;
    	param.type = 1;
    	return param;
	}
	return param;
}


Parameter newFloatParameter(char[] funcInput)
{
	Parameter param;

	int symbolAddress = identifiers.getSymbolAddress(funcInput);
	int symbolType = identifiers.getSymbolType(funcInput);


	if(symbolAddress == -1)
    {

       	try
   		{
			float x = toFloat(funcInput);
			param.value.floatVal = x;
			param.type = 0;
			return param;
		}
   		catch (ConvError error)
   		{
			writef("%s\n","Symbol Undefined, or ill-formed floating-point number");
   			return param;
		}
   	}
   	else if(symbolType != FLOAT)
   	{
   		throwError("Function parameter variable is of incorrect type");
   	}
    else
	{
		param.value.intVal = symbolAddress;
    	param.type = 1;
    	return param;
	}
	return param;
}


Parameter newStringParameter(char[] funcInput)
{
	Parameter param;

	int symbolAddress = identifiers.getSymbolAddress(funcInput);
	int symbolType = identifiers.getSymbolType(funcInput);


	if(symbolAddress == -1)
    {

		if(find(funcInput,"\"") == -1)
		{
			throwError("variable undefined");
		}
		else
		{
			param.value.intVal = data.currentIndex+8;
     	  	param.type = 0;
			data.addStringLiteral(funcInput);
			return param;
		}
	}
	else
    {
    	if(symbolType != STRING)
    	{
    		throwError("Function parameter variable is of incorrect type");
    	}
    	else
		{
			param.value.intVal = symbolAddress;
    		param.type = 1;
    		return param;
		}
	}
    return param;
}



//to ensure that when a labels are replaced with their addresses, some random string of data in the code
// doesn't happen to look like a label, add 3 underscores to the front and back of a label.  That reduces
//the chance of this happening.
int newLabel(char[] labelName)
{
	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","new label");
	}
	if(labels.getSymbolAddress(labelName) == -1)
	{
		char[] newLabel;
		newLabel = "___"~labelName~"___";
		labels.addSymbol(newLabel,0,code.currentIndex);
	}
	else
	{
		throwError("Label already defined");
	}
	return 1;
}


int MATCH_jne(char[] labelName)
{
	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_jne");
	}
	char[] newLabel = "___"~labelName~"___";
	code.add(JNE);
	code.addLabel(newLabel);
	return 1;
}






int MATCH_je(char[] labelName)
{
	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_je");
	}
	char[] newLabel = "___"~labelName~"___";
	code.add(JE);
	code.addLabel(newLabel);
	return 1;
}

int MATCH_jg(char[] labelName)
{
	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_jgt");
	}
	char[] newLabel = "___"~labelName~"___";
	code.add(JG);
	code.addLabel(newLabel);
	return 1;
}

int MATCH_jl(char[] labelName)
{
	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_jlt");
	}
	char[] newLabel = "___"~labelName~"___";
	code.add(JL);
	code.addLabel(newLabel);
	return 1;
}





int MATCH_jmp(char[] labelName)
{
    if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_jmp");
	}
	char[] newLabel = "___"~labelName~"___";
	code.add(JMP);
	code.addLabel(newLabel);
	return 1;
}



int MATCH_setToLong(char[] ident, int longValue)
{
	int symbolIndex = identifiers.getSymbolAddress(ident);
	int symbolType = identifiers.getSymbolType(ident);
	
	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_setLong");
	}
	
	//if the symbol isn't yet in the symbol table
	if(symbolIndex == -1)
    {
		identifiers.addSymbol(ident,LONG,numLongs++);
    	LongVarNames.addWithDelimeter(ident);
	}
    else
    {
		if(symbolType != LONG)
    	{
    		throwError("Variable not of long type");
    		return -1;
		}
	}

	//write the operation, the result operand address, and the operand to the code buffer.
 	code.add(SETVARTOLONG);
	code.add(identifiers.getSymbolAddress(ident));
  	code.add(longValue);

	return 1;
}



int MATCH_setToFloat(char[] ident, float floatValue)
{
	int symbolIndex = identifiers.getSymbolAddress(ident);
	int symbolType = identifiers.getSymbolType(ident);
	
	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_setFloat");
	}

	//if the symbol isn't yet in the symbol table
	if(symbolIndex == -1)
    {
		identifiers.addSymbol(ident,FLOAT,numFloats++);
    	FloatVarNames.addWithDelimeter(ident);
	}
    else
    {
		if(symbolType != FLOAT)
    	{
    		throwError("Variable not of float type");
    		return -1;
		}
	}

	//write the operation, the result operand address, and the operand to the code buffer.
 	code.add(SETVARTOFLOAT);
	code.add(identifiers.getSymbolAddress(ident));
  	code.add(floatValue);

	return 1;
}



int MATCH_setToVar(char[] ident1, char[] ident2)
{
	int symbolIndex1 = identifiers.getSymbolAddress(ident1);
	int symbolType1 = identifiers.getSymbolType(ident1);
	int symbolIndex2 = identifiers.getSymbolAddress(ident2);
	int symbolType2 = identifiers.getSymbolType(ident2);
    
	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_setToVar");
	}

	if(symbolIndex2 == -1)
	{
		throwError("Variable undefined");
		return -1;
	}

	//if the result symbol isn't yet in the symbol table
	if(symbolIndex1 == -1)
    {

		if(symbolType2 == LONG)
		{
        	identifiers.addSymbol(ident1,LONG,numLongs++);
  			LongVarNames.addWithDelimeter(ident1);
        }
        else if(symbolType2 == FLOAT)
        {
        	identifiers.addSymbol(ident1,FLOAT,numFloats++);
  			FloatVarNames.addWithDelimeter(ident1);
        }
        else if(symbolType2 == STRING)
        {
        	identifiers.addSymbol(ident1,STRING,numLongs++);
   			LongVarNames.addWithDelimeter(ident1);
        }
    }
    else if(symbolType1 != symbolType2)
    {
    	throwError("Variables not of the same type");
    	return -1;
	}

	if(symbolType2 == LONG)
	{
    	code.add(SETVARTOLONGVAR);
		code.add(identifiers.getSymbolAddress(ident1));
  		code.add(symbolIndex2);
	}
	else if(symbolType2 == FLOAT)
	{
    	code.add(SETVARTOFLOATVAR);
		code.add(identifiers.getSymbolAddress(ident1));
  		code.add(symbolIndex2);
	}
	else if(symbolType2 == STRING)
	{
    	code.add(SETVARTOSTRINGVAR);
		code.add(identifiers.getSymbolAddress(ident1));
  		code.add(symbolIndex2);
	}
	return 1;
}











int MATCH_compVarVar(char[] ident1, char[] ident2)
{
	int symbolAddress1 = identifiers.getSymbolAddress(ident1);
	int symbolType1  = identifiers.getSymbolType(ident1);
	int	symbolAddress2 = identifiers.getSymbolAddress(ident2);
	int	symbolType2  = identifiers.getSymbolType(ident2);

	if(GLOBAL_debugSwitch)
	{
		writef("%s\n","MATCH_compVarVar");
	}

  	if(symbolAddress1 == -1)
    {
		if(symbolAddress2 == -1)
	    {
			throwError("var2 of comp var1,var2 undefined");
			return -1;
		}

		//If the first variable is undefined, but the second isn't, add the first variable
		//to the symbol table with the type of the second variable
		else
		{
			if(symbolType2 == LONG)
			{
	        	identifiers.addSymbol(ident1,LONG,numLongs++);
	  			LongVarNames.addWithDelimeter(ident1);
	        }
	        else if(symbolType2 == FLOAT)
	        {
	        	identifiers.addSymbol(ident1,FLOAT,numFloats++);
	  			FloatVarNames.addWithDelimeter(ident1);
	        }
	        else if(symbolType2 == STRING)
	        {
	        	identifiers.addSymbol(ident1,STRING,numLongs++);
	   			LongVarNames.addWithDelimeter(ident1);
	        }
		}

	}
	else if(symbolAddress2 == -1)
	{
		throwError("var2 of comp var1,var2 undefined");
		return -1;
	}

	else if(symbolType1 != symbolType2)
	{
    		throwError("First and second halfs of comp operation are of different types");
			return -1;
	}
	else
	{
		if(symbolType2 == FLOAT)
		{
 		   code.add(COMPFLOATVARS);
    	   code.add(identifiers.getSymbolAddress(ident1));
    	   code.add(symbolAddress2);
  		}
        else if(symbolType2 == LONG)
		{

		   code.add(COMPLONGVARS);
    	   code.add(identifiers.getSymbolAddress(ident1));
    	   code.add(symbolAddress2);
  		}
  		else if(symbolType2 == STRING)
		{
 		   code.add(COMPSTRINGVARS);
    	   code.add(identifiers.getSymbolAddress(ident1));
    	   code.add(symbolAddress2);
  		}
    }
	return 1;
}


int MATCH_incVarByVar(char[] ident1,char[] ident2)
{
	int symbolIndex1 = identifiers.getSymbolAddress(ident1);
	int symbolType1 = identifiers.getSymbolType(ident1);
	int symbolIndex2 = identifiers.getSymbolAddress(ident2);
	int symbolType2 = identifiers.getSymbolType(ident2);

    if(GLOBAL_debugSwitch)
	{
    	writef("%s\n","MATCH_incVarByVar");
	}


	if(symbolIndex1 == -1)
	{
		if(symbolType2 == LONG)
		{
        	identifiers.addSymbol(ident1,LONG,numLongs++);
  			LongVarNames.addWithDelimeter(ident1);
        }
        else if(symbolType2 == FLOAT)
        {
        	identifiers.addSymbol(ident1,FLOAT,numFloats++);
  			FloatVarNames.addWithDelimeter(ident1);
        }
        else if(symbolType2 == STRING)
        {
        	identifiers.addSymbol(ident1,STRING,numLongs++);
   			LongVarNames.addWithDelimeter(ident1);
        }
	}

	//Variable 1 is already in the symbol table, but it doesn't have the same type as the other
	//variable
	else if(symbolType1 != symbolType2)
	{
		throwError("Variables are not of same type");
		return -1;
	}

	if(symbolIndex2 == -1)
	{
		throwError("Variables are undefined");
		return -1;
	}
 	


	if(identifiers.getSymbolType(ident1) == LONG)
	{
		code.add(INCVARBYLONGVAR);
		code.add(identifiers.getSymbolAddress(ident1));
		code.add(symbolIndex2);
	}
	else if(identifiers.getSymbolType(ident1) == FLOAT)
	{
		code.add(INCVARBYFLOATVAR);
		code.add(identifiers.getSymbolAddress(ident1));
		code.add(symbolIndex2);
	}

	return 1;
}

int MATCH_incVarByLong(char[] ident1,int longValue)
{
	int symbolAddress = identifiers.getSymbolAddress(ident1);
	int symbolType  = identifiers.getSymbolType(ident1);

    if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_incVarByLong");
	}

	//if the symbol isn't yet in the symbol table
	if(symbolAddress == -1)
    {
    	identifiers.addSymbol(ident1,LONG,numLongs++);
		LongVarNames.addWithDelimeter(ident1);
	}
	else if(symbolType != LONG)
	{
       	throwError("Variable not of long type");
		return -1;
	}
    
	code.add(INCVARBYLONG);
  	code.add(identifiers.getSymbolAddress(ident1));
   	code.add(longValue);

	return 1;
}

int MATCH_incVarByFloat(char[] ident1,float floatValue)
{
	int symbolAddress = identifiers.getSymbolAddress(ident1);
	int symbolType  = identifiers.getSymbolType(ident1);

    if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_incVarByFloat");
	}

	//if the symbol isn't yet in the symbol table
	if(symbolAddress == -1)
    {
    	identifiers.addSymbol(ident1,FLOAT,numFloats++);
        FloatVarNames.addWithDelimeter(ident1);
	}
	else if(symbolType != FLOAT)
	{
       	throwError("Variable not of float type");
		return -1;
	}
    
	code.add(INCVARBYFLOAT);
  	code.add(identifiers.getSymbolAddress(ident1));
   	code.add(floatValue);

	return 1;
}

int MATCH_compVarLong(char[] ident1, int longValue)
{
	int symbolAddress = identifiers.getSymbolAddress(ident1);
	int symbolType  = identifiers.getSymbolType(ident1);

	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","OP_compVarLong");
	}

	//if the symbol isn't yet in the symbol table
	if(symbolAddress == -1)
    {
    	identifiers.addSymbol(ident1,LONG,numLongs++);
      	LongVarNames.addWithDelimeter(ident1);
	}
	else if(symbolType != LONG)
	{
       	throwError("Variable not of long type");
		return -1;
	}

	code.add(COMPVARTOLONG);
  	code.add(identifiers.getSymbolAddress(ident1));
   	code.add(longValue);

 	return 1;
}

int MATCH_compVarFloat(char[] ident1, float floatValue)
{
	int symbolAddress = identifiers.getSymbolAddress(ident1);
	int symbolType  = identifiers.getSymbolType(ident1);

	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","OP_compVarLong");
	}

	//if the symbol isn't yet in the symbol table
	if(symbolAddress == -1)
    {
    	identifiers.addSymbol(ident1,FLOAT,numFloats++);
    	LongVarNames.addWithDelimeter(ident1);
	}
	else if(symbolType != FLOAT)
	{
       	throwError("Variable not of float type");
		return -1;
	}

	code.add(COMPFLOATTOVAR);
  	code.add(identifiers.getSymbolAddress(ident1));
   	code.add(floatValue);

 	return 1;
}








int MATCH_compVarString(char[] ident, char[] stringValue)
{
	int symbolAddress = identifiers.getSymbolAddress(ident);
	int symbolType  = identifiers.getSymbolType(ident);

	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","OP_compVarString");
	}

	//if the symbol isn't yet in the symbol table
	if(symbolAddress == -1)
    {
    	identifiers.addSymbol(ident,STRING,numLongs++);
		LongVarNames.addWithDelimeter(ident);
	}
	else if(symbolType != STRING)
	{
		throwError("Variable not of string type");
		return -1;
	}

	code.add(COMPVARTOSTRING);
  	code.add(identifiers.getSymbolAddress(ident));
   	code.add(data.currentIndex+8);
	data.addStringLiteral(stringValue);

 	return 1;
}



int foundComment()
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","found comment");
	}

	return 1;
}






int MATCH_setToString(char[] ident, char[] string)
{
	int symbolIndex = identifiers.getSymbolAddress(ident);
	int symbolType = identifiers.getSymbolType(ident);

    if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_setString");
	}

	//if the symbol isn't yet in the symbol table
	if(symbolIndex == -1)
    {
		identifiers.addSymbol(ident,STRING,numLongs++);
    	LongVarNames.addWithDelimeter(ident);
	}
    else
    {
		if(symbolType != STRING)
    	{
    		throwError("Variable not of string type");
    		return -1;
		}
	}

	//write the operation and opcode to the code Bytefield
 	code.add(SETVARTOSTRING);
	code.add(identifiers.getSymbolAddress(ident));
	code.add(data.currentIndex+8);
	data.addStringLiteral(string);




	return 1;
}

int MATCH_setToResult(char[] ident, int type)
{
	int symbolIndex = identifiers.getSymbolAddress(ident);
	int symbolType = identifiers.getSymbolType(ident);
	
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_setToResult");
	}

	//if the symbol isn't yet in the symbol table
	if(symbolIndex == -1)
    {
		if(type == LONG)
		{
			identifiers.addSymbol(ident,LONG,numLongs++);
  			LongVarNames.addWithDelimeter(ident);
        }
        else if(type == FLOAT)
        {
			identifiers.addSymbol(ident,FLOAT,numFloats++);
  			FloatVarNames.addWithDelimeter(ident);
        }
        else if(type == STRING)
        {
        	identifiers.addSymbol(ident,STRING,numLongs++);
   			LongVarNames.addWithDelimeter(ident);
        }
    }
    else
    {
		if(symbolType != type)
    	{
    		throwError("Variable not of function return type");
    		return -1;
		}
	}
	if(type == LONG)
	{
		code.add(SETVARTOLONGRESULT);
	}
	else if(type == FLOAT)
	{

		code.add(SETVARTOFLOATRESULT);
	}
	else if(type == STRING)
	{
		code.add(SETVARTOSTRINGRESULT);
	}

	//the address of the variable that the result value will be stored in
	code.add(identifiers.getSymbolAddress(ident));


	return 1;
}




int MATCH_addVarVar(char[] ident1,char[] ident2,char[] ident3)
{
	int symbolIndex1 = identifiers.getSymbolAddress(ident1);
	int symbolType1 = identifiers.getSymbolType(ident1);
	int symbolIndex2 = identifiers.getSymbolAddress(ident2);
	int symbolType2 = identifiers.getSymbolType(ident2);
	int symbolIndex3 = identifiers.getSymbolAddress(ident3);
	int symbolType3 = identifiers.getSymbolType(ident3);


    if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_addVarVar");
	}



	//Variables 2 and 3 are of the same type, but the first variable is not yet in the symbol table
	if(symbolIndex1 == -1)
	{

		if(symbolType2 == LONG)
		{
        	identifiers.addSymbol(ident1,LONG,numLongs++);
  			LongVarNames.addWithDelimeter(ident1);
        }
        else if(symbolType2 == FLOAT)
        {
        	identifiers.addSymbol(ident1,FLOAT,numFloats++);
  			FloatVarNames.addWithDelimeter(ident1);
        }
        else if(symbolType2 == STRING)
        {
        	identifiers.addSymbol(ident1,STRING,numLongs++);
   			LongVarNames.addWithDelimeter(ident1);
        }
	}

	//Variable 1 is already in the symbol table, but it doesn't have the same type as the other two
	//variables
	else if(symbolType1 != symbolType3)
	{
		throwError("Variables are not of same type");
		return -1;
	}

	if(symbolIndex2 == -1 || symbolIndex3 == -1)
	{
		throwError("Variables are undefined");
		return -1;
	}
    else if(symbolType2 != symbolType3)
	{
		throwError("Variables are not of same type");
		return -1;
	}

	if(identifiers.getSymbolType(ident1) == LONG)
	{
		code.add(ADDLONGVARS);
		code.add(identifiers.getSymbolAddress(ident1));
		code.add(symbolIndex2);
		code.add(symbolIndex3);
	}
	else if(identifiers.getSymbolType(ident1) == FLOAT)
	{
		code.add(ADDFLOATVARS);
		code.add(identifiers.getSymbolAddress(ident1));
		code.add(symbolIndex2);
		code.add(symbolIndex3);
	}

	return 1;
}


int MATCH_mulVarVar(char[] ident1,char[] ident2,char[] ident3)
{
	int symbolIndex1 = identifiers.getSymbolAddress(ident1);
	int symbolType1 = identifiers.getSymbolType(ident1);
	int symbolIndex2 = identifiers.getSymbolAddress(ident2);
	int symbolType2 = identifiers.getSymbolType(ident2);
	int symbolIndex3 = identifiers.getSymbolAddress(ident3);
	int symbolType3 = identifiers.getSymbolType(ident3);


    if(GLOBAL_debugSwitch)
    {
		writef("%s\n","mulVarVar");
	}



	//Variables 2 and 3 are of the same type, but the first variable is not yet in the symbol table
	if(symbolIndex1 == -1)
	{
		if(symbolType2 == LONG)
		{
        	identifiers.addSymbol(ident1,LONG,numLongs++);
  			LongVarNames.addWithDelimeter(ident1);
        }
        else if(symbolType2 == FLOAT)
        {
        	identifiers.addSymbol(ident1,FLOAT,numFloats++);
  			FloatVarNames.addWithDelimeter(ident1);
        }
        else if(symbolType2 == STRING)
        {
        	identifiers.addSymbol(ident1,STRING,numLongs++);
   			LongVarNames.addWithDelimeter(ident1);
        }
	}

	//Variable 1 is already in the symbol table, but it doesn't have the same type as the other two
	//variables
	else if(symbolType1 != symbolType3)
	{
		throwError("Variables are not of same type");
		return -1;
	}

	if(symbolIndex2 == -1 || symbolIndex3 == -1)
	{
		throwError("Variables are undefined");
		return -1;
	}
    else if(symbolType2 != symbolType3)
	{
		throwError("Variables are not of same type");
		return -1;
	}



	if(identifiers.getSymbolType(ident1) == LONG)
	{
		code.add(MULLONGVARS);
		code.add(identifiers.getSymbolAddress(ident1));
		code.add(symbolIndex2);
		code.add(symbolIndex3);
	}
	else if(identifiers.getSymbolType(ident1) == FLOAT)
	{
		code.add(MULFLOATVARS);
		code.add(identifiers.getSymbolAddress(ident1));
		code.add(symbolIndex2);
		code.add(symbolIndex3);
	}

	return 1;
}



int MATCH_addVarLong(char[] ident1,char[] ident2,int longValue)
{
	int symbolIndex1 = identifiers.getSymbolAddress(ident1);
	int symbolType1 = identifiers.getSymbolType(ident1);
	int symbolIndex2 = identifiers.getSymbolAddress(ident2);
	int symbolType2 = identifiers.getSymbolType(ident2);


    if(GLOBAL_debugSwitch)
    {
    	writef("%s\n","MATCH_addVarLong");
	}

	if(symbolIndex1 == -1)
	{

		identifiers.addSymbol(ident1,LONG,numLongs++);
  		LongVarNames.addWithDelimeter(ident1);
	}

	else if(symbolType1 != LONG)
	{
		throwError("Variable not of long type");
		return -1;
	}

	if(symbolIndex2 == -1)
	{
		throwError("Variable is undefined");
		return -1;
	}
    else if(symbolType2 != LONG)
	{
		throwError("Variable not of long type");
		return -1;
	}

	code.add(ADDLONGTOVAR);
	code.add(identifiers.getSymbolAddress(ident1));
	code.add(symbolIndex2);
	code.add(longValue);

	return 1;
}

int MATCH_addVarFloat(char[] ident1,char[] ident2, float floatValue)
{
	int symbolIndex1 = identifiers.getSymbolAddress(ident1);
	int symbolType1 = identifiers.getSymbolType(ident1);
	int symbolIndex2 = identifiers.getSymbolAddress(ident2);
	int symbolType2 = identifiers.getSymbolType(ident2);


    if(GLOBAL_debugSwitch)
    {
    	writef("%s\n","MATCH_addVarFloat");
	}

	if(symbolIndex1 == -1)
	{

		identifiers.addSymbol(ident1,FLOAT,numFloats++);
  		FloatVarNames.addWithDelimeter(ident1);
	}

	else if(symbolType1 != FLOAT)
	{
		throwError("Variable not of float type");
		return -1;
	}

	if(symbolIndex2 == -1)
	{
		throwError("Variable is undefined");
		return -1;
	}
    else if(symbolType2 != FLOAT)
	{
		throwError("Variable not of float type");
		return -1;
	}

	code.add(ADDFLOATTOVAR);
	code.add(identifiers.getSymbolAddress(ident1));
	code.add(symbolIndex2);
	code.add(floatValue);



	return 1;
}




int MATCH_mulVarLong(char[] ident1,char[] ident2,int longAddress)
{
	int symbolIndex1 = identifiers.getSymbolAddress(ident1);
	int symbolType1 = identifiers.getSymbolType(ident1);
	int symbolIndex2 = identifiers.getSymbolAddress(ident2);
	int symbolType2 = identifiers.getSymbolType(ident2);


    if(GLOBAL_debugSwitch)
    {
    	writef("%s\n","MATCH_addVarLong");
	}

	if(symbolIndex1 == -1)
	{

		identifiers.addSymbol(ident1,LONG,numLongs++);
  		LongVarNames.addWithDelimeter(ident1);
	}

	else if(symbolType1 != LONG)
	{
		throwError("Variable not of long type");
		return -1;
	}

	if(symbolIndex2 == -1)
	{
		throwError("Variable is undefined");
		return -1;
	}
    else if(symbolType2 != LONG)
	{
		throwError("Variable not of long type");
		return -1;
	}

	code.add(MULLONGTOVAR);
	code.add(identifiers.getSymbolAddress(ident1));
	code.add(symbolIndex2);
	code.add(longAddress);



	return 1;
}


int MATCH_mulVarFloat(char[] ident1,char[] ident2,float floatParam)
{
	int symbolIndex1 = identifiers.getSymbolAddress(ident1);
	int symbolType1 = identifiers.getSymbolType(ident1);
	int symbolIndex2 = identifiers.getSymbolAddress(ident2);
	int symbolType2 = identifiers.getSymbolType(ident2);



    if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_addVarFloat");
 	}

	if(symbolIndex1 == -1)
	{

		identifiers.addSymbol(ident1,FLOAT,numFloats++);
  		FloatVarNames.addWithDelimeter(ident1);
	}

	else if(symbolType1 != FLOAT)
	{
		throwError("Variable not of float type");
		return -1;
	}

	if(symbolIndex2 == -1)
	{
		throwError("Variable is undefined");
		return -1;
	}
    else if(symbolType2 != FLOAT)
	{
		throwError("Variable not of float type");
		return -1;
	}

	code.add(MULFLOATTOVAR);
	code.add(identifiers.getSymbolAddress(ident1));
	code.add(symbolIndex2);
	code.add(floatParam);
	return 1;
}


int MATCH_SetSlashMin(Parameter weaponTemplate,Parameter min)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetSlashMin");
	}

	code.add(SETSLASHMIN);
	code.add(weaponTemplate);
	code.add(min);
	return LONG;
}

int MATCH_SetSlashMax(Parameter weaponTemplate,Parameter max)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetSlashMax");
	}

	code.add(SETSLASHMAX);
	code.add(weaponTemplate);
	code.add(max);


	return LONG;
}




int MATCH_GetSlashMin(Parameter weaponTemplate)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_GetSlashMin");
	}

	code.add(GETSLASHMIN);
	code.add(weaponTemplate);
	return LONG;
}

int MATCH_GetSlashMax(Parameter weaponTemplate)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_GetSlashMax");
	}
	code.add(GETSLASHMAX);
	code.add(weaponTemplate);
	return LONG;
}
















int MATCH_EnterMenuMode()
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_EnterMenuMode");
	}
	code.add(ENTERMENUMODE);
	return LONG;
}

int MATCH_LeaveMenuMode()
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_EnterMenuMode");
	}
	code.add(LEAVEMENUMODE);
	return LONG;
}

int MATCH_GetScript(Parameter scriptName)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_GetScript");
	}
	code.add(GETSCRIPT);
	code.add(scriptName);
	return LONG;
}


int MATCH_IsRunning(Parameter scriptAddress)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_IsRunning");
	}
	code.add(ISRUNNING);
	code.add(scriptAddress);
	return LONG;
}




int MATCH_StartScript(Parameter scriptAddress, Parameter resetVars)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_StartScript");
	}
	code.add(STARTSCRIPT);
	code.add(scriptAddress);
	code.add(resetVars);
	return LONG;
}

int MATCH_StopScript(Parameter scriptAddress, Parameter resetVars)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_StopScript");
	}
	code.add(STOPSCRIPT);
	code.add(scriptAddress);
	code.add(resetVars);
	return LONG;
}







int MATCH_KeyPressed(Parameter key)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_KeyPressed");
	}

	code.add(KEYPRESSED);
	code.add(key);
	return LONG;
}


int MATCH_GetWeaponMultiplier()
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_GetWeaponMultiplier");
	}
	code.add(GETWEAPONMULTIPLIER);
	return FLOAT;
}




int MATCH_SetBookMultiplier(Parameter mult)
{

	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetBookMultiplier");
	}
	if(mult.value.floatVal < 0)
	{
		throwError("ERROR: Item value multiplier cannot be less than 0");
	}

	code.add(SETBOOKMULTIPLIER);
	code.add(mult);
	return LONG;
}


int MATCH_SetArmorMultiplier(Parameter mult)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetArmorMultiplier");
	}

	if(mult.value.floatVal < 0)
	{
		throwError("ERROR: Item value multiplier cannot be less than 0");
	}



	code.add(SETARMORMULTIPLIER);
	code.add(mult);
	return LONG;
}

int MATCH_SetWeaponMultiplier(Parameter mult)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetWeaponMultiplier");
	}

	if(mult.value.floatVal < 0)
	{
		throwError("ERROR: Item value multiplier cannot be less than 0");
	}


	code.add(SETWEAPONMULTIPLIER);
	code.add(mult);
	return LONG;
}

int MATCH_SetClothingMultiplier(Parameter mult)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetBookMultiplier");
	}

	if(mult.value.floatVal < 0)
	{
		throwError("ERROR: Item value multiplier cannot be less than 0");
	}


	code.add(SETCLOTHINGMULTIPLIER);
	code.add(mult);
	return LONG;
}

int MATCH_SetIngredientMultiplier(Parameter mult)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetBookMultiplier");
	}

	if(mult.value.floatVal < 0)
	{
		throwError("ERROR: Item value multiplier cannot be less than 0");
	}

	code.add(SETINGREDIENTMULTIPLIER);
	code.add(mult);
	return LONG;
}

int MATCH_SetMiscMultiplier(Parameter mult)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetBookMultiplier");
	}

	if(mult.value.floatVal < 0)
	{
		throwError("ERROR: Item value multiplier cannot be less than 0");
	}


	code.add(SETMISCMULTIPLIER);
	code.add(mult);
	return LONG;
}


int MATCH_GetButtonPressed()
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_GetButtonPressed");
	}
	code.add(GETBUTTONPRESSED);
	return LONG;
}

int MATCH_GetTextInput()
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_GetTextInput");
	}
	code.add(GETTEXTINPUT);
	return STRING;
}

int MATCH_GetPCSneaking()
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_GetPCSneaking");
	}
	code.add(GETPCSNEAKING);
	return LONG;
}


int MATCH_ShowInputBox(Parameter titleString, Parameter buttonText)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_ShowInputBox");
	}
	code.add(SHOWINPUTBOX);
	code.add(titleString);
	code.add(buttonText);
	return LONG;
}



int MATCH_GetTemplate(Parameter templateString)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_GetTemplate");
	}
	code.add(GETTEMPLATE);
	code.add(templateString);
	return LONG;
}

int MATCH_CreateWeapon(Parameter templateAddress)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_CreateWeapon");
	}
	code.add(CREATEWEAPON);
	code.add(templateAddress);
	return LONG;
}


int MATCH_CreateArmor(Parameter templateAddress)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","CreateArmor");
	}
	code.add(CREATEARMOR);
	code.add(templateAddress);
	return LONG;
}


int MATCH_CreateBook(Parameter templateAddress)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_CreateBook");
	}
	code.add(CREATEBOOK);
	code.add(templateAddress);
	return LONG;
}

int MATCH_SetTemplateName(Parameter templateAddress, Parameter name)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetTemplateName");
	}
	code.add(SETTEMPLATENAME);
	code.add(templateAddress);
	code.add(name);
	return LONG;
}


int MATCH_SetSlashDamage(Parameter weaponTemplate,Parameter min, Parameter max)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_SetSlashDamage");
	}
	code.add(SETSLASHDAMAGE);
	code.add(weaponTemplate);
	code.add(min);
	code.add(max);
	return LONG;
}










int MATCH_AddItem(Parameter containerTemplate, Parameter itemTemplate, Parameter itemCount)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_AddItem");
	}
	code.add(ADDITEM);
	code.add(containerTemplate);
	code.add(itemTemplate);
	code.add(itemCount);
	return LONG;
}



int MATCH_CreateClothing(Parameter templateAddress)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_CreateClothing");
	}
	code.add(CREATECLOTHING);
	code.add(templateAddress);
	return LONG;
}



int MATCH_AddItem(Parameter containerAddress, Parameter itemAddress)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_CreateWeapon");
	}
	code.add(ADDITEM);
	code.add(containerAddress);

	return LONG;
}



int MATCH_DisplayMessage(Parameter message)
{
	if(GLOBAL_debugSwitch)
    {
		writef("%s\n","MATCH_DisplayMessage");
	}
	code.add(DISPLAYMESSAGE);
	code.add(message);
	return LONG;
}





int beginScript(char[] string, char[] startFlag)
{
    if(GLOBAL_debugSwitch)
    {
		writef("%s\n","start");
	}
    //a new script is to be compiled, so initialize the data structs used in compilation.
	data = new Bytefield();
	code = new Bytefield();
	LongVarNames = new Bytefield();
 	FloatVarNames = new Bytefield();

    identifiers = new SymbolTable(0);
    labels = new SymbolTable(8);
	numLongs = 0;
	numFloats = 0;

	isStartScript = 0;

	//if the "start" keyword is present, set the startScript variable to 1, to indicate that
	//an SSCR record for this script should be added to the esp.
	if(startFlag.length != 0)
	{
		isStartScript = 1;
	}

	//copy the script name--for use in
	scriptName.length = string.length;
	scriptName ~= "\0";
	scriptName[0..string.length] = string[0..string.length];

	scriptCount++;
	return 1;
}

int endScript()
{
    if(GLOBAL_debugSwitch)
    {
		writef("%s\n","end");
	}

	//This contains the concatenated data and code, in that order.
	Bytefield combined = new Bytefield();

	//Dword align the data so that the code is also dword aligned
	data.align4();

	//Right now, the code contains labels as text.  You will see things like "7801 LABEL1" in it.  LABEL1
	//needs to be replaced with its address, as stored in the symbol table.  First the offset of all labels
	//must be updated.
	labels.updateOffset(labels.offset+data.currentIndex);
	foreach(label;labels.table)
	{
		code.replace(label.name,label.address);
	}

	//These are the first 8 bytes of the combined data+code.  The instruction is to jump over the data,
	//to the rest of the instructions.
	combined.add(PREPROCESS);
	combined.add(data.currentIndex+8);


	 //Add the data and code to the combined data+code bytefield
	combined.add(data);
	combined.add(code);


	Bytefield SCVRData = new Bytefield();
 	SCVRData.add(LongVarNames);
 	SCVRData.add(FloatVarNames);
	SCVRData.align4();


    SCPTRecord.add("SCPT");
	SCPTRecord.add(combined.currentIndex+SCVRData.currentIndex+76);
	SCPTRecord.add(0);
	SCPTRecord.add(0);
	SCPTRecord.add("SCHD");
	SCPTRecord.add(0x34);
	SCPTRecord.add(scriptName);
	SCPTRecord.fill0(32-scriptName.length);
	SCPTRecord.add(0);
	SCPTRecord.add(numLongs);
	SCPTRecord.add(numFloats);
	SCPTRecord.add(combined.currentIndex);
	SCPTRecord.add(SCVRData.currentIndex);
	SCPTRecord.add("SCVR");
	SCPTRecord.add(SCVRData.currentIndex);
	SCPTRecord.add(SCVRData);
	SCPTRecord.add("SCDT");
	SCPTRecord.add(combined.currentIndex);
	SCPTRecord.add(combined);


	if(isStartScript == 1)
	{
    	Bytefield SSCRData = new Bytefield();

		SSCRData.add("DATA");
		SSCRData.add(0x11);

		char[] randomString = getRandomString(16,scriptCount);
		SSCRData.add(randomString);
		SSCRData.add("NAME");
		SSCRData.add(cast(int)scriptName.length);
		SSCRData.add(scriptName);
		SSCRData.align4();

		SCPTRecord.add("SSCR");
		SCPTRecord.add(SSCRData.currentIndex);
		SCPTRecord.add(0);
		SCPTRecord.add(0);
		SCPTRecord.add(SSCRData);

	 }

	return 1;
}


Bytefield compileScript(char[] fileName,int debugSwitch)
{
	GLOBAL_debugSwitch = debugSwitch;
	SCPTRecord = new Bytefield();
	Parser myParser = new Parser();
	char[] scriptBuffer = cast(char[])read(fileName);
	myParser.initialize(scriptBuffer);
	myParser.parse_Script();

   	//at the end of the file, return the compiled data
	return SCPTRecord;
}



//Returns 16 byte string of random numbers, 1 through 9.
char[] getRandomString(int size, int index)
{
	char[] result;
	int x;

	rand_seed(getUTCtime(),index);

	for(int i = 0; i < size; i++)
	{
    	x = (rand() % 9)+1;

		//the number + 48 equals the ASCII character for that number
		result ~= x+48;
	}

	//add the string delimeter
	result ~= 0;
	return	result;
}















