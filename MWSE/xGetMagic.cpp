#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3MobileNPC.h"
#include "TES3Enchantment.h"
#include "TES3Reference.h"
#include "TES3Spell.h"

using namespace mwse;

namespace mwse
{
	class xGetMagic : mwse::InstructionInterface_t
	{
	public:
		xGetMagic();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetMagic xGetMagicInstance;

	xGetMagic::xGetMagic() : mwse::InstructionInterface_t(OpCode::xGetMagic) {}

	void xGetMagic::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetMagic::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Return values.
		long type = 0;
		const char* id = NULL;

		// Get reference to what we're finding enchantment information for.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference) {
			TES3::ObjectType::ObjectType recordType = reference->baseObject->objectType;
			if (recordType == TES3::ObjectType::Creature || recordType == TES3::ObjectType::NPC) {
				auto mobileObject = reference->getAttachedMobileActor();
				if (mobileObject && mobileObject->currentSpell.source.asGeneric) {
					TES3::Object * spellSource = mobileObject->currentSpell.source.asGeneric;
					id = spellSource->getObjectID();
					type = spellSource->objectType;
				}
				else {
#if _DEBUG
					log::getLog() << "xGetMagic: Could not obtain MACP record for reference." << std::endl;
#endif
				}
			}
			else {
#if _DEBUG
				log::getLog() << "xGetMagic: Invalid reference type:" << recordType << std::endl;
#endif
			}
		}
		else {
#if _DEBUG
			log::getLog() << "xGetMagic: Could not obtain reference." << std::endl;
#endif
		}

		// Return type/id.
		Stack::getInstance().pushString(id);
		Stack::getInstance().pushLong(type);

		return 0.0f;
	}
}