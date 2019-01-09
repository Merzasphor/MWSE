/************************************************************************
	
	xModAttribute.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3MobileNPC.h"
#include "TES3Reference.h"

using namespace mwse;

namespace mwse
{
	class xModAttribute : mwse::InstructionInterface_t
	{
	public:
		xModAttribute();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xModAttribute xModAttributeInstance;

	xModAttribute::xModAttribute() : mwse::InstructionInterface_t(OpCode::xModAttribute) {}

	void xModAttribute::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xModAttribute::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if (mwse::Stack::getInstance().size() < 2) {
#if _DEBUG
			mwse::log::getLog() << "xModAttribute: Function called with too few arguments." << std::endl;
#endif
			return 0.0f;
		}

		long attributeId = mwse::Stack::getInstance().popLong();
		float modValue = mwse::Stack::getInstance().popFloat();

		// Verify attribute range.
		if (attributeId < TES3::Attribute::FirstAttribute || attributeId > TES3::Attribute::LastAttribute) {
#if _DEBUG
			mwse::log::getLog() << "xModAttribute: Invalid attribute id: " << attributeId << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get script reference.
		TES3::Reference* reference = virtualMachine.getReference();
		if (reference == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xModAttribute: Called on invalid reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Make sure we're looking at an NPC or creature.
		TES3::ObjectType::ObjectType type = reference->baseObject->objectType;
		if (type != TES3::ObjectType::NPC && type != TES3::ObjectType::Creature) {
#if _DEBUG
			mwse::log::getLog() << "xModAttribute: Called on non-NPC, non-creature reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Get the associated MACP record.
		auto mobileObject = reference->getAttachedMobileActor();
		if (mobileObject == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xModAttribute: Could not find MACP record for reference." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(0);
			return 0.0f;
		}

		// Modify current.
		float newValue = mobileObject->attributes[attributeId].current + modValue;
		if (newValue < 0) {
			newValue = 0;
		}
		mobileObject->attributes[attributeId].current = newValue;

		// Modify base.
		newValue = mobileObject->attributes[attributeId].base + modValue;
		if (newValue < 0) {
			newValue = 0;
		}
		mobileObject->attributes[attributeId].base = newValue;

		// Push to indicate success.
		mwse::Stack::getInstance().pushLong(1);

		return 0.0f;
	}
}