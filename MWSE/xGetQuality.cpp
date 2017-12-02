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
#include "Reference.h"

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
		const mwFloat_t INVALID_VALUE = -1.0f;
	};

	static const mwse::mwOpcode_t xGetQualityOpcode = 0x3F69;
	static xGetQuality xGetQualityInstance;

	xGetQuality::xGetQuality() : mwse::InstructionInterface_t(xGetQualityOpcode) {}

	void xGetQuality::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetQuality::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xGetQuality: No reference provided." << std::endl;
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		// Get record.
		BaseRecord_t* record = reference->recordPointer;
		if (record == NULL) {
			mwse::log::getLog() << "xGetQuality: No base record found." << std::endl;
			mwse::Stack::getInstance().pushFloat(INVALID_VALUE);
			return 0.0f;
		}

		mwFloat_t value = 0;

		// Get the quality.
		RecordTypes::recordType_t recordType = record->recordType;
		if (recordType == RecordTypes::LOCKPICK) {
			LOCKRecord_t* lockpick = reinterpret_cast<LOCKRecord_t*>(reference->recordPointer);
			value = lockpick->quality;
		}
		else if (recordType == RecordTypes::PROBE) {
			PROBRecord_t* probe = reinterpret_cast<PROBRecord_t*>(reference->recordPointer);
			value = probe->quality;
		}
		else if (recordType == RecordTypes::REPAIR) {
			REPARecord_t* repair = reinterpret_cast<REPARecord_t*>(reference->recordPointer);
			value = repair->quality;
		}
		else if (recordType == RecordTypes::APPARATUS) {
			APPARecord_t* apparatus = reinterpret_cast<APPARecord_t*>(reference->recordPointer);
			value = apparatus->quality;
		}
		else {
			mwse::log::getLog() << "xGetQuality: Call on unsupported record type: " << recordType << std::endl;
		}

		mwse::Stack::getInstance().pushFloat(value);

		return 0.0f;
	}
}