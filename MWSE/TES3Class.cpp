#include "TES3Class.h"

#define TES3_Class_loadDescription 0x4A81D0
#define TES3_Class_setDescription 0x4A8200
#define TES3_Class_freeDescription 0x4A8450

namespace TES3 {
	char* Class::getObjectID() {
		return id;
	}

	char* Class::getName() {
		return name;
	}

	bool Class::getServiceFlag(unsigned int flag) {
		return (services & flag) != 0;
	}


	char * Class::loadDescription() {
		return reinterpret_cast<char *(__thiscall *)(Class*)>(TES3_Class_loadDescription)(this);
	}

	void Class::setDescription(const char * description) {
		reinterpret_cast<void(__thiscall *)(Class*, const char*)>(TES3_Class_setDescription)(this, description);
	}

	void Class::freeDescription() {
		reinterpret_cast<void(__thiscall *)(Class*)>(TES3_Class_freeDescription)(this);
	}

	void Class::setServiceFlag(unsigned int flag, bool set) {
		if (set) {
			services |= flag;
		}
		else {
			services &= ~flag;
		}
	}
}
