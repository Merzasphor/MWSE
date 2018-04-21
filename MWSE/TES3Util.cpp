#include "TES3Util.h"

#include "Log.h"

#include "mwOffsets.h"

#include "TES3Actor.h"
#include "TES3Attachment.h"
#include "TES3Class.h"
#include "TES3Clothing.h"
#include "TES3DataHandler.h"
#include "TES3Enchantment.h"
#include "TES3GameSetting.h"
#include "TES3MobilePlayer.h"
#include "TES3NPC.h"
#include "TES3Reference.h"
#include "TES3Skill.h"
#include "TES3Spell.h"
#include "TES3WorldController.h"

#define TES3_general_messagePlayer 0x5F90C0
#define TES3_general_setStringSlot 0x47B410

#define TES3_data_GMSTs 0x794800

namespace mwse {
	namespace tes3 {
		TES3::WorldController * getWorldController() {
			// Prior to 2.1, this was getMaster
			return *reinterpret_cast<TES3::WorldController**>(TES3_WORLD_CONTROLLER_IMAGE);
		}

		TES3::DataHandler * getDataHandler() {
			// Prior to 2.1, this was getCellMaster
			return *reinterpret_cast<TES3::DataHandler**>(TES3_DATA_HANDLER_IMAGE);
		}

		TES3::Game * getGame() {
			// Prior to 2.1, this was getViewMaster
			return *reinterpret_cast<TES3::Game**>(TES3_GAME_IMAGE);
		}

		TES3::Reference* getReference(const char* id) {
			bool isplayer = !_stricmp(id, "player") || !_stricmp(id, "playersavegame");
			if (isplayer) {
				return getWorldController()->getMobilePlayer()->reference;
			}
			else {
				return getDataHandler()->nonDynamicData->findFirstCloneOfActor(id);
			}
		}

		TES3::Reference* getReference(std::string& id) {
			return getReference(id.c_str());
		}

		TES3::Spell* getSpellById(const char* id) {
			TES3::Spell * spell = getDataHandler()->nonDynamicData->spellsList->head;
			while (spell != NULL && _stricmp(id, spell->objectID) != 0) {
				spell = reinterpret_cast<TES3::Spell*>(spell->nextInCollection);
			}

			return spell;
		}

		TES3::Spell* getSpellById(std::string& id) {
			return getSpellById(id.c_str());
		}

		TES3::Reference * skipRemovedReferences(TES3::Reference * reference) {
			while (reference != 0 && (reference->objectFlags & 0x20) == 0x20)
			{
				reference = reinterpret_cast<TES3::Reference*>(reference->nextInCollection);
			}
			return reference;
		}

		TES3::IteratorNode<TES3::ItemStack> * getFirstInventoryNode(TES3::Reference* reference) {
			TES3::IteratorNode<TES3::ItemStack> * node = NULL;

			if (hasInventory(reference->baseObject)) {
				node = reinterpret_cast<TES3::Actor*>(reference->baseObject)->inventory.iterator.head;
			}

			return node;
		}

		bool hasInventory(TES3::BaseObject* record) {
			TES3::ObjectType::ObjectType type = record->objectType;
			return (type == TES3::ObjectType::NPC || type == TES3::ObjectType::Creature || type == TES3::ObjectType::Container);
		}

		long getValue(TES3::Reference* reference, bool multiplyByCount) {
			// Get record.
			TES3::BaseObject* object = reference->baseObject;
			if (object == NULL) {
				throw std::exception("No base record found.");
			}

			// Get base value for the record.
			long value = object->vTable.object->getValue(object);

			// Multiply the value by the count of the item.
			if (multiplyByCount) {
				auto varNode = tes3::getAttachedItemDataNode(reference);
				if (varNode) {
					value *= varNode->count;
				}
			}

			return value;
		}

		float getWeight(TES3::Reference* reference, bool multiplyByCount) {
			// Get record.
			TES3::BaseObject* object = reference->baseObject;
			if (object == NULL) {
				throw std::exception("No base object found.");
			}

			// Get base weight for the record.
			float weight = object->vTable.object->getWeight(object);

			// Multiply the value by the count of the item.
			if (multiplyByCount) {
				auto varNode = tes3::getAttachedItemDataNode(reference);
				if (varNode) {
					weight *= varNode->count;
				}
			}

			return weight;
		}

		TES3::Enchantment* getEnchantment(TES3::BaseObject* object) {
			return object->vTable.object->getEnchantment(object);
		}

		bool getHasBaseRecord(TES3::BaseObject* record) {
			if (record == NULL) {
				return false;
			}

			switch (record->objectType) {
			case TES3::ObjectType::NPC:
			case TES3::ObjectType::Creature:
				return true;
			default:
				return false;
			}
		}

		TES3::BaseObject* getBaseRecord(TES3::BaseObject* reference) {
			if (!getHasBaseRecord(reference)) {
				return NULL;
			}

			TES3::NPC* base = reinterpret_cast<TES3::NPCInstance*>(reference)->baseNPC;
			if (base == NULL) {
				return NULL;
			}
			else if (base->objectType != reference->objectType) {
				return NULL;
			}

			return reinterpret_cast<TES3::BaseObject*>(base);
		}

