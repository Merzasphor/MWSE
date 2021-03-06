#include "ArrayFunctions.h"

bool CreateArrayFunction::execute()
{
	long id = machine.CreateArray("xCreateArray");
	return (machine.push(id));
}

bool GetArrayValueFunction::execute()
{
	long id;
	long index;
	long value = 0;
	if (machine.pop(id) && machine.pop(index)) {
		value = machine.GetArrayValue("xGetArrayValue", id, index);
	}
	return (machine.push(value));
}

bool SetArrayValueFunction::execute()
{
	long id;
	long index;
	long value;
	long result = 0;
	if (machine.pop(id) && machine.pop(index) && machine.pop(value)) {
		result = machine.SetArrayValue("xSetArrayValue", id, index, value);
	}
	return (machine.push(result));
}

bool GetArraySizeFunction::execute()
{
	long id;
	long size = 0;
	if (machine.pop(id)) {
		size = machine.GetArraySize("xGetArraySize", id);
	}
	return (machine.push(size));
}

bool ClearArrayFunction::execute()
{
	long id;
	long success = 0;
	if (machine.pop(id)) {
		success = machine.ClearArray("xClearArray", id);
	}
	return (machine.push(success));
}
