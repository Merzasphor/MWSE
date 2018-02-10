/************************************************************************
	
	ScriptUtil.h - Copyright (c) 2008 The MWSE Project
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

#pragma once

#include "mwOffsets.h"
#include "ObjectTypes.h"
#include "mwseString.h"
#include "OpCodes.h"

namespace mwse
{
	namespace mwscript
	{

		//
		// Manipulation of script state.
		//

		int getInstructionPointer();
		void setInstructionPointer(int IP);

		//
		// Manipulation of script variables.
		//

		TES3::Reference* getScriptTargetReference();
		void setScriptTargetReference(TES3::Reference* reference);

		TES3::BaseObject* getScriptTargetTemplate();
		void setScriptTargetTemplate(TES3::BaseObject* record);

		TES3::BaseObject* getScriptSecondObject();
		void setScriptSecondObject(const char* string);
		void setScriptSecondObject(TES3::BaseObject* record);

		mwLong getScriptVariableIndex();
		void setScriptVariableIndex(mwLong index);

		mwFloat getScriptDestinationX();
		void setScriptDestinationX(mwFloat value);

		mwFloat getScriptDestinationY();
		void setScriptDestinationY(mwFloat value);

		mwFloat getScriptDestinationZ();
		void setScriptDestinationZ(mwFloat value);

		void setScriptDestination(mwFloat x, mwFloat y, mwFloat z);

		mwFloat getScriptTargetRotationX();
		void setScriptTargetRotationX(mwFloat value);

		mwFloat getScriptTargetRotationY();
		void setScriptTargetRotationY(mwFloat value);

		mwFloat getScriptTargetRotationZ();
		void setScriptTargetRotationZ(mwFloat value);

		void setScriptTargetRotation(mwFloat x, mwFloat y, mwFloat z);

		//
		// Execute original op code.
		//

		float RunOriginalOpCode(TES3::Script* script, TES3::Reference* reference, OpCode::OpCode_t opCode, TES3::BaseObject* objectParam, char charParam, float unk1, float unk2);

		//
		// Wrapper functions for original opcodes.
		//

		void AddItem(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate, mwLong count);

		void AddSpell(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* spellTemplate);

		void AITravel(TES3::Script* script, TES3::Reference* reference, mwFloat x, mwFloat y, mwFloat z);

		void Cast(TES3::Script* script, TES3::Reference* reference, TES3::Spell* spell, TES3::BaseObject* target);

		void Drop(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate, mwLong count);

		void Equip(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate);

		void ExplodeSpell(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* spellTemplate);

		bool HasItemEquipped(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate);

		mwLong GetItemCount(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate);

		bool GetSpellEffects(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* spellTemplate);

		void PlaceAtPC(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* placedTemplate, mwLong count, mwFloat distance, mwFloat direction);

		void Position(TES3::Script* script, TES3::Reference* reference, mwFloat x, mwFloat y, mwFloat z, mwFloat rotation);

		void PositionCell(TES3::Script* script, TES3::Reference* reference, mwFloat x, mwFloat y, mwFloat z, mwFloat rotation, const char* cell);

		void RemoveItem(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate, mwLong count);

		void RemoveSpell(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* spellTemplate);

		bool ScriptRunning(TES3::Script* script, TES3::Script* targetScript);

		void SetLevel(TES3::Script* script, TES3::Reference* reference, mwShort level);

		void StartCombat(TES3::Script* script, TES3::Reference* reference, TES3::Reference* target);

		void StartScript(TES3::Script* script, TES3::Reference* reference, TES3::Script* targetScript);

		void StopScript(TES3::Script* script, TES3::Script* targetScript);

		//
		// In-function hook callbacks for getting script variables.
		//

		extern TES3::Reference* lastCreatedPlaceAtPCReference;

		void OnPlaceReferenceCreated(TES3::Reference* reference);
	}
}