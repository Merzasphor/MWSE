#include "LuaEvents.h"

#include "LuaManager.h"
#include "LuaUtil.h"

#include "TES3Actor.h"
#include "TES3ActorAnimationData.h"
#include "TES3Alchemy.h"
#include "TES3Cell.h"
#include "TES3MagicEffectInstance.h"
#include "TES3MagicSourceInstance.h"
#include "TES3MobilePlayer.h"
#include "TES3MobileProjectile.h"
#include "TES3Reference.h"
#include "TES3UIBlock.h"
#include "TES3Spell.h"
#include "TES3Weapon.h"
#include "TES3WorldController.h"

#include "UIUtil.h"

#include "Log.h"

namespace mwse {
	namespace lua {
		namespace event {
			sol::object trigger(const char* eventType, sol::table eventData, sol::object eventOptions) {
				sol::state& state = LuaManager::getInstance().getState();

				// Trigger the function, check for lua errors.
				sol::protected_function trigger = state["event"]["trigger"];
				auto result = trigger(eventType, eventData, eventOptions);
				if (!result.valid()) {
					sol::error error = result;
					log::getLog() << "Lua error encountered when raising " << eventType << " event:" << std::endl << error.what() << std::endl;
				}

				return result;
			}

			void clearObjectFilter(sol::object filterObject) {
				sol::state& state = LuaManager::getInstance().getState();
				sol::protected_function trigger = state["event"]["clear"];
				trigger(sol::nil, filterObject);
			}

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
			// Filtered event.
			//

			ObjectFilteredEvent::ObjectFilteredEvent(const char* name, TES3::BaseObject* filter) :
				GenericEvent(name),
				m_EventFilter(filter)
			{

			}

			sol::object ObjectFilteredEvent::getEventOptions() {
				sol::table options = LuaManager::getInstance().getState().create_table();
				options["filter"] = makeLuaObject(m_EventFilter);
				return options;
			}

			//
			// Equip event.
			//

			EquipEvent::EquipEvent(TES3::Reference* reference, TES3::BaseObject* item, TES3::ItemData* itemData) :
				ObjectFilteredEvent("equip", item),
				m_Reference(reference),
				m_Item(item),
				m_ItemData(itemData)
			{

			}

			sol::table EquipEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["reference"] = makeLuaObject(m_Reference);
				eventData["item"] = makeLuaObject(m_Item);
				eventData["itemData"] = m_ItemData;

				return eventData;
			}

			//
			// Equipped event. Called after something is equipped. Can be called from the
			// background thread.
			//

			EquippedEvent::EquippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id) :
				ObjectFilteredEvent("equipped", i),
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
					eventData["reference"] = makeLuaObject(m_MobileActor->reference);
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
				eventData["timestamp"] = tes3::getWorldController()->getHighPrecisionSimulationTimestamp();

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
				ObjectFilteredEvent("activate", target),
				m_Activator(activator),
				m_Target(target)
			{

			}

			sol::table ActivateEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["activator"] = makeLuaObject(m_Activator);
				eventData["target"] = makeLuaObject(m_Target);

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

			sol::object SaveGameEvent::getEventOptions() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table options = state.create_table();

				options["filter"] = m_FileName;

				return options;
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

			sol::object LoadGameEvent::getEventOptions() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table options = state.create_table();

				options["filter"] = m_FileName;

				return options;
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

			CellChangedEvent::CellChangedEvent(TES3::Cell* cell, TES3::Cell* previousCell) :
				ObjectFilteredEvent("cellChanged", cell),
				m_Cell(cell),
				m_PreviousCell(previousCell)
			{

			}

			sol::table CellChangedEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["cell"] = makeLuaObject(m_Cell);
				eventData["previousCell"] = makeLuaObject(m_PreviousCell);

