#include "CSPhysicalObject.h"

#include "CSStatic.h"

namespace se::cs {
	bool PhysicalObject::canRotateOnAllAxes() const {
		switch (objectType) {
		case ObjectType::Creature:
		case ObjectType::LeveledCreature:
		case ObjectType::NPC:
			return false;
		case ObjectType::Static:
			if (this == Static::gDoorMarker::get()) {
				return false;
			}
		}
		return true;
	}
}
