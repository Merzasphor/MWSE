#include "CSContainer.h"

namespace se::cs {
	bool Container::getIsOrganic() const {
		return (actorFlags & ActorFlagContainer::Organic) != 0;
	}

	bool Container::getRespawns() const {
		return (actorFlags & ActorFlagContainer::Respawns) != 0;
	}
}
