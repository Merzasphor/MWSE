#pragma once

#define reltolinear(a) (a+0x400000)
#define RUNFUNCIDXTOCODE(a) (OPCODE)(((a)+0x1000))

//------Relative Addresses for game code-------------------------
#define FIXUPSCRIPTBREAK 0x0fdb00
#define RUNSCRIPTBREAK	0x1028a0
#define DECODEWITHINFOBREAK	0x100540 // beware local vars different

#define RUNFUNCIDXERRBREAK 0x10d5d6 //edx=opcode, same
#define RUNFUNCIDXERRCONTINUE 0x10d5f6
#define RUNFUNCOPCODETEST 0x105831 //0x505831
/*
this actually runs the original functions
put the opcode in the EDX register.
*/

#define FIXUPTEMPLATE 0x0fe180
#define FIXUPTEMPLATEBREAK 0x0fe195
#define FIXUPPLAYER 0x0fe05a
#define FIXUPPLAYERBREAK 0x0fe068
#define FIXUPINSTANCE 0x0fe06d
#define FIXUPINSTANCEBREAK 0x0fe081

#define PLACEATPCRESULT 0x109a94
#define HASITEMEQUIPPEDRESULT  0x107c54

//------Relative Addresses for game data-------------------------
#define TES3IP_IMAGE	0x3cebb0
#define TES3OP_IMAGE	0x3a91c4

#define LOCALVARIABLES_IMAGE 0x3cebf8
#define SCRIPTTARGETREF_IMAGE	0x3cebec
#define SCRIPTTARGETTEMPL_IMAGE	0x3cebf4
#define SECONDOBJECT_IMAGE	0x3ce6f8 //first variable...
#define SECONDOBJECT_LENGTH_IMAGE 0x3cebb8

#define MASTER_IMAGE	0x3c67dc // cross check with fps_opt
#define MASTERCELL_IMAGE	0x3c67e0
#define MASTER2_IMAGE	0x3c6cdc // master + 0x500

#define VARINDEX_IMAGE	0x3cebb4 //count most of the time
#define DESTINATIONX_IMAGE	0x3cea48
#define DESTINATIONY_IMAGE	0x3cea4c
#define DESTINATIONZ_IMAGE	0x3cea50
#define DESTINATION_IMAGE DESTINATIONX_IMAGE
#define TARGETROTX_IMAGE	0x3ceb08
#define TARGETROTY_IMAGE	0x3ceb0c
#define TARGETROTZ_IMAGE	0x3ceb10
#define TARGETROT_IMAGE	TARGETROTX_IMAGE
#define TARGETCELL_IMAGE 0x3ce6f8

#define RUNSCRIPT_INREFOFFSET (0x04+0x4+0xC+0xf) // stays the same

//------Memory Layout of Virtual Machine-------------------------

#define SCRIPTMEM_SIZE (1<<16)
#define STACKMEM_SIZE (1<<16)
#define GENERALMEM_SIZE (VMSIZE_MAX-SCRIPTMEM_SIZE-STACKMEM_SIZE)

#define SCRIPTMEM_VPOS ((VPVOID)0)
#define GENERALMEM_VPOS ((VPVOID)(SCRIPTMEM_VPOS+SCRIPTMEM_SIZE))
#define STACKMEM_VPOS ((VPVOID)(GENERALMEM_VPOS+GENERALMEM_SIZE))

#define STACKMEM_MIN (VMSIZE)STACKMEM_VPOS
#define STACKMEM_MAX ((VMSIZE)(STACKMEM_VPOS+STACKMEM_SIZE))