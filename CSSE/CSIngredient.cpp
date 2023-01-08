#include "CSIngredient.h"

#include "CSDataHandler.h"
#include "CSRecordHandler.h"

namespace se::cs {
	void Ingredient::getEffectName(char* buffer, size_t bufferSize, int index) const {
		const auto recordHandler = DataHandler::get()->recordHandler;
		recordHandler->getNameForEffect(buffer, bufferSize, effects[index], effectAttributeIds[index], effectSkillIds[index]);
	}
}
