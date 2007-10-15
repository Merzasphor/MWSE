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


#include "vm.h"
#include "gui.h"





int FUNCTION_ShowInputBox()
{

	char* dialogTitle;
	char* buttonText;
	dialogTitle = getStringParameter();
	buttonText = getStringParameter();
	newInputDialog(dialogTitle,buttonText);
	setResult(1);

	return 1;

}


int FUNCTION_GetButtonPressed()
{
	_asm
	{
    	mov eax,dword ptr ds:[0x7b88c0];
		mov GLOBAL_result,eax;
	}
	return 1;
}


int FUNCTION_GetPCSneaking()
{
	int isSneaking;
	static int getPCStruct = 0x0040ff20;
	_asm
	{
		mov ecx,dword ptr ds:[0x7c67dc];
		call getPCStruct;
		xor ebx,ebx;
		mov bx,[eax+0x8];
		shr ebx,0x0A;
		mov isSneaking,ebx;
	}
	setResult(isSneaking);
	return 1;
}





int FUNCTION_GetPCJumping()
{
	int isJumping;
	static int getPCStruct = 0x0040ff20;
	_asm
	{
		mov ecx,dword ptr ds:[0x7c67dc];
		call getPCStruct;
		xor ebx,ebx;
		mov bx,[eax+0x8];
		shr ebx,0x0C;
		mov isJumping,ebx;
	}
	setResult(isJumping);

	return 1;
}



int FUNCTION_GetPCRunning()
{
	int isRunning;
	static int getPCStruct = 0x0040ff20;
	_asm
	{
		mov ecx,dword ptr ds:[0x7c67dc];
		call getPCStruct;
		xor ebx,ebx;
		mov bx,[eax+0x8];
		shr ebx,0x09;
		mov isRunning,ebx;
	}
	setResult(isRunning);
	return 1;
}



int FUNCTION_SetTemplateName()
{
	WEAPRECORD *weaponRecord;
	char *templateName;

	weaponRecord = (WEAPRECORD *)getLongParameter();
	templateName = getStringParameter();


	if(weaponRecord == 0)
	{
		setResult(0);
		return 1;
	}

	else
	{
		weaponRecord->nameStringPtr = templateName;
		setResult(1);
		return 1;
	}
}

int FUNCTION_GetWeaponMultiplier()
{
	setResult(GLOBAL_weaponMultiplier);
	return 1;
} 



int FUNCTION_KeyPressed()
{
	static char *keymap;
	char testKey;
	char keyValue;

	_asm
	{
		mov eax,dword ptr ds:[0x7c67dc];
		mov ebx,dword ptr ds:[eax+0x4c];
		add ebx,0x18f4;
		mov ecx,ebx;
		mov keymap,ecx;
	}

	testKey = (char)getLongParameter();

	if(testKey > 223 || testKey < 0)
	{
		setResult(0);
		return 1;
	}
	else
	{
		keyValue = keymap[testKey];
		if(keyValue == (char)0x80)
		{
			setResult(1);
			return 1;
		}
		else
		{
			setResult(0);
			return 1;
		}
	}

	return 1;
}


int FUNCTION_GetTextInput()
{
	_asm
	{
		mov eax,GLOBAL_inputText;
		mov GLOBAL_result,eax;
	}
	return 1;
}




