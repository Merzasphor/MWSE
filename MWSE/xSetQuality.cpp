/************************************************************************
	
	xSetQuality.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3Reference.h"
#include "TES3Lockpick.h"
#include "TES3Probe.h"
#include "TES3RepairTool.h"
#include "TES3Apparatus.h"

using namespace mwse;

namespace mwse
{
	class xSetQuality : mwse::InstructionInterface_t
	{
	public:
		xSetQuality();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetQuality xSetQualityInstance;

	xSetQuality::xSetQuality() : mwse::InstructionInterface_t(OpCode::xSetQuality) {}

	void xSetQuality::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetQuality::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		float value = mwse::Stack::getInstance().popFloat();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetQuality: No reference provided." << std::endl;
#endif
			return 0.0f;
		}

		// Get record.
		TES3::BaseObject* record = reference->baseObject;
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetQuality: No base record found." << std::endl;
#endif
			return 0.0f;
		}

		// Get the quality.
		bool valueSet = false;
		TES3::ObjectType::ObjectType recordType = record->objectType;
		if (recordType == TES3::ObjectType::Lockpick) {
			reinterpret_cast<TES3::Lockpick*>(reference->baseObject)->quality = value;
			valueSet = true;
		}
		else if (recordType == TES3::ObjectType::Probe) {
			reinterpret_cast<TES3::Probe*>(reference->baseObject)->quality = value;
			valueSet = true;
		}
		else if (recordType == TES3::ObjectType::Repair) {
			reinterpret_cast<TES3::RepairTool*>(reference->baseObject)->quality = value;
			valueSet = true;
		}
		else if (recordType == TES3::ObjectType::Apparatus) {
			reinterpret_cast<TES3::Apparatus*>(reference->baseObject)->quality = value;
			valueSet = true;
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xSetQuality: Call on unsupported record type: " << recordType << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushLong(valueSet);

		return 0.0f;
	}
}