		char* setDataString(char** container, const char* string) {
			return reinterpret_cast<char*(__cdecl *)(char**, const char*)>(TES3_general_setStringSlot)(container, string);
		}

		bool insertAttachment(TES3::Reference* reference, TES3::Attachment* attachment) {
			if (reference == NULL || attachment == NULL) {
				return false;
			}

			// Make sure no attachment already exists of this type.
			if (tes3::getAttachment<TES3::Attachment>(reference, attachment->type) != NULL) {
				return false;
			}

			// If there are no attachments, set this as the first.
			if (reference->attachments == NULL) {
				reference->attachments = attachment;
				return true;
			}

			// Otherwise, get the last attachment.
			TES3::Attachment* lastAttachment = reference->attachments;
			while (lastAttachment->next != NULL) {
				lastAttachment = lastAttachment->next;
			}

			// Link the attachment.
			lastAttachment->next = attachment;
			return true;
		}

		TES3::MobileActor* getAttachedMobileActor(TES3::Reference* reference) {
			auto attachment = getAttachment<TES3::MobileActorAttachment>(reference, TES3::AttachmentType::ActorData);
			if (attachment) {
				return attachment->data;
			}

			return NULL;
		}

		TES3::MobileCreature* getAttachedMobileCreature(TES3::Reference* reference) {
			auto attachment = getAttachment<TES3::MobileActorAttachment>(reference, TES3::AttachmentType::ActorData);
			if (attachment) {
				return reinterpret_cast<TES3::MobileCreature*>(attachment->data);
			}

			return NULL;
		}

		TES3::MobileNPC* getAttachedMobileNPC(TES3::Reference* reference) {
			auto attachment = getAttachment<TES3::MobileActorAttachment>(reference, TES3::AttachmentType::ActorData);
			if (attachment) {
				return reinterpret_cast<TES3::MobileNPC*>(attachment->data);
			}

			return NULL;
		}

		TES3::MobilePlayer* getAttachedMobilePlayer(TES3::Reference* reference) {
			auto attachment = getAttachment<TES3::MobileActorAttachment>(reference, TES3::AttachmentType::ActorData);
			if (attachment) {
				return reinterpret_cast<TES3::MobilePlayer*>(attachment->data);
			}

			return NULL;
		}

		TES3::ItemData* getAttachedItemDataNode(TES3::Reference* reference) {
			auto attachment = getAttachment<TES3::ItemDataAttachment>(reference, TES3::AttachmentType::Variables);
			if (attachment) {
				return attachment->data;
			}

			return NULL;
		}

		TES3::LockAttachmentNode* getAttachedLockNode(TES3::Reference* reference) {
			auto attachment = getAttachment<TES3::LockAttachment>(reference, TES3::AttachmentType::Lock);
			if (attachment) {
				return attachment->data;
			}

			return NULL;
		}

		unsigned int* getBaseEffectFlags() {
			return reinterpret_cast<unsigned int*>(TES3_DATA_EFFECT_FLAGS);
		}

		bool getBaseEffectFlag(int index, TES3::EffectFlag::EffectFlag flag) {
			return reinterpret_cast<unsigned int*>(TES3_DATA_EFFECT_FLAGS)[index] & flag;
		}

		void setBaseEffectFlag(int index, TES3::EffectFlag::EffectFlag flag, bool set) {
			if (set) {
				reinterpret_cast<unsigned int*>(TES3_DATA_EFFECT_FLAGS)[index] |= flag;
			}
			else {
				reinterpret_cast<unsigned int*>(TES3_DATA_EFFECT_FLAGS)[index] &= ~flag;
			}
		}

		size_t getEffectCount(const TES3::Effect* effectArray) {
			size_t count = 0;
			for (size_t i = 0; i < 8; i++) {
				if (effectArray[i].effectID != TES3::EffectID::None) {
					count++;
				}
			}
			return count;
		}

