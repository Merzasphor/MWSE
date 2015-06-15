//Tes3Offsets.h
#pragma once

#include "TES3MACHINE.h"
#include "FUNCEXTENDER.h"
#include "STRINGS.h"

#ifndef ULONG
#define ULONG unsigned long int
#endif
	
#define LONGOFFSET(a,b) (VPVOID)(ULONG)( ((ULONG*)(a)) + b)

#define OFFSET_SCDT		0x16
#define OFFSET_NPCFLAGS		0x0d
#define OFFSET_NPCCLASS		0x2d
#define OFFSET_NPCSERVICES	0x3a
#define OFFSET_NPCLEVEL		0x1f
#define OFFSET_CLASSSERVICES	0x22
#define OFFSET_GOLD		0xd8
#define OFFSET_NPCBASEGOLD	0x2b
#define OFFSET_CREBASEGOLD	0x36
#define OFFSET_LEVI_LIST	0x0c

// offset of value/weight/etc. in carriable item templates
ULONG offsetOfValue(ULONG type);
ULONG offsetOfWeight(ULONG type);
ULONG offsetOfCondition(ULONG type);
ULONG offsetOfQuality(ULONG type);

const char *GetNameString(TES3MACHINE& vm, VPVOID temp, ULONG type, VPVOID base);
	
bool GetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, void* data, size_t size);
template<class T> bool GetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, T &data)
{
    return GetOffsetData(vm, base, offset, reinterpret_cast<void *>(&data), sizeof(data));
}
template<class T> bool GetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, T *data)
{
    return GetOffsetData(vm, base, offset, reinterpret_cast<void *>(data), sizeof(*data));
}
	
bool SetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, void *data, size_t size);
template<class T> bool SetOffsetData(TES3MACHINE& vm, VPVOID base, ULONG offset, T data) 
{
    return SetOffsetData(vm, base, offset, reinterpret_cast<void *>(&data), sizeof(T));
}

bool GetIdString(TES3MACHINE& vm, VPVOID temp, char *id);

bool GetTargetData(TES3MACHINE& vm, VPVOID* refr, VPVOID* temp=0, ULONG* type=0, VPVOID* base=0);

bool GetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, void* data, size_t size);

void* GetAttachPointer(TES3MACHINE& vm, VPVOID ref, ULONG type);

template<class T> bool GetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, T &data)
{
    return GetAttachData(vm, ref, type, offset, reinterpret_cast<void *>(&data), sizeof(T));
}
template<class T> bool GetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, T *data)
{
    return GetAttachData(vm, ref, type, offset, reinterpret_cast<void *>(data), sizeof(T));
}

bool SetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, void *data, size_t size);
template<class T> bool SetAttachData(TES3MACHINE& vm, VPVOID ref, ULONG type, ULONG offset, T data)
{
    return SetAttachData(vm, ref, type, offset, reinterpret_cast<void *>(&data), sizeof(T));
}

//what's wrong with this?
#if 0
// Data structures for the offsets

struct TEMPLATE_LEVI
{
        VOID* vtable;
        DWORD type;		// LEVI, literally 'IVEL'
        DWORD flags;		// Generic object template flags
	ULONG unknown3;		// Some sort of pointer to the master file?
	ULONG unknown4;
	ULONG unknown5;		// Points to a template list of some sort.
	ULONG unknown6;
	ULONG unknown7;
	ULONG unknown8;
	ULONG unknown9;
	ULONG unknowna;
	STRING* objectid;
	LIST* listhead;
	ULONG unknownd;
	DWORD properties;	// 1=call for all levels, 2=calc for each item
	DWORD chance;		// chance of none
};

struct LIST {
	ULONG u0;
	DWORD listsize;	// number of items in list
	NODE* first;
	NODE* last;
};

struct NODE {
	NODE* prev;
	NODE* next;
	RAND* entry;
};

struct RAND {
	TMPL* template;
	SHORT pclevel;
};
#endif
