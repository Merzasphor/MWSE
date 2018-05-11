#include "TES3CellLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		auto iterateReferencesFiltered(TES3::Cell* cell, unsigned int desiredType) {
			unsigned int currentList = 0;
			TES3::Reference * reference = cell->actors.head;
			return [cell, reference, currentList, desiredType]() mutable -> sol::object {
				while (reference && desiredType != 0 && reference->baseObject->objectType != desiredType) {
					reference = reinterpret_cast<TES3::Reference*>(reference->nextInCollection);

					// Check to see if we need to run to the next list.
					if (reference == NULL) {
						switch (currentList) {
						case 0:
							reference = cell->activators.head;
							break;
						case 1:
							reference = cell->statics.head;
							break;
						}
						currentList++;
					}
				}

				if (reference == NULL) {
					return sol::nil;
				}

				sol::state& state = LuaManager::getInstance().getState();
				sol::object ret = sol::make_object(state, reference);
				reference = reinterpret_cast<TES3::Reference*>(reference->nextInCollection);
				return ret;
			};
		}

		auto iterateReferences(TES3::Cell* cell) {
			return iterateReferencesFiltered(cell, 0);
		}

		void bindTES3Cell() {
			sol::state& state = LuaManager::getInstance().getState();

			state.new_usertype<TES3::CellExteriorData>("TES3CellExteriorData",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"cell", &TES3::CellExteriorData::cell,
				"gridX", &TES3::CellExteriorData::gridX,
				"gridY", &TES3::CellExteriorData::gridY

				);

			state.new_usertype<TES3::Cell>("TES3Cell",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"objectType", &TES3::Cell::objectType,

				"id", sol::readonly_property(&TES3::Cell::getObjectID),

				"flags", &TES3::Cell::cellFlags,

				"actors", &TES3::Cell::actors,
				"activators", &TES3::Cell::activators,
				"statics", &TES3::Cell::statics,
				"moveReferences", &TES3::Cell::moveReferences,

				"pathGrid", sol::readonly_property(&TES3::Cell::pathGrid),

				"gridX", sol::readonly_property(&TES3::Cell::getGridX),
				"gridY", sol::readonly_property(&TES3::Cell::getGridY),

				"ambientColor", sol::property(&TES3::Cell::getAmbientColor, &TES3::Cell::setAmbientColor),
				"sunColor", sol::property(&TES3::Cell::getSunColor, &TES3::Cell::setSunColor),
				"fogColor", sol::property(&TES3::Cell::getFogColor, &TES3::Cell::setFogColor),
				"fogDensity", sol::property(&TES3::Cell::getFogDensity, &TES3::Cell::setFogDensity),

				"waterLevel", sol::property(&TES3::Cell::getWaterLevel, &TES3::Cell::setWaterLevel),

				"region", sol::readonly_property(&TES3::Cell::getRegion),

				//
				// Functions.
				//

				"iterateReferences", sol::overload(iterateReferences, iterateReferencesFiltered)

				);
		}
	}
}
