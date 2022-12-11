// dllmain.cpp : Defines the entry point for the DLL application.

#include "TES3IteratedList.h"
#include "NILinkedList.h"
#include "NITArray.h"

#include "MemoryUtil.h"

static std::ofstream logstream;

namespace NI {
	struct Node;
	struct Renderer;

	struct Vector3 {
		float x, y, z;

		Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
		Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

		Vector3 operator+(const Vector3& vec3) const {
			return Vector3(x + vec3.x, y + vec3.y, z + vec3.z);
		}

		Vector3 operator-(const Vector3& vec3) const {
			return Vector3(x - vec3.x, y - vec3.y, z - vec3.z);
		}

		friend std::ostream& operator<<(std::ostream& str, const Vector3& vector) {
			str << "(" << vector.x << "," << vector.y << "," << vector.z << ")";
			return str;
		}
	};

	struct Vector4 {
		float x, y, z, w;
	};

	struct Matrix33 {
		Vector3 m0, m1, m2;

		friend std::ostream& operator<<(std::ostream& str, const Matrix33& matrix) {
			str << "[" << matrix.m0 << "," << matrix.m1 << "," << matrix.m2 << "]";
			return str;
		}

		static constexpr auto _multiplyValueMatrix = reinterpret_cast<Matrix33 * (__thiscall*)(Matrix33*, Matrix33*, Matrix33*)>(0x5E2060);
		Matrix33* multiplyValue(Matrix33* out_result, Matrix33* value) {
			return _multiplyValueMatrix(this, out_result, value);
		}

		Matrix33 multiplyValue(Matrix33* value) {
			Matrix33 result;
			multiplyValue(&result, value);
			return result;
		}

		static constexpr auto _multiplyValueVec3 = reinterpret_cast<Vector3 * (__thiscall*)(Matrix33*, Vector3*, Vector3*)>(0x5E21F0);
		Vector3* multiplyValue(Vector3* out_result, Vector3* value) {
			return _multiplyValueVec3(this, out_result, value);
		}

		Vector3 multiplyValue(Vector3* value) {
			Vector3 result;
			multiplyValue(&result, value);
			return result;
		}

		static constexpr auto _toRotationX = reinterpret_cast<void(__thiscall*)(Matrix33*, float)>(0x5E1CC0);
		void toRotationX(float value) {
			_toRotationX(this, value);
		}

		static constexpr auto _toRotationY = reinterpret_cast<void(__thiscall*)(Matrix33*, float)>(0x5E1D00);
		void toRotationY(float value) {
			_toRotationY(this, value);
		}

		static constexpr auto _toRotationZ = reinterpret_cast<void(__thiscall*)(Matrix33*, float)>(0x5E1D40);
		void toRotationZ(float value) {
			_toRotationZ(this, value);
		}

		bool isIdentityMatrix() const {
			return this == getIdentityMatrix();
		}

		void toIdentity() {
			*this = *getIdentityMatrix();
		}

		static Matrix33* getIdentityMatrix() {
			return reinterpret_cast<Matrix33*>(0x6D7BDC);
		}

		static Matrix33 fromEulerXYZ(float x, float y, float z) {
			float cx = cos(x);
			float sx = sin(x);
			float cy = cos(y);
			float sy = sin(y);
			float cz = cos(z);
			float sz = sin(z);

			Matrix33 m;
			m.m0.x = cy * cz;
			m.m0.y = cy * sz;
			m.m0.z = -sy;
			m.m1.x = sx * sy * cz - cx * sz;
			m.m1.y = sx * sy * sz + cx * cz;
			m.m1.z = sx * cy;
			m.m2.x = cx * sy * cz + sx * sz;
			m.m2.y = cx * sy * sz - sx * cz;
			m.m2.z = cx * cy;

			return m;
		}

		Vector3 toEulerXYZ() {
			float x = 0.0;
			float y = 0.0;
			float z = 0.0;

			y = asin(-this->m0.z);
			if (cos(y) != 0) {
				x = atan2(this->m1.z, this->m2.z);
				z = atan2(this->m0.y, this->m0.x);
			}
			else {
				x = atan2(this->m2.x, this->m2.y);
				z = 0;
			};

			NI::Vector3 out;
			out.x = x;
			out.y = y;
			out.z = z;

			return out;
		}
	};

	struct Matrix44 {
		Vector4 m0, m1, m2, m3;
	};

	struct Transform {
		Matrix33 rotation;
		Vector3 position;
		float scale;
	};

	struct RTTI {
		const char* name; // 0x0
		RTTI* baseRTTI; // 0x4
	};

