/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3Actor.h"
#include "TES3Inventory.h"
#include "TES3Reference.h"

namespace mwse
{
	class xInventory : mwse::InstructionInterface_t
	{
	public:
		xInventory();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xInventory xInventoryInstance;

	xInventory::xInventory() : mwse::InstructionInterface_t(OpCode::xInventory) {}

	void xInventory::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xInventory::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xInventory: Invalid reference attachment." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		if (!reference->baseObject->isActor()) {
#if _DEBUG
			mwse::log::getLog() << "xInventory: Reference is not for an actor." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(0.0f);
			return 0.0f;
		}
		
		TES3::IteratedList<TES3::ItemStack*>::Node* firstItem = static_cast<TES3::Actor*>(reference->baseObject)->inventory.itemStacks.head;
		if (firstItem == NULL) {
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		mwse::Stack::getInstance().pushLong((long)firstItem->next);
		mwse::Stack::getInstance().pushLong(firstItem->data->count);
		mwse::Stack::getInstance().pushString(firstItem->data->object->vTable.object->getObjectID(firstItem->data->object));

		return 0.0f;
	}
}
