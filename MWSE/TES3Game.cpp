#include "TES3Game.h"

namespace TES3 {
	Game * Game::get() {
		return *reinterpret_cast<TES3::Game**>(0x7C6CDC);
	}

	void Game::setGamma(float value) {
		vTable->setGamma(this, value);
	}

	const auto TES3_Game_initialize = reinterpret_cast<bool(__thiscall *)(Game*)>(0x417880);
	bool Game::initialize() {
		return TES3_Game_initialize(this);
	}

	const auto TES3_Game_clearTarget = reinterpret_cast<bool(__thiscall *)(Game*)>(0x41CD00);
	void Game::clearTarget() {
		TES3_Game_clearTarget(this);
	}
}
