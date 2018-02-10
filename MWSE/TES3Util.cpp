#include "TES3Util.h"

#include "Log.h"

#include "mwOffsets.h"

#include "TES3Activator.h"
#include "TES3Alchemy.h"
#include "TES3Apparatus.h"
#include "TES3Armor.h"
#include "TES3Attachment.h"
#include "TES3Book.h"
#include "TES3CellMaster.h"
#include "TES3Class.h"
#include "TES3Clothing.h"
#include "TES3Collections.h"
#include "TES3Container.h"
#include "TES3Door.h"
#include "TES3Enchantment.h"
#include "TES3GlobalVariable.h"
#include "TES3Ingredient.h"
#include "TES3Light.h"
#include "TES3Lockpick.h"
#include "TES3MACP.h"
#include "TES3MagicEffect.h"
#include "TES3Master.h"
#include "TES3Misc.h"
#include "TES3NPC.h"
#include "TES3Probe.h"
#include "TES3Reference.h"
#include "TES3Repair.h"
#include "TES3Script.h"
#include "TES3Spell.h"
#include "TES3Static.h"
#include "TES3ViewMaster.h"
#include "TES3Weapon.h"

namespace mwse
{
	namespace tes3
	{
		TES3::Master * getMaster() {
			return *reinterpret_cast<TES3::Master**>(TES3_MASTER_IMAGE);
		}

		TES3::CellMaster * getCellMaster() {
			return *reinterpret_cast<TES3::CellMaster**>(TES3_MASTERCELL_IMAGE);
		}

		TES3::ViewMaster * getViewMaster() {
			return *reinterpret_cast<TES3::ViewMaster**>(TES3_VIEWMASTER_IMAGE);
		}

		TES3::GlobalVariable* getGlobalRecord(const char* id) {
			static int findGLOB = TES3_FUNC_FIND_GLOBAL;
			TES3::GlobalVariable* global = NULL;
			__asm
			{
				mov ecx, dword ptr ds : [TES3_MASTERCELL_IMAGE];
				mov ecx, [ecx];
				push id;
				call findGLOB;
				mov global, eax;
			}
			return global;
		}

		TES3::GlobalVariable* getGlobalRecord(const std::string& id) {
			return getGlobalRecord(id.c_str());
		}

		TES3::BaseObject* getTemplate(const char *id)
		{
			TES3::RecordLists * recordLists = tes3::getCellMaster()->recordLists;

			TES3::BaseObject * foundTemplate = NULL;

			static int fixupTemplateFunction = TES3_FUNC_FIXUP_TEMPLATE;
			_asm
			{
				mov ecx, recordLists;
				push id;
				call fixupTemplateFunction;
				mov foundTemplate, eax;
			}

			return foundTemplate;
		}

		TES3::Script* getScript(const char* id) {
			static int findScript = TES3_FUNC_FIND_SCRIPT;
			TES3::Script* script = NULL;
			__asm
			{
				mov ecx, dword ptr ds : [TES3_MASTERCELL_IMAGE];
				mov ecx, [ecx];
				push id;
				call findScript;
				mov script, eax;
			}
			return script;
		}

		TES3::Script* getScript(const std::string& id) {
			return getScript(id.c_str());
		}

		TES3::BaseObject* getTemplate(const std::string& id)
		{
			return getTemplate(id.c_str());
		}

		void addObject(TES3::BaseObject* record) {
			int const kAddObject = TES3_FUNC_ADD_NEW_OBJECT;
			__asm {
				mov edx, dword ptr ds : [TES3_MASTERCELL_IMAGE];
				mov ecx, dword ptr ds : [edx];
				push record;
				call kAddObject;
			}
		}

		TES3::Reference * skipRemovedReferences(TES3::Reference * reference) {
			while (reference != 0 && (reference->baseFlags & 0x20) == 0x20)
			{
				reference = reinterpret_cast<TES3::Reference*>(reference->nextObject);
			}
			return reference;
		}

		TES3::IteratorNode<TES3::InventoryNode> * getFirstInventoryNode(TES3::Reference* reference) {
			TES3::IteratorNode<TES3::InventoryNode>* node = NULL;

			TES3::BaseObject* record = reference->objectPointer;
			TES3::Container* recordAsContainer = reinterpret_cast<TES3::Container*>(record);

			if (hasInventory(record)) {
				node = recordAsContainer->inventory.head;
			}

			return node;
		}

