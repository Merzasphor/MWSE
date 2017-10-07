#include "GetGsStringFunction.h"

#include "TES3MemMap.h"
#include "TES3TYPES.h"

bool GetGsStringFunction::execute()
{
	long gmst_id;
	long gmst_string_id = 0;
	if (machine.pop(gmst_id) && gmst_id >= 0) {
		TES3CELLMASTER const* const cell_master =
			*(reinterpret_cast<TES3CELLMASTER**>reltolinear(MASTERCELL_IMAGE));
		GMSTRecord const* const* const gmsts = cell_master->recordLists->GMSTs;
		char const* const gmst_string = strings.add(gmsts[gmst_id]->value.string_value);
		gmst_string_id = reinterpret_cast<long>(gmst_string);
	}
	return machine.push(gmst_string_id);
}
