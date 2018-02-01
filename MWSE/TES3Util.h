/************************************************************************

	TES3Util.h - Copyright (c) 2008 The MWSE Project
	http://www.sourceforge.net/projects/mwse

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

#include "mwseTypes.h"
#include "mwseString.h"

namespace mwse
{
	namespace tes3
	{
		TES3CellMaster_t * getCellMaster();

		GLOBRecord_t* getGlobalRecord(const char* id);
		GLOBRecord_t* getGlobalRecord(const std::string& id);

		TES3DefaultTemplate_t* getTemplate(const char *id);
		TES3DefaultTemplate_t* getTemplate(const std::string& id);

		template <typename T>
		T* getRecordById(const char* id) {
			return reinterpret_cast<T*>(getTemplate(id));
		}

		template <typename T>
		T* getRecordById(const std::string& id) {
			return reinterpret_cast<T*>(getTemplate(id.c_str()));
		}

		SCPTRecord_t* getScript(const char* id);
		SCPTRecord_t* getScript(const std::string& id);

		void addObject(BaseRecord_t* record);

		REFRRecord_t* skipRemovedReferences(REFRRecord_t* reference);

		bool getHasBaseRecord(TES3DefaultTemplate_t* record);

		IteratorNode_t<InventoryNode_t> * getFirstInventoryNode(REFRRecord_t* reference);

		bool hasInventory(BaseRecord_t* record);

		char* getName(BaseRecord_t* record);

		mwLong_t getValue(BaseRecord_t* record);
		mwLong_t getValue(REFRRecord_t* reference, bool multiplyByCount);

		mwFloat_t getWeight(BaseRecord_t* record);
		mwFloat_t getWeight(REFRRecord_t* reference, bool multiplyByCount);

		ENCHRecord_t* getEnchantment(TES3DefaultTemplate_t* record);

		char* getModel(BaseRecord_t* record);

		TES3DefaultTemplate_t* getBaseRecord(TES3DefaultTemplate_t* reference);

		BaseRecord_t* getFirstAttachmentByType(REFRRecord_t* reference, RecordTypes::attachType_t attachmentType);

		MACPRecord_t* getAttachedMACPRecord(REFRRecord_t* reference);

		mwVarHolderNode_t* getAttachedVarHolderNode(REFRRecord_t* reference);

		mwLockNode_t* getAttachedLockNode(REFRRecord_t* reference);

		SPELRecord_t* getSpellRecordById(const std::string& id);

		ENCHRecord_t* getEnchantRecordById(const std::string& id);

		ALCHRecord_t* getAlchemyRecordById(const std::string& id);

		size_t getEffectCount(const Effect_t* effectArray);

		bool setEffect(Effect_t * effects, mwLong_t index, mwLong_t effectId,
			mwLong_t skillAttributeId, mwLong_t range, mwLong_t area, mwLong_t duration,
			mwLong_t minimumMagnitude, mwLong_t maximumMagnitude);

		float getSkillRequirement(REFRRecord_t* reference, mwLong_t skillId);

		void checkForSkillUp(REFRRecord_t* reference, mwLong_t skillId);

		void checkForLevelUp(mwLong_t progress);

		// Used in xFirstNPC/Static/Item. The last element should never be non-null.
		// The first eight elements are pointers to the first reference from the 8 surrounding cells.
		extern REFRRecord_t* exteriorRefs[9];

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
