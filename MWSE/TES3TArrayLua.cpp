#include "TES3TArrayLua.h"

#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Attachment.h"
#include "TES3Cell.h"
#include "TES3Dialogue.h"
#include "TES3DialogueInfo.h"
#include "TES3GlobalVariable.h"
#include "TES3Inventory.h"
#include "TES3Item.h"
#include "TES3ItemData.h"
#include "TES3Faction.h"
#include "TES3LeveledList.h"
#include "TES3MobileActor.h"
#include "TES3Quest.h"
#include "TES3Reference.h"
#include "TES3Region.h"
#include "TES3Spell.h"

#include "NIPick.h"
#include "NIProperty.h"

namespace mwse {
	namespace lua {
		void bindTES3TArray() {
			// Basic TArray bindings.
			bindTArray<TES3::ItemData>("tes3itemDataTArray");
			bindTArray<NI::PickRecord>("niTArrayPickRecord");
			bindTArray<NI::TexturingProperty::Map>("niTArrayTexturingPropertyMap");
		}
	}
}
