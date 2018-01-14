/************************************************************************
	
	ScriptUtil.cpp - Copyright (c) 2008 The MWSE Project
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

#include "ScriptUtil.h"

namespace mwse
{
	namespace mwscript
	{
		int getInstructionPointer() {
			return *reinterpret_cast<int*>(TES3_IP_IMAGE);
		}

		void setInstructionPointer(int IP) {
			*reinterpret_cast<int*>(TES3_IP_IMAGE) = IP;
		}

		REFRRecord_t* getScriptTargetReference() {
			return *reinterpret_cast<REFRRecord_t**>(TES3_SCRIPTTARGETREF_IMAGE);
		}

		void setScriptTargetReference(REFRRecord_t* reference) {
			*reinterpret_cast<REFRRecord_t**>(TES3_SCRIPTTARGETREF_IMAGE) = reference;
			setScriptTargetTemplate(reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer));
		}

		TES3DefaultTemplate_t* getScriptTargetTemplate() {
			return *reinterpret_cast<TES3DefaultTemplate_t**>(TES3_SCRIPTTARGETTEMPL_IMAGE);
		}

		void setScriptTargetTemplate(TES3DefaultTemplate_t* record) {
			*reinterpret_cast<TES3DefaultTemplate_t**>(TES3_SCRIPTTARGETTEMPL_IMAGE) = record;
		}

		TES3DefaultTemplate_t* getScriptSecondObject() {
			return *reinterpret_cast<TES3DefaultTemplate_t**>(TES3_SECONDOBJECT_IMAGE);
		}

		void setScriptSecondObject(TES3DefaultTemplate_t* record) {
			*reinterpret_cast<TES3DefaultTemplate_t**>(TES3_SECONDOBJECT_IMAGE) = record;
		}

		mwLong_t getScriptVariableIndex() {
			return *reinterpret_cast<mwLong_t*>(TES3_VARINDEX_IMAGE);
		}

		void setScriptVariableIndex(mwLong_t index) {
			*reinterpret_cast<mwLong_t*>(TES3_VARINDEX_IMAGE) = index;
		}

		mwFloat_t getDestinationX() {
			return *reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_X_IMAGE);
		}

		void setDestinationX(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_X_IMAGE) = value;
		}

		mwFloat_t getDestinationY() {
			return *reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Y_IMAGE);
		}

		void setDestinationY(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Y_IMAGE) = value;
		}

		mwFloat_t getDestinationZ() {
			return *reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Z_IMAGE);
		}

		void setDestinationZ(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Z_IMAGE) = value;
		}

		void setDestination(mwFloat_t x, mwFloat_t y, mwFloat_t z) {
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_X_IMAGE) = x;
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Y_IMAGE) = y;
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Z_IMAGE) = z;
		}

		float RunOriginalOpCode(SCPTRecord_t* script, REFRRecord_t* reference, int opCode, TES3DefaultTemplate_t* objectParam = NULL, char charParam = '_', float unk1 = 0.0f, float unk2 = 0.0f) {
			float result = 0.0;

			REFRRecord_t* cachedTargetReference = getScriptTargetReference();
			TES3DefaultTemplate_t* cachedTargetTemplate = getScriptTargetTemplate();

			setScriptTargetReference(reference);

			int IP = getInstructionPointer();

			static int origRunOpCode = 0x505770;
			__asm {
				mov ecx, script
				push objectParam
				push charParam
				push opCode

				call origRunOpCode

				fstp result
			}

			setInstructionPointer(IP);

			setScriptTargetReference(cachedTargetReference);
			setScriptTargetTemplate(cachedTargetTemplate);

			return result;
		}

		void AddItem(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate, mwLong_t count) {
			// Cache previous script variables.
			mwLong_t cachedVarIndex = getScriptVariableIndex();
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			setScriptVariableIndex(count);
			RunOriginalOpCode(script, reference, TES3_OPCODE_ADDITEM);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}

		void AddSpell(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* spellTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			RunOriginalOpCode(script, reference, TES3_OPCODE_ADDSPELL);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void AITravel(SCPTRecord_t* script, REFRRecord_t* reference, mwFloat_t x, mwFloat_t y, mwFloat_t z) {
			// Cache destination values.
			mwFloat_t cachedDestinationX = getDestinationX();
			mwFloat_t cachedDestinationY = getDestinationY();
			mwFloat_t cachedDestinationZ = getDestinationZ();

			// Call original opcode.
			setDestination(x, y, z);
			RunOriginalOpCode(script, reference, TES3_OPCODE_AITRAVEL);

			// Restore destination values.
			setDestination(cachedDestinationX, cachedDestinationY, cachedDestinationZ);
		}

		void Drop(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate, mwLong_t count) {
			// Cache previous script variables.
			mwLong_t cachedVarIndex = getScriptVariableIndex();
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			setScriptVariableIndex(count);
			RunOriginalOpCode(script, reference, TES3_OPCODE_DROP);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}

		void Equip(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			RunOriginalOpCode(script, reference, TES3_OPCODE_EQUIP);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void ExplodeSpell(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* spellTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			RunOriginalOpCode(script, reference, TES3_OPCODE_EXPLODESPELL);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		bool HasItemEquipped(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			float value = RunOriginalOpCode(script, reference, TES3_OPCODE_HASITEMEQUIPPED);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);

			return value != 0.0f;
		}

		bool GetSpellEffects(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* spellTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			mwFloat_t value = RunOriginalOpCode(script, reference, TES3_OPCODE_GETSPELLEFFECTS);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);

			return value != 0.0f;
		}

		void PlaceAtPC(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* placedTemplate, mwLong_t count, mwFloat_t distance, mwFloat_t direction) {
			// Cache script variables.
			mwFloat_t cachedDestinationX = getDestinationX();
			mwFloat_t cachedDestinationY = getDestinationY();
			mwLong_t cachedVarIndex = getScriptVariableIndex();

			// Call original opcode.
			setScriptVariableIndex(count);
			setDestinationX(distance);
			setDestinationY(direction);
			RunOriginalOpCode(script, reference, TES3_OPCODE_PLACEATPC);

			// Restore script variables.
			setDestinationX(cachedDestinationX);
			setDestinationY(cachedDestinationY);
			setScriptVariableIndex(cachedVarIndex);
		}
	}
}
