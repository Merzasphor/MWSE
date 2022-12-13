#include "DialogRenderWindow.h"

#include "MathUtil.h"
#include "MemoryUtil.h"
#include "WindowsUtil.h"

#include "NICamera.h"
#include "NINode.h"
#include "NIPick.h"

#include "CSLandTexture.h"
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

	struct NetImmerseInstance {
		struct VirtualTable {
			void* dtor; // 0x0
			void* setRegistryKey; // 0x4
			void* setWindowWidth; // 0x8
			void* setWindowHeight; // 0xC
			void* setBitDepth; // 0x10
			void* setBackBuffers; // 0x14
			void* setMultisampleEnable; // 0x18
			void* setMultisamples; // 0x1C
			void* setFullScreen; // 0x20
			void(__thiscall* setPixelShaderEnabled)(NetImmerseInstance*, bool); // 0x24
			void* setStencil; // 0x28
			void* setMipmap; // 0x2C
			void* setMipmapSkipLevel; // 0x30
			void* setHardwareTL; // 0x34
			void* setMultipass; // 0x38
			void* setVertexProcessing; // 0x3C
			void* setSwapEffect; // 0x40
			void* setRefreshRate; // 0x44
			void* setPresentInterval; // 0x48
			void* setAdapterID; // 0x4C
			void(__thiscall* setGamma)(NetImmerseInstance*, float); // 0x50
			void* readSettings; // 0x54
			void* writeSettings; // 0x58
			void* createRenderer; // 0x5C
			void* createRendererFromSettings; // 0x60
		};
		VirtualTable* vTable; // 0x0
		const char* ownerString; // 0x4
		int windowWidth; // 0x8
		int windowHeight; // 0xC
		int screenDepth; // 0x10
		int backBuffers; // 0x14
		int multiSamples; // 0x18
		bool fullscreen; // 0x1C
		bool stencil; // 0x1D
		bool mipmap; // 0x1E
		bool hardware; // 0x1F
		bool pixelShader; // 0x20
		bool multiPass; // 0x21
		bool screenShotsEnabled; // 0x22
		int vertexProcessing; // 0x24
		int swapEffect; // 0x28
		int refreshRate; // 0x2C
		int adapter; // 0x30
		int mipmapSkipLevel; // 0x34
		int presentationInterval; // 0x38
		float gamma; // 0x3C
		NI::Vector3 unknown_0x40;
		NI::Node* node; // 0x4C
		NI::Renderer* renderer; // 0x50
		int unknown_0x54;
		HWND parentWindow; // 0x58
		int unknown_0x5C;
		int unknown_0x60;
	};
	static_assert(sizeof(NetImmerseInstance) == 0x64, "CS::NetImmerseInstance failed size validation");
	static_assert(sizeof(NetImmerseInstance::VirtualTable) == 0x64, "CS::NetImmerseInstance's virtual table failed size validation");

	struct RenderController {
		NetImmerseInstance* niInstance; // 0x0
		NI::Node* node; // 0x4
		NI::Camera* camera; // 0x8

		static auto get() {
			return *reinterpret_cast<RenderController**>(0x6CF77C);
		}
	};
	static_assert(sizeof(RenderController) == 0xC, "CS::RenderController failed size validation");

	struct SceneGraphController {
		NI::Node* sceneRoot;
		NI::Node* objectRoot;
		NI::Node* landscapeRoot;
		NI::ZBufferProperty* zBufferProperty;
		NI::Property* wireframeProperty;
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;

		static auto get() {
			return *reinterpret_cast<SceneGraphController**>(0x6CEB78);
		}
	};
	static_assert(sizeof(SceneGraphController) == 0x24, "CS::SceneGraphController failed size validation");

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

		if (!isKeyDown('X') && !isKeyDown('Y')) {
			rotationAxis = TranslationData::RotationAxis::Z;
		}

		auto& cumulativeRot = *reinterpret_cast<NI::Vector3*>(0x6CF760);
		switch (rotationAxis) {
		case TranslationData::RotationAxis::X:
			cumulativeRot.x += relativeMouseDelta * rotationSpeed * 0.1f;
			se::math::standardizeAngleRadians(cumulativeRot.x);
			break;
		case TranslationData::RotationAxis::Y:
			cumulativeRot.y += relativeMouseDelta * rotationSpeed * 0.1f;
			se::math::standardizeAngleRadians(cumulativeRot.y);
			break;
		case TranslationData::RotationAxis::Z:
			cumulativeRot.z += relativeMouseDelta * rotationSpeed * 0.1f;
			se::math::standardizeAngleRadians(cumulativeRot.z);
			break;
		}
		
		auto snapAngleDegrees = se::memory::MemAccess<int>::Get(0x6CE9AC);
		auto snapAngle = se::math::degreesToRadians((float)snapAngleDegrees);
		bool isSnapping = ((rotationFlags & 2) != 0) && (snapAngle != 0.0f);

		auto clip = isSnapping ? snapAngle : 0.0f;
		if (cumulativeRot.x <= clip && cumulativeRot.y <= clip && cumulativeRot.z <= clip) {
			return 0;
		}

		if (isSnapping) {
			cumulativeRot.x = std::roundf(cumulativeRot.x / snapAngle) * snapAngle;
			cumulativeRot.y = std::roundf(cumulativeRot.y / snapAngle) * snapAngle;
			cumulativeRot.z = std::roundf(cumulativeRot.z / snapAngle) * snapAngle;
		}

		// Save rotation before clearing.
		NI::Matrix33 userRotation;
		userRotation.fromEulerXYZ(cumulativeRot.x, cumulativeRot.y, cumulativeRot.z);

		// Restart accumulating process.
		cumulativeRot.x = 0;
		cumulativeRot.y = 0;
		cumulativeRot.z = 0;

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

				NI::Vector3 orientation;
				newRotation.toEulerXYZ(&orientation);

				if (isSnapping) {
					orientation.x = std::roundf(orientation.x / snapAngle) * snapAngle;
					orientation.y = std::roundf(orientation.y / snapAngle) * snapAngle;
					orientation.z = std::roundf(orientation.z / snapAngle) * snapAngle;
				}
				se::math::standardizeAngleRadians(orientation.x);
				se::math::standardizeAngleRadians(orientation.y);
				se::math::standardizeAngleRadians(orientation.z);

				reference->yetAnotherOrientation = orientation;
				reference->orientationNonAttached = orientation;
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
	// Patch: Extend Render Window message handling.
	//

	static WORD lastRenderWindowPosX = 0;
	static WORD lastRenderWindowPosY = 0;

	constexpr auto landscapeEditWindowId = 203;

	void PickLandscapeTexture(HWND hWnd) {
		auto editorWindow = memory::MemAccess<HWND>::Get(0x6CE95C);
		if (!editorWindow) {
			return;
		}

		auto rendererPicker = reinterpret_cast<NI::Pick*>(0x6CF528);
		auto rendererController = RenderController::get();
		auto sceneGraphController = SceneGraphController::get();

		// Cache picker settings we care about.
		const auto previousRoot = rendererPicker->root;

		// Make changes to the pick that we need to.
		rendererPicker->root = sceneGraphController->landscapeRoot;

		NI::Vector3 origin;
		NI::Vector3 direction;
		if (rendererController->camera->windowPointToRay(lastRenderWindowPosX, lastRenderWindowPosY, origin, direction)) {
			direction.normalize();

			if (rendererPicker->pickObjects(&origin, &direction)) {
				auto firstResult = rendererPicker->results.at(0);
				if (firstResult->object) {
					auto texturingProperty = firstResult->object->getTexturingProperty();
					if (texturingProperty) {
						auto baseMap = texturingProperty->getBaseMap();
						if (baseMap && baseMap->texture) {
							LVITEMA queryData = {};
							queryData.mask = LVIF_PARAM;
							auto textureList = GetDlgItem(editorWindow, 1492);
							int textureCount = ListView_GetItemCount(textureList);
							for (int row = 0; row < textureCount; ++row) {
								queryData.iItem = row;
								if (ListView_GetItem(textureList, &queryData)) {
									auto landTexture = reinterpret_cast<LandTexture*>(queryData.lParam);
									if (landTexture) {
										if (landTexture->texture == baseMap->texture) {
											ListView_SetItemState(textureList, row, LVIS_SELECTED, LVIS_SELECTED);
											break;
										}
									}
								}
							}
						}
					}
				}
			}
		}


		// Restore pick settings.
		rendererPicker->clearResults();
		rendererPicker->root = previousRoot;
	}

	inline void PatchDialogProc_OnKeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (wParam) {
		case 'P':
			PickLandscapeTexture(hWnd);
			break;
		}
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (msg) {
		case WM_MOUSEMOVE:
			lastRenderWindowPosX = LOWORD(lParam);
			lastRenderWindowPosY = HIWORD(lParam);
			break;
		}

		// Call original function.
		const auto CS_RenderWindowDialogProc = reinterpret_cast<WNDPROC>(0x45A3F0);
		auto result = CS_RenderWindowDialogProc(hWnd, msg, wParam, lParam);

		switch (msg) {
		case WM_KEYDOWN:
			PatchDialogProc_OnKeyDown(hWnd, msg, wParam, lParam);
			break;
		}

		return result;
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

		// Patch: Extend Render Window message handling.
		genJumpEnforced(0x4020EF, 0x45A3F0, reinterpret_cast<DWORD>(PatchDialogProc));
	}
}