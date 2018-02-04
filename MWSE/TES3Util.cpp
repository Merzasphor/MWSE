#include "TES3Util.h"

#include "Log.h"

#include "mwOffsets.h"

namespace mwse
{
	namespace tes3
	{
		TES3Master_t * getMaster() {
			return *reinterpret_cast<TES3Master_t**>(TES3_MASTER_IMAGE);
		}

		TES3CellMaster_t * getCellMaster() {
			return *reinterpret_cast<TES3CellMaster_t**>(TES3_MASTERCELL_IMAGE);
		}

		GLOBRecord_t* getGlobalRecord(const char* id) {
			static int findGLOB = TES3_FUNC_FIND_GLOBAL;
			GLOBRecord_t* global = NULL;
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

		GLOBRecord_t* getGlobalRecord(const std::string& id) {
			return getGlobalRecord(id.c_str());
		}

		TES3DefaultTemplate_t* getTemplate(const char *id)
		{
			RecordLists_t* recordLists = tes3::getCellMaster()->recordLists;

			TES3DefaultTemplate_t * foundTemplate = NULL;

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

		SCPTRecord_t* getScript(const char* id) {
			static int findScript = TES3_FUNC_FIND_SCRIPT;
			SCPTRecord_t* script = NULL;
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

		SCPTRecord_t* getScript(const std::string& id) {
			return getScript(id.c_str());
		}

		TES3DefaultTemplate_t* getTemplate(const std::string& id)
		{
			return getTemplate(id.c_str());
		}

		void addObject(BaseRecord_t* record) {
			int const kAddObject = TES3_FUNC_ADD_NEW_OBJECT;
			__asm {
				mov edx, dword ptr ds : [TES3_MASTERCELL_IMAGE];
				mov ecx, dword ptr ds : [edx];
				push record;
				call kAddObject;
			}
		}

		REFRRecord_t * skipRemovedReferences(REFRRecord_t * reference) {
			while (reference != 0 && (reference->flags & 0x20) == 0x20)
			{
				reference = reference->nextRecord;
			}
			return reference;
		}

		IteratorNode_t<InventoryNode_t> * getFirstInventoryNode(REFRRecord_t* reference) {
			IteratorNode_t<InventoryNode_t>* node = NULL;

			BaseRecord_t* record = reference->recordPointer;
			CONTRecord_t* recordAsContainer = reinterpret_cast<CONTRecord_t*>(record);

			if (hasInventory(record)) {
				node = recordAsContainer->inventory.head;
			}

			return node;
		}

		bool hasInventory(BaseRecord_t* record) {
			RecordTypes::recordType_t type = record->recordType;
			return (type == RecordTypes::NPC || type == RecordTypes::CREATURE || type == RecordTypes::CONTAINER);
		}

		char* getName(BaseRecord_t* record) {
			char* name = NULL;

			RecordTypes::recordType_t type = record->recordType;
			switch (type) {
			case RecordTypes::NPC:
			case RecordTypes::CREATURE:
				name = reinterpret_cast<NPCCopyRecord_t*>(record)->baseNPC->name;
				break;
			case RecordTypes::CONTAINER:
				name = reinterpret_cast<CONTRecord_t*>(record)->name;
				break;
			case RecordTypes::LIGHT:
				name = reinterpret_cast<LIGHRecord_t*>(record)->name;
				break;
			case RecordTypes::ALCHEMY:
			case RecordTypes::AMMO:
			case RecordTypes::ARMOR:
			case RecordTypes::BOOK:
			case RecordTypes::CLOTHING:
			case RecordTypes::MISC:
			case RecordTypes::WEAPON:
				name = reinterpret_cast<ARMORecord_t*>(record)->name;
				break;
			case RecordTypes::ACTIVATOR:
				name = reinterpret_cast<ACTIRecord_t*>(record)->name;
				break;
			case RecordTypes::DOOR:
				name = reinterpret_cast<DOORRecord_t*>(record)->name;
				break;
			case RecordTypes::APPARATUS:
				name = reinterpret_cast<APPARecord_t*>(record)->name;
				break;
			case RecordTypes::INGREDIENT:
			case RecordTypes::LOCKPICK:
			case RecordTypes::PROBE:
			case RecordTypes::REPAIR:
				name = reinterpret_cast<LOCKRecord_t*>(record)->name;
				break;
			}

			return name;
		}

		mwLong_t getValue(BaseRecord_t* record) {
			mwLong_t value = 0;

			// Get the value from the base record. We group records here by the same offset.
			RecordTypes::recordType_t recordType = record->recordType;
			switch (recordType) {
			case RecordTypes::BOOK:
			case RecordTypes::ALCHEMY:
			case RecordTypes::AMMO:
			case RecordTypes::WEAPON:
				value = reinterpret_cast<BOOKRecord_t*>(record)->value;
				break;
			case RecordTypes::LIGHT:
				value = reinterpret_cast<LIGHRecord_t*>(record)->value;
				break;
			case RecordTypes::INGREDIENT:
			case RecordTypes::LOCK:
			case RecordTypes::PROBE:
			case RecordTypes::REPAIR:
				value = reinterpret_cast<LOCKRecord_t*>(record)->value;
				break;
			case RecordTypes::ARMOR:
				value = reinterpret_cast<ARMORecord_t*>(record)->value;
				break;
			case RecordTypes::CLOTHING:
				// Clothing has the same offset as armor, but it's a short rather than a long.
				value = reinterpret_cast<CLOTRecord_t*>(record)->value;
				break;
			case RecordTypes::APPARATUS:
				value = reinterpret_cast<APPARecord_t*>(record)->value;
				break;
			case RecordTypes::MISC:
			{
				value = reinterpret_cast<MISCRecord_t*>(record)->value;
				break;
			}
			default:
				throw std::exception("Call on invalid record type.");
			}

			return value;
		}

		mwLong_t getValue(REFRRecord_t* reference, bool multiplyByCount) {
			// Get record.
			BaseRecord_t* record = reference->recordPointer;
			if (record == NULL) {
				throw std::exception("No base record found.");
			}

			// Get base value for the record.
			mwLong_t value = getValue(record);

			// Multiply the value by the count of the item.
			if (multiplyByCount) {
				InventoryNode_t* inventoryNode = reinterpret_cast<InventoryNode_t*>(tes3::getAttachedVarHolderNode(reference));
				if (inventoryNode) {
					value *= inventoryNode->itemCount;
				}
			}

			return value;
		}

		mwFloat_t getWeight(BaseRecord_t* record) {
			mwFloat_t weight = 0.0f;

			// Get the weight from the base record. We group records here by the same offset.
			RecordTypes::recordType_t recordType = record->recordType;
			switch (recordType) {
			case RecordTypes::MISC:
			case RecordTypes::BOOK:
			case RecordTypes::ALCHEMY:
			case RecordTypes::AMMO:
			case RecordTypes::WEAPON:
				weight = reinterpret_cast<BOOKRecord_t*>(record)->weight;
				break;
			case RecordTypes::LIGHT:
				weight = reinterpret_cast<LIGHRecord_t*>(record)->weight;
				break;
			case RecordTypes::INGREDIENT:
			case RecordTypes::LOCK:
			case RecordTypes::PROBE:
			case RecordTypes::REPAIR:
				weight = reinterpret_cast<LOCKRecord_t*>(record)->weight;
				break;
			case RecordTypes::ARMOR:
				weight = reinterpret_cast<ARMORecord_t*>(record)->weight;
				break;
			case RecordTypes::CLOTHING:
				weight = reinterpret_cast<CLOTRecord_t*>(record)->weight;
				break;
			case RecordTypes::APPARATUS:
				weight = reinterpret_cast<APPARecord_t*>(record)->weight;
				break;
			case RecordTypes::CONTAINER:
				weight = reinterpret_cast<CONTRecord_t*>(record)->weight;
				break;
			case RecordTypes::LEVELLEDITEM:
				weight = 0.000001f;
				break;
			default:
				throw std::exception("Call on invalid record type.");
			}

			return weight;
		}

		mwFloat_t getWeight(REFRRecord_t* reference, bool multiplyByCount) {
			// Get record.
			BaseRecord_t* record = reference->recordPointer;
			if (record == NULL) {
				throw std::exception("No base record found.");
			}

			// Get base weight for the record.
			mwFloat_t weight = getWeight(record);

			// Multiply the value by the count of the item.
			if (multiplyByCount) {
				InventoryNode_t* inventoryNode = reinterpret_cast<InventoryNode_t*>(tes3::getAttachedVarHolderNode(reference));
				if (inventoryNode) {
					weight *= inventoryNode->itemCount;
				}
			}

			return weight;
		}

		ENCHRecord_t* getEnchantment(TES3DefaultTemplate_t* record) {
			ENCHRecord_t* enchantment = NULL;

			RecordTypes::recordType_t type = record->recordType;
			switch (type) {
			case RecordTypes::AMMO:
				enchantment = reinterpret_cast<AMMORecord_t*>(record)->enchantment;
				break;
			case RecordTypes::ARMOR:
				enchantment = reinterpret_cast<ARMORecord_t*>(record)->enchantment;
				break;
			case RecordTypes::BOOK:
				enchantment = reinterpret_cast<BOOKRecord_t*>(record)->enchantment;
				break;
			case RecordTypes::CLOTHING:
				enchantment = reinterpret_cast<CLOTRecord_t*>(record)->enchantment;
				break;
			case RecordTypes::WEAPON:
				enchantment = reinterpret_cast<WEAPRecord_t*>(record)->enchantment;
				break;
			default:
				throw std::exception("Call on invalid record type.");
			}

			return enchantment;
		}

		char* getModel(BaseRecord_t* record) {
			char* model = NULL;

			RecordTypes::recordType_t type = record->recordType;
			switch (type) {
			case RecordTypes::ACTIVATOR:
				model = reinterpret_cast<ACTIRecord_t*>(record)->model;
				break;
			case RecordTypes::ALCHEMY:
			case RecordTypes::AMMO:
			case RecordTypes::ARMOR:
			case RecordTypes::BOOK:
			case RecordTypes::CLOTHING:
			case RecordTypes::MISC:
				model = reinterpret_cast<ALCHRecord_t*>(record)->model;
				break;
			case RecordTypes::APPARATUS:
				model = reinterpret_cast<APPARecord_t*>(record)->model;
				break;
			case RecordTypes::CONTAINER:
				model = reinterpret_cast<CONTRecord_t*>(record)->model;
				break;
			case RecordTypes::INGREDIENT:
				model = reinterpret_cast<INGRRecord_t*>(record)->model;
				break;
			case RecordTypes::LOCKPICK:
			case RecordTypes::PROBE:
				model = reinterpret_cast<LOCKRecord_t*>(record)->modal;
				break;
			case RecordTypes::LIGH:
				model = reinterpret_cast<LIGHRecord_t*>(record)->model;
				break;
			case RecordTypes::REPAIR:
				model = reinterpret_cast<REPARecord_t*>(record)->model;
				break;
			case RecordTypes::WEAPON:
				model = reinterpret_cast<WEAPRecord_t*>(record)->model;
				break;
			case RecordTypes::DOOR:
				model = reinterpret_cast<DOORRecord_t*>(record)->model;
			default:
				log::getLog() << __FUNCTION__ << ": Unhandled record type of " << std::hex << type << " at " << (long)record << std::dec << std::endl;
				break;
			}

			return model;
		}

		bool getHasBaseRecord(TES3DefaultTemplate_t* record) {
			if (record == NULL) {
				return false;
			}

			switch (record->recordType) {
			case RecordTypes::NPC:
			case RecordTypes::CREATURE:
				return true;
			default:
				return false;
			}
		}

		TES3DefaultTemplate_t* getBaseRecord(TES3DefaultTemplate_t* reference) {
			if (!getHasBaseRecord(reference)) {
				return NULL;
			}

			NPCBaseRecord_t* base = reinterpret_cast<NPCCopyRecord_t*>(reference)->baseNPC;
			if (base == NULL) {
				return NULL;
			}
			else if (base->recordType != reference->recordType) {
				return NULL;
			}

			return reinterpret_cast<TES3DefaultTemplate_t*>(base);
		}

		BaseRecord_t* getFirstAttachmentByType(REFRRecord_t* reference, RecordTypes::attachType_t attachmentType) {
			if (reference == NULL || reference->attachments == NULL) {
				return NULL;
			}

			AttachmentNode_t<mwVarHolderNode_t>* listNode = reinterpret_cast<AttachmentNode_t<mwVarHolderNode_t>*>(reference->attachments);
			while (listNode) {
				if (listNode->type == attachmentType) {
					return reinterpret_cast<BaseRecord_t*>(listNode->data);
				}
				listNode = listNode->next;
			}

			return NULL;
		}

		MACPRecord_t* getAttachedMACPRecord(REFRRecord_t* reference) {
			return reinterpret_cast<MACPRecord_t*>(getFirstAttachmentByType(reference, RecordTypes::MACHNODE));
		}

		mwVarHolderNode_t* getAttachedVarHolderNode(REFRRecord_t* reference) {
			return reinterpret_cast<mwVarHolderNode_t*>(getFirstAttachmentByType(reference, RecordTypes::VARNODE));
		}

		mwLockNode_t* getAttachedLockNode(REFRRecord_t* reference) {
			return reinterpret_cast<mwLockNode_t*>(getFirstAttachmentByType(reference, RecordTypes::LOCKNODE));
		}

		SPELRecord_t* getSpellRecordById(const std::string& id) {
			TES3CellMaster_t* cellMaster = getCellMaster();

			SPELRecord_t * spell = cellMaster->recordLists->spellsList->head;
			while (spell != NULL && !(spell->recordType == RecordTypes::SPELL && strcmp(id.c_str(), spell->id) == 0)) {
				spell = spell->nextRecord;
			}

			return spell;
		}

		ENCHRecord_t* getEnchantRecordById(const std::string& id) {
			TES3CellMaster_t* cellMaster = getCellMaster();

			ENCHRecord_t * enchant = reinterpret_cast<ENCHRecord_t*>(cellMaster->recordLists->list->head);
			while (enchant != NULL && !(enchant->recordType == RecordTypes::ENCHANTMENT && strcmp(id.c_str(), enchant->id) == 0)) {
				enchant = enchant->nextRecord;
			}

			return enchant;
		}

		ALCHRecord_t* getAlchemyRecordById(const std::string& id) {
			TES3CellMaster_t* cellMaster = getCellMaster();

			ALCHRecord_t * record = reinterpret_cast<ALCHRecord_t*>(cellMaster->recordLists->list->head);
			while (record != NULL && !(record->recordType == RecordTypes::ALCHEMY && strcmp(id.c_str(), record->id) == 0)) {
				record = record->nextRecord;
			}

			return record;
		}

		size_t getEffectCount(const Effect_t* effectArray) {
			size_t count = 0;
			for (size_t i = 0; i < 8; i++) {
				if (effectArray[i].effectId != Effects::NoEffect) {
					count++;
				}
			}
			return count;
		}

		bool setEffect(Effect_t * effects, mwLong_t index, mwLong_t effectId,
			mwLong_t skillAttributeId, mwLong_t range, mwLong_t area, mwLong_t duration,
			mwLong_t minimumMagnitude, mwLong_t maximumMagnitude) {
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
			if (effectId < Effects::FirstMagicEffect || effectId > Effects::LastMagicEffect) {
				mwse::log::getLog() << __FUNCTION__ << ": Effect id outside bounds." << std::endl;
				return false;
			}

			// Validate that the effect supports the range type.
			const int flags = Effects::MagicEffectFlagMap[effectId];
			if ((range == Effects::RangeSelf && !(flags & Effects::CastSelf)) ||
				(range == Effects::CastTouch && !(flags & Effects::RangeTouch)) ||
				(range == Effects::RangeTarget && !(flags & Effects::CastTarget))) {
				mwse::log::getLog() << __FUNCTION__ << ": Effect " << effectId << " (with flags " << std::hex << flags << std::dec << ") does not support given range type of " << range << "." << std::endl;
				return false;
			}

			// Convert index to zero-based.
			index--;

			// Set basic effect data.
			Effect_t& effect = effects[index];
			effect.effectId = effectId;
			effect.rangeType = range;
			effect.area = area;

			// Set skill.
			if (flags & Effects::TargetSkill) {
				effect.skillId = skillAttributeId;
			}
			else {
				effect.skillId = NoSkill;
			}

			// Set attribute.
			if (flags & Effects::TargetAttribute) {
				effect.attributeId = skillAttributeId;
			}
			else {
				effect.attributeId = NoAttribute;
			}

			// Set duration.
			if (flags & Effects::NoDuration) {
				effect.duration = 0;
			}
			else {
				effect.duration = duration;
			}

			// Set magnitude.
			if (flags & Effects::NoMagnitude) {
				effect.magMin = 0;
				effect.magMax = 0;
			}
			else {
				effect.magMin = minimumMagnitude;
				effect.magMax = maximumMagnitude;
			}

			return true;
		}

		float getSkillRequirement(REFRRecord_t* reference, mwLong_t skillId) {
			TES3CellMaster_t* cellMaster = getCellMaster();
			GMSTRecord_t ** gmsts = cellMaster->recordLists->GMSTs;

			MACPRecord_t* macp = getAttachedMACPRecord(reference);
			const MACPRecord_t::Skill& skill = macp->skills[skillId];

			// Multiply requirement by skill type bonus.
			float requirement = skill.base + 1.0f;
			if (skill.skillType == Misc) {
				requirement *= gmsts[GMST::fMiscSkillBonus]->value.float_value;
			}
			else if (skill.skillType == Minor) {
				requirement *= gmsts[GMST::fMinorSkillBonus]->value.float_value;
			}
			else if (skill.skillType == Major) {
				requirement *= gmsts[GMST::fMajorSkillBonus]->value.float_value;
			}

			// Multiply requirement by specialization bonus.
			CLASRecord_t* classRecord = reinterpret_cast<NPCCopyRecord_t*>(macp->reference->recordPointer)->baseNPC->classRecord;
			if (cellMaster->recordLists->skills[skillId].specialization == classRecord->specialization) {
				requirement *= gmsts[GMST::fSpecialSkillBonus]->value.float_value;
			}

			return requirement;
		}

		void checkForSkillUp(REFRRecord_t* reference, mwLong_t skillId) {
			MACPRecord_t* macp = getAttachedMACPRecord(reference);
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

		void checkForLevelUp(mwLong_t progress) {
			GMSTRecord_t** GMSTs = getCellMaster()->recordLists->GMSTs;
			if (progress >= GMSTs[GMST::iLevelupTotal]->value.long_value) {
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

		REFRRecord_t* exteriorRefs[9] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

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
