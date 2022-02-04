#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "FileUtil.h"

using namespace mwse;

namespace mwse
{
	class xFileWriteLong : mwse::InstructionInterface_t
	{
	public:
		xFileWriteLong();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xFileWriteLong xFileWriteLongInstance;

	xFileWriteLong::xFileWriteLong() : mwse::InstructionInterface_t(OpCode::xFileWriteLong) {}

	void xFileWriteLong::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xFileWriteLong::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 2) {
			mwse::log::getLog() << "xFileWriteLong: Function called with too few arguments." << std::endl;
			return 0.0f;
		}

		mwseString& fileName = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		long value = mwse::Stack::getInstance().popLong();

		mwse::FileSystem::getInstance().writeLong(fileName.c_str(), value);

		return 0.0f;
	}
}