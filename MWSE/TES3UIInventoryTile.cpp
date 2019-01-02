#include "TES3UIInventoryTile.h"

namespace TES3 {
	namespace UI {
		bool InventoryTile::getFlag(unsigned int flag) {
			return (flags & flag) != 0;
		}
	}
}
