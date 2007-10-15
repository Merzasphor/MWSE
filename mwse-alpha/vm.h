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

#ifndef VM_H

#define VM_H

#define nextDWORD(var) _asm mov ecx,GLOBAL_currentIP _asm mov ebx,GLOBAL_scriptCode _asm mov eax,dword ptr ds:[ebx+ecx] _asm mov var,eax _asm add GLOBAL_currentIP,4

#define setResult(x) _asm mov eax,x _asm mov GLOBAL_result,eax

//Assembler macros

#define SET_RETURN_VALUE_TO_ZERO _asm mov eax,0x7a91c4 _asm	mov ebx,0x0 _asm mov [eax],ebx

//MAINLOOP_CLEANUP clears the stack and jmps back to the next instruction in GetInstruction.
//A bunch of items are on the stack.  I didn't put them there.
//They are put there by morrowind in before and during the GetInstruction function.  From the
//GetInstruction function (a native morrowind function not in this file) jumps to vmLoop.  It
//also jumps to other functions, depending on the instruction that is recieved.  When the instruction
//0x10E is recieved, it jumps to vmLoop, though. Mmm k?  So every function that GetInstruction jumps to,
//whether it be one of those other ones, or vmLoop, must clear the stack of values.
//Now, that extra pop ecx, add esp,4, jmp ecx is something unique to this function.  Needs to be
//there to prevent a crash.  Walk through the code using Ollydbg to find out why.
#define MAINLOOP_CLEANUP 		_asm pop edi _asm pop esi _asm pop ebp _asm pop ebx _asm add esp,0x24 _asm pop ecx _asm add esp,4 _asm jmp ecx


#define PREPROCESS 0x10E
#define STARTVM   0x10F

#define JMP   0x100
#define JNE   0x101 
#define JE   0x102
#define JG   0x103 
#define JL   0x104 
#define SETVARTOLONG   0x105 
#define SETVARTOFLOAT   0x106 
#define SETVARTOSTRING   0x107 
#define SETVARTOLONGVAR   0x108
#define SETVARTOFLOATVAR   0x109 
#define SETVARTOSTRINGVAR   0x10A 

#define COMPLONGVARS   0x10B
#define COMPFLOATVARS   0x10C
#define COMPSTRINGVARS   0x10D
#define COMPVARTOFLOAT   0x10E
#define COMPVARTOSTRING   0x10F
#define COMPVARTOLONG   0x110
#define ADDVARTOLONG   0x111
#define ADDVARTOFLOAT   0x112
#define ADDFLOATVARS   0x113
#define ADDLONGVARS   0x114
#define MULVARTOLONG   0x115
#define MULVARTOFLOAT   0x116
#define MULFLOATVARS   0x117
#define MULLONGVARS   0x118

#define INCVARBYLONG   0x11A
#define INCVARBYFLOAT   0x11B
#define INCVARBYFLOATVAR   0x11C
#define INCVARBYLONGVAR   0x11D
#define SETVARTOLONGRESULT   0x119
#define SETVARTOFLOATRESULT 0x11E
#define SETVARTOSTRINGRESULT  0x11F



//Function opcodes
#define DISPLAYMESSAGE   0x200
#define GETTEMPLATE       0x201
#define CREATEWEAPON      0x202
#define GETBUTTONPRESSED 0x203
#define GETTEXTINPUT     0x204
#define SHOWINPUTBOX     0x205
#define GETPCSNEAKING    0x206
#define ADDITEM          0x207
#define SETBOOKMULTIPLIER  0x208
#define SETARMORMULTIPLIER  0x209
#define SETWEAPONMULTIPLIER  0x20A
#define SETCLOTHINGMULTIPLIER  0x20B
#define SETINGREDIENTMULTIPLIER  0x20C
#define SETMISCMULTIPLIER  0x20D
#define CREATEARMOR 0x20E
#define CREATEBOOK 0x20F
#define CREATECLOTHING 0x210
#define SETTEMPLATENAME 0x211
#define GETSCRIPT       0x212
#define ISRUNNING  0x213
#define STARTSCRIPT  0x214
#define STOPSCRIPT  0x215
#define KEYPRESSED 0x216
#define ENTERMENUMODE 0x217
#define LEAVEMENUMODE 0x218
#define SETSLASHDAMAGE 0x219
#define SETSLASHMIN 0x21A
#define SETSLASHMAX 0x21B
#define GETSLASHMIN 0x21C
#define GETSLASHMAX 0x21D
#define GETWEAPONMULTIPLIER 0x21E

