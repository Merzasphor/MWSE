//Timeslip (2005/08/04): Undefine min when std:min is being used

#include "TES3MACHINE.h"
#include "TES3MEMMAP.h"
#include "BUFSPACE.h"
#include "PROCESSMEM.h"
#include "DEBUGGING.h"
#include "LOG.h"

#include <algorithm>

#include "TES3OPCODES.h"

#include "INSTCALL.h"
#include "INSTCOPY.h"
#include "INSTFLOAT.h"
#include "INSTINT.h"
#include "INSTJUMP.h"
#include "INSTNOP.h"
#include "INSTPOP.h"
#include "INSTPUSH.h"
#include "FUNCVARIABLES.h"
#include "FUNCAI.h"
#include "FUNCPOSITION.h"
#include "FUNCREFERENCE.h"
#ifdef CDC
// 2005-02-14  CDC
#include "FUNCPROPERTIES.h"
// 2005-06-27  CDC
#include "FUNCTEXT.h"
#endif
#include "FUNCLOG.h"
#include "FUNCFILE.h"
#include "FUNCINVENTORY.h"
#include "FUNCEXTENDER.h"

#ifdef DEBUG
#include <stdio.h>
#ifndef NELEMS
#define NELEMS(a) (sizeof(a)/sizeof(a[0]))
#endif
#endif
// 22-08-2006 Tp21
#include "warnings.h"

#define PLACEHOLDER 0

#define SUPER VIRTUALMACHINE