	namespace RTTIStaticPtr {
		enum RTTIStaticPtr : uintptr_t {
			AvoidNode = 0xFFFFFFFF, // TODO: Resolve
			BrickNiExtraData = 0xFFFFFFFF, // TODO: Resolve
			BSMirroredNode = 0xFFFFFFFF, // TODO: Resolve
			NiAccumulator = 0xFFFFFFFF, // TODO: Resolve
			NiAlphaAccumulator = 0xFFFFFFFF, // TODO: Resolve
			NiAlphaController = 0xFFFFFFFF, // TODO: Resolve
			NiAlphaProperty = 0xFFFFFFFF, // TODO: Resolve
			NiAmbientLight = 0xFFFFFFFF, // TODO: Resolve
			NiAutoNormalParticles = 0xFFFFFFFF, // TODO: Resolve
			NiAutoNormalParticlesData = 0xFFFFFFFF, // TODO: Resolve
			NiAVObject = 0xFFFFFFFF, // TODO: Resolve
			NiBillboardNode = 0xFFFFFFFF, // TODO: Resolve
			NiBltSource = 0xFFFFFFFF, // TODO: Resolve
			NiBSAnimationManager = 0xFFFFFFFF, // TODO: Resolve
			NiBSAnimationNode = 0xFFFFFFFF, // TODO: Resolve
			NiBSPArrayController = 0xFFFFFFFF, // TODO: Resolve
			NiBSParticleNode = 0xFFFFFFFF, // TODO: Resolve
			NiBSPNode = 0xFFFFFFFF, // TODO: Resolve
			NiCamera = 0xFFFFFFFF, // TODO: Resolve
			NiClusterAccumulator = 0xFFFFFFFF, // TODO: Resolve
			NiCollisionSwitch = 0xFFFFFFFF, // TODO: Resolve
			NiColorData = 0xFFFFFFFF, // TODO: Resolve
			NiDirectionalLight = 0xFFFFFFFF, // TODO: Resolve
			NiDitherProperty = 0xFFFFFFFF, // TODO: Resolve
			NiDX8Renderer = 0xFFFFFFFF, // TODO: Resolve
			NiDynamicEffect = 0xFFFFFFFF, // TODO: Resolve
			NiExtraData = 0xFFFFFFFF, // TODO: Resolve
			NiFlipController = 0xFFFFFFFF, // TODO: Resolve
			NiFloatController = 0xFFFFFFFF, // TODO: Resolve
			NiFloatData = 0xFFFFFFFF, // TODO: Resolve
			NiFltAnimationNode = 0xFFFFFFFF, // TODO: Resolve
			NiFogProperty = 0xFFFFFFFF, // TODO: Resolve
			NiGeometry = 0xFFFFFFFF, // TODO: Resolve
			NiGeometryData = 0xFFFFFFFF, // TODO: Resolve
			NiGeomMorpherController = 0xFFFFFFFF, // TODO: Resolve
			NiGravity = 0xFFFFFFFF, // TODO: Resolve
			NiKeyframeController = 0xFFFFFFFF, // TODO: Resolve
			NiKeyframeData = 0xFFFFFFFF, // TODO: Resolve
			NiKeyframeManager = 0xFFFFFFFF, // TODO: Resolve
			NiLight = 0xFFFFFFFF, // TODO: Resolve
			NiLightColorController = 0xFFFFFFFF, // TODO: Resolve
			NiLines = 0xFFFFFFFF, // TODO: Resolve
			NiLinesData = 0xFFFFFFFF, // TODO: Resolve
			NiLODNode = 0xFFFFFFFF, // TODO: Resolve
			NiLookAtController = 0xFFFFFFFF, // TODO: Resolve
			NiMaterialColorController = 0xFFFFFFFF, // TODO: Resolve
			NiMaterialProperty = 0xFFFFFFFF, // TODO: Resolve
			NiMorphData = 0xFFFFFFFF, // TODO: Resolve
			NiMorpherController = 0xFFFFFFFF, // TODO: Resolve
			NiNode = 0x6D7260,
			NiObject = 0xFFFFFFFF, // TODO: Resolve
			NiObjectNET = 0xFFFFFFFF, // TODO: Resolve
			NiPalette = 0xFFFFFFFF, // TODO: Resolve
			NiParticleBomb = 0xFFFFFFFF, // TODO: Resolve
			NiParticleCollider = 0xFFFFFFFF, // TODO: Resolve
			NiParticleColorModifier = 0xFFFFFFFF, // TODO: Resolve
			NiParticleGrowFade = 0xFFFFFFFF, // TODO: Resolve
			NiParticleModifier = 0xFFFFFFFF, // TODO: Resolve
			NiParticleRotation = 0xFFFFFFFF, // TODO: Resolve
			NiParticles = 0xFFFFFFFF, // TODO: Resolve
			NiParticlesData = 0xFFFFFFFF, // TODO: Resolve
			NiParticleSystemController = 0xFFFFFFFF, // TODO: Resolve
			NiPathController = 0xFFFFFFFF, // TODO: Resolve
			NiPixelData = 0xFFFFFFFF, // TODO: Resolve
			NiPlanarCollider = 0xFFFFFFFF, // TODO: Resolve
			NiPointLight = 0xFFFFFFFF, // TODO: Resolve
			NiPosData = 0xFFFFFFFF, // TODO: Resolve
			NiProperty = 0xFFFFFFFF, // TODO: Resolve
			NiRenderedCubeMap = 0xFFFFFFFF, // TODO: Resolve
			NiRenderedTexture = 0xFFFFFFFF, // TODO: Resolve
			NiRenderer = 0xFFFFFFFF, // TODO: Resolve
			NiRendererSpecificProperty = 0xFFFFFFFF, // TODO: Resolve
			NiRollController = 0xFFFFFFFF, // TODO: Resolve
			NiRotatingParticles = 0xFFFFFFFF, // TODO: Resolve
			NiRotatingParticlesData = 0xFFFFFFFF, // TODO: Resolve
			NiScreenPolygon = 0xFFFFFFFF, // TODO: Resolve
			NiSequenceStreamHelper = 0xFFFFFFFF, // TODO: Resolve
			NiShadeProperty = 0xFFFFFFFF, // TODO: Resolve
			NiSkinData = 0xFFFFFFFF, // TODO: Resolve
			NiSkinInstance = 0xFFFFFFFF, // TODO: Resolve
			NiSkinPartition = 0xFFFFFFFF, // TODO: Resolve
			NiSortAdjustNode = 0xFFFFFFFF, // TODO: Resolve
			NiSourceTexture = 0xFFFFFFFF, // TODO: Resolve
			NiSpecularProperty = 0xFFFFFFFF, // TODO: Resolve
			NiSphericalCollider = 0xFFFFFFFF, // TODO: Resolve
			NiSpotLight = 0xFFFFFFFF, // TODO: Resolve
			NiStencilProperty = 0xFFFFFFFF, // TODO: Resolve
			NiStringExtraData = 0x6D77D4,
			NiSwitchNode = 0xFFFFFFFF, // TODO: Resolve
			NiTextKeyExtraData = 0xFFFFFFFF, // TODO: Resolve
			NiTexture = 0xFFFFFFFF, // TODO: Resolve
			NiTextureEffect = 0xFFFFFFFF, // TODO: Resolve
			NiTexturingProperty = 0xFFFFFFFF, // TODO: Resolve
			NiTimeController = 0xFFFFFFFF, // TODO: Resolve
			NiTriBasedGeom = 0xFFFFFFFF, // TODO: Resolve
			NiTriBasedGeomData = 0xFFFFFFFF, // TODO: Resolve
			NiTriShape = 0xFFFFFFFF, // TODO: Resolve
			NiTriShapeData = 0xFFFFFFFF, // TODO: Resolve
			NiTriShapeDynamicData = 0xFFFFFFFF, // TODO: Resolve
			NiTriStrips = 0xFFFFFFFF, // TODO: Resolve
			NiTriStripsData = 0xFFFFFFFF, // TODO: Resolve
			NiUVController = 0xFFFFFFFF, // TODO: Resolve
			NiUVData = 0xFFFFFFFF, // TODO: Resolve
			NiVertexColorProperty = 0xFFFFFFFF, // TODO: Resolve
			NiVertWeightsExtraData = 0xFFFFFFFF, // TODO: Resolve
			NiVisController = 0xFFFFFFFF, // TODO: Resolve
			NiVisData = 0xFFFFFFFF, // TODO: Resolve
			NiWireframeProperty = 0xFFFFFFFF, // TODO: Resolve
			NiZBufferProperty = 0xFFFFFFFF, // TODO: Resolve
			OffscreenSceneGraph_MasterPropertyAccumulator = 0xFFFFFFFF, // TODO: Resolve
			RootCollisionNode = 0xFFFFFFFF, // TODO: Resolve
			TES3ObjectExtraData = 0xFFFFFFFF, // TODO: Resolve
		};
	}

