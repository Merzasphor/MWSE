#pragma once

#include "mwseTypes.h"
#include "mwAdapter.h"

namespace mwse
{
	public class VMHookInterface
	{
		virtual void executeOperation(mwOpcode_t opcode, mwAdapter::Context_t &context, SCPTRecord_t &script) = 0;
		virtual void loadParametersForOperation(mwOpcode_t opcode, mwAdapter::Context_t &context, SCPTRecord_t &script) = 0;
	};
}