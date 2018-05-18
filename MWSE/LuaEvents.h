#pragma once

#include "LuaUnifiedHeader.h"

namespace mwse {
	namespace lua {
		namespace event {
			sol::object trigger(const char* eventType, sol::table eventData = sol::nil, sol::object eventFilter = sol::nil);

			class BaseEvent {
			public:
				virtual const char* getEventName() { return NULL; };
				virtual sol::table createEventTable() { return sol::nil; };
				virtual sol::object getEventOptions() { return sol::nil; }
			};

			// ---------------------------------------------------------------------------- //

			class GenericEvent : public BaseEvent {
			public:
				GenericEvent(const char* name);
				const char* getEventName();

			protected:
				const char* m_EventName;
			};

			// ---------------------------------------------------------------------------- //

			class ObjectFilteredEvent : public GenericEvent {
			public:
				ObjectFilteredEvent(const char* name, sol::object filter);
				sol::object getEventOptions();

			protected:
				sol::object m_EventFilter;
			};

			// ---------------------------------------------------------------------------- //

			class EquipEvent : public ObjectFilteredEvent {
			public:
				EquipEvent(TES3::Reference* reference, TES3::BaseObject* item, TES3::ItemData* itemData);
				sol::table createEventTable();

			protected:
				TES3::Reference* m_Reference;
				TES3::BaseObject* m_Item;
				TES3::ItemData* m_ItemData;
			};

			// ---------------------------------------------------------------------------- //

			class EquippedEvent : public ObjectFilteredEvent {
			public:
				EquippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id);
				sol::table createEventTable();

			protected:
				TES3::Actor* m_Actor;
				TES3::MobileActor* m_MobileActor;
				TES3::BaseObject* m_Item;
				TES3::ItemData* m_ItemData;
			};

			// ---------------------------------------------------------------------------- //

			class UnequippedEvent : public EquippedEvent {
			public:
				UnequippedEvent(TES3::Actor* a, TES3::MobileActor* ma, TES3::BaseObject* i, TES3::ItemData* id);
			};

			// ---------------------------------------------------------------------------- //

			class SimulateEvent : public GenericEvent {
			public:
				SimulateEvent(float delta);
				sol::table createEventTable();

			protected:
				float m_Delta;
			};

			// ---------------------------------------------------------------------------- //

			class FrameEvent : public SimulateEvent {
			public:
				FrameEvent(float delta, bool menuMode);
				sol::table createEventTable();

			protected:
				bool m_MenuMode;
			};

			// ---------------------------------------------------------------------------- //

			class ButtonPressedEvent : public GenericEvent {
			public:
				ButtonPressedEvent(int buttonId);
				sol::table createEventTable();

			protected:
				int m_ButtonId;
			};

			// ---------------------------------------------------------------------------- //

			class ActivateEvent : public ObjectFilteredEvent {
			public:
				ActivateEvent(TES3::Reference* activator, TES3::Reference* target);
				sol::table createEventTable();

			protected:
				TES3::Reference* m_Activator;
				TES3::Reference* m_Target;
			};

			// ---------------------------------------------------------------------------- //

			class SaveGameEvent : public GenericEvent {
			public:
				SaveGameEvent(const char* saveName, const char* fileName);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				const char* m_SaveName;
				const char* m_FileName;
			};

			// ---------------------------------------------------------------------------- //

			class SavedGameEvent : public SaveGameEvent {
			public:
				SavedGameEvent(const char* saveName, const char* fileName);
			};

			// ---------------------------------------------------------------------------- //

			class LoadGameEvent : public GenericEvent {
			public:
				LoadGameEvent(const char* fileName, bool quickLoad = false, bool newGame = false);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				const char* m_FileName;
				bool m_QuickLoad;
				bool m_NewGame;
			};

			// ---------------------------------------------------------------------------- //

			class LoadedGameEvent : public LoadGameEvent {
			public:
				LoadedGameEvent(const char* fileName, bool quickLoad = false, bool newGame = false);
			};

			// ---------------------------------------------------------------------------- //

			class CellChangedEvent : public ObjectFilteredEvent {
			public:
				CellChangedEvent(TES3::Cell* cell, float x, float y, float z);
				sol::table createEventTable();

			protected:
				TES3::Cell* m_Cell;
				float m_X;
				float m_Y;
				float m_Z;
			};

			// ---------------------------------------------------------------------------- //

			class CombatStartEvent : public ObjectFilteredEvent {
			public:
				CombatStartEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				TES3::MobileActor* m_Target;
			};