	struct Object {
		struct VirtualTable {
			void(__thiscall* destructor)(Object*, int); // 0x0
			RTTI* (__thiscall* getRTTI)(const Object*); // 0x4
			Object* (__thiscall* createClone)(Object*); // 0x8
			void(__thiscall* loadBinary)(Object*, void*); // 0xC
			void(__thiscall* linkObject)(Object*, void*); // 0x10
			bool(__thiscall* registerStreamables)(Object*, void*); // 0x14
			void(__thiscall* saveBinary)(Object*, void*); // 0x18
			bool(__thiscall* isEqual)(const Object*, const Object*); // 0x1C
			void(__thiscall* addViewerStrings)(Object*, void*); // 0x20
			void(__thiscall* processClone)(Object*); // 0x24
			void(__thiscall* createRendererData)(Object*); // 0x28
		};
		VirtualTable* vtbl; // 0x0
		unsigned int refCount; // 0x4

		RTTI* getRTTI() const {
			return vtbl->getRTTI(this);
		}

		bool isOfType(const RTTI* type) const {
			return vtbl->getRTTI(this) == type;
		}

		bool isOfType(uintptr_t rtti) const {
			return isOfType(reinterpret_cast<RTTI*>(rtti));
		}

		bool isInstanceOfType(const RTTI* type) const {
			for (const RTTI* rtti = vtbl->getRTTI(this); rtti; rtti = rtti->baseRTTI) {
				if (rtti == type) {
					return true;
				}
			}

			return false;
		}

		bool isInstanceOfType(uintptr_t rtti) const {
			return isInstanceOfType(reinterpret_cast<RTTI*>(rtti));
		}
	};
	static_assert(sizeof(Object::VirtualTable) == 0x2C, "NI::Object's vtable failed size validation");

	struct ExtraData : Object {
		size_t genericDataLength; // 0x8
		void* genericData; // 0xC // Only loaded if NiExtraData isn't subclassed.
		ExtraData* next; // 0x10

	};
	static_assert(sizeof(ExtraData) == 0x14, "NI::TextKey failed size validation");

