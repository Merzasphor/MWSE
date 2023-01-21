#pragma once

#include "NIObjectNET.h"

#include "NIBoundingBox.h"
#include "NILinkedList.h"
#include "NIProperty.h"
#include "NITransform.h"

namespace NI {
	struct ObjectVelocities {
		Vector3 localVelocity;
		Vector3 worldVelocity;
	};

	struct AVObject_vTable : Object_vTable {
		void(__thiscall* updateControllers)(AVObject*, float); // 0x2C
		void(__thiscall* applyTransform)(AVObject*, Matrix33*, Vector3*, bool); // 0x30
		Bound* (__thiscall* getWorldBound)(AVObject*); // 0x34
		void(__thiscall* createWorldVertices)(AVObject*); // 0x38
		void(__thiscall* updateWorldVertices)(AVObject*); // 0x3C
		void(__thiscall* destroyWorldVertices)(AVObject*); // 0x40
		void(__thiscall* createWorldNormals)(AVObject*); // 0x44
		void(__thiscall* updateWorldNormals)(AVObject*); // 0x48
		void(__thiscall* destroyWorldNormals)(AVObject*); // 0x4C
		void(__thiscall* setAppCulled)(AVObject*, bool); // 0x50
		bool(__thiscall* getAppCulled)(const AVObject*); // 0x54
		void(__thiscall* setPropagationMode)(AVObject*, int); // 0x58
		AVObject* (__thiscall* getObjectByName)(AVObject*, const char*); // 0x5C
		void(__thiscall* updateDownwardPass)(AVObject*, float, bool, bool); // 0x60
		bool(__thiscall* isVisualObject)(AVObject*); // 0x64
		void(__thiscall* updatePropertiesDownward)(AVObject*, void*); // 0x68
		void(__thiscall* updateEffectsDownward)(AVObject*, void*); // 0x6C
		void* (__thiscall* getPropertyState)(AVObject*, void**); // 0x70
		void* (__thiscall* getEffectsState)(AVObject*, void**); // 0x74
		void(__thiscall* display)(AVObject*, Camera*); // 0x78
		void(__thiscall* updateCollisionData)(AVObject*); // 0x7C
		bool(__thiscall* testCollisions)(AVObject*, float, void*, void*); // 0x80
		int(__thiscall* findCollisions)(AVObject*, float, void*, void*); // 0x84
		bool(__thiscall* findIntersections)(AVObject*, Vector3*, Vector3*, Pick*); // 0x88
		void(__thiscall* updateWorldData)(AVObject*); // 0x8C
		void(__thiscall* updateWorldBound)(AVObject*); // 0x90
	};
	static_assert(sizeof(AVObject_vTable) == 0x94, "NI::AVObject's vtable failed size validation");

	struct AVObject : ObjectNET {
		unsigned short flags; // 0x14
		short pad_16;
		Node* parentNode; // 0x18
		Vector3 worldBoundOrigin; // 0x1C
		float worldBoundRadius; // 0x28
		Matrix33* localRotation; // 0x2C
		Vector3 localTranslate; // 0x30
		float localScale; // 0x3C
		Transform worldTransform; // 0x40
		ObjectVelocities* velocities; // 0x74
		void* modelABV; // 0x78
		void* worldABV; // 0x7C
		int(__cdecl* collideCallback)(void*); // 0x80
		void* collideCallbackUserData; // 0x84
		PropertyLinkedList propertyNode; // 0x88

		//
		// vTable wrappers.
		//

		Vector3 getLocalVelocity() const;
		void setLocalVelocity(Vector3*);

		AVObject* getObjectByName(const char*);

		template <typename T>
		T* getObjectByNameAndType(const char* name) {
			return static_cast<T*>(vTable.asAVObject->getObjectByName(this, name));
		}

		bool getAppCulled() const;
		void setAppCulled(bool culled);

		void createWorldVertices();
		void updateWorldVertices();
		void createWorldNormals();
		void updateWorldNormals();
		void updateWorldDeforms();
		void updateWorldBound();

		//
		// Other related this-call functions.
		//

		void update(float fTime = 0.0f, bool bUpdateControllers = false, bool bUpdateBounds = true);
		void updateEffects();
		void updateProperties();
		Matrix33* getLocalRotationMatrix() const;
		void setLocalRotationMatrix(const Matrix33* matrix);

		void attachProperty(Property* property);
		Pointer<Property> detachPropertyByType(PropertyType type);
#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		sol::table detachAllProperties_lua(sol::this_state ts);
#endif

		//
		// Custom functions.
		//

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		std::shared_ptr<TES3::BoundingBox> createBoundingBox_lua() const;
#endif

		Transform getLocalTransform() const;
		float getLowestVertexZ() const;

		void clearTransforms();
		void copyTransforms(const AVObject* from);
		void copyTransforms(const Transform* from);

		Pointer<Property> getProperty(PropertyType type) const;
		Pointer<AlphaProperty> getAlphaProperty() const;
		void setAlphaProperty(std::optional<AlphaProperty*> prop);
		Pointer<FogProperty> getFogProperty() const;
		void setFogProperty(std::optional<FogProperty*> prop);
		Pointer<MaterialProperty> getMaterialProperty() const;
		void setMaterialProperty(std::optional<MaterialProperty*> prop);
		Pointer<StencilProperty> getStencilProperty() const;
		void setStencilProperty(std::optional<StencilProperty*> prop);
		Pointer<TexturingProperty> getTexturingProperty() const;
		void setTexturingProperty(std::optional<TexturingProperty*> prop);
		Pointer<VertexColorProperty> getVertexColorProperty() const;
		void setVertexColorProperty(std::optional<VertexColorProperty*> prop);
		Pointer<ZBufferProperty> getZBufferProperty() const;
		void setZBufferProperty(std::optional<ZBufferProperty*> prop);

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
		void update_lua(sol::optional<sol::table> args);
#endif

	};
	static_assert(sizeof(AVObject) == 0x90, "NI::AVObject failed size validation");

	void __cdecl CalculateBounds(const AVObject* object, Vector3& out_min, Vector3& out_max, const Vector3& translation, const Matrix33& rotation, const float& scale);

	void __cdecl VerifyWorldVertices(const AVObject* object);
}

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
MWSE_SOL_CUSTOMIZED_PUSHER_DECLARE_NI(NI::AVObject)
#endif
