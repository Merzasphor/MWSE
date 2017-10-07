#pragma once
#include "WinHeader.h"

/*inline float ReadFloat(DWORD addr);
inline BYTE ReadByte(DWORD addr);
inline WORD ReadShort(DWORD addr);
inline DWORD ReadInt(DWORD addr);

inline void WriteFloat(DWORD addr, float data);
inline void WriteByte(DWORD addr, BYTE data);
inline void WriteShort(DWORD addr, WORD data);
inline void WriteInt(DWORD addr, DWORD data);*/

#include "ADDRESSSPACE.h"

struct PROCESSMEM : public ADDRESSSPACE
{
	PROCESSMEM(LPVOID base, VMSIZE size);
	virtual bool Read(VPVOID addr, VOID* buf, VMSIZE size);
	virtual bool Write(VPVOID addr, VOID* buf, VMSIZE size);
	virtual VMSIZE size(void);
	virtual bool ReBase(LPVOID base);
private:
	LPVOID baseptr;
	VMSIZE memsize;
};