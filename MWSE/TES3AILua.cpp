#include "TES3AILua.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3AIConfig.h"
#include "TES3AIData.h"
#include "TES3AIPackage.h"
#include "TES3Cell.h"
#include "TES3MobileActor.h"

namespace mwse {
	namespace lua {
		void bindTES3AI() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::AIConfig
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::AIConfig>("tes3aiConfig");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["alarm"] = &TES3::AIConfig::alarm;
				usertypeDefinition["fight"] = &TES3::AIConfig::fight;
				usertypeDefinition["flee"] = &TES3::AIConfig::flee;
				usertypeDefinition["hello"] = &TES3::AIConfig::hello;
				usertypeDefinition["merchantFlags"] = &TES3::AIConfig::merchantFlags;
				usertypeDefinition["travelDestinations"] = &TES3::AIConfig::travelDestinations;

				// Nicer access to merchant flags.
				usertypeDefinition["bartersAlchemy"] = sol::property(&TES3::AIConfig::getBartersAlchemy, &TES3::AIConfig::setBartersAlchemy);
				usertypeDefinition["bartersApparatus"] = sol::property(&TES3::AIConfig::getBartersApparatus, &TES3::AIConfig::setBartersApparatus);
				usertypeDefinition["bartersArmor"] = sol::property(&TES3::AIConfig::getBartersArmor, &TES3::AIConfig::setBartersArmor);
				usertypeDefinition["bartersBooks"] = sol::property(&TES3::AIConfig::getBartersBooks, &TES3::AIConfig::setBartersBooks);
				usertypeDefinition["bartersClothing"] = sol::property(&TES3::AIConfig::getBartersClothing, &TES3::AIConfig::setBartersClothing);
				usertypeDefinition["bartersEnchantedItems"] = sol::property(&TES3::AIConfig::getBartersEnchantedItems, &TES3::AIConfig::setBartersEnchantedItems);
				usertypeDefinition["bartersIngredients"] = sol::property(&TES3::AIConfig::getBartersIngredients, &TES3::AIConfig::setBartersIngredients);
				usertypeDefinition["bartersLights"] = sol::property(&TES3::AIConfig::getBartersLights, &TES3::AIConfig::setBartersLights);
				usertypeDefinition["bartersLockpicks"] = sol::property(&TES3::AIConfig::getBartersLockpicks, &TES3::AIConfig::setBartersLockpicks);
				usertypeDefinition["bartersMiscItems"] = sol::property(&TES3::AIConfig::getBartersMiscItems, &TES3::AIConfig::setBartersMiscItems);
				usertypeDefinition["bartersProbes"] = sol::property(&TES3::AIConfig::getBartersProbes, &TES3::AIConfig::setBartersProbes);
				usertypeDefinition["bartersRepairTools"] = sol::property(&TES3::AIConfig::getBartersRepairTools, &TES3::AIConfig::setBartersRepairTools);
				usertypeDefinition["bartersWeapons"] = sol::property(&TES3::AIConfig::getBartersWeapons, &TES3::AIConfig::setBartersWeapons);
				usertypeDefinition["offersEnchanting"] = sol::property(&TES3::AIConfig::getOffersEnchanting, &TES3::AIConfig::setOffersEnchanting);
				usertypeDefinition["offersRepairs"] = sol::property(&TES3::AIConfig::getOffersRepairs, &TES3::AIConfig::setOffersRepairs);
				usertypeDefinition["offersSpellmaking"] = sol::property(&TES3::AIConfig::getOffersSpellmaking, &TES3::AIConfig::setOffersSpellmaking);
				usertypeDefinition["offersSpells"] = sol::property(&TES3::AIConfig::getOffersSpells, &TES3::AIConfig::setOffersSpells);
				usertypeDefinition["offersTraining"] = sol::property(&TES3::AIConfig::getOffersTraining, &TES3::AIConfig::setOffersTraining);
			}

			// Binding for TES3::AIPlanner
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::AIPlanner>("tes3aiPlanner");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["countPackages"] = sol::readonly_property(&TES3::AIPlanner::countPackages);
				usertypeDefinition["indexActivePackage"] = sol::readonly_property(&TES3::AIPlanner::indexActivePackage);
				usertypeDefinition["mobile"] = sol::readonly_property(&TES3::AIPlanner::mobileActor);

				// Basic function binding.
				usertypeDefinition["getActivePackage"] = &TES3::AIPlanner::getActivePackage;

				// Indirect bindings to unions and arrays.
				usertypeDefinition["packages"] = sol::readonly_property(&TES3::AIPlanner::getPackages);
			}

			// Binding for TES3::AIPackage
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::AIPackage>("tes3aiPackage");
				usertypeDefinition["new"] = sol::no_constructor;

				// Basic property binding.
				usertypeDefinition["destinationCell"] = sol::readonly_property(&TES3::AIPackage::destinationCell);
				usertypeDefinition["distance"] = sol::readonly_property(&TES3::AIPackage::distance);
				usertypeDefinition["duration"] = sol::readonly_property(&TES3::AIPackage::duration);
				usertypeDefinition["hourOfDay"] = sol::readonly_property(&TES3::AIPackage::hourOfDay);
				usertypeDefinition["isDone"] = sol::readonly_property(&TES3::AIPackage::done);
				usertypeDefinition["isFinalized"] = sol::readonly_property(&TES3::AIPackage::finalized);
				usertypeDefinition["isMoving"] = sol::readonly_property(&TES3::AIPackage::moving);
				usertypeDefinition["isReset"] = sol::readonly_property(&TES3::AIPackage::reset);
				usertypeDefinition["isStarted"] = sol::readonly_property(&TES3::AIPackage::started);
				usertypeDefinition["targetPosition"] = sol::readonly_property(&TES3::AIPackage::targetPosition);
				usertypeDefinition["type"] = sol::readonly_property(&TES3::AIPackage::packageType);
			}
		}
	}
}

