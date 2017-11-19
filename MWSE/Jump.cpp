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
		mwLong_t address;
	};

	static const mwOpcode_t jumpOpcode = 0x3809;
	static Jump jumpInstance;

	Jump::Jump(): InstructionInterface_t(jumpOpcode){}

	void Jump::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getLongValue();
	}

	float Jump::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long * scriptIP = virtualMachine.getScriptIP();
		*scriptIP = address;
		return 0.0;
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
		mwLong_t address;
	};

	static const mwOpcode_t jumpZeroOpcode = 0x380b;
	static JumpZero jumpZeroInstance;

	JumpZero::JumpZero(): InstructionInterface_t(jumpZeroOpcode){}

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
		return 0.0;
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
		mwLong_t address;
	};

	static const mwOpcode_t jumpNotZeroOpcode = 0x380d;
	static JumpNotZero jumpNotZeroInstance;

	JumpNotZero::JumpNotZero(): InstructionInterface_t(jumpNotZeroOpcode){}

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
		return 0.0;
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
		mwLong_t address;
	};

	static const mwOpcode_t jumpPositiveOpcode = 0x3816;
	static JumpPositive jumpPositiveInstance;

	JumpPositive::JumpPositive(): InstructionInterface_t(jumpPositiveOpcode){}

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
		return 0.0;
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
		mwLong_t address;
	};

	static const mwOpcode_t jumpNegativeOpcode = 0x3818;
	static JumpNegative jumpNegativeInstance;

	JumpNegative::JumpNegative(): InstructionInterface_t(jumpNegativeOpcode){}

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
		return 0.0;
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
		mwShort_t address;
	};

	static const mwOpcode_t jumpShortOpcode = 0x380a;
	static JumpShort jumpShortInstance;

	JumpShort::JumpShort(): InstructionInterface_t(jumpShortOpcode){}

	void JumpShort::loadParameters(mwse::VMExecuteInterface &virtualMachine)
	{
		address = virtualMachine.getShortValue();
	}

	float JumpShort::execute(mwse::VMExecuteInterface &virtualMachine)
	{
		long * scriptIP = virtualMachine.getScriptIP();
		*scriptIP = static_cast<long>(address);
		return 0.0;
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
		mwShort_t address;
	};

	static const mwOpcode_t jumpShortZeroOpcode = 0x380c;
	static JumpShortZero jumpShortZeroInstance;

	JumpShortZero::JumpShortZero(): InstructionInterface_t(jumpShortZeroOpcode){}

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
		return 0.0;
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
		mwShort_t address;
	};

	static const mwOpcode_t jumpShortNotZeroOpcode = 0x380e;
	static JumpShortNotZero jumpShortNotZeroInstance;

	JumpShortNotZero::JumpShortNotZero(): InstructionInterface_t(jumpShortNotZeroOpcode){}

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
		return 0.0;
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
		mwShort_t address;
	};

	static const mwOpcode_t jumpShortPositiveOpcode = 0x3817;
	static JumpShortPositive jumpShortPositiveInstance;

	JumpShortPositive::JumpShortPositive(): InstructionInterface_t(jumpShortPositiveOpcode){}

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
		return 0.0;
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
		mwShort_t address;
	};

	static const mwOpcode_t jumpShortNegativeOpcode = 0x3819;
	static JumpShortNegative jumpShortNegativeInstance;

	JumpShortNegative::JumpShortNegative(): InstructionInterface_t(jumpShortNegativeOpcode){}

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
		return 0.0;
	}
	//----------------------------------------

}