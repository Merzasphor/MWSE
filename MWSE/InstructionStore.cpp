/************************************************************************
               InstructionStore.cpp - Copyright (c) 2008 The MWSE Project
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

#include "InstructionStore.h"

using namespace mwse;

static const int table_size = 255;

InstructionStore InstructionStore::single_instance;

InstructionStore::InstructionStore()
{
}

void InstructionStore::add(InstructionInterface_t &implementation)
{
    size_t primary_index = (implementation.getOpCode() >> 8) & 0xFF;
    size_t secondary_index = implementation.getOpCode() & 0xFF;
    InstructionInterface_t **secondary_table = opCode_primary_table[primary_index];
    if (secondary_table == NULL) {
        opCode_primary_table[primary_index] = secondary_table = new InstructionInterface_t *[table_size];
        for (int i = 0; i < table_size; i++) {
            secondary_table[i] = NULL;
        }
    }
    secondary_table[secondary_index] = &implementation;
}
