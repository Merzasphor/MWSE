// dllmain.cpp : Defines the entry point for the DLL application.

#include "TES3IteratedList.h"

static std::ofstream logstream;
static unsigned int patchCount = 0;

template <class T>
class MemAccess {
public:
	static inline T Get(uintptr_t address) {
		return *reinterpret_cast<T*>(address);
	}

	static inline void Set(uintptr_t address, T value) {
		*reinterpret_cast<T*>(address) = value;
	}
};

void genNOP(DWORD Address) {
	MemAccess<unsigned char>::Set(Address, 0x90);
}

bool genCallEnforced(DWORD address, DWORD previousTo, DWORD to, DWORD size = 0x5) {
	// Make sure we're doing a call.
	BYTE instruction = *reinterpret_cast<BYTE*>(address);
	if (instruction != 0xE8) {
#if _DEBUG
		logstream << "[MemoryUtil] Skipping call generation at 0x" << std::hex << address << ". Expected 0xe8, found instruction: 0x" << (int)instruction << "." << std::endl;
#endif
		return false;
	}

	// Read previous call address to make sure it's what we are expecting.
	DWORD currentCallAddress = *reinterpret_cast<DWORD*>(address + 1) + address + 0x5;
	if (currentCallAddress != previousTo) {
#if _DEBUG
		logstream << "[MemoryUtil] Skipping call generation at 0x" << std::hex << address << ". Expected previous call to 0x" << previousTo << ", found 0x" << currentCallAddress << "." << std::endl;
#endif
		return false;
	}

	// Unprotect memory.
	DWORD oldProtect;
	VirtualProtect((DWORD*)address, size, PAGE_READWRITE, &oldProtect);

	// Create our call.
	MemAccess<unsigned char>::Set(address, 0xE8);
	MemAccess<DWORD>::Set(address + 1, to - address - 0x5);

	// NOP out the rest of the block.
	for (DWORD i = address + 5; i < address + size; ++i) {
		genNOP(i);
	}

	// Protect memory again.
	VirtualProtect((DWORD*)address, size, oldProtect, &oldProtect);

	++patchCount;
	return true;
}

bool genJumpEnforced(DWORD address, DWORD previousTo, DWORD to, DWORD size = 0x5) {
	// Make sure we're doing a jump.
	BYTE instruction = *reinterpret_cast<BYTE*>(address);
	if (instruction != 0xE9) {
#if _DEBUG
		logstream << "[MemoryUtil] Skipping jump generation at 0x" << std::hex << address << ". Expected 0xe9, found instruction: 0x" << (int)instruction << "." << std::endl;
#endif
		return false;
	}

	// Read previous jump address to make sure it's what we are expecting.
	DWORD currentCallAddress = *reinterpret_cast<DWORD*>(address + 1) + address + 0x5;
	if (currentCallAddress != previousTo) {
#if _DEBUG
		logstream << "[MemoryUtil] Skipping jump generation at 0x" << std::hex << address << ". Expected previous jump to 0x" << previousTo << ", found 0x" << currentCallAddress << "." << std::endl;
#endif
		return false;
	}

	// Unprotect memory.
	DWORD oldProtect;
	VirtualProtect((DWORD*)address, size, PAGE_READWRITE, &oldProtect);

	// Create our jump.
	MemAccess<unsigned char>::Set(address, 0xE9);
	MemAccess<DWORD>::Set(address + 1, to - address - 0x5);

	// NOP out the rest of the block.
	for (DWORD i = address + 5; i < address + size; ++i) {
		genNOP(i);
	}

	// Protect memory again.
	VirtualProtect((DWORD*)address, size, oldProtect, &oldProtect);

	++patchCount;
	return true;
}

