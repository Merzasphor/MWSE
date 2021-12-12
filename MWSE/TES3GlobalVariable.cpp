#include "TES3GlobalVariable.h"

namespace TES3 {
	double GlobalVariable::getValue_lua() const {
		switch (toupper(valueType)) {
		case 'S': return short(value);
		case 'L': return int(value);
		}
		return value;
	}

	void GlobalVariable::setValue_lua(double v) {
		switch (toupper(valueType)) {
		case 'S':
			value = float(short(v));
			break;
		case 'L':
			value = float(int(v));
			break;
		default:
			value = float(v);
		}
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::GlobalVariable)
