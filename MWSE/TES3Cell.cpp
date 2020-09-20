#include "TES3Cell.h"

#include "MemoryUtil.h"

namespace TES3 {
	const auto TES3_Cell_constructor = reinterpret_cast<Cell*(__thiscall *)(Cell*)>(0x4DB500);
	Cell * Cell::create() {
		return TES3_Cell_constructor(mwse::tes3::_new<Cell>());
	}

	const auto TES3_Cell_getFirstObjectOfType = reinterpret_cast<Reference*(__thiscall *)(const Cell*, int, unsigned char)>(0x4DBEF0);
	Reference * Cell::getFirstObjectOfType(ObjectType::ObjectType type, bool skipDeleted) const {
		return TES3_Cell_getFirstObjectOfType(this, type, skipDeleted);
	}

	bool Cell::isInterior() const {
		return getCellFlag(TES3::CellFlag::Interior);
	}

	const auto TES3_Cell_getExteriorGridX = reinterpret_cast<int(__thiscall *)(const Cell*)>(0x4DB9D0);
	int Cell::getGridX() const {
		return TES3_Cell_getExteriorGridX(this);
	}

	const auto TES3_Cell_setGridX = reinterpret_cast<void(__thiscall *)(Cell*, int)>(0x4DB9E0);
	void Cell::setGridX(int x) {
		TES3_Cell_setGridX(this, x);
	}

	const auto TES3_Cell_getExteriorGridY = reinterpret_cast<int(__thiscall *)(const Cell*)>(0x4DB9F0);
	int Cell::getGridY() const {
		return TES3_Cell_getExteriorGridY(this);
	}

	const auto TES3_Cell_setGridY = reinterpret_cast<void(__thiscall *)(Cell*, int)>(0x4DBA00);
	void Cell::setGridY(int y) {
		TES3_Cell_setGridY(this, y);
	}

	const auto TES3_Cell_setName = reinterpret_cast<void(__thiscall *)(Cell*, const char*)>(0x4E25E0);
	void Cell::setName(const char* name) {
		TES3_Cell_setName(this, name);
	}

	const auto TES3_Cell_addMapNote = reinterpret_cast<void(__thiscall*)(Cell*, Vector2*, float, const char*)>(0x4E3730);
	void Cell::addMapNote(Vector2* position, float unknown, const char* text) {
		TES3_Cell_addMapNote(this, position, unknown, text);
	}

	const auto TES3_Cell_insertReference = reinterpret_cast<void(__thiscall *)(Cell*, Reference*)>(0x4DC030);
	void Cell::insertReference(Reference* reference) {
		TES3_Cell_insertReference(this, reference);
	}

	const char* Cell::getName() const {
		return name;
	}

	bool Cell::getCellFlag(unsigned int flag) const {
		return (cellFlags & flag);
	}

	void Cell::setCellFlag(unsigned int flag, bool value) {
		if (value) {
			cellFlags |= flag;
		}
		else {
			cellFlags &= ~flag;
		}
	}

	std::optional<float> Cell::getFogDensity() const {
		if (cellFlags & CellFlag::Interior) {
			return VariantData.interior.fogDensity;
		}
		return {};
	}

	void Cell::setFogDensity(float value) {
		if (cellFlags & CellFlag::Interior) {
			VariantData.interior.fogDensity = value;
		}
	}

	std::optional<float> Cell::getWaterLevel() const {
		if (!(cellFlags & CellFlag::Interior) || cellFlags & CellFlag::BehavesAsExterior) {
			return 0.0;
		}
		else if (cellFlags & CellFlag::HasWater) {
			return waterLevelOrRegion.waterLevel;
		}
		return {};
	}

	void Cell::setWaterLevel(float value) {
		if (!(cellFlags & CellFlag::Interior) || cellFlags & CellFlag::BehavesAsExterior) {
			return;
		}
		else {
			if (cellFlags & CellFlag::HasWater) {
				waterLevelOrRegion.waterLevel = value;
			}
		}
	}

	Region * Cell::getRegion() const {
		if (!(cellFlags & CellFlag::Interior) || cellFlags & CellFlag::BehavesAsExterior) {
			return waterLevelOrRegion.region;
		}
		else {
			return nullptr;
		}
	}

	TES3::PackedColor* Cell::getAmbientColor() {
		if (cellFlags & TES3::CellFlag::Interior) {
			return &VariantData.interior.ambientColor;
		}
		return nullptr;
	}

	TES3::PackedColor* Cell::getFogColor() {
		if (cellFlags & TES3::CellFlag::Interior) {
			return &VariantData.interior.fogColor;
		}
		return nullptr;
	}

	TES3::PackedColor* Cell::getSunColor() {
		if (cellFlags & TES3::CellFlag::Interior) {
			return &VariantData.interior.sunColor;
		}
		return nullptr;
	}

	bool Cell::getBehavesAsExterior() const {
		return getCellFlag(TES3::CellFlag::BehavesAsExterior);
	}

	void Cell::setBehavesAsExterior(bool value) {
		setCellFlag(TES3::CellFlag::BehavesAsExterior, value);
	}

	bool Cell::getHasWater() const {
		return getCellFlag(TES3::CellFlag::HasWater);
	}

	void Cell::setHasWater(bool value) {
		setCellFlag(TES3::CellFlag::HasWater, value);
	}

	bool Cell::getIsInterior() const {
		return getCellFlag(TES3::CellFlag::Interior);
	}

	void Cell::setIsInterior(bool value) {
		setCellFlag(TES3::CellFlag::Interior, value);
	}

	bool Cell::getSleepingIsIllegal() const {
		return getCellFlag(TES3::CellFlag::SleepIsIllegal);
	}

	void Cell::setSleepingIsIllegal(bool value) {
		setCellFlag(TES3::CellFlag::SleepIsIllegal, value);
	}

	bool Cell::isPointInCell(float x, float y) const {
		if (cellFlags & CellFlag::Interior) {
			return true;
		}
		else {
			int cellX = toGridCoord(x), cellY = toGridCoord(y);
			return cellX == VariantData.exterior.gridX && cellY == VariantData.exterior.gridY;
		}
	}

	DWORD getObjectTypeForInput(sol::object obj) {
		if (obj.is<DWORD>()) {
			return obj.as<DWORD>();
		}
		throw std::invalid_argument("Invalid reference filter provided.");
	}

	void addReferencesToTable(sol::table& result, const TES3::ReferenceList& references, std::unordered_set<DWORD>& filters) {
		for (auto ref : references) {
			if (filters.empty() || filters.count(ref->baseObject->objectType) > 0) {
				result.add(ref);
			}
		}
	}

	sol::table Cell::getFilteredReferences(sol::optional<sol::object> param, sol::this_state ts) const {
		sol::state_view state = ts;
		sol::table result = state.create_table();

		std::unordered_set<DWORD> filter;
		if (param) {
			if (param.value().is<sol::table>()) {
				for (auto& entry : param.value().as<sol::table>()) {
					filter.insert(getObjectTypeForInput(entry.second));
				}
			}
			else {
				filter.insert(getObjectTypeForInput(param.value()));
			}
		}

		addReferencesToTable(result, actors, filter);
		addReferencesToTable(result, persistentRefs, filter);
		addReferencesToTable(result, temporaryRefs, filter);

		return result;
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::Cell)
