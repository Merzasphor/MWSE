#include "SetGsStringFunction.h"

#include "TES3MemMap.h"
#include "TES3TYPES.h"

bool SetGsStringFunction::execute()
{
	long gmst_id, gmst_string_id;
	long result = 0;
	if (machine.pop(gmst_id) && machine.pop(gmst_string_id) &&
		gmst_id >= 0 && gmst_string_id != 0) {
		TES3CELLMASTER const* const cell_master =
			*(reinterpret_cast<TES3CELLMASTER**>reltolinear(MASTERCELL_IMAGE));
		char*& gmst_string = cell_master->recordLists->GMSTs[gmst_id]->value.string_value;
		char const* const new_string = 
			machine.GetString(reinterpret_cast<VPVOID>(gmst_string_id));
		if (strlen(new_string) > strlen(gmst_string)) {
			gmst_string = 
				static_cast<char*>(machine.Realloc(gmst_string, strlen(new_string) + 1));
		}
		strcpy(gmst_string, new_string);
		result = 1;
	}
	return machine.push(result);
}
