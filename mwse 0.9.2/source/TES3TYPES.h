#ifndef _TES3TYPES_H_FHJMETBWARBAWDBNETY
#define _TES3TYPES_H_FHJMETBWARBAWDBNETY

#include "VMTYPES.h"

typedef short	TES3SHORT;
typedef long	TES3LONG;
typedef float	TES3FLOAT;
typedef enum{VARNODE=6,MACHNODE=8} TES3ATTACHTYPE;

typedef enum{NPC='_CPN',CREA='AERC',CONT='TNOC'} TEMPLTYPE;

typedef enum{NORTHWEST=0,NORTH=1,NORTHEAST=2,WEST=3,CENTRE=4,EAST=5,SOUTHWEST=6,SOUTH=7,SOUTHEAST=8} TES3CELLGRID;

typedef BYTE* VPSTR;

// 2005-06-27  CDC
struct TES3HEADER
{
	VPVOID	vtable;
	DWORD	type;
};

struct TES3IDSTRING
{
	char id[128];
};
typedef TES3IDSTRING* VPIDSTRING;

struct TES3VARIABLES
{
	TES3SHORT*	shorts;
	TES3LONG*	longs;
	TES3FLOAT*	floats;
};
typedef TES3VARIABLES* VPVARIABLES;

struct TES3SCRIPT
{
	VPVOID	vtable;
	DWORD	type;
	BYTE	unknown[8];
	BYTE	name[0x20];
	DWORD	numshorts;
	DWORD	numlongs;
	DWORD	numfloats;
	DWORD	scdtlength;
	BYTE	unknown2[0x58-0x3c-sizeof(DWORD)];
	VPVOID	scdt;
};
typedef TES3SCRIPT* VPSCRIPT;

struct TES3LISTNODE
{
	DWORD type;
	TES3LISTNODE* next;
	VPVOID dataptr;
};
typedef TES3LISTNODE* VPLISTNODE;

struct TES3LISTITERATOR
{
	BYTE unknown[8];
	VPLISTNODE first;
	BYTE unknown2[4];
	VPLISTNODE current;
};
typedef TES3LISTITERATOR* VPLISTITERATOR;

struct TES3REFERENCE;

struct TES3TEMPLATE
{
	VPVOID vtable;
	DWORD type; // , CREA NPC_, MISC, things like that
	BYTE unknown[0x18-sizeof(VPVOID)-sizeof(DWORD)];
	TES3REFERENCE* first;
	BYTE unknown2[0x2C-0x18-sizeof(TES3REFERENCE*)];
	VPSTR objectid;
	BYTE unknown3[0x3c-0x2c-sizeof(BYTE*)];
	DWORD invflags;
	TES3LISTITERATOR inventory;
};
typedef TES3TEMPLATE* VPTEMPLATE;

struct TES3STACK
{
	DWORD	count;
	VPTEMPLATE templ;
};
typedef TES3STACK* VPSTACK;

struct TES3REFERENCE
{
	VPVOID vtable;
	DWORD type;	// "REFR"
	BYTE	unknown[0x18-sizeof(VPVOID)-sizeof(DWORD)];
	TES3REFERENCE* nextofsametempl;
	TES3REFERENCE* prev;
	TES3REFERENCE* next;
	BYTE	unknown2[0x28-0x18-3*sizeof(TES3REFERENCE*)];
	VPTEMPLATE templ;
	BYTE	unknown3[0x38-0x28-sizeof(VPTEMPLATE)];
	FLOAT	x,y,z;
	VPLISTNODE attachments;
	BYTE unknown4[0x60-0x38-3*sizeof(FLOAT)-sizeof(VPLISTNODE)];
};
typedef TES3REFERENCE* VPREFERENCE;

struct TES3VARHOLDER
{
	BYTE unknown[0x18];
	VPVARIABLES vars;
};
typedef TES3VARHOLDER* VPVARHOLDER;

struct TES3MACH
{
	BYTE unknown[0x14];
	VPREFERENCE	ref;
	BYTE unknown2[0xcc+0x20 - 0x14-sizeof(VPREFERENCE)];
	TES3MACH* combattarget;
};
typedef TES3MACH* VPMACH;

struct TES3COORDINATE
{
	TES3FLOAT x,y,z;
};
typedef TES3COORDINATE* VPCOORDINATE;

struct TES3ROTATION
{
	TES3FLOAT x,y,z;
};
typedef TES3ROTATION* VPROTATION;

struct TES3ARMOUR
{
	TES3TEMPLATE common;
	BYTE unknown[0x110-sizeof(TES3TEMPLATE)];
	DWORD septims;
};

struct TES3WEAPON
{
	TES3TEMPLATE common;
	BYTE unknown[0x58-sizeof(TES3TEMPLATE)];
	DWORD septims;
};

struct TES3REFLISTHEAD
{
	LONG	size;
	VPREFERENCE first;
	VPREFERENCE last;
	VPREFERENCE container;
};

struct TES3CELL
{
	BYTE unknown[0x10];
	VPSTR cellname; // may be null
	BYTE unknown2[0x30-0x10-sizeof(VPSTR)];
	TES3REFLISTHEAD npc;
	TES3REFLISTHEAD statics;
	BYTE unknown3[0x58-0x30-2*sizeof(TES3REFLISTHEAD)];
	TES3REFLISTHEAD otheritems;
};
typedef TES3CELL* VPCELL;

struct TES3CELLPTR
{
	LONG size;
	VPCELL	first;
};
typedef TES3CELLPTR* VPCELLPTR;

struct TES3CELLMASTER
{
	BYTE unknown[0x4];
	VPCELLPTR exteriorcells[9];
	BYTE unknown2[0xac-0x4-9*sizeof(VPCELLPTR)];
	VPCELL	interiorcell;
};
typedef TES3CELLMASTER* VPCELLMASTER;

struct TES3VIEWMASTER
{
	BYTE unknown[0x4c];
	BYTE unknown2[0x9c];
	VPREFERENCE target;
};
typedef TES3VIEWMASTER* VPVIEWMASTER;

#endif
