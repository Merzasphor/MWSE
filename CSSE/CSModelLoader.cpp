#include "CSModelLoader.h"

namespace se::cs {
	NI::Node* ModelLoader::loadNIF(const char* path) {
		const auto ModelLoader_loadNIF = reinterpret_cast<NI::Node*(__thiscall*)(ModelLoader*, const char*)>(0x545E00);
		return ModelLoader_loadNIF(this, path);
	}
}
