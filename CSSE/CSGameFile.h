#pragma once

namespace se::cs {
	struct GameFile {
		unsigned int unknown_0x0;
		unsigned int unknown_0x4;
		unsigned int unknown_0x8;
		char fileName[260];
		char filePath[260];
		// ...

		void setToLoadFlag(bool state);
	};
}
