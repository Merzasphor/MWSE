/************************************************************************
               VMExecuteInterface.h - Copyright (c) 2008 The MWSE Project
                http://www.sourceforge.net/projects/mwse

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#pragma once

#include "mwseString.h"

#include "ObjectTypes.h"
#include "TES3Reference.h"
#include "TES3Script.h"

using namespace mwse;

namespace mwse
{
	class VMExecuteInterface
	{
	public:
		//VirtualMachine specific
		virtual long* getScriptIP() = 0;	//to get the script Instruction Pointer, (for functions that change this, like jump and call like things).

		//local variables, methods to access local variables
		virtual mwLong getLongVariable(int index) = 0;							//by index
		virtual mwLong getLongVariable(const char *id) = 0;						//by name
		virtual mwLong getLongVariable(int index, TES3::Reference &reference) = 0;	//foreign
		virtual void setLongVariable(int index, mwLong value) = 0;
		virtual void setLongVariable(const char *id, mwLong value) = 0;
		virtual void setLongVariable(int index, mwLong value , TES3::Reference &reference) = 0;

		virtual mwShort getShortVariable(int index) = 0;
		virtual mwShort getShortVariable(const char *id) = 0;
		virtual mwShort getShortVariable(int index, TES3::Reference &reference) = 0;
		virtual void setShortVariable(int index, mwShort value) = 0;
		virtual void setShortVariable(const char *id, mwShort value) = 0;
		virtual void setShortVariable(int index, mwShort value , TES3::Reference &reference) = 0;

		virtual mwFloat getFloatVariable(int index) = 0;
		virtual mwFloat getFloatVariable(const char *id) = 0;
		virtual mwFloat getFloatVariable(int index, TES3::Reference &reference) = 0;
		virtual void setFloatVariable(int index, mwFloat value) = 0;
		virtual void setFloatVariable(const char *id, mwFloat value) = 0;
		virtual void setFloatVariable(int index, mwFloat value , TES3::Reference &reference) = 0;

		//global variables, methods to access global variables
		virtual mwLong getLongGlobal(const char *id) = 0;
		virtual void setLongGlobal(const char *id, mwLong value) = 0;
		
		virtual mwShort getShortGlobal(const char *id) = 0;
		virtual void setShortGlobal(const char *id, mwShort value) = 0;

		virtual mwFloat getFloatGlobal(const char *id) = 0;
		virtual void setFloatGlobal(const char *id, mwFloat value) = 0;

		//objects and stuff
		//look at GETREF function in old MWSE for examples on how to fetch references!
		virtual TES3::Reference * getReference(const char *id) = 0; //can also be called getMorrowindObject i guess, this fetches the correct reference for the given object (player, npc, book, light, etc)
		virtual TES3::Reference * getReference() = 0; //gets the current reference, maybe it's better to put this in another function. it'll do for now
		
		virtual void setReference(TES3::Reference * reference) = 0; //this sets the reference, to be used for the next instruction (also works on other MWSE instructions in the same run), but for all other things, this needs to be called before the function! (as it needs a run in runScript)
		
		virtual TES3::Reference * getCurrentTarget() = 0;	//get the current reference under the crosshairs
		virtual TES3::BaseObject * getTemplate(const char *id) = 0;	//get a template (spell, item, npc) given an id. template are NOT REFR objects. they are 'not in the game yet', but available.

		//getParameters
		//virtual * get*Parameter() = 0;
		
		//virtual template<class T> void getStreamValue(T returnValue, bool peek = false) = 0;	//T must be in paramter list... if peek is true, then it doesn't increase the stream pointer
		//OR
		virtual char getByteValue(bool peek = false) = 0;			//peek means don't increase stream pointer
		virtual mwShort getShortValue(bool peek = false) = 0;
		virtual mwLong getLongValue(bool peek =false) = 0;
		virtual mwFloat getFloatValue(bool peek = false) = 0;

		virtual mwseString_t& getString(mwLong fromStack) = 0;	//only ment for stack-based syntax!, parameter-based syntax functions should use getStringParameter!!!

		virtual void dumpScriptVariables() = 0;

		virtual TES3::Script& getScript() = 0;
	};
};