	struct StringExtraData : ExtraData {
		char* string; // 0x14
	};
	static_assert(sizeof(StringExtraData) == 0x18, "NI::StringExtraData failed size validation");

	struct ObjectNET : Object {
		char* name; // 0x8
		ExtraData* extraData; // 0xC
		void* controllers; // 0x10

		bool hasStringDataWithValue(const char* value) const {
			if (!value) {
				return false;
			}

			const auto keylen = strnlen_s(value, 128);

			auto extra = extraData;
			while (extra) {
				const auto stringData = static_cast<NI::StringExtraData*>(extra);
				if (extra->isInstanceOfType(NI::RTTIStaticPtr::NiStringExtraData) && stringData->string) {
					if (_strnicmp(value, stringData->string, keylen) == 0) {
						return true;
					}
				}
				extra = extra->next;
			}
			return false;
		}
	};

	struct AVObject : ObjectNET {
		struct VirtualTable : Object::VirtualTable {
			void(__thiscall* updateControllers)(AVObject*, float); // 0x2C
			void(__thiscall* applyTransform)(AVObject*, Matrix33*, Vector3*, bool); // 0x30
			void* (__thiscall* getWorldBound)(AVObject*); // 0x34
			void(__thiscall* createWorldVertices)(AVObject*); // 0x38
			void(__thiscall* updateWorldVertices)(AVObject*); // 0x3C
			void(__thiscall* destroyWorldVertices)(AVObject*); // 0x40
			void(__thiscall* createWorldNormals)(AVObject*); // 0x44
			void(__thiscall* updateWorldNormals)(AVObject*); // 0x48
			void(__thiscall* destroyWorldNormals)(AVObject*); // 0x4C
			void(__thiscall* setAppCulled)(AVObject*, bool); // 0x50
			bool(__thiscall* getAppCulled)(AVObject*); // 0x54
			void(__thiscall* setPropagationMode)(AVObject*, int); // 0x58
			AVObject* (__thiscall* getObjectByName)(AVObject*, const char*); // 0x5C
			void(__thiscall* updateDownwardPass)(AVObject*, float, bool, bool); // 0x60
			bool(__thiscall* isVisualObject)(AVObject*); // 0x64
			void(__thiscall* updatePropertiesDownward)(AVObject*, void*); // 0x68
			void(__thiscall* updateEffectsDownward)(AVObject*, void*); // 0x6C
			void* (__thiscall* getPropertyState)(AVObject*, void**); // 0x70
			void* (__thiscall* getEffectsState)(AVObject*, void**); // 0x74
			void(__thiscall* display)(AVObject*, void*); // 0x78
			void(__thiscall* updateCollisionData)(AVObject*); // 0x7C
			bool(__thiscall* testCollisions)(AVObject*, float, void*, void*); // 0x80
			int(__thiscall* findCollisions)(AVObject*, float, void*, void*); // 0x84
			bool(__thiscall* findIntersections)(AVObject*, Vector3*, Vector3*, void*); // 0x88
			void(__thiscall* updateWorldData)(AVObject*); // 0x8C
			void(__thiscall* updateWorldBound)(AVObject*); // 0x90
		};
		unsigned short flags; // 0x14
		short pad_16;
		Node* parentNode; // 0x18
		Vector3 worldBoundOrigin; // 0x1C
		float worldBoundRadius; // 0x28
		Matrix33* localRotation; // 0x2C
		Vector3 localTranslate; // 0x30
		float localScale; // 0x3C
		Transform worldTransform; // 0x40
		void* velocities; // 0x74
		void* modelABV; // 0x78
		void* worldABV; // 0x7C
		int(__cdecl* collideCallback)(void*); // 0x80
		void* collideCallbackUserData; // 0x84
		LinkedList<void> propertyNode; // 0x88

		void setAppCulled(bool culled) {
			static_cast<AVObject::VirtualTable*>(vtbl)->setAppCulled(this, culled);
		}

		AVObject* getObjectByName(const char* name) {
			const auto getObjByName = static_cast<AVObject::VirtualTable*>(vtbl)->getObjectByName;
			return static_cast<AVObject::VirtualTable*>(vtbl)->getObjectByName(this, name);
		}
	};
	static_assert(sizeof(AVObject) == 0x90, "NI::AVObject failed size validation");
	static_assert(sizeof(AVObject::VirtualTable) == 0x94, "NI::AVObject's vtable failed size validation");

	struct Node : AVObject {
		TArray<AVObject*> children; // 0x90
		LinkedList<void*> effectList; // 0xA8
	};
	static_assert(sizeof(Node) == 0xB0, "NI::Node failed size validation");

	struct Frustum {
		float left; // 0x0
		float right; // 0x4
		float top; // 0x8
		float bottom; // 0xC
		float near; // 0x10
		float far; // 0x14
	};