		bool hasInventory(TES3::BaseObject* record) {
			TES3::ObjectType::ObjectType type = record->objectType;
			return (type == TES3::ObjectType::NPC || type == TES3::ObjectType::Creature || type == TES3::ObjectType::Container);
		}

		char* getName(TES3::BaseObject* record) {
			char* name = NULL;

			TES3::ObjectType::ObjectType type = record->objectType;
			switch (type) {
			case TES3::ObjectType::NPC:
			case TES3::ObjectType::Creature:
				name = reinterpret_cast<TES3::NPCInstance*>(record)->baseNPC->name;
				break;
			case TES3::ObjectType::Container:
				name = reinterpret_cast<TES3::Container*>(record)->name;
				break;
			case TES3::ObjectType::Light:
				name = reinterpret_cast<TES3::Light*>(record)->name;
				break;
			case TES3::ObjectType::Alchemy:
			case TES3::ObjectType::Ammo:
			case TES3::ObjectType::Armor:
			case TES3::ObjectType::Book:
			case TES3::ObjectType::Clothing:
			case TES3::ObjectType::Misc:
			case TES3::ObjectType::Weapon:
				name = reinterpret_cast<TES3::Armor*>(record)->name;
				break;
			case TES3::ObjectType::Activator:
				name = reinterpret_cast<TES3::Activator*>(record)->name;
				break;
			case TES3::ObjectType::Door:
				name = reinterpret_cast<TES3::Door*>(record)->name;
				break;
			case TES3::ObjectType::Apparatus:
				name = reinterpret_cast<TES3::Apparatus*>(record)->name;
				break;
			case TES3::ObjectType::Ingredient:
			case TES3::ObjectType::Lockpick:
			case TES3::ObjectType::Probe:
			case TES3::ObjectType::Repair:
				name = reinterpret_cast<TES3::Lockpick*>(record)->name;
				break;
			}

			return name;
		}

		mwLong getValue(TES3::BaseObject* record) {
			mwLong value = 0;

			// Get the value from the base record. We group records here by the same offset.
			TES3::ObjectType::ObjectType objectType = record->objectType;
			switch (objectType) {
			case TES3::ObjectType::Book:
			case TES3::ObjectType::Alchemy:
			case TES3::ObjectType::Ammo:
			case TES3::ObjectType::Weapon:
				value = reinterpret_cast<TES3::Book*>(record)->value;
				break;
			case TES3::ObjectType::Light:
				value = reinterpret_cast<TES3::Light*>(record)->value;
				break;
			case TES3::ObjectType::Ingredient:
			case TES3::ObjectType::Lockpick:
			case TES3::ObjectType::Probe:
			case TES3::ObjectType::Repair:
				value = reinterpret_cast<TES3::Lockpick*>(record)->value;
				break;
			case TES3::ObjectType::Armor:
				value = reinterpret_cast<TES3::Armor*>(record)->value;
				break;
			case TES3::ObjectType::Clothing:
				// Clothing has the same offset as armor, but it's a short rather than a long.
				value = reinterpret_cast<TES3::Clothing*>(record)->value;
				break;
			case TES3::ObjectType::Apparatus:
				value = reinterpret_cast<TES3::Apparatus*>(record)->value;
				break;
			case TES3::ObjectType::Misc:
			{
				value = reinterpret_cast<TES3::Misc*>(record)->value;
				break;
			}
			default:
				throw std::exception("Call on invalid record type.");
			}

			return value;
		}

		mwLong getValue(TES3::Reference* reference, bool multiplyByCount) {
			// Get record.
			TES3::BaseObject* record = reference->objectPointer;
			if (record == NULL) {
				throw std::exception("No base record found.");
			}

			// Get base value for the record.
			mwLong value = getValue(record);

			// Multiply the value by the count of the item.
			if (multiplyByCount) {
				TES3::InventoryNode* inventoryNode = reinterpret_cast<TES3::InventoryNode*>(tes3::getAttachedVarHolderNode(reference));
				if (inventoryNode) {
					value *= inventoryNode->itemCount;
				}
			}

			return value;
		}

