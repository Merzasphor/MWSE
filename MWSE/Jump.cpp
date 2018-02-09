/************************************************************************
               Jump.cpp - Copyright (c) 2008 The MWSE Project
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

#include "VMExecuteInterface.h"
#include "Stack.h"
#include "InstructionInterface.h"
#include "Flags.h"

using namespace mwse;

namespace mwse
{
	//----------------------------------------
	class Jump : public InstructionInterface_t
	{
	public:
		Jump();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwLong address;
	};

	static Jump jumpInstance;

	Jump::Jump(): InstructionInterface_t(OpCode::_Jump){}

	void Jump::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getLongValue();
	}

	float Jump::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long * scriptIP = virtualMachine.getScriptIP();
		*scriptIP = address;
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class JumpZero : public InstructionInterface_t
	{
	public:
		JumpZero();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwLong address;
	};

	static JumpZero jumpZeroInstance;

	JumpZero::JumpZero(): InstructionInterface_t(OpCode::_JumpZero){}

	void JumpZero::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getLongValue();
	}

	float JumpZero::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if(Flags::getZero())
		{
			long * scriptIP = virtualMachine.getScriptIP();
			*scriptIP = address;
		}
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class JumpNotZero : public InstructionInterface_t
	{
	public:
		JumpNotZero();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwLong address;
	};

	static JumpNotZero jumpNotZeroInstance;

	JumpNotZero::JumpNotZero(): InstructionInterface_t(OpCode::_JumpNotZero){}

	void JumpNotZero::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getLongValue();
	}

	float JumpNotZero::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if(!Flags::getZero())
		{
			long * scriptIP = virtualMachine.getScriptIP();
			*scriptIP = address;
		}
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class JumpPositive : public InstructionInterface_t
	{
	public:
		JumpPositive();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwLong address;
	};

	static JumpPositive jumpPositiveInstance;

	JumpPositive::JumpPositive(): InstructionInterface_t(OpCode::_JumpPositive){}

	void JumpPositive::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getLongValue();
	}

	float JumpPositive::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if(Flags::getPositive())
		{
			long * scriptIP = virtualMachine.getScriptIP();
			*scriptIP = address;
		}
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class JumpNegative : public InstructionInterface_t
	{
	public:
		JumpNegative();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwLong address;
	};

	static JumpNegative jumpNegativeInstance;

	JumpNegative::JumpNegative(): InstructionInterface_t(OpCode::_JumpNegative){}

	void JumpNegative::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getLongValue();
	}

	float JumpNegative::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if(!Flags::getPositive())
		{
			long * scriptIP = virtualMachine.getScriptIP();
			*scriptIP = address;
		}
		return 0.0f;
	}
	//----------------------------------------


	//short jumps

	//----------------------------------------
	class JumpShort : public InstructionInterface_t
	{
	public:
		JumpShort();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwShort address;
	};

	static JumpShort jumpShortInstance;

	JumpShort::JumpShort(): InstructionInterface_t(OpCode::_JumpShort){}

	void JumpShort::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getShortValue();
	}

	float JumpShort::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long * scriptIP = virtualMachine.getScriptIP();
		*scriptIP = static_cast<long>(address);
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class JumpShortZero : public InstructionInterface_t
	{
	public:
		JumpShortZero();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwShort address;
	};

	static JumpShortZero jumpShortZeroInstance;

	JumpShortZero::JumpShortZero(): InstructionInterface_t(OpCode::_JumpShortZero){}

	void JumpShortZero::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getShortValue();
	}

	float JumpShortZero::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if(Flags::getZero())
		{
			long * scriptIP = virtualMachine.getScriptIP();
			*scriptIP = static_cast<long>(address);
		}
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class JumpShortNotZero : public InstructionInterface_t
	{
	public:
		JumpShortNotZero();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwShort address;
	};

	static JumpShortNotZero jumpShortNotZeroInstance;

	JumpShortNotZero::JumpShortNotZero(): InstructionInterface_t(OpCode::_JumpShortNotZero){}

	void JumpShortNotZero::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getShortValue();
	}

	float JumpShortNotZero::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if(!Flags::getZero())
		{
			long * scriptIP = virtualMachine.getScriptIP();
			*scriptIP = static_cast<long>(address);
		}
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class JumpShortPositive : public InstructionInterface_t
	{
	public:
		JumpShortPositive();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwShort address;
	};

	static JumpShortPositive jumpShortPositiveInstance;

	JumpShortPositive::JumpShortPositive(): InstructionInterface_t(OpCode::_JumpShortPositive){}

	void JumpShortPositive::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getShortValue();
	}

	float JumpShortPositive::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if(Flags::getPositive())
		{
			long * scriptIP = virtualMachine.getScriptIP();
			*scriptIP = static_cast<long>(address);
		}
		return 0.0f;
	}
	//----------------------------------------
	//----------------------------------------
	class JumpShortNegative : public InstructionInterface_t
	{
	public:
		JumpShortNegative();
		virtual float execute(VMExecuteInterface &virtualMachine);
		virtual void loadParameters(VMExecuteInterface &virtualMachine);
	protected:
	private:
		mwShort address;
	};

	static JumpShortNegative jumpShortNegativeInstance;

	JumpShortNegative::JumpShortNegative(): InstructionInterface_t(OpCode::_JumpShortNegative){}

	void JumpShortNegative::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getShortValue();
	}

	float JumpShortNegative::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		if(!Flags::getPositive())
		{
			long * scriptIP = virtualMachine.getScriptIP();
			*scriptIP = static_cast<long>(address);
		}
		return 0.0f;
	}
	//----------------------------------------

}