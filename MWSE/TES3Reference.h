#pragma once

#include "sol.hpp"

#include "TES3Defines.h"
#include "TES3Attachment.h"
#include "TES3Vectors.h"

namespace TES3 {
	struct Reference : Object {
		PhysicalObject * baseObject; // 0x28
		Vector3 orientation; // 0x2c
		Vector3 position; // 0x38
		Attachment * attachments; // 0x44
		unsigned int sourceID; // 0x48
		unsigned int targetID; // 0x4C

		//
		// Basic operators.
		//

		Reference();
		~Reference();

		//
		// Other related this-call functions.
		//

		__declspec(dllexport) void activate(Reference* activator, int unknown = 1);
		__declspec(dllexport) void setActionFlag(int);
		__declspec(dllexport) void clearActionFlag(int);
		__declspec(dllexport) bool testActionFlag(int);
		__declspec(dllexport) void setActionReference(Reference*);
		__declspec(dllexport) Reference * getActionReference();

		__declspec(dllexport) ItemDataAttachment* addItemDataAttachment(ItemData*);
		__declspec(dllexport) Vector3* getOrCreateOrientationFromAttachment();
		__declspec(dllexport) Vector3* getPositionFromAttachment();
		__declspec(dllexport) LockAttachmentNode* getOrCreateLockNode();
		__declspec(dllexport) ScriptVariables * getScriptVariables();
		__declspec(dllexport) void removeAttachment(TES3::Attachment * attachment);
		__declspec(dllexport) void ensureScriptDataIsInstanced();

		__declspec(dllexport) void detachDynamicLightFromAffectedNodes();
		__declspec(dllexport) void deleteDynamicLightAttachment();

		__declspec(dllexport) bool updateBipedParts();

		//
		// Other utility functions.
		//

		__declspec(dllexport) bool enable();
		__declspec(dllexport) bool disable();
		__declspec(dllexport) bool getDisabled();

		__declspec(dllexport) Vector3 * getPosition();
		__declspec(dllexport) void setPosition(const Vector3 * newPosition);

		__declspec(dllexport) Vector3 * getOrientation();
		__declspec(dllexport) void setOrientation(const Vector3 * newOrientation);

		__declspec(dllexport) TravelDestination * setTravelDestination(const Vector3 * position, const Vector3 * orientation, Cell * cell = nullptr);

		__declspec(dllexport) Matrix33* updateSceneMatrix(Matrix33* matrix, bool eulerXYZ = false);

		__declspec(dllexport) Inventory * getInventory();
		__declspec(dllexport) Iterator<EquipmentStack> * getEquipment();

		__declspec(dllexport) void relocate(Cell * cell, const Vector3 * position);
		__declspec(dllexport) bool clone();

		__declspec(dllexport) bool insertAttachment(Attachment* attachment);
		__declspec(dllexport) Attachment* getAttachment(AttachmentType::AttachmentType type);
		__declspec(dllexport) MobileObject* getAttachedMobileObject();
		__declspec(dllexport) MobileActor* getAttachedMobileActor();
		__declspec(dllexport) MobileCreature* getAttachedMobileCreature();
		__declspec(dllexport) MobileNPC* getAttachedMobileNPC();
		__declspec(dllexport) MobileProjectile* getAttachedMobileProjectile();
		__declspec(dllexport) ItemData* getAttachedItemData();
		__declspec(dllexport) void setAttachedItemData(ItemData * itemData);
		__declspec(dllexport) ItemData* getOrCreateAttachedItemData();
		__declspec(dllexport) LockAttachmentNode* getAttachedLockNode();
		__declspec(dllexport) AnimationData* getAttachedAnimationData();

		__declspec(dllexport) LightAttachmentNode* getAttachedDynamicLight();
		__declspec(dllexport) LightAttachmentNode* getOrCreateAttachedDynamicLight(NI::PointLight *, float);

		__declspec(dllexport) bool getEmptyInventoryFlag();
		__declspec(dllexport) void setEmptyInventoryFlag(bool);

		void attemptUnlockDisarm(MobileNPC * disarmer, Item * tool, ItemData * itemData = nullptr);

		// Override for references to raise an event when their scene node is created.
		__declspec(dllexport) NI::Node * getSceneGraphNode();

		//
		// Lua interface functions.
		//

		void setPositionFromLua(sol::stack_object value);
		void setOrientationFromLua(sol::stack_object value);

		// Return a table (or nil) of attachments for this object.
		sol::object getAttachments();

		sol::table getLuaTable();

	};
	static_assert(sizeof(Reference) == 0x50, "TES3::Reference failed size validation");
}
