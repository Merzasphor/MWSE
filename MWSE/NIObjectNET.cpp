#include "NIObjectNET.h"

#include "LuaUtil.h"

#include "StringUtil.h"

#include "NIExtraData.h"

namespace NI {
	const auto NI_ObjectNET_prependController = reinterpret_cast<void(__thiscall*)(const ObjectNET*, TimeController*)>(0x6EA3E0);
	const auto NI_ObjectNET_removeController = reinterpret_cast<void(__thiscall*)(const ObjectNET*, TimeController*)>(0x6EA450);
	const auto NI_ObjectNET_removeAllControllers = reinterpret_cast<void(__thiscall*)(const ObjectNET*)>(0x6EA5A0);

	const auto NI_ObjectNET_setName = reinterpret_cast<void(__thiscall*)(const ObjectNET*, const char *)>(0x6EA1A0);

	void ObjectNET::prependController(TimeController * controller) {
		NI_ObjectNET_prependController(this, controller);
	}

	void ObjectNET::removeController(TimeController * controller) {
		NI_ObjectNET_removeController(this, controller);
	}

	void ObjectNET::removeAllControllers() {
		NI_ObjectNET_removeAllControllers(this);
	}

	void ObjectNET::setName(const char* name) {
		NI_ObjectNET_setName(this, name);
	}

	sol::object ObjectNET::getExtraData_lua() const {
		return mwse::lua::makeLuaNiPointer(extraData);
	}

	StringExtraData* ObjectNET::getStringDataWithValue(const char* value) const {
		auto extra = extraData;
		while (extra) {
			if (extra->isInstanceOfType(NI::RTTIStaticPtr::NiStringExtraData)) {
				if (mwse::string::iequal(value, reinterpret_cast<NI::StringExtraData*>(extra)->string)) {
					return reinterpret_cast<NI::StringExtraData*>(extra);
				}
			}
			extra = extra->next;
		}
		return nullptr;
	}

	sol::object ObjectNET::getStringDataWithValue_lua(const char* value) const {
		return mwse::lua::makeLuaNiPointer(getStringDataWithValue(value));
	}

	bool ObjectNET::hasStringDataWithValue(const char* value) const {
		return getStringDataWithValue(value) != nullptr;
	}

	StringExtraData* ObjectNET::getStringDataStartingWithValue(const char* value) const {
		size_t maxCount = strlen(value);
		auto extra = extraData;
		while (extra) {
			if (extra->isInstanceOfType(NI::RTTIStaticPtr::NiStringExtraData)) {
				if (mwse::string::niequal(value, reinterpret_cast<NI::StringExtraData*>(extra)->string, maxCount)) {
					return reinterpret_cast<NI::StringExtraData*>(extra);
				}
			}
			extra = extra->next;
		}
		return nullptr;
	}

	sol::object ObjectNET::getStringDataStartingWithValue_lua(const char* value) const {
		return mwse::lua::makeLuaNiPointer(getStringDataStartingWithValue(value));
	}

	bool ObjectNET::hasStringDataStartingWithValue(const char* value) const {
		return getStringDataStartingWithValue(value) != nullptr;
	}

}