TES3MACHINE::TES3MACHINE(HANDLE process, LPVOID base)
:	SUPER()
	,hProcess(process)
	,procbase(base)
	,scriptaddr(0)
	,script()
	,flow()
	,breakpoint(0)
	,instructionpointer(0)
	,stackpointer(0)
	,executable(new BUFSPACE(SCRIPTMEM_SIZE))
{
	if(!AddAddressSpace(SCRIPTMEM_VPOS,executable))
		LOG::log("TES3MACHINE: AddAddressSpace SCRIPTMEM failed\n");
	if(!AddAddressSpace(STACKMEM_VPOS, new BUFSPACE(STACKMEM_SIZE)))
		LOG::log("TES3MACHINE: AddAddressSpace STACKMEM failed\n");
#ifdef DEBUG
	{
		FILE* fin= fopen("bootscript.scdt","rb");
		if(fin)
		{
			BYTE buf[512]= {NULL};
			VPVOID pos= 0;
			int read= 0;
			while((read= fread(buf,sizeof(BYTE),NELEMS(buf),fin))>0)
			{
				executable->Write(pos,&buf,read);
				pos+= read;
			}	
			fclose(fin);
		}
	}
#else	
	if(!AddAddressSpace(GENERALMEM_VPOS,
		new PROCESSMEM(process,GENERALMEM_VPOS,GENERALMEM_SIZE)))
		LOG::log("TES3MACHINE: AddAddressSpace GENERALMEM failed\n");
#endif

	AddInstruction(CALL,new INSTCALL(*this));
	AddInstruction(CALLSHORT,new INSTCALLSHORT(*this));
	AddInstruction(RETURN,new INSTRETURN(*this));
	AddInstruction(RETURNP,new INSTRETURNP(*this));
	AddInstruction(RETURNVP,new INSTRETURNVP(*this));

	AddInstruction(COPYREG,new INSTCOPYREG(*this));
	AddInstruction(COPYFROMSTACK,new INSTCOPYFROMSTACK(*this));
	AddInstruction(COPYTOSTACK,new INSTCOPYTOSTACK(*this));

	AddInstruction(JUMP,new INSTJUMP(*this));
	AddInstruction(JUMPSHORT,new INSTJUMPSHORT(*this));
	AddInstruction(JUMPZERO,new INSTJUMPZERO(*this));
	AddInstruction(JUMPSHORTZERO,new INSTJUMPSHORTZERO(*this));
	AddInstruction(JUMPNOTZERO,new INSTJUMPNOTZERO(*this));
	AddInstruction(JUMPSHORTNOTZERO,new INSTJUMPSHORTNOTZERO(*this));
	AddInstruction(JUMPPOSITIVE,new INSTJUMPPOSITIVE(*this));
	AddInstruction(JUMPSHORTPOSITIVE,new INSTJUMPSHORTPOSITIVE(*this));
	AddInstruction(JUMPNEGATIVE,new INSTJUMPNEGATIVE(*this));
	AddInstruction(JUMPSHORTNEGATIVE,new INSTJUMPSHORTNEGATIVE(*this));

	AddInstruction(POP,new INSTPOP(*this));
	AddInstruction(POPREG,new INSTPOPREG(*this));

	AddInstruction(PUSH,new INSTPUSH(*this));
	AddInstruction(PUSHB,new INSTPUSHB(*this));
	AddInstruction(PUSHS,new INSTPUSHS(*this));
	AddInstruction(PUSHREG,new INSTPUSHREG(*this));
	AddInstruction(DECLARELOCAL,new INSTDECLARELOCAL(*this));

	AddInstruction(ADD,new INSTADD(*this));
	AddInstruction(SUB,new INSTSUB(*this));
	AddInstruction(MUL,new INSTMUL(*this));
	AddInstruction(DIV,new INSTDIV(*this));
	AddInstruction(MOD,new INSTMOD(*this));

	AddInstruction(ITOF,new INSTITOF(*this));
	AddInstruction(FTOI,new INSTFTOI(*this));
	AddInstruction(FADD,new INSTFADD(*this));
	AddInstruction(FSUB,new INSTFSUB(*this));
	AddInstruction(FMUL,new INSTFMUL(*this));
	AddInstruction(FDIV,new INSTFDIV(*this));

	AddInstruction(TAN,new INSTTAN(*this));
	AddInstruction(SIN,new INSTSIN(*this));
	AddInstruction(COS,new INSTCOS(*this));
	AddInstruction(ARCTAN,new INSTARCTAN(*this));
	AddInstruction(ARCSIN,new INSTARCSIN(*this));
	AddInstruction(ARCCOS,new INSTARCCOS(*this));
	AddInstruction(DEGRAD,new INSTDEGRAD(*this));
	AddInstruction(RADDEG,new INSTRADDEG(*this));
	AddInstruction(SQRT,new INSTSQRT(*this));
	AddInstruction(HYPOT,new INSTHYPOT(*this));


	AddInstruction(GETLOCAL,new FUNCGETLOCAL(*this));
	AddInstruction(GETFOREIGN,new FUNCGETLOCAL(*this));
	AddInstruction(SETLOCAL,new FUNCSETLOCAL(*this));
	AddInstruction(SETFOREIGN,new FUNCSETLOCAL(*this));
	
	AddInstruction(AITRAVEL,new FUNCAITRAVEL(*this));
	AddInstruction(POSITION,new FUNCPOSITION(*this));
	
	AddInstruction(REFPCTARGET,new FUNCREFPCTARGET(*this));
	AddInstruction(GETPCTARGET,new FUNCGETPCTARGET(*this));
	AddInstruction(REFTYPE,new FUNCREFTYPE(*this));
	
	AddInstruction(LOGMSG,new FUNCLOG(*this));
	
	AddInstruction(FILEREWIND,new FUNCFILEREWIND(*this));
	AddInstruction(FILEREADSHORT,new FUNCFILEREADTWOBYTES(*this));
	AddInstruction(FILEREADLONG, new FUNCFILEREADFOURBYTES(*this));
	AddInstruction(FILEREADFLOAT, new FUNCFILEREADFOURBYTES(*this));
	AddInstruction(FILEREADSTRING, new FUNCFILEREADSTRING(*this));
	AddInstruction(FILESEEK, new FUNCFILESEEK(*this));

	AddInstruction(SETREF,new FUNCREF(*this));
	AddInstruction(FIRSTNPC,new FUNCFIRSTNPC(*this));
	AddInstruction(NEXTREF,new FUNCNEXTREF(*this));
	AddInstruction(REFID,new FUNCREFID(*this));
	AddInstruction(GETREF,new FUNCGETREF(*this));
	AddInstruction(FIRSTITEM,new FUNCFIRSTITEM(*this));
	AddInstruction(FIRSTSTATIC,new FUNCFIRSTSTATIC(*this));
	
	AddInstruction(GETCOMBAT,new FUNCGETCOMBAT(*this));
	AddInstruction(STARTCOMBAT,new FUNCSTARTCOMBAT(*this));
	AddInstruction(DISTANCE,new FUNCDISTANCE(*this));

	AddInstruction(ADDITEM,new FUNCADDITEM(*this));
	AddInstruction(REMOVEITEM,new FUNCREMOVEITEM(*this));
	AddInstruction(INVENTORY,new FUNCINVENTORY(*this));
	AddInstruction(NEXTSTACK,new FUNCNEXTSTACK(*this));
	AddInstruction(POSITIONCELL,new FUNCPOSITIONCELL(*this));
	AddInstruction(PCCELLID,new FUNCPCCELLID(*this));
	
	AddInstruction(PLACE, new FUNCPLACEAT(*this));
	AddInstruction(STRCMP, new FUNCSTRCMP(*this));
	AddInstruction(HASEQUIPED, new FUNCHASEQUIPED(*this));

	AddInstruction(FILEWRITESHORT,new FUNCFILEWRITETWOBYTES(*this));
	AddInstruction(FILEWRITELONG, new FUNCFILEWRITEFOURBYTES(*this));
	AddInstruction(FILEWRITEFLOAT, new FUNCFILEWRITEFOURBYTES(*this));
	AddInstruction(FILEWRITESTRING, new FUNCFILEWRITESTRING(*this));

#ifdef CDC
	// 2005-02-14  CDC
	AddInstruction(GETVALUE, new FUNCGETVALUE(*this));
	AddInstruction(GETOWNER, new FUNCGETOWNER(*this));
	AddInstruction(GETWEIGHT, new FUNCGETWEIGHT(*this));
	AddInstruction(GETENCUMB, new FUNCGETENCUMB(*this));
	AddInstruction(GETMAXCOND, new FUNCGETMAXCOND(*this));
	AddInstruction(GETCONDITION, new FUNCGETCONDITION(*this));
	AddInstruction(GETMAXCHARGE, new FUNCGETMAXCHARGE(*this));
	AddInstruction(GETCHARGE, new FUNCGETCHARGE(*this));
	AddInstruction(GETQUALITY, new FUNCGETQUALITY(*this));

	AddInstruction(GETNAME, new FUNCGETNAME(*this));
	AddInstruction(GETBASEID, new FUNCGETBASEID(*this));

	AddInstruction(GETBASESTR, new FUNCGETBASESTR(*this));
	AddInstruction(GETBASEINT, new FUNCGETBASEINT(*this));
	AddInstruction(GETBASEWIL, new FUNCGETBASEWIL(*this));
	AddInstruction(GETBASEAGI, new FUNCGETBASEAGI(*this));
	AddInstruction(GETBASESPE, new FUNCGETBASESPE(*this));
	AddInstruction(GETBASEEND, new FUNCGETBASEEND(*this));
	AddInstruction(GETBASEPER, new FUNCGETBASEPER(*this));
	AddInstruction(GETBASELUC, new FUNCGETBASELUC(*this));

	AddInstruction(ISFEMALE, new FUNCISFEMALE(*this));
	AddInstruction(MYCELLID, new FUNCMYCELLID(*this));

	AddInstruction(GETBASEGOLD, new FUNCGETBASEGOLD(*this));
	AddInstruction(GETGOLD, new FUNCGETGOLD(*this));

	AddInstruction(SETBASEGOLD, new FUNCSETBASEGOLD(*this));
	AddInstruction(SETGOLD, new FUNCSETGOLD(*this));

	AddInstruction(ISTRADER, new FUNCISTRADER(*this));
	AddInstruction(ISTRAINER, new FUNCISTRAINER(*this));
	AddInstruction(ISPROVIDER, new FUNCISPROVIDER(*this));

	AddInstruction(MESSAGEFIX, new FUNCMESSAGEFIX(*this));


	// 2005-07-10  CDC  0.9.2 functions
	AddInstruction(KEYPRESSED, new FUNCKEYPRESSED(*this));	
	AddInstruction(TEXTINPUT, new FUNCTEXTINPUT(*this));
	AddInstruction(TEXTINPUTALT, new FUNCTEXTINPUTALT(*this));
	AddInstruction(CONTENTLIST, new FUNCCONTENTLIST(*this));

	AddInstruction(GETSERVICE, new FUNCGETSERVICE(*this));
	AddInstruction(SETSERVICE, new FUNCSETSERVICE(*this));
	AddInstruction(MODSERVICE, new FUNCMODSERVICE(*this));

	AddInstruction(FILEREADTEXT, new FUNCFILEREADTEXT(*this));
	AddInstruction(FILEWRITETEXT, new FUNCFILEWRITETEXT(*this));
	AddInstruction(STRINGLENGTH, new FUNCSTRINGLENGTH(*this));
	AddInstruction(STRINGBUILD, new FUNCSTRINGBUILD(*this));
	AddInstruction(STRINGPARSE, new FUNCSTRINGPARSE(*this));

	AddInstruction(MEMLOOK, new FUNCMEMLOOK(*this));

	//Fliggerty 12-27-06
	AddInstruction(ADDSPELL, new FUNCADDSPELL(*this));

	//Tp21 22-08-2006
	AddInstruction(DROPITEM, new FUNCDROPITEM(*this));
	AddInstruction(EQUIPITEM, new FUNCEQUIPITEM(*this));
	AddInstruction(SETNAME, new FUNCSETNAME(*this));
	AddInstruction(GETSPELLEFFECTS, new FUNCGETSPELLEFFECTS(*this));
	AddInstruction(CAST, new FUNCCAST(*this));
#endif
}

