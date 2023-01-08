#include "CSSpell.h"

namespace se::cs {
	bool Spell::getSpellFlag(SpellFlag::Flag flag) const {
		return (spellFlags & flag) == flag;
	}

	bool Spell::getPlayerStart() const {
		return getSpellFlag(SpellFlag::PCStartSpell);
	}
}
