#include "NIKeyframeController.h"

namespace NI {
	std::reference_wrapper<float[3]> TCBPosKey::getTCB() {
		return tcb;
	}

	sol::object KeyframeData::getPositionKeys_lua(sol::this_state L) const {
		// Make sure we're looking at the main state.
		L = sol::main_thread(L);

		switch (positionType) {
		case AnimationKey::Type::NoInterp:
		case AnimationKey::Type::Linear:
			return sol::make_object(L, nonstd::span(positionKeys.asPosKey, positionKeyCount));
		case AnimationKey::Type::Bezier:
			return sol::make_object(L, nonstd::span(positionKeys.asBezPosKey, positionKeyCount));
		case AnimationKey::Type::TCB:
			return sol::make_object(L, nonstd::span(positionKeys.asTCBPosKey, positionKeyCount));
		default:
			throw std::runtime_error("Invalid position type found. Report to MWSE developers.");
		}
	}
}