		mwFloat getWeight(TES3::BaseObject* record) {
			mwFloat weight = 0.0f;

			// Get the weight from the base record. We group records here by the same offset.
			TES3::ObjectType::ObjectType objectType = record->objectType;
			switch (objectType) {
			case TES3::ObjectType::Misc:
			case TES3::ObjectType::Book:
			case TES3::ObjectType::Alchemy:
			case TES3::ObjectType::Ammo:
			case TES3::ObjectType::Weapon:
				weight = reinterpret_cast<TES3::Book*>(record)->weight;
				break;
			case TES3::ObjectType::Light:
				weight = reinterpret_cast<TES3::Light*>(record)->weight;
				break;
			case TES3::ObjectType::Ingredient:
			case TES3::ObjectType::Lockpick:
			case TES3::ObjectType::Probe:
			case TES3::ObjectType::Repair:
				weight = reinterpret_cast<TES3::Lockpick*>(record)->weight;
				break;
			case TES3::ObjectType::Armor:
				weight = reinterpret_cast<TES3::Armor*>(record)->weight;
				break;
			case TES3::ObjectType::Clothing:
				weight = reinterpret_cast<TES3::Clothing*>(record)->weight;
				break;
			case TES3::ObjectType::Apparatus:
				weight = reinterpret_cast<TES3::Apparatus*>(record)->weight;
				break;
			case TES3::ObjectType::Container:
				weight = reinterpret_cast<TES3::Container*>(record)->weight;
				break;
			case TES3::ObjectType::LevelledItem:
				weight = 0.000001f;
				break;
			default:
				throw std::exception("Call on invalid record type.");
			}

			return weight;
		}

		mwFloat getWeight(TES3::Reference* reference, bool multiplyByCount) {
			// Get record.
			TES3::BaseObject* record = reference->objectPointer;
			if (record == NULL) {
				throw std::exception("No base record found.");
			}

			// Get base weight for the record.
			mwFloat weight = getWeight(record);

			// Multiply the value by the count of the item.
			if (multiplyByCount) {
				TES3::InventoryNode* inventoryNode = reinterpret_cast<TES3::InventoryNode*>(tes3::getAttachedVarHolderNode(reference));
				if (inventoryNode) {
					weight *= inventoryNode->itemCount;
				}
			}

			return weight;
		}

		TES3::Enchantment* getEnchantment(TES3::BaseObject* record) {
			TES3::Enchantment* enchantment = NULL;

			TES3::ObjectType::ObjectType type = record->objectType;
			switch (type) {
			case TES3::ObjectType::Ammo:
				enchantment = reinterpret_cast<TES3::Ammo*>(record)->enchantment;
				break;
			case TES3::ObjectType::Armor:
				enchantment = reinterpret_cast<TES3::Armor*>(record)->enchantment;
				break;
			case TES3::ObjectType::Book:
				enchantment = reinterpret_cast<TES3::Book*>(record)->enchantment;
				break;
			case TES3::ObjectType::Clothing:
				enchantment = reinterpret_cast<TES3::Clothing*>(record)->enchantment;
				break;
			case TES3::ObjectType::Weapon:
				enchantment = reinterpret_cast<TES3::Weapon*>(record)->enchantment;
				break;
#if _DEBUG
			default:
				throw std::exception("Call on invalid record type.");
#endif
			}

			return enchantment;
		}

