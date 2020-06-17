#include "NIObjectNET.h"

#include "NIAVObject.h"
#include "NIExtraData.h"
#include "NINode.h"

#include "TES3Reference.h"

#include "LuaUtil.h"

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

	sol::object ObjectNET::getTes3Reference_lua(sol::optional<bool> searchParents) {
		return mwse::lua::makeLuaObject(getTes3Reference(searchParents.value_or(false)));
	}
}
