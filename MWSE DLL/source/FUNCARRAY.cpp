#include "FUNCARRAY.h"
#include "cLog.h"

bool FUNCCREATEARRAY::execute(void)
{
	long id = machine.CreateArray("xCreateArray");
	return (machine.push(id));
}

bool FUNCGETARRAYVALUE::execute(void)
{
	long id;
	long index;
	long value = 0;
	if (machine.pop(id) && machine.pop(index)) {
		value = machine.GetArrayValue("xGetArrayValue", id, index);
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
		result = machine.SetArrayValue("xSetArrayValue", id, index, value);
	}
	return (machine.push(result));
}