#include "FUNCARRAY.h"
#include "cLog.h"

#include <map>

long const MAXARRAYID = 16777215; // max 24 bit int - avoid exceding MW global precision

struct MWSEArray
{
	enum ArrayTypes
	{
		Float,
		Long
	};
	ArrayTypes type;
	long size;
	void * data;
};

static std::map<long, MWSEArray> arrays;

bool FUNCCREATEARRAY::execute(void)
{
	long size;
	long type;
	long id = 0;

	if (machine.pop(type) && type >= MWSEArray::Float && type <= MWSEArray::Long &&
		machine.pop(size) && size > 0)
	{
		long newId;
		if (arrays.empty())
		{ 
			newId = 1;
		}
		else
		{
			newId = 1 + arrays.rbegin()->first;
		}

		if (newId <= MAXARRAYID)
		{
			id = newId;
			MWSEArray newArray;
			newArray.type = static_cast<MWSEArray::ArrayTypes>(type);
			newArray.size = size;
			if (newArray.type == MWSEArray::Float)
			{
				newArray.data = reinterpret_cast<void*>(new float[newArray.size]);
			}
			else if (newArray.type == MWSEArray::Long)
			{
				newArray.data = reinterpret_cast<void*>(new long[newArray.size]);
			}
			arrays[id] = newArray;
		}
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

	if (machine.pop(id) && id > 0 && id <= MAXARRAYID
		&& machine.pop(index) && index >= 0)
	{
		MWSEArray const & a = arrays[id];
		if (index <= a.size - 1)
		{
			if (a.type == MWSEArray::Float)
			{
				float * data = reinterpret_cast<float*>(a.data);
				return(machine.push(data[index]));
			}
			else if (a.type == MWSEArray::Long)
			{
				long * data = reinterpret_cast<long*>(a.data);
				return(machine.push(data[index]));
			}
		}
		else
		{
			cLog::mLogMessage("xGetArrayValue: Array index out of bounds. id: %d index: %d", id, index);
		}
	}

	return (machine.push(static_cast<VMREGTYPE>(0)));
}

bool FUNCSETARRAYVALUE::execute(void)
{
	long id;
	long index;
	bool result = false;

	if (machine.pop(id) && id > 0 && id <= MAXARRAYID
		&& machine.pop(index) && index >= 0)
	{
		MWSEArray const & a = arrays[id];
		if (index <= a.size - 1)
		{
			if (a.type == MWSEArray::Float)
			{
				float value;
				if (machine.pop(value))
				{
					float * data = reinterpret_cast<float*>(a.data);
					data[index] = value;
					result = true;
				}
				
			}
			else if (a.type == MWSEArray::Long)
			{
				long value;
				if (machine.pop(value))
				{
					long * data = reinterpret_cast<long*>(a.data);
					data[index] = value;
					result = true;
				}
			}
		}
		else
		{
			cLog::mLogMessage("xSetArrayValue: Array index out of bounds. id: %d index: %d", id, index);
		}
	}

	return (machine.push(static_cast<VMREGTYPE>(result)));
}