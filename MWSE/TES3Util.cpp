#include "TES3Util.h"

#include "Log.h"

namespace mwse
{
	namespace tes3
	{
		TES3CellMaster_t * getCellMaster() {
			return *reinterpret_cast<TES3CellMaster_t**>(0x7C67E0);
		}

		GLOBRecord_t* getGlobalRecord(const char* id) {
			static int findGLOB = 0x4BA820;
			GLOBRecord_t* global = NULL;
			__asm
			{
				mov ecx, dword ptr ds : [0x7C67E0];
				push id;
				call findGLOB;
				mov foundRecord, eax;
			}
			return global;
		}

		GLOBRecord_t* getGlobalRecord(const mwseString_t& id) {
			return getGlobalRecord(id.c_str());
		}

		REFRRecord_t * skipRemovedReferences(REFRRecord_t * reference) {
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

			ListNode_t<BaseRecord_t>* listNode = reference->attachments;
			while (listNode) {
				if (listNode->attachType == attachmentType) {
					return listNode->dataPtr;
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
			if ((flags & Effects::CastSelf && range == Effects::RangeSelf) ||
				(flags & Effects::CastTouch && range == Effects::RangeTouch) ||
				(flags & Effects::CastTarget && range == Effects::RangeTarget)) {
				mwse::log::getLog() << __FUNCTION__ << ": Effect does not support given range type." << std::endl;
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
				int const FuncSkillUp = 0x56BBE0;
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
				const int loadMessage = 0x40F930;
				const int displayMessage = 0x5F90C0;
				__asm
				{
					mov ecx, dword ptr[0x7C67DC];
					push 0x1;
					push 0x0;
					push 0x2AA;
					call loadMessage;
					push eax;
					call displayMessage;
				}
			}
		}

		REFRRecord_t* exteriorRefs[9] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };

		void clearExteriorRefs() {
			for (size_t i = 0; i <= 9; i++) {
				exteriorRefs[i] = NULL;
			}
		}
	}
}
