#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "FileUtil.h"

using namespace mwse;

namespace mwse
{
	class xFileSeek : mwse::InstructionInterface_t
	{
	public:
		xFileSeek();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xFileSeek xFileSeekInstance;

	xFileSeek::xFileSeek() : mwse::InstructionInterface_t(OpCode::xFileSeek) {}

	void xFileSeek::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xFileSeek::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 2) {
			mwse::log::getLog() << "xFileSeek: Function called with too few arguments." << std::endl;
			return 0.0f;
		}

		mwseString& fileName = virtualMachine.getString(mwse::Stack::getInstance().popLong());
		long position = mwse::Stack::getInstance().popLong();

		mwse::FileSystem::getInstance().seek(fileName.c_str(), position);

		return 0.0f;
	}
}