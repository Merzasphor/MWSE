/************************************************************************

xSetIngredientEffect.cpp - Copyright (c) 2008 The MWSE Project
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

using namespace mwse;

namespace mwse
{
	class xSetIngredientEffect : mwse::InstructionInterface_t
	{
	public:
		xSetIngredientEffect();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xSetIngredientEffect xSetIngredientEffectInstance;

	xSetIngredientEffect::xSetIngredientEffect() : mwse::InstructionInterface_t(OpCode::xSetIngredientEffect) {}

	void xSetIngredientEffect::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xSetIngredientEffect::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString_t& id = virtualMachine.getString(Stack::getInstance().popLong());
		mwLong index = Stack::getInstance().popLong() - 1;
		mwLong effectEnumId = Stack::getInstance().popLong();
		mwLong skillAttributeId = Stack::getInstance().popLong();

		// Get the ingredient.
		INGRRecord_t* ingredient = reinterpret_cast<INGRRecord_t*>(tes3::getTemplate(id));
		if (ingredient == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xSetIngredientEffect: No ingredient record found with id '" << id << "'." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate index.
		if (index < 0 || index > 3) {
#if _DEBUG
			mwse::log::getLog() << "xSetIngredientEffect: Invalid index. Value must be between 1 and 4." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Validate effect id.
		if (effectEnumId < Effects::FirstMagicEffect || effectEnumId > Effects::LastMagicEffect) {
#if _DEBUG
			mwse::log::getLog() << "xSetIngredientEffect: Invalid effect id." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(false);
			return 0.0f;
		}

		// Set the ingredient effect information.
		ingredient->effects[index] = effectEnumId;
		if (effectEnumId == Effects::DrainAttribute || effectEnumId == Effects::DamageAttribute
			|| effectEnumId == Effects::RestoreAttribute || effectEnumId == Effects::FortifyAttribute
			|| effectEnumId == Effects::AbsorbAttribute) {
			ingredient->effectAttributeIds[index] = skillAttributeId;
			ingredient->effectSkillIds[index] = -1;
		}
		else if (effectEnumId == Effects::DrainSkill || effectEnumId == Effects::DamageSkill
			|| effectEnumId == Effects::RestoreSkill || effectEnumId == Effects::FortifySkill
			|| effectEnumId == Effects::AbsorbSkill) {
			ingredient->effectAttributeIds[index] = -1;
			ingredient->effectSkillIds[index] = skillAttributeId;
		}
		else {
			ingredient->effectAttributeIds[index] = -1;
			ingredient->effectSkillIds[index] = -1;
		}

		mwse::Stack::getInstance().pushLong(true);

		return 0.0f;
	}
}