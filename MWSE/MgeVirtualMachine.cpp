#include "MgeVirtualMachine.h"

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "OpCodes.h"

namespace mwse {
	class MgeInstruction : InstructionInterface_t {
	public:
		MgeInstruction(OpCode::OpCode_t opcode, INSTRUCTION* instruction);
		virtual float execute(VMExecuteInterface& virtualMachine);
		virtual void loadParameters(VMExecuteInterface& virtualMachine);
	private:
		OpCode::OpCode_t opcode;
		INSTRUCTION* instruction;
	};

	MgeInstruction::MgeInstruction(OpCode::OpCode_t opcode, INSTRUCTION* instruction) :
		instruction(instruction),
		opcode(opcode),
		InstructionInterface_t(opcode)
	{

	}

	void MgeInstruction::loadParameters(mwse::VMExecuteInterface& virtualMachine) {

	}

	float MgeInstruction::execute(mwse::VMExecuteInterface& virtualMachine) {
		if constexpr (DEBUG_MGE_VM) {
			log::getLog() << __FUNCTION__ << " opcode: " << std::hex << opcode << std::endl;
		}
		instruction->execute();
		return 0.0f;
	}
}

using namespace mwse;

VIRTUALMACHINE::~VIRTUALMACHINE(void) {

}

bool VIRTUALMACHINE::AddAddressSpace(VPVOID position, ADDRESSSPACE* space) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	return true;
}

bool VIRTUALMACHINE::AddInstruction(OPCODE opcode, INSTRUCTION* instruction) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << " opcode: " << std::hex << opcode << std::endl;
	}

	// The memory here is managed in the instruction interface.
	auto mge_instruction = new mwse::MgeInstruction((OpCode::OpCode_t)opcode, instruction);

	return true;
}

//function to access memory to read or write to it
bool VIRTUALMACHINE::AccessMem(MEMACCESSOR& access, VPVOID addr, VOID* buf, VMSIZE size) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	return true;
}

// function to read stuff from memory 
bool VIRTUALMACHINE::ReadMem(const VPVOID addr, VOID* buf, VMSIZE size) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	return true;
}

//function to write stuff to memory
bool VIRTUALMACHINE::WriteMem(VPVOID addr, const VOID* buf, VMSIZE size) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	return true;
}

bool VIRTUALMACHINE::GetInstruction(VPVOID addr, OPCODE& opcode) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	return true;
}

//see if the given opcode is an extended instruction
bool VIRTUALMACHINE::IsInstruction(OPCODE inst) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	return true;
}

bool VIRTUALMACHINE::step(bool skip) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	return false;
}

bool VIRTUALMACHINE::run(void) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	return true;
}


bool VIRTUALMACHINE::Interrupt(VMINTERRUPT intnum) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	// 2005-07-07  CDC  It should return something.  False since it didn't do anything?
	return false;
}

bool VIRTUALMACHINE::push(VMREGTYPE val) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	mwse::Stack::getInstance().pushLong(val);
	return true;
}

bool VIRTUALMACHINE::push(VMFLOAT val) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	mwse::Stack::getInstance().pushFloat(val);
	return true;
}

bool VIRTUALMACHINE::pop(VMREGTYPE& val) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	val = mwse::Stack::getInstance().popLong();
	return true;
}

bool VIRTUALMACHINE::pop(VMFLOAT& val) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	val = mwse::Stack::getInstance().popFloat();

	return true;
}

void VIRTUALMACHINE::SetFlags(VMREGTYPE value) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	if (value) {
		flags = (value > 0) ? FPOS : 0;
	}
	else {
		flags = FZERO | FPOS;
	}
}

void VIRTUALMACHINE::SetFlags(VMFLOAT value) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}

	if (value) {
		flags = (value > 0) ? FPOS : 0;
	}
	else {
		flags = FZERO | FPOS;
	}
}

VMFLAGSTYPE VIRTUALMACHINE::GetFlags(void) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}
	return flags;
}

void VIRTUALMACHINE::BadOpcodeHandler(OPCODE opcode, VPVOID ip) {
	if constexpr (DEBUG_MGE_VM) {
		mwse::log::getLog() << __FUNCTION__ << std::endl;
	}
}

