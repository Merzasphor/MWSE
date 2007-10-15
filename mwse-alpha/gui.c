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

#include "gui.h"
#include <stdlib.h>

int *newWindow(int windowID)
{
	int *windowAddress;
	_asm
	{
		push windowID;
		mov ebx,0x595400;
		call ebx;
		mov windowAddress,eax;
		add esp,4;
	}
	return windowAddress;
}

int setWidth(int *widgetAddress,int width)
{
	setAttribute(widgetAddress,1,width,ATTRIB_width);
	return 1;
}

int setHeight(int *widgetAddress, int height)
{
	setAttribute(widgetAddress,1,height,ATTRIB_height);
	return 1;
}



int *newCanvas(int *parentWindow, int id)
{
		int *canvasAddress = newWidget(parentWindow,1,0x00642550,id);
		return canvasAddress;
}


int *newBorder(int *parentWidget,int *NIFAddressPointer)
{
	int *borderAddress;
	_asm
	{
		mov ecx,parentWidget;
		push 0;
		push NIFAddressPointer;
		push ATTRIB_null;
		mov ebx,0x00588830;
		call ebx;
		mov borderAddress,eax;
	}
	return borderAddress;
}


int *newBlock(int *parentWidget)
{
	int *returnAddress;
	_asm
	{
		push 0;
		push 0xFFFF80b4;
		mov ecx,parentWidget;
		mov ebx,0x00588980;
		call ebx;
		mov returnAddress,eax;
	}
	return returnAddress;
}

int addButtonText(int *parentWidget,char *textPointer)
{
	_asm
	{

		mov ecx,parentWidget;
		push textPointer;
		mov ebx,0x0058ad30;
		call ebx;
	}
}

int addText(int *parentWidget,char *textPointer)
{
	_asm
	{
		push 0;
		push 0;
		push 0x1e7;
		mov ebx,0x40f930;
		call ebx;

		mov ecx,parentWidget;
		push textPointer;
		push ATTRIB_null;
		mov ebx,0x00588be0;
		call ebx;
	}
}


int doSomething(int *widget)
{
	_asm
	{
		mov eax,widget;
		mov ebx,0x3f800000;
		mov [eax+0x118],ebx;
	}
}

int show(int *widget)
{
	_asm
	{
		push 1;
		mov ecx,widget;
		mov ebx,0x00581400;
		call ebx;
	}
}

int *newWidget(int *parentWidget, int data1, int data2, int id)
{
	int *newWidgetAddress;

	_asm
	{
		mov ecx,parentWidget;
		push data1;
		push data2;
		push id;
		mov ebx,0x00588140;
		call ebx;
		mov newWidgetAddress,eax;
	}

	return newWidgetAddress;
}

int *setAttribute(int *widgetAddress, int data1, int data2, int data3)
{
	_asm
	{
		mov ecx,widgetAddress;
		push data1;
		push data2;
		push data3;
		mov ebx,0x00581f30;
		call ebx;
	}
}


//On the changing of modes
//There is a menu mode, which is entered into when you perform this command:
	//mov eax,dword ptr ds:[0x7c67dc];
	//mov [eax+0xd6],1;

//And there is a game mode, which is entered into when you perform this command:
		//set game mode flag to 0
		//mov [eax+0xd5],0;

//Entering game mode always works...but entering menu mode doesn't always work, unless you do it right.
//See, when you try to enter menu mode after you have set the game mode flag to 1, you won't enter menu mode.
//So, to correctly enter menu mode, you have to set the menu mode flag to 1, AND set the game mode flag to 0.
//However, when entering game mode, you ONLY set the game mode flag to 1.  If you also set the menu mode flag
//to 0, then game mode won't correctly be entered into (the mouse pointer will still be in "menu mode" mode.



int enterMenuMode()
{
   	_asm
	{

		//Set the ButtonPressed in-game variable to -1.
		mov dword ptr ds:[0x7b88c0],-1;




		//set game mode flag to 0
        mov eax,dword ptr ds:[0x7c67dc];
		mov [eax+0xd5],0;

        //This function enters menu mode
		//and wipes the string buffer so that keyboard inputs when not in menu mode are not placed
		//in a text box
        xor eax,eax;
		mov ax,word ptr ds:[0x7d4c64];
		push eax;
		mov ebx,0x00595230;
		call ebx;
		add esp,4;



	}
}


int leaveMenuMode(char *widgetAddress)
{
	static int freeWindow = 0x727530;
	static int returnValue = 0;
    static int gameFocus = 0x595270;
	_asm
	{
		//close the menu
		mov ecx, widgetAddress;
		mov ebx, 0x577FB0;
		call ebx;

		push widgetAddress;
		call freeWindow;
		add esp,4;

		//set game mode flag to 1
		mov eax,dword ptr ds:[0x7c67dc];
		mov [eax+0xd5],1;

	 }


}



