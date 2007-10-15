/*
	Copyright Ryan Kluzak

	This file is part of MWSE

    MWSE is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    MWSE is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with MWSE; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <windows.h>
#include "vm.h"
#include <string.h>







int WINAPI DllMain(HINSTANCE hInstance, DWORD fdwReason, PVOID pvReserved)
{


	if(fdwReason == DLL_PROCESS_ATTACH)
	{
		DWORD dwOld;
		
		//before this, the number of "core" ops is 8.  I change it to 9.  The ninth
		//op is "0x10E", which signifies that our custom vm should take control
		char *numberOfOps = (char *)0x500572;
		

		int *oldInstructionTable = (int *)0x502144;
		int *newInstructionTable = (int *)0x73625e;
		char *instructionCall = (char *)0x50057b;


		char *newCallAddress1 = (char *)0x736f8c;
		char *soulGemCall =  (char *)0x59175d;
		char *standardItemValueCall1 =  (char *)0x5917a5;
		char *standardItemValueCall2 = (char *)0x5917ca;
		char *potionValueCall =  (char *)0x5917ca;


		//Set the largest OP to A.
		VirtualProtect(numberOfOps,3,PAGE_EXECUTE_READWRITE,&dwOld);
		numberOfOps[0] = (char)0x83;
		numberOfOps[1] = (char)0xF8;
		numberOfOps[2] = (char)0x0A;


		//change the reference to the new call table.
        VirtualProtect(instructionCall,7,PAGE_EXECUTE_READWRITE,&dwOld);
		instructionCall[0] = (char)0xff;
		instructionCall[1] = (char)0x24;
		instructionCall[2] = (char)0x85;
		instructionCall[3] = (char)0x5e;
		instructionCall[4] = (char)0x62;
        instructionCall[5] = (char)0x73;
        instructionCall[6] = (char)0x00;



		//Create a new optable to supplant the original, this one with two extra entries at the end.
		VirtualProtect(newInstructionTable,0x44,PAGE_EXECUTE_READWRITE,&dwOld);

		newInstructionTable[0x105-0x105] = 0x500582;

		newInstructionTable[0x106-0x105] = 0x500724;
		newInstructionTable[0x107-0x105] = 0x5007A7;
		newInstructionTable[0x108-0x105] = 0x50074B;
		newInstructionTable[0x109-0x105] = 0x502139;

		newInstructionTable[0x10A-0x105] = 0x5007c5;
		newInstructionTable[0x10B-0x105] = 0x502139;
		newInstructionTable[0x10C-0x105] = 0x500852;
		newInstructionTable[0x10D-0x105] = 0x500988;
		newInstructionTable[PREPROCESS-0x105] = (int)preprocess;
		newInstructionTable[STARTVM-0x105] = (int)vmLoop;




		GLOBAL_opTable[JMP] = (int)OP_jmp;
		GLOBAL_opTable[JNE] = (int)OP_jne;
		GLOBAL_opTable[JE] = (int)OP_je;
		GLOBAL_opTable[JL] = (int)OP_jl;
		GLOBAL_opTable[JG] = (int)OP_jg;
		GLOBAL_opTable[COMPVARTOLONG] = (int)OP_compVarToLong;
		GLOBAL_opTable[COMPLONGVARS] = (int)OP_compLongVars;
		GLOBAL_opTable[SETVARTOLONG] = (int)OP_setVarToLong;
		GLOBAL_opTable[INCVARBYLONG] = (int)OP_incVarByLong;
		GLOBAL_opTable[INCVARBYLONGVAR] = (int)OP_incVarByLongVar;
		GLOBAL_opTable[SETVARTOLONGVAR] = (int)OP_setVarToLongVar;
		GLOBAL_opTable[SETVARTOFLOATVAR] = (int)OP_setVarToLongVar;
		GLOBAL_opTable[SETVARTOSTRINGVAR] = (int)OP_setVarToLongVar;
		GLOBAL_opTable[SETVARTOFLOAT] = (int)OP_setVarToFloat;
		GLOBAL_opTable[INCVARBYFLOAT] = (int)OP_incVarByFloat;
		GLOBAL_opTable[INCVARBYFLOATVAR] = (int)OP_incVarByFloatVar;
		GLOBAL_opTable[SETVARTOSTRING] = (int)OP_setVarToString;
		GLOBAL_opTable[COMPVARTOSTRING] = (int)OP_compVarToString;
		GLOBAL_opTable[SETVARTOLONGRESULT] = (int)OP_setVarToLongResult;
		GLOBAL_opTable[SETVARTOFLOATRESULT] = (int)OP_setVarToFloatResult;
		GLOBAL_opTable[SETVARTOSTRINGRESULT] = (int)OP_setVarToStringResult;
		GLOBAL_opTable[ADDFLOATVARS] = (int)OP_addFloatVars;
		GLOBAL_opTable[ADDLONGVARS] = (int)OP_addLongVars;
		GLOBAL_opTable[ADDVARTOLONG] = (int)OP_addVarToLong;
		GLOBAL_opTable[ADDVARTOFLOAT] = (int)OP_addVarToFloat;
		GLOBAL_opTable[MULVARTOLONG] = (int)OP_mulVarToLong;
		GLOBAL_opTable[MULVARTOFLOAT] = (int)OP_mulVarToFloat;
		GLOBAL_opTable[MULLONGVARS] = (int)OP_mulLongVars;
		GLOBAL_opTable[MULFLOATVARS] = (int)OP_mulFloatVars;


		GLOBAL_opTable[DISPLAYMESSAGE] = (int)FUNCTION_DisplayMessage;
		GLOBAL_opTable[GETBUTTONPRESSED] = (int)FUNCTION_GetButtonPressed;
		GLOBAL_opTable[GETTEXTINPUT] = (int)FUNCTION_GetTextInput;
		GLOBAL_opTable[SHOWINPUTBOX] = (int)FUNCTION_ShowInputBox;
		GLOBAL_opTable[GETPCSNEAKING] = (int)FUNCTION_GetPCSneaking;
		GLOBAL_opTable[SETBOOKMULTIPLIER] = (int)FUNCTION_SetBookMultiplier;
		GLOBAL_opTable[SETWEAPONMULTIPLIER] = (int)FUNCTION_SetWeaponMultiplier;
		GLOBAL_opTable[SETARMORMULTIPLIER] = (int)FUNCTION_SetArmorMultiplier;
		GLOBAL_opTable[SETINGREDIENTMULTIPLIER] = (int)FUNCTION_SetIngredientMultiplier;
		GLOBAL_opTable[SETMISCMULTIPLIER] = (int)FUNCTION_SetMiscMultiplier;
		GLOBAL_opTable[SETCLOTHINGMULTIPLIER] = (int)FUNCTION_SetClothingMultiplier;
		GLOBAL_opTable[GETTEMPLATE]    = (int)FUNCTION_GetTemplate;
		GLOBAL_opTable[CREATEWEAPON]   = (int)FUNCTION_CreateWeapon;
		GLOBAL_opTable[CREATEARMOR]   = (int)FUNCTION_CreateArmor;
		GLOBAL_opTable[CREATECLOTHING]   = (int)FUNCTION_CreateClothing;
		GLOBAL_opTable[CREATEBOOK]   = (int)FUNCTION_CreateBook;
		GLOBAL_opTable[ADDITEM]      = (int)FUNCTION_AddItem;
		GLOBAL_opTable[SETTEMPLATENAME] = (int)FUNCTION_SetTemplateName;
		GLOBAL_opTable[GETSCRIPT] = (int)FUNCTION_GetScript;
		GLOBAL_opTable[STARTSCRIPT] = (int)FUNCTION_StartScript;
		GLOBAL_opTable[STOPSCRIPT] = (int)FUNCTION_StopScript;
		GLOBAL_opTable[ISRUNNING] = (int)FUNCTION_IsRunning;
		GLOBAL_opTable[KEYPRESSED] = (int)FUNCTION_KeyPressed;
		GLOBAL_opTable[GETWEAPONMULTIPLIER] = (int)FUNCTION_GetWeaponMultiplier;
		GLOBAL_opTable[SETSLASHDAMAGE] = (int)FUNCTION_SetSlashDamage;
		GLOBAL_opTable[SETSLASHMIN] = (int)FUNCTION_SetSlashMin;
		GLOBAL_opTable[SETSLASHMAX] = (int)FUNCTION_SetSlashMax;
		GLOBAL_opTable[GETSLASHMIN] = (int)FUNCTION_GetSlashMin;
		GLOBAL_opTable[GETSLASHMAX] = (int)FUNCTION_GetSlashMax;



        //at address standardItemValueCall1, which is 0x5917a5, a call is made to a function
        //that gets the value of an item.  This changes the function that is called to the
        //value at address newCallAddress1, which is 0x736f8c.
		VirtualProtect(standardItemValueCall1,6,PAGE_EXECUTE_READWRITE,&dwOld);
		standardItemValueCall1[0] = (char)0xff;
		standardItemValueCall1[1] = (char)0x15;
		standardItemValueCall1[2] = (int)newCallAddress1 & 255;
		standardItemValueCall1[3] = (int)newCallAddress1>>8 & 255;
		standardItemValueCall1[4] = (int)newCallAddress1>>16 & 255;
		standardItemValueCall1[5] = (int)newCallAddress1>>24 & 255;

		
        //at address standardItemValueCall2, which is 0x5917ca, a call is made to a function
        //that gets the value of an item.  This changes the function that is called to the
        //value at address newCallAddress1, which is 0x736f8c.
        VirtualProtect(standardItemValueCall2,6,PAGE_EXECUTE_READWRITE,&dwOld);
		standardItemValueCall2[0] = (char)0xff;
		standardItemValueCall2[1] = (char)0x15;
		standardItemValueCall2[2] = (int)newCallAddress1 & 255;
		standardItemValueCall2[3] = (int)newCallAddress1>>8 & 255;
		standardItemValueCall2[4] = (int)newCallAddress1>>16 & 255;
		standardItemValueCall2[5] = (int)newCallAddress1>>24 & 255;
		



		//This holds the value of the function that is called at address standardItemValueCall1.
		//All this really does is change four bytes at address 0x736f8c.  It changes them to 
		//the address of the function getStandardItemValue

		VirtualProtect(newCallAddress1,4,PAGE_EXECUTE_READWRITE,&dwOld);
		newCallAddress1[0] = (int)getStandardItemValue & 255;
		newCallAddress1[1] = (int)getStandardItemValue>>8 & 255;
		newCallAddress1[2] = (int)getStandardItemValue>>16 & 255;
		newCallAddress1[3] = (int)getStandardItemValue>>24 & 255;



		//initialize the value multipliers to 1.0
        GLOBAL_clothingMultiplier = 1.0;
		GLOBAL_weaponMultiplier = 1.0;
		GLOBAL_armorMultiplier = 1.0;
		GLOBAL_bookMultiplier = 1.0;
		GLOBAL_miscMultiplier = 1.0;
		GLOBAL_ingredientMultiplier = 1.0;
		
		

	}

	if(fdwReason == DLL_PROCESS_DETACH)
	{

	}

	return 1;
}


//This is a preprocessor.  It runs one time for every script during the loading period of Morrowind
//Right now all this does is replace the first instruction, which is currently PREPROCESS, with STARTVM.
//I imagine that some pretty nifty stuff could be done here.
int __declspec(naked) preprocess()
{
	GLOBAL_morrowindIP = (int *)0x7CEBB0;
	_asm
	{
		mov eax,[ebx+0x58];
		mov GLOBAL_scriptCode,eax;
	}
	GLOBAL_scriptCode[0] = STARTVM;

	//Set this to a high value to let morrowind know that the preprocessing phase is over.  If this
	//is not set, then morrowind will try to perform preprocessing on every instruction in the script.
	*GLOBAL_morrowindIP = 1000000;


	//Morrowind expects the next instruction to be located in 7a91c4.  Put a zero there
	//to let it know no instruction was found (because all of them have already been executed)
	SET_RETURN_VALUE_TO_ZERO;

	//Clean the stack
	MAINLOOP_CLEANUP;




}



int getStandardItemValue()
{
	static int CLOT = 0x544F4C43;
	static int WEAP = 0x50414557;
	static int ARMO = 0x4F4D5241;
	static int BOOK = 0x4B4F4F42;
	static int MISC = 0x4353494D;
	static int INGR = 0x52474E49;

	int itemType;
	int itemValue;
	
	_asm
	{
		mov eax,[ecx+0x4];
		mov itemType,eax;
	}
	
	if(itemType == CLOT)
	{
     	_asm
		{
			xor eax,eax;
			mov ax,word ptr ds:[ecx+0xB0];
			mov itemValue,eax;
		}
		return (int)(itemValue*GLOBAL_clothingMultiplier);
 	}
	else if(itemType == WEAP)
	{
     	_asm
		{
			mov eax,[ecx+0x58];
			mov itemValue,eax;
		}
		return (int)(itemValue*GLOBAL_weaponMultiplier);
	}
	else if(itemType == ARMO)
	{
     	_asm
		{

			mov eax,[ecx+0xB0];
			mov itemValue,eax;
		}
		return (int)(itemValue*GLOBAL_armorMultiplier);
	}
	else if(itemType == BOOK)
	{
		_asm
		{
			mov eax,[ecx+0x58];
			mov itemValue,eax;
		}
		
		return (int)(itemValue*GLOBAL_bookMultiplier);
	}
	else if(itemType == MISC)
	{
		_asm
		{
			mov eax,[ecx+0x58];
			mov itemValue,eax;
		}
		
		return (int)(itemValue*GLOBAL_miscMultiplier);
	}
	else if(itemType == INGR)
	{
     	_asm
		{
			mov eax,[ecx+0xAC];
			mov itemValue,eax;
		}
		return (int)(itemValue*GLOBAL_ingredientMultiplier);
	}

	return 1;
}

 

//this isn't really a function, because Morrowind jumps here based on the 0x10E instruction.
//This is really the continuation of a function, so must return a value.  This is jumped to
//from the the "GetInstruction" function in Morrowind, located at 0x500510.  To let morrowind know that 
//there is no instruction to execute (because all of them are herein executed), put -1 in 0x7a91c4,
//which is the address that the instruction to be executed is located at.
int __declspec(naked) vmLoop()
{
	_asm
	{
		 //store the address of the code segment of the current script.
		mov eax,[ebx+0x58];
		mov GLOBAL_scriptCode,eax;

		mov eax,[ebx+0x34];
		mov GLOBAL_numLongVars,eax;

		mov eax,[ebx+0x38];
		mov GLOBAL_numFloatVars,eax;

		mov eax,[ebx+0x48];
		mov GLOBAL_longVarNames,eax;

		mov eax,[ebx+0x4c];
  		mov GLOBAL_floatVarNames,eax;

		mov eax,[ebx+0x60];
  		mov GLOBAL_longVarValues,eax;
  		
        mov eax,[ebx+0x64];
		mov GLOBAL_floatVarValues,eax;


		//store the length of the script in bytes
		mov eax,[ebx+0x3c];
		mov GLOBAL_maxIP,eax;

	}

	//The ip of the first actual code instruction is the parameter to the 0x10E instruction, which
	//is at location 4 of the script.
	GLOBAL_currentIP = 4;
	_asm
	{
		mov eax,GLOBAL_scriptCode;
		add eax,GLOBAL_currentIP;
		mov ebx,[eax];
		mov GLOBAL_currentIP, ebx;


	}


	//Run every instruction
	while(GLOBAL_currentIP < GLOBAL_maxIP)
	{

		nextDWORD(GLOBAL_nextInstruction);
		_asm
		{
			mov eax,GLOBAL_nextInstruction;
			call [eax*4+GLOBAL_opTable];
		}

	}

	//set the morrowind native VM IP to GLOBAL_currentIP
	*GLOBAL_morrowindIP = GLOBAL_currentIP;

	//reset the IP
	GLOBAL_currentIP = 0;






	//Morrowind expects the next instruction to be located in 7a91c4.  Put a zero there
	//to let it know no instruction was found (because all of them have already been executed)
	SET_RETURN_VALUE_TO_ZERO;

	//Clean the stack
	MAINLOOP_CLEANUP;


}





//The location to jump to is at GLOBAL_currentIP+4 (which contains the argument to the jmp op).
//Get that value, and store it in GLOBAL_currentIP.
int OP_jmp()
{
	int newAddress;
	nextDWORD(newAddress);
	GLOBAL_currentIP = newAddress;
	return 1;
}



int OP_setVarToString()
{
	
	int varAddress;
	int stringAddress; 
	
	nextDWORD(varAddress);
	nextDWORD(stringAddress);

	 _asm
	{

		//put the resolved variable address in eax
   		mov eax,varAddress;
		mov ecx,dword ptr ds:[GLOBAL_longVarValues];
		mov edx,4;
		mul edx;
		add ecx,eax;

		//put the resolved string address in ebx
		mov ebx,GLOBAL_scriptCode;
		add ebx,stringAddress;

		//put the resolved string address in the resolved variable address
		mov [ecx],ebx;
	}
}


int OP_compVarToString()
{
	int varAddress;
	int stringAddress;

	nextDWORD(varAddress);
	nextDWORD(stringAddress);


	//resolve the varAddress and the string address and then compare the strings
	_asm
	{
   		mov eax,varAddress;
		mov ecx,dword ptr ds:[GLOBAL_longVarValues];
		mov edx,4;
		mul edx;
		add ecx,eax;
		
		
		push dword ptr ds:[ecx];
  		mov ebx,GLOBAL_scriptCode;
		add ebx,stringAddress;
		push ebx;
		call stricmp;

		//put the eflags register in GLOBAL_compResult;
		pushfd
		pop ecx;
		mov GLOBAL_compResult,ecx;
	}

	return 1;

}


int OP_setVarToLongResult()
{
	int varAddress;
	nextDWORD(varAddress);
	GLOBAL_longVarValues[varAddress] = GLOBAL_result;
	return 1;
}


int OP_setVarToFloatResult()
{
	int varAddress;
	nextDWORD(varAddress);
	
	_asm
	{
		mov ecx,GLOBAL_floatVarValues;
		mov ebx,varAddress;
		mov eax,GLOBAL_result;
		mov [ecx+ebx*4],eax;
	}

	return 1;
}

int OP_setVarToStringResult()
{
	int varAddress;
	nextDWORD(varAddress);
	GLOBAL_longVarValues[varAddress] = GLOBAL_result;
	return 1;
}



int OP_setVarToLong()
{
	int varAddress;
	int longValue;

	nextDWORD(varAddress);
	nextDWORD(longValue);

	GLOBAL_longVarValues[varAddress] = longValue;

	return 1;
}


int OP_addVarToLong()
{
	int resultVarAddress;
	int varAddress;
	int longValue;

	nextDWORD(resultVarAddress);
	nextDWORD(varAddress);
	nextDWORD(longValue);

	GLOBAL_longVarValues[resultVarAddress] = GLOBAL_longVarValues[varAddress]+longValue;
	return 1;
}




int OP_addVarToFloat()
{
	int resultVarAddress;
	int varAddress;
	int floatValue;

	nextDWORD(resultVarAddress);
	nextDWORD(varAddress);
	nextDWORD(floatValue);
    GLOBAL_floatVarValues[resultVarAddress] = GLOBAL_floatVarValues[varAddress]+floatValue;
	return 1;
}


int OP_addFloatVars()
{
	int resultVarAddress;
	int varAddress1;
	int varAddress2;

	nextDWORD(resultVarAddress);
	nextDWORD(varAddress1);
	nextDWORD(varAddress2);

	GLOBAL_floatVarValues[resultVarAddress] = GLOBAL_floatVarValues[varAddress1] + GLOBAL_floatVarValues[varAddress2];

	return 1;
}




int OP_addLongVars()
{
	int resultVarAddress;
	int varAddress1;
	int varAddress2;

	nextDWORD(resultVarAddress);
	nextDWORD(varAddress1);
	nextDWORD(varAddress2);


   	GLOBAL_longVarValues[resultVarAddress] = GLOBAL_longVarValues[varAddress1] + GLOBAL_longVarValues[varAddress2];

	return 1;
}




int OP_mulVarToLong()
{
	int resultVarAddress;
	int varAddress;
	int longValue;

	nextDWORD(resultVarAddress);
	nextDWORD(varAddress);
	nextDWORD(longValue);

    GLOBAL_longVarValues[resultVarAddress] = GLOBAL_longVarValues[varAddress]*longValue;

	return 1;
}




int OP_mulVarToFloat()
{
	int resultVarAddress;
	int varAddress;
	int longValue;

	nextDWORD(resultVarAddress);
	nextDWORD(varAddress);
	nextDWORD(longValue);

    GLOBAL_floatVarValues[resultVarAddress] = GLOBAL_floatVarValues[varAddress]*longValue;


	return 1;
}


int OP_mulFloatVars()
{
	int resultVarAddress;
	int varAddress1;
	int varAddress2;

	nextDWORD(resultVarAddress);
	nextDWORD(varAddress1);
	nextDWORD(varAddress2);

   	GLOBAL_floatVarValues[resultVarAddress] = GLOBAL_floatVarValues[varAddress1] * GLOBAL_floatVarValues[varAddress2];


	return 1;
}




int OP_mulLongVars()
{
	int resultVarAddress;
	int varAddress1;
	int varAddress2;

	nextDWORD(resultVarAddress);
	nextDWORD(varAddress1);
	nextDWORD(varAddress2);

   	GLOBAL_longVarValues[resultVarAddress] = GLOBAL_longVarValues[varAddress1] * GLOBAL_longVarValues[varAddress2];


	return 1;
}















int OP_setVarToFloat()
{
	int varAddress;
	int floatValue;
	
	nextDWORD(varAddress);
	nextDWORD(floatValue);

	GLOBAL_floatVarValues[varAddress] = floatValue;

}





int OP_jne()
{
	int newAddress;
	nextDWORD(newAddress);
	_asm
	{
		//save the current eflags register
    	pushfd;

		//put the last cmp result in the eflags register
		push GLOBAL_compResult;
		popfd;

		//now, if eflags contains jne, then the GLOBAL_currentIP value should be updated so that the jump
		//is actually performed.
		jne DO_JNE;

		//Do this if jne is not true.
		popfd;
   		jmp DO_NOT_JNE;

		//perform the jump and restore eflags
		DO_JNE:
		mov eax,newAddress;
		mov GLOBAL_currentIP,eax;
		popfd;
 }
 DO_NOT_JNE:


 return 1;
}

int OP_je()
{
	int newAddress;
	nextDWORD(newAddress);

	_asm
	{
		//save the current eflags register
    	pushfd;

		//put the last cmp result in the eflags register
		push GLOBAL_compResult;
		popfd;

		//now, if eflags contains je, then the GLOBAL_currentIP value should be updated so that the jump
		//is actually performed.
		je DO_JE;

		//Do this if jne is not true.
		popfd;
   		jmp DO_NOT_JE;

		//perform the jump and restore eflags
		DO_JE:
		mov eax,newAddress;
		mov GLOBAL_currentIP,eax;
		popfd;
 }
 DO_NOT_JE:


 return 1;
}

int OP_jg()
{
	int newAddress;
	nextDWORD(newAddress);
	_asm
	{
		//save the current eflags register
    	pushfd;

		//put the last cmp result in the eflags register
		push GLOBAL_compResult;
		popfd;

		//now, if eflags contains je, then the GLOBAL_currentIP value should be updated so that the jump
		//is actually performed.
		jg DO_JG;

		//Do this if jne is not true.
		popfd;
   		jmp DO_NOT_JG;

		//perform the jump and restore eflags
		DO_JG:
		mov eax,newAddress;
		mov GLOBAL_currentIP,eax;
		popfd;
 }
 DO_NOT_JG:


 return 1;
}

int OP_jl()
{
	int newAddress;
	nextDWORD(newAddress);
	_asm
	{
		//save the current eflags register
    	pushfd;

		//put the last cmp result in the eflags register
		push GLOBAL_compResult;
		popfd;

		//now, if eflags contains je, then the GLOBAL_currentIP value should be updated so that the jump
		//is actually performed.
		jl DO_JL;

		//Do this if jne is not true.
		popfd;
   		jmp DO_NOT_JL;

		//perform the jump and restore eflags
		DO_JL:
		mov eax,newAddress;
		mov GLOBAL_currentIP,eax;
		popfd;
 	}
	 DO_NOT_JL:


 return 1;
}

int OP_jle()
{
	int newAddress;
	nextDWORD(newAddress);
	_asm
	{
		//save the current eflags register
    	pushfd;

		//put the last cmp result in the eflags register
		push GLOBAL_compResult;
		popfd;

		//now, if eflags contains je, then the GLOBAL_currentIP value should be updated so that the jump
		//is actually performed.
		jle DO_JLE;

		//Do this if jne is not true.
		popfd;
   		jmp DO_NOT_JLE;

		//perform the jump and restore eflags
		DO_JLE:
		mov eax,newAddress;
		mov GLOBAL_currentIP,eax;
		popfd;
 }
 DO_NOT_JLE:


 return 1;
}

int OP_jge()
{
	int newAddress;
	nextDWORD(newAddress);
	_asm
	{
		//save the current eflags register
    	pushfd;

		//put the last cmp result in the eflags register
		push GLOBAL_compResult;
		popfd;

		//now, if eflags contains je, then the GLOBAL_currentIP value should be updated so that the jump
		//is actually performed.
		jge DO_JGE;

		//Do this if jne is not true.
		popfd;
   		jmp DO_NOT_JGE;

		//perform the jump and restore eflags
		DO_JGE:
		mov eax,newAddress;
		mov GLOBAL_currentIP,eax;
		popfd;
 }
 DO_NOT_JGE:


 return 1;
}




int OP_compVarToLong()
{
	int varAddress;
	int longParam;
    nextDWORD(varAddress);
    nextDWORD(longParam);


	//Get the value of the first parameter, which is a variable.  Then compare the two parameters.
	_asm
	{
		//put param1 in edx
		mov ebx,GLOBAL_longVarValues;
		mov eax,varAddress;
		mov edx,4;
		mul edx;
		add ebx,eax;
		mov edx,dword ptr ds:[ebx];

 		//put param2 in ecx
		mov ecx,longParam;


		//compare the values and store the result in GLOBAL_compResult;
		cmp edx,ecx
		pushfd;
		pop eax;
		mov GLOBAL_compResult,eax;
	}

	return 1;
}


int OP_incVarByLong()
{
	int varAddress;
	int longValue;
    nextDWORD(varAddress);
    nextDWORD(longValue);
	
	GLOBAL_longVarValues[varAddress] = GLOBAL_longVarValues[varAddress]+longValue;

	return 1;
}

int OP_incVarByFloat()
{
	int varAddress;
	float floatValue;
    nextDWORD(varAddress);
    nextDWORD(floatValue);

    GLOBAL_floatVarValues[varAddress] = GLOBAL_floatVarValues[varAddress]+floatValue;
}


int OP_incVarByFloatVar()
{
	int varAddress1;
	int varAddress2;
    nextDWORD(varAddress1);
    nextDWORD(varAddress2);
	
	GLOBAL_floatVarValues[varAddress1]+=GLOBAL_floatVarValues[varAddress2];

	return 1;
}
 



int OP_incVarByLongVar()
{
	int varAddress1;
	int varAddress2;
    nextDWORD(varAddress1);
    nextDWORD(varAddress2);

   	GLOBAL_longVarValues[varAddress1]+=GLOBAL_longVarValues[varAddress2];

	return 1;
}


int OP_setVarToLongVar()
{
	int varAddress1;
	int varAddress2;
    nextDWORD(varAddress1);
    nextDWORD(varAddress2);

    GLOBAL_longVarValues[varAddress1] = GLOBAL_longVarValues[varAddress2];


 	return 1;
}

int OP_setVarToFloatVar()
{
	int varAddress1;
	int varAddress2;
    nextDWORD(varAddress1);
    nextDWORD(varAddress2);

    GLOBAL_floatVarValues[varAddress1] = GLOBAL_floatVarValues[varAddress2];


 	return 1;
}


int OP_setVarToStringVar()
{
	int varAddress1;
	int varAddress2;
    nextDWORD(varAddress1);
    nextDWORD(varAddress2);

    GLOBAL_longVarValues[varAddress1] = GLOBAL_longVarValues[varAddress2];


 	return 1;
}




int OP_compLongVars()
{
	int varAddress1;
	int varAddress2;
    nextDWORD(varAddress1);
    nextDWORD(varAddress2);
	
	
	//Get the value of the first parameter, which is a variable.
	_asm
	{
		//put param1 in ebx
		mov eax,GLOBAL_longVarValues;
		add eax,varAddress1;
		mov ebx,dword ptr ds:[eax];

		
		//put param2 in ecx
		mov eax,GLOBAL_longVarValues;
		add eax,varAddress2;
		mov ecx,dword ptr ds:[eax];

		//compare the values and store the result in GLOBAL_compResult;
		cmp ebx,ecx
		pushfd;
		pop eax;
		mov GLOBAL_compResult,eax;
	}

	return 1;
}



char *getStringParameter()
{
	char *param;

	_asm
	{
		mov eax,GLOBAL_scriptCode;
		mov ebx,GLOBAL_currentIP;

		//ecx contains the parameter's type
		mov ecx,[eax+ebx];


		//edx contains the parameter
		mov edx,[eax+ebx+4];


		cmp ecx,0;
		je ISVALUE;

		//If ecx == 1, then the parameter is a variable, and the value of the variable must be retrieved.
		mov ebx,GLOBAL_longVarValues;
		mov eax,4;
		mul edx;
		add ebx,eax;
		mov edx,[ebx];
		jmp done;

		//If ecx == 0, then the parameter is the address of a string, and not the address of a
		//variable
		ISVALUE:
		add eax,edx;
		mov edx,eax;

		done:
		mov param,edx;

	}

	GLOBAL_currentIP+=8;

	return param;

}

int getLongParameter()
{
	int param;

	_asm
	{
		mov eax,GLOBAL_scriptCode;
		mov ebx,GLOBAL_currentIP;

		//ecx contains the parameter's type
		mov ecx,[eax+ebx];


		//edx contains the parameter
		mov edx,[eax+ebx+4];


		cmp ecx,0;
		je ISVALUE;

		//If ecx == 1, then the parameter is a variable, and the value of the variable must be retrieved.
		mov ebx,GLOBAL_longVarValues;
		mov eax,4;
		mul edx;
		add ebx,eax;
		mov edx,[ebx];

        //If ecx == 0, then the parameter is a value
		ISVALUE:
		mov param,edx;
	}

	GLOBAL_currentIP+=8;

	return param;

}

float getFloatParameter()
{
	float param;

	_asm
	{
		mov eax,GLOBAL_scriptCode;
		mov ebx,GLOBAL_currentIP;

		//ecx contains the parameter's type
		mov ecx,[eax+ebx];


		//edx contains the parameter
		mov edx,[eax+ebx+4];


		cmp ecx,0;
		je ISVALUE;

		//If ecx == 1, then the parameter is a variable, and the value of the variable must be retrieved.
		mov ebx,GLOBAL_floatVarValues;
		mov eax,4;
		mul edx;
		add ebx,eax;
		mov edx,[ebx];

		//If ecx == 0, then the parameter is a value
		ISVALUE:
		mov param,edx;
	}

	GLOBAL_currentIP+=8;

	return param;

}