bool TES3MACHINE::GetRegister(WORD regidx, VMREGTYPE& value)
{
	bool result= true;
	
	switch(regidx)
	{
	case IP:
		value= instructionpointer;
		result= true;
		break;
	case SP:
		value= stackpointer;
		break;
	default:
		if(regidx<=GPMAX)
			value= generalregs[regidx-GP];
		else
			result= false;
	}
	
	return result;
}

bool TES3MACHINE::SetRegister(WORD regidx, VMREGTYPE value)
{
	bool result= true;
	
	switch(regidx)
	{
	case IP:
		instructionpointer= value;
		result= true;
		break;
	case SP:
		if(value && value<STACKMEM_MIN) // || value>STACKMEM_MAX) // how do I test the upper limit?
			result= false;
		else
			stackpointer= value;
		break;
	default:
		if(regidx<=GPMAX)
		{
			SetFlags(value);
			generalregs[regidx-GP]= value;
		}
		else
			result= false;
	}
	
	return result;
}

bool TES3MACHINE::SetScript(VPSCRIPT pscript)
{
	scriptaddr=	pscript;
	return ReadMem((VPVOID)pscript,&script,sizeof(script));
}

bool TES3MACHINE::Interrupt(VMINTERRUPT num)
{
	bool result= false;
	if(num==INTSWITCHREFERENCE)
	{
		BYTE buf[512];
		VMSIZE read= 0;
		VMSIZE offset= 0;
		result= true;

//having min define for the next line hurts
#ifdef MSVC
#undef min
		while(result && (read=std::min((VMSIZE)sizeof(buf),script.scdtlength-offset))>0)
#define min(a,b) (((a) < (b)) ? (a) : (b))
#else
		while(result && (read=std::min((VMSIZE)sizeof(buf),script.scdtlength-offset))>0)
#endif
		{
			result= (ReadMem(script.scdt+offset,buf,read)
				&& WriteMem((VPVOID)SCRIPTMEM_VPOS+offset,buf,read));
			offset+= read;
		}
		strings.clear();
		SetRegister(SP,0);
	}
		
	return result;
}

