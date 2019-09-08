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

#include "mwseString.h"

#include "TES3Defines.h"

#include "TES3MagicEffect.h"

namespace mwse {
	namespace tes3 {
		TES3::Reference* getReference(const char* id);
		TES3::Reference* getReference(std::string& id);

		char* setDataString(char**, const char*);

		bool setEffect(TES3::Effect * effects, long index, long effectId,
			long skillAttributeId, long range, long area, long duration,
			long minimumMagnitude, long maximumMagnitude);

		void checkForLevelUp(long progress);

		void messagePlayer(const char* message);

		int getSkillNameGMST(int);
		int getAttributeNameGMST(int);
		int getCastRangeNameGMST(int);

		TES3::SoulGemData * addCustomSoulGem(TES3::Misc * item);
		TES3::SoulGemData * getSoulGemData(TES3::Misc * item);
		bool isSoulGem(TES3::Object* objectOrReference);

		TES3::ArmorSlotData * getArmorSlotData(int slot);
		void setArmorSlotData(TES3::ArmorSlotData * data);

		// Used in xFirstNPC/Static/Item. The last element should never be non-null.
		// The first eight elements are pointers to the first reference from the 8 surrounding cells.
		extern TES3::Reference* exteriorRefs[9];

		void clearExteriorRefs();

		void startNewGame();

		int getRestHoursInterrupted();
		void setRestHoursInterrupted(int);
		int getRestInterruptCount();
		void setRestInterruptCount(int);

		int resolveAssetPath(const char* path, char * out_buffer = nullptr);

		//
		// Original function calls in Morrowind.
		//

		int rand(unsigned int arg0 = 0);

		template <typename T>
		T * _new() {
			return reinterpret_cast<T*(__cdecl*)(size_t)>(0x727692)(sizeof(T));
		}

		void * _new(size_t size);

		template <typename T>
		void _delete(T * address) {
			const auto __delete = reinterpret_cast<void (__cdecl*)(T *)>(0x727530);
			__delete(address);
		}

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