//Global variables
int GLOBAL_maxIP;
int GLOBAL_numLongVars;
int GLOBAL_numFloatVars;
int GLOBAL_currentIP;
int GLOBAL_nextDWORD;
int GLOBAL_compResult;
int GLOBAL_nextInstruction;
float GLOBAL_clothingMultiplier;
float GLOBAL_weaponMultiplier;
float GLOBAL_armorMultiplier;
float GLOBAL_bookMultiplier;
float GLOBAL_miscMultiplier;
float GLOBAL_ingredientMultiplier;

//all function results are placed here.
int GLOBAL_result;
int *GLOBAL_morrowindIP;

//contains the pointer to the code segment of the current script.  call update() at the start of every OP or FUNCTION
//to set GLOBAL_scriptCode to the current script.
int *GLOBAL_scriptCode;

int GLOBAL_opTable[0x400];



char *GLOBAL_longVarNames[1024];
char *GLOBAL_floatVarNames[1024];
long *GLOBAL_longVarValues;
float *GLOBAL_floatVarValues;


//Functions
int FUNCTION_DisplayMessage();
int FUNCTION_GetTemplate();
int FUNCTION_CreateWeapon();
int FUNCTION_CreateArmor();
int FUNCTION_CreateClothing();
int FUNCTION_CreateBook();
int FUNCTION_GetButtonPressed();
int FUNCTION_GetTextInput();
int FUNCTION_ShowInputBox();
int FUNCTION_AddItem();
int FUNCTION_GetPCSneaking();
int FUNCTION_SetBookMultiplier();
int FUNCTION_SetArmorMultiplier();
int FUNCTION_SetWeaponMultiplier();
int FUNCTION_SetClothingMultiplier();
int FUNCTION_SetIngredientMultiplier();
int FUNCTION_SetMiscMultiplier();
int FUNCTION_SetTemplateName();
int FUNCTION_GetScript();
int FUNCTION_StartScript();
int FUNCTION_StopScript();
int FUNCTION_IsRunning();
int FUNCTION_KeyPressed();
int FUNCTION_GetWeaponMultiplier();
int FUNCTION_EnterMenuMode();
int FUNCTION_LeaveMenuMode();
int FUNCTION_SetSlashDamage();
int FUNCTION_SetSlashMin();
int FUNCTION_SetSlashMax();
int FUNCTION_GetSlashMin();
int FUNCTION_GetSlashMax();




//OPS and helper functions
int getTemplate(char *id);
int getItemValue();
int OP_jmp();
int OP_jne();
int OP_je();
int OP_jg();
int OP_jl();
int OP_jle();
int OP_jge();
int OP_setVarToLong();
int OP_setVarToFloat();
int OP_compVarToLong();
int OP_compLongVars();
int OP_incVarByLong();
int OP_addLongVars();
int OP_addFloatVars();
int OP_mulFloatVars();
int OP_mulLongVars();
int OP_addVarToLong();
int OP_addVarToFloat();
int OP_mulVarToLong();
int OP_mulVarToFloat();

