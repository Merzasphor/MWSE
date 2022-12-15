#pragma once

#include "NINode.h"

namespace se::cs {
	struct ModelLoader {
		void* nifs; // 0x0
		void* keyFrames; // 0x4

		NI::Node* loadNIF(const char* path);
	};
}