const CONTEXT& TES3MACHINE::GetFlow(void)
{
	return flow;
}

void TES3MACHINE::SetFlow(const CONTEXT& newflow)
{
	this->flow= newflow;
}

bool TES3MACHINE::SetVMDebuggerBreakpoint(HWBREAKPOINT* breakpoint)
{
	if(this->breakpoint && breakpoint)
		return false;
	this->breakpoint= breakpoint;
	return true;
}

HWBREAKPOINT* TES3MACHINE::GetVMDebuggerBreakpoint()
{
	return breakpoint;
}

const char* TES3MACHINE::GetScriptName(void)
{
	const char* result= NULL;
	if(scriptaddr)
		result= (const char*)script.name;
		
	return result;
}

const char* TES3MACHINE::GetString(VPVOID addr)
{
	const char* result= 0;
	VMBYTE blen= 0;
	
//	LOG::log("TES3MACHINE::GetString(%lx)\n",addr);
	if(addr && (LPVOID)addr<(LPVOID)32767)
	{
		if(ReadMem(addr,&blen,sizeof(blen)))
		{
			char* string= new char[blen+4];
			if(ReadMem(addr+sizeof(blen),string,blen))
			{
				string[blen]= '\0';
				result= strings.add(string);
			}
			delete []string;
		}
	}
	else
		result= (const char*)addr;
		
//	const char* printable= result;
//	if(!printable)
//		printable= "null";
		
//	LOG::log("%s= TES3MACHINE::GetString(%lx)\n",printable,addr);
	return result;
}


