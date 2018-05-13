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
		return (flags & LightFlags::CanCarry);
	}

	void Light::setCanCarry(bool value) {
		if (value) {
			flags |= LightFlags::CanCarry;
		}
		else {
			flags &= ~LightFlags::CanCarry;
		}
	}

	bool Light::getIsNegative() {
		return (flags & LightFlags::Negative);
	}

	void Light::setIsNegative(bool value) {
		if (value) {
			flags |= LightFlags::Negative;
		}
		else {
			flags &= ~LightFlags::Negative;
		}
	}

	bool Light::getFlickers() {
		return (flags & LightFlags::Flicker);
	}

	void Light::setFlickers(bool value) {
		if (value) {
			flags |= LightFlags::Flicker;
		}
		else {
			flags &= ~LightFlags::Flicker;
		}
	}

	bool Light::getIsFire() {
		return (flags & LightFlags::Fire);
	}

	void Light::setIsFire(bool value) {
		if (value) {
			flags |= LightFlags::Fire;
		}
		else {
			flags &= ~LightFlags::Fire;
		}
	}

	bool Light::getIsOffByDefault() {
		return (flags & LightFlags::OffByDefault);
	}

	void Light::setIsOffByDefault(bool value) {
		if (value) {
			flags |= LightFlags::OffByDefault;
		}
		else {
			flags &= ~LightFlags::OffByDefault;
		}
	}

	bool Light::getFlickersSlowly() {
		return (flags & LightFlags::FlickerSlow);
	}

	void Light::setFlickersSlowly(bool value) {
		if (value) {
			flags |= LightFlags::FlickerSlow;
		}
		else {
			flags &= ~LightFlags::FlickerSlow;
		}
	}

	bool Light::getPulses() {
		return (flags & LightFlags::Pulse);
	}

	void Light::setPulses(bool value) {
		if (value) {
			flags |= LightFlags::Pulse;
		}
		else {
			flags &= ~LightFlags::Pulse;
		}
	}

	bool Light::getPulsesSlowly() {
		return (flags & LightFlags::PulseSlow);
	}

	void Light::setPulsesSlowly(bool value) {
		if (value) {
			flags |= LightFlags::PulseSlow;
		}
		else {
			flags &= ~LightFlags::PulseSlow;
		}
	}
}
