#pragma once

namespace TES3 {
	namespace AIBehavior {
		enum Behavior {
			AIBehaviour_Hello = 0x0,
			AIBehaviour_Idle = 0x2,
			AIBehaviour_Attack = 0x3,
			AIBehaviour_Avoid = 0x4,
			AIBehaviour_Flee = 0x6,
			AIBehaviour_Walk = 0x8,
			AIBehaviour_Greet = 0xC,
			AIBehaviour_Undecided = 0xFF,
		};
	}
}
