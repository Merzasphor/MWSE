/************************************************************************
	
	xSetQuality.cpp - Copyright (c) 2008 The MWSE Project
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
		mwFloat_t value = mwse::Stack::getInstance().popFloat();

		// Get reference.
		REFRRecord_t* reference = virtualMachine.getReference();
		if (reference == NULL) {
			mwse::log::getLog() << "xSetQuality: No reference provided." << std::endl;
			return 0.0f;
		}

		// Get record.
		BaseRecord_t* record = reference->recordPointer;
		if (record == NULL) {
			mwse::log::getLog() << "xSetQuality: No base record found." << std::endl;
			return 0.0f;
		}

		// Get the quality.
		RecordTypes::recordType_t recordType = record->recordType;
		if (recordType == RecordTypes::LOCKPICK) {
			reinterpret_cast<LOCKRecord_t*>(reference->recordPointer)->quality = value;
		}
		else if (recordType == RecordTypes::PROBE) {
			reinterpret_cast<PROBRecord_t*>(reference->recordPointer)->quality = value;
		}
		else if (recordType == RecordTypes::REPAIR) {
			reinterpret_cast<REPARecord_t*>(reference->recordPointer)->quality = value;
		}
		else if (recordType == RecordTypes::APPARATUS) {
			reinterpret_cast<APPARecord_t*>(reference->recordPointer)->quality = value;
		}
		else {
			mwse::log::getLog() << "xSetQuality: Call on unsupported record type: " << recordType << std::endl;
		}

		return 0.0f;
	}
}