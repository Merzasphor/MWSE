#include "DialogRenderWindow.h"

#include "LogUtil.h"
#include "MathUtil.h"
#include "MemoryUtil.h"
#include "WindowsUtil.h"

#include "NIBound.h"
#include "NICamera.h"
#include "NILight.h"
#include "NINode.h"
#include "NIPick.h"

#include "CSCell.h"
#include "CSDataHandler.h"
#include "CSGameFile.h"
#include "CSLandTexture.h"
#include "CSLight.h"
#include "CSRecordHandler.h"
#include "CSReference.h"
#include "CSStatic.h"

#include "Settings.h"

namespace se::cs::dialog::render_window {
	using namespace windows;

	static WORD lastRenderWindowPosX = 0;
	static WORD lastRenderWindowPosY = 0;

	//
	// Patch: Use world rotation values unless ALT is held.
	//

	using gObjectMove = memory::ExternalGlobal<float, 0x6CE9B0>;
	using gSnapAngleInDegrees = memory::ExternalGlobal<int, 0x6CE9AC>;
	using gRotationFlags = memory::ExternalGlobal<BYTE, 0x6CE9A4>;
	using gCumulativeRotationValues = memory::ExternalGlobal<NI::Vector3, 0x6CF760>;
	using gRenderWindowPick = memory::ExternalGlobal<NI::Pick, 0x6CF528>;
	using gCurrentCell = memory::ExternalGlobal<Cell*, 0x6CF7B8>;

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
		NI::Bound bound; // 0x8

		static inline auto get() {
			return memory::ExternalGlobal<TranslationData*, 0x6CE968>::get();
		}
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