	struct Camera : AVObject {
		Matrix44 worldToCamera; // 0x90
		float viewDistance; // 0xD0
		float twoDivRmL; // 0xD4
		float twoDivTmB; // 0xD8
		Vector3 worldDirection; // 0xDC
		Vector3 worldUp; // 0xE8
		Vector3 worldRight; // 0xF4
		Frustum viewFrustum; // 0x100
		Vector4 port; // 0x118
		Node* scene; // 0x128
		TArray<void*> unknown_0x12C; // Screen related?
		Renderer* renderer; // 0x144
		TArray<void*> unknown_0x148; // Multiple cameras?
		int unknown_0x160;
		Vector4 cullingPlanes[6]; // 0x164
		float unknown_0x1C4;
		float unknown_0x1C8;
		float unknown_0x1CC;
		float unknown_0x1D0;
		void* unknown_0x1D4;
		int unknown_0x1D8;
		float LODAdjust; // 0x1DC
	};
	static_assert(sizeof(Camera) == 0x1E0, "NI::Camera failed size validation");
}

namespace TES3 {
	namespace ObjectType {
		enum ObjectType {
			Invalid = 0,
			Activator = 'ITCA',
			Alchemy = 'HCLA',
			Ammo = 'OMMA',
			AnimationGroup = 'GINA',
			Apparatus = 'APPA',
			Armor = 'OMRA',
			Birthsign = 'NGSB',
			Bodypart = 'YDOB',
			Book = 'KOOB',
			Cell = 'LLEC',
			Class = 'SALC',
			Clothing = 'TOLC',
			Container = 'TNOC',
			Creature = 'AERC',
			CreatureClone = 'CERC',
			Dialogue = 'LAID',
			DialogueInfo = 'OFNI',
			Door = 'ROOD',
			Enchantment = 'HCNE',
			Faction = 'TCAF',
			GameSetting = 'TSMG',
			Global = 'BOLG',
			Ingredient = 'RGNI',
			Land = 'DNAL',
			LandTexture = 'XETL',
			LeveledCreature = 'CVEL',
			LeveledItem = 'IVEL',
			Light = 'HGIL',
			Lockpick = 'KCOL',
			MagicEffect = 'FEGM',
			MagicSourceInstance = 'LLPS',
			Misc = 'CSIM',
			MobileCreature = 'RCAM',
			MobileNPC = 'HCAM',
			MobileObject = 'TCAM',
			MobilePlayer = 'PCAM',
			MobileProjectile = 'JRPM',
			MobileSpellProjectile = 'PSPM',
			NPC = '_CPN',
			NPCClone = 'CCPN',
			PathGrid = 'DRGP',
			Probe = 'BORP',
			Quest = 'SEUQ',
			Race = 'ECAR',
			Reference = 'RFER',
			Region = 'NGER',
			Repair = 'APER',
			Script = 'TPCS',
			Skill = 'LIKS',
			Sound = 'NUOS',
			SoundGenerator = 'GDNS',
			Spell = 'LEPS',
			Static = 'TATS',
			TES3 = '3SET',
			Weapon = 'PAEW',
		};
	}

	struct GameFile {
		unsigned int unknown_0x0;
		unsigned int unknown_0x4;
		unsigned int unknown_0x8;
		char fileName[260];
		char filePath[260];
	};

	struct BaseObject {
		struct VirtualTable {
			void(__thiscall* destructor)(BaseObject*, signed char); // 0x0
			int(__thiscall* loadObjectSpecific)(BaseObject*, GameFile*); // 0x4
			int(__thiscall* saveRecordSpecific)(BaseObject*, GameFile*); // 0x8
			int(__thiscall* loadObject)(BaseObject*, GameFile*); // 0xC
			int(__thiscall* saveObject)(BaseObject*, GameFile*); // 0x10
			void(__thiscall* setObjectModified)(BaseObject*, bool); // 0x14
			int(__thiscall* setObjectFlag40)(BaseObject*, unsigned char); // 0x18
			void* unknown_0x1C;
			const char* (__thiscall* getObjectID)(const BaseObject*); // 0x20
		};
		VirtualTable* vtbl; // 0x0
		ObjectType::ObjectType objectType; // 0x4
		unsigned int flags; // 0x8
		GameFile* sourceFile; // 0xC

		const char* getObjectID() const {
			return vtbl->getObjectID(this);
		}
	};
	static_assert(sizeof(BaseObject) == 0x10, "TES3::BaseObject failed size validation");

	struct Object : BaseObject {
		NI::AVObject* sceneNode; // 0x10
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
	};

	struct DialogueInfo : BaseObject {
		struct LoadLinkNode {
			const char* name; // 0x0
			const char* previous; // 0x4
			const char* next; // 0x8
		};
		LoadLinkNode* loadLinkNodes; // 0x10
		int unknown_0x14;
		int unknown_0x18;
		unsigned char npcRank; // 0x1C
		unsigned char npcSex; // 0x1D
		unsigned char pcRank; // 0x1E
		unsigned char unknown_0x1F;
		char unknown_0x20[60];
		int unknown_0x5C[18];
	};
	static_assert(sizeof(DialogueInfo) == 0xA4, "TES3::DialogueInfo failed size validation");

	struct Dialogue : BaseObject {
		const char* id; // 0x10
		unsigned char type; // 0x14
		IteratedList<DialogueInfo*> topics; // 0x18
	};
	static_assert(sizeof(Dialogue) == 0x2C, "TES3::Dialogue failed size validation");

