/************************************************************************

	xGetIngredientEffect.cpp - Copyright (c) 2008 The MWSE Project
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
#include "TES3Ingredient.h"

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
		mwseString& id = virtualMachine.getString(Stack::getInstance().popLong());
		long index = Stack::getInstance().popLong() - 1;

		// Return values.
		long effectEnumId = TES3::EffectID::None;
		long skillAttributeId = -1;

		// Get the ingredient.
		TES3::Ingredient* ingredient = TES3::DataHandler::get()->nonDynamicData->resolveObjectByType<TES3::Ingredient>(id, TES3::ObjectType::Ingredient);
		if (ingredient == NULL) {
#if _DEBUG
			mwse::log::getLog() << "xGetIngredientEffect: No ingredient record found with id '" << id << "'." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(skillAttributeId);
			mwse::Stack::getInstance().pushLong(effectEnumId);
			return 0.0f;
		}
		
		// Validate index.
		if (index < 0 || index > 3) {
#if _DEBUG
			mwse::log::getLog() << "xGetIngredientEffect: Invalid index. Value must be between 1 and 4." << std::endl;
#endif
			mwse::Stack::getInstance().pushLong(skillAttributeId);
			mwse::Stack::getInstance().pushLong(effectEnumId);
			return 0.0f;
		}

		// Get the ingredient effect information.
		effectEnumId = ingredient->effects[index];
		if (effectEnumId == TES3::EffectID::DrainAttribute || effectEnumId == TES3::EffectID::DamageAttribute
			|| effectEnumId == TES3::EffectID::RestoreAttribute || effectEnumId == TES3::EffectID::FortifyAttribute
			|| effectEnumId == TES3::EffectID::AbsorbAttribute) {
			skillAttributeId = ingredient->effectAttributeIds[index];
		}
		else if (effectEnumId == TES3::EffectID::DrainSkill || effectEnumId == TES3::EffectID::DamageSkill
			|| effectEnumId == TES3::EffectID::RestoreSkill || effectEnumId == TES3::EffectID::FortifySkill
			|| effectEnumId == TES3::EffectID::AbsorbSkill) {
			skillAttributeId = ingredient->effectSkillIds[index];
		}

		mwse::Stack::getInstance().pushLong(skillAttributeId);
		mwse::Stack::getInstance().pushLong(effectEnumId);

		return 0.0f;
	}
}