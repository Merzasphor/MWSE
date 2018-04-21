/************************************************************************
	
	mwseOffsets.h - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#pragma once

//
// Addresses for game data.
//

#define TES3_IP_IMAGE 0x7CEBB0
#define TES3_OP_IMAGE 0x7A91C4

#define TES3_LOCALVARIABLES_IMAGE 0x7CEBF8
#define TES3_SCRIPTTARGETREF_IMAGE 0x7CEBEC
#define TES3_SCRIPTTARGETTEMPL_IMAGE 0x7CEBF4
#define TES3_SECONDOBJECT_IMAGE 0x7CE6F8
#define TES3_SECONDOBJECT_LENGTH_IMAGE 0x7CEBB8
#define TES3_VARINDEX_IMAGE 0x7CEBB4

#define TES3_WORLD_CONTROLLER_IMAGE 0x7C67DC
#define TES3_GAME_IMAGE 0x7C6CDC
#define TES3_DATA_HANDLER_IMAGE 0x7C67E0

#define TES3_DESTINATION_X_IMAGE 0x7CEA48
#define TES3_DESTINATION_Y_IMAGE 0x7CEA4C
#define TES3_DESTINATION_Z_IMAGE 0x7CEA50

#define TES3_TARGET_ROTX_IMAGE 0x7CEB08
#define TES3_TARGET_ROTY_IMAGE 0x7CEB0C
#define TES3_TARGET_ROTZ_IMAGE 0x7CEB10

#define TES3_DATA_BUFFER 0x7CB678

//
// Hooking positions.
//

#define TES3_HOOK_GET_NEXT_INSTRUCTION 0x50055B
#define TES3_HOOK_GET_NEXT_INSTRUCTION_SIZE 0x6
#define TES3_HOOK_GET_NEXT_INSTRUCTION_RETURN (TES3_HOOK_GET_NEXT_INSTRUCTION + TES3_HOOK_GET_NEXT_INSTRUCTION_SIZE)

#define TES3_HOOK_RUN_FUNCTION 0x505831
#define TES3_HOOK_RUN_FUNCTION_SIZE 0x6
#define TES3_HOOK_RUN_FUNCTION_RETURN (TES3_HOOK_RUN_FUNCTION + TES3_HOOK_RUN_FUNCTION_SIZE)

#define TES3_HOOK_PLACE_GETREFERENCE 0x509992
#define TES3_HOOK_PLACE_GETREFERENCE_SIZE 0x6
#define TES3_HOOK_PLACE_GETREFERENCE_RETURN (TES3_HOOK_PLACE_GETREFERENCE + TES3_HOOK_PLACE_GETREFERENCE_SIZE)

//
// Addresses for in-function offsets.
//

#define TES3_INFUNC_RUN_SCRIPT_OPCODE 0x505793;
#define TES3_INFUNC_SCRIPT_ADD_ITEM 0x508B54;
#define TES3_MALLOC 0x749471C0
#define TES3_FREE 0x74947000
#define TES3_REALLOC 0x749472B0

//
// Address of hardcoded data.
//

#define TES3_DATA_EFFECT_FLAGS 0x747D88
