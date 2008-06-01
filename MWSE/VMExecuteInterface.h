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

#include "mwseTypes.h"

using namespace mwse;

namespace mwse
{
	class VMExecuteInterface
	{
	public:
		//local variables, methods to access local variables
		virtual mwLong_t getLongVariable(int index) = 0;
		virtual mwLong_t getLongVariable(const char *id) = 0;
		virtual mwLong_t getLongVariable(int index, REFRRecord_t &reference);
		virtual void setLongVariable(int index, mwLong_t value) = 0;
		virtual void setLongVariable(const char *id, mwLong_t value) = 0;
		virtual void setLongVariable(int index, mwLong_t value , REFRRecord_t &reference);

		virtual mwShort_t getShortVariable(int index) = 0;
		virtual mwShort_t getShortVariable(const char *id) = 0;
		virtual mwShort_t getShortVariable(int index, REFRRecord_t &reference);
		virtual void setShortVariable(int index, mwShort_t value) = 0;
		virtual void setShortVariable(const char *id, mwShort_t value) = 0;
		virtual void setShortVariable(int index, mwShort_t value , REFRRecord_t &reference);

		virtual mwFloat_t getFloatVariable(int index) = 0;
		virtual mwFloat_t getFloatVariable(const char *id) = 0;
		virtual mwFloat_t getFloatVariable(int index, REFRRecord_t &reference);
		virtual void setFloatVariable(int index, mwFloat_t value) = 0;
		virtual void setFloatVariable(const char *id, mwFloat_t value) = 0;
		virtual void setFloatVariable(int index, mwFloat_t value , REFRRecord_t &reference);

		//global variables, methods to access global variables
		virtual mwLong_t getLongGlobal(const char *id) = 0;
		virtual void setLongGlobal(const char *id, mwLong_t value) = 0;
		
		virtual mwShort_t getShortGlobal(const char *id) = 0;
		virtual void setShortGlobal(const char *id, mwShort_t value) = 0;

		virtual mwFloat_t getFloatGlobal(const char *id) = 0;
		virtual void setFloatGlobal(const char *id, mwFloat_t value) = 0;

		//objects and stuff
		//look at GETREF function in old MWSE for examples on how to fetch references!
		virtual void * getReference(const char *id) = 0; //can also be called getMorrowindObject i guess, this fetches the correct reference for the given object (player, npc, book, light, etc)
		virtual void * getReference() = 0; //gets the current reference, maybe it's better to put this in another function. it'll do for now
		
		virtual void setReference(void * reference) = 0; //this sets the reference, to be used for the next instruction (also works on other MWSE instructions in the same run), but for all other things, this needs to be called before the function! (as it needs a run in runScript)
		
		//getParameters
		//virtual * get*Parameter() = 0;
	};
};