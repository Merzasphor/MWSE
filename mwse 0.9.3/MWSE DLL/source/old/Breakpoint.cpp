#include "Breakpoint.h"
#include "log.h"

static void* Overwritten;
static Context context;

struct BreakpointData {
	DWORD addr;
	DWORD len;
	BYTE* overwritten;
	BreakpointFunc* func;
	bool active;

	BreakpointData(DWORD _addr, DWORD _len, const BYTE* _overwritten) {
		addr=_addr;
		len=_len;
		overwritten=new BYTE[len+7];
		CopyMemory(overwritten, _overwritten, len);
		overwritten[len+0]=0xff;
		overwritten[len+1]=0x35;
		*(DWORD*)&overwritten[len+2]=(DWORD)&context.eip;
		overwritten[len+6]=0xc3;

		func=0;
		active=false;
	}
};

static const BYTE BP0[9]  = { 0x51, 0x53, 0x8b, 0xd9, 0xb9, 0x78, 0xb4, 0x7c, 0x00 };
static const BYTE BP1[8]  = { 0x55, 0x8b, 0xec, 0x83, 0xe4, 0xf8, 0x6a, 0xff };
static const BYTE BP2[10] = { 0x33, 0xf6, 0x83, 0xc5, 0x02, 0x3d, 0x26, 0x01, 0x00, 0x00 };
static const BYTE BP3[8]  = { 0x8b, 0x44, 0x24, 0x2c, 0x83, 0xc0, 0x10, 0x50 };
static const BYTE BP4[10] = { 0x8b, 0xd0, 0x3b, 0xd5, 0x0f, 0x85, 0x52, 0x04, 0x00, 0x00 };
static const BYTE BP5[8]  = { 0x8b, 0x50, 0x14, 0xe9, 0x84, 0x05, 0x00, 0x00 };
static const BYTE BP6[7]  = { 0x8b, 0xd0, 0xe9, 0x6b, 0x05, 0x00, 0x00 };

static BreakpointData Breakpoints[] = {
	BreakpointData(0x4fdb00, 9, BP0),
	BreakpointData(0x5028a0, 8, BP1),
	BreakpointData(0x500540, 10, BP2),
	BreakpointData(0x50d5d6, 8, BP3),
	BreakpointData(0x4fe195, 10, BP4),
	BreakpointData(0x4fe065, 8, BP5),
	BreakpointData(0x4fe07f, 7, BP6)
};

static DWORD _stdcall InterruptExtern2(DWORD ID) {
	Overwritten = Breakpoints[ID].overwritten;
	
	DWORD d=context.eip;
	Breakpoints[ID].func(&context);
	return (context.eip==d)?0:1;
}

static __declspec(naked) void InterruptExtern() {
	_asm {
		//Save state
		mov context.eax, eax
		pushfd
		pop eax
		mov context.flags, eax
		mov context.ebx, ebx
		mov context.ecx, ecx
		mov context.edx, edx
		mov context.edi, edi
		mov context.esi, esi
		mov context.ebp, ebp
		pop eax
		mov context.eip, eax
		pop eax
		mov context.esp, esp
		push eax

		//Carry out the interrupt
		call InterruptExtern2

		//restore state apart from the eax register and the flags
		mov ebx, context.ebx
		mov ecx, context.ecx
		mov edx, context.edx
		mov edi, context.edi
		mov esi, context.esi
		mov ebp, context.ebp
		mov esp, context.esp

		//check result
		test eax, eax
		jz Continue

		//Jump to some other point in morrowind's code
		mov eax, context.eax
		push context.flags
		popfd
		push context.eip
		ret
Continue:
		//continue execution where it left off
		mov eax, context.eax
		push context.flags
		popfd
		jmp Overwritten
	}
}

//Not enough room to inject code for these, so move the injection site back a little and add the displaced code here
//Since one of the instructions was a relative jump, also need to replace it with an absolute jump here
static const DWORD InterruptEnd = 0x004fe5f1;
static __declspec(naked) void Interrupt5() {
	_asm {
		mov edx, [eax+0x14]
		_emit 0x6a
		_emit 0x06
		call InterruptExtern
		jmp InterruptEnd
	}
}

static __declspec(naked) void Interrupt6() {
	_asm {
		mov edx, eax
		_emit 0x6a
		_emit 0x07
		call InterruptExtern
		jmp InterruptEnd
	}
}

static const DWORD InterruptExternAddr = (DWORD)&InterruptExtern;
static const DWORD Interrupt5Addr = (DWORD)&Interrupt5;
static const DWORD Interrupt6Addr = (DWORD)&Interrupt6;

void AddBreakpoint(BYTE ID, BreakpointFunc func) {
	if(ID>6) return;
	if(Breakpoints[ID].active) return;

	//LOG::log("Setting breakpoint ID %d\n", ID);

	Breakpoints[ID].func=func;
	DWORD OldProtect;
	VirtualProtect((DWORD*)Breakpoints[ID].addr, Breakpoints[ID].len, PAGE_READWRITE, &OldProtect);
	BYTE* data = (BYTE*)Breakpoints[ID].addr;
	//Not enough room at the injection site for these two, so they need special treatment
	if(ID==5||ID==6) {
		data[0]=0xff; //jmp Interrupt5/6
		data[1]=0x25;
		if(ID==5) *(DWORD*)&data[2]=(DWORD)&Interrupt5Addr;
		else *(DWORD*)&data[2]=(DWORD)&Interrupt6Addr;
		for(DWORD i=6;i<Breakpoints[ID].len;i++) data[i]=0x90;
	} else {
		data[0]=0x6a; //push one immediate byte to stack
		data[1]=ID;
		data[2]=0xff; //call InterruptExtern
		data[3]=0x15;
		*(DWORD*)&data[4]=(DWORD)&InterruptExternAddr;
		for(DWORD i=8;i<Breakpoints[ID].len;i++) data[i]=0x90;
	}
	VirtualProtect((DWORD*)Breakpoints[ID].addr, Breakpoints[ID].len, OldProtect, &OldProtect);
}

void RemoveBreakpoint(BYTE ID) {
	if(ID>6) return;
	if(!Breakpoints[ID].active) return;

	//LOG::log("Removing breakpoint ID %d\n", ID);

	DWORD OldProtect;
	const BYTE* source;
	switch(ID) {
		case 0: source=(BYTE*)&BP0; break;
		case 1: source=(BYTE*)&BP1; break;
		case 2: source=(BYTE*)&BP2; break;
		case 3: source=(BYTE*)&BP3; break;
		case 4: source=(BYTE*)&BP4; break;
		case 5: source=(BYTE*)&BP5; break;
		case 6: source=(BYTE*)&BP6; break;
	}
	VirtualProtect((DWORD*)Breakpoints[ID].addr, Breakpoints[ID].len, PAGE_READWRITE, &OldProtect);
	CopyMemory((DWORD*)Breakpoints[ID].addr, source, Breakpoints[ID].len);
	VirtualProtect((DWORD*)Breakpoints[ID].addr, Breakpoints[ID].len, OldProtect, &OldProtect);
}