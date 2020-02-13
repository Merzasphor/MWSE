#include "NIStream.h"

namespace NI {
	const auto NI_Stream_ctor = reinterpret_cast<void(__thiscall*)(Stream*)>(0x51AD20);
	Stream::Stream() {
		NI_Stream_ctor(this);
	}

	const auto NI_Stream_dtor = reinterpret_cast<void(__thiscall*)(Stream*)>(0x51AD60);
	Stream::~Stream() {
		NI_Stream_dtor(this);
	}

	const auto NI_Stream_load = reinterpret_cast<bool(__thiscall*)(Stream*, const char*)>(0x6C41D0);
	bool Stream::load(const char* path) {
		return NI_Stream_load(this, path);
	}

	const auto NI_Stream_save = reinterpret_cast<bool(__thiscall*)(Stream*, const char*)>(0x6C4710);
	bool Stream::save(const char* path) {
		return NI_Stream_save(this, path);
	}

	const auto NI_Stream_insertObject = reinterpret_cast<void(__thiscall*)(Stream*, Object*)>(0x6C2FD0);
	void Stream::insertObject(Object* object) {
		NI_Stream_insertObject(this, object);
	}
}
