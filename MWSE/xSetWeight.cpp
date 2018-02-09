/************************************************************************
	
	xSetWeight.cpp - Copyright (c) 2008 The MWSE Project
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

namespace mwse {
	class xSetWeight : mwse::InstructionInterface_t {
	public:
		xSetWeight();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetWeight xSetWeightInstance;

	xSetWeight::xSetWeight() : mwse::InstructionInterface_t(OpCode::xSetWeight) {}

	void xSetWeight::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetWeight::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameters.
		mwFloat weight = mwse::Stack::getInstance().popFloat();

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetWeight: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get record.
		TES3::BaseObject* record = reference->objectPointer;
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetWeight: No base record found." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get the weight from the base record. We group records here by the same offset.
		bool setWeight = true;
		TES3::ObjectType::ObjectType recordType = record->objectType;
		switch (recordType) {
		case TES3::ObjectType::MISC:
		case TES3::ObjectType::BOOK:
		case TES3::ObjectType::Alchemy:
		case TES3::ObjectType::AMMO:
		case TES3::ObjectType::WEAPON:
			reinterpret_cast<BOOKRecord_t*>(record)->weight = weight;
			break;
		case TES3::ObjectType::LIGHT:
			reinterpret_cast<LIGHRecord_t*>(record)->weight = weight;
			break;
		case TES3::ObjectType::INGREDIENT:
		case TES3::ObjectType::LOCK:
		case TES3::ObjectType::PROBE:
		case TES3::ObjectType::REPAIR:
			reinterpret_cast<LOCKRecord_t*>(record)->weight = weight;
			break;
		case TES3::ObjectType::ARMOR:
			reinterpret_cast<TES3::Armor*>(record)->weight = weight;
			break;
		case TES3::ObjectType::CLOTHING:
			// Clothing has the same offset as armor, but it's a short rather than a long.
			reinterpret_cast<TES3::Clothing*>(record)->weight = weight;
			break;
		case TES3::ObjectType::APPARATUS:
			reinterpret_cast<APPARecord_t*>(record)->weight = weight;
			break;
		case TES3::ObjectType::CONTAINER:
			reinterpret_cast<CONTRecord_t*>(record)->weight = weight;
			break;
		default:
			setWeight = false;
#if _DEBUG
			mwse::log::getLog() << "xSetWeight: Call on invalid record type." << std::endl;
#endif
			break;
		}

		mwse::Stack::getInstance().pushLong(setWeight);

		return 0.0f;
	}
}