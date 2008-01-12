#include "mwseTypes.h"
#include "InstructionInterface.h"
#include "InstructionStore.h"

using namespace mwse;

InstructionInterface_t::InstructionInterface_t(const mwOpcode_t ctor_opcode):
    opcode(ctor_opcode)
{
    InstructionStore::getInstance().add(*this);
}
