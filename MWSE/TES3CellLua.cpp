#include "TES3CellLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Cell.h"
#include "TES3Region.h"

#include <Windows.h>

namespace mwse {
	namespace lua {
		auto iterateReferencesFiltered(TES3::Cell* cell, unsigned int desiredType) {
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();

			unsigned int currentList = 0;

			// Prepare the lists we care about.
			std::queue<TES3::Reference*> referenceListQueue;
			if (cell->actors.size > 0) {
				referenceListQueue.push(cell->actors.head);
			}
			if (cell->persistentRefs.size > 0) {
				referenceListQueue.push(cell->persistentRefs.head);
			}
			if (cell->temporaryRefs.size > 0) {
				referenceListQueue.push(cell->temporaryRefs.head);
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
				sol::object ret = lua::makeLuaObject(reference);

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
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::PackedColor
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::PackedColor>("tes3packedColor");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["r"] = &TES3::PackedColor::r;
				usertypeDefinition["g"] = &TES3::PackedColor::g;
				usertypeDefinition["b"] = &TES3::PackedColor::b;
				usertypeDefinition["a"] = &TES3::PackedColor::a;

				// 
				usertypeDefinition["red"] = &TES3::PackedColor::r;
				usertypeDefinition["green"] = &TES3::PackedColor::g;
				usertypeDefinition["blue"] = &TES3::PackedColor::b;
				usertypeDefinition["alpha"] = &TES3::PackedColor::a;
			}

			// Binding for TES3::Cell
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Cell>("tes3cell");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition["actors"] = sol::readonly_property(&TES3::Cell::actors);
				usertypeDefinition["activators"] = sol::readonly_property(&TES3::Cell::persistentRefs);
				usertypeDefinition["cellFlags"] = &TES3::Cell::cellFlags;
				usertypeDefinition["statics"] = sol::readonly_property(&TES3::Cell::temporaryRefs);

				// Functions exposed as properties.
				usertypeDefinition["ambientColor"] = sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							return &self.VariantData.interior.ambientColor;
						}
						return nullptr;
					}
				);
				usertypeDefinition["behavesAsExterior"] = sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::BehavesAsExterior); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::BehavesAsExterior, set); }
				);
				usertypeDefinition["fogColor"] = sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							return &self.VariantData.interior.fogColor;
						}
						return nullptr;
					}
				);
				usertypeDefinition["fogDensity"] = sol::property(
					[](TES3::Cell& self) -> sol::optional<float>
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							return self.VariantData.interior.fogDensity;
						}
						return sol::optional<float>();
					},
					[](TES3::Cell& self, float value)
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							self.VariantData.interior.fogDensity = value;
						}
					}
				);
				usertypeDefinition["gridX"] = sol::property(&TES3::Cell::getGridX, &TES3::Cell::setGridX);
				usertypeDefinition["gridY"] = sol::property(&TES3::Cell::getGridY, &TES3::Cell::setGridY);
				usertypeDefinition["hasWater"] = sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::HasWater); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::HasWater, set); }
				);
				usertypeDefinition["isInterior"] = sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::Interior); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::Interior, set); }
				);
				usertypeDefinition["name"] = sol::property(
					[](TES3::Cell& self) { return self.name; },
					[](TES3::Cell& self, const char* name) { self.setName(name); }
				);
				usertypeDefinition["pickObjectsRoot"] = sol::readonly_property(&TES3::Cell::pickObjectsRoot);
				usertypeDefinition["region"] = sol::readonly_property(&TES3::Cell::getRegion);
				usertypeDefinition["restingIsIllegal"] = sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::SleepIsIllegal); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::SleepIsIllegal, set); }
				);
				usertypeDefinition["staticObjectsRoot"] = sol::readonly_property(&TES3::Cell::staticObjectsRoot);
				usertypeDefinition["sunColor"] = sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							return &self.VariantData.interior.sunColor;
						}
						return nullptr;
					}
				);
				usertypeDefinition["waterLevel"] = sol::property(
					[](TES3::Cell& self) -> sol::optional<float>
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							return self.waterLevelOrRegion.waterLevel;
						}
						return sol::optional<float>();
					},
					&TES3::Cell::setWaterLevel
				);

				// Basic function binding.
				usertypeDefinition["iterateReferences"] = sol::overload(iterateReferences, iterateReferencesFiltered);
			}
		}
	}
}
