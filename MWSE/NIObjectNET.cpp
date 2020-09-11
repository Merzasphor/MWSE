#include "NIObjectNET.h"

#include "NIAVObject.h"
#include "NIExtraData.h"
#include "NINode.h"

#include "TES3Reference.h"

#include "StringUtil.h"

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

	const char* ObjectNET::getName() const {
		return this->name;
	}

	void ObjectNET::setName(const char* name) {
		NI_ObjectNET_setName(this, name);
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

	bool ObjectNET::hasStringDataStartingWithValue(const char* value) const {
		return getStringDataStartingWithValue(value) != nullptr;
	}

	TES3::Reference* ObjectNET::getTes3Reference(bool searchParents) {
		for (auto ed = extraData; ed; ed = ed->next) {
			if (ed->isOfType(RTTIStaticPtr::TES3ObjectExtraData)) {
				return static_cast<Tes3ExtraData*>(ed)->reference;
			}
		}

		if (searchParents && isInstanceOfType(RTTIStaticPtr::NiAVObject) && static_cast<AVObject*>(this)->parentNode) {
			return static_cast<AVObject*>(this)->parentNode->getTes3Reference(true);
		}

		return nullptr;
	}

	TES3::Reference* ObjectNET::getTes3Reference_lua(sol::optional<bool> searchParents) {
		return getTes3Reference(searchParents.value_or(false));
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ObjectNET)