bool TES3MACHINE::dumpmem(VPVOID ptr, int size)
{
	bool result= false;
	BYTE* buf= new BYTE[size];
	if(ReadMem(ptr,buf,size))
	{
		LOG::logbinary(buf,size);
		result= true;
	}
	else
		LOG::log("dumpmem: ReadMem failed");
	delete[] buf;
	return result;
}

void TES3MACHINE::dumpscriptstack(void)
{
	VMREGTYPE sp= 0;
	if(GetRegister(SP,sp))
	{
		LOG::log("script sp %lx\n",sp);
		int size= 0-sp;
		dumpmem((VPVOID)sp,size<64?size:64);
	}
	else
		LOG::log("dumpscriptstack: GetRegister failed");
}

void TES3MACHINE::dumpscript(void)
{
	LOG::log("Stack at %lx\n",scriptaddr);
	LOG::logbinary((LPVOID)&script,sizeof(script));
	LOG::log("SCDT\n");
	dumpmem(script.scdt,script.scdtlength);
}

void TES3MACHINE::dumptemplate(VPTEMPLATE ptempl)
{
	TES3TEMPLATE templ;
	char buf[256];
	if(ReadMem((VPVOID)ptempl,(void*)&templ,sizeof(TES3TEMPLATE)))
	{
		LOG::log("Template from %lx\n",ptempl);
		LOG::logbinary((void*)&templ,sizeof(TES3TEMPLATE));
		if(ReadMem((VPVOID)templ.objectid,buf,32))
		{
			LOG::log("ObjectID from %lx\n",templ.objectid);
			LOG::logbinary(buf,32);
		}
		else
			LOG::log("dumpobject: ObjectID failed\n");
	}
	else
		LOG::log("dumpobject: Template failed\n");
}

void TES3MACHINE::dumpobject(VPREFERENCE pref)
{
#ifdef CDC
	// 2005-02-05  CDC     2005-07-06  0 is an address, non-digits quit now
	// Allows for interactive exploration of memory - not pretty, but works
	// You'll need a fairly wide screen and should start the extender from
	// a CygWin shell window for best effect.
	// The MEMLOOK function will trigger this code which breaks out of the
	// program and dumps the REFR data for the current object.
	// Warning: Memory addresses in the listing are in little-endian order
	// but those listed on the first line aren't.
	// You can type a memory address (in hex) to dump a section of memory
	// starting at that address or a letter (other than a through f and
	// A through F) to return to the game.  If you type a small hex number 
	// the value will be used like an array subscript to pick a memory 
	// address from the currently shown data treating the data as an array 
	// of long values.  Some interesting values include:
	//   From the REFR data:
	//      0A  the template for the current object
	//      11  the attachments for the current object
	//      05  a cell link field (from there 03 takes you to the cell template)
	//   From the template data area:
	//	0B  the objectid for this object
	//	1B  a second template I call the base template
	//   For NPC_ type template or base template data:
	//	14  the character's real name
	//	2C  the character's race
	//	2D  the character's class
	//	2E  the character's head
	//	2F  the character's hair
	//   For the attachment list, the first item is a type code
	//	01  is the next attachment list item
	//	02  is the data for that attachment
	//   For attachement type 6, the first field (00) is a count.
	//	01  is the owner
	//	05  is the script
	//   Attachement type 8 is long and has lot's of interesting data
	unsigned long addr = (unsigned long) pref;
        unsigned x, y, size;
	BYTE buffer[1024];
	BYTE* ptr= buffer;
	char buf[1024];

	size = sizeof(TES3REFERENCE);
	printf("Script %lx %lx: Reference from ",scriptaddr,script);
	do {
        if ( addr <= 0x40 ) 
		addr = *((unsigned long *)(ptr+addr*4));
	printf("%lX - %lX\n", addr, addr+size);
	if(!ReadMem((VPVOID)addr,(void*)&buffer,size))
		return;
	for(y=0;y<size;y+=32)
	{
		for(x=0;x<32 && (x+y)<size;x++) {
			printf("%02X",((int)ptr[y+x])&0xFF);
			if ( x == 3 || x == 11 || x == 19 || x == 27 )
				printf(" ");
			if ( x == 7 || x == 23 )
				printf("  ");
			if ( x == 15 )
				printf(" | ");
		}
		printf(" ");
		for(x=0;x<32 && (x+y)<size;x++) {
			if(isprint(ptr[y+x]))
				printf("%c",ptr[y+x]);
			else
				printf(".");
			if ( x == 3 || x == 11 || x == 19 || x == 27 )
				printf(" ");
			if ( x == 7 || x == 23 )
				printf("  ");
			if ( x == 15 )
				printf(" | ");
		}
#if 0
		printf("\n");
		for(x=0;x<32 && (x+y)<size;x+=4) {
			printf("%4.2f ",*((float*)(ptr+y+x)));
			if ( x == 7 || x == 23 )
				printf(" ");
			if ( x == 15 )
				printf(" | ");
		}

		printf("  ");
		for(x=0;x<32 && (x+y)<size;x+=4) {
			printf("%ld ",*((unsigned long*)(ptr+y+x)));
			if ( x == 7 || x == 23 )
				printf(" ");
			if ( x == 15 )
				printf(" | ");
		}
#endif
		printf("\n");
	}
	fflush(stdout);
	size = 256;
	scanf("%1020s", buf);
	sscanf(buf,"%lx", &addr);
	} while ( (buf[0]>='0' && buf[0]<='9') || (buf[0]>='a' && buf[0]<='f') || ( buf[0]>= 'A'&& buf[0]<='F') );
	

#else
	TES3REFERENCE ref;
	if(ReadMem((VPVOID)pref,(void*)&ref,sizeof(TES3REFERENCE)))
	{
		LOG::log("Reference from %lx\n",pref);
		LOG::logbinary((void*)&ref,sizeof(TES3REFERENCE));
		dumptemplate(ref.templ);
	}
	else
		LOG::log("dumpobject: Reference failed\n");
#endif
}

