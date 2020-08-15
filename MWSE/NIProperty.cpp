#include "NIProperty.h"

#include "MemoryUtil.h"

#include "NITexture.h"

namespace NI {
	unsigned int TexturingProperty::getDecalCount() const {
		auto count = maps.at(0) == nullptr ? 0U : 1U;
		for (unsigned int i = (unsigned int)MapType::EXTRA_DECALS_FIRST; i <= (unsigned int)MapType::EXTRA_DECALS_LAST; i++) {
			if (i >= maps.storageCount) {
				break;
			}

			if (maps.storage[i] != nullptr) {
				count++;
			}
		}
		return count;
	}

	bool TexturingProperty::canAddDecalMap() const {
		return getDecalCount() < 8;
	}

	unsigned int TexturingProperty::addDecalMap(Texture* texture) {
		unsigned int index = maps.at((size_t)MapType::DECAL_0) == nullptr ? (size_t)MapType::DECAL_0 : (size_t)MapType::EXTRA_DECALS_FIRST;
		if (index != (size_t)MapType::DECAL_0) {
			while (index < maps.storageCount && maps.at(index) != nullptr) {
				++index;
			}
		}

		if (index > (size_t)MapType::EXTRA_DECALS_LAST) {
			return (size_t)MapType::INVALID;
		}

		if (maps.storageCount <= index) {
			maps.setSize(maps.storageCount + maps.growByCount);
		}

		auto map = mwse::tes3::_new<Map>();
		memset(map, 0, sizeof(Map));
		map->vTable = (void*)0x7465E8;
		map->clampMode = ClampMode::WRAP_S_WRAP_T;
		map->filterMode = FilterMode::BILERP;
		maps.setAtIndex(index, map);

		if (texture) {
			map->texture = texture;
		}

		return index;
	}

	sol::optional<std::tuple<TexturingProperty::Map*, unsigned int>> TexturingProperty::addDecalMap_lua(sol::optional<Texture*> texture) {
		auto index = addDecalMap(texture.value_or(nullptr));
		if (index == (size_t)MapType::INVALID) {
			return {};
		}
		return std::make_tuple(maps.at(index), index + 1);
	}
}
