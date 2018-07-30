#include "TES3CrimeEvent.h"



namespace TES3 {
	const auto TES3_CrimeEvent_ctor = reinterpret_cast<CrimeEvent * (__thiscall*)(CrimeEvent *)>(0x51F250);
	const auto TES3_CrimeEvent_dtor = reinterpret_cast<CrimeEvent * (__thiscall*)(CrimeEvent *)>(0x51F580);
	const auto TES3_CrimeEvent_copy = reinterpret_cast<CrimeEvent * (__thiscall*)(CrimeEvent *, CrimeEvent *)>(0x51F3A0);

	CrimeEvent::CrimeEvent() {
		TES3_CrimeEvent_ctor(this);
	}

	CrimeEvent::~CrimeEvent() {
		TES3_CrimeEvent_dtor(this);
	}

	void CrimeEvent::copy(CrimeEvent* crimeEvent) {
		TES3_CrimeEvent_copy(this, crimeEvent);
	}
}
