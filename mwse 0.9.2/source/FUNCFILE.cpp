
#include "FUNCFILE.h"
#include <stdio.h>
#include "DEBUGGING.h"
#include "FUNCTEXT.h"
// 22-08-2006 Tp21
#include "warnings.h"


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

#ifdef DEBUGGING
	LOG::log("%d = FUNCFILEREADTWOBYTES(%s,%d) %s\n",numshorts,filename,stackparams.numshorts,result?"succeeded":"failed");
	if(datain)
	{
		for(int i=0;i<numshorts;i++)
			LOG::log("\t%d\n",(int)datain[i]);
	}
#endif
	if(datain)
		delete []datain;
		
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
#ifdef DEBUGGING
	LOG::log("%d = FUNCFILEREADFOURBYTES(%s,%d) %s\n",count,filename,stackparams.numunits,result?"succeeded":"failed");
	if(data)
	{
		for(int i=1;i<count+1;i++)
			LOG::log("\t%d\n",(int)data[i]);
	}
#endif
	if(data)
		delete []data;
		
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

#ifdef DEBUGGING
	LOG::log("FUNCFILEREWIND(%s) %s\n",filename,result?"succeeded":"failed");
#endif

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
#ifdef DEBUGGING
	LOG::log("FUNCFILESEEK(%s,%d) %s\n",filename,offset,result?"succeeded":"failed");
#endif

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
#ifdef DEBUGGING
	LOG::log("%s = FUNCFILEREADSTRING(%s) %s\n",stored,filename,result?"succeeded":"failed");
#endif

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

#ifdef DEBUGGING
	LOG::log("FUNCFILEWRITETWOBYTES(%s,%x) %s\n",filename,val,result?"succeeded":"failed");
#endif

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

#ifdef DEBUGGING
	LOG::log("FUNCFILEWRITEFOURBYTES(%s,%x) %s\n",filename,val,result?"succeeded":"failed");
#endif

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

#ifdef DEBUGGING
	LOG::log("FUNCFILESTRING(%s,%x,%d) %s\n",filename,str,result,result?"succeeded":"failed");
#endif

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
#ifdef DEBUGGING
	LOG::log("%s = FUNCFILEREADTEXT(%s) %s\n",stored,filename,result?"succeeded":"failed");
#endif
	return result;
}

// 2005-06-28  CDC   Formatted writes (but doesn't return anything now (07-12)
bool FUNCFILEWRITETEXT::execute(void)
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
		char buffer[BUFSIZ*4+1];	// Matches how much can be read, but is it long enough?
		int len = BUFSIZ*4;
		int substitutions = interpolate(machine, str, buffer, len);
		if ( buffer[0] )
			str = buffer;
		len = strlen(str) + 1;
		if ( substitutions < 0 )	// want to skip printing the null!
			len = len - 1;
		if ( filesys.write(filename,str,len) )
			result = true;
	}
#ifdef DEBUGGING
	LOG::log("FUNCFILETEXT(%s,%x,%d) %s\n",filename,str,result,result?"succeeded":"failed");
#endif
	return result;
}
