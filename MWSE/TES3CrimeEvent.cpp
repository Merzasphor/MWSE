#include "TES3CrimeEvent.h"



namespace TES3 {
	CrimeEvent::CrimeEvent() {
		ctor();
	}

	CrimeEvent::~CrimeEvent() {
		dtor();
	}

	const auto TES3_CrimeEvent_ctor = reinterpret_cast<CrimeEvent * (__thiscall*)(CrimeEvent *)>(0x51F250);
	CrimeEvent * CrimeEvent::ctor() {
		return TES3_CrimeEvent_ctor(this);
	}

	const auto TES3_CrimeEvent_dtor = reinterpret_cast<CrimeEvent * (__thiscall*)(CrimeEvent *)>(0x51F580);
	void CrimeEvent::dtor() {
		TES3_CrimeEvent_dtor(this);
	}

	const auto TES3_CrimeEvent_copy = reinterpret_cast<CrimeEvent * (__thiscall*)(CrimeEvent *, CrimeEvent *)>(0x51F3A0);
	void CrimeEvent::copy(CrimeEvent* crimeEvent) {
		TES3_CrimeEvent_copy(this, crimeEvent);
	}
}
