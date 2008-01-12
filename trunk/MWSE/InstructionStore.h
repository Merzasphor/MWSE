#pragma once

#include "mwseTypes.h"
#include "InstructionInterface.h"
#include "Log.h"

#include <exception>

namespace mwse {
        // This can afford to be expensive for adding opcodes, as that's not done often.
        // Conversely, looking up opcodes needs to be as fast as possible.

        // The fastest would be to have an array (std::vector) but given that opcodes
        // are 16 bit, we don't want to allocate 64K for opcodes.
    class IllegalOpCode: public std::exception {
        public:
            IllegalOpCode(const mwOpcode_t ctor_bad_opcode):
                bad_opcode(ctor_bad_opcode)
            {
            }
            virtual const char *what() const throw()
            {
                return "Illegal script instruction encountered";
            }
        const mwOpcode_t bad_opcode;
    };

    class InstructionStore {
        private:
            InstructionStore(); // private, this is a singleton
            static InstructionStore single_instance;

            InstructionInterface_t **opCode_primary_table[256];

        public:
            static InstructionStore& getInstance()
			{
				return single_instance;
			}

            void add(InstructionInterface_t &implementation);

            inline InstructionInterface_t *get(const mwOpcode_t opcode) throw (IllegalOpCode)
            {
                // TODO: Insert timing here to compare implementations.
                unsigned int primary_index = (opcode >> 8) & 0xFF;
                unsigned int secondary_index = opcode & 0xFF;
                InstructionInterface_t **secondary_table = opCode_primary_table[primary_index];
                if (secondary_table == NULL || secondary_table[secondary_index] == NULL) {
                    // FIXME: This should probably be in the VM, where it can report script name and offset.
                    log::getLog() << "Illegal or unimplemented opcode " << std::hex << opcode << std::endl;
                    throw IllegalOpCode(opcode);
                }
                return secondary_table[secondary_index];
            }
    };
};
