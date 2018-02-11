/************************************************************************

	TES3Util.h - Copyright (c) 2008 The MWSE Project
	https://github.com/MWSE/MWSE/

	This program is free software; you can redistribute it and/or
	modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 2
	of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

**************************************************************************/

#pragma once

#include <random>
#include <queue>

#include "mwseString.h"

#include "ObjectTypes.h"
#include "TES3Collections.h"
#include "TES3Attachment.h"

namespace mwse
{
	namespace tes3
	{
		TES3::Master * getMaster();
		TES3::CellMaster * getCellMaster();
		TES3::ViewMaster * getViewMaster();

		TES3::GlobalVariable* getGlobalRecord(const char* id);
		TES3::GlobalVariable* getGlobalRecord(const std::string& id);

		TES3::BaseObject* getTemplate(const char *id);
		TES3::BaseObject* getTemplate(const std::string& id);

		template <typename T>
		T* getRecordById(const char* id) {
			return reinterpret_cast<T*>(getTemplate(id));
		}

		template <typename T>
		T* getRecordById(const std::string& id) {
			return reinterpret_cast<T*>(getTemplate(id.c_str()));
		}

		TES3::Script* getScript(const char* id);
		TES3::Script* getScript(const std::string& id);

		void addObject(TES3::BaseObject* record);

		TES3::Reference* skipRemovedReferences(TES3::Reference* reference);

		bool getHasBaseRecord(TES3::BaseObject* record);

		TES3::IteratorNode<TES3::InventoryNode> * getFirstInventoryNode(TES3::Reference* reference);

		bool hasInventory(TES3::BaseObject* record);

		char* getName(TES3::BaseObject* record);

		mwLong getValue(TES3::BaseObject* record);
		mwLong getValue(TES3::Reference* reference, bool multiplyByCount);

		mwFloat getWeight(TES3::BaseObject* record);
		mwFloat getWeight(TES3::Reference* reference, bool multiplyByCount);

		TES3::Enchantment* getEnchantment(TES3::BaseObject* record);

		char* getModel(TES3::BaseObject* record);

		TES3::BaseObject* getBaseRecord(TES3::BaseObject* reference);

		template <typename T>
		T* getAttachment(TES3::Reference* reference, TES3::AttachmentType attachmentType) {
			if (reference == NULL || reference->attachments == NULL) {
				return NULL;
			}

			TES3::BaseAttachment* attachment = reference->attachments;
			while (attachment && attachment->type != attachmentType) {
				attachment = attachment->next;
			}

			return reinterpret_cast<T*>(attachment);
		}

		TES3::MACP* getAttachedMACPRecord(TES3::Reference* reference);

		TES3::VariableAttachmentNode* getAttachedVariableNode(TES3::Reference* reference);

		TES3::LockAttachmentNode* getAttachedLockNode(TES3::Reference* reference);

		TES3::Spell* getSpellRecordById(const std::string& id);

		TES3::Enchantment* getEnchantRecordById(const std::string& id);

		TES3::Alchemy* getAlchemyRecordById(const std::string& id);

		size_t getEffectCount(const TES3::Effect* effectArray);

		bool setEffect(TES3::Effect * effects, mwLong index, mwLong effectId,
			mwLong skillAttributeId, mwLong range, mwLong area, mwLong duration,
			mwLong minimumMagnitude, mwLong maximumMagnitude);

		float getSkillRequirement(TES3::Reference* reference, mwLong skillId);

		void checkForSkillUp(TES3::Reference* reference, mwLong skillId);

		void checkForLevelUp(mwLong progress);

		// Used in xFirstNPC/Static/Item. The last element should never be non-null.
		// The first eight elements are pointers to the first reference from the 8 surrounding cells.
		extern TES3::Reference* exteriorRefs[9];

		void clearExteriorRefs();

		//
		// Original function calls in Morrowind.
		//

		typedef void* (__cdecl *ExternalRealloc)(void*, size_t);
		extern ExternalRealloc _realloc;
		void* realloc(void* address, size_t size);

		typedef void* (__cdecl *ExternalMalloc)(size_t);
		extern ExternalMalloc _malloc;
		void* malloc(size_t size);

		typedef void(__cdecl *ExternalFree)(void*);
		extern ExternalFree _free;
		void free(void* address);
	}
};
