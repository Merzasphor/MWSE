#include "TES3Reference.h"

#include "LuaManager.h"
#include "LuaUtil.h"
#include "TES3Util.h"

#include "NINode.h"

#include "TES3Actor.h"

#define TES3_Reference_activate 0x4E9610
#define TES3_Reference_setActionFlag 0x4E55A0
#define TES3_Reference_clearActionFlag 0x4E55E0
#define TES3_Reference_testActionFlag 0x4E5520
#define TES3_Reference_setActionReference 0x4E5610
#define TES3_Reference_getActionReference 0x4E5650

#define TES3_Reference_addItemDataAttachment 0x4E5360

namespace TES3 {
	void Reference::activate(Reference* activator, int unknown) {
		// If our event data says to block, don't let the object activate.
		sol::object response = mwse::lua::LuaManager::getInstance().triggerEvent(new mwse::lua::event::ActivateEvent(activator, this));
		if (response != sol::nil && response.is<sol::table>()) {
			sol::table eventData = response;
			if (eventData["block"] == true) {
				return;
			}
		}

		reinterpret_cast<void(__thiscall *)(Reference*, Reference*, int)>(TES3_Reference_activate)(this, activator, unknown);
	}

	void Reference::setActionFlag(int flag) {
		reinterpret_cast<void(__thiscall *)(Reference*, int)>(TES3_Reference_setActionFlag)(this, flag);
	}

	void Reference::clearActionFlag(int flag) {
		reinterpret_cast<void(__thiscall *)(Reference*, int)>(TES3_Reference_clearActionFlag)(this, flag);
	}

	bool Reference::testActionFlag(int flag) {
		return (reinterpret_cast<signed char(__thiscall *)(Reference*, int)>(TES3_Reference_testActionFlag)(this, flag) != 0);
	}

	void Reference::setActionReference(Reference* reference) {
		reinterpret_cast<void (__thiscall *)(Reference*, Reference*)>(TES3_Reference_setActionReference)(this, reference);
	}

	Reference* Reference::getActionReference() {
		return reinterpret_cast<Reference* (__thiscall *)(Reference*)>(TES3_Reference_getActionReference)(this);
	}

	TES3::ItemDataAttachment* Reference::addItemDataAttachment(TES3::ItemData* data) {
		return reinterpret_cast<ItemDataAttachment* (__thiscall *)(Reference*, TES3::ItemData*)>(TES3_Reference_addItemDataAttachment)(this, data);
	}

	void Reference::setPositionFromLua(sol::stack_object value) {
		// Is it a vector?
		if (value.is<TES3::Vector3*>()) {
			setPosition(value.as<TES3::Vector3*>());
		}
		// Allow a simple table to be provided.
		else if (value.is<sol::table>()) {
			// Get the values from the table.
			sol::table positionTable = value.as<sol::table>();
			if (positionTable.size() == 3) {
				setPosition(positionTable[1], positionTable[2], positionTable[3]);
			}
		}
	}

	void Reference::setPosition(float x, float y, float z) {
		sceneNode->localTranslate.x = x;
		sceneNode->localTranslate.y = y;
		sceneNode->localTranslate.z = z;
		sceneNode->propagatePositionChange();
		position.x = x;
		position.y = y;
		position.z = z;
	}

	void Reference::setPosition(TES3::Vector3* positionVec) {
		setPosition(positionVec->x, positionVec->y, positionVec->z);
	}

	TES3::Inventory * Reference::getInventory() {
		// Only actors have equipment.
		if (baseObject->objectType != TES3::ObjectType::Container &&
			baseObject->objectType != TES3::ObjectType::Creature &&
			baseObject->objectType != TES3::ObjectType::NPC) {
			return NULL;
		}

		return &reinterpret_cast<TES3::Actor*>(baseObject)->inventory;
	}

	TES3::Iterator<EquipmentStack> * Reference::getEquipment() {
		// Only actors have equipment.
		if (baseObject->objectType != TES3::ObjectType::Container &&
			baseObject->objectType != TES3::ObjectType::Creature &&
			baseObject->objectType != TES3::ObjectType::NPC) {
			return NULL;
		}

		return &reinterpret_cast<TES3::Actor*>(baseObject)->equipment;
	}
}
