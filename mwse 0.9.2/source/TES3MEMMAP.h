//Tes3MemMap.h
//this file containes all sorts of opcodes, these are ESSENTIAL for MWSE to work.
//it also contains game data addresses, for example where to put your parameters for original functions.
//add 0x400000 to them for the real addresses!
#pragma once

//------Relative Addresses for game code-------------------------
#define FIXUPSCRIPTBREAK ((LPVOID)0xfdb00)
#define RUNSCRIPTBREAK	((LPVOID)0x1028a0)
#define DECODEWITHINFOBREAK	((LPVOID)0x100540) // beware local vars different

#define RUNFUNCIDXERRBREAK ((LPVOID)0x10d5d6) //edx=opcode, same
#define RUNFUNCIDXERRCONTINUE ((LPVOID)0x10d5f6)
#define RUNFUNCOPCODETEST ((LPVOID)0x105831)

#define FIXUPTEMPLATE ((LPVOID)0xfe180)
#define FIXUPTEMPLATEBREAK ((LPVOID)0xfe195)
#define FIXUPPLAYER ((LPVOID)0xfe05a)
#define FIXUPPLAYERBREAK ((LPVOID)0xfe068)
#define FIXUPINSTANCE ((LPVOID)0xfe06d)
#define FIXUPINSTANCEBREAK ((LPVOID)0xfe081)

#define PLACEATPCRESULT ((LPVOID)0x109a94)
#define HASITEMEQUIPPEDRESULT ((LPVOID) 0x107c54)

//------Relative Addresses for game data-------------------------
#define TES3IP_IMAGE	((LPVOID)0x3cebb0)
#define TES3OP_IMAGE	((LPVOID)0x3a91c4)

#define LOCALVARIABLES_IMAGE ((LPVOID)0x3cebf8)
#define SCRIPTTARGETREF_IMAGE	((LPVOID)0x3cebec)
#define SCRIPTTARGETTEMPL_IMAGE	((LPVOID)0x3cebf4)
#define SECONDOBJECT_IMAGE	((LPVOID)0x3ce6f8) //first variable...
#define SECONDOBJECT_LENGTH_IMAGE ((LPVOID)0x3cebb8)

#define MASTER_IMAGE	((LPVOID)0x3c67dc) // cross check with fps_opt
#define MASTERCELL_IMAGE	((LPVOID)0x3c67e0)
#define MASTER2_IMAGE	((LPVOID)0x3c6cdc) // master + 0x500

#define VARINDEX_IMAGE	((LPVOID)0x3cebb4) //count most of the time
#define DESTINATIONX_IMAGE	((LPVOID)0x3cea48)
#define DESTINATIONY_IMAGE	((LPVOID)0x3cea4c)
#define DESTINATIONZ_IMAGE	((LPVOID)0x3cea50)
#define DESTINATION_IMAGE DESTINATIONX_IMAGE
#define TARGETROTX_IMAGE	((LPVOID)0x3ceb08)
#define TARGETROTY_IMAGE	((LPVOID)0x3ceb0c)
#define TARGETROTZ_IMAGE	((LPVOID)0x3ceb10)
#define TARGETROT_IMAGE	TARGETROTX_IMAGE
#define TARGETCELL_IMAGE ((LPVOID)0x3ce6f8)

#define RUNSCRIPT_INREFOFFSET (0x04+0x4+0xC+0xf) // stays the same

/*** old adresses, not compatible anymore!
//------Relative Addresses for game code-------------------------
#define FIXUPSCRIPTBREAK ((LPVOID)0xfad60)
#define RUNSCRIPTBREAK ((LPVOID)0xffae0)
#define DECODEWITHINFOBREAK ((LPVOID)0xfd792)

#define RUNFUNCIDXERRBREAK ((LPVOID)0x0010A505)
#define RUNFUNCIDXERRCONTINUE ((LPVOID)0x0010A525)
#define RUNFUNCOPCODETEST ((LPVOID)0x102a71)

#define FIXUPTEMPLATE ((LPVOID)0xfb3e0)
#define FIXUPTEMPLATEBREAK ((LPVOID)0xfb3f5)
#define FIXUPPLAYER ((LPVOID)0xfb2ba)
#define FIXUPPLAYERBREAK ((LPVOID)0xfb2c8)
#define FIXUPINSTANCE ((LPVOID)0xfb2cd)
#define FIXUPINSTANCEBREAK ((LPVOID)0xfb2e1)

#define PLACEATPCRESULT ((LPVOID)0x106d03)
#define HASITEMEQUIPPEDRESULT ((LPVOID) 0x105015)

//------Relative Addresses for game data-------------------------

#define TES3IP_IMAGE ((LPVOID)0x03c64f0)
#define TES3OP_IMAGE	((LPVOID)0x3a0cf4)

#define LOCALVARIABLES_IMAGE ((LPVOID)0x3c6538)
#define SCRIPTTARGETREF_IMAGE	((LPVOID)0x3c652C)
#define SCRIPTTARGETTEMPL_IMAGE	((LPVOID)0x3c6534)
#define SECONDOBJECT_IMAGE	((LPVOID)0x3c6038)
#define SECONDOBJECT_LENGTH_IMAGE ((LPVOID)0x3c64f8)

#define MASTER_IMAGE	((LPVOID)0x3be11c)
#define MASTERCELL_IMAGE	((LPVOID)0x3be120)
#define MASTER2_IMAGE	((LPVOID)0x3be61c)

#define VARINDEX_IMAGE	((LPVOID)0x3c64f4)
#define DESTINATIONX_IMAGE	((LPVOID)0x3c6388)
#define DESTINATIONY_IMAGE	((LPVOID)0x3c638c)
#define DESTINATIONZ_IMAGE	((LPVOID)0x3C6390)
#define DESTINATION_IMAGE DESTINATIONX_IMAGE
#define TARGETROTX_IMAGE	((LPVOID)0x3c6448)
#define TARGETROTY_IMAGE	((LPVOID)0x3c644c)
#define TARGETROTZ_IMAGE	((LPVOID)0x3c6450)
#define TARGETROT_IMAGE	TARGETROTX_IMAGE
#define TARGETCELL_IMAGE ((LPVOID)0x3c6038)

#define RUNSCRIPT_INREFOFFSET (0x04+0x4+0xC+0xf) //ebp+return addr+stack param+runscript offset

***/

//------Memory Layout of Virtual Machine-------------------------

#define SCRIPTMEM_SIZE (1<<16)
#define STACKMEM_SIZE (1<<16)
#define GENERALMEM_SIZE (VMSIZE_MAX-SCRIPTMEM_SIZE-STACKMEM_SIZE)

#define SCRIPTMEM_VPOS ((VPVOID)0)
#define GENERALMEM_VPOS ((VPVOID)(SCRIPTMEM_VPOS+SCRIPTMEM_SIZE))
#define STACKMEM_VPOS ((VPVOID)(GENERALMEM_VPOS+GENERALMEM_SIZE))

#define STACKMEM_MIN (VMSIZE)STACKMEM_VPOS
#define STACKMEM_MAX ((VMSIZE)(STACKMEM_VPOS+STACKMEM_SIZE))
