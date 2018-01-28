/************************************************************************

	xGetIngredientEffect.cpp - Copyright (c) 2008 The MWSE Project
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
	class xGetIngredientEffect : mwse::InstructionInterface_t
	{
	public:
		xGetIngredientEffect();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	};

	static xGetIngredientEffect xGetIngredientEffectInstance;

	xGetIngredientEffect::xGetIngredientEffect() : mwse::InstructionInterface_t(OpCode::xGetIngredientEffect) {}

	void xGetIngredientEffect::loadParameters(mwse::VMExecuteInterface &virtualMachine) {}

	float xGetIngredientEffect::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		// Get parameters.
		mwseString_t& id = virtualMachine.getString(Stack::getInstance().popLong());
		mwLong_t index = Stack::getInstance().popLong() - 1;

		// Return values.
		mwLong_t effectEnumId = Effects::NoEffect;
		mwLong_t skillAttributeId = -1;

		// Get the ingredient.
		INGRRecord_t* ingredient = reinterpret_cast<INGRRecord_t*>(tes3::getTemplate(id));
		if (ingredient == NULL) {
			mwse::log::getLog() << "xGetIngredientEffect: No ingredient record found with id '" << id << "'." << std::endl;
			mwse::Stack::getInstance().pushLong(skillAttributeId);
			mwse::Stack::getInstance().pushLong(effectEnumId);
			return 0.0f;
		}
		
		// Validate index.
		if (index < 0 || index > 3) {
			mwse::log::getLog() << "xGetIngredientEffect: Invalid index. Value must be between 1 and 4." << std::endl;
			mwse::Stack::getInstance().pushLong(skillAttributeId);
			mwse::Stack::getInstance().pushLong(effectEnumId);
			return 0.0f;
		}

		// Get the ingredient effect information.
		effectEnumId = ingredient->effects[index];
		if (effectEnumId == Effects::DrainAttribute || effectEnumId == Effects::DamageAttribute
			|| effectEnumId == Effects::RestoreAttribute || effectEnumId == Effects::FortifyAttribute
			|| effectEnumId == Effects::AbsorbAttribute) {
			skillAttributeId = ingredient->effectAttributeIds[index];
		}
		else if (effectEnumId == Effects::DrainSkill || effectEnumId == Effects::DamageSkill
			|| effectEnumId == Effects::RestoreSkill || effectEnumId == Effects::FortifySkill
			|| effectEnumId == Effects::AbsorbSkill) {
			skillAttributeId = ingredient->effectSkillIds[index];
		}

		mwse::Stack::getInstance().pushLong(skillAttributeId);
		mwse::Stack::getInstance().pushLong(effectEnumId);

		return 0.0f;
	}
}