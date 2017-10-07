#include "RandomLongFunction.h"

bool RandomLongFunction::execute()
{
	long min, max;
	long result = 0.0;
	if (machine.pop(min) && machine.pop(max) && min <= max) {
		result = machine.GetRandomLong(min, max);
	}
	return machine.push(result);
}