void TES3MACHINE::dumpobjects(void)
{
	const CONTEXT& context= GetFlow();
	VPVOID master2= 0;
	VPVOID target= 0;
	VPVOID pvariables= 0;
	TES3VARIABLES variables;
	
	LOG::log("Stack from %lx\n",context.Esp);
	if(!dumpmem((VPVOID)context.Esp,64))
		LOG::log("dump: Stack failed\n");
		
	LOG::log("Base from %lx\n",context.Ebp);
	if(!dumpmem((VPVOID)context.Ebp,64))
		LOG::log("dump: Stack failed\n");

	LOG::log("View Target:\n");
	if(ReadMem((VPVOID)reltolinear(MASTER2_IMAGE),&master2,sizeof(master2)))
	{
		LOG::log("master2= %lx\n",master2);
		if(ReadMem(master2+0x4c+0x9c,&target,sizeof(target)))
			dumpobject((VPREFERENCE)target);
		else
			LOG::log("dump: target failed\n");
	}
	else
		LOG::log("dump: ViewData failed\n");

	LOG::log("Script Local Variables\n");
	dumpobject((VPREFERENCE)context.Ecx);
	
	if(ReadMem((VPVOID)reltolinear(LOCALVARIABLES_IMAGE),&pvariables,sizeof(pvariables))
		&& ReadMem(pvariables,&variables,sizeof(variables)))
	{
		LOG::log("LOCALVARIABLES from %lx\n",pvariables);
		LOG::logbinary(&variables,sizeof(variables));
	}
	else
		LOG::log("dump: LOCALVARIABLES failed\n");
		
	LOG::log("script at %lx\n",scriptaddr);
	LOG::logbinary((LPVOID)&script,sizeof(script));
}

void TES3MACHINE::searchforscripttarget(void)
{
	const CONTEXT& context= GetFlow();
	DWORD scripttarget= context.Ecx;
	LOG::log("Searching for script target %lx\n",scripttarget);

	for(VPVOID pagestart= (VPVOID)0;pagestart<(VPVOID)0x80000000;pagestart+= 0x1000)
	{
		BYTE buf[0x1000];
		if(ReadMem(pagestart,buf,sizeof(buf)))
		{
			for(int i=0;i<= sizeof(buf)-sizeof(DWORD);i++)
			{
				DWORD val= *(DWORD*)&buf[i];
				if(val==scripttarget)
					LOG::log("found scripttarget pointer %lx at %lx\n",val,pagestart+i);
			}
		}
	}
}
