/************************************************************************
	
	mwseOffsets.h - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

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

// Addresses for game data.
#define TES3_IP_IMAGE 0x7CEBB0
#define TES3_OP_IMAGE 0x7A91C4

#define TES3_LOCALVARIABLES_IMAGE 0x7CEBF8
#define TES3_SCRIPTTARGETREF_IMAGE 0x7CEBEC
#define TES3_SCRIPTTARGETTEMPL_IMAGE 0x7CEBF4
#define TES3_SECONDOBJECT_IMAGE 0x7CE6F8
#define TES3_SECONDOBJECT_LENGTH_IMAGE 0x7CEBB8

#define TES3_MASTER_IMAGE 0x7C67DC
#define TES3_MASTER2_IMAGE 0x7C6CDC
#define TES3_MASTERCELL_IMAGE 0x7C67E0 // Master cell image. Use tes3::getCellMaster()

// Addresses for game functions.
#define TES3_FUNC_GET_MACP 0x40FF20
#define TES3_FUNC_LOAD_MESSAGE 0x40F930
#define TES3_FUNC_FIXUP_INSTANCE 0x4B8F50
#define TES3_FUNC_FIXUP_TEMPLATE 0x4B8B60
#define TES3_FUNC_FIND_GLOBAL 0x4BA820
#define TES3_FUNC_SKILL_LEVEL_UP 0x56BBE0
#define TES3_FUNC_FIND_SCRIPT_VARIABLE 0x50E7B0
#define TES3_FUNC_DISPLAY_MESSAGE 0x5F90C0
#define TES3_FUNC_ADD_NEW_OBJECT 0x4B8980
