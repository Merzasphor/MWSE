#pragma once

#include "MemoryUtil.h"

namespace mwse {
	class VirtualMachine;

	namespace mwAdapter {
		void Hook();

		VirtualMachine* GetVMInstance();
	}
}