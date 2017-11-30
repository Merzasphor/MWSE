#include "TES3Util.h"

#include "Log.h"

namespace mwse
{
	namespace tes3
	{
		TES3CellMaster_t * getCellMaster()
		{
			return *reinterpret_cast<TES3CellMaster_t**>(0x7C67E0);
		}

		REFRRecord_t * skipRemovedReferences(REFRRecord_t * reference)
		{
			while (reference != 0 && (reference->flags & 0x20) == 0x20)
			{
				reference = reference->nextRecord;
			}
			return reference;
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
			} else if (base->recordType != reference->recordType) {
				return NULL;
			}

			return reinterpret_cast<TES3DefaultTemplate_t*>(base);
		}

		BaseRecord_t* getFirstAttachmentByType(REFRRecord_t* reference, RecordTypes::attachType_t attachmentType) {
			if (reference == NULL || reference->attachments == NULL) {
				return NULL;
			}

			ListNode_t* listNode = reference->attachments;
			while (listNode) {
				if (listNode->attachType == attachmentType) {
					return reinterpret_cast<BaseRecord_t*>(listNode->dataPtr);
				}
				listNode = listNode->nextNode;
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

		SPELRecord_t* getSpellRecordById(const mwseString_t& id) {
			TES3CellMaster_t* cellMaster = getCellMaster();

			SPELRecord_t * spell = cellMaster->recordLists->spellsList->head;
			while (spell != NULL && !(spell->recordType == RecordTypes::SPELL && strcmp(id.c_str(), spell->id) == 0)) {
				spell = spell->nextRecord;
			}

			return spell;
		}

		ENCHRecord_t* getEnchantRecordById(const mwseString_t& id) {
			TES3CellMaster_t* cellMaster = getCellMaster();

			ENCHRecord_t * enchant = reinterpret_cast<ENCHRecord_t*>(cellMaster->recordLists->list->head);
			while (enchant != NULL && !(enchant->recordType == RecordTypes::ENCHANTMENT && strcmp(id.c_str(), enchant->id) == 0)) {
				enchant = enchant->nextRecord;
			}

			return enchant;
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

		REFRRecord_t* exteriorRefs[9] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		void clearExteriorRefs() {
			for (size_t i = 0; i <= 9; i++) {
				exteriorRefs[i] = NULL;
			}
		}
	}
}
