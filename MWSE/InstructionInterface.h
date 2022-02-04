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
