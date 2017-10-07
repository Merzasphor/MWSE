#include "ProcessMem.h"

#define ReadMemory(a,b,c) CopyMemory(b,a,c)
#define WriteMemory CopyMemory

/*inline float ReadFloat(DWORD addr) { return *reinterpret_cast<float*>(addr); }
inline BYTE ReadByte(DWORD addr)   { return *reinterpret_cast<BYTE*>(addr);  }
inline WORD ReadShort(DWORD addr)  { return *reinterpret_cast<WORD*>(addr);  }
inline DWORD ReadInt(DWORD addr)   { return *reinterpret_cast<DWORD*>(addr); }

inline void WriteFloat(DWORD addr, float data) { *reinterpret_cast<float*>(addr)=data; }
inline void WriteByte(DWORD addr, BYTE data)   { *reinterpret_cast<BYTE*>(addr)=data;  }
inline void WriteShort(DWORD addr, WORD data)  { *reinterpret_cast<WORD*>(addr)=data;  }
inline void WriteInt(DWORD addr, DWORD data)   { *reinterpret_cast<DWORD*>(addr)=data; }*/

PROCESSMEM::PROCESSMEM(PVOID base, VMSIZE size) : baseptr(base), memsize(size)
{
}

bool PROCESSMEM::Read(VPVOID addr, VOID* buf, VMSIZE size)
{
	void* modaddr=(void*)((DWORD)addr+(DWORD)baseptr);
	MEMORY_BASIC_INFORMATION info;

	VMSIZE regionSize;
	VMSIZE checkSize = size;
	void* checkAddr = modaddr;
	bool result = true;
	
	// This loop scans memory regions starting with the target address and going up to target size.
	// If the memory we want to read spans multiple regions, check all of them before calling
	// ReadMemory.

	bool done = false;
	while(!done)
	{
		// get info about the region of memory that the target address resides in
		if(!VirtualQuery(checkAddr, &info, sizeof(info)))
		{
			result = false;
			break;
		}
		
		// Check for guard pages
		if (info.Protect & PAGE_GUARD) 
		{
			result = false;
			break;
		}
		
		// Check for read access
		if(!(info.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE))) 
		{
			result = false;
			break;
		}

		regionSize = info.RegionSize;
		if (info.BaseAddress < checkAddr)
		{
			regionSize -= reinterpret_cast<DWORD>(checkAddr) - reinterpret_cast<DWORD>(info.BaseAddress);
		}

		if (checkSize <= regionSize)
		{
			done = true;
			ReadMemory(modaddr, buf, size);
		}
		else
		{
			checkSize -= regionSize;
			checkAddr = reinterpret_cast<void*>(reinterpret_cast<DWORD>(checkAddr) + regionSize);
		}
	}

	return result;
}


bool PROCESSMEM::Write(VPVOID addr, VOID* buf, VMSIZE size)
{
	void* modaddr=(void*)((DWORD)addr+(DWORD)baseptr);
	MEMORY_BASIC_INFORMATION info;
	if(!VirtualQuery(modaddr,&info,sizeof(info))) return false;
	if(info.Protect&(PAGE_READWRITE|PAGE_EXECUTE_READWRITE)) {
		WriteMemory(modaddr,buf,size);
		return true;
	} else {
		return false;
	}
}

VMSIZE PROCESSMEM::size(void)
{
	return memsize;
}

bool PROCESSMEM::ReBase(LPVOID base)
{
	baseptr= base;
	
	return true;
}
