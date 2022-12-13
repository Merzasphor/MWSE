#include "DialogRenderWindow.h"

#include "MathUtil.h"
#include "MemoryUtil.h"
#include "WindowsUtil.h"

#include "NINode.h"

#include "CSReference.h"

namespace se::cs::dialog::render_window {
	using namespace se::windows;

	//
	// Patch: Use world rotation values unless ALT is held.
	//
	
	// TODO: Move to real definition file.
	struct ReferenceTransformationAttachment {
		NI::Vector3 orientation;
		NI::Vector3 position;
	};

	// TODO: Move to real definition file.
	struct TranslationData {
		enum class RotationAxis : unsigned int {
			X = 1,
			Z = 2,
			Y = 3,
		};
		struct Target {
			Reference* reference; // 0x0
			Target* previous; // 0x4
			Target* next; // 0x8
		};
		Target* firstTarget; // 0x0
		unsigned int numberOfTargets; // 0x4
		NI::Vector3 position; // 0x8
		void* unknown_0x14;
	};

	const auto TES3_CS_OriginalRotationLogic = reinterpret_cast<bool(__cdecl*)(void*, TranslationData::Target*, int, TranslationData::RotationAxis)>(0x4652D0);
	bool __cdecl Patch_ReplaceRotationLogic(void* unknown1, TranslationData::Target* firstTarget, int relativeMouseDelta, TranslationData::RotationAxis rotationAxis) {
		// Allow holding ALT modifier to do vanilla behavior.
		if (isKeyDown(VK_MENU)) {
			return TES3_CS_OriginalRotationLogic(unknown1, firstTarget, relativeMouseDelta, rotationAxis);
		}

		if (relativeMouseDelta == 0) {
			return false;
		}

		auto data = se::memory::MemAccess<TranslationData*>::Get(0x6CE968);

		auto rotationSpeed = se::memory::MemAccess<float>::Get(0x6CE9B0);
		auto rotationFlags = se::memory::MemAccess<BYTE>::Get(0x6CE9A4);

		float x = 0.0f;
		float y = 0.0f;
		float z = 0.0f;

		if (!isKeyDown('X') && !isKeyDown('Y')) {
			rotationAxis = TranslationData::RotationAxis::Z;
		}

		switch (rotationAxis) {
		case TranslationData::RotationAxis::X:
			x += relativeMouseDelta * rotationSpeed * 0.1f;
			break;
		case TranslationData::RotationAxis::Y:
			y += relativeMouseDelta * rotationSpeed * 0.1f;
			break;
		case TranslationData::RotationAxis::Z:
			z += relativeMouseDelta * rotationSpeed * 0.1f;
			break;
		}

		bool isSnapping = (rotationFlags & 2) != 0;
		if (isSnapping) {
			const auto snapAngleInRadians = se::math::degreesToRadians(se::memory::MemAccess<int>::Get(0x6CE9AC));
			if (snapAngleInRadians != 0.0f) {
				x = std::roundf(x / snapAngleInRadians) * snapAngleInRadians;
				y = std::roundf(y / snapAngleInRadians) * snapAngleInRadians;
				z = std::roundf(z / snapAngleInRadians) * snapAngleInRadians;
			}
		}

		se::math::standardizeAngleRadians(x);
		se::math::standardizeAngleRadians(y);
		se::math::standardizeAngleRadians(z);

		// Seems to crash when performing an undo if you don't set this vector.
		auto& undoRotation = *reinterpret_cast<NI::Vector3*>(0x6CF760);
		undoRotation.x = x;
		undoRotation.y = y;
		undoRotation.z = z;

		// Due to snapping these may have been set to 0, in which case no need to do anything else.
		if (x == 0.0f && y == 0.0f && z == 0.0f) {
			return 0;
		}

		NI::Matrix33 userRotation;
		userRotation.fromEulerXYZ(x, y, z);

		for (auto target = data->firstTarget; target; target = target->next) {
			auto reference = target->reference;

			reinterpret_cast<void(__thiscall*)(Reference*)>(0x4026E4)(reference);
			reinterpret_cast<void(__thiscall*)(se::cs::BaseObject*, bool)>(0x4019E7)(reference->baseObject, true);

			// Disallow XY rotations on actors and northmarkers.
			auto doRotations = true;
			if (rotationAxis != TranslationData::RotationAxis::Z) {
				switch (reference->baseObject->objectType) {
				case ObjectType::Creature:
				case ObjectType::LeveledCreature:
				case ObjectType::NPC:
					doRotations = false;
					break;
				case ObjectType::Static:
					if (reference->baseObject == se::memory::MemAccess<se::cs::BaseObject*>::Get(0x6D566C)) {
						doRotations = false;
						break;
					}
				}
			}

			if (doRotations) {
				auto& oldRotation = *reference->sceneNode->localRotation;
				auto newRotation = userRotation * oldRotation;

				newRotation.toEulerXYZ(&reference->yetAnotherOrientation);
				se::math::standardizeAngleRadians(reference->yetAnotherOrientation.x);
				se::math::standardizeAngleRadians(reference->yetAnotherOrientation.y);
				se::math::standardizeAngleRadians(reference->yetAnotherOrientation.z);
				reference->orientationNonAttached = reference->yetAnotherOrientation;

				reference->sceneNode->setLocalRotationMatrix(&newRotation);
			}

			// Rotate positions.
			if (data->numberOfTargets > 1) {
				auto p = reference->position - data->position;
				reference->position = (userRotation * p) + data->position;
				reference->sceneNode->localTranslate = reference->position;
			}

			reference->sceneNode->update(0.0f, true, true);
		}

		return true;
	}