bool writeDoubleWordEnforced(DWORD address, DWORD previousValue, DWORD value) {
	DWORD currentValue = *reinterpret_cast<DWORD*>(address);
	if (currentValue != previousValue) {
#ifdef _DEBUG
		logstream << "[MemoryUtil] Skipping write double word at 0x" << std::hex << address << ". Expected previous value of 0x" << previousValue << ", found 0x" << currentValue << "." << std::endl;
#endif
		return false;
	}

	// Unprotect memory.
	DWORD oldProtect;
	VirtualProtect((DWORD*)address, sizeof(DWORD), PAGE_READWRITE, &oldProtect);

	// Overwrite our single byte.
	MemAccess<DWORD>::Set(address, value);

	// Protect memory again.
	VirtualProtect((DWORD*)address, sizeof(DWORD), oldProtect, &oldProtect);

	return true;
}

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
		RTTI* parent; // 0x4
	};

	struct Object {
		struct VirtualTable {
			void(__thiscall* destructor)(Object*, int); // 0x0
			RTTI* (__thiscall* getRTTI)(const Object*); // 0x4
		};
		VirtualTable* vtbl; // 0x0
		unsigned int refCount; // 0x4

		RTTI* getRTTI() const {
			return vtbl->getRTTI(this);
		}
	};

	struct ObjectNET : Object {
		char* name; // 0x8
		void* extraData; // 0xC
		void* controllers; // 0x10
	};

	template <typename T>
	struct LinkedList {
		T* data;
		LinkedList<T>* next;
	};
	static_assert(sizeof(LinkedList<void>) == 0x8, "NI::LinkedList failed size validation");

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
		void* velocities; // 0x74
		void* modelABV; // 0x78
		void* worldABV; // 0x7C
		int(__cdecl* collideCallback)(void*); // 0x80
		void* collideCallbackUserData; // 0x84
		LinkedList<void> propertyNode; // 0x88
	};

	struct Frustum {
		float left; // 0x0
		float right; // 0x4
		float top; // 0x8
		float bottom; // 0xC
		float near; // 0x10
		float far; // 0x14
	};

	template <typename T>
	struct TArray {
		void* vtbl;
		T* storage; // 0x4
		size_t storageCount; // 0x8 // # of slots in the array.
		size_t endIndex; // 0xC // First empty slot in the array.
		size_t filledCount; // 0x10 // Number of filled slots.
		size_t growByCount; // 0x14 // Number of slots to increase storage by.
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
		void* vtbl; // 0x0
		ObjectType::ObjectType objectType; // 0x4
		unsigned int flags; // 0x8
		GameFile* sourceFile; // 0xC
	};
	static_assert(sizeof(BaseObject) == 0x10, "TES3::BaseObject failed size validation");

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

	struct Reference : BaseObject {
		NI::AVObject* sceneNode; // 0x10
		int unknown_0x14;
		int unknown_0x18;
		int unknown_0x1C;
		int unknown_0x20;
		int unknown_0x24;
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
	const auto cachedValue = MemAccess<bool>::Get(0x6D0B6E);
	MemAccess<bool>::Set(0x6D0B6E, true);
	TES3_Dialogue_resolveLinks(dialogue, recordHandler);
	MemAccess<bool>::Set(0x6D0B6E, cachedValue);
}

