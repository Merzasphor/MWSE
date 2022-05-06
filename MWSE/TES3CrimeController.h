#pragma once

#include "TES3Defines.h"

namespace TES3 {
	struct CrimeController {
		bool unknown_0x0;
		CrimeEventList * events; // 0x4
		int eventCount; // 0x8

		CrimeController() = delete;
		~CrimeController() = delete;

		//
		// Other related this-call functions.
		//

		// Raw call to underlying insert crime function.
		void insertCrime(CrimeEventList ** out_result, CrimeEventList * head, CrimeEvent * crime);

		// Raw call to underlying delete crime function.
		void deleteCrime(CrimeEventList ** out_result, CrimeEventList * node);

		//
		// Custom functions.
		//

		// Helper variant of the function that uses the current events head automatically.
		CrimeEventList * insertCrime(CrimeEvent * crime);
		// Helper variant of the function that doesn't use the out_result parameter.
		CrimeEventList * insertCrime(CrimeEventList * head, CrimeEvent * crime);

	};
	static_assert(sizeof(CrimeController) == 0xC, "TES3::CrimeController failed size validation");
}