	struct RecordHandler {
		int activeModCount; // 0x0
		int unknown_0x4[13];
		IteratedList<Dialogue*>* dialogues; // 0x38
		int unknown_0x3C[10975];
		GameFile* activeGameFiles[256]; // 0xABB8
		// ...
	};
	static_assert(offsetof(RecordHandler, activeGameFiles) == 0xABB8, "TES3::RecordHandler failed offset validation");

	struct ReferenceTransformationAttachment {
		NI::Vector3 orientation;
		NI::Vector3 position;
	};

	struct Reference : Object {
		BaseObject* baseObject; // 0x28
		NI::Vector3 orientationNonAttached; //0x2C
		NI::Vector3 anotherOrientation; //0x38
		NI::Vector3 yetAnotherOrientation; //0x44
		NI::Vector3 position; // 0x50
	};

	struct TranslationData {
		enum class RotationAxis : unsigned int {
			X = 1,
			Z = 2,
			Y = 3,
		};
		struct Target {
			TES3::Reference* reference; // 0x0
			Target* previous; // 0x4
			Target* next; // 0x8
		};
		Target* firstTarget; // 0x0
		unsigned int numberOfTargets; // 0x4
		NI::Vector3 position; // 0x8
		void* unknown_0x14;
	};
}

static TES3::GameFile* master_Morrowind = nullptr;
static TES3::GameFile* master_Tribunal = nullptr;
static TES3::GameFile* master_Bloodmoon = nullptr;

bool isVanillaMaster(TES3::GameFile* master) {
	return (master_Morrowind && master == master_Morrowind)
		|| (master_Tribunal && master == master_Tribunal)
		|| (master_Bloodmoon && master == master_Bloodmoon);
}

const auto TES3_RecordHandler_whoCares = reinterpret_cast<void(__thiscall*)(TES3::RecordHandler*)>(0x4041C4);
void __fastcall Patch_FindVanillaMasters(TES3::RecordHandler* recordHandler) {
	const auto constHandler = recordHandler;
	for (auto i = 0; i < constHandler->activeModCount; ++i) {
		const auto gameFile = constHandler->activeGameFiles[i];
		if (master_Morrowind == nullptr && _strnicmp(gameFile->fileName, "Morrowind.esm", 260) == 0) {
			master_Morrowind = gameFile;
		}
		else if (master_Tribunal == nullptr && _strnicmp(gameFile->fileName, "Tribunal.esm", 260) == 0) {
			master_Tribunal = gameFile;
		}
		else if (master_Bloodmoon == nullptr && _strnicmp(gameFile->fileName, "Bloodmoon.esm", 260) == 0) {
			master_Bloodmoon = gameFile;
		}
	}

	TES3_RecordHandler_whoCares(recordHandler);
}

const auto TES3_Dialogue_resolveLinks = reinterpret_cast<void(__thiscall*)(TES3::Dialogue*, void*)>(0x4F30C0);
void __fastcall Patch_SuppressDialogueInfoResolveIssues(TES3::Dialogue* dialogue, DWORD _EDX_, void* recordHandler) {
	const auto cachedValue = mwse::memory::MemAccess<bool>::Get(0x6D0B6E);
	mwse::memory::MemAccess<bool>::Set(0x6D0B6E, true);
	TES3_Dialogue_resolveLinks(dialogue, recordHandler);
	mwse::memory::MemAccess<bool>::Set(0x6D0B6E, cachedValue);
}

const auto ShowDuplicateReferenceWarning = reinterpret_cast<bool(__cdecl*)(const char*, int)>(0x40123A);
bool __cdecl PatchSuppressDuplicateReferenceRemovedWarningForVanillaMasters(const char* message, int referenceCount) {
	if (referenceCount == 1 && master_Tribunal && master_Bloodmoon) {
		const auto cachedValue = mwse::memory::MemAccess<bool>::Get(0x6D0B6E);
		mwse::memory::MemAccess<bool>::Set(0x6D0B6E, true);
		auto result = ShowDuplicateReferenceWarning(message, referenceCount);
		mwse::memory::MemAccess<bool>::Set(0x6D0B6E, cachedValue);
		return result;
	}
	else {
		return ShowDuplicateReferenceWarning(message, referenceCount);
	}
}

static auto last2ndClassUpdateTime = std::chrono::milliseconds::zero();
const auto TES3CS_UpdateStatusMessage = reinterpret_cast<void(__cdecl*)(WPARAM, LPARAM)>(0x404881);
void __cdecl PatchThrottleMessageUpdate(WPARAM type, LPARAM lParam) {
	if (type == 2) {
		const auto now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch());
		const auto msSinceLastUpdate = now - last2ndClassUpdateTime;
		if (msSinceLastUpdate.count() < 20) {
			return;
		}
		last2ndClassUpdateTime = now;
	}
	else {
		last2ndClassUpdateTime = std::chrono::milliseconds::zero();
	}
	TES3CS_UpdateStatusMessage(type, lParam);
}

constexpr auto M_PI = 3.14159265358979323846; // pi
constexpr auto M_PIf = float(M_PI); // pi
constexpr auto M_2PI = 2.0 * M_PI; // 2pi
constexpr auto M_2PIf = float(M_2PI);
constexpr auto M_DEGREES_TO_RADIANS = M_PI / 180.0;

