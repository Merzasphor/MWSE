#include "NIObject.h"

#include "NIDefines.h"

#include "NIRTTI.h"
#include "NIStream.h"

#include "MemoryUtil.h"

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

	sol::object Object::getOrCreateLuaObject(lua_State* L) {
		if (this == nullptr) {
			return sol::nil;
		}

		niObjectCacheMutex.lock();

		auto cacheHit = niObjectCache.find(this);
		if (cacheHit != niObjectCache.end()) {
			auto result = cacheHit->second;
			niObjectCacheMutex.unlock();
			return result;
		}

		niObjectCacheMutex.unlock();

		// Loop through RTTI information until we find a type we like.
		auto currentRTTI = getRunTimeTypeInformation();
		sol::object ref = sol::nil;
		while (currentRTTI != nullptr && ref == sol::nil) {
			switch ((uintptr_t)currentRTTI) {
			case RTTIStaticPtr::NiAlphaProperty:
				ref = sol::make_object_userdata(L, Pointer(static_cast<AlphaProperty*>(this)));
				break;
			case RTTIStaticPtr::NiAmbientLight:
				ref = sol::make_object_userdata(L, Pointer(static_cast<AmbientLight*>(this)));
				break;
			case RTTIStaticPtr::NiAVObject:
				ref = sol::make_object_userdata(L, Pointer(static_cast<AVObject*>(this)));
				break;
			case RTTIStaticPtr::NiCamera:
				ref = sol::make_object_userdata(L, Pointer(static_cast<Camera*>(this)));
				break;
			case RTTIStaticPtr::NiCollisionSwitch:
				ref = sol::make_object_userdata(L, Pointer(static_cast<CollisionSwitch*>(this)));
				break;
			case RTTIStaticPtr::NiDirectionalLight:
				ref = sol::make_object_userdata(L, Pointer(static_cast<DirectionalLight*>(this)));
				break;
			case RTTIStaticPtr::NiFogProperty:
				ref = sol::make_object_userdata(L, Pointer(static_cast<FogProperty*>(this)));
				break;
			case RTTIStaticPtr::NiMaterialProperty:
				ref = sol::make_object_userdata(L, Pointer(static_cast<MaterialProperty*>(this)));
				break;
			case RTTIStaticPtr::NiNode:
				ref = sol::make_object(L, Pointer(static_cast<Node*>(this)));
				break;
			case RTTIStaticPtr::NiObject:
				ref = sol::make_object_userdata(L, Pointer(this));
				break;
			case RTTIStaticPtr::NiObjectNET:
				ref = sol::make_object_userdata(L, Pointer(static_cast<ObjectNET*>(this)));
				break;
			case RTTIStaticPtr::NiPixelData:
				ref = sol::make_object_userdata(L, Pointer(static_cast<PixelData*>(this)));
				break;
			case RTTIStaticPtr::NiPointLight:
				ref = sol::make_object_userdata(L, Pointer(static_cast<PointLight*>(this)));
				break;
			case RTTIStaticPtr::NiSourceTexture:
				ref = sol::make_object_userdata(L, Pointer(static_cast<SourceTexture*>(this)));
				break;
			case RTTIStaticPtr::NiSpotLight:
				ref = sol::make_object_userdata(L, Pointer(static_cast<SpotLight*>(this)));
				break;
			case RTTIStaticPtr::NiStencilProperty:
				ref = sol::make_object_userdata(L, Pointer(static_cast<StencilProperty*>(this)));
				break;
			case RTTIStaticPtr::NiSwitchNode:
				ref = sol::make_object_userdata(L, Pointer(static_cast<SwitchNode*>(this)));
				break;
			case RTTIStaticPtr::NiTexturingProperty:
				ref = sol::make_object_userdata(L, Pointer(static_cast<TexturingProperty*>(this)));
				break;
			case RTTIStaticPtr::NiTriShape:
				ref = sol::make_object_userdata(L, Pointer(static_cast<TriShape*>(this)));
				break;
			case RTTIStaticPtr::NiVertexColorProperty:
				ref = sol::make_object_userdata(L, Pointer(static_cast<VertexColorProperty*>(this)));
				break;
			}

			currentRTTI = currentRTTI->baseRTTI;
		}

		if (ref != sol::nil) {
			niObjectCacheMutex.lock();
			niObjectCache[this] = ref;
			niObjectCacheMutex.unlock();
		}

		return ref;
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

int sol_lua_push(sol::types<NI::Object>, lua_State* L, NI::Object& obj) {
	return obj.getOrCreateLuaObject(L).push(L);
}

int sol_lua_push(sol::types<NI::Object*>, lua_State* L, NI::Object* obj) {
	return obj->getOrCreateLuaObject(L).push(L);
}

int sol_lua_push(sol::types<NI::Pointer<NI::Object>>, lua_State* L, NI::Pointer<NI::Object>& obj) {
	return obj->getOrCreateLuaObject(L).push(L);
}

int sol_lua_push(sol::types<NI::Pointer<NI::Object>*>, lua_State* L, NI::Pointer<NI::Object>* obj) {
	return (*obj)->getOrCreateLuaObject(L).push(L);
}
