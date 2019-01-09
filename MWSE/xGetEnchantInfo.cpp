/************************************************************************
	
	xGetEnchantInfo.cpp - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

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

#include "TES3DataHandler.h"
#include "TES3Enchantment.h"

using namespace mwse;

namespace mwse
{
	class xGetEnchantInfo : mwse::InstructionInterface_t
	{
	public:
		xGetEnchantInfo();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetEnchantInfo xGetEnchantInfoInstance;

	xGetEnchantInfo::xGetEnchantInfo() : mwse::InstructionInterface_t(OpCode::xGetEnchantInfo) {}

	void xGetEnchantInfo::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetEnchantInfo::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString& enchantId = virtualMachine.getString(Stack::getInstance().popLong());

		// Return values.
		long type = 0;
		long cost = 0;
		long maxCharge = 0;
		long effects = 0;
		long autocalc = 0;

		// Validate effect index.
		TES3::Enchantment* enchantment = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Enchantment>(enchantId, TES3::ObjectType::Enchantment);
		if (enchantment != NULL) {
			type = int(enchantment->castType);
			cost = enchantment->chargeCost;
			maxCharge = enchantment->maxCharge;
			effects = enchantment->getActiveEffectCount();
			autocalc = enchantment->vTable.object->getAutoCalc(enchantment);
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetEnchantInfo: Could not find spell of id '" << enchantId << "'" << std::endl;
#endif
		}
		mwse::Stack::getInstance().pushLong(autocalc);
		mwse::Stack::getInstance().pushLong(effects);
		mwse::Stack::getInstance().pushLong(maxCharge);
		mwse::Stack::getInstance().pushLong(cost);
		mwse::Stack::getInstance().pushLong(type);

		return 0.0f;
	}
}