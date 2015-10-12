//FuncFile.cpp

#include "FUNCFILE.h"
#include <stdio.h>
#include "DEBUGGING.h"
#include "FUNCTEXT.h"
// 22-08-2006 Tp21
#include "warnings.h"

#include <string>

FUNCFILEREADTWOBYTES::FUNCFILEREADTWOBYTES(TES3MACHINE& vm) : machine(vm)
{
}

FUNCFILEREADFOURBYTES::FUNCFILEREADFOURBYTES(TES3MACHINE& vm) : machine(vm)
{
}

FUNCFILEREWIND::FUNCFILEREWIND(TES3MACHINE& vm) : machine(vm)
{
}

FUNCFILESEEK::FUNCFILESEEK(TES3MACHINE& vm) : machine(vm)
{
}

FUNCFILEREADSTRING::FUNCFILEREADSTRING(TES3MACHINE& vm) : machine(vm)
{
}

FUNCFILEWRITETWOBYTES::FUNCFILEWRITETWOBYTES(TES3MACHINE& vm)
:	machine(vm)
{
}

FUNCFILEWRITEFOURBYTES::FUNCFILEWRITEFOURBYTES(TES3MACHINE& vm) : machine(vm)
{
}

FUNCFILEWRITESTRING::FUNCFILEWRITESTRING(TES3MACHINE& vm) :	machine(vm)
{
}

bool FUNCFILEREADTWOBYTES::execute(void)
{
	bool result = false;

	struct { VMREGTYPE pfilename; VMREGTYPE numshorts; } stackparams;
	const char* filename= "null";
	VMREGTYPE stackpointer= 0;
	VMSHORT* datain= 0;
	int numshorts= 0;
	
	if(machine.GetRegister(SP,stackpointer)
		&& machine.ReadMem((VPVOID)stackpointer,&stackparams,sizeof(stackparams))
		&& (filename=machine.GetString((VPVOID)stackparams.pfilename))!=0)
	{
		stackpointer+= sizeof(stackparams)-stackparams.numshorts*sizeof(VMREGTYPE)-sizeof(VMREGTYPE);

		if(machine.SetRegister(SP,stackpointer))
		{
			datain= new VMSHORT[stackparams.numshorts];

			numshorts= filesys.read((char*)filename,datain,stackparams.numshorts*sizeof(VMSHORT))/sizeof(VMSHORT);

			VMREGTYPE* dataout= new VMREGTYPE[numshorts+1];
			dataout[0]= numshorts;
			for(int i=numshorts-1;i>=0;i--)
				dataout[i+1]= datain[i];

			result= machine.WriteMem((VPVOID)stackpointer,dataout,numshorts*sizeof(VMREGTYPE)+sizeof(VMREGTYPE));

			delete []dataout;
		}
	}

	if(datain) delete []datain;
		
	return result;
}

bool FUNCFILEREADFOURBYTES::execute(void)
{
	bool result= false;

	struct { VMREGTYPE pfilename; VMREGTYPE numunits; } stackparams;
	const char* filename= "null";
	VMREGTYPE stackpointer= 0;
	VMREGTYPE* data= 0;
	int count= 0;
	
	if(machine.GetRegister(SP,stackpointer)
		&& machine.ReadMem((VPVOID)stackpointer,&stackparams,sizeof(stackparams))
		&& (filename=machine.GetString((VPVOID)stackparams.pfilename))!=0)
	{
		stackpointer+= sizeof(stackparams)-stackparams.numunits*sizeof(VMREGTYPE)-sizeof(VMREGTYPE);

		if(machine.SetRegister(SP,stackpointer))
		{
			data= new VMREGTYPE[stackparams.numunits+1];

			count= filesys.read((char*)filename,&data[1],stackparams.numunits*sizeof(VMREGTYPE))/sizeof(VMREGTYPE);

			data[0]= count;

			result= machine.WriteMem((VPVOID)stackpointer,data,count*sizeof(VMREGTYPE)+sizeof(VMREGTYPE));
		}
	}

	if(data) delete []data;
		
	return result;
}

bool FUNCFILEREWIND::execute(void)
{
	bool result = false;

	VMREGTYPE pfilename = 0;
	const char* filename = "null";

	if ( machine.pop ( pfilename )
		&& ( filename = machine.GetString ( ( VPVOID ) pfilename ) ) !=0 )
	{
		result = filesys.seek ( filename, 0 );
	}

	return result;
}

bool FUNCFILESEEK::execute(void)
{
	bool result = false;

	VMREGTYPE pfilename = 0;
	const char* filename = "null";
	VMREGTYPE offset = 0;

	if ( machine.pop ( pfilename )
		&& ( filename = machine.GetString ( ( VPVOID ) pfilename ) ) !=0
		&& machine.pop ( offset ) )
	{
		result = filesys.seek ( filename, offset );
	}

	return result;
}



