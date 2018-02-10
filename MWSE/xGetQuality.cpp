/************************************************************************
	
	xGetQuality.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3Lockpick.h"
#include "TES3Probe.h"
#include "TES3Repair.h"
#include "TES3Apparatus.h"

using namespace mwse;

namespace mwse
{
	class xGetQuality : mwse::InstructionInterface_t
	{
	public:
		xGetQuality();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	private:
		const mwFloat INVALID_VALUE = -1.0f;
	};

	static xGetQuality xGetQualityInstance;

	xGetQuality::xGetQuality() : mwse::InstructionInterface_t(OpCode::xGetQuality) {}

	void xGetQuality::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetQuality::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetQuality: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get record.
		TES3::BaseObject* record = reference->objectPointer;
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetQuality: No base record found." << std::endl;
#endif
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		mwFloat value = 0;

		// Get the quality.
		TES3::ObjectType::ObjectType recordType = record->objectType;
		if (recordType == TES3::ObjectType::Lockpick) {
			TES3::Lockpick* lockpick = reinterpret_cast<TES3::Lockpick*>(reference->objectPointer);
			value = lockpick->quality;
		}
		else if (recordType == TES3::ObjectType::Probe) {
			TES3::Probe* probe = reinterpret_cast<TES3::Probe*>(reference->objectPointer);
			value = probe->quality;
		}
		else if (recordType == TES3::ObjectType::Repair) {
			TES3::Repair* repair = reinterpret_cast<TES3::Repair*>(reference->objectPointer);
			value = repair->quality;
		}
		else if (recordType == TES3::ObjectType::Apparatus) {
			TES3::Apparatus* apparatus = reinterpret_cast<TES3::Apparatus*>(reference->objectPointer);
			value = apparatus->quality;
		}
		else {
#if _DEBUG
			mwse::log::getLog() << "xGetQuality: Call on unsupported record type: " << recordType << std::endl;
#endif
		}

		mwse::Stack::getInstance().pushFloat(value);

		return 0.0f;
	}
}