		static inline auto get() {
			return memory::ExternalGlobal<SceneGraphController*, 0x6CEB78>::get();
		}
	};
	static_assert(sizeof(SceneGraphController) == 0x24, "CS::SceneGraphController failed size validation");

	const auto TES3_CS_OriginalRotationLogic = reinterpret_cast<bool(__cdecl*)(void*, TranslationData::Target*, int, TranslationData::RotationAxis)>(0x4652D0);
	bool __cdecl Patch_ReplaceRotationLogic(void* unknown1, TranslationData::Target* firstTarget, int relativeMouseDelta, TranslationData::RotationAxis rotationAxis) {
		// Allow holding ALT modifier to do vanilla behavior.
		bool useWorldAxisRotation = settings.render_window.use_world_axis_rotations_by_default;
		if (isKeyDown(VK_MENU)) {
			useWorldAxisRotation = !useWorldAxisRotation;
		}

		if (!useWorldAxisRotation) {
			return TES3_CS_OriginalRotationLogic(unknown1, firstTarget, relativeMouseDelta, rotationAxis);
		}

		if (relativeMouseDelta == 0) {
			return false;
		}

		auto data = TranslationData::get();

		const auto rotationSpeed = gObjectMove::get();
		const auto rotationFlags = gRotationFlags::get();

		if (!isKeyDown('X') && !isKeyDown('Y')) {
			rotationAxis = TranslationData::RotationAxis::Z;
		}

		auto& cumulativeRot = gCumulativeRotationValues::get();
		switch (rotationAxis) {
		case TranslationData::RotationAxis::X:
			cumulativeRot.x += relativeMouseDelta * rotationSpeed * 0.1f;
			break;
		case TranslationData::RotationAxis::Y:
			cumulativeRot.y += relativeMouseDelta * rotationSpeed * 0.1f;
			break;
		case TranslationData::RotationAxis::Z:
			cumulativeRot.z += relativeMouseDelta * rotationSpeed * 0.1f;
			break;
		}

		const auto snapAngle = math::degreesToRadians(gSnapAngleInDegrees::get());
		const bool isSnapping = ((rotationFlags & 2) != 0) && (snapAngle != 0.0f);

		NI::Vector3 orientation = cumulativeRot;
		if (isSnapping) {
			orientation.x = std::roundf(orientation.x / snapAngle) * snapAngle;
			orientation.y = std::roundf(orientation.y / snapAngle) * snapAngle;
			orientation.z = std::roundf(orientation.z / snapAngle) * snapAngle;
		}

		// Due to snapping these may have been set to 0, in which case no need to do anything else.
		if (orientation.x == 0.0f
			&& orientation.y == 0.0f
			&& orientation.z == 0.0f)
		{
			return 0;
		}

		// Restart accumulating process.
		cumulativeRot.x = 0;
		cumulativeRot.y = 0;
		cumulativeRot.z = 0;

		NI::Matrix33 userRotation;
		userRotation.fromEulerXYZ(orientation.x, orientation.y, orientation.z);

		for (auto target = data->firstTarget; target; target = target->next) {
			auto reference = target->reference;

			reference->updateBaseObjectAndAttachment7();
			reference->baseObject->setFlag80(true);

			// Disallow XY rotations on actors and northmarkers.
			auto doRotations = true;
			if (rotationAxis != TranslationData::RotationAxis::Z && !reference->baseObject->canRotateOnAllAxes()) {
				doRotations = false;
			}

			if (doRotations) {
				auto& oldRotation = *reference->sceneNode->localRotation;
				auto newRotation = userRotation * oldRotation;

				// Slightly modified toEulerXYZ that does not do factorization.
				{
					orientation.y = asin(-newRotation.m0.z);
					if (cos(orientation.y) != 0) {
						orientation.x = atan2(newRotation.m1.z, newRotation.m2.z);
						orientation.z = atan2(newRotation.m0.y, newRotation.m0.x);
					}
					else {
						orientation.x = atan2(newRotation.m2.x, newRotation.m2.y);
						orientation.z = 0;
					};
				}

				if (isSnapping && (target == data->firstTarget)) {
					// Snapping the new rotation after adjustments were applied.
					// So we must only snap the *current* axis and not all them.
					switch (rotationAxis) {
					case TranslationData::RotationAxis::X:
						orientation.x = std::roundf(orientation.x / snapAngle) * snapAngle;
						break;
					case TranslationData::RotationAxis::Y:
						orientation.y = std::roundf(orientation.y / snapAngle) * snapAngle;
						break;
					case TranslationData::RotationAxis::Z:
						orientation.z = std::roundf(orientation.z / snapAngle) * snapAngle;
						break;
					}

					// Ensure the matrix is also snapped.
					newRotation.fromEulerXYZ(orientation.x, orientation.y, orientation.z);

					// Ensure all targets use the snapped rotation.
					userRotation = newRotation * oldRotation.transpose();
				}

				math::standardizeAngleRadians(orientation.x);
				math::standardizeAngleRadians(orientation.y);
				math::standardizeAngleRadians(orientation.z);

				reference->yetAnotherOrientation = orientation;
				reference->orientationNonAttached = orientation;

				NI::Matrix33 referenceHandledRotations;
				reference->updateRotationMatrixForRaceAndSex(referenceHandledRotations);
				reference->sceneNode->setLocalRotationMatrix(&referenceHandledRotations);
			}

			// Rotate positions.
			if (data->numberOfTargets > 1) {
				auto p = reference->position - data->bound.center;
				reference->position = (userRotation * p) + data->bound.center;
				reference->unknown_0x10 = reference->position;
				reference->sceneNode->localTranslate = reference->position;
			}

			reference->sceneNode->update(0.0f, true, true);
		}

		return true;
	}

	//
	// Patch: Improve multi-reference scaling.
	//

	void __cdecl Patch_ReplaceScalingLogic(RenderController* renderController, TranslationData::Target* firstTarget, int scaler) {
		auto translationData = TranslationData::get();
		if (!isKeyDown(VK_MENU) || translationData->numberOfTargets == 1) {
			const auto VanillaScalingHandler = reinterpret_cast<void(__cdecl*)(RenderController*, TranslationData::Target*, int)>(0x404949);
			VanillaScalingHandler(renderController, firstTarget, scaler);
			return;
		}

		const auto scaleDelta = scaler * 0.01f;

		const auto& center = translationData->bound.center;

		for (auto target = firstTarget; target; target = target->next) {
			auto reference = target->reference;

			const auto oldScale = reference->getScale();
			reference->setScale(oldScale + scaleDelta);

			const auto newScale = reference->getScale();
			if (newScale != oldScale) {
				reference->setFlag80(true);

				const auto offset = reference->position - center;
				const auto multiplier = newScale / oldScale;

				reference->position = center + offset * multiplier;
				reference->unknown_0x10 = reference->position;
				reference->sceneNode->localTranslate = reference->position;
				reference->sceneNode->update(0.0f, true, true);

				reference->updateBaseObjectAndAttachment7();
			}
		}
	}

	//
	// Patch: Allow alt-dragging objects to snap to surfaces.
	//

	enum class SnappingAxis {
		POSITIVE_X,
		NEGATIVE_X,
		POSITIVE_Y,
		NEGATIVE_Y,
		POSITIVE_Z,
		NEGATIVE_Z,
	};

	SnappingAxis snappingAxis = SnappingAxis::POSITIVE_Z;

	int __cdecl Patch_ReplaceDragMovementLogic(RenderController* renderController, TranslationData::Target* firstTarget, int dx, int dy, bool lockX, bool lockY, bool lockZ) {
		// We only care if we are holding the alt key and only have one object selected.
		auto data = memory::MemAccess<TranslationData*>::Get(0x6CE968);
		if (data->numberOfTargets != 1 || !isKeyDown(VK_MENU)) {
			const auto DefaultDragMovementFunction = reinterpret_cast<int(__cdecl*)(RenderController*, TranslationData::Target*, int, int, bool, bool, bool)>(0x401F4B);
			return DefaultDragMovementFunction(renderController, firstTarget, dx, dy, lockX, lockY, lockZ);
		}

		using namespace math;

		auto rendererPicker = &gRenderWindowPick::get();
		auto rendererController = RenderController::get();
		auto sceneGraphController = SceneGraphController::get();

		// Cache picker settings we care about.
		const auto& previousRoot = rendererPicker->root;
		const auto previousReturnNormal = rendererPicker->returnNormal;

		// Make changes to the pick that we need to.
		rendererPicker->root = sceneGraphController->sceneRoot;
		rendererPicker->returnNormal = true;

		auto reference = data->firstTarget->reference;
		reference->sceneNode->setAppCulled(true);

		NI::Vector3 origin;
		NI::Vector3 direction;
		if (rendererController->camera->windowPointToRay(lastRenderWindowPosX, lastRenderWindowPosY, origin, direction)) {
			direction.normalize();

			if (rendererPicker->pickObjects(&origin, &direction)) {
				auto firstResult = rendererPicker->results.at(0);
				if (firstResult) {
					auto object = reference->baseObject;

					auto refSnappingAxis = snappingAxis;
					if (!object->canRotateOnAllAxes()) {
						refSnappingAxis = SnappingAxis::POSITIVE_Z;
					}

					reference->setModified(true);
					reference->setFlag80(true);
					reference->updateBaseObjectAndAttachment7();

					// Set position.
					NI::Vector3 offset;
					const auto scale = reference->getScale();
					switch (refSnappingAxis) {
					case SnappingAxis::POSITIVE_X:
						offset = firstResult->normal * abs(object->boundingBoxMin.x) * scale;
						break;
					case SnappingAxis::NEGATIVE_X:
						offset = firstResult->normal * abs(object->boundingBoxMax.x) * scale;
						break;
					case SnappingAxis::POSITIVE_Y:
						offset = firstResult->normal * abs(object->boundingBoxMin.y) * scale;
						break;
					case SnappingAxis::NEGATIVE_Y:
						offset = firstResult->normal * abs(object->boundingBoxMax.y) * scale;
						break;
					case SnappingAxis::POSITIVE_Z:
						offset = firstResult->normal * abs(object->boundingBoxMin.z) * scale;
						break;
					case SnappingAxis::NEGATIVE_Z:
						offset = firstResult->normal * abs(object->boundingBoxMax.z) * scale;
						break;
					}

					reference->position = firstResult->intersection + offset;
					reference->unknown_0x10 = reference->position;
					reference->sceneNode->localTranslate = reference->position;

					// Set rotation.
					if (object->canRotateOnAllAxes()) {
						NI::Vector3 orientation;
						switch (refSnappingAxis) {
						case SnappingAxis::POSITIVE_X:
						case SnappingAxis::NEGATIVE_X:
							orientation.x = 1.0f;
							break;
						case SnappingAxis::POSITIVE_Y:
						case SnappingAxis::NEGATIVE_Y:
							orientation.y = 1.0f;
							break;
						case SnappingAxis::POSITIVE_Z:
						case SnappingAxis::NEGATIVE_Z:
							orientation.z = 1.0f;
							break;
						}
						
						NI::Matrix33 rotation;
						rotation.toRotationDifference(orientation, firstResult->normal);

						// Flip axis if it's negative snapping.
						switch (refSnappingAxis) {
						case SnappingAxis::NEGATIVE_X:
						case SnappingAxis::NEGATIVE_Y:
						case SnappingAxis::NEGATIVE_Z:
							rotation = rotation.invert();
							break;
						}

						// Restore the original base orientation.
						switch (refSnappingAxis) {
						case SnappingAxis::POSITIVE_X:
						case SnappingAxis::NEGATIVE_X:
							orientation.x = reference->yetAnotherOrientation.x;
							break;
						case SnappingAxis::POSITIVE_Y:
						case SnappingAxis::NEGATIVE_Y:
							orientation.y = reference->yetAnotherOrientation.y;
							break;
						case SnappingAxis::POSITIVE_Z:
						case SnappingAxis::NEGATIVE_Z:
							orientation.z = reference->yetAnotherOrientation.z;
							break;
						}

						rotation.toEulerXYZ(&orientation);

						math::standardizeAngleRadians(orientation.x);
						math::standardizeAngleRadians(orientation.y);
						math::standardizeAngleRadians(orientation.z);

						reference->yetAnotherOrientation = orientation;
						reference->orientationNonAttached = orientation;

						reference->sceneNode->setLocalRotationMatrix(&rotation);
					}
					
					reference->sceneNode->update(0.0f, true, true);

					// Update lighting data.
					auto dataHandler = DataHandler::get();
					auto attachedLightData = reference->getLightAttachment();
					if (object->objectType == ObjectType::Light && attachedLightData) {
						auto baseObjectLight = static_cast<Light*>(object);
						if (dataHandler->currentInteriorCell) {
							attachedLightData->light->detachAllAffectedNodes();
							baseObjectLight->updateLightingData(attachedLightData->light, dataHandler->currentInteriorCell);
						}
						else {
							dataHandler->updateAllLights();
						}
					}
					else {
						dataHandler->maybeUpdateLightForReference(reference);
					}
				}
			}
		}

		reference->sceneNode->setAppCulled(false);

		// Restore pick settings.
		rendererPicker->clearResults();
		rendererPicker->root = previousRoot;
		rendererPicker->returnNormal = previousReturnNormal;

		return 1;
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

	const auto TES3_Object_IsMarker = reinterpret_cast<bool(__thiscall*)(BaseObject*)>(0x549B20);
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

	static bool PatchDialogProc_preventMainHandler = false;

	constexpr auto landscapeEditWindowId = 203;

	bool PickLandscapeTexture(HWND hWnd) {
		auto editorWindow = memory::MemAccess<HWND>::Get(0x6CE95C);
		if (!editorWindow) {
			return false;
		}

		// Make sure that we're not in color mode.
		if (IsDlgButtonChecked(editorWindow, 1008)) {
			return false;
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
											ListView_EnsureVisible(textureList, row, TRUE);
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

		return true;
	}

	void hideSelectedReferences() {
		auto translationData = TranslationData::get();
		
		for (auto target = translationData->firstTarget; target; target = target->next) {
			auto node = target->reference->sceneNode;
			if (node) {
				node->addExtraData(new NI::StringExtraData("xHID"));
				node->setAppCulled(true);
				node->update();
			}
		}

		const auto thing = reinterpret_cast<void(__thiscall*)(TranslationData*, bool)>(0x403391);
		thing(translationData, true);
	}

	void unhideNode(NI::Node* node) {
		auto hideFlag = node->getStringDataWithValue("xHID");
		if (hideFlag) {
			node->removeExtraData(hideFlag);
			node->setAppCulled(false);
			node->update();
		}

		for (auto& child : node->children) {
			if (child && child->isInstanceOfType(NI::RTTIStaticPtr::NiNode)) {
				unhideNode(static_cast<NI::Node*>(child.get()));
			}
		}
	}

	void unhideAllReferences() {
		unhideNode(SceneGraphController::get()->objectRoot);
	}

	void saveRenderStateToQuickStart() {
		auto renderController = RenderController::get();
		auto dataHandler = DataHandler::get();
		auto recordHandler = dataHandler->recordHandler;
		auto& quickstart = settings.quickstart;

		// Store camera position.
		quickstart.position[0] = renderController->camera->worldTransform.translation.x;
		quickstart.position[1] = renderController->camera->worldTransform.translation.y;
		quickstart.position[2] = renderController->camera->worldTransform.translation.z;

		// Store camera orientation as euler angle.
		NI::Vector3 orientationVector;
		renderController->node->getLocalRotationMatrix()->toEulerXYZ(&orientationVector);
		quickstart.orientation[0] = orientationVector.x;
		quickstart.orientation[1] = orientationVector.y;
		quickstart.orientation[2] = orientationVector.z;

		// If we're in an interior, store the cell ID.
		auto currentCell = gCurrentCell::get();
		if (currentCell == dataHandler->currentInteriorCell) {
			quickstart.cell = gCurrentCell::get()->getObjectID();
		}
		else {
			quickstart.cell.clear();
		}

		// Store the active game file list.
		quickstart.data_files.clear();
		for (auto i = 0; i < recordHandler->activeModCount; ++i) {
			quickstart.data_files.push_back(recordHandler->activeGameFiles[i]->fileName);
		}
		
		// Also store the current file set as active.
		if (recordHandler->activeFile) {
			quickstart.active_file = recordHandler->activeFile->fileName;
		}

		quickstart.enabled = true;

		settings.save();
	}

	void clearRenderStateFromQuickStart() {
		auto renderController = RenderController::get();
		auto& quickstart = settings.quickstart;

		quickstart.enabled = false;
		quickstart.data_files.clear();
		quickstart.active_file.clear();
		quickstart.cell.clear();
		quickstart.position = { 0.0f, 0.0f, 0.0f };
		quickstart.orientation = { 0.0f, 0.0f, 0.0f };

		settings.save();
	}

	void showContextAwareActionMenu(HWND hWndRenderWindow) {
		auto menu = CreatePopupMenu();
		if (menu == NULL) {
			return;
		}

		auto recordHandler = DataHandler::get()->recordHandler;
		auto translationData = TranslationData::get();
		const bool hasReferencesSelected = translationData->numberOfTargets > 0;

		enum ContextMenuId {
			RESERVED_ERROR,
			RESERVED_NO_CALLBACK,
			HIDE_SELECTION,
			RESTORE_HIDDEN_REFERENCES,
			SET_SNAPPING_AXIS_POSITIVE_X,
			SET_SNAPPING_AXIS_NEGATIVE_X,
			SET_SNAPPING_AXIS_POSITIVE_Y,
			SET_SNAPPING_AXIS_NEGATIVE_Y,
			SET_SNAPPING_AXIS_POSITIVE_Z,
			SET_SNAPPING_AXIS_NEGATIVE_Z,
			SAVE_STATE_TO_QUICKSTART,
			CLEAR_STATE_FROM_QUICKSTART,
		};

		/*
		* Reserved hotkeys:
		*	H: Hide Selection
		*	R: Restore Hidden References
		*	S: Set Snapping Axis
		*/

		MENUITEMINFO menuItem = {};
		menuItem.cbSize = sizeof(MENUITEMINFO);
		unsigned int index = 0;

		MENUITEMINFO subMenuSnappingAxis = {};
		subMenuSnappingAxis.cbSize = sizeof(MENUITEMINFO);
		subMenuSnappingAxis.hSubMenu = CreateMenu();

		{
			unsigned int subIndex = 0;

			menuItem.wID = SET_SNAPPING_AXIS_POSITIVE_X;
			menuItem.fMask = MIIM_FTYPE | MIIM_CHECKMARKS | MIIM_STRING | MIIM_ID;
			menuItem.fType = MFT_STRING | MFT_RADIOCHECK;
			menuItem.fState = (snappingAxis == SnappingAxis::POSITIVE_X) ? MFS_CHECKED : MFS_UNCHECKED;
			menuItem.dwTypeData = (LPSTR)"+&X";
			menuItem.hbmpChecked = NULL;
			menuItem.hbmpUnchecked = NULL;
			InsertMenuItemA(subMenuSnappingAxis.hSubMenu, ++subIndex, TRUE, &menuItem);

			menuItem.wID = SET_SNAPPING_AXIS_NEGATIVE_X;
			menuItem.fMask = MIIM_FTYPE | MIIM_CHECKMARKS | MIIM_STRING | MIIM_ID;
			menuItem.fType = MFT_STRING | MFT_RADIOCHECK;
			menuItem.fState = (snappingAxis == SnappingAxis::NEGATIVE_X) ? MFS_CHECKED : MFS_UNCHECKED;
			menuItem.dwTypeData = (LPSTR)"-X";
			InsertMenuItemA(subMenuSnappingAxis.hSubMenu, ++subIndex, TRUE, &menuItem);

			menuItem.wID = SET_SNAPPING_AXIS_POSITIVE_Y;
			menuItem.fMask = MIIM_FTYPE | MIIM_CHECKMARKS | MIIM_STRING | MIIM_ID;
			menuItem.fType = MFT_STRING | MFT_RADIOCHECK;
			menuItem.fState = (snappingAxis == SnappingAxis::POSITIVE_Y) ? MFS_CHECKED : MFS_UNCHECKED;
			menuItem.dwTypeData = (LPSTR)"+&Y";
			InsertMenuItemA(subMenuSnappingAxis.hSubMenu, ++subIndex, TRUE, &menuItem);

			menuItem.wID = SET_SNAPPING_AXIS_NEGATIVE_Y;
			menuItem.fMask = MIIM_FTYPE | MIIM_CHECKMARKS | MIIM_STRING | MIIM_ID;
			menuItem.fType = MFT_STRING | MFT_RADIOCHECK;
			menuItem.fState = (snappingAxis == SnappingAxis::NEGATIVE_Y) ? MFS_CHECKED : MFS_UNCHECKED;
			menuItem.dwTypeData = (LPSTR)"-Y";
			InsertMenuItemA(subMenuSnappingAxis.hSubMenu, ++subIndex, TRUE, &menuItem);

			menuItem.wID = SET_SNAPPING_AXIS_POSITIVE_Z;
			menuItem.fMask = MIIM_FTYPE | MIIM_CHECKMARKS | MIIM_STRING | MIIM_ID;
			menuItem.fType = MFT_STRING | MFT_RADIOCHECK;
			menuItem.fState = (snappingAxis == SnappingAxis::POSITIVE_Z) ? MFS_CHECKED : MFS_UNCHECKED;
			menuItem.dwTypeData = (LPSTR)"+&Z";
			InsertMenuItemA(subMenuSnappingAxis.hSubMenu, ++subIndex, TRUE, &menuItem);

			menuItem.wID = SET_SNAPPING_AXIS_NEGATIVE_Z;
			menuItem.fMask = MIIM_FTYPE | MIIM_CHECKMARKS | MIIM_STRING | MIIM_ID;
			menuItem.fType = MFT_STRING | MFT_RADIOCHECK;
			menuItem.fState = (snappingAxis == SnappingAxis::NEGATIVE_Z) ? MFS_CHECKED : MFS_UNCHECKED;
			menuItem.dwTypeData = (LPSTR)"-Z";
			InsertMenuItemA(subMenuSnappingAxis.hSubMenu, ++subIndex, TRUE, &menuItem);

			CheckMenuRadioItem(subMenuSnappingAxis.hSubMenu, 0, 5, (UINT)snappingAxis, MF_BYPOSITION);
		}

		menuItem.wID = RESERVED_NO_CALLBACK;
		menuItem.fMask = MIIM_SUBMENU | MIIM_TYPE;
		menuItem.fType = MFT_STRING;
		menuItem.fState = hasReferencesSelected ? MFS_ENABLED : MFS_DISABLED;
		menuItem.hSubMenu = subMenuSnappingAxis.hSubMenu;
		menuItem.dwTypeData = (LPSTR)"Set &Snapping Axis";
		InsertMenuItemA(menu, ++index, TRUE, &menuItem);

		menuItem.wID = RESERVED_NO_CALLBACK;
		menuItem.fMask = MIIM_FTYPE | MIIM_ID;
		menuItem.fType = MFT_SEPARATOR;
		InsertMenuItemA(menu, ++index, TRUE, &menuItem);

		menuItem.wID = HIDE_SELECTION;
		menuItem.fMask = MIIM_FTYPE | MIIM_STRING | MIIM_ID | MIIM_STATE;
		menuItem.fType = MFT_STRING;
		menuItem.fState = hasReferencesSelected ? MFS_ENABLED : MFS_DISABLED;
		menuItem.dwTypeData = (LPSTR)"&Hide Selection";
		InsertMenuItemA(menu, ++index, TRUE, &menuItem);

		menuItem.wID = RESTORE_HIDDEN_REFERENCES;
		menuItem.fMask = MIIM_FTYPE | MIIM_STRING | MIIM_ID | MIIM_STATE;
		menuItem.fType = MFT_STRING;
		menuItem.fState = MFS_ENABLED;
		menuItem.dwTypeData = (LPSTR)"&Restore Hidden References";
		InsertMenuItemA(menu, ++index, TRUE, &menuItem);

		menuItem.wID = RESERVED_NO_CALLBACK;
		menuItem.fMask = MIIM_FTYPE | MIIM_ID;
		menuItem.fType = MFT_SEPARATOR;
		InsertMenuItemA(menu, ++index, TRUE, &menuItem);

		menuItem.wID = SAVE_STATE_TO_QUICKSTART;
		menuItem.fMask = MIIM_FTYPE | MIIM_STRING | MIIM_ID | MIIM_STATE;
		menuItem.fType = MFT_STRING;
		menuItem.fState = (recordHandler->activeModCount > 0) ? MFS_ENABLED : MFS_DISABLED;
		menuItem.dwTypeData = (LPSTR)"Save State to QuickStart";
		InsertMenuItemA(menu, ++index, TRUE, &menuItem);

		menuItem.wID = CLEAR_STATE_FROM_QUICKSTART;
		menuItem.fMask = MIIM_FTYPE | MIIM_STRING | MIIM_ID | MIIM_STATE;
		menuItem.fType = MFT_STRING;
		menuItem.fState = settings.quickstart.enabled ? MFS_ENABLED : MFS_DISABLED;
		menuItem.dwTypeData = (LPSTR)"Clear QuickStart";
		InsertMenuItemA(menu, ++index, TRUE, &menuItem);

		POINT p;
		GetCursorPos(&p);

		// Due to where this message is, prevent annoying beep sound when the tracking of the menu consumes shit.
		MSG msg;
		PeekMessage(&msg, NULL, WM_CHAR, WM_CHAR, PM_REMOVE);

		auto result = TrackPopupMenuEx(menu, TPM_LEFTALIGN | TPM_TOPALIGN | TPM_RETURNCMD | TPM_LEFTBUTTON | TPM_NOANIMATION | TPM_VERTICAL, p.x, p.y, hWndRenderWindow, NULL);
		
		switch (result) {
		case RESERVED_ERROR:
			break;
		case HIDE_SELECTION:
			hideSelectedReferences();
			break;
		case RESTORE_HIDDEN_REFERENCES:
			unhideAllReferences();
			break;
		case SET_SNAPPING_AXIS_POSITIVE_X:
			snappingAxis = SnappingAxis::POSITIVE_X;
			break;
		case SET_SNAPPING_AXIS_NEGATIVE_X:
			snappingAxis = SnappingAxis::NEGATIVE_X;
			break;
		case SET_SNAPPING_AXIS_POSITIVE_Y:
			snappingAxis = SnappingAxis::POSITIVE_Y;
			break;
		case SET_SNAPPING_AXIS_NEGATIVE_Y:
			snappingAxis = SnappingAxis::NEGATIVE_Y;
			break;
		case SET_SNAPPING_AXIS_POSITIVE_Z:
			snappingAxis = SnappingAxis::POSITIVE_Z;
			break;
		case SET_SNAPPING_AXIS_NEGATIVE_Z:
			snappingAxis = SnappingAxis::NEGATIVE_Z;
			break;
		case SAVE_STATE_TO_QUICKSTART:
			saveRenderStateToQuickStart();
			break;
		case CLEAR_STATE_FROM_QUICKSTART:
			clearRenderStateFromQuickStart();
			break;
		default:
			log::stream << "Unknown render window context menu ID " << result << " used!" << std::endl;
		}

		// Cleanup our menus.
		DestroyMenu(menu);
		DestroyMenu(subMenuSnappingAxis.hSubMenu);

		// We also stole paint stuff, so repaint.
		SendMessage(hWndRenderWindow, WM_PAINT, 0, 0);
		PatchDialogProc_preventMainHandler = true;
	}

	inline void PatchDialogProc_OnRMouseButtonDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		constexpr auto comboPickLandscapeTexture = MK_CONTROL | MK_RBUTTON;
		if ((wParam & comboPickLandscapeTexture) == comboPickLandscapeTexture) {
			if (PickLandscapeTexture(hWnd)) {
				PatchDialogProc_preventMainHandler = true;
			}
		}
	}

	inline void PatchDialogProc_OnKeyDown(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		switch (wParam) {
		case 'Q':
			showContextAwareActionMenu(hWnd);
			break;
		}
	}

	LRESULT CALLBACK PatchDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
		PatchDialogProc_preventMainHandler = false;

		switch (msg) {
		case WM_MOUSEMOVE:
			lastRenderWindowPosX = LOWORD(lParam);
			lastRenderWindowPosY = HIWORD(lParam);
			break;
		case WM_RBUTTONDOWN:
			PatchDialogProc_OnRMouseButtonDown(hWnd, msg, wParam, lParam);
			break;
		}

		if (PatchDialogProc_preventMainHandler) {
			return TRUE;
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

		// Patch: Improve multi-reference scaling.
		genCallEnforced(0x45EE3A, 0x404949, reinterpret_cast<DWORD>(Patch_ReplaceScalingLogic));

		// Patch: Improve drag-move logic.
		genCallEnforced(0x45EE85, 0x401F4B, reinterpret_cast<DWORD>(Patch_ReplaceDragMovementLogic));

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