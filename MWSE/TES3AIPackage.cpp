#include "TES3AIPackage.h"

namespace TES3 {
	void AIPackage::simulate() {
		vTable->simulate(this);
	}

	bool AIPackage::movement() {
		return vTable->movement(this);
	}

	bool AIPackage::initialize() {
		return vTable->initialize(this);
	}

	void AIPackage::cleanup() {
		vTable->cleanup(this);
	}
}
