#include "TES3DialogueLua.h"

#include "LuaManager.h"
#include "LuaUtil.h"
#include "TES3ObjectLua.h"

#include "TES3Actor.h"
#include "TES3Dialogue.h"
#include "TES3DialogueConditional.h"
#include "TES3DialogueInfo.h"
#include "TES3MobileActor.h"
#include "TES3MobilePlayer.h"
#include "TES3Quest.h"
#include "TES3Reference.h"
#include "TES3WorldController.h"

namespace mwse {
	namespace lua {
		TES3::BaseObject* getFilterObject(TES3::DialogueInfo& info, TES3::DialogueInfoFilterType type) {
			TES3::DialogueInfoFilterNode *node;

			for (node = info.conditions; node; node = node->next) {
				if (node->tag == type) {
					break;
				}
			}
			if (!node) {
				return nullptr;
			}

			switch (type) {
			case TES3::DialogueInfoFilterType::Actor:
			case TES3::DialogueInfoFilterType::Race:
			case TES3::DialogueInfoFilterType::Class:
			case TES3::DialogueInfoFilterType::NPCFaction:
			case TES3::DialogueInfoFilterType::Cell:
			case TES3::DialogueInfoFilterType::PCFaction:
				return node->object;
			default:
				return nullptr;
			}
		}

		void bindTES3Dialogue() {
			// Get our lua state.
			auto stateHandle = LuaManager::getInstance().getThreadSafeStateHandle();
			sol::state& state = stateHandle.state;

			// Binding for TES3::Dialogue
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Dialogue>("tes3dialogue");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForBaseObject(usertypeDefinition);

				// Override to-string to use the name rather than the (non-existant) id.
				usertypeDefinition[sol::meta_function::to_string] = [](TES3::Dialogue& self) { return self.name; };

				// Override tojson to use the name rather than the (non-existant) id.
				usertypeDefinition["__tojson"] = [](TES3::Dialogue& self) {
					std::ostringstream ss;
					ss << "\"tes3dialogue:" << self.name << "\"";
					return ss.str();
				};

				// Basic property binding.
				usertypeDefinition["info"] = sol::readonly_property(&TES3::Dialogue::info);
				usertypeDefinition["journalIndex"] = sol::property(&TES3::Dialogue::journalIndex, &TES3::Dialogue::setJournalIndex);
				usertypeDefinition["type"] = sol::readonly_property(&TES3::Dialogue::type);

				// Expose the ability to add it to the journal.
				usertypeDefinition["addToJournal"] = [](TES3::Dialogue& self, sol::table params) {
					int index = getOptionalParam<int>(params, "index", 0);
					TES3::MobileActor * actor = getOptionalParamMobileActor(params, "actor");
					if (actor == nullptr) {
						actor = TES3::WorldController::get()->getMobilePlayer();
					}
					return self.addToJournal(index, actor);
				};

				// Expose filtering.
				usertypeDefinition["getInfo"] = [](TES3::Dialogue& self, sol::table params) {
					TES3::MobileActor * mobile = getOptionalParamMobileActor(params, "actor");
					return self.getDeepFilteredInfo(reinterpret_cast<TES3::Actor*>(mobile->reference->baseObject), mobile->reference, true);
				};
			}

			// Binding for TES3::DialogueInfo
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::DialogueInfo>("tes3dialogueinfo");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForBaseObject(usertypeDefinition);

				// Allow dialogue to be serialized to json using its ID.
				usertypeDefinition["__tojson"] = [](TES3::DialogueInfo& self, sol::table state) {
					std::ostringstream ss;
					ss << "\"tes3dialogueInfo:" << self.getLongIDFromFile() << "\"";
					return ss.str();
				};

				// Basic property binding.
				usertypeDefinition["type"] = sol::readonly_property(&TES3::DialogueInfo::type);
				usertypeDefinition["disposition"] = sol::readonly_property(&TES3::DialogueInfo::disposition);
				usertypeDefinition["npcRank"] = sol::readonly_property(&TES3::DialogueInfo::npcRank);
				usertypeDefinition["npcSex"] = sol::readonly_property(&TES3::DialogueInfo::npcSex);
				usertypeDefinition["pcRank"] = sol::readonly_property(&TES3::DialogueInfo::pcRank);
				usertypeDefinition["firstHeardFrom"] = sol::property(
					[](TES3::DialogueInfo& self) { return self.firstHeardFrom; },
					[](TES3::DialogueInfo& self, TES3::Actor* actor) { self.firstHeardFrom = actor; }
				);

				// Filter functions.
				usertypeDefinition["actor"] = sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::Actor);
					}
				);
				usertypeDefinition["npcRace"] = sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::Race);
					}
				);
				usertypeDefinition["npcClass"] = sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::Class);
					}
				);
				usertypeDefinition["npcFaction"] = sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::NPCFaction);
					}
				);
				usertypeDefinition["cell"] = sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::Cell);
					}
				);
				usertypeDefinition["pcFaction"] = sol::property(
					[](TES3::DialogueInfo& self) {
						return getFilterObject(self, TES3::DialogueInfoFilterType::PCFaction);
					}
				);

				// Load link access.
				usertypeDefinition["id"] = sol::readonly_property([](TES3::DialogueInfo& self) -> sol::optional<std::string> {
					if (self.loadId()) {
						std::string id = self.loadLinkNode->name;
						self.unloadId();
						return id;
					}

					return sol::optional<std::string>();
				});

				// Functions exposed as properties.
				usertypeDefinition["text"] = sol::readonly_property(&TES3::DialogueInfo::getText);

				// Basic function binding.
				usertypeDefinition["runScript"] = &TES3::DialogueInfo::runScript;
			}

			// Binding for TES3::Quest
			{
				// Start our usertype. We must finish this with state.set_usertype.
				auto usertypeDefinition = state.new_usertype<TES3::Quest>("tes3quest");
				usertypeDefinition["new"] = sol::no_constructor;

				// Define inheritance structures. These must be defined in order from top to bottom. The complete chain must be defined.
				usertypeDefinition[sol::base_classes] = sol::bases<TES3::BaseObject>();
				setUserdataForBaseObject(usertypeDefinition);

				// Allow objects to be serialized to json using their ID.
				usertypeDefinition["__tojson"] = [](TES3::BaseObject& self, sol::table state) {
					std::ostringstream ss;
					ss << "\"tes3quest:" << self.getObjectID() << "\"";
					return ss.str();
				};

				// Basic property binding.
				usertypeDefinition["dialogue"] = sol::readonly_property(&TES3::Quest::dialogue);
				usertypeDefinition["info"] = sol::readonly_property(&TES3::Quest::activeInfo);
			}
		}
	}
}
