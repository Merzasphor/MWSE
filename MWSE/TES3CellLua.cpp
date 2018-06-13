#include "TES3CellLua.h"

#include "sol.hpp"
#include "LuaManager.h"

#include "TES3Cell.h"
#include "TES3Region.h"

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
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::CellExteriorData
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::CellExteriorData>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("cell", &TES3::CellExteriorData::cell);
				usertypeDefinition.set("gridX", &TES3::CellExteriorData::gridX);
				usertypeDefinition.set("gridY", &TES3::CellExteriorData::gridY);

				// Finish up our usertype.
				state.set_usertype("tes3cellExteriorData", usertypeDefinition);
			}

			// Binding for TES3::PackedColor
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::PackedColor>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Basic property binding.
				usertypeDefinition.set("r", &TES3::PackedColor::r);
				usertypeDefinition.set("g", &TES3::PackedColor::g);
				usertypeDefinition.set("b", &TES3::PackedColor::b);
				usertypeDefinition.set("a", &TES3::PackedColor::a);

				// Finish up our usertype.
				state.set_usertype("tes3packedColor", usertypeDefinition);
			}

			// Binding for TES3::Cell
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Cell>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());

				// Allow object to be converted to strings using their object ID.
				usertypeDefinition.set(sol::meta_function::to_string, &TES3::Cell::getObjectID);

				// Basic property binding.
				usertypeDefinition.set("actors", &TES3::Cell::actors);
				usertypeDefinition.set("activators", &TES3::Cell::activators);
				usertypeDefinition.set("cellFlags", &TES3::Cell::cellFlags);
				usertypeDefinition.set("pathGrid", &TES3::Cell::pathGrid);
				usertypeDefinition.set("statics", &TES3::Cell::statics);
				usertypeDefinition.set("moveReferences", &TES3::Cell::moveReferences);

				// Functions exposed as properties.
				usertypeDefinition.set("ambientColor", sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
				{
					if (self.cellFlags & TES3::CellFlag::Interior) {
						return &self.VariantData.interior.ambientColor;
					}
					return NULL;
				}
				));
				usertypeDefinition.set("behavesAsExterior", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::BehavesAsExterior); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::BehavesAsExterior, set); }
				));
				usertypeDefinition.set("fogColor", sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
				{
					if (self.cellFlags & TES3::CellFlag::Interior) {
						return &self.VariantData.interior.fogColor;
					}
					return NULL;
				}
				));
				usertypeDefinition.set("fogDensity", sol::property(&TES3::Cell::getFogDensity, &TES3::Cell::setFogDensity));
				usertypeDefinition.set("gridX", sol::readonly_property(&TES3::Cell::getGridX));
				usertypeDefinition.set("gridY", sol::readonly_property(&TES3::Cell::getGridY));
				usertypeDefinition.set("hasWater", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::HasWater); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::HasWater, set); }
				));
				usertypeDefinition.set("isInterior", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::Interior); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::Interior, set); }
				));

				usertypeDefinition.set("region", sol::readonly_property(&TES3::Cell::getRegion));
				usertypeDefinition.set("restingIsIllegal", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::SleepIsIllegal); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::SleepIsIllegal, set); }
				));
				usertypeDefinition.set("sunColor", sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
				{
					if (self.cellFlags & TES3::CellFlag::Interior) {
						return &self.VariantData.interior.sunColor;
					}
					return NULL;
				}
				));
				usertypeDefinition.set("waterLevel", sol::property(&TES3::Cell::getWaterLevel, &TES3::Cell::setWaterLevel));

				// Basic function binding.
				usertypeDefinition.set("iterateReferences", sol::overload(iterateReferences, iterateReferencesFiltered));

				// Finish up our usertype.
				state.set_usertype("tes3cell", usertypeDefinition);
			}
		}
	}
}