	//
	// Patch: Allow custom markers to be toggled.
	//

	static std::unordered_map<Object*, bool> validEditorMarkers;

	void SetCullOnTriEditorMarkers(NI::AVObject* object, bool cull) {
		if (object->isInstanceOfType(NI::RTTIStaticPtr::NiNode)) {
			for (auto& child : static_cast<NI::Node*>(object)->children) {
				if (child) {
					SetCullOnTriEditorMarkers(child, cull);
				}
			}
		}
		else if (object->name) {
			if (_strnicmp(object->name, "Tri EditorMarker", 16) == 0) {
				object->setAppCulled(cull);
			}
		}
	}

	const auto TES3_Object_IsMarker = reinterpret_cast<bool(__thiscall*)(se::cs::BaseObject*)>(0x549B20);
	void __fastcall PatchEditorMarkers(Reference* reference, bool cull) {
		if (reference->sceneNode == nullptr) {
			return;
		}

		if (TES3_Object_IsMarker(reference->baseObject)) {
			reference->sceneNode->setAppCulled(cull);
		}
		else if (reference->sceneNode->hasStringDataWithValue("MRK")) {
			SetCullOnTriEditorMarkers(reference->sceneNode, cull);

			auto editorMarker = reference->sceneNode->getObjectByName("EditorMarker");
			if (editorMarker) {
				editorMarker->setAppCulled(cull);
			}
		}
	}

	__declspec(naked) void PatchEditorMarkers_Setup() {
		__asm {
			mov edx, [esp + 0x18 + 0x4]
		}
	}
	constexpr auto PatchEditorMarkers_Setup_Size = 0x4u;

	//
	// Patch: When hiding objects (Shift+C) in terrain editing mode (H), do not hide the terrain editing circle.
	//

	void __fastcall PatchAddBlankTexturingProperty(NI::LinkedList<NI::Property*>* properties, DWORD _EDX_, NI::Property* prop) {
		const auto avObject = memory::getMainStructureFromOffset<NI::AVObject>(properties, offsetof(NI::AVObject, propertyNode));
		
		// Add existing property.
		avObject->attachProperty(prop);

		// Add an empty texturing property.
		auto texturingProp = new NI::TexturingProperty();
		avObject->attachProperty(texturingProp);

		int x = 4;
	}

	void __fastcall PatchFixMaterialPropertyColors(NI::LinkedList<NI::Property*>* properties, DWORD _EDX_, NI::MaterialProperty* prop) {
		const auto color = NI::Color(1.0f, 0.0f, 0.0f);
		prop->ambient = color;
		prop->diffuse = color;
		prop->specular = color;
		prop->emissive = color;

		const auto avObject = memory::getMainStructureFromOffset<NI::AVObject>(properties, offsetof(NI::AVObject, propertyNode));
		avObject->attachProperty(prop);
	}

	//
	//
	//

	void installPatches() {
		using namespace memory;

		// Patch: Use world rotation values.
		genJumpEnforced(0x403D41, 0x4652D0, reinterpret_cast<DWORD>(Patch_ReplaceRotationLogic));

		// Patch: Custom marker toggling code.
		writePatchCodeUnprotected(0x49E932, (BYTE*)PatchEditorMarkers_Setup, PatchEditorMarkers_Setup_Size);
		genCallUnprotected(0x49E932 + PatchEditorMarkers_Setup_Size, reinterpret_cast<DWORD>(PatchEditorMarkers), 0x49E94D - 0x49E932 - PatchEditorMarkers_Setup_Size);

		// Patch: When hiding objects (Shift+C) in terrain editing mode (H), do not hide the terrain editing circle.
		writeDoubleWordEnforced(0x45F166 + 0x2, 0x12C, 0x134);
		writeDoubleWordEnforced(0x45F39C + 0x2, 0x12C, 0x134);
		writeDoubleWordEnforced(0x45F719 + 0x2, 0x12C, 0x134);
		genCallEnforced(0x45F4ED, 0x4015A0, reinterpret_cast<DWORD>(PatchFixMaterialPropertyColors));
		genCallEnforced(0x45F626, 0x4015A0, reinterpret_cast<DWORD>(PatchAddBlankTexturingProperty));
	}
}