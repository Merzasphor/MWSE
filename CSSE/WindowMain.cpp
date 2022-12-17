#include "WindowMain.h"

#include "MemoryUtil.h"

namespace se::cs::window::main {
	using namespace se::memory;

	static auto last2ndClassUpdateTime = std::chrono::milliseconds::zero();
	const auto TES3CS_UpdateStatusMessage = reinterpret_cast<void(__cdecl*)(WPARAM, LPARAM)>(0x46E680);
	void __cdecl PatchThrottleMessageUpdate(WPARAM type, LPARAM lParam) {
		if (type == 2) {
			const auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
			const auto msSinceLastUpdate = now - last2ndClassUpdateTime;
			if (msSinceLastUpdate.count() < 20) {
				return;
			}
			last2ndClassUpdateTime = now;
		}
		else {
			last2ndClassUpdateTime = std::chrono::milliseconds::zero();
		}
		TES3CS_UpdateStatusMessage(type, lParam);
	}

	void installPatches() {
		// Patch: Throttle UI status updates.
		genJumpEnforced(0x404881, 0x46E680, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	}
}