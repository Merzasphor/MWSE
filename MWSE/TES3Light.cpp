#include "TES3Light.h"

namespace TES3 {
	bool Light::getIsDynamic() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setIsDynamic(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}

	bool Light::getCanCarry() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setCanCarry(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}

	bool Light::getIsNegative() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setIsNegative(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}

	bool Light::getFlickers() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setFlickers(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}

	bool Light::getIsFire() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setIsFire(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}

	bool Light::getIsOffByDefault() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setIsOffByDefault(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}

	bool Light::getFlickersSlowly() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setFlickersSlowly(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}

	bool Light::getPulses() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setPulses(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}

	bool Light::getPulsesSlowly() {
		return (flags & LightFlags::Dynamic);
	}

	void Light::setPulsesSlowly(bool value) {
		if (value) {
			flags |= LightFlags::Dynamic;
		}
		else {
			flags &= ~LightFlags::Dynamic;
		}
	}
}