//7ce6f8 holds template of item to add
//7cebb4 holds number of items to add
//7cebec holds reference of npc
//7cebf4 holds template of npc
int FUNCTION_AddItem()
{

	int npcTemplate;
	int itemTemplate;
	int itemCount;
	int totalCount;
	static int addItem = 0x4957F0;
	static int getMACP = 0x40ff20;
	static int getPCREFR = 0x467350;
	static int runFunction = 0x505770;


	//the first paramter is the address of some container template
	npcTemplate = getLongParameter();
	
	//the next parameter is the address of some item template
	itemTemplate = getLongParameter();


	//the next paramter is the number of items to add
	itemCount = getLongParameter();

    if(itemTemplate == -1)
	{
		setResult(0);
    }
    else
	{
     	_asm
		{

			//This block of code gets the reference of the player character.
			mov ecx,dword ptr ds:[0x7c67dc];
			call getMACP;
			mov ecx,eax;
			call getPCREFR;

			//Put the reference associated with the template in ebx.
			//and check to see if that reference is equal to eax, which holds the Player Character
			//reference from the getPCREFR call.
            mov ebx,npcTemplate;
			mov ebx,[ebx+0x18];
			cmp eax,ebx;
			jne notPC;

			//Run this if the npcTemplate is the Player Character template.
			//put the reference in 0x7cebf4
			mov dword ptr ds:[0x7cebec],ebx;

			//put the template in 0x7cebf4
			mov eax,npcTemplate;
			mov dword ptr ds:[0x7cebf4],eax;

			//put the item's template address in 0x7ce6f8
			mov eax,itemTemplate;
			mov dword ptr ds:[0x7ce6f8],eax;

			//put the item count in 0x7cebb4;
			mov eax,itemCount;
			mov dword ptr ds:[0x7cebb4],eax;

			//call runFunction with opcode 10D4 (addItem)
			push 1;
			push 0;
			push 0x10D4;
			call runFunction;
			mov totalCount,eax;
			jmp done;


			//run this if the npcTemplate is NOT the Player Character template
			notPC:
			mov esi,itemTemplate;
			mov ecx,npcTemplate;
			push 0;
			push itemCount;
			push itemTemplate;
			call addItem;
			mov totalCount,eax;


		   done:




		  }
	}
	setResult(totalCount);

	return 1;

}


int FUNCTION_DisplayMessage()
{
	static int displayMessage = 0x5f90c0;

   	char *message = getStringParameter();

	_asm
	{
    	push 1;
    	push 0;
    	push message;
    	call displayMessage;
	}
}






int FUNCTION_CreateWeapon()
{
	static int CLOT = 0x544F4C43;
	static int WEAP = 0x50414557;
	static int ARMO = 0x4F4D5241;
	static int BOOK = 0x4B4F4F42;
	
	int objectType;
	WEAPRECORD *oldObject;
	WEAPRECORD *newObject;

	oldObject = (WEAPRECORD *)getLongParameter();

	if((int)oldObject == -1)
	{
		setResult(0);
		return 1;
	}
	
	objectType = oldObject->recordType;
	
	if(objectType == WEAP)
	{

		_asm
		{
			mov ecx,oldObject;
			push 0x78;
			mov ebx,0x00727692;
			call ebx;
			add esp,0x4
			mov newObject,eax


			//initializeWeaponRecord(newWeaponAddress);
			mov ecx,newObject;
			mov ebx,0x004f1ee0;
			call ebx; 
		
		
			//copy data from the address that holds the old weapon to the 
			//address that holds the new weapon.  
			//Specifically, copy the old weapon id, the old weapon name, and the old
			//weapon stats

			push 1;
			push oldObject;
			mov ecx,newObject;
			mov ebx,0x004f2600;
			call ebx;
	           



			//remove the weaponID pointer 
			push 0x007c6180;
			mov ecx,newObject;
			mov ebx,0x004ef880;
			call ebx;



			//add a pointer to some data...still figuring it out
			//add some other data
			//add new weapon id
			mov edx,dword ptr ds:[0x7c67e0];
			mov ecx,dword ptr ds:[edx];
			push newObject;
			mov ebx,0x004b8980;
			call ebx;	
		}
	}
	
	else
	{
		setResult(0);
		return 1;
	}
	

	//push a reference to the new template
	setResult(newObject);
	return 1;


}


