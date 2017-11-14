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