/************************************************************************
               Stack.h - Copyright (c) 2008 The MWSE Project
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

#include "mwseTypes.h"
#include "mwseString.h"

/**
 * This Stack class is a singleton. It provides an
 * efficient push/pop mechanism for a parameter stack.
 *
 * Items on the stack are native types plus the two MWSE types.
 * No validation across push/pop operations are performed; that is,
 * no error will occur in the sequence of:
 *      pushLong(value);
 *      mwFloat_t value = popFloat(value);
 * save where the value defines a cast operator that validates
 * its value (as may be the case for mwseString).
 *
 * Basic usage:
 *      Stack::getInstance().pushLong(value);
 *      ....
 *      mwLong_t value = Stack::getInstance().popLong(value);
 */
namespace mwse {
    class Stack {
        public:
            static Stack &getInstance() { return singleton; };

            typedef unsigned int StackItem_t;

            void pushShort(const mwShort_t value)
            {
                push(static_cast<StackItem_t>(value));
            }
            void pushLong(const mwLong_t value)
            {
                push(static_cast<StackItem_t>(value));
            }
            void pushFloat(const mwFloat_t value)
            {
                push(static_cast<StackItem_t>(value));
            }
            void pushString(const mwseString_t &value)
            {
                push(static_cast<StackItem_t>(value));
            }
            //void pushRef(const mwRef_t &value);

            mwShort_t   popShort(void)
            {
                return static_cast<mwShort_t>(pop());
            }
            mwLong_t    popLong(void)
            {
                return static_cast<mwLong_t>(pop());
            }
            mwFloat_t   popFloat(void)
            {
                return static_cast<mwFloat_t>(pop());
            }
            mwseString_t popString(void)
            {
                return static_cast<mwseString_t>(pop());
            }
            //mwRef_t & popRef(void);

        private:
            Stack();

            static Stack singleton;

            void push(StackItem_t value)
            {
                if (stack_top >= stack_size) {
                    stack_size += 32;
                    StackItem_t *new_stack = new StackItem_t[stack_size];
                    for (size_t i = 0; i < stack_top; i++) {
                        new_stack[i] = stack_storage[i];
                    }
                    delete [] stack_storage;
                    stack_storage = new_stack;
                }
                stack_storage[stack_top] = value;
                stack_top++;
            }
    
            StackItem_t pop()
            {
                if (stack_top == 0) {
                    //throw ?
                }
                stack_top --;
                return stack_storage[stack_top];
            }

            StackItem_t * stack_storage;  // dynamically sized array
            size_t      stack_size;     // current allocated size
            size_t      stack_top;      // current top (0=empty; 1=one item)
    };
};
