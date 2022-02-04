#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"

#include "TES3NPC.h"
#include "TES3Creature.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xGetBaseGold : mwse::InstructionInterface_t
	{
	public:
		xGetBaseGold();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetBaseGold xGetBaseGoldInstance;

	xGetBaseGold::xGetBaseGold() : mwse::InstructionInterface_t(OpCode::xGetBaseGold) {}

	void xGetBaseGold::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetBaseGold::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetBaseGold: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushShort(0);
			return 0.0f;
		}

		short gold = 0;

		// Get the gold based on the base record type.
		TES3::BaseObject* baseRecord = reference->baseObject;
		if (baseRecord->objectType == TES3::ObjectType::NPC) {
			TES3::NPCInstance* npc = reinterpret_cast<TES3::NPCInstance*>(baseRecord);
			if (npc->baseNPC) {
				gold = npc->baseNPC->barterGold;
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetBaseGold: Could not get base NPC record for \"" << npc->objectID << "\"" << std::endl;
#endif
			}
		}
		else if (baseRecord->objectType == TES3::ObjectType::Creature) {
			TES3::CreatureInstance* creature = reinterpret_cast<TES3::CreatureInstance*>(baseRecord);
			if (creature->baseCreature) {
				gold = creature->baseCreature->barterGold;
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetBaseGold: Could not get base creature record for \"" << creature->objectID << "\"" << std::endl;
#endif
			}
		}

		// Push the base value of that skill.
		mwse::Stack::getInstance().pushShort(gold);

		return 0.0f;
	}
}