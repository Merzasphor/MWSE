#pragma once

#include "TES3CrimeEvent.h"

namespace TES3 {
	struct CrimeTree {
		CrimeTree * a;
		CrimeTree * b;
		CrimeEvent data;
	};
	static_assert(sizeof(CrimeTree) == 0x44, "TES3::CrimeTree failed size validation");
}
