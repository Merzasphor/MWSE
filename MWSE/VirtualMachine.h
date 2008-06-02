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