const auto ShowDuplicateReferenceWarning = reinterpret_cast<bool(__cdecl*)(const char*, int)>(0x40123A);
bool __cdecl PatchSuppressDuplicateReferenceRemovedWarningForVanillaMasters(const char* message, int referenceCount) {
	if (referenceCount == 1 && master_Tribunal && master_Bloodmoon) {
		const auto cachedValue = MemAccess<bool>::Get(0x6D0B6E);
		MemAccess<bool>::Set(0x6D0B6E, true);
		auto result = ShowDuplicateReferenceWarning(message, referenceCount);
		MemAccess<bool>::Set(0x6D0B6E, cachedValue);
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

	auto data = MemAccess<TES3::TranslationData*>::Get(0x6CE968);

	auto rotationSpeed = MemAccess<float>::Get(0x6CE9B0);
	auto rotationFlags = MemAccess<BYTE>::Get(0x6CE9A4);

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
		const auto snapAngleInRadians = MemAccess<int>::Get(0x6CE9AC) * float(M_DEGREES_TO_RADIANS);
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
				if (reference->baseObject == MemAccess<TES3::BaseObject*>::Get(0x6D566C)) {
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

void installPatches() {
	// Get the vanilla masters so we suppress errors from them.
	genCallEnforced(0x50194E, 0x4041C4, reinterpret_cast<DWORD>(Patch_FindVanillaMasters));

	// Patch: Suppress "[Following/Previous] string is different for topic" warning popups for vanilla masters.
	genJumpEnforced(0x4023BA, 0x4F30C0, reinterpret_cast<DWORD>(Patch_SuppressDialogueInfoResolveIssues));

	// Patch: Suppress "1 duplicate references were removed" warning popups for vanilla masters.
	genCallEnforced(0x50A9ED, 0x40123A, reinterpret_cast<DWORD>(PatchSuppressDuplicateReferenceRemovedWarningForVanillaMasters));

	// Patch: Use world rotation values.
	genJumpEnforced(0x403D41, 0x4652D0, reinterpret_cast<DWORD>(Patch_ReplaceRotationLogic));

	// Patch: Throttle UI status updates.
	genCallEnforced(0x4BCBBC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4BD489, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4BD503, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C0C84, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C0F39, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C0FB3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C1DFF, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C3C1D, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C9AE9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C9B63, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C41C3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C72D7, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C77B9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C2319, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C2393, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C4149, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C7833, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4C9607, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CB4B1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CB809, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CB883, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CCD54, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CD0F3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CD079, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CE0F7, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CE4F3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CE479, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CF733, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CFB49, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4CFBC3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D0DB7, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D3C09, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D3C83, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D7ED9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D27A3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D83CD, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D1119, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D1193, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D2313, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D2729, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D3893, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4D8353, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4DAA82, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4DAE03, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4DAE7F, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4DCF81, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4DD6D3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4DD659, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4DFF8B, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E2BB1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E2F89, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E03F3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E5B7F, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E9ABA, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E61A8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E84F8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E0379, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E3003, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4E6223, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4F0FC2, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4F0FFB, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4F3E52, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4F3FDB, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4F4124, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4FA2D8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4FA83E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4FA490, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x44B8E2, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x44B940, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x44BBD6, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x44BC0C, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x44BFBE, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x44BFCA, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45C8BE, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45C8D0, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45C9ED, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45C962, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45CA7E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45CA48, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45CA54, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45CA60, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45CACE, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45CADA, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x45CAE6, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46B56A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46B59F, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46BF8F, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46C3CC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46C5C6, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46C9A1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46C768, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46CBA1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46CCB1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x46E6CD, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x49FE06, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x49FE44, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x50A597, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x50F5E1, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x52F8B8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x53A727, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x53AA8E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x53AB07, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x53AFF0, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x53B3B9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x53B432, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x54D9D9, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x54D39A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x54DA53, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x501A6B, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x501AA6, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x501AEC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x501B7C, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x501BDB, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x501F7E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x502E50, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x503DEC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x504DE8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x505C32, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x505E58, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x551DF5, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4096D8, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4098AC, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x4098D4, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x5043D0, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x5300D3, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x5527BF, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x5535DE, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x40969E, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x40978D, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x50187A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x50255C, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x55284A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x55354A, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x409805, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x409848, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x412391, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x412848, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x412889, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x467150, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x501944, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x502705, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x502953, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x503363, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x503425, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x503761, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x504221, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x524537, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x524919, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x524993, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x530059, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
	genCallEnforced(0x552821, 0x404881, reinterpret_cast<DWORD>(PatchThrottleMessageUpdate));
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
		logstream.open("csse.log");
		installPatches();
		logstream << "CSSE initialization complete. Installed " << patchCount << " patches." << std::endl;
		break;
    }
    return TRUE;
}

