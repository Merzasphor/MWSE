#include "NIObject.h"

#include "NIDefines.h"

#include "NIRTTI.h"
#include "NIStream.h"

#include <cstring>

#include "TES3Util.h"

namespace NI {
	const auto NI_Object_ctor = reinterpret_cast<Object * (__thiscall*)(Object *)>(0x6E98A0);
	Object::Object() {
		NI_Object_ctor(this);
	}

	const auto NI_Object_dtor = reinterpret_cast<Object * (__thiscall*)(Object *)>(0x6E98F0);
	Object::~Object() {
		NI_Object_dtor(this);
	}

	void * Object::operator new(size_t size) {
		return mwse::tes3::_new(size);
	}

	void Object::operator delete(void * address) {
		mwse::tes3::_delete(address);
	}

	RTTI * Object::getRunTimeTypeInformation() {
		return vTable.asObject->getRTTI(this);
	}

	Object * Object::createClone() {
		return reinterpret_cast<Object * (__thiscall *)(Object *)>(0x6E9910)(this);
	}

	void Object::release() {
		reinterpret_cast<void(__thiscall *)(Object *)>(0x404630)(this);
	}

	bool Object::isOfType(const RTTI* type) {
		return (vTable.asObject->getRTTI(this) == type);
	}

	bool Object::isInstanceOfType(const RTTI* type) {
		for (const RTTI* rtti = vTable.asObject->getRTTI(this); rtti; rtti = rtti->baseRTTI) {
			if (rtti == type) {
				return true;
			}
		}

		return false;
	}

	bool Object::saveBinary(const char* filename) {
		Stream stream;
		stream.insertObject(this);
		return stream.save(filename);
	}
}
