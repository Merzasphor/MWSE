#include "TES3Item.h"

namespace TES3 {
	ItemData * ItemData::createForObject(BaseObject * object) {
		return reinterpret_cast<TES3::ItemData*(__cdecl *)(TES3::BaseObject*)>(0x4E7750)(object);
	}
}
