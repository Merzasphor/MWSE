#include "TES3Quest.h"

namespace TES3 {
	char* Quest::getObjectID() const {
		return name;
	}

	std::string Quest::toJson() const {
		std::ostringstream ss;
		ss << "\"tes3quest:" << getObjectID() << "\"";
		return std::move(ss.str());
	}
}
