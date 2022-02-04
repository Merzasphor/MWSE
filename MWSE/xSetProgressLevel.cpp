#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include "TES3MobilePlayer.h"
#include "TES3WorldController.h"

using namespace mwse;

namespace mwse
{
	class xSetProgressLevel : mwse::InstructionInterface_t
	{
	public:
		xSetProgressLevel();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetProgressLevel xSetProgressLevelInstance;

	xSetProgressLevel::xSetProgressLevel() : mwse::InstructionInterface_t(OpCode::xSetProgressLevel) {}

	void xSetProgressLevel::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetProgressLevel::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameter.
		long progress = mwse::Stack::getInstance().popLong();

		// Get the associated MACP record.
		auto mobileObject = TES3::WorldController::get()->getMobilePlayer();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetProgressLevel: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set progress.
		mobileObject->levelUpProgress = progress;

		// Check for level up.
		tes3::checkForLevelUp(progress);

		// Push success.
		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}