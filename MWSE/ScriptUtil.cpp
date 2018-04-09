/************************************************************************
	
	ScriptUtil.cpp - Copyright (c) 2008 The MWSE Project
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

#include "ScriptUtil.h"

#include "TES3Spell.h"
#include "TES3Reference.h"

namespace mwse
{
	namespace mwscript
	{
		TES3::Reference* lastCreatedPlaceAtPCReference = NULL;

		int getInstructionPointer() {
			return *reinterpret_cast<int*>(TES3_IP_IMAGE);
		}

		void setInstructionPointer(int IP) {
			*reinterpret_cast<int*>(TES3_IP_IMAGE) = IP;
		}

		TES3::ScriptVariables* getLocalScriptVariables() {
			return *reinterpret_cast<TES3::ScriptVariables**>(TES3_LOCALVARIABLES_IMAGE);
		}

		TES3::Reference* getScriptTargetReference() {
			return *reinterpret_cast<TES3::Reference**>(TES3_SCRIPTTARGETREF_IMAGE);
		}

		void setScriptTargetReference(TES3::Reference* reference) {
			*reinterpret_cast<TES3::Reference**>(TES3_SCRIPTTARGETREF_IMAGE) = reference;
			if (reference != NULL) {
				setScriptTargetTemplate(reference->baseObject);
			}
			else {
				setScriptTargetTemplate(reinterpret_cast<TES3::BaseObject*>(NULL));
			}
		}

		TES3::BaseObject* getScriptTargetTemplate() {
			return *reinterpret_cast<TES3::BaseObject**>(TES3_SCRIPTTARGETTEMPL_IMAGE);
		}

		void setScriptTargetTemplate(TES3::BaseObject* record) {
			*reinterpret_cast<TES3::BaseObject**>(TES3_SCRIPTTARGETTEMPL_IMAGE) = record;
		}

		TES3::BaseObject* getScriptSecondObject() {
			return *reinterpret_cast<TES3::BaseObject**>(TES3_SECONDOBJECT_IMAGE);
		}

		void setScriptSecondObject(const char* string) {
			strncpy(reinterpret_cast<char*>(TES3_SECONDOBJECT_IMAGE), string, strlen(string)+1);
		}

		void setScriptSecondObject(TES3::BaseObject* record) {
			*reinterpret_cast<TES3::BaseObject**>(TES3_SECONDOBJECT_IMAGE) = record;
		}

		long getScriptVariableIndex() {
			return *reinterpret_cast<long*>(TES3_VARINDEX_IMAGE);
		}

		void setScriptVariableIndex(long index) {
			*reinterpret_cast<long*>(TES3_VARINDEX_IMAGE) = index;
		}

		float getScriptDestinationX() {
			return *reinterpret_cast<float*>(TES3_DESTINATION_X_IMAGE);
		}

		void setScriptDestinationX(float value) {
			*reinterpret_cast<float*>(TES3_DESTINATION_X_IMAGE) = value;
		}

		float getScriptDestinationY() {
			return *reinterpret_cast<float*>(TES3_DESTINATION_Y_IMAGE);
		}

		void setScriptDestinationY(float value) {
			*reinterpret_cast<float*>(TES3_DESTINATION_Y_IMAGE) = value;
		}

		float getScriptDestinationZ() {
			return *reinterpret_cast<float*>(TES3_DESTINATION_Z_IMAGE);
		}

		void setScriptDestinationZ(float value) {
			*reinterpret_cast<float*>(TES3_DESTINATION_Z_IMAGE) = value;
		}

		void setScriptDestination(float x, float y, float z) {
			*reinterpret_cast<float*>(TES3_DESTINATION_X_IMAGE) = x;
			*reinterpret_cast<float*>(TES3_DESTINATION_Y_IMAGE) = y;
			*reinterpret_cast<float*>(TES3_DESTINATION_Z_IMAGE) = z;
		}

		float getScriptTargetRotationX() {
			return *reinterpret_cast<float*>(TES3_TARGET_ROTX_IMAGE);
		}

		void setScriptTargetRotationX(float value) {
			*reinterpret_cast<float*>(TES3_TARGET_ROTX_IMAGE) = value;
		}

		float getScriptTargetRotationY() {
			return *reinterpret_cast<float*>(TES3_TARGET_ROTY_IMAGE);
		}

		void setScriptTargetRotationY(float value) {
			*reinterpret_cast<float*>(TES3_TARGET_ROTY_IMAGE) = value;
		}

		float getScriptTargetRotationZ() {
			return *reinterpret_cast<float*>(TES3_TARGET_ROTZ_IMAGE);
		}

		void setScriptTargetRotationZ(float value) {
			*reinterpret_cast<float*>(TES3_TARGET_ROTZ_IMAGE) = value;
		}

		void setScriptTargetRotation(float x, float y, float z) {
			*reinterpret_cast<float*>(TES3_TARGET_ROTX_IMAGE) = x;
			*reinterpret_cast<float*>(TES3_TARGET_ROTY_IMAGE) = y;
			*reinterpret_cast<float*>(TES3_TARGET_ROTZ_IMAGE) = z;
		}

		float RunOriginalOpCode(TES3::Script* script, TES3::Reference* reference, OpCode::OpCode_t opCode, TES3::BaseObject* objectParam = NULL, char charParam = '_', float unk1 = 0.0f, float unk2 = 0.0f) {
			float result = 0.0;

			TES3::Reference* cachedTargetReference = getScriptTargetReference();
			TES3::BaseObject* cachedTargetTemplate = getScriptTargetTemplate();

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

		void Activate(TES3::Script* script, TES3::Reference* reference) {
			RunOriginalOpCode(script, reference, OpCode::Activate);
		}

		void AddItem(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate, long count) {
			// Cache previous script variables.
			long cachedVarIndex = getScriptVariableIndex();
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			setScriptVariableIndex(count);
			RunOriginalOpCode(script, reference, OpCode::AddItem);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}

		void AddSpell(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* spellTemplate) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			RunOriginalOpCode(script, reference, OpCode::AddSpell);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void AITravel(TES3::Script* script, TES3::Reference* reference, float x, float y, float z) {
			// Cache destination values.
			float cachedDestinationX = getScriptDestinationX();
			float cachedDestinationY = getScriptDestinationY();
			float cachedDestinationZ = getScriptDestinationZ();

			// Call original opcode.
			setScriptDestination(x, y, z);
			RunOriginalOpCode(script, reference, OpCode::AITravel);

			// Restore destination values.
			setScriptDestination(cachedDestinationX, cachedDestinationY, cachedDestinationZ);
		}

		void Cast(TES3::Script* script, TES3::Reference* reference, TES3::Spell* spell, TES3::BaseObject* target) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(reinterpret_cast<TES3::BaseObject*>(spell));
			RunOriginalOpCode(script, reference, OpCode::Cast);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void Drop(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate, long count) {
			// Cache previous script variables.
			long cachedVarIndex = getScriptVariableIndex();
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			setScriptVariableIndex(count);
			RunOriginalOpCode(script, reference, OpCode::Drop);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}

		void Equip(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			RunOriginalOpCode(script, reference, OpCode::Equip);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void ExplodeSpell(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* spellTemplate) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			RunOriginalOpCode(script, reference, OpCode::ExplodeSpell);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		bool HasItemEquipped(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			float value = RunOriginalOpCode(script, reference, OpCode::HasItemEquipped);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);

			return value != 0.0f;
		}

		long GetItemCount(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			long value = RunOriginalOpCode(script, reference, OpCode::GetItemCount);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);

			return value;
		}

		bool GetSpellEffects(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* spellTemplate) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			float value = RunOriginalOpCode(script, reference, OpCode::GetSpellEffects);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);

			return value != 0.0f;
		}

		void PlaceAtPC(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* placedTemplate, long count, float distance, float direction) {
			// Cache script variables.
			float cachedDestinationX = getScriptDestinationX();
			float cachedDestinationY = getScriptDestinationY();
			long cachedVarIndex = getScriptVariableIndex();
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

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

		void Position(TES3::Script* script, TES3::Reference* reference, float x, float y, float z, float rotation) {
			// Cache script variables.
			float cachedDestinationX = getScriptDestinationX();
			float cachedDestinationY = getScriptDestinationY();
			float cachedDestinationZ = getScriptDestinationZ();
			float cachedRotationX = getScriptTargetRotationX();
			float cachedRotationY = getScriptTargetRotationY();
			float cachedRotationZ = getScriptTargetRotationZ();

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

		void PositionCell(TES3::Script* script, TES3::Reference* reference, float x, float y, float z, float rotation, const char* cell) {
			// Cache script variables.
			float cachedDestinationX = getScriptDestinationX();
			float cachedDestinationY = getScriptDestinationY();
			float cachedDestinationZ = getScriptDestinationZ();
			float cachedRotationX = getScriptTargetRotationX();
			float cachedRotationY = getScriptTargetRotationY();
			float cachedRotationZ = getScriptTargetRotationZ();
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

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

		void RemoveItem(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* itemTemplate, long count) {
			// Cache previous script variables.
			long cachedVarIndex = getScriptVariableIndex();
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			setScriptVariableIndex(count);
			RunOriginalOpCode(script, reference, OpCode::RemoveItem);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}

		void RemoveSpell(TES3::Script* script, TES3::Reference* reference, TES3::BaseObject* spellTemplate) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(spellTemplate);
			RunOriginalOpCode(script, reference, OpCode::RemoveSpell);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		bool ScriptRunning(TES3::Script* script, TES3::Script* targetScript) {
			// Run original opcode.
			float value = RunOriginalOpCode(script, NULL, OpCode::ScriptRunning, reinterpret_cast<TES3::BaseObject*>(targetScript));

			return value != 0.0f;
		}

		void SetLevel(TES3::Script* script, TES3::Reference* reference, short level) {
			// Cache previous script variables.
			long cachedVarIndex = getScriptVariableIndex();

			// Prepare variables and run original opcode.
			setScriptVariableIndex(level);
			RunOriginalOpCode(script, reference, OpCode::SetLevel);

			// Restore original script variables.
			setScriptVariableIndex(cachedVarIndex);
		}

		void StartCombat(TES3::Script* script, TES3::Reference* reference, TES3::Reference* target) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(reinterpret_cast<TES3::BaseObject*>(target));
			RunOriginalOpCode(script, reference, OpCode::StartCombat);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void StartScript(TES3::Script* script, TES3::Reference* reference, TES3::Script* targetScript) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(reinterpret_cast<TES3::BaseObject*>(targetScript));
			RunOriginalOpCode(script, reference, OpCode::StartScript);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void StopScript(TES3::Script* script, TES3::Script* targetScript) {
			// Cache previous script variables.
			TES3::BaseObject* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(reinterpret_cast<TES3::BaseObject*>(targetScript));
			RunOriginalOpCode(script, NULL, OpCode::StopScript);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
		}

		void OnPlaceReferenceCreated(TES3::Reference* reference) {
			lastCreatedPlaceAtPCReference = reference;
		}
	}
}
