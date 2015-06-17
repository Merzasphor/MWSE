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
		cLog::mLogMessage("xCreateArray: Unable to create array. id exceeds MAXARRAYID. id: %d\n", id);
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
				value = a[index];
			}
			else
			{
				cLog::mLogMessage("xGetArrayValue: Array index out of bounds. id: %d index: %d\n", id, index);
			}
		}
		else
		{
			cLog::mLogMessage("xGetArrayValue: Invalid array id. id: %d\n", id);
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

	if (machine.pop(id) && machine.pop(index) && machine.pop(value))
	{
		if (id > 0 && id <= MAXARRAYID)
		{
			if (index >= 0)
			{
				std::vector<long> & a = arrays[id - 1];
				if (index + 1 > a.size())
				{
					a.resize(index + 1);
				}
				a[index] = value;
				result = true;
			}
			else
			{
				cLog::mLogMessage("xSetArrayValue: Array index out of bounds. id: %d index: %d\n", id, index);
			}
		}
		else
		{
			cLog::mLogMessage("xSetArrayValue: Invalid array id. id: %d\n", id);
		}
	}

	return (machine.push(static_cast<VMREGTYPE>(result)));
}