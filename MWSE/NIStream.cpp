#include "NIStream.h"

#include "NIBinaryStream.h"

#include "MemoryUtil.h"

namespace NI {
	//
	// NiStream::LoadingObject
	//

	void* Stream::LoadingObject::operator new(size_t size) {
		return mwse::tes3::_new<LoadingObject>();
	}

	void Stream::LoadingObject::operator delete(void* block) {
		mwse::tes3::_delete(block);
	}

	Stream::LoadingObject::LoadingObject() {
		vTable = reinterpret_cast<VirtualTable*>(0x74F36C);
		unknown_0x4 = 0;
		unknown_0x8 = 0;
		linkId = -1;
	}

	//
	// NiStream
	//

	const auto NI_Stream_ctor = reinterpret_cast<void(__thiscall*)(Stream*)>(0x6C2B60);
	Stream::Stream() {
		NI_Stream_ctor(this);
	}

	const auto NI_Stream_dtor = reinterpret_cast<void(__thiscall*)(Stream*)>(0x6C2DD0);
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

	void Stream::readString(char** string) {
		_readString(this, string);
	}

	void Stream::writeString(const char* string) {
		_writeString(this, string);
	}

	Object* Stream::getLinkObject(int id) const {
		return _getLinkObject(this, id);
	}

	int Stream::getLinkId(const Object* object) const {
		return _getObjectIndex(this, object);
	}

	void Stream::readLinkId(unsigned int id) {
		inStream->read(&currentlyLoading->linkId);
	}

	void Stream::writeLinkId(Object* object) {
		auto linkId = getLinkId(object);
		outStream->write(&linkId);
	}

	Object* Stream::getCopiedObject(const Object* existing) {
		const auto recentlyCopiedObjects = *reinterpret_cast<TES3::HashMap<const Object*, Object*>**>(0x7DE768);
		if (auto result = recentlyCopiedObjects->getNode(existing)) {
			return result->value;
		}
		return nullptr;
	}

	void __cdecl Stream::registerLoader(const char* className, CreateFunction createObjectFunction) {
		_registerLoader(className, createObjectFunction);
	}

	std::string Stream::readStdString() {
		char* string = nullptr;
		readString(&string);

		std::string out_string = string;

		mwse::tes3::_delete(string);

		return std::move(out_string);
	}
}
