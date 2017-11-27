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

		REFRRecord_t* exteriorRefs[9] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		void clearExteriorRefs() {
			for (size_t i = 0; i <= 9; i++) {
				exteriorRefs[i] = NULL;
			}
		}
	}
}
