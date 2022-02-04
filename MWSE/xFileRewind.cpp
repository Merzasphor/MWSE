#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "FileUtil.h"

using namespace mwse;

namespace mwse
{
	class xFileRewind : mwse::InstructionInterface_t
	{
	public:
		xFileRewind();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xFileRewind xFileRewindInstance;

	xFileRewind::xFileRewind() : mwse::InstructionInterface_t(OpCode::xFileRewind) {}

	void xFileRewind::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xFileRewind::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 1) {
			mwse::log::getLog() << "xFileRewind: Function called with too few arguments." << std::endl;
			return 0.0f;
		}

		mwseString& fileName = virtualMachine.getString(mwse::Stack::getInstance().popLong());

		mwse::FileSystem::getInstance().seek(fileName.c_str(), 0);

		return 0.0f;
	}
}