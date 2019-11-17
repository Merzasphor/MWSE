#include "TES3MobileSpellProjectile.h"

#include "TES3SpellInstanceController.h"
#include "TES3WorldController.h"

namespace TES3 {
	MagicSourceInstance* MobileSpellProjectile::getInstance() {
		return TES3::WorldController::get()->spellInstanceController->getInstanceFromSerial(spellInstanceSerial);
	}
}
