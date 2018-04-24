#include "TES3UIBlock.h"

#define TES3_ui_performUpdate 0x583B70
#define TES3_ui_timingUpdate 0x583B60

namespace TES3 {
	namespace UI {
		Block* Block::performLayout(signed char something) {
			return reinterpret_cast<Block*(__thiscall *)(TES3::UI::Block*, signed char)>(TES3_ui_performUpdate)(this, something);
		}

		long Block::timingUpdate() {
			return reinterpret_cast<long(__thiscall *)(TES3::UI::Block*)>(TES3_ui_timingUpdate)(this);
		}
	}
}
