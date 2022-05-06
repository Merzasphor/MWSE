#pragma once

#include "TES3CrimeEvent.h"

namespace TES3 {
	struct CrimeEventList {
		CrimeEventList * previous; // 0x0
		CrimeEventList * next; // 0x4
		CrimeEvent data; // 0x8

		CrimeEventList() = delete;
		~CrimeEventList() = delete;

		static CrimeEventList * createBetween(CrimeEventList * previous, CrimeEventList * next);
	};
	static_assert(sizeof(CrimeEventList) == 0x44, "TES3::CrimeEventList failed size validation");
}
