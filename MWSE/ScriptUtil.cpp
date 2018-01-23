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
		REFRRecord_t* lastCreatedPlaceAtPCReference = NULL;

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
			if (reference != NULL) {
				setScriptTargetTemplate(reinterpret_cast<TES3DefaultTemplate_t*>(reference->recordPointer));
			}
			else {
				setScriptTargetTemplate(reinterpret_cast<TES3DefaultTemplate_t*>(NULL));
			}
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

		void setScriptSecondObject(const char* string) {
			strncpy(reinterpret_cast<char*>(TES3_SECONDOBJECT_IMAGE), string, strlen(string)+1);
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

		mwFloat_t getScriptDestinationX() {
			return *reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_X_IMAGE);
		}

		void setScriptDestinationX(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_X_IMAGE) = value;
		}

		mwFloat_t getScriptDestinationY() {
			return *reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Y_IMAGE);
		}

		void setScriptDestinationY(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Y_IMAGE) = value;
		}

		mwFloat_t getScriptDestinationZ() {
			return *reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Z_IMAGE);
		}

		void setScriptDestinationZ(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Z_IMAGE) = value;
		}

		void setScriptDestination(mwFloat_t x, mwFloat_t y, mwFloat_t z) {
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_X_IMAGE) = x;
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Y_IMAGE) = y;
			*reinterpret_cast<mwFloat_t*>(TES3_DESTINATION_Z_IMAGE) = z;
		}

		mwFloat_t getScriptTargetRotationX() {
			return *reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTX_IMAGE);
		}

		void setScriptTargetRotationX(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTX_IMAGE) = value;
		}

		mwFloat_t getScriptTargetRotationY() {
			return *reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTY_IMAGE);
		}

		void setScriptTargetRotationY(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTY_IMAGE) = value;
		}

		mwFloat_t getScriptTargetRotationZ() {
			return *reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTZ_IMAGE);
		}

		void setScriptTargetRotationZ(mwFloat_t value) {
			*reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTZ_IMAGE) = value;
		}

		void setScriptTargetRotation(mwFloat_t x, mwFloat_t y, mwFloat_t z) {
			*reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTX_IMAGE) = x;
			*reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTY_IMAGE) = y;
			*reinterpret_cast<mwFloat_t*>(TES3_TARGET_ROTZ_IMAGE) = z;
		}

		float RunOriginalOpCode(SCPTRecord_t* script, REFRRecord_t* reference, OpCode::OpCode_t opCode, TES3DefaultTemplate_t* objectParam = NULL, char charParam = '_', float unk1 = 0.0f, float unk2 = 0.0f) {
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
			RunOriginalOpCode(script, reference, OpCode::AddItem);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}

		void AddSpell(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* spellTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			RunOriginalOpCode(script, reference, OpCode::AddSpell);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void AITravel(SCPTRecord_t* script, REFRRecord_t* reference, mwFloat_t x, mwFloat_t y, mwFloat_t z) {
			// Cache destination values.
			mwFloat_t cachedDestinationX = getScriptDestinationX();
			mwFloat_t cachedDestinationY = getScriptDestinationY();
			mwFloat_t cachedDestinationZ = getScriptDestinationZ();

			// Call original opcode.
			setScriptDestination(x, y, z);
			RunOriginalOpCode(script, reference, OpCode::AITravel);

			// Restore destination values.
			setScriptDestination(cachedDestinationX, cachedDestinationY, cachedDestinationZ);
		}

		void Cast(SCPTRecord_t* script, REFRRecord_t* reference, SPELRecord_t* spell, TES3DefaultTemplate_t* target) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(reinterpret_cast<TES3DefaultTemplate_t*>(spell));
			RunOriginalOpCode(script, reference, OpCode::Cast);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void Drop(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate, mwLong_t count) {
			// Cache previous script variables.
			mwLong_t cachedVarIndex = getScriptVariableIndex();
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			setScriptVariableIndex(count);
			RunOriginalOpCode(script, reference, OpCode::Drop);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}

		void Equip(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			RunOriginalOpCode(script, reference, OpCode::Equip);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void ExplodeSpell(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* spellTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			RunOriginalOpCode(script, reference, OpCode::ExplodeSpell);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		bool HasItemEquipped(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			float value = RunOriginalOpCode(script, reference, OpCode::HasItemEquipped);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);

			return value != 0.0f;
		}

		bool GetSpellEffects(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* spellTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			mwFloat_t value = RunOriginalOpCode(script, reference, OpCode::GetSpellEffects);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);

			return value != 0.0f;
		}

		void PlaceAtPC(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* placedTemplate, mwLong_t count, mwFloat_t distance, mwFloat_t direction) {
			// Cache script variables.
			mwFloat_t cachedDestinationX = getScriptDestinationX();
			mwFloat_t cachedDestinationY = getScriptDestinationY();
			mwLong_t cachedVarIndex = getScriptVariableIndex();
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Call original opcode.
			setScriptVariableIndex(count);
			setScriptDestinationX(distance);
			setScriptDestinationY(direction);
			setScriptSecondObject(placedTemplate);
			RunOriginalOpCode(script, reference, OpCode::PlaceAtPC);

			// Restore script variables.
			setScriptDestinationX(cachedDestinationX);
			setScriptDestinationY(cachedDestinationY);
			setScriptVariableIndex(cachedVarIndex);
			setScriptSecondObject(cachedSecondObject);
		}

		void Position(SCPTRecord_t* script, REFRRecord_t* reference, mwFloat_t x, mwFloat_t y, mwFloat_t z, mwFloat_t rotation) {
			// Cache script variables.
			mwFloat_t cachedDestinationX = getScriptDestinationX();
			mwFloat_t cachedDestinationY = getScriptDestinationY();
			mwFloat_t cachedDestinationZ = getScriptDestinationZ();
			mwFloat_t cachedRotationX = getScriptTargetRotationX();
			mwFloat_t cachedRotationY = getScriptTargetRotationY();
			mwFloat_t cachedRotationZ = getScriptTargetRotationZ();

			// Call original opcode.
			setScriptDestination(x, y, z);
			setScriptTargetRotation(0.0f, 0.0f, rotation);
			RunOriginalOpCode(script, reference, OpCode::Position);

			// Restore script variables.
			setScriptDestinationX(cachedDestinationX);
			setScriptDestinationY(cachedDestinationY);
			setScriptDestinationZ(cachedDestinationZ);
			setScriptTargetRotationX(cachedRotationX);
			setScriptTargetRotationY(cachedRotationY);
			setScriptTargetRotationZ(cachedRotationZ);
		}

		void PositionCell(SCPTRecord_t* script, REFRRecord_t* reference, mwFloat_t x, mwFloat_t y, mwFloat_t z, mwFloat_t rotation, const char* cell) {
			// Cache script variables.
			mwFloat_t cachedDestinationX = getScriptDestinationX();
			mwFloat_t cachedDestinationY = getScriptDestinationY();
			mwFloat_t cachedDestinationZ = getScriptDestinationZ();
			mwFloat_t cachedRotationX = getScriptTargetRotationX();
			mwFloat_t cachedRotationY = getScriptTargetRotationY();
			mwFloat_t cachedRotationZ = getScriptTargetRotationZ();
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Call original opcode.
			setScriptDestination(x, y, z);
			setScriptTargetRotation(0.0f, 0.0f, rotation);
			setScriptSecondObject(cell);
			RunOriginalOpCode(script, reference, OpCode::PositionCell);

			// Restore script variables.
			setScriptDestinationX(cachedDestinationX);
			setScriptDestinationY(cachedDestinationY);
			setScriptDestinationZ(cachedDestinationZ);
			setScriptTargetRotationX(cachedRotationX);
			setScriptTargetRotationY(cachedRotationY);
			setScriptTargetRotationZ(cachedRotationZ);
			setScriptSecondObject(cachedSecondObject);
		}

		void RemoveItem(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate, mwLong_t count) {
			// Cache previous script variables.
			mwLong_t cachedVarIndex = getScriptVariableIndex();
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			setScriptVariableIndex(count);
			RunOriginalOpCode(script, reference, OpCode::RemoveItem);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}

		void RemoveSpell(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* spellTemplate) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			RunOriginalOpCode(script, reference, OpCode::RemoveSpell);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void SetLevel(SCPTRecord_t* script, REFRRecord_t* reference, mwShort_t level) {
			// Cache previous script variables.
			mwLong_t cachedVarIndex = getScriptVariableIndex();

			// Prepare variables and run original opcode.
			setScriptVariableIndex(level);
			RunOriginalOpCode(script, reference, OpCode::SetLevel);

			// Restore original script variables.
			setScriptVariableIndex(cachedVarIndex);
		}

		void StartCombat(SCPTRecord_t* script, REFRRecord_t* reference, REFRRecord_t* target) {
			// Cache previous script variables.
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(reinterpret_cast<TES3DefaultTemplate_t*>(target));
			RunOriginalOpCode(script, reference, OpCode::StartCombat);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void OnPlaceReferenceCreated(REFRRecord_t* reference) {
			lastCreatedPlaceAtPCReference = reference;
		}
	}
}
