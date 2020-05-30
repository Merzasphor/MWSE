#include "NILinesData.h"

#include "NIBinaryStream.h"
#include "NIStream.h"

#include "TES3Util.h"

namespace NI {
	const auto NI_GeometryData_loadBinary = reinterpret_cast<void(__thiscall*)(GeometryData*, Stream*)>(0x6EF5E0);
	void LinesData::loadBinary(Stream* stream) {
		// Parent class load.
		NI_GeometryData_loadBinary(this, stream);

		// Fixed flag loading logic.
		flags = (bool*)mwse::tes3::_new(vertexCount);
		stream->inStream->read(flags, vertexCount);
	}
}
