#include "TES3Faction.h"

namespace TES3 {
	char * Faction::getName() {
		return name;
	}

	void Faction::setName(const char* value) {
		if (value != NULL && strlen(value) < 32) {
			strcpy(name, value);
		}
	}
}