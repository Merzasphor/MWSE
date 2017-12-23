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

		REFRRecord_t* skipRemovedReferences(REFRRecord_t* reference);

		bool getHasBaseRecord(TES3DefaultTemplate_t* record);

		TES3DefaultTemplate_t* getBaseRecord(TES3DefaultTemplate_t* reference);

		BaseRecord_t* getFirstAttachmentByType(REFRRecord_t* reference, RecordTypes::attachType_t attachmentType);

		MACPRecord_t* getAttachedMACPRecord(REFRRecord_t* reference);

		mwVarHolderNode_t* getAttachedVarHolderNode(REFRRecord_t* reference);

		mwLockNode_t* getAttachedLockNode(REFRRecord_t* reference);

		SPELRecord_t* getSpellRecordById(const mwseString_t& id);

		ENCHRecord_t* getEnchantRecordById(const mwseString_t& id);

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
	}
};
