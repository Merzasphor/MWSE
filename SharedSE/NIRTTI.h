#pragma once

#include "NIDefines.h"

namespace NI {
	struct RTTI {
		const char* name; // 0x0
		RTTI* baseRTTI; // 0x4

		RTTI(const char* name, RTTI* parent = nullptr);
		RTTI(const char* name, RTTIStaticPtr::RTTIStaticPtr parent);

		const char* toString() const;
	};
}
