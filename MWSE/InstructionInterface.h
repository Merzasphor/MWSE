#ifndef INSTRUCTION_INTERFACE_H
#define INSTRUCTION_INTERFACE_H

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
#endif
