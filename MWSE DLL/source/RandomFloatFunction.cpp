#include "RandomFloatFunction.h"

bool RandomFloatFunction::execute()
{
	float min, max;
	float result = 0.0;
	if (machine.pop(min) && machine.pop(max) && min <= max) {
		result = machine.GetRandomFloat(min, max);
	}
	return machine.push(result);
}