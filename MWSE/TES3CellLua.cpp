#include "TES3CellLua.h"

#include "LuaUnifiedHeader.h"
#include "LuaManager.h"

namespace mwse {
	namespace lua {
		auto iterateReferencesFiltered(TES3::Cell* cell, unsigned int desiredType) {
			unsigned int currentList = 0;

			// Prepare the lists we care about.
			std::queue<TES3::Reference*> referenceListQueue;
			if (cell->actors.size > 0) {
				referenceListQueue.push(cell->actors.head);
			}
			if (cell->activators.size > 0) {
				referenceListQueue.push(cell->activators.head);
			}
			if (cell->statics.size > 0) {
				referenceListQueue.push(cell->statics.head);
			}

			// Get the first reference we care about.
			TES3::Reference* reference = NULL;
			if (!referenceListQueue.empty()) {
				reference = referenceListQueue.front();
				referenceListQueue.pop();
			}

			return [cell, reference, referenceListQueue, desiredType]() mutable -> sol::object {
				while (reference && desiredType != 0 && reference->baseObject->objectType != desiredType) {
					reference = reinterpret_cast<TES3::Reference*>(reference->nextInCollection);

					// If we hit the end of the list, check for the next list.
					if (reference == NULL && !referenceListQueue.empty()) {
						reference = referenceListQueue.front();
						referenceListQueue.pop();
					}
				}

				// If we didn't find an object, return nil.
				if (reference == NULL) {
					return sol::nil;
				}

				// Get the object we want to return.
				sol::state& state = LuaManager::getInstance().getState();
				sol::object ret = sol::make_object(state, reference);

				// Get the next reference. If we're at the end of the list, go to the next one.
				reference = reinterpret_cast<TES3::Reference*>(reference->nextInCollection);
				if (reference == NULL && !referenceListQueue.empty()) {
					reference = referenceListQueue.front();
					referenceListQueue.pop();
				}

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

			state.new_usertype<TES3::PackedColor>("TES3PackedColor",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Properties.
				//

				"r", &TES3::PackedColor::r,
				"g", &TES3::PackedColor::g,
				"b", &TES3::PackedColor::b,
				"a", &TES3::PackedColor::a

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
				"isInterior", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::Interior); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::Interior, set); }
					),
				"hasWater", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::HasWater); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::HasWater, set); }
					),
				"restingIsIllegal", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::SleepIsIllegal); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::SleepIsIllegal, set); }
					),
				"behavesAsExterior", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::BehavesAsExterior); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::BehavesAsExterior, set); }
					),

				"actors", &TES3::Cell::actors,
				"activators", &TES3::Cell::activators,
				"statics", &TES3::Cell::statics,
				"moveReferences", &TES3::Cell::moveReferences,

				"pathGrid", sol::readonly_property(&TES3::Cell::pathGrid),

				"gridX", sol::readonly_property(&TES3::Cell::getGridX),
				"gridY", sol::readonly_property(&TES3::Cell::getGridY),

				"ambientColor", sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
			{
				if (self.cellFlags & TES3::CellFlag::Interior) {
					return &self.VariantData.interior.ambientColor;
				}
				return NULL;
			}),
				"sunColor", sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
			{
				if (self.cellFlags & TES3::CellFlag::Interior) {
					return &self.VariantData.interior.sunColor;
				}
				return NULL;
			}),
				"fogColor", sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
			{
				if (self.cellFlags & TES3::CellFlag::Interior) {
					return &self.VariantData.interior.fogColor;
				}
				return NULL;
			}),
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
