#include "TES3Misc.h"

#include "TES3Util.h"

namespace TES3 {
	const auto TES3_MiscItem_ctor = reinterpret_cast< void( __thiscall * )( Misc * ) >( 0x4A6320 );
	Misc::Misc() :
		stolenList{},
		name{},
		script{},
		model{},
		icon{},
		weight{},
		value{},
		flags{}
	{
		TES3_MiscItem_ctor( this );
	}

	const auto TES3_MiscItem_dtor = reinterpret_cast< void( __thiscall * )( Misc * ) >( 0x4A6400 );
	Misc::~Misc(	)
	{
		TES3_MiscItem_dtor( this );
	}

	const auto TES3_Misc_getGoldStackCount = reinterpret_cast<int(__cdecl*)(Misc*)>(0x49A750);
	int Misc::getGoldStackCount() {
		return TES3_Misc_getGoldStackCount(this);
	}

	SoulGemData * Misc::getSoulGemData() {
		return mwse::tes3::getSoulGemData(this);
	}

	bool Misc::isSoulGem() {
		return mwse::tes3::isSoulGem(this);
	}
}
