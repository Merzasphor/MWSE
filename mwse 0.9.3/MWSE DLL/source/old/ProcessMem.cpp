#include "ProcessMem.h"

inline float ReadFloat(DWORD addr) { return *reinterpret_cast<float*>(addr); }
inline BYTE ReadByte(DWORD addr)   { return *reinterpret_cast<BYTE*>(addr);  }
inline WORD ReadShort(DWORD addr)  { return *reinterpret_cast<WORD*>(addr);  }
inline DWORD ReadInt(DWORD addr)   { return *reinterpret_cast<DWORD*>(addr); }

inline void WriteFloat(DWORD addr, float data) { *reinterpret_cast<float*>(addr)=data; }
inline void WriteByte(DWORD addr, BYTE data)   { *reinterpret_cast<BYTE*>(addr)=data;  }
inline void WriteShort(DWORD addr, WORD data)  { *reinterpret_cast<WORD*>(addr)=data;  }
inline void WriteInt(DWORD addr, DWORD data)   { *reinterpret_cast<DWORD*>(addr)=data; }