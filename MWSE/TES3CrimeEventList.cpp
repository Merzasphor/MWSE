#include "TES3CrimeEventList.h"

namespace TES3 {
	const auto TES3_CrimeEventList_createBetween = reinterpret_cast<CrimeEventList * (__stdcall*)(CrimeEventList *, CrimeEventList *)>(0x4EC3E0);
	CrimeEventList * CrimeEventList::createBetween(CrimeEventList * previous, CrimeEventList * next) {
		auto result = TES3_CrimeEventList_createBetween(previous, next);
		previous->next = result;
		result->next->previous = result;

		return result;
	}
}
