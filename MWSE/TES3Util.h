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
		__declspec(dllexport) TES3::Reference* getReference(const char* id);
		__declspec(dllexport) TES3::Reference* getReference(std::string& id);

		__declspec(dllexport) char* setDataString(char**, const char*);

		__declspec(dllexport) unsigned int* getBaseEffectFlags();
		__declspec(dllexport) bool getBaseEffectFlag(int index, TES3::EffectFlag::Flag flag);
		__declspec(dllexport) void setBaseEffectFlag(int index, TES3::EffectFlag::Flag flag, bool set);

		__declspec(dllexport) bool setEffect(TES3::Effect * effects, long index, long effectId,
			long skillAttributeId, long range, long area, long duration,
			long minimumMagnitude, long maximumMagnitude);

		__declspec(dllexport) void checkForLevelUp(long progress);

		__declspec(dllexport) void messagePlayer(const char* message);

		__declspec(dllexport) int getSkillNameGMST(int);
		__declspec(dllexport) int getAttributeNameGMST(int);
		__declspec(dllexport) int getCastRangeNameGMST(int);

		__declspec(dllexport) TES3::SoulGemData * addCustomSoulGem(TES3::Misc * item);
		__declspec(dllexport) TES3::SoulGemData * getSoulGemData(TES3::Misc * item);
		__declspec(dllexport) bool isSoulGem(TES3::Object* objectOrReference);

		__declspec(dllexport) TES3::ArmorSlotData * getArmorSlotData(int slot);
		__declspec(dllexport) void setArmorSlotData(TES3::ArmorSlotData * data);

		// Used in xFirstNPC/Static/Item. The last element should never be non-null.
		// The first eight elements are pointers to the first reference from the 8 surrounding cells.
		extern TES3::Reference* exteriorRefs[9];

		void clearExteriorRefs();

		__declspec(dllexport) void startNewGame();

		__declspec(dllexport) int getRestHoursInterrupted();
		__declspec(dllexport) void setRestHoursInterrupted(int);
		__declspec(dllexport) int getRestInterruptCount();
		__declspec(dllexport) void setRestInterruptCount(int);

		__declspec(dllexport) int resolveAssetPath(const char* path, char * out_buffer = nullptr);

		//
		// Original function calls in Morrowind.
		//

		template <typename T>
		__declspec(dllexport) T * _new() {
			return reinterpret_cast<T*(__cdecl*)(size_t)>(0x727692)(sizeof(T));
		}

		__declspec(dllexport) void * _new(size_t size);

		template <typename T>
		__declspec(dllexport) void _delete(T * address) {
			const auto __delete = reinterpret_cast<void (__cdecl*)(T *)>(0x727530);
			__delete(address);
		}

		typedef void* (__cdecl *ExternalRealloc)(void*, size_t);
		extern ExternalRealloc _realloc;
		__declspec(dllexport) void* realloc(void* address, size_t size);

		typedef void* (__cdecl *ExternalMalloc)(size_t);
		extern ExternalMalloc _malloc;
		__declspec(dllexport) void* malloc(size_t size);

		template <typename T>
		__declspec(dllexport) T* malloc(size_t size) {
			return reinterpret_cast<T*>(_malloc(size));
		}

		template <typename T>
		__declspec(dllexport) T* malloc() {
			T * ret = reinterpret_cast<T*>(_malloc(sizeof(T)));
			memset(ret, 0, sizeof(T));
			return ret;
		}

		typedef void(__cdecl *ExternalFree)(void*);
		extern ExternalFree _free;
		__declspec(dllexport) void free(void* address);
	}
};
