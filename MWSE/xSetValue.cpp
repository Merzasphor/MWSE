/************************************************************************
	
	xSetValue.cpp - Copyright (c) 2008 The MWSE Project
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

#include "TES3Book.h"
#include "TES3Light.h"
#include "TES3Lockpick.h"
#include "TES3Armor.h"
#include "TES3Clothing.h"
#include "TES3Apparatus.h"
#include "TES3Misc.h"

using namespace mwse;

namespace mwse {
	class xSetValue : mwse::InstructionInterface_t {
	public:
		xSetValue();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetValue xSetValueInstance;

	xSetValue::xSetValue() : mwse::InstructionInterface_t(OpCode::xSetValue) {}

	void xSetValue::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetValue::execute(mwse::VMExecuteInterface &virtualMachine) {
		// Get parameter.
		mwLong value = mwse::Stack::getInstance().popLong();
		bool setValue = false;

		// Get reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetValue: No reference provided." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Get record.
		TES3::BaseObject* record = reference->objectPointer;
		if (record == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetValue: No base record found." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set the value from the base record. We group records here by the same offset.
		TES3::ObjectType::ObjectType recordType = record->objectType;
		switch (recordType) {
		case TES3::ObjectType::Book:
		case TES3::ObjectType::Alchemy:
		case TES3::ObjectType::Ammo:
		case TES3::ObjectType::Weapon:
			reinterpret_cast<TES3::Book*>(record)->value = value;
			setValue = true;
			break;
		case TES3::ObjectType::Light:
			reinterpret_cast<TES3::Light*>(record)->value = value;
			setValue = true;
			break;
		case TES3::ObjectType::Ingredient:
		case TES3::ObjectType::Lockpick:
		case TES3::ObjectType::Probe:
		case TES3::ObjectType::Repair:
			reinterpret_cast<TES3::Lockpick*>(record)->value = value;
			setValue = true;
			break;
		case TES3::ObjectType::Armor:
			reinterpret_cast<TES3::Armor*>(record)->value = value;
			setValue = true;
			break;
		case TES3::ObjectType::Clothing:
			// Clothing has the same offset as armor, but it's a short rather than a long.
			reinterpret_cast<TES3::Clothing*>(record)->value = value;
			setValue = true;
			break;
		case TES3::ObjectType::Apparatus:
			reinterpret_cast<TES3::Apparatus*>(record)->value = value;
			setValue = true;
			break;
		case TES3::ObjectType::Misc:
		{
			reinterpret_cast<TES3::Misc*>(record)->value = value;
			setValue = true;
			break;
		}
		default:
#if _DEBUG
			mwse::log::getLog() << "xSetValue: Call on invalid record type." << std::endl;
#endif
			break;
		}

		mwse::Stack::getInstance().pushLong(setValue);

		return 0.0f;
	}
}