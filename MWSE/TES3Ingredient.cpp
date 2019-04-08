#include "TES3Ingredient.h"

namespace TES3 {
	void Ingredient::setName(const char* n) {
		if (strlen(n) >= 32) {
			throw std::length_error("Input string is more than 31 characters long.");
		}

		strcpy(name, n);
	}
}
