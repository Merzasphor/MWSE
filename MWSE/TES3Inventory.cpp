#include "TES3Inventory.h"

#define TES3_Inventory_resolveLevelledLists 0x49A190

namespace TES3 {
	void Inventory::resolveLevelledLists(MobileActor* actor) {
		reinterpret_cast<void(__thiscall *)(Inventory*, MobileActor*)>(TES3_Inventory_resolveLevelledLists)(this, actor);
	}
}
