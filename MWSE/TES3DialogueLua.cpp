#include "TES3DialogueLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"
#include "TES3ObjectLua.h"

#include "TES3Actor.h"
#include "TES3Dialogue.h"
#include "TES3DialogueConditional.h"
#include "TES3DialogueInfo.h"

namespace mwse {
	namespace lua {
		sol::object getFilterObject(TES3::DialogueInfo& info, TES3::DialogueInfoFilterType type) {
			TES3::DialogueInfoFilterNode *node;

			for (node = info.conditions; node; node = node->next) {
				if (node->tag == type) {
					break;
				}
			}
			if (!node) {
				return sol::nil;
			}

			switch (type) {
			case TES3::DialogueInfoFilterType::Actor:
			case TES3::DialogueInfoFilterType::Race:
			case TES3::DialogueInfoFilterType::Class:
			case TES3::DialogueInfoFilterType::NPCFaction:
			case TES3::DialogueInfoFilterType::Cell:
			case TES3::DialogueInfoFilterType::PCFaction:
				return makeLuaObject(node->object);
			default:
				return sol::nil;
			}
		}

		void bindTES3Dialogue() {
			// Get our lua state.
			sol::state& state = LuaManager::getInstance().getState();

			// Binding for TES3::Dialogue
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::Dialogue>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("info", sol::readonly_property(&TES3::Dialogue::info));
				usertypeDefinition.set("journalIndex", sol::readonly_property(&TES3::Dialogue::journalIndex));
				usertypeDefinition.set("type", sol::readonly_property(&TES3::Dialogue::type));

				// Override id property to point to the name.
				usertypeDefinition.set("id", sol::readonly_property(&TES3::Dialogue::name));

				// Finish up our usertype.
				state.set_usertype("tes3dialogue", usertypeDefinition);
			}

			// Binding for TES3::DialogueInfo
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.create_simple_usertype<TES3::DialogueInfo>();
				usertypeDefinition.set("new", sol::no_constructor);

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition.set(sol::base_classes, sol::bases<TES3::BaseObject>());
				setUserdataForBaseObject(usertypeDefinition);

				// Basic property binding.
				usertypeDefinition.set("type", sol::readonly_property(&TES3::DialogueInfo::type));
				usertypeDefinition.set("disposition", sol::readonly_property(&TES3::DialogueInfo::disposition));
				usertypeDefinition.set("npcRank", sol::readonly_property(&TES3::DialogueInfo::npcRank));
				usertypeDefinition.set("npcSex", sol::readonly_property(&TES3::DialogueInfo::npcSex));
				usertypeDefinition.set("pcRank", sol::readonly_property(&TES3::DialogueInfo::pcRank));
				usertypeDefinition.set("firstHeardFrom", sol::readonly_property(&TES3::DialogueInfo::firstHeardFrom));

				// Accessor functions.
				usertypeDefinition.set("actor", sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::Actor);
					}
				));
				usertypeDefinition.set("npcRace", sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::Race);
					}
				));
				usertypeDefinition.set("npcClass", sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::Class);
					}
				));
				usertypeDefinition.set("npcFaction", sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::NPCFaction);
					}
				));
				usertypeDefinition.set("cell", sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::Cell);
					}
				));
				usertypeDefinition.set("pcFaction", sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::PCFaction);
					}
				));

				// Finish up our usertype.
				state.set_usertype("tes3dialogueinfo", usertypeDefinition);
			}
		}
	}
}
