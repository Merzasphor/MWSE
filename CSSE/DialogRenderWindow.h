#pragma once

#include "NIDefines.h"

#include "MemoryUtil.h"

namespace se::cs::dialog::render_window {
	struct NetImmerseInstance;

	struct RenderController {
		NetImmerseInstance* niInstance; // 0x0
		NI::Node* node; // 0x4
		NI::Camera* camera; // 0x8

		static inline auto get() {
			return memory::ExternalGlobal<RenderController*, 0x6CF77C>::get();
		}
	};
	static_assert(sizeof(RenderController) == 0xC, "CS::RenderController failed size validation");

	constexpr UINT DIALOG_ID = 176;

	void installPatches();
}
