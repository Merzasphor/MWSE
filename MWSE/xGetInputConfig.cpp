/************************************************************************
	
	xGetInputConfig.cpp - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "TES3Util.h"
#include <Windows.h>

using namespace mwse;

namespace mwse {
	class xGetInputConfig : mwse::InstructionInterface_t {
	public:
		xGetInputConfig();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	enum xGetInputConfigReturnType {
		ReturnVirtualKeyCode,
		ReturnScanCode
	};

	static xGetInputConfig xGetInputConfigInstance;

	xGetInputConfig::xGetInputConfig() : mwse::InstructionInterface_t(OpCode::xGetInputConfig) {}

	void xGetInputConfig::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetInputConfig::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		mwLong_t inputIndex = Stack::getInstance().popLong();
		mwLong_t returnType = Stack::getInstance().popLong();

		// Validate index.
		if (inputIndex < KeyFirst || inputIndex > KeyLast) {
#if _DEBUG
			mwse::log::getLog() << "xGetInputConfig: Index out of bounds." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get our structure.
		InputConfig_t::Input_t& config = tes3::getMaster()->inputConfig->inputMaps[inputIndex];

		// If we're not converting to Windows keys, just grab the key code and the input type and push it back.
		if (returnType == ReturnScanCode) {
			mwse::Stack::getInstance().pushLong(config.device);
			mwse::Stack::getInstance().pushLong(config.keyCode);
			return 0.0f;
		}

		// If we are converting to a VK_ keycode (for use for the other input functions)...
		else if (returnType == ReturnVirtualKeyCode) {
			mwLong_t convertedKey = 0;
			bool converted = false;

			long keyCode = config.keyCode;
			long device = config.device;
			if (device == DeviceKeyboard || device == DeviceMouse) {
				convertedKey = MapVirtualKey(keyCode, MAPVK_VSC_TO_VK);
				converted = (convertedKey != 0);
			}
			else {
#if _DEBUG
				mwse::log::getLog() << "xGetInputConfig: Device type " << device << " cannot be converted." << std::endl;
#endif
			}

			mwse::Stack::getInstance().pushLong(converted);
			mwse::Stack::getInstance().pushLong(convertedKey);
			return 0.0f;
		}

		// Invalid return type.
#if _DEBUG
		mwse::log::getLog() << "xGetInputConfig: Invalid return type " << returnType << "." << std::endl;
#endif
		mwse::Stack::getInstance().pushLong(0);
		mwse::Stack::getInstance().pushLong(0);

		return 0.0f;
	}
}