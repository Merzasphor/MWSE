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

		float RunOriginalOpCode(SCPTRecord_t* script, float unk1, float unk2, int opCode, char charParam, REFRRecord_t* reference) {
			float result = 0.0;

			int IP = getInstructionPointer();

			static int origRunOpCode = 0x505770;
			__asm {
				mov ecx, script
				push reference
				push charParam
				push opCode

				call origRunOpCode

				fstp result
			}

			setInstructionPointer(IP);

			return result;
		}

		void AddItem(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate, mwLong_t count) {
			// Cache previous script variables.
			mwLong_t cachedVarIndex = getScriptVariableIndex();
			TES3DefaultTemplate_t* cachedSecondObject = getScriptSecondObject();

			// Prepare variables and run original opcode.
			setScriptSecondObject(itemTemplate);
			setScriptVariableIndex(count);
			RunOriginalOpCode(script, 0.0f, 0.0f, 0x10D4, ' ', reference);

			// Restore original script variables.
			setScriptSecondObject(cachedSecondObject);
			setScriptVariableIndex(cachedVarIndex);
		}
	}
}