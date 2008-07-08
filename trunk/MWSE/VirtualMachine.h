/************************************************************************
               VirtualMachine.h - Copyright (c) 2008 The MWSE Project
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
#include "mwAdapter.h"
#include "VMHookInterface.h"
#include "VMExecuteInterface.h"

using namespace mwse;

namespace mwse
{
	class VirtualMachine : public VMHookInterface, VMExecuteInterface
	{
	public:
		VirtualMachine();
		virtual float executeOperation(mwOpcode_t opcode, mwAdapter::Context_t &context, SCPTRecord_t &script);
		virtual void loadParametersForOperation(mwOpcode_t opcode, mwAdapter::Context_t &context, SCPTRecord_t &script);
		virtual bool isOpcode(const mwOpcode_t opcode);

		virtual REFRRecord_t * getReference();
		virtual REFRRecord_t * getReference(const char *id);
		virtual void setReference(REFRRecord_t * reference);

		//local variables, methods to access local variables
		virtual mwLong_t getLongVariable(int index);							//by index
		virtual mwLong_t getLongVariable(const char *id);						//by name
		virtual mwLong_t getLongVariable(int index, REFRRecord_t &reference);	//foreign
		virtual void setLongVariable(int index, mwLong_t value);
		virtual void setLongVariable(const char *id, mwLong_t value);
		virtual void setLongVariable(int index, mwLong_t value , REFRRecord_t &reference);

		virtual mwShort_t getShortVariable(int index);
		virtual mwShort_t getShortVariable(const char *id);
		virtual mwShort_t getShortVariable(int index, REFRRecord_t &reference);
		virtual void setShortVariable(int index, mwShort_t value);
		virtual void setShortVariable(const char *id, mwShort_t value);
		virtual void setShortVariable(int index, mwShort_t value , REFRRecord_t &reference);

		virtual mwFloat_t getFloatVariable(int index);
		virtual mwFloat_t getFloatVariable(const char *id);
		virtual mwFloat_t getFloatVariable(int index, REFRRecord_t &reference);
		virtual void setFloatVariable(int index, mwFloat_t value);
		virtual void setFloatVariable(const char *id, mwFloat_t value);
		virtual void setFloatVariable(int index, mwFloat_t value , REFRRecord_t &reference);

		//global variables, methods to access global variables
		virtual mwLong_t getLongGlobal(const char *id);
		virtual void setLongGlobal(const char *id, mwLong_t value);
		
		virtual mwShort_t getShortGlobal(const char *id);
		virtual void setShortGlobal(const char *id, mwShort_t value);

		virtual mwFloat_t getFloatGlobal(const char *id);
		virtual void setFloatGlobal(const char *id, mwFloat_t value);

	protected:
	private:
		mwAdapter::Context_t getContext();				//for internal functions that need the context (registers, etc)
		void setContext(mwAdapter::Context_t context); //for internal functions that need the context (registers, etc)

		SCPTRecord_t& getScript();				//get reference to current script
		void setScript(SCPTRecord_t &script);	//set reference to current script
		
		mwAdapter::Context_t context;			//current context (registers, etc)
		SCPTRecord_t * script;					//current script pointer
		long *mwScriptIP;
	};
};