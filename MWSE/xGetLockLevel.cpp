/************************************************************************
	
#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetLockLevel : mwse::InstructionInterface_t
	{
	public:
		xGetLockLevel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetLockLevel xGetLockLevelInstance;

	xGetLockLevel::xGetLockLevel() : mwse::InstructionInterface_t(OpCode::xGetLockLevel) {}

	void xGetLockLevel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetLockLevel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		short lockLevel = -1;

		// Get reference to what we're finding the lock level of.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetLockLevel: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		TES3::ObjectType::ObjectType type = reference->baseObject->objectType;
		if (type == TES3::ObjectType::Container || type == TES3::ObjectType::Door) {
			auto lockNode = reference->getAttachedLockNode();
			if (lockNode) {
				lockLevel = lockNode->lockLevel;
			}
			else {
#if _DEBUG
				log::getLog() << "xGetLockLevel: Could not obtain lock node." << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			log::getLog() << "xGetLockLevel: Called on a non-container, non-door reference." << std::endl;
#endif
		}

		Stack::getInstance().pushShort(lockLevel);

		return 0.0f;
	}
}