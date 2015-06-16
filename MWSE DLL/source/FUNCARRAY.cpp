#include "FUNCARRAY.h"
#include "cLog.h"

#include <vector>

long const MAXARRAYID = 16777215; // max 24 bit int - avoid exceding MW global precision

static std::vector< std::vector< long > > arrays;

bool FUNCCREATEARRAY::execute(void)
{
	long id = 0;
	long newId;

	if (arrays.empty())
	{ 
		newId = 1;
	}
	else
	{
		newId = 1 + arrays.size();
	}

	if (newId <= MAXARRAYID)
	{
		id = newId;
		arrays.push_back(std::vector<long>());
	}
	else
	{
		cLog::mLogMessage("xCreateArray: Unable to create array. id: %d", id);
	}

#ifdef DEBUGGING
	cLog::mLogMessage("%f= FUNCCREATEARRAY()\n",size);
#endif	

	return (machine.push(id));
}

bool FUNCGETARRAYVALUE::execute(void)
{
	long id;
	long index;
	long value = 0;

	if (machine.pop(id) && machine.pop(index))
	{
		if ((id > 0 && id <= arrays.size()))
		{
			std::vector<long> const & a = arrays[id - 1];
			if (index >= 0 && index < a.size())
			{	
				if (index <= a.size() - 1)
				{
					value = a[index];
				}
				else
				{
					cLog::mLogMessage("xGetArrayValue: Array index out of bounds. id: %d index: %d", id, index);
				}
			}
		}
	}

	return (machine.push(value));
}

bool FUNCSETARRAYVALUE::execute(void)
{
	long id;
	long index;
	long value;
	bool result = false;

	if (machine.pop(id) && id > 0 && id <= MAXARRAYID
		&& machine.pop(index) && index >= 0
		&& machine.pop(value))
	{
		std::vector<long> & a = arrays[id - 1];
		if (index + 1 > a.size())
		{
			a.resize(index + 1);
		}
		a[index] = value;
		result = true;
	}

	return (machine.push(static_cast<VMREGTYPE>(result)));
}