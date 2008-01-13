/************************************************************************
               InstructionInterface.h - Copyright (c) 2008 The MWSE Project
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

namespace mwse {
    class InstructionInterface_t {
        public:
            inline mwOpcode_t getOpCode() const { return opcode; }
            //void execute(... [need types for this]) = 0;
            //void loadParameters(..., bool scanonly /* do not load, for scanning inactive branches of _if_*/) = 0;
        protected:
            InstructionInterface_t(const mwOpcode_t ctor_opcode);
        private:
            const mwOpcode_t opcode;
    };
};
