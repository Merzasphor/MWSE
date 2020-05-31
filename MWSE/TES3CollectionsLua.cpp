#include "TES3CollectionsLua.h"

#include "LuaUtil.h"
#include "LuaManager.h"

#include "TES3Attachment.h"
#include "TES3Birthsign.h"
#include "TES3Cell.h"
#include "TES3Dialogue.h"
#include "TES3DialogueInfo.h"
#include "TES3GlobalVariable.h"
#include "TES3Inventory.h"
#include "TES3Item.h"
#include "TES3ItemData.h"
#include "TES3Faction.h"
#include "TES3LeveledList.h"
#include "TES3MobileActor.h"
#include "TES3Quest.h"
#include "TES3Reference.h"
#include "TES3Region.h"
#include "TES3Spell.h"

#include "NIPick.h"
#include "NIProperty.h"

namespace mwse {
	namespace lua {
		std::tuple<sol::object, sol::object> bindGenericObjectIterator_pairsNext(sol::user<Iterator_state<TES3::BaseObject>&> user_it_state, sol::this_state l) {
			Iterator_state<TES3::BaseObject>& it_state = user_it_state;
			if (it_state.it == nullptr) {
				return std::make_tuple(sol::object(sol::lua_nil), sol::object(sol::lua_nil));
			}

			auto values = std::make_tuple(sol::object(l, sol::in_place, it_state.it), makeLuaObject(it_state.it->data));
			it_state.it = it_state.it->next;
			return values;
		}

		std::tuple<sol::object, sol::object> bindGenericObjectStlList_pairsNext(sol::user<GenericObjectStlList_iteratorState&> user_it_state, sol::this_state l) {
			GenericObjectStlList_iteratorState& it_state = user_it_state;
			if (it_state.it == nullptr) {
				return std::make_tuple(sol::object(sol::lua_nil), sol::object(sol::lua_nil));
			}

			auto values = std::make_tuple(sol::object(l, sol::in_place, it_state.it->data->getObjectID()), makeLuaObject(it_state.it->data));
			it_state.it = it_state.it->next;
			return values;
		}

		void bindTES3Collections() {
			// Iterator bindings.
			bindIterator<TES3::EquipmentStack>("tes3equipmentStackIterator", "tes3equipmentStackIteratorNode");
			bindIterator<TES3::Faction::ReactionNode>("tes3reactionNodeIterator", "tes3reactionNodeIteratorNode");
			bindIterator<TES3::ItemStack>("tes3itemStackIterator", "tes3itemStackIteratorNode");
			bindIterator<TES3::LeveledListNode>("tes3leveledListNodeIterator", "tes3leveledListNodeIteratorNode");
			bindIterator<TES3::RegionSound>("tes3regionSoundIterator", "tes3regionSoundIteratorNode");
			bindIterator<TES3::TravelDestination>("tes3travelDestinationIterator", "tes3travelDestinationIteratorNode");

			// Generic TES3::Object iterators. As above, but the result data will be reinterpreted at runtime.
			bindGenericObjectIterator<TES3::BaseObject>("tes3baseObjectIterator", "tes3baseObjectIteratorNode");
			bindGenericObjectIterator<TES3::Birthsign>("tes3birthsignIterator", "tes3birthsignIteratorNode");
			bindGenericObjectIterator<TES3::Dialogue>("tes3dialogueIterator", "tes3dialogueIteratorNode");
			bindGenericObjectIterator<TES3::DialogueInfo>("tes3dialogueInfoIterator", "tes3dialogueInfoIteratorNode");
			bindGenericObjectIterator<TES3::GlobalVariable>("tes3globalIterator", "tes3globalIteratorNode");
			bindGenericObjectIterator<TES3::MobileActor>("tes3mobileActorIterator", "tes3mobileActorIteratorNode");
			bindGenericObjectIterator<TES3::Quest>("tes3questIterator", "tes3questIteratorNode");
			bindGenericObjectIterator<TES3::Reference>("tes3referenceIterator", "tes3referenceIteratorNode");
			bindGenericObjectIterator<TES3::Region>("tes3regionIterator", "tes3regionIteratorNode");
			bindGenericObjectIterator<TES3::Spell>("tes3spellIterator", "tes3spellIteratorNode");

			// Generic TES3::Object STL collections.
			bindGenericObjectStlList<TES3::Cell>("tes3cellStlList", "tes3cellStlListNode");

			// Bind some iterators.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;
			state.new_usertype<TES3::LinkedList<TES3::Object>>("tes3objectLinkedList",
				// Disable construction of this type.
				"new", sol::no_constructor,

				//
				// Meta functions.
				//

				sol::meta_function::index, [](TES3::LinkedList<TES3::Object>& self, int index)
			{
				TES3::Object* object = self.head;
				while (object && index > 1) {
					object = object->nextInCollection;
					index--;
				}
				return makeLuaObject(object);
			},
				sol::meta_function::length, [](TES3::LinkedList<TES3::Object>& self) { return self.size; }

			);
		}
	}
}
