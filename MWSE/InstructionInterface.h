/************************************************************************
               InstructionInterface.h - Copyright (c) 2008 The MWSE Project
                https://github.com/MWSE/MWSE/

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

#include "OpCodes.h"

namespace mwse {
    class VMExecuteInterface;

    class InstructionInterface_t {
        public:
            inline OpCode::OpCode_t getOpCode() const { return opcode; }
            virtual float execute(VMExecuteInterface &virtualMachine) = 0;		//added 'virtual' so the linker wouldn't complain, added the '=0' back in.
            virtual void loadParameters(VMExecuteInterface &virtualMachine) = 0;	//same here
        protected:
            InstructionInterface_t(const OpCode::OpCode_t ctor_opcode);
        private:
            const OpCode::OpCode_t opcode;
    };
};
