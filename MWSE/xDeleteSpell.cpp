#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "MemoryUtil.h"

#include "TES3DataHandler.h"
#include "TES3Spell.h"

using namespace mwse;

namespace mwse
{
	class xDeleteSpell : mwse::InstructionInterface_t
	{
	public:
		xDeleteSpell();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xDeleteSpell xDeleteSpellInstance;

	xDeleteSpell::xDeleteSpell() : mwse::InstructionInterface_t(OpCode::xDeleteSpell) {}

	void xDeleteSpell::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xDeleteSpell::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& id = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		// Get spell.
		TES3::Spell* spell = TES3::DataHandler::get()->nonDynamicData->getSpellById(id.c_str());
		if (spell == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xDeleteSpell: No spell found with id '" << id << "'." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Manipulate the record list to remove this object.
		auto spellsList = TES3::DataHandler::get()->nonDynamicData->spellsList;
		spellsList->erase_value(spell);

		// Delete the spell from memory.
		tes3::free(spell->name);
		tes3::free(spell->objectID);
		tes3::free(spell);

		/*
			TODO: Calling AddSpell on a deleted spell does not cause an error. There
			must be some other data structure that should be updated when deleting a
			spell.
		*/

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}