int *newButton(int *parentWidget, char *textPointer, int *callbackFunction, int id)
{
	int *buttonAddress = newWidget(parentWidget,0,0x00639420,id);
	setAttribute(buttonAddress,0x20,(int)callbackFunction,ATTRIB_click);
	addButtonText(buttonAddress,textPointer);
	return buttonAddress;
}

int newInputDialog(char *dialogTitle, char *buttonText)
{
	int *windowAddress;
	int *buttonAddress;
	int *textInputAddress;
	int *borderAddress;
	int *blockAddress1;
	int *blockAddress2;
    static int refresh = 0x57f2a0;



	//Set the ButtonPressed in-game variable to -1.
	_asm
	{
		mov dword ptr ds:[0x7b88c0],-1;

	}




	windowAddress = newWindow(1234);

	newCanvas(windowAddress,5678);
	setAttribute(windowAddress,2,0x3f800000,ATTRIB_alpha);
    addText(windowAddress,dialogTitle);


	//First block contains border, which contains text input field
	blockAddress1 = newBlock(windowAddress);
    setWidth(blockAddress1,300);
	show(blockAddress1);
	setAttribute(blockAddress1,2,0x3f000000,ATTRIB_align_x);
   	borderAddress = newBorder(blockAddress1,(int *)0x007b4680);
    setWidth(borderAddress,300);
    setHeight(borderAddress,30);
    setAttribute(borderAddress,2,0,ATTRIB_align_x);
    setAttribute(borderAddress,2,0x3f000000,ATTRIB_align_y);
  	textInputAddress = newTextInput(borderAddress,0xfdc1);
	setAttribute(textInputAddress,10,0xFFFF80BD,0xfb73);

	//2nd block contains button
	blockAddress2 = newBlock(windowAddress);
	show(blockAddress2);
	doSomething(blockAddress2);
	setAttribute(blockAddress2,2,0x3f800000,ATTRIB_align_x);

	//setWidth(blockAddress2,300);
	buttonAddress = newButton(blockAddress2, buttonText,(int *)dialogCallback,0xfdc0);


	GLOBAL_windowAddress = (char *)windowAddress;

	enterMenuMode();

   	return 1;

}

int dialogCallback(int *widgetAddress)
{

	static int closeWindows = 0x595450;
	static int getMACP = 0x40ff20;
	
	GLOBAL_inputText =  (char *)malloc(sizeof(char)*64);


	//get the text that was input and store it, then close the menu and return control to the game.

	_asm
	{
		//Set the ButtonPressed in-game variable to 0.
		mov dword ptr ds:[0x7b88c0],0;


		mov ebx,dword ptr ds:[0x7c67dc];
 		mov ebx,dword ptr ds:[ebx+0x2e4];
      	mov ebx,dword ptr ds:[ebx+0x10];
		mov ebx,[ebx+0x88];

		//If ebx == 0, there was an error getting the user input
		cmp ebx,0
		je done

		//set source index to the location of the text input.
		mov esi,[ebx+0x168];

        //set destination index to the global var named inputText
		mov edi,GLOBAL_inputText;

		//place the size of the text in cl, for the rep movs instruction
		mov ecx,[ebx+0x16C];

		//The last character of an input string is always "|".  We don't want that character as apart
		//of the string, so we'll subtract 1 from the size of the string to be copied.
		sub ecx,1;

		//perform the string copy
		rep	movs byte ptr [edi], byte ptr [esi];


		//place the string delimeter 0 at the end of the string
		mov byte ptr [edi], 0;
	
	
		done:
	}

	leaveMenuMode(GLOBAL_windowAddress);

	return 1;
}


int *newTextInput(int *parentWidget,int id)
{
	int *inputAddress = newWidget(parentWidget,0,0x0064a8e0,id);
	addButtonText(inputAddress,(char *)0x007b467c);
	setAttribute(inputAddress,1,5,ATTRIB_border_left);
	setAttribute(inputAddress,1,5,ATTRIB_border_right);
	setAttribute(inputAddress,1,31,PartTextInput_length_limit);
	setAttribute(inputAddress,0x10,ATTRIB_partial,ATTRIB_focusable);


    _asm
    {


		mov ebx,dword ptr ds:[0x7c67dc];
 		mov ebx,dword ptr ds:[ebx+0x2e4];
      	mov ebx,dword ptr ds:[ebx+0x10];
		mov ecx,inputAddress;
		mov [ebx+0x88],ecx;
	}

	return inputAddress;
}


