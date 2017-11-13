#include "FUNCARRAY.h"
#include "cLog.h"

bool FUNCCREATEARRAY::execute(void)
{
	long id;
	TES3MACHINE::ArrayError error = machine.CreateArray(&id);
	if (error == TES3MACHINE::kInvalidId) {
		cLog::mLogMessage(
			"xCreateArray: Unable to create array. Maximum number of arrays reached. id: %d\n",
			id);
	}
	return (machine.push(id));
}

bool FUNCGETARRAYVALUE::execute(void)
{
	long id;
	long index;
	long value = 0;
	if (machine.pop(id) && machine.pop(index)) {
		TES3MACHINE::ArrayError error = machine.GetArrayValue(id, index, &value);
		if (error == TES3MACHINE::kInvalidId) {
			cLog::mLogMessage("xGetArrayValue: Invalid array id: %d\n", id);
		} else if (error == TES3MACHINE::kOutOfBounds) {
			cLog::mLogMessage(
				"xGetArrayValue: Array index out of bounds. id: %d index: %d\n",
				id, index);
		}
	}
	return (machine.push(value));
}

bool FUNCSETARRAYVALUE::execute(void)
{
	long id;
	long index;
	long value;
	long result = 0;
	if (machine.pop(id) && machine.pop(index) && machine.pop(value)) {
		TES3MACHINE::ArrayError error = machine.SetArrayValue(id, index, value);
		if (error == TES3MACHINE::kOutOfBounds) {
			cLog::mLogMessage("xSetArrayValue: Array index out of bounds. id: %d index: %d\n", id, index);
		} else if (error == TES3MACHINE::kInvalidId){
			cLog::mLogMessage("xSetArrayValue: Invalid array id: %d\n", id);
		} else if (error == TES3MACHINE::kNoError) {
			result = 1;
		}
	}
	return (machine.push(result));
}