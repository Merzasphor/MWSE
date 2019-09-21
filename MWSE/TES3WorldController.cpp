#include "TES3WorldController.h"

#include "TES3Actor.h"
#include "TES3DataHandler.h"
#include "TES3GameSetting.h"
#include "TES3GlobalVariable.h"
#include "TES3MobilePlayer.h"
#include "TES3Reference.h"
#include "TES3WeatherController.h"

#include "TES3Util.h"

#define TES3_WorldController_mainLoopBeforeInput 0x40F610
#define TES3_WorldController_getMobilePlayer 0x40FF20
#define TES3_WorldController_playItemUpDownSound 0x411050
#define TES3_WorldController_getSimulationTimestamp 0x411000

#define TES3_Data_daysInMonth 0x775E40
#define TES3_Data_cumulativeDaysForMonth 0x775E58

namespace TES3 {

	//
	// KillCounter
	//

	void KillCounter::increment(MobileActor * mobile) {
		TES3::Actor * actor = static_cast<TES3::Actor*>(mobile->reference->baseObject)->getBaseActor();

		// Is this actor already in the collection?
		KillCounter::Node * node = nullptr;
		auto itt = killedActors->head;
		while (itt) {
			if (itt->data->actor == actor) {
				node = itt->data;
				break;
			}

			itt = itt->next;
		}

		// If it isn't in the collection, create a new node and add it.
		if (node == nullptr) {
			node = mwse::tes3::_new<KillCounter::Node>();
			node->count = 0;
			node->actor = actor;
			killedActors->addItem(node);
		}

		// Increment kills for this actor and total kills.
		node->count++;
		totalKills++;

		// Increment werewolf kills if the player is wolfing out.
		if (mobile->actorType == TES3::MobileActorType::NPC && TES3::WorldController::get()->getMobilePlayer()->getMobileActorFlag(TES3::MobileActorFlag::Werewolf)) {
			werewolfKills++;
		}

		// TODO: Add back in console logging.
	}

	int KillCounter::getKillCount(Actor * actor) {
		auto node = killedActors->head;
		while (node) {
			if (node->data->actor == actor) {
				return node->data->count;
			}

			node = node->next;
		}

		return 0;
	}

	//
	// InventoryData
	//

	const auto TES3_InventoryData_ClearIcons = reinterpret_cast<void(__thiscall*)(InventoryData *, int)>(0x632270);
	void InventoryData::clearIcons(int type) {
		TES3_InventoryData_ClearIcons(this, type);
	}

	const auto TES3_InventoryData_AddInventoryItems = reinterpret_cast<void(__thiscall*)(InventoryData *, Inventory *, int)>(0x633510);
	void InventoryData::addInventoryItems(Inventory * inventory, int type) {
		TES3_InventoryData_AddInventoryItems(this, inventory, type);
	}

	//
	// WorldController
	//

	WorldController * WorldController::get() {
		return *reinterpret_cast<TES3::WorldController**>(0x7C67DC);
	}

	void WorldController::mainLoopBeforeInput() {
		reinterpret_cast<void(__thiscall *)(WorldController*)>(TES3_WorldController_mainLoopBeforeInput)(this);
	}

	MobilePlayer* WorldController::getMobilePlayer() {
		return reinterpret_cast<MobilePlayer*(__thiscall *)(WorldController*)>(TES3_WorldController_getMobilePlayer)(this);
	}

	void WorldController::playItemUpDownSound(BaseObject* item, bool pickup, Reference* reference) {
		reinterpret_cast<void(__thiscall *)(WorldController*, BaseObject*, int, Reference*)>(TES3_WorldController_playItemUpDownSound)(this, item, pickup, reference);
	}

	float WorldController::getSimulationTimestamp() {
		return reinterpret_cast<float(__thiscall *)(WorldController*)>(TES3_WorldController_getSimulationTimestamp)(this);
	}

