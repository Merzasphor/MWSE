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

#include "TES3Attachment.h"
#include "TES3DataHandler.h"
#include "TES3Inventory.h"
#include "TES3Collections.h"
#include "TES3DataHandler.h"
#include "TES3Spell.h"

namespace mwse {
	namespace tes3 {
		TES3::WorldController * getWorldController();
		TES3::DataHandler * getDataHandler();
		TES3::Game * getGame();

		TES3::Reference* getReference(const char* id);
		TES3::Reference* getReference(std::string& id);

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

		void addObject(TES3::BaseObject* record);

		TES3::Reference* skipRemovedReferences(TES3::Reference* reference);

		bool getHasBaseRecord(TES3::BaseObject* record);

		TES3::IteratorNode<TES3::ItemStack> * getFirstInventoryNode(TES3::Reference* reference);

		bool hasInventory(TES3::BaseObject* record);

		long getValue(TES3::Reference* reference, bool multiplyByCount);

		float getWeight(TES3::Reference* reference, bool multiplyByCount);

		TES3::BaseObject* getBaseRecord(TES3::BaseObject* reference);

		template <typename T>
		T* getAttachment(TES3::Reference* reference, TES3::AttachmentType::AttachmentType attachmentType) {
			if (reference == NULL || reference->attachments == NULL) {
				return NULL;
			}

			TES3::Attachment* attachment = reference->attachments;
			while (attachment && attachment->type != attachmentType) {
				attachment = attachment->next;
			}

			return reinterpret_cast<T*>(attachment);
		}

		bool insertAttachment(TES3::Reference* reference, TES3::Attachment* attachment);

		TES3::MobileActor* getAttachedMobileActor(TES3::Reference* reference);
		TES3::MobileCreature* getAttachedMobileCreature(TES3::Reference* reference);
		TES3::MobileNPC* getAttachedMobileNPC(TES3::Reference* reference);
		TES3::MobilePlayer* getAttachedMobilePlayer(TES3::Reference* reference);

		TES3::ItemData* getAttachedItemDataNode(TES3::Reference* reference);

		TES3::LockAttachmentNode* getAttachedLockNode(TES3::Reference* reference);

		template <typename T>
		T* getObjectByID(const std::string& id, TES3::ObjectType::ObjectType type) {
			const char* objectID = id.c_str();

			TES3::Object * object;
			if (type == TES3::ObjectType::Spell) {
				object = getDataHandler()->nonDynamicData->spellsList->head;
			}
			else {
				object = getDataHandler()->nonDynamicData->list->head;
			}

			while (object != NULL && !(object->objectType == type && _stricmp(objectID, object->vTable.object->getObjectID(object)) == 0)) {
				object = object->nextInCollection;
			}

			return reinterpret_cast<T*>(object);
		}

		size_t getEffectCount(const TES3::Effect* effectArray);

		bool setEffect(TES3::Effect * effects, long index, long effectId,
			long skillAttributeId, long range, long area, long duration,
			long minimumMagnitude, long maximumMagnitude);

		float getSkillRequirement(TES3::Reference* reference, long skillId);

		void checkForLevelUp(long progress);

		void messagePlayer(const char* message);

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

		template <typename T>
		T* malloc(size_t size) {
			return reinterpret_cast<T*>(_malloc(size));
		}

		template <typename T>
		T* malloc() {
			T * ret = reinterpret_cast<T*>(_malloc(sizeof(T)));
			memset(ret, 0, sizeof(T));
			return ret;
		}

		typedef void(__cdecl *ExternalFree)(void*);
		extern ExternalFree _free;
		void free(void* address);
	}
};
