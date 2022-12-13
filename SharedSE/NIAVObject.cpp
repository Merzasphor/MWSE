#include "NIAVObject.h"

#include "NIProperty.h"

#include "ExceptionUtil.h"
#include "MemoryUtil.h"

namespace NI {
	Vector3 AVObject::getLocalVelocity() const {
		if (velocities) {
			return velocities->localVelocity;
		}
		return Vector3{ 0, 0, 0 };
	}

	void AVObject::setLocalVelocity(Vector3* v) {
		if (velocities) {
			velocities->localVelocity = *v;
		}
		else {
			velocities = se::memory::_new<ObjectVelocities>();
			velocities->localVelocity = *v;
			velocities->worldVelocity = { 0, 0, 0 };
		}
	}

	AVObject* AVObject::getObjectByName(const char* name) {
		return vTable.asAVObject->getObjectByName(this, name);
	}

	bool AVObject::getAppCulled() {
		return vTable.asAVObject->getAppCulled(this);
	}

	void AVObject::setAppCulled(bool culled) {
		vTable.asAVObject->setAppCulled(this, culled);
	}

	void AVObject::update(float fTime, bool bUpdateControllers, bool bUpdateBounds) {
#if defined(SE_NI_AVOBJECT_FNADDR_UPDATE) && SE_NI_AVOBJECT_FNADDR_UPDATE > 0
		const auto NI_PropertyList_update = reinterpret_cast<void(__thiscall*)(AVObject*, float, int, int)>(SE_NI_AVOBJECT_FNADDR_UPDATE);
		NI_PropertyList_update(this, fTime, bUpdateControllers, bUpdateBounds);
#else
		throw not_implemented_exception();
#endif
	}

	void AVObject::updateEffects() {
#if defined(SE_NI_AVOBJECT_FNADDR_UPDATEEFFECTS) && SE_NI_AVOBJECT_FNADDR_UPDATEEFFECTS > 0
		const auto NI_PropertyList_updateEffects = reinterpret_cast<void(__thiscall*)(AVObject*)>(SE_NI_AVOBJECT_FNADDR_UPDATEEFFECTS);
		NI_PropertyList_updateEffects(this);
#else
		throw not_implemented_exception();
#endif
	}

	void AVObject::updateProperties() {
#if defined(SE_NI_AVOBJECT_FNADDR_UPDATEPROPERTIES) && SE_NI_AVOBJECT_FNADDR_UPDATEPROPERTIES > 0
		const auto NI_AVObject_updateProperties = reinterpret_cast<void(__thiscall*)(AVObject*)>(SE_NI_AVOBJECT_FNADDR_UPDATEPROPERTIES);
		NI_AVObject_updateProperties(this);
#else
		throw not_implemented_exception();
#endif
	}

	Matrix33* AVObject::getLocalRotationMatrix() const {
		return localRotation;
	}

	void AVObject::setLocalRotationMatrix(Matrix33* matrix) {
#if defined(SE_NI_AVOBJECT_FNADDR_SETLOCALROTATIONMATRIX) && SE_NI_AVOBJECT_FNADDR_SETLOCALROTATIONMATRIX > 0
		const auto NI_PropertyList_setLocalRotationMatrix = reinterpret_cast<void(__thiscall*)(AVObject*, Matrix33*)>(SE_NI_AVOBJECT_FNADDR_SETLOCALROTATIONMATRIX);
		NI_PropertyList_setLocalRotationMatrix(this, matrix);
#else
		throw not_implemented_exception();
#endif
	}

	void AVObject::attachProperty(Property* property) {
#if defined(SE_NI_AVOBJECT_FNADDR_ATTACHPROPERTY) && SE_NI_AVOBJECT_FNADDR_ATTACHPROPERTY > 0
		const auto NI_PropertyList_addHead = reinterpret_cast<void(__thiscall*)(PropertyLinkedList*, Pointer<Property>)>(SE_NI_AVOBJECT_FNADDR_ATTACHPROPERTY);
		NI_PropertyList_addHead(&propertyNode, property);
#else
		throw not_implemented_exception();
#endif
	}

	Pointer<Property> AVObject::detachPropertyByType(PropertyType type) {
#if defined(SE_NI_AVObject_FNADDR_DETACHPROPERTYBYTYPE) && SE_NI_AVObject_FNADDR_DETACHPROPERTYBYTYPE > 0
		const auto NI_AVObject_detachPropertyByType = reinterpret_cast<Pointer<Property> *(__thiscall*)(AVObject*, Pointer<Property>*, PropertyType)>(SE_NI_AVObject_FNADDR_DETACHPROPERTYBYTYPE);

		NI::Pointer<NI::Property> prop;
		NI_AVObject_detachPropertyByType(this, &prop, type);
		return prop;
#else
		throw not_implemented_exception();
#endif
	}

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
	sol::table AVObject::detachAllProperties_lua(sol::this_state ts) {
		sol::state_view state = ts;
		auto removedProperties = state.create_table();

		while (propertyNode.data) {
			auto removed = detachPropertyByType(propertyNode.data->getType());
			if (removed) {
				removedProperties.add(removed);
			}
		}

		return removedProperties;
	}