int FUNCTION_CreateClothing()
{
	static int CLOT = 0x544F4C43;
	static int WEAP = 0x50414557;
	static int ARMO = 0x4F4D5241;
	static int BOOK = 0x4B4F4F42;
	
	int objectType;
	WEAPRECORD *oldObject;
	WEAPRECORD *newObject;

	oldObject = (WEAPRECORD *)getLongParameter();
	
	if((int)oldObject == -1)
	{
		setResult(-1);
		return 1;
	}
	
	objectType = oldObject->recordType;
	
	if(objectType == CLOT)
	{

		_asm
		{

			mov ecx,oldObject
			push 0xb8;
			mov ebx,0x00727692;
			call ebx;
			add esp,0x4;
			mov newObject,eax;
		

			mov ecx,newObject;
			mov ebx,0x004a2c70;
			call ebx;


			push 1;
			push oldObject;
			mov ecx,newObject;
			mov ebx,0x004a3590;
			call ebx;


			//remove the weaponID pointer 
			push 0x007c6180;
			mov ecx,newObject;
			mov ebx,0x004ef880;
			call ebx;


			mov edx,dword ptr ds:[0x7c67e0];
			mov ecx,dword ptr ds:[edx];
			push newObject;
			mov ebx,0x004b8980;
			call ebx;
		}
	}

	
	else
	{
		setResult(0);
		return 1;
	}
	

	//push a reference to the new template
	setResult(newObject);
	return 1;
}




int FUNCTION_CreateArmor()
{
	static int CLOT = 0x544F4C43;
	static int WEAP = 0x50414557;
	static int ARMO = 0x4F4D5241;
	static int BOOK = 0x4B4F4F42;
	
	int objectType;
	WEAPRECORD *oldObject;
	WEAPRECORD *newObject;

	oldObject = (WEAPRECORD *)getLongParameter();
	
	if((int)oldObject == -1)
	{
		setResult(0);
		return 1;
	}
	
	objectType = oldObject->recordType;
	
	if(objectType == ARMO)
	{
		_asm
		{
			mov ecx,oldObject;
			push 0xc4;
			mov ebx,0x00727692;
			call ebx;
			add esp,0x4;
			mov newObject,eax;
		

			mov ecx,newObject;
			mov ebx,0x4a0360;
			call ebx;


			push 1;
			push oldObject;
			mov ecx,newObject;
			mov ebx,0x4a0bf0;
			call ebx;


			push 0x007c6180;
			mov ecx,newObject;
			mov ebx,0x004ef880;
			call ebx;


			mov edx,dword ptr ds:[0x7c67e0];
			mov ecx,dword ptr ds:[edx];
			push newObject;
			mov ebx,0x004b8980;
			call ebx;
		}
	}

	
	else
	{
		setResult(0);
		return 1;
	}
	

	//push a reference to the new template
	setResult(newObject);
	return 1;
}





int FUNCTION_CreateBook()
{
	static int CLOT = 0x544F4C43;
	static int WEAP = 0x50414557;
	static int ARMO = 0x4F4D5241;
	static int BOOK = 0x4B4F4F42;
	
	int objectType;
	WEAPRECORD *oldObject;
	WEAPRECORD *newObject;

	oldObject = (WEAPRECORD *)getLongParameter();
	
	if((int)oldObject == -1)
	{
		setResult(0);
		return 1;
	}
	
	objectType = oldObject->recordType;
	
	if(objectType == BOOK)
	{
		_asm
		{
			mov ecx, oldObject;            
			push 0x70;
			mov ebx,0x00727692;
			call ebx;
			add esp,0x4;
			mov newObject,eax;
		

			mov ecx,newObject;
			mov ebx, 0x004a1e90;
			call ebx;


			push 1;
			push oldObject;
			mov ecx,newObject;
			mov ebx,0x004a24e0;
			call ebx;



			push 0x007c6180;
			mov ecx,newObject;
			mov ebx,0x004ef880;
			call ebx;



			mov edx,dword ptr ds:[0x7c67e0];
			mov ecx,dword ptr ds:[edx];
			push newObject;
			mov ebx,0x004b8980;
			call ebx;

		}
	}

	
	else
	{
		setResult(0);
		return 1;
	}
	

	//push a reference to the new template
	setResult(newObject);
	return 1;
}









