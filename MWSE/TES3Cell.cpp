#include "TES3Cell.h"
#include "TES3Util.h"


namespace TES3 {
	const auto TES3_Cell_constructor = reinterpret_cast<Cell*(__thiscall *)(Cell*)>(0x4DB500);
	Cell * Cell::create() {
		return TES3_Cell_constructor(mwse::tes3::_new<Cell>());
	}

	const auto TES3_Cell_getFirstObjectOfType = reinterpret_cast<Reference*(__thiscall *)(Cell*, int, unsigned char)>(0x4DBEF0);
	Reference * Cell::getFirstObjectOfType(ObjectType::ObjectType type, bool skipDeleted = true) {
		return TES3_Cell_getFirstObjectOfType(this, type, skipDeleted);
	}

	bool Cell::isInterior() {
		return getCellFlag(TES3::CellFlag::Interior);
	}

	const auto TES3_Cell_getExteriorGridX = reinterpret_cast<int(__thiscall *)(Cell*)>(0x4DB9D0);
	int Cell::getGridX() {
		return TES3_Cell_getExteriorGridX(this);
	}

	const auto TES3_Cell_setGridX = reinterpret_cast<void(__thiscall *)(Cell*, int)>(0x4DB9E0);
	void Cell::setGridX(int x) {
		TES3_Cell_setGridX(this, x);
	}

	const auto TES3_Cell_getExteriorGridY = reinterpret_cast<int(__thiscall *)(Cell*)>(0x4DB9F0);
	int Cell::getGridY() {
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

	const auto TES3_Cell_insertReference = reinterpret_cast<void(__thiscall *)(Cell*, Reference*)>(0x4DC030);
	void Cell::insertReference(Reference* reference) {
		TES3_Cell_insertReference(this, reference);
	}

	bool Cell::getCellFlag(unsigned int flag) {
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

	float Cell::getFogDensity() {
		if (cellFlags & CellFlag::Interior) {
			return VariantData.interior.fogDensity;
		}
		else {
			return -1;
		}
	}

	void Cell::setFogDensity(float value) {
		if (cellFlags & CellFlag::Interior) {
			VariantData.interior.fogDensity = value;
		}
	}

	float Cell::getWaterLevel() {
		if (!(cellFlags & CellFlag::Interior) || cellFlags & CellFlag::BehavesAsExterior) {
			return 0.0;
		}
		else {
			return (cellFlags & CellFlag::HasWater) ? waterLevelOrRegion.waterLevel : FLT_MIN;
		}
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

	Region * Cell::getRegion() {
		if (!(cellFlags & CellFlag::Interior) || cellFlags & CellFlag::BehavesAsExterior) {
			return waterLevelOrRegion.region;
		}
		else {
			return nullptr;
		}
	}

	bool Cell::isPointInCell(float x, float y) {
		if (cellFlags & CellFlag::Interior) {
			return true;
		}
		else {
			int cellX = toGridCoord(x), cellY = toGridCoord(y);
			return cellX == VariantData.exterior.gridX && cellY == VariantData.exterior.gridY;
		}
	}
}
