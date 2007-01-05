#pragma once
#include "WinHeader.h"

#define ReadMemory(a,b,c) CopyMemory(b,a,c)
#define WriteMemory CopyMemory

inline float ReadFloat(DWORD addr);
inline BYTE ReadByte(DWORD addr);
inline WORD ReadShort(DWORD addr);
inline DWORD ReadInt(DWORD addr);

inline void WriteFloat(DWORD addr, float data);
inline void WriteByte(DWORD addr, BYTE data);
inline void WriteShort(DWORD addr, WORD data);
inline void WriteInt(DWORD addr, DWORD data);

//------Relative Addresses for game code-------------------------
#define FIXUPSCRIPTBREAK 0x4fdb00
#define RUNSCRIPTBREAK	0x5028a0
#define DECODEWITHINFOBREAK	0x500540 // beware local vars different

#define RUNFUNCIDXERRBREAK 0x50d5d6 //edx=opcode, same
#define RUNFUNCIDXERRCONTINUE 0x50d5f6
#define RUNFUNCOPCODETEST 0x505831

#define FIXUPTEMPLATE 0x4fe180
#define FIXUPTEMPLATEBREAK 0x4fe195
#define FIXUPPLAYER 0x4fe05a
#define FIXUPPLAYERBREAK 0x4fe068
#define FIXUPINSTANCE 0x4fe06d
#define FIXUPINSTANCEBREAK 0x4fe081

#define PLACEATPCRESULT 0x509a94
#define HASITEMEQUIPPEDRESULT  0x507c54

//------Relative Addresses for game data-------------------------
#define TES3IP_IMAGE	0x7cebb0
#define TES3OP_IMAGE	0x7a91c4

#define LOCALVARIABLES_IMAGE 0x7cebf8
#define SCRIPTTARGETREF_IMAGE	0x7cebec
#define SCRIPTTARGETTEMPL_IMAGE	0x7cebf4
#define SECONDOBJECT_IMAGE	0x7ce6f8 //first variable...
#define SECONDOBJECT_LENGTH_IMAGE 0x7cebb8

#define MASTER_IMAGE	0x7c67dc // cross check with fps_opt
#define MASTERCELL_IMAGE	0x7c67e0
#define MASTER2_IMAGE	0x7c6cdc // master + 0x500

#define VARINDEX_IMAGE	0x7cebb4 //count most of the time
#define DESTINATIONX_IMAGE	0x7cea48
#define DESTINATIONY_IMAGE	0x7cea4c
#define DESTINATIONZ_IMAGE	0x7cea50
#define DESTINATION_IMAGE DESTINATIONX_IMAGE
#define TARGETROTX_IMAGE	0x7ceb08
#define TARGETROTY_IMAGE	0x7ceb0c
#define TARGETROTZ_IMAGE	0x7ceb10
#define TARGETROT_IMAGE	TARGETROTX_IMAGE
#define TARGETCELL_IMAGE 0x7ce6f8

#define RUNSCRIPT_INREFOFFSET (0x04+0x4+0xC+0xf) // stays the same