void fmodZeroTo2pi(float& value) {
	while (value > M_2PIf) {
		value -= M_2PIf;
	}
	while (value < 0.0f) {
		value += M_2PIf;
	}
}

inline bool isKeyDown(int key) {
	return (GetKeyState(key) & 0x8000) != 0;
}

const auto TES3_CS_OriginalRotationLogic = reinterpret_cast<bool(__cdecl*)(void*, TES3::TranslationData::Target*, int, TES3::TranslationData::RotationAxis)>(0x4652D0);
bool __cdecl Patch_ReplaceRotationLogic(void* unknown1, TES3::TranslationData::Target* firstTarget, int relativeMouseDelta, TES3::TranslationData::RotationAxis rotationAxis) {
	// Allow holding ALT modifier to do vanilla behavior.
	if (isKeyDown(VK_MENU)) {
		return TES3_CS_OriginalRotationLogic(unknown1, firstTarget, relativeMouseDelta, rotationAxis);
	}

	if (relativeMouseDelta == 0) {
		return false;
	}

	auto data = mwse::memory::MemAccess<TES3::TranslationData*>::Get(0x6CE968);

	auto rotationSpeed = mwse::memory::MemAccess<float>::Get(0x6CE9B0);
	auto rotationFlags = mwse::memory::MemAccess<BYTE>::Get(0x6CE9A4);

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	
	if (!isKeyDown('X') && !isKeyDown('Y')) {
		rotationAxis = TES3::TranslationData::RotationAxis::Z;
	}

	switch (rotationAxis) {
	case TES3::TranslationData::RotationAxis::X:
		x += relativeMouseDelta * rotationSpeed * 0.1f;
		break;
	case TES3::TranslationData::RotationAxis::Y:
		y += relativeMouseDelta * rotationSpeed * 0.1f;
		break;
	case TES3::TranslationData::RotationAxis::Z:
		z += relativeMouseDelta * rotationSpeed * 0.1f;
		break;
	}

	bool isSnapping = (rotationFlags & 2) != 0;
	if (isSnapping) {
		const auto snapAngleInRadians = mwse::memory::MemAccess<int>::Get(0x6CE9AC) * float(M_DEGREES_TO_RADIANS);
		if (snapAngleInRadians != 0.0f) {
			x = std::roundf(x / snapAngleInRadians) * snapAngleInRadians;
			y = std::roundf(y / snapAngleInRadians) * snapAngleInRadians;
			z = std::roundf(z / snapAngleInRadians) * snapAngleInRadians;
		}
	}

	fmodZeroTo2pi(x);
	fmodZeroTo2pi(y);
	fmodZeroTo2pi(z);

	// Seems to crash when performing an undo if you don't set this vector.
	auto& undoRotation = *reinterpret_cast<NI::Vector3*>(0x6CF760);
	undoRotation.x = x;
	undoRotation.y = y;
	undoRotation.z = z;

	// Due to snapping these may have been set to 0, in which case no need to do anything else.
	if (x == 0.0f && y == 0.0f && z == 0.0f) {
		return 0;
	}

	auto userRotation = NI::Matrix33::fromEulerXYZ(x, y, z);

	for (auto target = data->firstTarget; target; target = target->next) {
		auto reference = target->reference;

		reinterpret_cast<void(__thiscall*)(TES3::Reference*)>(0x4026E4)(reference);
		reinterpret_cast<void(__thiscall*)(TES3::BaseObject*, bool)>(0x4019E7)(reference->baseObject, true);

		// Disallow XY rotations on actors and northmarkers.
		auto doRotations = true;
		if (rotationAxis != TES3::TranslationData::RotationAxis::Z) {
			switch (reference->baseObject->objectType) {
			case TES3::ObjectType::Creature:
			case TES3::ObjectType::LeveledCreature:
			case TES3::ObjectType::NPC:
				doRotations = false;
				break;
			case TES3::ObjectType::Static:
				if (reference->baseObject == mwse::memory::MemAccess<TES3::BaseObject*>::Get(0x6D566C)) {
					doRotations = false;
					break;
				}
			}
		}

		if (doRotations) {
			NI::Matrix33* oldRotation = reference->sceneNode->localRotation;
			NI::Matrix33 newRotation = userRotation.multiplyValue(oldRotation);

			reference->yetAnotherOrientation = newRotation.toEulerXYZ();
			fmodZeroTo2pi(reference->yetAnotherOrientation.x);
			fmodZeroTo2pi(reference->yetAnotherOrientation.y);
			fmodZeroTo2pi(reference->yetAnotherOrientation.z);
			reference->orientationNonAttached = reference->yetAnotherOrientation;

			// ??
			// auto matrix = reinterpret_cast<NI::Matrix33 * (__thiscall*)(TES3::Reference*, NI::Matrix33*, bool)>(0x4028B0)(reference, &newRotation, false);
			reinterpret_cast<void(__thiscall*)(NI::Matrix33**, NI::Matrix33*)>(0x5E1970)(&reference->sceneNode->localRotation, &newRotation);
		}

		// Rotate positions.
		if (data->numberOfTargets > 1) {
			auto p = reference->position - data->position;
			reference->position = userRotation.multiplyValue(&p) + data->position;
			reference->sceneNode->localTranslate = reference->position;
		}

		// ?? (sceneNode->update()?)
		reinterpret_cast<void(__thiscall*)(NI::AVObject*, int, int, int)>(0x5DAFB0)(reference->sceneNode, 0, 1, 1);
	}

	return true;
}

