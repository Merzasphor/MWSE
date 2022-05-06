#include "NIKeyframeController.h"

namespace NI {
	std::reference_wrapper<decltype(EulerRotKey::numKeys)> EulerRotKey::getNumKeys_lua() {
		return std::ref(numKeys);
	}

	std::reference_wrapper<decltype(EulerRotKey:: keyTypes)> EulerRotKey::getKeyTypes_lua() {
		return std::ref(keyTypes);
	}

	sol::table EulerRotKey::getKeys_lua(sol::this_state ts) {
		sol::state_view state = ts;
		auto table = state.create_table(3);
		for (auto i = 0; i < 3; i++) {
			if (keys[i].asFloatKey) {
				switch (keyTypes[i]) {
				case AnimationKey::Type::NoInterp:
				case AnimationKey::Type::Linear:
					table[i + 1] = nonstd::span(keys[i].asFloatKey, numKeys[i]);
					break;
				case AnimationKey::Type::Bezier:
					table[i + 1] = nonstd::span(keys[i].asBezFloatKey, numKeys[i]);
					break;
				case AnimationKey::Type::TCB:
					table[i + 1] = nonstd::span(keys[i].asTCBFloatKey, numKeys[i]);
					break;
				default:
					throw std::runtime_error("Invalid euler rotation key type found. Report to MWSE developers.");
				}
			}
		}
		return table;
	}

	std::reference_wrapper<decltype(EulerRotKey::lastIndices)> EulerRotKey::getLastIndices_lua() {
		return std::ref(lastIndices);
	}

	sol::object KeyframeData::getRotationKeys_lua(sol::this_state L) {
		// Make sure we're looking at the main state.
		L = sol::main_thread(L);

		switch (rotationType) {
		case AnimationKey::Type::NoInterp:
		case AnimationKey::Type::Linear:
			return sol::make_object(L, nonstd::span(rotationKeys.asRotKey, rotationKeyCount));
		case AnimationKey::Type::Bezier:
			return sol::make_object(L, nonstd::span(rotationKeys.asBezRotKey, rotationKeyCount));
		case AnimationKey::Type::TCB:
			return sol::make_object(L, nonstd::span(rotationKeys.asTCBRotKey, rotationKeyCount));
		case AnimationKey::Type::Euler:
			return sol::make_object(L, nonstd::span(rotationKeys.asEulerRotKey, rotationKeyCount));
		default:
			throw std::runtime_error("Invalid position type found. Report to MWSE developers.");
		}
	}

	sol::object KeyframeData::getPositionKeys_lua(sol::this_state L) {
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

	sol::object KeyframeData::getScaleKeys_lua(sol::this_state L) {
		// Make sure we're looking at the main state.
		L = sol::main_thread(L);

		switch (scaleType) {
		case AnimationKey::Type::NoInterp:
		case AnimationKey::Type::Linear:
			return sol::make_object(L, nonstd::span(scaleKeys.asFloatKey, scaleKeyCount));
		case AnimationKey::Type::Bezier:
			return sol::make_object(L, nonstd::span(scaleKeys.asBezFloatKey, scaleKeyCount));
		case AnimationKey::Type::TCB:
			return sol::make_object(L, nonstd::span(scaleKeys.asTCBFloatKey, scaleKeyCount));
		default:
			throw std::runtime_error("Invalid position type found. Report to MWSE developers.");
		}
	}
}