			// ---------------------------------------------------------------------------- //

			class CombatStartedEvent : public ObjectFilteredEvent {
			public:
				CombatStartedEvent(TES3::MobileActor* mobileActor, TES3::MobileActor* target);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
				TES3::MobileActor* m_Target;
			};

			// ---------------------------------------------------------------------------- //

			class CombatStopEvent : public ObjectFilteredEvent {
			public:
				CombatStopEvent(TES3::MobileActor* mobileActor);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
			};

			// ---------------------------------------------------------------------------- //

			class CombatStoppedEvent : public ObjectFilteredEvent {
			public:
				CombatStoppedEvent(TES3::MobileActor* mobileActor);
				sol::table createEventTable();

			protected:
				TES3::MobileActor* m_MobileActor;
			};

			// ---------------------------------------------------------------------------- //

			class AttackEvent : public ObjectFilteredEvent {
			public:
				AttackEvent(TES3::ActorAnimationData* animData);
				sol::table createEventTable();

			protected:
				TES3::ActorAnimationData* m_AnimationData;
			};

			// ---------------------------------------------------------------------------- //

			class MobileObjectActorCollisionEvent : public ObjectFilteredEvent {
			public:
				MobileObjectActorCollisionEvent(TES3::MobileObject* mobileObject, TES3::Reference* targetReference);
				sol::table createEventTable();

			protected:
				TES3::MobileObject* m_MobileObject;
				TES3::Reference* m_TargetReference;
			};

			// ---------------------------------------------------------------------------- //

			class MobileObjectWaterImpactEvent : public ObjectFilteredEvent {
			public:
				MobileObjectWaterImpactEvent(TES3::MobileObject* mobileObject, bool inWater);
				sol::table createEventTable();

			protected:
				TES3::MobileObject* m_MobileObject;
				bool m_InWater;
			};

			// ---------------------------------------------------------------------------- //

			class GenericUiPreEvent : public GenericEvent {
			public:
				GenericUiPreEvent(TES3::UI::Block* parent, TES3::UI::Block* block, unsigned int prop, unsigned int var1, unsigned int var2);
				sol::table createEventTable();

			protected:
				TES3::UI::Block* m_Parent;
				TES3::UI::Block* m_Block;
				unsigned int m_Property;
				unsigned int m_Variable1;
				unsigned int m_Variable2;
			};

			// ---------------------------------------------------------------------------- //

			class GenericUiPostEvent : public GenericUiPreEvent {
			public:
				GenericUiPostEvent(TES3::UI::Block* parent, TES3::UI::Block* block, unsigned int prop, unsigned int var1, unsigned int var2);
			};

			// ---------------------------------------------------------------------------- //

			class ShowRestWaitMenuEvent : public GenericEvent {
			public:
				ShowRestWaitMenuEvent(bool allowRest, bool scripted);
				sol::table createEventTable();

			protected:
				bool m_AllowRest;
				bool m_Scripted;
			};

			// ---------------------------------------------------------------------------- //

			class KeyEvent : public GenericEvent {
			public:
				KeyEvent(int keyCode, bool pressed, bool controlDown, bool shiftDown, bool altDown, bool superDown);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				int m_KeyCode;
				bool m_Pressed;
				bool m_ControlDown;
				bool m_ShiftDown;
				bool m_AltDown;
				bool m_SuperDown;
			};

			// ---------------------------------------------------------------------------- //

			class DeathEvent : public ObjectFilteredEvent {
			public:
				DeathEvent(TES3::MobileActor* mobileActor);
				sol::table createEventTable();

			protected:
				TES3::MobileActor * m_MobileActor;
			};

			// ---------------------------------------------------------------------------- //

			class DamageEvent : public ObjectFilteredEvent {
			public:
				DamageEvent(TES3::MobileActor* mobileActor, float damage);
				sol::table createEventTable();

			protected:
				TES3::MobileActor * m_MobileActor;
				float m_Damage;
			};

			// ---------------------------------------------------------------------------- //

			class DamagedEvent : public ObjectFilteredEvent {
			public:
				DamagedEvent(TES3::MobileActor* mobileActor, float damage);
				sol::table createEventTable();

			protected:
				TES3::MobileActor * m_MobileActor;
				float m_Damage;
			};

			// ---------------------------------------------------------------------------- //

			class SkillExerciseEvent : public GenericEvent {
			public:
				SkillExerciseEvent(int skillId, float progress);
				sol::table createEventTable();
				sol::object getEventOptions();

			protected:
				int m_Skill;
				float m_Progress;
			};
		}
	}
}
