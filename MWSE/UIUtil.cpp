#include "UIUtil.h"

#define TES3_ui_requestMenuModeOff 0x595270
#define TES3_ui_requestMenuModeOn 0x595230

namespace mwse {
	namespace tes3 {
		namespace ui {
			bool requestMenuModeOff() {
				return reinterpret_cast<signed char(__cdecl *)()>(TES3_ui_requestMenuModeOff)();
			}

			bool requestMenuModeOn(short prop) {
				return reinterpret_cast<signed char(__cdecl *)(short)>(TES3_ui_requestMenuModeOn)(prop);
			}
		}
	}
}