		char* getModel(TES3::BaseObject* record) {
			char* model = NULL;

			TES3::ObjectType::ObjectType type = record->objectType;
			switch (type) {
			case TES3::ObjectType::Activator:
				model = reinterpret_cast<TES3::Activator*>(record)->model;
				break;
			case TES3::ObjectType::Armor:
				model = reinterpret_cast<TES3::Armor*>(record)->model;
				break;
			case TES3::ObjectType::Alchemy:
			case TES3::ObjectType::Ammo:
			case TES3::ObjectType::Book:
			case TES3::ObjectType::Clothing:
			case TES3::ObjectType::Misc:
				model = reinterpret_cast<TES3::Alchemy*>(record)->model;
				break;
			case TES3::ObjectType::Apparatus:
				model = reinterpret_cast<TES3::Apparatus*>(record)->model;
				break;
			case TES3::ObjectType::Container:
				model = reinterpret_cast<TES3::Container*>(record)->model;
				break;
			case TES3::ObjectType::Ingredient:
				model = reinterpret_cast<TES3::Ingredient*>(record)->model;
				break;
			case TES3::ObjectType::Lockpick:
			case TES3::ObjectType::Probe:
				model = reinterpret_cast<TES3::Lockpick*>(record)->modal;
				break;
			case TES3::ObjectType::Light:
				model = reinterpret_cast<TES3::Light*>(record)->model;
				break;
			case TES3::ObjectType::Repair:
				model = reinterpret_cast<TES3::Repair*>(record)->model;
				break;
			case TES3::ObjectType::Weapon:
				model = reinterpret_cast<TES3::Weapon*>(record)->model;
				break;
			case TES3::ObjectType::Door:
				model = reinterpret_cast<TES3::Door*>(record)->model;
				break;
			case TES3::ObjectType::Static:
			case TES3::ObjectType::Bodypart:
				model = reinterpret_cast<TES3::Static*>(record)->model;
				break;
#if _DEBUG
			default:
				log::getLog() << __FUNCTION__ << ": Unhandled record type of " << std::hex << type << " at " << (long)record << std::dec << std::endl;
				break;
#endif
			}

			return model;
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

		TES3::BaseObject* getFirstAttachmentByType(TES3::Reference* reference, TES3::AttachmentType attachmentType) {
			if (reference == NULL || reference->attachments == NULL) {
				return NULL;
			}

			TES3::Attachment<TES3::VariableHolderAttachment>* listNode = reinterpret_cast<TES3::Attachment<TES3::VariableHolderAttachment>*>(reference->attachments);
			while (listNode) {
				if (listNode->type == attachmentType) {
					return reinterpret_cast<TES3::BaseObject*>(listNode->data);
				}
				listNode = listNode->next;
			}

			return NULL;
		}

		TES3::MACP* getAttachedMACPRecord(TES3::Reference* reference) {
			return reinterpret_cast<TES3::MACP*>(getFirstAttachmentByType(reference, TES3::AttachmentMACP));
		}

		TES3::VariableHolderAttachment* getAttachedVarHolderNode(TES3::Reference* reference) {
			return reinterpret_cast<TES3::VariableHolderAttachment*>(getFirstAttachmentByType(reference, TES3::AttachmentVariables));
		}

		TES3::LockAttachment* getAttachedLockNode(TES3::Reference* reference) {
			return reinterpret_cast<TES3::LockAttachment*>(getFirstAttachmentByType(reference, TES3::AttachmentLock));
		}

		TES3::Spell* getSpellRecordById(const std::string& id) {
			const char* objectID = id.c_str();

			TES3::BaseObject * record = reinterpret_cast<TES3::BaseObject*>(getCellMaster()->recordLists->spellsList->head);
			while (record != NULL && !(record->objectType == TES3::ObjectType::Spell && strcmp(objectID, record->objectID) == 0)) {
				record = record->nextObject;
			}

			return reinterpret_cast<TES3::Spell*>(record);
		}

		TES3::Enchantment* getEnchantRecordById(const std::string& id) {
			const char* objectID = id.c_str();

			TES3::BaseObject * record = getCellMaster()->recordLists->list->head;
			while (record != NULL && !(record->objectType == TES3::ObjectType::Enchantment && strcmp(objectID, record->objectID) == 0)) {
				record = record->nextObject;
			}

			return reinterpret_cast<TES3::Enchantment*>(record);
		}

		TES3::Alchemy* getAlchemyRecordById(const std::string& id) {
			const char* objectID = id.c_str();

			TES3::BaseObject * record = getCellMaster()->recordLists->list->head;
			while (record != NULL && !(record->objectType == TES3::ObjectType::Alchemy && strcmp(objectID, record->objectID) == 0)) {
				record = record->nextObject;
			}

			return reinterpret_cast<TES3::Alchemy*>(record);
		}

		size_t getEffectCount(const TES3::Effect* effectArray) {
			size_t count = 0;
			for (size_t i = 0; i < 8; i++) {
				if (effectArray[i].ID != TES3::EffectNone) {
					count++;
				}
			}
			return count;
		}

		bool setEffect(TES3::Effect * effects, mwLong index, mwLong effectId,
			mwLong skillAttributeId, mwLong range, mwLong area, mwLong duration,
			mwLong minimumMagnitude, mwLong maximumMagnitude) {
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
			if (effectId < TES3::EffectFirst || effectId > TES3::EffectLast) {
				mwse::log::getLog() << __FUNCTION__ << ": Effect id outside bounds." << std::endl;
				return false;
			}

			// Validate that the effect supports the range type.
			const int flags = TES3::MagicEffectFlagMap[effectId];
			if ((range == TES3::EffectRangeSelf && !(flags & TES3::CastSelf)) ||
				(range == TES3::CastTouch && !(flags & TES3::EffectRangeTouch)) ||
				(range == TES3::EffectRangeTarget && !(flags & TES3::CastTarget))) {
#if _DEBUG
				mwse::log::getLog() << __FUNCTION__ << ": Effect " << effectId << " (with flags " << std::hex << flags << std::dec << ") does not support given range type of " << range << "." << std::endl;
#endif
				return false;
			}

			// Convert index to zero-based.
			index--;

			// Set basic effect data.
			TES3::Effect& effect = effects[index];
			effect.ID = effectId;
			effect.range = range;
			effect.area = area;

			// Set skill.
			if (flags & TES3::TargetSkill) {
				effect.skillID = skillAttributeId;
			}
			else {
				effect.skillID = TES3::SkillInvalid;
			}

			// Set attribute.
			if (flags & TES3::TargetAttribute) {
				effect.attributeID = skillAttributeId;
			}
			else {
				effect.attributeID = TES3::AttributeInvalid;
			}

			// Set duration.
			if (flags & TES3::NoDuration) {
				effect.duration = 0;
			}
			else {
				effect.duration = duration;
			}

			// Set magnitude.
			if (flags & TES3::NoMagnitude) {
				effect.magnitudeMin = 0;
				effect.magnitudeMax = 0;
			}
			else {
				effect.magnitudeMin = minimumMagnitude;
				effect.magnitudeMax = maximumMagnitude;
			}

			return true;
		}

		float getSkillRequirement(TES3::Reference* reference, mwLong skillId) {
			TES3::CellMaster* cellMaster = getCellMaster();
			TES3::GameSetting ** gmsts = cellMaster->recordLists->GMSTs;

			TES3::MACP* macp = getAttachedMACPRecord(reference);
			const TES3::MACP::Skill& skill = macp->skills[skillId];

			// Multiply requirement by skill type bonus.
			float requirement = skill.base + 1.0f;
			if (skill.skillType == TES3::SkillTypeMisc) {
				requirement *= gmsts[TES3::GMST::fMiscSkillBonus]->value.float_value;
			}
			else if (skill.skillType == TES3::SkillTypeMinor) {
				requirement *= gmsts[TES3::GMST::fMinorSkillBonus]->value.float_value;
			}
			else if (skill.skillType == TES3::SkillTypeMajor) {
				requirement *= gmsts[TES3::GMST::fMajorSkillBonus]->value.float_value;
			}

			// Multiply requirement by specialization bonus.
			TES3::Class* classRecord = reinterpret_cast<TES3::NPCInstance*>(macp->reference->objectPointer)->baseNPC->classRecord;
			if (cellMaster->recordLists->skills[skillId].specialization == classRecord->specialization) {
				requirement *= gmsts[TES3::GMST::fSpecialSkillBonus]->value.float_value;
			}

			return requirement;
		}

		void checkForSkillUp(TES3::Reference* reference, mwLong skillId) {
			TES3::MACP* macp = getAttachedMACPRecord(reference);
			if (macp) {
				int const FuncSkillUp = TES3_FUNC_SKILL_LEVEL_UP;
				__asm
				{
					mov ecx, macp
					push skillId
					call FuncSkillUp
				}
			}
		}

		void checkForLevelUp(mwLong progress) {
			TES3::GameSetting** GMSTs = getCellMaster()->recordLists->GMSTs;
			if (progress >= GMSTs[TES3::GMST::iLevelupTotal]->value.long_value) {
				const int loadMessage = TES3_FUNC_LOAD_MESSAGE;
				const int displayMessage = TES3_FUNC_DISPLAY_MESSAGE;
				__asm
				{
					mov ecx, dword ptr[TES3_MASTER_IMAGE];
					push 0x1;
					push 0x0;
					push 0x2AA;
					call loadMessage;
					push eax;
					call displayMessage;
					add esp, 0xC
				}
			}
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