		bool setEffect(TES3::Effect * effects, long index, long effectId,
			long skillAttributeId, long range, long area, long duration,
			long minimumMagnitude, long maximumMagnitude) {
			// Validate effect pointer.
			if (effects == NULL) {
				mwse::log::getLog() << __FUNCTION__ << ": No effect passed." << std::endl;
				return false;
			}

			// Validate index.
			if (index < 1 || index > 8) {
				mwse::log::getLog() << __FUNCTION__ << ": Index must be between [1,8]." << std::endl;
				return false;
			}

			// Validate effect id.
			if (effectId < TES3::EffectID::FirstEffect || effectId > TES3::EffectID::LastEffect) {
				mwse::log::getLog() << __FUNCTION__ << ": Effect id outside bounds." << std::endl;
				return false;
			}

			// Validate that the effect supports the range type.
			const int flags = TES3::MagicEffectFlagMap[effectId];
			if ((range == TES3::EffectRange::Self && !(flags & TES3::EffectFlag::CanCastSelf)) ||
				(range == TES3::EffectRange::Touch && !(flags & TES3::EffectFlag::CanCastTouch)) ||
				(range == TES3::EffectRange::Target && !(flags & TES3::EffectFlag::CanCastTarget))) {
#if _DEBUG
				mwse::log::getLog() << __FUNCTION__ << ": Effect " << effectId << " (with flags " << std::hex << flags << std::dec << ") does not support given range type of " << range << "." << std::endl;
#endif
				return false;
			}

			// Convert index to zero-based.
			index--;

			// Set basic effect data.
			TES3::Effect& effect = effects[index];
			effect.effectID = effectId;
			effect.rangeType = range;
			effect.radius = area;

			// Set skill.
			if (flags & TES3::EffectFlag::TargetSkill) {
				effect.skillID = skillAttributeId;
			}
			else {
				effect.skillID = TES3::SkillID::Invalid;
			}

			// Set attribute.
			if (flags & TES3::EffectFlag::TargetAttribute) {
				effect.attributeID = skillAttributeId;
			}
			else {
				effect.attributeID = TES3::Attribute::Invalid;
			}

			// Set duration.
			if (flags & TES3::EffectFlag::NoDuration) {
				effect.duration = 0;
			}
			else {
				effect.duration = duration;
			}

			// Set magnitude.
			if (flags & TES3::EffectFlag::NoMagnitude) {
				effect.magnitudeMin = 0;
				effect.magnitudeMax = 0;
			}
			else {
				effect.magnitudeMin = minimumMagnitude;
				effect.magnitudeMax = maximumMagnitude;
			}

			return true;
		}

		bool effectsMatch(TES3::Effect* effectsA, TES3::Effect* effectsB, long count) {
			for (int i = 0; i < count; i++) {
				if (effectsA[i].effectID != effectsB[i].effectID ||
					effectsA[i].skillID != effectsB[i].skillID ||
					effectsA[i].attributeID != effectsB[i].attributeID ||
					effectsA[i].rangeType != effectsB[i].rangeType ||
					effectsA[i].radius != effectsB[i].radius ||
					effectsA[i].duration != effectsB[i].duration ||
					effectsA[i].magnitudeMin != effectsB[i].magnitudeMin ||
					effectsA[i].magnitudeMax != effectsB[i].magnitudeMax) {
					return false;
				}
			}
			return true;
		}

		float getSkillRequirement(TES3::Reference* reference, long skillId) {
			// This function only works on NPCs.
			if (reference->baseObject->objectType != TES3::ObjectType::NPC) {
				return -1.0f;
			}

			TES3::DataHandler* dataHandler = getDataHandler();
			TES3::GameSetting ** gmsts = dataHandler->nonDynamicData->GMSTs;

			TES3::MobileNPC* mobileObject = reinterpret_cast<TES3::MobileNPC*>(getAttachedMobileActor(reference));
			const TES3::SkillStatistic& skill = mobileObject->skills[skillId];

			// Multiply requirement by skill type bonus.
			float requirement = skill.base + 1.0f;
			if (skill.type == TES3::SkillType::Misc) {
				requirement *= gmsts[TES3::GMST::fMiscSkillBonus]->value.asFloat;
			}
			else if (skill.type == TES3::SkillType::Minor) {
				requirement *= gmsts[TES3::GMST::fMinorSkillBonus]->value.asFloat;
			}
			else if (skill.type == TES3::SkillType::Major) {
				requirement *= gmsts[TES3::GMST::fMajorSkillBonus]->value.asFloat;
			}

			// Multiply requirement by specialization bonus.
			TES3::Class* classRecord = reinterpret_cast<TES3::NPCInstance*>(mobileObject->reference->baseObject)->baseNPC->class_;
			if (dataHandler->nonDynamicData->skills[skillId].specialization == classRecord->specialization) {
				requirement *= gmsts[TES3::GMST::fSpecialSkillBonus]->value.asFloat;
			}

			return requirement;
		}

		void checkForLevelUp(long progress) {
			TES3::NonDynamicData* nonDynamicData = getDataHandler()->nonDynamicData;
			if (progress >= nonDynamicData->GMSTs[TES3::GMST::iLevelupTotal]->value.asLong) {
				const char* levelUpMessage = nonDynamicData->GMSTs[TES3::GMST::sLevelUpMsg]->value.asString;
				messagePlayer(levelUpMessage);
			}
		}

		void messagePlayer(const char* message) {
			reinterpret_cast<void(__cdecl *)(const char*, int, int)>(TES3_general_messagePlayer)(message, 0, 1);
		}

		TES3::GameSettingInfo* getGMSTInfo(int index) {
			return &reinterpret_cast<TES3::GameSettingInfo*>(TES3_data_GMSTs)[index];
		}

		TES3::Reference* exteriorRefs[9] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		void clearExteriorRefs() {
			for (size_t i = 0; i < 9; i++) {
				exteriorRefs[i] = NULL;
			}
		}

		ExternalRealloc _realloc = NULL;
		void* realloc(void* address, size_t size) {
			return _realloc(address, size);
		}

		ExternalMalloc _malloc = NULL;
		void* malloc(size_t size) {
			return _malloc(size);
		}

		ExternalFree _free = NULL;
		void free(void* address) {
			_free(address);
		}
	}
}
