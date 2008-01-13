#pragma once

#include "mwseTypes.h"
#include "VMHookInterface.h"
#include "VMOperationInterface.h"

using namespace mwse;

namespace mwse
{
	class VirtualMachine : public VMHookInterface, VMOperationInterface
	{
	}
};