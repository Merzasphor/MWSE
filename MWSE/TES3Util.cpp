#include "TES3Util.h"

namespace mwse
{
	namespace tes3
	{
		TES3CellMaster_t * getCellMaster()
		{
			return *reinterpret_cast<TES3CellMaster_t**>(0x7C67E0);
		}

		REFRRecord_t * skipRemovedReferences(REFRRecord_t * reference)
		{
			while (reference != 0 && (reference->flags & 0x20) == 0x20)
			{
				reference = reference->nextRecord;
			}
			return reference;
		}
	}
}
