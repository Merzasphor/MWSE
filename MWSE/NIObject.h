#pragma once

#include "NIDefines.h"

#include "sol_forward.hpp"

namespace NI {
	struct Object {
		union {
			AVObject_vTable * asAVObject;
			DynamicEffect_vTable * asDynamicEffect;
			Geometry_vTable * asGeometry;
			GeometryData_vTable * asGeometryData;
			Node_vTable * asNode;
			Object_vTable * asObject;
			Property_vTable * asProperty;
			Renderer_vTable * asRenderer;
			SourceTexture_vTable * asSourceTexture;
			Texture_vTable * asTexture;
			TriBasedGeometryData_vTable* asTriBasedGeometryData;
			TriShape_vTable * asTriShape;
		} vTable; // 0x0
		int refCount; // 0x4

		//
		// Basic operators.
		//

		Object();
		~Object();

		static void *operator new(size_t size);
		static void operator delete(void *block);

		//
		// vTable Wrappers
		//

		RTTI * getRunTimeTypeInformation() const;

		Object * createClone();

		//
		// Other related this-call functions.
		//

		void release();

		// Slow, but name-based lookup of nodes.
		bool isOfType(const RTTI*) const;
		bool isOfType(uintptr_t rtti) const { return isOfType(reinterpret_cast<RTTI*>(rtti)); }
		bool isInstanceOfType(const RTTI*) const;
		bool isInstanceOfType(uintptr_t rtti) const { return isInstanceOfType(reinterpret_cast<RTTI*>(rtti)); }

		//
		// Custom functions.
		//

		// Storage for cached userdata.
		static sol::object getOrCreateLuaObject(lua_State* L, const Object* object);
		static int pushCachedLuaObject(lua_State* L, const Object* object);
		static void clearCachedLuaObject(const Object* object);
		static void clearCachedLuaObjects();

		//
		// Custom functions.
		//

		bool saveBinary(const char* filename);

	};
	static_assert(sizeof(Object) == 0x8, "NI::Object failed size validation");

	struct Object_vTable {
		void (__thiscall * destructor)(Object*, int); // 0x0
		RTTI * (__thiscall * getRTTI)(const Object*); // 0x4
		Object * (__thiscall * createClone)(Object*); // 0x8
		Object * (__thiscall * loadBinary)(Object*, Stream*); // 0xC
		void * linkObject; // 0x10
		void * registerStreamables; // 0x14
		void (__thiscall* saveBinary)(Object*, Stream*); // 0x18
		bool (__thiscall * isEqual)(Object*, Object*); // 0x1C
		void * getViewerStrings; // 0x20
		void * addViewerStrings; // 0x24
		void * unknown_0x28; // 0x28
	};
	static_assert(sizeof(Object_vTable) == 0x2C, "NI::Object's vtable failed size validation");
}

#define MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(T)\
int sol_lua_push(sol::types<T*>, lua_State* L, const T* object);\
int sol_lua_push(sol::types<T>, lua_State* L, const T& object);
#define MWSE_SOL_CACHE_NIOBJECT_TYPE_BODY(T)\
int sol_lua_push(sol::types<T*>, lua_State* L, const T* object) { return T::pushCachedLuaObject(L, object); }\
int sol_lua_push(sol::types<T>, lua_State* L, const T& object) { return T::pushCachedLuaObject(L, &object); }

MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::AlphaProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::AmbientLight);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::AVObject);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::Camera);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::CollisionSwitch);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::DirectionalLight);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::FogProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::MaterialProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::Node);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::Object);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::ObjectNET);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::PixelData);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::PointLight);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::SourceTexture);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::SpotLight);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::StencilProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::SwitchNode);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::TexturingProperty);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::TriShape);
MWSE_SOL_CACHE_NIOBJECT_TYPE_DEF(NI::VertexColorProperty);
