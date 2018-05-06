#include "LuaEvents.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3ActorAnimationData.h"
#include "TES3UIBlock.h"

namespace mwse {
	namespace lua {

		//
		// Generic event. Delivers no real payload and contains a dynamic name.
		//

		GenericEvent::GenericEvent(const char* name) :
			m_EventName(name)
		{

		}

		const char* GenericEvent::getEventName() {
			return m_EventName;
		}

		//
		// Equip event.
		//

		EquipEvent::EquipEvent(TES3::Reference* reference, TES3::BaseObject* item, TES3::ItemData* itemData) :
			GenericEvent("equip"),
			m_Reference(reference),
			m_Item(item),
			m_ItemData(itemData)
		{

		}

		sol::table EquipEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["reference"] = m_Reference;
			eventData["item"] = makeLuaObject(m_Item);
			eventData["itemData"] = m_ItemData;

			return eventData;
		}

		//
		// Equipped event. Called after something is equipped. Can be called from the
		// background thread.
		//

		EquippedEvent::EquippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id) :
			GenericEvent("equipped"),
			m_Actor(a),
			m_MobileActor(ma),
			m_Item(i),
			m_ItemData(id)
		{

		}

		sol::table EquippedEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["actor"] = makeLuaObject(m_Actor);
			if (m_MobileActor) {
				eventData["reference"] = m_MobileActor->reference;
			}
			eventData["item"] = makeLuaObject(m_Item);
			eventData["itemData"] = m_ItemData;

			return eventData;
		}

		//
		// Unequipped event. Same as the equipped event with a different name.
		//

		UnequippedEvent::UnequippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id) :
			EquippedEvent(a, ma, i, id)
		{
			m_EventName = "unequipped";
		}

		//
		// Simulate event.
		//

		SimulateEvent::SimulateEvent(float delta) :
			GenericEvent("simulate"),
			m_Delta(delta)
		{

		}

		sol::table SimulateEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["delta"] = m_Delta;

			return eventData;
		}

		//
		// Enter frame event.
		//

		FrameEvent::FrameEvent(float delta, bool menuMode) :
			SimulateEvent(delta),
			m_MenuMode(menuMode)
		{
			m_EventName = "enterFrame";
		}

		sol::table FrameEvent::createEventTable() {
			sol::table eventData = SimulateEvent::createEventTable();
			eventData["menuMode"] = m_MenuMode;
			return eventData;
		}

		//
		// Button pressed event.
		//

		ButtonPressedEvent::ButtonPressedEvent(int buttonId) :
			GenericEvent("buttonPressed"),
			m_ButtonId(buttonId)
		{

		}

		sol::table ButtonPressedEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["button"] = m_ButtonId;

			return eventData;
		}

		//
		// Activate event.
		//

		ActivateEvent::ActivateEvent(TES3::Reference* activator, TES3::Reference* target) :
			GenericEvent("activate"),
			m_Activator(activator),
			m_Target(target)
		{

		}

		sol::table ActivateEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["activator"] = m_Activator;
			eventData["target"] = m_Target;

			return eventData;
		}

		//
		// Save game event.
		//

		SaveGameEvent::SaveGameEvent(const char* saveName, const char* fileName) :
			GenericEvent("save"),
			m_SaveName(saveName),
			m_FileName(fileName)
		{

		}

		sol::table SaveGameEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["name"] = m_SaveName;
			eventData["filename"] = m_FileName;

			return eventData;
		}

		//
		// Saved game event.
		//

		SavedGameEvent::SavedGameEvent(const char* saveName, const char* fileName) :
			SaveGameEvent(saveName, fileName)
		{
			m_EventName = "saved";
		}

		//
		// Load game event.
		//

		LoadGameEvent::LoadGameEvent(const char* fileName, bool quickLoad, bool newGame) :
			GenericEvent("load"),
			m_FileName(fileName),
			m_QuickLoad(quickLoad),
			m_NewGame(newGame)
		{
			if (m_FileName == NULL && !m_NewGame) {
				m_QuickLoad = true;
				m_FileName = "quiksave.ess";
			}
		}

		sol::table LoadGameEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			if (m_NewGame) {
				eventData["newGame"] = true;
				eventData["quickload"] = false;
			}
			else {
				std::string filename = m_FileName;
				eventData["filename"] = filename.substr(0, filename.find_last_of('.'));;
				eventData["quickload"] = m_QuickLoad;
				eventData["newGame"] = false;
			}

			return eventData;
		}

		//
		// Loaded game event.
		//

		LoadedGameEvent::LoadedGameEvent(const char* fileName, bool quickLoad, bool newGame) :
			LoadGameEvent(fileName, quickLoad, newGame)
		{
			m_EventName = "loaded";
		}

		//
		// Cell change event.
		//

		CellChangedEvent::CellChangedEvent(TES3::Cell* cell, float x, float y, float z) :
			GenericEvent("cellChanged"),
			m_Cell(cell),
			m_X(x),
			m_Y(y),
			m_Z(z)
		{

		}

		sol::table CellChangedEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["cell"] = m_Cell;
			eventData["x"] = m_X;
			eventData["y"] = m_Y;
			eventData["z"] = m_Z;

			return eventData;
		}

		//
		// Combat start event.
		//

		CombatStartEvent::CombatStartEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target) :
			GenericEvent("combatStart"),
			m_MobileActor(mobileActor),
			m_Target(target)
		{

		}

		sol::table CombatStartEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["actor"] = makeLuaObject(m_MobileActor);
			eventData["target"] = makeLuaObject(m_Target);

			return eventData;
		}

		//
		// Combat started event.
		//

		CombatStartedEvent::CombatStartedEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target) :
			GenericEvent("combatStarted"),
			m_MobileActor(mobileActor),
			m_Target(target)
		{

		}

		sol::table CombatStartedEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["actor"] = makeLuaObject(m_MobileActor);
			eventData["target"] = makeLuaObject(m_Target);

			return eventData;
		}

		//
		// Combat stop event.
		//

		CombatStopEvent::CombatStopEvent(TES3::MobileActor* mobileActor) :
			GenericEvent("combatStop"),
			m_MobileActor(mobileActor)
		{

		}

		sol::table CombatStopEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["actor"] = makeLuaObject(m_MobileActor);

			return eventData;
		}

		//
		// Combat stopped event.
		//

		CombatStoppedEvent::CombatStoppedEvent(TES3::MobileActor* mobileActor) :
			GenericEvent("combatStopped"),
			m_MobileActor(mobileActor)
		{

		}

		sol::table CombatStoppedEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["actor"] = makeLuaObject(m_MobileActor);

			return eventData;
		}
		
		//
		// Attack event.
		//

		AttackEvent::AttackEvent(TES3::ActorAnimationData* animData) :
			GenericEvent("attack"),
			m_AnimationData(animData)
		{

		}

		sol::table AttackEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["actor"] = makeLuaObject(m_AnimationData->mobileActor);

			return eventData;
		}

		//
		// Hit event, but for projectiles.
		//

		ProjectileHitEvent::ProjectileHitEvent(TES3::MobileProjectile* projectile, TES3::Reference* targetReference) :
			GenericEvent("hit"),
			m_MobileProjectile(projectile),
			m_TargetReference(targetReference)
		{

		}

		sol::table ProjectileHitEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["attacker"] = m_MobileProjectile->firingActor->reference;
			eventData["target"] = m_TargetReference;
			eventData["weapon"] = m_MobileProjectile->firingWeapon;
			eventData["projectile"] = m_MobileProjectile;

			return eventData;
		}

		//
		// General UI pre-events.
		//

		GenericUiPreEvent::GenericUiPreEvent(TES3::UI::Block* parent, TES3::UI::Block* block, unsigned int prop, unsigned int var1, unsigned int var2) :
			GenericEvent("uiPreEvent"),
			m_Parent(parent),
			m_Block(block),
			m_Property(prop),
			m_Variable1(var1),
			m_Variable2(var2)
		{

		}

		sol::table GenericUiPreEvent::createEventTable() {
			sol::state& state = LuaManager::getInstance().getState();
			sol::table eventData = state.create_table();

			eventData["parent"] = m_Parent;
			eventData["block"] = m_Block;
			eventData["property"] = m_Property;
			eventData["var1"] = m_Variable1;
			eventData["var2"] = m_Variable2;

			return eventData;
		}

		//
		// General UI post-events.
		//

		GenericUiPostEvent::GenericUiPostEvent(TES3::UI::Block* parent, TES3::UI::Block* block, unsigned int prop, unsigned int var1, unsigned int var2) :
			GenericUiPreEvent(parent, block, prop, var1, var2)
		{
			m_EventName = "uiEvent";
		}

	}
}
