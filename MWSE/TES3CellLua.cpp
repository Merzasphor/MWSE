#include "TES3CellLua.h"

#include "LuaManager.h"
#include "TES3ObjectLua.h"

#include "TES3Cell.h"
#include "TES3Region.h"

namespace mwse {
	namespace lua {
		auto iterateReferencesFiltered(const TES3::Cell& cell, const std::unordered_set<unsigned int> desiredTypes) {
			// Prepare the lists we care about.
			std::queue<TES3::Reference*> referenceListQueue;
			if (cell.actors.size > 0) {
				referenceListQueue.push(cell.actors.head);
			}
			if (cell.persistentRefs.size > 0) {
				referenceListQueue.push(cell.persistentRefs.head);
			}
			if (cell.temporaryRefs.size > 0) {
				referenceListQueue.push(cell.temporaryRefs.head);
			}

			// Get the first reference we care about.
			TES3::Reference* reference = nullptr;
			if (!referenceListQueue.empty()) {
				reference = referenceListQueue.front();
				referenceListQueue.pop();
			}

			return [cell, reference, referenceListQueue, desiredTypes]() mutable -> sol::object {
				while (reference && !desiredTypes.empty() && !desiredTypes.count(reference->baseObject->objectType)) {
					reference = reinterpret_cast<TES3::Reference*>(reference->nextInCollection);

					// If we hit the end of the list, check for the next list.
					if (reference == nullptr && !referenceListQueue.empty()) {
						reference = referenceListQueue.front();
						referenceListQueue.pop();
					}
				}

				if (reference == nullptr) {
					return sol::nil;
				}

				// Get the object we want to return.
				sol::object ret = lua::makeLuaObject(reference);

				// Get the next reference. If we're at the end of the list, go to the next one
				reference = reinterpret_cast<TES3::Reference*>(reference->nextInCollection);
				if (reference == nullptr && !referenceListQueue.empty()) {
					reference = referenceListQueue.front();
					referenceListQueue.pop();
				}

				return ret;
			};
		}

		void bindTES3Cell() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

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

				// 
				usertypeDefinition.set("red", &TES3::PackedColor::r);
				usertypeDefinition.set("green", &TES3::PackedColor::g);
				usertypeDefinition.set("blue", &TES3::PackedColor::b);
				usertypeDefinition.set("alpha", &TES3::PackedColor::a);

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
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("actors", sol::readonly_property(&TES3::Cell::actors));
				usertypeDefinition.set("activators", sol::readonly_property(&TES3::Cell::persistentRefs));
				usertypeDefinition.set("cellFlags", &TES3::Cell::cellFlags);
				usertypeDefinition.set("statics", sol::readonly_property(&TES3::Cell::temporaryRefs));

				// Functions exposed as properties.
				usertypeDefinition.set("ambientColor", sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							return &self.VariantData.interior.ambientColor;
						}
						return nullptr;
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
						return nullptr;
					}
				));
				usertypeDefinition.set("fogDensity", sol::property(
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
				));
				usertypeDefinition.set("gridX", sol::property(&TES3::Cell::getGridX, &TES3::Cell::setGridX));
				usertypeDefinition.set("gridY", sol::property(&TES3::Cell::getGridY, &TES3::Cell::setGridY));
				usertypeDefinition.set("hasWater", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::HasWater); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::HasWater, set); }
				));
				usertypeDefinition.set("isInterior", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::Interior); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::Interior, set); }
				));
				usertypeDefinition.set("name", sol::property(
					[](TES3::Cell& self) { return self.name; },
					[](TES3::Cell& self, const char* name) { self.setName(name); }
				));
				usertypeDefinition.set("pickObjectsRoot", sol::readonly_property(&TES3::Cell::pickObjectsRoot));
				usertypeDefinition.set("region", sol::readonly_property(&TES3::Cell::getRegion));
				usertypeDefinition.set("restingIsIllegal", sol::property(
					[](TES3::Cell& self) { return self.getCellFlag(TES3::CellFlag::SleepIsIllegal); },
					[](TES3::Cell& self, bool set) { self.setCellFlag(TES3::CellFlag::SleepIsIllegal, set); }
				));
				usertypeDefinition.set("staticObjectsRoot", sol::readonly_property(&TES3::Cell::staticObjectsRoot));
				usertypeDefinition.set("sunColor", sol::readonly_property(
					[](TES3::Cell& self) -> TES3::PackedColor*
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							return &self.VariantData.interior.sunColor;
						}
						return nullptr;
					}
				));
				usertypeDefinition.set("waterLevel", sol::property(
					[](TES3::Cell& self) -> sol::optional<float>
					{
						if (self.cellFlags & TES3::CellFlag::Interior) {
							return self.waterLevelOrRegion.waterLevel;
						}
						return sol::optional<float>();
					},
					&TES3::Cell::setWaterLevel
				));

				// Basic function binding.
				usertypeDefinition.set("iterateReferences", [](TES3::Cell& self, sol::optional<sol::object> param) {
					std::unordered_set<unsigned int> filters;

					if (param) {
						if (param.value().is<unsigned int>()) {
							filters.insert(param.value().as<unsigned int>());
						}
						else if (param.value().is<sol::table>()) {
							sol::table filterTable = param.value().as<sol::table>();
							for (const auto& kv : filterTable) {
								if (kv.second.is<unsigned int>()) {
									filters.insert(kv.second.as<unsigned int>());
								}
							}
						}
						else {
							throw std::invalid_argument("Iteration can only be filtered by object type, a table of object types, or must not have any filter.");
						}
					}

					return iterateReferencesFiltered(self, std::move(filters));
				});

				// Finish up our usertype.
				state.set_usertype("tes3cell", usertypeDefinition);
			}
		}
	}
}
