#include "TES3WorldController.h"

#include "TES3Actor.h"
#include "TES3GlobalVariable.h"
#include "TES3MobilePlayer.h"
#include "TES3Reference.h"

#include "TES3Util.h"

#define TES3_WorldController_mainLoopBeforeInput 0x40F610
#define TES3_WorldController_getMobilePlayer 0x40FF20
#define TES3_WorldController_playItemUpDownSound 0x411050
#define TES3_WorldController_getSimulationTimestamp 0x411000

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

	unsigned short WorldController::getDaysInMonth(int month) {
		return reinterpret_cast<unsigned short*>(TES3_Data_cumulativeDaysForMonth)[month];
	}

	double WorldController::getHighPrecisionSimulationTimestamp() {
		return (gvarYear->value * 365.0 + getDaysInMonth((int)gvarMonth->value) + gvarDay->value) * 24.0 + gvarGameHour->value;
	}

	const auto TES3_WorldController_applyEnchantEffect = reinterpret_cast<bool(__thiscall*)(WorldController*, NI::Node*, Enchantment*)>(0x410B00);
	bool WorldController::applyEnchantEffect(NI::Node* node, Enchantment * enchantment) {
		return TES3_WorldController_applyEnchantEffect(this, node, enchantment);
	}

	const auto TES3_WorldController_updateTiming = reinterpret_cast<void(__thiscall*)(WorldController*)>(0x453610);
	void WorldController::updateTiming() {
		TES3_WorldController_updateTiming(this);
	}


}
