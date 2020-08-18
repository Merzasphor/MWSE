#include "NIProperty.h"

#include "MemoryUtil.h"

#include "NITexture.h"

namespace NI {

	//
	// NiProperty
	//

	PropertyType Property::getType() {
		return static_cast<PropertyType>(vTable.asProperty->getType(this));
	}

	void Property::update(float dt) {
		vTable.asProperty->update(this, dt);
	}

	//
	// NiFogProperty
	//

	std::reference_wrapper<unsigned char[4]> FogProperty::getColor() {
		return std::ref(color);
	}

	//
	// NiMaterialProperty
	//

	Color MaterialProperty::getAmbient() {
		return ambient;
	}

	void MaterialProperty::setAmbient(Color& value) {
		ambient = value;
		revisionID++;
	}


	Color MaterialProperty::getDiffuse() {
		return diffuse;
	}

	void MaterialProperty::setDiffuse(Color& value) {
		diffuse = value;
		revisionID++;
	}


	Color MaterialProperty::getSpecular() {
		return specular;
	}

	void MaterialProperty::setSpecular(Color& value) {
		specular = value;
		revisionID++;
	}


	Color MaterialProperty::getEmissive() {
		return emissive;
	}

	void MaterialProperty::setEmissive(Color& value) {
		emissive = value;
		revisionID++;
	}


	float MaterialProperty::getShininess() {
		return shininess;
	}

	void MaterialProperty::setShininess(float value) {
		shininess = value;
		revisionID++;
	}


	float MaterialProperty::getAlpha() {
		return alpha;
	}

	void MaterialProperty::setAlpha(float value) {
		alpha = value;
		revisionID++;
	}

	void MaterialProperty::incrementRevisionId() {
		revisionID++;
	}

	//
	// NiTexturingProperty
	//

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
			if (i >= maps.size()) {
				break;
			}

			if (maps[i] != nullptr) {
				count++;
			}
		}
		return count;
	}

	bool TexturingProperty::canAddDecalMap() const {
		return getDecalCount() < 7;
	}

	unsigned int TexturingProperty::addDecalMap(Texture* texture) {
		unsigned int index = (unsigned int)MapType::DECAL_FIRST;
		while (index < maps.size() && maps[index] != nullptr) {
			++index;
		}

		if (index > (size_t)MapType::DECAL_LAST) {
			return (size_t)MapType::INVALID;
		}

		maps.growToFit(index);

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

		if (index >= maps.size()) {
			return false;
		}

		if (maps[index] == nullptr) {
			return false;
		}

		delete maps[index];
		maps.setAtIndex(index, nullptr);
		return true;
	}

	bool TexturingProperty::removeDecal_lua(unsigned int index) {
		return removeDecal(index - 1);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::Property)
