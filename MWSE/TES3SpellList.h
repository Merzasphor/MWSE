#pragma once

#include "TES3Defines.h"

#include "TES3Collections.h"

#include <string>

namespace TES3 {
	struct SpellList {
		int unknown_0x0;
		Iterator<Spell> list;

		//
		// Other related this-call functions.
		//

		bool add(Spell*);
		bool add(const char*);
		bool add(const std::string&);

		bool remove(Spell*);
		bool remove(const char*);
		bool remove(const std::string&);

		bool contains(Spell*);
		bool contains(const char*);
		bool contains(const std::string&);

		Spell* getCheapest();

		//
		// Custom functions.
		//

		bool containsType(signed char);

	};
}
