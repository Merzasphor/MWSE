
#pragma once

#include "mwOffsets.h"
#include "mwseTypes.h"
#include "mwseString.h"

namespace mwse
{
	namespace mwscript
	{
		//
		int getInstructionPointer();

		//
		void setInstructionPointer(int IP);

		//
		TES3DefaultTemplate_t* getScriptSecondObject();

		//
		void setScriptSecondObject(TES3DefaultTemplate_t* record);

		// 
		mwLong_t getScriptVariableIndex();

		// 
		void setScriptVariableIndex(mwLong_t index);

		//
		float RunOriginalOpCode(SCPTRecord_t* script, float unk1, float unk2, int opCode, char charParam, REFRRecord_t* reference);

		//
		void AddItem(SCPTRecord_t* script, REFRRecord_t* reference, TES3DefaultTemplate_t* itemTemplate, mwLong_t count);
	}
}