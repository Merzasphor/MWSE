#include "PatchUtil.h"

#include "mwOffsets.h"
#include "TES3Script.h"

#include "MemoryUtil.h"

namespace mwse {
	namespace patch {

		//
		// Patch: Enable
		//

		void PatchScriptOpEnable() {
			TES3::ScriptVariables* scriptVars = *reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE);
			if (scriptVars != NULL) {
				scriptVars->unknown_0x68 &= 0xFE;
			}
		}

		//
		// Patch: Disable
		//

		void PatchScriptOpDisable() {
			TES3::ScriptVariables* scriptVars = *reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE);
			if (scriptVars != NULL) {
				scriptVars->unknown_0x68 |= 0x1;
			}
		}

		// Install all the patches.
		void installPatches() {
			// Patch: Enable/Disable
			genCallUnprotected(0x508FEB, reinterpret_cast<DWORD>(PatchScriptOpEnable), 0x9);
			genCallUnprotected(0x5090DB, reinterpret_cast<DWORD>(PatchScriptOpDisable), 0x9);
		}
	}
}
