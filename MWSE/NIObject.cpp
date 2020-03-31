#include "NIObject.h"

#include "NIDefines.h"

#include "NIRTTI.h"
#include "NIStream.h"

#include <cstring>

#include "TES3Util.h"

#include "sol.hpp"

#include <unordered_map>
#include <mutex>

#include "NIAmbientLight.h"
#include "NIAVObject.h"
#include "NICamera.h"
#include "NICollisionSwitch.h"
#include "NIDirectionalLight.h"
#include "NINode.h"
#include "NIObjectNET.h"
#include "NIPixelData.h"
#include "NIPointLight.h"
#include "NIProperty.h"
#include "NISourceTexture.h"
#include "NISpotLight.h"
#include "NISwitchNode.h"
#include "NITriShape.h"

#include "LuaObjectInvalidatedEvent.h"

#include "LuaManager.h"

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

	RTTI * Object::getRunTimeTypeInformation() const {
		return vTable.asObject->getRTTI(this);
	}

	Object * Object::createClone() {
		return reinterpret_cast<Object * (__thiscall *)(Object *)>(0x6E9910)(this);
	}

	void Object::release() {
		reinterpret_cast<void(__thiscall *)(Object *)>(0x404630)(this);
	}

	bool Object::isOfType(const RTTI* type) const {
		return (vTable.asObject->getRTTI(this) == type);
	}

	bool Object::isInstanceOfType(const RTTI* type) const {
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

	static std::unordered_map<const Object*, sol::object> niObjectCache;
	static std::mutex niObjectCacheMutex;

	sol::object Object::getOrCreateLuaObject(lua_State* L, Object* object) {
		if (object == nullptr) {
			return sol::nil;
		}

		niObjectCacheMutex.lock();

		auto cacheHit = niObjectCache.find(object);
		if (cacheHit != niObjectCache.end()) {
			auto result = cacheHit->second;
			niObjectCacheMutex.unlock();
			return result;
		}

		niObjectCacheMutex.unlock();

		// Loop through RTTI information until we find a type we like.
		auto currentRTTI = object->getRunTimeTypeInformation();
		sol::object ref = sol::nil;
		while (currentRTTI != nullptr && ref == sol::nil) {
			switch ((uintptr_t)currentRTTI) {
			case NI::RTTIStaticPtr::NiAlphaProperty:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::AlphaProperty*>(object)));
				break;
			case NI::RTTIStaticPtr::NiAmbientLight:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::AmbientLight*>(object)));
				break;
			case NI::RTTIStaticPtr::NiAVObject:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::AVObject*>(object)));
				break;
			case NI::RTTIStaticPtr::NiCamera:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::Camera*>(object)));
				break;
			case NI::RTTIStaticPtr::NiCollisionSwitch:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::CollisionSwitch*>(object)));
				break;
			case NI::RTTIStaticPtr::NiDirectionalLight:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::DirectionalLight*>(object)));
				break;
			case NI::RTTIStaticPtr::NiFogProperty:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::FogProperty*>(object)));
				break;
			case NI::RTTIStaticPtr::NiMaterialProperty:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::MaterialProperty*>(object)));
				break;
			case NI::RTTIStaticPtr::NiNode:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::Node*>(object)));
				break;
			case NI::RTTIStaticPtr::NiObject:
				ref = sol::make_object_userdata(L, NI::Pointer(object));
				break;
			case NI::RTTIStaticPtr::NiObjectNET:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::ObjectNET*>(object)));
				break;
			case NI::RTTIStaticPtr::NiPixelData:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::PixelData*>(object)));
				break;
			case NI::RTTIStaticPtr::NiPointLight:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::PointLight*>(object)));
				break;
			case NI::RTTIStaticPtr::NiSourceTexture:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::SourceTexture*>(object)));
				break;
			case NI::RTTIStaticPtr::NiSpotLight:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::SpotLight*>(object)));
				break;
			case NI::RTTIStaticPtr::NiStencilProperty:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::StencilProperty*>(object)));
				break;
			case NI::RTTIStaticPtr::NiSwitchNode:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::SwitchNode*>(object)));
				break;
			case NI::RTTIStaticPtr::NiTexturingProperty:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::TexturingProperty*>(object)));
				break;
			case NI::RTTIStaticPtr::NiTriShape:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::TriShape*>(object)));
				break;
			case NI::RTTIStaticPtr::NiVertexColorProperty:
				ref = sol::make_object_userdata(L, NI::Pointer(static_cast<NI::VertexColorProperty*>(object)));
				break;
			}

			currentRTTI = currentRTTI->baseRTTI;
		}

		if (ref != sol::nil) {
			niObjectCacheMutex.lock();
			niObjectCache[object] = ref;
			niObjectCacheMutex.unlock();
		}

		return ref;
	}

	int Object::pushCachedLuaObject(lua_State* L, Object* object) {
		return getOrCreateLuaObject(L, object).push(L);
	}

	void Object::clearCachedLuaObject(const Object* object) {
		if (!niObjectCache.empty()) {
			niObjectCacheMutex.lock();

			// Clear any events that make use of this object.
			auto it = niObjectCache.find(object);
			if (it != niObjectCache.end()) {
				// Let people know that this object is invalidated.
				mwse::lua::LuaManager::getInstance().getThreadSafeStateHandle().triggerEvent(new mwse::lua::event::ObjectInvalidatedEvent(it->second));

				// Clear any events that make use of this object.
				mwse::lua::event::clearObjectFilter(it->second);

				// Remove it from the cache.
				niObjectCache.erase(it);
			}

			niObjectCacheMutex.unlock();
		}
	}

	void Object::clearCachedLuaObjects() {
		niObjectCacheMutex.lock();
		niObjectCache.clear();
		niObjectCacheMutex.unlock();
	}
}

MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::AlphaProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::AmbientLight);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::AVObject);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::Camera);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::CollisionSwitch);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::DirectionalLight);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::FogProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::MaterialProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::Node);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::Object);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::ObjectNET);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::PixelData);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::PointLight);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::SourceTexture);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::SpotLight);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::StencilProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::SwitchNode);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::TexturingProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::TriShape);
MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(NI::VertexColorProperty);