int FUNCTION_GetTemplate()
{
	char *itemString = getStringParameter();
	int itemTemplateAddress;

	itemTemplateAddress = getTemplate(itemString);

	if(itemTemplateAddress == 0)
	{
		setResult(0);
	}
	else
	{
		setResult(itemTemplateAddress);
	}
}





int FUNCTION_SetBookMultiplier()
{
	GLOBAL_bookMultiplier = getFloatParameter();
	setResult(1);
}
int FUNCTION_SetArmorMultiplier()
{
	GLOBAL_armorMultiplier = getFloatParameter();

	setResult(1);
}

int FUNCTION_SetWeaponMultiplier()
{
	float floatInput = getFloatParameter();
	if(floatInput <= 1.0)
	{
		floatInput = 1.0;
	}
	GLOBAL_weaponMultiplier = floatInput;
	setResult(1);
}

int FUNCTION_SetClothingMultiplier()
{
	GLOBAL_clothingMultiplier = getFloatParameter();
	setResult(1);
}

int FUNCTION_SetIngredientMultiplier()
{
	GLOBAL_ingredientMultiplier = getFloatParameter();
	setResult(1);
}

int FUNCTION_SetMiscMultiplier()
{
	GLOBAL_miscMultiplier = getFloatParameter();
	setResult(1);
}




int FUNCTION_GetScript()
{
	char *scriptName = getStringParameter();
	static int getScriptAddress = 0x4ba700;

	int scriptAddress;

	_asm
	{
		mov edx,dword ptr ds:[0x7c67e0];
		mov ecx,[edx];
		push scriptName;
		call getScriptAddress;
		mov scriptAddress,eax;
	}
	setResult(scriptAddress);
	return 1;
}

int FUNCTION_StartScript()
{
	SCPTRECORD *script = (SCPTRECORD *)getLongParameter();
	int resetVars = getLongParameter();
	static int startScript = 0x40fa80;
	int index = 0;

	if(script == 0)
	{
		setResult(0);
		return 1;
	}
	if(resetVars == 1)
	{
		for(index = 0; index < script->numShorts; index++)
		{
			script->shortVarValues[index] = 0;
		}
		for(index = 0; index < script->numLongs; index++)
		{
			script->longVarValues[index] = 0;
		}
		for(index = 0; index < script->numFloats; index++)
		{
			script->floatVarValues[index] = 0;
		}
	}

	_asm
	{
		push script;
		mov ecx,dword ptr ds:[0x7c67dc];
		call startScript;
		mov GLOBAL_result,eax;
	}
	setResult(1);
	return 1;
}

int FUNCTION_StopScript()
{
	SCPTRECORD *script = (SCPTRECORD *)getLongParameter();
	int resetVars = getLongParameter();
	static int stopScript = 0x40fb00;
	int index = 0;


	if(script == 0)
	{
		setResult(0);
		return 1;
	}
    
	if(resetVars == 1)
	{
		for(index = 0; index < script->numShorts; index++)
		{
			script->shortVarValues[index] = 0;
		}
		for(index = 0; index < script->numLongs; index++)
		{
			script->longVarValues[index] = 0;
		}
		for(index = 0; index < script->numFloats; index++)
		{
			script->floatVarValues[index] = 0;
		}
	}
	
	_asm
	{
		push script;
		mov ecx,dword ptr ds:[0x7c67dc];
		call stopScript;
		mov GLOBAL_result,eax;
	}
	setResult(1);

	return 1;
}



int FUNCTION_IsRunning()
{

	int scriptAddress = getLongParameter();

 	_asm
	{
		
		//put the root of the script linked list of running scripts in esi;
		mov edi,dword ptr ds:[0x7c67DC]
		mov ecx,[edi+0x338];
       	mov esi,[ecx+0x8];

		//put ScriptNode in ebx;
		nextNode:
		mov ebx,[esi+0x8];

		//put the script address that was found in the ScriptNode in ecx, and compare it to scriptAddress;
		mov ecx,[ebx+0x4];
		cmp scriptAddress,ecx;
		je found;
		
		//Move to the next link in the list.
		mov esi,[esi+0x4];
		
		//If the link is 0, then the script is not in the list.
		cmp esi,0;
		je notFound;
		
		//else, check the ScriptNode for this link.
		jmp nextNode;

		found:
		mov GLOBAL_result,1;
		jmp done;

		notFound:
		mov GLOBAL_result,0;
	
		done:
	}

	return 1;


}