bool FUNCFILEREADSTRING::execute(void)
{
	bool result= false;

	VMREGTYPE pfilename= 0;
	const char* filename= "null";
	const char* stored= "null";

	if(machine.pop(pfilename)
		&& (filename=machine.GetString((VPVOID)pfilename))!=0)
	{
		char string[sizeof(TES3IDSTRING)]= "\0";

// 2005-07-10  CDC  Modified readcstring returns number of characters read instead of strlen now
		if(filesys.readcstring(filename, string, sizeof(string)) > 1)
			stored = strings.add(string);

		result = machine.push((VMREGTYPE)stored);
	}

	return result;
}

bool FUNCFILEWRITETWOBYTES::execute(void)
{
	bool result = false;

	VMREGTYPE pfilename = 0;
	VMREGTYPE val = 0;
	const char* filename = "null";

	if(machine.pop(pfilename)
		&& machine.pop(val)
		&& (filename=machine.GetString((VPVOID)pfilename))!=0)
	{
		VMSHORT tmp= val;
		result= filesys.write(filename,&tmp,sizeof(tmp));
	}

	return result;
}

bool FUNCFILEWRITEFOURBYTES::execute(void)
{
	bool result= false;

	VMREGTYPE pfilename= 0;
	VMREGTYPE val= 0;
	const char* filename= "null";

	if(machine.pop(pfilename)
		&& machine.pop(val)
		&& (filename=machine.GetString((VPVOID)pfilename))!=0)
	{
		result= filesys.write(filename,&val,sizeof(val));
	}

	return result;
}

bool FUNCFILEWRITESTRING::execute(void)
{
	bool result= false;

	VMREGTYPE pfilename= 0;
	VMREGTYPE pstr= 0;
	const char* filename= "null";
	const char* str= "null";

	if(machine.pop(pfilename)
		&& machine.pop(pstr)
		&& (filename=machine.GetString((VPVOID)pfilename))!=0
		&& (str=machine.GetString((VPVOID)pstr))!=0)
	{
		result= filesys.write(filename,str,strlen(str)+1);
	}

	return result;
}

// 2005-07-10  CDC  Separate the new formated string writing into their own separate functions

// 2005-06-28  CDC  Not ideal, but this lets you read the formatted text back in from the file
bool FUNCFILEREADTEXT::execute(void)
{
	bool result= false;
	VMREGTYPE pfilename= 0;
	const char* filename= "null";
	const char* stored= "null";
	VMREGTYPE pFormat = 0;
	const char* format;
	bool eolmode = false;
	int resultmax;

	if ( machine.pop(pfilename) 
		&& ( ( filename=machine.GetString((VPVOID)pfilename) ) !=0 )
		&& machine.pop(pFormat)
		&& ( ( format=machine.GetString((VPVOID)pFormat) ) !=0 ) )
	{
		// Count how many results there should be based on the format string
		enumerate(format, resultmax, eolmode);
		resultmax++;	// there's always a status count

		VMREGTYPE* resultset=new VMREGTYPE[resultmax];	// Store results so we can push them on in reverse
		char stringbuf[BUFSIZ*4+1];	// May be enough, but could be larger.  Matches Write size.
		char *string = stringbuf;
		string[BUFSIZ*4] = 0;
		if ( eolmode )
			resultset[0] = (VMREGTYPE)filesys.readcstring(filename,string,-(BUFSIZ*4));
		else
			resultset[0] = (VMREGTYPE)filesys.readcstring(filename,string,BUFSIZ*4);

		if ( resultset[0] )
			secernate(format, string, resultset, resultmax);

		while ( resultmax-- )
			result= machine.push((VMREGTYPE)resultset[resultmax]);
	}
	return result;
}

// 2005-06-28  CDC   Formatted writes (but doesn't return anything now (07-12)
bool FUNCFILEWRITETEXT::execute(void)
{
	bool result = false;
	VMREGTYPE pfilename = 0;
	VMREGTYPE pstr = 0;
	char const* filename = "null";
	char const* str = "null";
	if (machine.pop(pfilename)
		&& machine.pop(pstr)
		&& (filename = machine.GetString((VPVOID)pfilename)) != 0
		&& (str = machine.GetString((VPVOID)pstr)) != 0) {
		std::string new_string;
		bool suppress_null = interpolate(machine, str, new_string) < 0;
		int len = new_string.length() + 1;
		if (suppress_null) --len;
		if (filesys.write(filename, new_string.c_str(), len)) result = true;
	}
	return result;
}
