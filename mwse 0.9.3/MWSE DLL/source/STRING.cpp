//String.cpp

#include "STRINGS.h"
#include "TES3MACHINE.h"
#include "DEBUGGING.h"


// 2005-06-25  CDC    Use old C-style permanent storage just because it's easy

typedef std::map<STRING,const char*> STRINGCACHE;   // use a map to make them less volatile

static STRINGCACHE stringcache;

void STRINGS::clear()
{
	stringcache.erase(stringcache.begin(),stringcache.end());
}

const char* STRINGS::add(const char* str)
{
	STRINGCACHE::iterator it= stringcache.find(str);
	if(it==stringcache.end()) {
		const char *strdata = new char[strlen(str)+1];
		strcpy((char*)strdata, str);
		stringcache.insert(STRINGCACHE::value_type(str,strdata));
		it = stringcache.find(str);
	}
	return it->second;
}


STRINGS strings;   // A common string cache

FUNCSTRCMP::FUNCSTRCMP(TES3MACHINE& vm) : machine(vm)
{
}

bool FUNCSTRCMP::execute(void)
{
	bool result= false;
	VMREGTYPE pstr1= 0, pstr2= 0;
	const char* str1= "null";
	const char* str2= "null";
	long cmp= 0;
	if(machine.pop(pstr1)
		&& machine.pop(pstr2)
		&& (str1=machine.GetString((VPVOID)pstr1))!=0
		&& (str2=machine.GetString((VPVOID)pstr2))!=0)
	{
		cmp= ::strcmp(str1,str2);
//		while(*str1 && *str2 && *str1==*str2)
//		{
//			str1++;str2++;
//		}
//		cmp= *str1-*str2;

		result= machine.push(cmp);
	}

#ifdef DEBUGGING
	cLog::mLogMessage("%ld = FUNCSTRCMP(%s,%s) %s\n",cmp,str1,str2,result?"succeeded":"failed");
#endif
	
	return result;
}
