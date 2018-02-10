/************************************************************************
               Push.cpp - Copyright (c) 2008 The MWSE Project
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

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"

using namespace mwse;

namespace mwse
{
	//----------------------------------------
	class Push : public InstructionInterface_t
	{
	public:
		Push();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		long pushData;
	};

	static Push pushInstance;

	Push::Push(): InstructionInterface_t(OpCode::_PushLong){}

	void Push::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		pushData = virtualMachine.getLongValue();
	}

	float Push::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		Stack::getInstance().pushLong(pushData);
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class PushB : public InstructionInterface_t
	{
	public:
		PushB();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		long pushData;
	};

	static PushB pushBInstance;

	PushB::PushB(): InstructionInterface_t(OpCode::_PushByte){}

	void PushB::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		pushData = virtualMachine.getByteValue();
	}

	float PushB::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		Stack::getInstance().pushByte(pushData);
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class PushS : public InstructionInterface_t
	{
	public:
		PushS();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		long pushData;
	};

	static PushS pushSInstance;

	PushS::PushS(): InstructionInterface_t(OpCode::_PushShort){}

	void PushS::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		pushData = virtualMachine.getShortValue();
	}

	float PushS::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		Stack::getInstance().pushShort(pushData);
		return 0.0f;
	}
	//----------------------------------------
}