int OP_incVarByLongVar();
int OP_incVarByFloat();
int OP_incVarByFloatVar();
int OP_setVarToLongVar();
int OP_setVarToFloatVar();
int OP_setVarToStringVar();
int OP_setVarToString();
int OP_compVarToString();
int OP_setVarToLongResult();
int OP_setVarToFloatResult();
int OP_setVarToStringResult();
int getLongParameter();
float getFloatParameter();
char *getStringParameter();
int preprocess();
int vmLoop();
int getNextDWORD();
int getStandardItemValue();
int handleOpcode();


typedef struct
{
	int  vtable;			//pointer to object handling functions
	int recordType;
	int recordSize;
	char *modNamePtr;
	char scriptName[32];
	int numShorts;
	int numLongs;
	int numFloats;
	int scriptDataSize;
	int localVarSize;     //the length of the local var names concatenated (includes \0 for string endings)
	char **shortVarNamePointers;    
	char **longVarNamePointers;
	char **floatVarNamePointers;
	char *varNamePointers;
	int unknownData;	    //equals 0
	int machineCode;	//pointer to the script object executed by the game.  Since I'm not accessing it, I'll just put an int here to take up 4 bytes of space.
	short *shortVarValues;  //pointer to array of shorts, each associated with its corresponding variable
	long *longVarValues;
	float *floatVarValues;
}SCPTRECORD;




//there is an address in memory that in turn holds a reference to a linked list of SCPTNODES.
//Traversinig this list allows one to access all scripts in memory.
//This address is found by the initRootScriptNode function
typedef struct
{
	int unknown;
	SCPTRECORD *scptRecord;
}SCPTNODE;


//Each container has two linked-list pointers: one with the first data node pointing to the first
//item, and one with the first data node pointing to the last item.
typedef struct
{
	int itemCount;
	int *recordAddress;
}INVENTORYNODE;



//The game uses some linked lists.
typedef struct
{
	struct LINKEDLIST *prevNode;
	struct LINKEDLIST *nextNode;
	int *dataNode;
}LINKEDLIST;


//Structures that replicate those found in memory.
typedef struct
{
	int  vtable;			//pointer to object handling functions
	int recordType;
 	int recordSize;
	char *modNamePtr;
}NPCBASERECORD;


typedef struct
{
	int vtable;
	int recordType;
	int recordSize;
	char *modNamePtr;
	int unknown1;
	int unknown2;
	int unknown3;
	int *prevRecord;
	int *nextRecord;
	int *unknown4;
	int unknown5;
	char *IDStringPtr;
	int *unknownFunctionPtr;
	int unknown6;
	int unknown7;
	int unknown8;
	int unknown9;
	char *nameStringPtr;
	int unknown;
	char *nifStringPtr;
	char *tgaStringPtr;
	float weight; //ver
	int   value;  //ver
	short weaponType;   //ver
	short maxCondition; //ver
 	float speed;  //ver
	float reach;  //ver
	short enchantPoints;
	char chopMin;
	char chopMax;
	char slashMin;
	char slashMax;
	char thrustMin;
	char thrustMax;
	short flags;
}WEAPRECORD;



typedef struct
{
	int  vtable;			//pointer to object handling functions
	int recordType;
 	int unknown1;
	int unknown2;
	int unknown3;
	int unknown4;
	int *reference;
	int *prevRecord;
	int *nextRecord;
	int unknown5;
	int unknown6;
	char *IDStringPtr;
 	int unknown7;
	int unknown8;
	int unknown9;
	int unknown10;
	int unknown11;
	int unknown12;
	LINKEDLIST *inventoryStart;
	LINKEDLIST *inventoryEnd;
}NPCCOPYRECORD;







typedef struct
{
	int  vtable;			//pointer to object handling functions
	int recordType;
 	int recordSize;
	char *modNamePtr;
	int unknown1;
	int unknown2;
	int unknown3;
	struct REFRRECORD *prevREFRRECORD;
	struct REFRRECORD *nextREFRRECORD;
	int unknown4;
	int *recordPointer;  //points to the record for which this is a reference
}REFRRECORD;




#endif