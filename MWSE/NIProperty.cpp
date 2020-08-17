#include "NIProperty.h"

#include "MemoryUtil.h"

#include "NITexture.h"

namespace NI {
	void* TexturingProperty::Map::operator new(size_t size) {
		return mwse::tes3::_new(size);
	}

	void TexturingProperty::Map::operator delete(void* address) {
		mwse::tes3::_delete(address);
	}

	const auto NI_TexturingProperty_Map_ctor = reinterpret_cast<TexturingProperty::Map * (__thiscall*)(TexturingProperty::Map*)>(0x42DCD0);
	TexturingProperty::Map::Map() {
		NI_TexturingProperty_Map_ctor(this);
	}

	const auto NI_TexturingProperty_Map_ctorWithParams = reinterpret_cast<TexturingProperty::Map * (__thiscall*)(TexturingProperty::Map*, Texture*, unsigned int, TexturingProperty::ClampMode, TexturingProperty::FilterMode)>(0x4CEEC0);
	TexturingProperty::Map::Map(Texture* _texture, ClampMode _clampMode, FilterMode _filterMode, unsigned int _textCoords) {
		NI_TexturingProperty_Map_ctorWithParams(this, _texture, _textCoords, _clampMode, _filterMode);
	}

	TexturingProperty::Map::~Map() {
		texture = nullptr;
		vTable->destructor(this, false);
	}

	TexturingProperty::BumpMap::BumpMap() : Map() {
		vTable = (VirtualTable*)0x7507B0;
		lumaScale = 1.0f;
		lumaOffset = 0.0f;
		bumpMat[0][0] = 0.5f;
		bumpMat[0][1] = 0.0f;
		bumpMat[1][0] = 0.0f;
		bumpMat[1][1] = 0.5f;
	}

	TexturingProperty::BumpMap::BumpMap(Texture* _texture, ClampMode _clampMode, FilterMode _filterMode, unsigned int _textCoords) : Map(_texture, _clampMode, _filterMode, _textCoords) {
		vTable = (VirtualTable*)0x7507B0;
		lumaScale = 1.0f;
		lumaOffset = 0.0f;
		bumpMat[0][0] = 0.5f;
		bumpMat[0][1] = 0.0f;
		bumpMat[1][0] = 0.0f;
		bumpMat[1][1] = 0.5f;
	}

	unsigned int TexturingProperty::getDecalCount() const {
		auto count = 0;
		for (unsigned int i = (unsigned int)MapType::DECAL_FIRST; i <= (unsigned int)MapType::DECAL_LAST; i++) {
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
		//return getDecalCount() < 7;
		return true;
	}

	unsigned int TexturingProperty::addDecalMap(Texture* texture) {
		unsigned int index = (unsigned int)MapType::DECAL_FIRST;
		while (index < maps.storageCount && maps.at(index) != nullptr) {
			++index;
		}

		if (index > (size_t)MapType::DECAL_LAST) {
			return (size_t)MapType::INVALID;
		}

		if (maps.storageCount <= index) {
			maps.setSize(maps.storageCount + maps.growByCount);
		}

		auto map = new Map(texture);
		maps.setAtIndex(index, map);

		return index;
	}

	sol::optional<std::tuple<TexturingProperty::Map*, unsigned int>> TexturingProperty::addDecalMap_lua(sol::optional<Texture*> texture) {
		auto index = addDecalMap(texture.value_or(nullptr));
		if (index == (size_t)MapType::INVALID) {
			return {};
		}
		return std::make_tuple(maps.at(index), index + 1);
	}

	bool TexturingProperty::removeDecal(unsigned int index) {
		if (index < (unsigned int)MapType::DECAL_FIRST || index >(unsigned int)MapType::DECAL_LAST) {
			throw std::invalid_argument("Invalid map index provided.");
		}

		if (index >= maps.storageCount) {
			return false;
		}

		if (maps.storage[index] == nullptr) {
			return false;
		}

		delete maps.storage[index];
		Map* temp = nullptr;
		maps.setAtIndex(index, temp);
		return true;
	}

	bool TexturingProperty::removeDecal_lua(unsigned int index) {
		return removeDecal(index - 1);
	}
}
