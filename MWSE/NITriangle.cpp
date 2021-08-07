#include "NITriangle.h"

namespace NI {
	std::reference_wrapper<unsigned short[3]> Triangle::getVertices() {
		return std::ref(vertices);
	}
}