	const auto TES3_WorldController_processGlobalScripts = reinterpret_cast<void(__thiscall*)(WorldController*)>(0x40FBE0);
	void WorldController::processGlobalScripts() {
		TES3_WorldController_processGlobalScripts(this);
	}

	unsigned short WorldController::getDaysInMonth(int month) {
		if (month < 0 || month > 11) {
			return -1;
		}
		return reinterpret_cast<unsigned short*>(TES3_Data_daysInMonth)[month];
	}

	unsigned short WorldController::getCumulativeDaysForMonth(int month) {
		if (month < 0 || month > 11) {
			return -1;
		}
		return reinterpret_cast<unsigned short*>(TES3_Data_cumulativeDaysForMonth)[month];
	}

	double WorldController::getHighPrecisionSimulationTimestamp() {
		return (gvarYear->value * 365.0 + getCumulativeDaysForMonth((int)gvarMonth->value) + gvarDay->value) * 24.0 + gvarGameHour->value;
	}

	const auto TES3_WorldController_applyEnchantEffect = reinterpret_cast<bool(__thiscall*)(WorldController*, NI::Node*, Enchantment*)>(0x410B00);
	bool WorldController::applyEnchantEffect(NI::Node* node, Enchantment * enchantment) {
		return TES3_WorldController_applyEnchantEffect(this, node, enchantment);
	}

	const auto TES3_WorldController_updateTiming = reinterpret_cast<void(__thiscall*)(WorldController*)>(0x453610);
	void WorldController::updateTiming() {
		TES3_WorldController_updateTiming(this);
	}

	const auto TES3_WorldController_updateEnvironmentLightingWeather = reinterpret_cast<void(__thiscall*)(WorldController*)>(0x4100D0);
	void WorldController::updateEnvironmentLightingWeather() {
		TES3_WorldController_updateEnvironmentLightingWeather(this);
	}

	void WorldController::tickClock() {
		gvarGameHour->value += (deltaTime * gvarTimescale->value) / 3600.0f;
		checkForDayWrapping();
	}

	void WorldController::checkForDayWrapping() {
		// Make sure we didn't somehow move backwards.
		if (gvarGameHour->value < 0.0f) {
			gvarGameHour->value = 0.0f;
			return;
		}
		// If we're not at midnight yet, we don't need to tick over.
		else if (gvarGameHour->value < 24.0f) {
			return;
		}

		// Keep decrementing 24 hours until we've caught up.
		auto ndd = TES3::DataHandler::get()->nonDynamicData;
		bool respawnContainers = false;
		while (gvarGameHour->value >= 24.0f) {
			// Drop these values to integers to be later set back to the global values.
			int day = gvarDay->value;
			int daysPassed = gvarDaysPassed->value;
			int month = gvarMonth->value;
			int year = gvarYear->value;

			// Increment day count, reduce game hour by 24.
			day++;
			daysPassed++;
			gvarGameHour->value -= 24.0f;

			// Tell the weather controller that a day has passed.
			weatherController->daysRemaining--;
			if (weatherController->daysRemaining < 0) {
				weatherController->daysRemaining = 0;
			}

			// Are we advancing to the next month?
			int daysInMonth = getDaysInMonth(month);
			if (day > daysInMonth) {
				day = 1;
				month++;

				// Do we need to respawn containers?
				int monthsToRespawn = --gvarMonthsToRespawn->value;
				if (monthsToRespawn <= 0) {
					respawnContainers = true;
					gvarMonthsToRespawn->value = ndd->GMSTs[TES3::GMST::iMonthsToRespawn]->value.asLong;
				}
				else {
					gvarMonthsToRespawn->value = monthsToRespawn;
				}
			}

			// The next year?
			if (month >= 12) {
				month = 0;
				year++;
			}

			// Update global variables.
			gvarDay->value = day;
			gvarDaysPassed->value = daysPassed;
			gvarMonth->value = month;
			gvarYear->value = year;
		}

		if (respawnContainers) {
			ndd->respawnContainers();
		}
	}
}
