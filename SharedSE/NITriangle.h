#pragma once

namespace NI {
	struct Triangle {
		unsigned short vertices[3];

		std::reference_wrapper<unsigned short[3]> getVertices();
	};
}