static std::unordered_map<TES3::Object*, bool> validEditorMarkers;

void SetCullOnTriEditorMarkers(NI::AVObject* object, bool cull) {
	if (object->isInstanceOfType(NI::RTTIStaticPtr::NiNode)) {
		for (auto& child : static_cast<NI::Node*>(object)->children) {
			if (child) {
				SetCullOnTriEditorMarkers(child, cull);
			}
		}
	}
	else if (object->name) {
		if (_strnicmp(object->name, "Tri EditorMarker", 12) == 0) {
			object->setAppCulled(cull);
		}
	}
}

const auto TES3_Object_IsMarker = reinterpret_cast<bool(__thiscall*)(TES3::BaseObject*)>(0x549B20);
void __fastcall PatchEditorMarkers(TES3::Reference* reference, bool cull) {
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

void installPatches() {
	// Get the vanilla masters so we suppress errors from them.
	mwse::memory::genCallEnforced(0x50194E, 0x4041C4, reinterpret_cast<DWORD>(Patch_FindVanillaMasters));

	// Patch: Suppress "[Following/Previous] string is different for topic" warning popups for vanilla masters.
	mwse::memory::genJumpEnforced(0x4023BA, 0x4F30C0, reinterpret_cast<DWORD>(Patch_SuppressDialogueInfoResolveIssues));

	// Patch: Suppress "1 duplicate references were removed" warning popups for vanilla masters.
	mwse::memory::genCallEnforced(0x50A9ED, 0x40123A, reinterpret_cast<DWORD>(PatchSuppressDuplicateReferenceRemovedWarningForVanillaMasters));

	// Patch: Use world rotation values.
	mwse::memory::genJumpEnforced(0x403D41, 0x4652D0, reinterpret_cast<DWORD>(Patch_ReplaceRotationLogic));

	// Patch: Custom marker toggling code.
	mwse::memory::writePatchCodeUnprotected(0x49E932, (BYTE*)PatchEditorMarkers_Setup, PatchEditorMarkers_Setup_Size);
	mwse::memory::genCallUnprotected(0x49E932 + PatchEditorMarkers_Setup_Size, reinterpret_cast<DWORD>(PatchEditorMarkers), 0x49E94D - 0x49E932 - PatchEditorMarkers_Setup_Size);

	// Patch: Throttle UI status updates.
	mwse::memory::genCallEnforced(0x4BCBBC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4BD489, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4BD503, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C0C84, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C0F39, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C0FB3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C1DFF, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C3C1D, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C9AE9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C9B63, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C41C3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C72D7, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C77B9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C2319, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C2393, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C4149, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C7833, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4C9607, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CB4B1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CB809, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CB883, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CCD54, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CD0F3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CD079, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CE0F7, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CE4F3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CE479, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CF733, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CFB49, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4CFBC3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D0DB7, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D3C09, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D3C83, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D7ED9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D27A3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D83CD, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D1119, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D1193, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D2313, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D2729, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D3893, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4D8353, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4DAA82, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4DAE03, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4DAE7F, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4DCF81, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4DD6D3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4DD659, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4DFF8B, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E2BB1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E2F89, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E03F3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E5B7F, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E9ABA, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E61A8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E84F8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E0379, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E3003, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4E6223, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4F0FC2, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4F0FFB, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4F3E52, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4F3FDB, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4F4124, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4FA2D8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4FA83E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4FA490, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x44B8E2, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x44B940, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x44BBD6, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x44BC0C, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x44BFBE, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x44BFCA, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45C8BE, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45C8D0, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45C9ED, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45C962, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45CA7E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45CA48, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45CA54, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45CA60, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45CACE, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45CADA, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x45CAE6, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46B56A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46B59F, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46BF8F, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46C3CC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46C5C6, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46C9A1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46C768, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46CBA1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46CCB1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x46E6CD, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x49FE06, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x49FE44, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x50A597, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x50F5E1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x52F8B8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x53A727, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x53AA8E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x53AB07, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x53AFF0, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x53B3B9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x53B432, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x54D9D9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x54D39A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x54DA53, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x501A6B, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x501AA6, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x501AEC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x501B7C, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x501BDB, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x501F7E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x502E50, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x503DEC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x504DE8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x505C32, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x505E58, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x551DF5, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4096D8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4098AC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x4098D4, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x5043D0, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x5300D3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x5527BF, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x5535DE, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x40969E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x40978D, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x50187A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x50255C, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x55284A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x55354A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x409805, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x409848, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x412391, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x412848, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x412889, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x467150, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x501944, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x502705, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x502953, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x503363, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x503425, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x503761, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x504221, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x524537, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x524919, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x524993, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x530059, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	mwse::memory::genCallEnforced(0x552821, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
		logstream.open("csse.log");
		installPatches();
		logstream << "CSSE initialization complete." << std::endl;
		break;
    }
    return TRUE;
}

