#pragma once

#include "mwseString.h"

#include "TES3Defines.h"

namespace mwse {
	class VMExecuteInterface {
	public:
		//VirtualMachine specific
		virtual long* getScriptIP() = 0;	//to get the script Instruction Pointer, (for functions that change this, like jump and call like things).

		//local variables, methods to access local variables
		virtual long getLongVariable(int index) = 0;							//by index
		virtual long getLongVariable(const char* id) = 0;						//by name
		virtual long getLongVariable(int index, TES3::Reference& reference) = 0;	//foreign
		virtual void setLongVariable(int index, long value) = 0;
		virtual void setLongVariable(const char* id, long value) = 0;
		virtual void setLongVariable(int index, long value, TES3::Reference& reference) = 0;

		virtual short getShortVariable(int index) = 0;
		virtual short getShortVariable(const char* id) = 0;
		virtual short getShortVariable(int index, TES3::Reference& reference) = 0;
		virtual void setShortVariable(int index, short value) = 0;
		virtual void setShortVariable(const char* id, short value) = 0;
		virtual void setShortVariable(int index, short value, TES3::Reference& reference) = 0;

		virtual float getFloatVariable(int index) = 0;
		virtual float getFloatVariable(const char* id) = 0;
		virtual float getFloatVariable(int index, TES3::Reference& reference) = 0;
		virtual void setFloatVariable(int index, float value) = 0;
		virtual void setFloatVariable(const char* id, float value) = 0;
		virtual void setFloatVariable(int index, float value, TES3::Reference& reference) = 0;

		//global variables, methods to access global variables
		virtual long getLongGlobal(const char* id) = 0;
		virtual void setLongGlobal(const char* id, long value) = 0;

		virtual short getShortGlobal(const char* id) = 0;
		virtual void setShortGlobal(const char* id, short value) = 0;

		virtual float getFloatGlobal(const char* id) = 0;
		virtual void setFloatGlobal(const char* id, float value) = 0;

		//objects and stuff
		//look at GETREF function in old MWSE for examples on how to fetch references!
		virtual TES3::Reference* getReference(const char* id) = 0; //can also be called getMorrowindObject i guess, this fetches the correct reference for the given object (player, npc, book, light, etc)
		virtual TES3::Reference* getReference() = 0; //gets the current reference, maybe it's better to put this in another function. it'll do for now

		virtual void setReference(TES3::Reference* reference) = 0; //this sets the reference, to be used for the next instruction (also works on other MWSE instructions in the same run), but for all other things, this needs to be called before the function! (as it needs a run in runScript)

		virtual TES3::Reference* getCurrentTarget() = 0;	//get the current reference under the crosshairs
		virtual TES3::BaseObject* getTemplate(const char* id) = 0;	//get a template (spell, item, npc) given an id. template are NOT REFR objects. they are 'not in the game yet', but available.

		//getParameters
		//virtual * get*Parameter() = 0;

		//virtual template<class T> void getStreamValue(T returnValue, bool peek = false) = 0;	//T must be in paramter list... if peek is true, then it doesn't increase the stream pointer
		//OR
		virtual char getByteValue(bool peek = false) = 0;			//peek means don't increase stream pointer
		virtual short getShortValue(bool peek = false) = 0;
		virtual long getLongValue(bool peek = false) = 0;
		virtual float getFloatValue(bool peek = false) = 0;

		virtual mwseString& getString(long fromStack) = 0;	//only ment for stack-based syntax!, parameter-based syntax functions should use getStringParameter!!!

		virtual void dumpScriptVariables() = 0;

		virtual TES3::Script* getScript() = 0;
	};
};