				return eventData;
			}

			//
			// Combat start event.
			//

			CombatStartEvent::CombatStartEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target) :
				ObjectFilteredEvent("combatStart", mobileActor->reference),
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
				ObjectFilteredEvent("combatStarted", mobileActor->reference),
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
				ObjectFilteredEvent("combatStop", mobileActor->reference),
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
				ObjectFilteredEvent("combatStopped", mobileActor->reference),
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
				ObjectFilteredEvent("attack", animData->mobileActor->reference),
				m_AnimationData(animData)
			{

			}

			sol::table AttackEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["mobile"] = makeLuaObject(m_AnimationData->mobileActor);
				eventData["reference"] = makeLuaObject(m_AnimationData->mobileActor->reference);

				TES3::MobileActor* target = m_AnimationData->mobileActor->actionData.hitTarget;
				if (target) {
					eventData["targetMobile"] = makeLuaObject(target);
					eventData["targetReference"] = makeLuaObject(target->reference);
				}

				return eventData;
			}

			//
			// Generic collision event.
			//

			MobileObjectCollisionEvent::MobileObjectCollisionEvent(TES3::MobileObject* mobileObject, TES3::Reference* targetReference) :
				ObjectFilteredEvent("collision", mobileObject->reference),
				m_MobileObject(mobileObject),
				m_TargetReference(targetReference)
			{

			}

			sol::table MobileObjectCollisionEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["mobile"] = makeLuaObject(m_MobileObject);
				eventData["reference"] = makeLuaObject(m_MobileObject->reference);
				eventData["target"] = makeLuaObject(m_TargetReference);

				return eventData;
			}

			//
			// Collision event: MobileProjectile on actor
			//

			MobileProjectileActorCollisionEvent::MobileProjectileActorCollisionEvent(TES3::MobileProjectile* projectile, TES3::Reference* targetReference) :
				ObjectFilteredEvent("projectileHitActor", projectile->firingActor->reference),
				m_Projectile(projectile),
				m_TargetReference(targetReference)
			{

			}

			sol::table MobileProjectileActorCollisionEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["mobile"] = makeLuaObject(m_Projectile);
				eventData["target"] = makeLuaObject(m_TargetReference);

				// Give a shorthand to the firing reference.
				if (m_Projectile->firingActor && m_Projectile->firingActor->reference) {
					eventData["firingReference"] = makeLuaObject(m_Projectile->firingActor->reference);
				}

				// Also give a shorthand to the firing weapon.
				if (m_Projectile->firingWeapon) {
					eventData["firingWeapon"] = makeLuaObject(m_Projectile->firingWeapon);
				}


				return eventData;
			}

			//
			// Projectile expiration event.
			//

			ProjectileExpireEvent::ProjectileExpireEvent(TES3::MobileProjectile* projectile) :
				ObjectFilteredEvent("projectileExpire", NULL),
				m_Projectile(projectile)
			{
				// Make sure that we have a firing actor before putting it.
				if (m_Projectile->firingActor) {
					m_EventFilter = m_Projectile->firingActor->reference;
				}
			}

			sol::table ProjectileExpireEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["mobile"] = makeLuaObject(m_Projectile);

				// Give a shorthand to the firing reference.
				if (m_Projectile->firingActor && m_Projectile->firingActor->reference) {
					eventData["firingReference"] = makeLuaObject(m_Projectile->firingActor->reference);
				}

				// Also give a shorthand to the firing weapon.
				if (m_Projectile->firingWeapon) {
					eventData["firingWeapon"] = makeLuaObject(m_Projectile->firingWeapon);
				}

				return eventData;
			}

			//
			// Water impact event for projectiles.
			//

			MobileObjectWaterImpactEvent::MobileObjectWaterImpactEvent(TES3::MobileObject* mobileObject, bool inWater) :
				ObjectFilteredEvent("collideWater", mobileObject->reference),
				m_MobileObject(mobileObject),
				m_InWater(inWater)
			{

			}

			sol::table MobileObjectWaterImpactEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["mobile"] = makeLuaObject(m_MobileObject);
				eventData["inWater"] = m_InWater;

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

			//
			// Show rest/wait menu event.
			//

			ShowRestWaitMenuEvent::ShowRestWaitMenuEvent(bool allowRest, bool scripted) :
				GenericEvent("uiShowRestMenu"),
				m_AllowRest(allowRest),
				m_Scripted(scripted)
			{

			}

			sol::table ShowRestWaitMenuEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["allowRest"] = m_AllowRest;
				eventData["scripted"] = m_Scripted;

				return eventData;
			}

			//
			// Key event.
			//

			KeyEvent::KeyEvent(int keyCode, bool pressed, bool controlDown, bool shiftDown, bool altDown, bool superDown) :
				GenericEvent("key"),
				m_KeyCode(keyCode),
				m_Pressed(pressed),
				m_ControlDown(controlDown),
				m_ShiftDown(shiftDown),
				m_AltDown(altDown),
				m_SuperDown(superDown)
			{

			}

			sol::table KeyEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["keyCode"] = m_KeyCode;
				eventData["pressed"] = m_Pressed;
				eventData["isControlDown"] = m_ControlDown;
				eventData["isShiftDown"] = m_ShiftDown;
				eventData["isAltDown"] = m_AltDown;
				eventData["isSuperDown"] = m_SuperDown;

				return eventData;
			}

			sol::object KeyEvent::getEventOptions() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table options = state.create_table();

				options["filter"] = m_KeyCode;

				return options;
			}

			//
			// Key down event.
			//

			KeyDownEvent::KeyDownEvent(int keyCode, bool controlDown, bool shiftDown, bool altDown, bool superDown) :
				KeyEvent(keyCode, true, controlDown, shiftDown, altDown, superDown)
			{
				m_EventName = "keyDown";
			}

			//
			// Key up event.
			//

			KeyUpEvent::KeyUpEvent(int keyCode, bool controlDown, bool shiftDown, bool altDown, bool superDown) :
				KeyEvent(keyCode, false, controlDown, shiftDown, altDown, superDown)
			{
				m_EventName = "keyUp";
			}

			//
			// Death event.
			//

			DeathEvent::DeathEvent(TES3::MobileActor* mobileActor) :
				ObjectFilteredEvent("death", mobileActor->reference),
				m_MobileActor(mobileActor)
			{

			}

			sol::table DeathEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["mobile"] = makeLuaObject(m_MobileActor);
				eventData["reference"] = makeLuaObject(m_MobileActor->reference);

				return eventData;
			}

			//
			// Damage event.
			//

			DamageEvent::DamageEvent(TES3::MobileActor* mobileActor, float damage) :
				ObjectFilteredEvent("damage", mobileActor->reference),
				m_MobileActor(mobileActor),
				m_Damage(damage)
			{

			}

			sol::table DamageEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["mobile"] = makeLuaObject(m_MobileActor);
				eventData["reference"] = makeLuaObject(m_MobileActor->reference);
				eventData["damage"] = m_Damage;

				return eventData;
			}

			//
			// Damaged event.
			//

			DamagedEvent::DamagedEvent(TES3::MobileActor* mobileActor, float damage) :
				ObjectFilteredEvent("damaged", mobileActor->reference),
				m_MobileActor(mobileActor),
				m_Damage(damage)
			{

			}

			sol::table DamagedEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["mobile"] = makeLuaObject(m_MobileActor);
				eventData["reference"] = makeLuaObject(m_MobileActor->reference);
				eventData["damage"] = m_Damage;

				return eventData;
			}

			//
			// Exercise skill event.
			//

			SkillExerciseEvent::SkillExerciseEvent(int skillId, float progress) :
				GenericEvent("exerciseSkill"),
				m_Skill(skillId),
				m_Progress(progress)
			{

			}

			sol::table SkillExerciseEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["skill"] = m_Skill;
				eventData["progress"] = m_Progress;

				return eventData;
			}

			sol::object SkillExerciseEvent::getEventOptions() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table options = state.create_table();

				options["filter"] = m_Skill;

				return options;
			}

			//
			// Level up event.
			//

			LevelUpEvent::LevelUpEvent() :
				GenericEvent("levelUp")
			{

			}

			sol::table LevelUpEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				TES3::MobilePlayer* player = tes3::getWorldController()->getMobilePlayer();

				eventData["level"] = player->reference->baseObject->getLevel();

				return eventData;
			}

			sol::object LevelUpEvent::getEventOptions() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table options = state.create_table();

				TES3::MobilePlayer* player = tes3::getWorldController()->getMobilePlayer();

				options["filter"] = player->reference->baseObject->getLevel();

				return options;
			}

			//
			// Spell tick event.
			//

			SpellTickEvent::SpellTickEvent(TES3::MagicSourceInstance * spellInstance, float deltaTime, TES3::MagicEffectInstance * effectInstance, int effectIndex, bool negateOnExpiry, int isUncapped, TES3::Statistic * statistic, void * attributeTypeInfo, int resistAttribute, bool(__cdecl *resistanceTestFunction)(void *, void *, int)) :
				GenericEvent("spellTick"),
				m_MagicSourceInstance(spellInstance),
				m_DeltaTime(deltaTime),
				m_EffectInstance(effectInstance),
				m_EffectIndex(effectIndex),
				m_NegateOnExpiry(negateOnExpiry),
				m_IsUncapped(isUncapped),
				m_Statistic(statistic),
				m_AttributeTypeInfo(attributeTypeInfo),
				m_ResistAttribute(resistAttribute),
				m_ResistanceTestFunction(resistanceTestFunction)
			{

			}

			sol::table SpellTickEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["caster"] = makeLuaObject(m_MagicSourceInstance->caster);
				eventData["target"] = makeLuaObject(m_EffectInstance->target);

				eventData["source"] = makeLuaObject(m_MagicSourceInstance->sourceCombo.source.asGeneric);
				eventData["sourceInstance"] = makeLuaObject(m_MagicSourceInstance);
				eventData["deltaTime"] = m_DeltaTime;
				eventData["effectIndex"] = m_EffectIndex;
				eventData["effectInstance"] = m_EffectInstance;
				eventData["negateOnExpiry"] = m_NegateOnExpiry;
				eventData["isUncapped"] = m_IsUncapped;
				eventData["statistic"] = m_Statistic;
				eventData["attributeTypeInfo"] = m_AttributeTypeInfo;
				eventData["resistAttribute"] = m_ResistAttribute;
				eventData["resistanceTestFunction"] = m_ResistanceTestFunction;

				// Get the specific effect on the source.
				TES3::Effect * effects = m_MagicSourceInstance->sourceCombo.getSourceEffects();
				if (effects) {
					eventData["effect"] = effects[m_EffectIndex];
				}

				return eventData;
			}

			sol::object SpellTickEvent::getEventOptions() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table options = state.create_table();

				options["filter"] = makeLuaObject(m_MagicSourceInstance->sourceCombo.source.asGeneric);

				return options;
			}

			//
			// Spell resist event.
			//

			SpellResistEvent::SpellResistEvent(TES3::MagicSourceInstance * spellInstance, TES3::MagicEffectInstance * effectInstance, int effectIndex, int resistAttribute) :
				GenericEvent("spellResist"),
				m_MagicSourceInstance(spellInstance),
				m_EffectInstance(effectInstance),
				m_EffectIndex(effectIndex),
				m_ResistAttribute(resistAttribute)
			{

			}

			sol::table SpellResistEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["caster"] = makeLuaObject(m_MagicSourceInstance->caster);
				eventData["target"] = makeLuaObject(m_EffectInstance->target);
				eventData["resistedPercent"] = m_EffectInstance->resistedPercent;

				eventData["source"] = makeLuaObject(m_MagicSourceInstance->sourceCombo.source.asGeneric);
				eventData["sourceInstance"] = makeLuaObject(m_MagicSourceInstance);
				eventData["effectIndex"] = m_EffectIndex;
				eventData["effectInstance"] = m_EffectInstance;
				eventData["resistAttribute"] = m_ResistAttribute;

				// Get the specific effect on the source.
				TES3::Effect * effects = m_MagicSourceInstance->sourceCombo.getSourceEffects();
				if (effects) {
					eventData["effect"] = effects[m_EffectIndex];
				}

				// Get cast chance if it's a spell.
				if (m_MagicSourceInstance->sourceCombo.sourceType == TES3::MagicSourceType::Spell || m_MagicSourceInstance->sourceCombo.sourceType == TES3::MagicSourceType::Enchantment) {
					eventData["spellCastChance"] = m_MagicSourceInstance->sourceCombo.source.asSpell->calculateCastChance(m_MagicSourceInstance->caster);
				}
				
				return eventData;
			}

			sol::object SpellResistEvent::getEventOptions() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table options = state.create_table();

				options["filter"] = makeLuaObject(m_MagicSourceInstance->sourceCombo.source.asGeneric);

				return options;
			}

			//
			// Potion brewed event.
			//

			PotionBrewedEvent::PotionBrewedEvent(TES3::Alchemy * object) :
				GenericEvent("potionBrewed"),
				m_Object(object)
			{

			}

			sol::table PotionBrewedEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["object"] = makeLuaObject(m_Object);

				return eventData;
			}

			//
			// Menu mode change event.
			//

			MenuStateEvent::MenuStateEvent(bool inMenuMode) :
				m_InMenuMode(inMenuMode)
			{

			}

			const char* MenuStateEvent::getEventName() {
				if (m_InMenuMode) {
					return "menuEnter";
				}
				else {
					return "menuExit";
				}
			}

			sol::table MenuStateEvent::createEventTable() {
				sol::state& state = LuaManager::getInstance().getState();
				sol::table eventData = state.create_table();

				eventData["menuMode"] = m_InMenuMode;
				if (m_InMenuMode) {
					TES3::UI::Block * top = tes3::ui::getTopMenu();
					eventData["menu"] = top;
				}

				return eventData;
			}

		}
	}
}