	const auto NI_CreateBoundingBoxForNode = reinterpret_cast<void(__cdecl*)(const AVObject*, TES3::Vector3*, TES3::Vector3*, const TES3::Vector3*, const Matrix33*, const float*)>(0x4EF410);
	std::shared_ptr<TES3::BoundingBox> AVObject::createBoundingBox_lua() const {
		constexpr auto min = std::numeric_limits<float>::min();
		constexpr auto max = std::numeric_limits<float>::max();
		auto bb = std::make_shared<TES3::BoundingBox>(max, max, max, min, min, min);
		float scale = localScale;
		NI_CreateBoundingBoxForNode(this, &bb->minimum, &bb->maximum, (const TES3::Vector3*)0x7DE6CC, (const Matrix33*)0x7DE664, &scale);
		return bb;
	}
#endif

	void AVObject::clearTransforms() {
		localScale = 1.0f;
		localTranslate.x = 0.0f;
		localTranslate.y = 0.0f;
		localTranslate.z = 0.0f;
		setLocalRotationMatrix(Matrix33::IdentityMatrix);
	}

	Pointer<Property> AVObject::getProperty(PropertyType type) const {
		auto propNode = &propertyNode;
		while (propNode && propNode->data) {
			if (propNode->data->getType() == type) {
				return propNode->data;
			}
			propNode = propNode->next;
		}
		return nullptr;
	}

	Pointer<AlphaProperty> AVObject::getAlphaProperty() const {
		return static_cast<AlphaProperty*>(getProperty(PropertyType::Alpha).get());
	}

	void AVObject::setAlphaProperty(std::optional<AlphaProperty*> prop) {
		detachPropertyByType(PropertyType::Alpha);
		if (prop) {
			attachProperty(prop.value());
		}
	}

	Pointer<FogProperty> AVObject::getFogProperty() const {
		return static_cast<FogProperty*>(getProperty(PropertyType::Fog).get());
	}

	void AVObject::setFogProperty(std::optional<FogProperty*> prop) {
		detachPropertyByType(PropertyType::Fog);
		if (prop) {
			attachProperty(prop.value());
		}
	}

	Pointer<MaterialProperty> AVObject::getMaterialProperty() const {
		return static_cast<MaterialProperty*>(getProperty(PropertyType::Material).get());
	}

	void AVObject::setMaterialProperty(std::optional<MaterialProperty*> prop) {
		detachPropertyByType(PropertyType::Material);
		if (prop) {
			attachProperty(prop.value());
		}
	}

	Pointer<StencilProperty> AVObject::getStencilProperty() const {
		return static_cast<StencilProperty*>(getProperty(PropertyType::Stencil).get());
	}

	void AVObject::setStencilProperty(std::optional<StencilProperty*> prop) {
		detachPropertyByType(PropertyType::Stencil);
		if (prop) {
			attachProperty(prop.value());
		}
	}

	Pointer<TexturingProperty> AVObject::getTexturingProperty() const {
		return static_cast<TexturingProperty*>(getProperty(PropertyType::Texturing).get());
	}

	void AVObject::setTexturingProperty(std::optional<TexturingProperty*> prop) {
		detachPropertyByType(PropertyType::Texturing);
		if (prop) {
			attachProperty(prop.value());
		}
	}

	Pointer<VertexColorProperty> AVObject::getVertexColorProperty() const {
		return static_cast<VertexColorProperty*>(getProperty(PropertyType::VertexColor).get());
	}

	void AVObject::setVertexColorProperty(std::optional<VertexColorProperty*> prop) {
		detachPropertyByType(PropertyType::VertexColor);
		if (prop) {
			attachProperty(prop.value());
		}
	}

	Pointer<ZBufferProperty> AVObject::getZBufferProperty() const {
		return static_cast<ZBufferProperty*>(getProperty(PropertyType::ZBuffer).get());
	}

	void AVObject::setZBufferProperty(std::optional<ZBufferProperty*> prop) {
		detachPropertyByType(PropertyType::ZBuffer);
		if (prop) {
			attachProperty(prop.value());
		}
	}

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
	void AVObject::update_lua(sol::optional<sol::table> args) {
		if (args) {
			auto values = args.value();
			float time = values.get_or("time", 0.0f);
			bool updateControllers = values.get_or("controllers", false);
			bool updateBounds = values.get_or("bounds", true);

			update(time, updateControllers, updateBounds);
		}
		else {
			update();
		}
	}
#endif
}

#if defined(SE_USE_LUA) && SE_USE_LUA == 1
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::AVObject)
#endif
