#pragma once

#include "CSDefines.h"
#include "CSBaseObject.h"

namespace se::cs {
	struct GameSetting : BaseObject {
		struct Initializer {
			enum class ValueType : unsigned int {
				Integer,
				Float,
				String,
			};
			const char* name; // 0x0
			const char* defaultStringValue; // 0x4
			int defaultIntValue; // 0x8
			float defaultFloatValue; // 0xC
			ValueType valueType;
		};
		union {
			int asInt;
			float asFloat;
			const char* asString;
		} value; // 0x10
		int index; // 0x14

		static constexpr auto initializers = reinterpret_cast<Initializer*>(0x6A8128);
	};
	static_assert(sizeof(GameSetting) == 0x18, "TES3::GameSetting failed size validation");
}
