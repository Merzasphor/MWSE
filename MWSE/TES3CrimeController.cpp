#include "TES3CrimeController.h"

namespace TES3 {
	const auto TES3_CrimeController_insertCrime = reinterpret_cast<void(__thiscall*)(CrimeController*, CrimeEventList**, CrimeEventList*, CrimeEvent*)>(0x52DEF0);
	void CrimeController::insertCrime(CrimeEventList** out_result, CrimeEventList* head, CrimeEvent* crime) {
		TES3_CrimeController_insertCrime(this, out_result, head, crime);
	}

	const auto TES3_CrimeController_deleteCrime = reinterpret_cast<void(__thiscall*)(CrimeController*, CrimeEventList**, CrimeEventList*)>(0x52DF70);
	void CrimeController::deleteCrime(CrimeEventList** out_result, CrimeEventList* node) {
		TES3_CrimeController_deleteCrime(this, out_result, node);
	}

	CrimeEventList* CrimeController::insertCrime(CrimeEvent* crime) {
		return insertCrime(events, crime);
	}

	CrimeEventList* CrimeController::insertCrime(CrimeEventList* head, CrimeEvent* crime) {
		CrimeEventList* result = nullptr;
		insertCrime(&result, head, crime);
		return result;
	}
}
