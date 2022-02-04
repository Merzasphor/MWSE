#include "InstructionInterface.h"
#include "InstructionStore.h"

using namespace mwse;

InstructionInterface_t::InstructionInterface_t(const OpCode::OpCode_t ctor_opcode) :
	opcode(ctor_opcode)
{
	InstructionStore::getInstance().add(*this);
}