int FUNCTION_SetSlashMin()
{

	WEAPRECORD *weaponRecord = (WEAPRECORD *)getLongParameter();
	int minSlash = getLongParameter();

	if(weaponRecord == 0)
	{
		setResult(0);
		return 1;
	}
	else
	{
		weaponRecord->slashMin = minSlash;
		setResult(1);
		return 1;
	}
}

int FUNCTION_SetSlashMax()
{

	WEAPRECORD *weaponRecord = (WEAPRECORD *)getLongParameter();
	int maxSlash = getLongParameter();

	if(weaponRecord == 0)
	{
		setResult(0);
		return 1;
	}
	else
	{
		weaponRecord->slashMax = maxSlash;
		setResult(1);
		return 1;
	}
}

int FUNCTION_GetSlashMax()
{

	WEAPRECORD *weaponRecord = (WEAPRECORD *)getLongParameter();

	if(weaponRecord == 0)
	{
		setResult(-1);
		return 1;
	}
	else
	{
		int max = weaponRecord->slashMax;
		setResult(max);
		return 1;
	}
}


int FUNCTION_GetSlashMin()
{

	WEAPRECORD *weaponRecord = (WEAPRECORD *)getLongParameter();

	if(weaponRecord == 0)
	{
		setResult(-1);
		return 1;
	}
	else
	{
		int min = weaponRecord->slashMin;
		setResult(min);
		return 1;
	}
}










int FUNCTION_SetSlashDamage()
{

	WEAPRECORD *weaponRecord = (WEAPRECORD *)getLongParameter();
	int minSlash = getLongParameter();
	int maxSlash = getLongParameter();

	if(weaponRecord == 0)
	{
		setResult(0);
		return 1;
	}
	else
	{
		weaponRecord->slashMin = minSlash;
		weaponRecord->slashMax = maxSlash;
		setResult(1);
		return 1;
	}
}






 //returns the address of an object's template record
int getTemplate(char *id)
{
	//address of function that performs the find template function
	static int NPC_ = 0x5f43504e;
	static int *findTemplate = (int *)0x481eb0;
	static char npcTemplateName[1024];
	int templateAddress;
	int result;

	if(strcmp(id,"player") == 0)
	{
	   	static int getMACP = 0x40ff20;
		static int getPCREFR = 0x467350;

		_asm
		{
			//This block of code gets the reference of the player character.
			mov ecx,dword ptr ds:[0x7c67dc];
			call getMACP;
			mov ecx,eax;
			call getPCREFR;
			mov ebx,[eax+0x28];
			mov templateAddress,ebx;
		}
		return templateAddress;
	}
	else
	{
		strcpy(npcTemplateName,id);
		strcat(npcTemplateName,"00000000");
	}


	_asm
	{
		mov edx, dword ptr ds:[0x7c67e0];
		mov ecx, dword ptr ds:[edx];
		mov esi, ecx;
		mov ecx, dword ptr ds:[esi+0xb268];
		push id;
		call findTemplate;
		mov templateAddress,eax;


		//if the template is of type NPC_, then we need to find the template address of the name
		//of the NPC using the actual id of the NPC, which will be the NPC name with eight zeros appended to it
		mov ebx,[eax+0x4]
		cmp ebx,NPC_
		
		//If the template is not of type NPC_, then we already have the actual template name.
		jne done
		
		//else, do it over again, this time with the correct template name.
		mov edx, dword ptr ds:[0x7c67e0];
		mov ecx, dword ptr ds:[edx];
		mov esi, ecx;
		mov ecx, dword ptr ds:[esi+0xb268];
		lea eax,npcTemplateName;
		push eax;
		call findTemplate;
		mov templateAddress,eax;


		done:

	}
	return templateAddress;
}

