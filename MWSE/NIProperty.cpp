#include "NIProperty.h"

#include "MemoryUtil.h"

#include "NIBinaryStream.h"
#include "NIStream.h"
#include "NITexture.h"

namespace NI {

	//
	// NiProperty
	//

	const auto NI_Property_ctor = reinterpret_cast<Property * (__thiscall*)(Property*)>(0x405990);
	Property::Property() {
		NI_Property_ctor(this);
	}

	const auto NI_Property_dtor = reinterpret_cast<void(__thiscall*)(Property*)>(0x405B40);
	Property::~Property() {
		NI_Property_dtor(this);
	}

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

	void MaterialProperty::setAmbient_lua(sol::object value) {
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

	void MaterialProperty::setDiffuse_lua(sol::object value) {
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

	void MaterialProperty::setSpecular_lua(sol::object value) {
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

	void MaterialProperty::setEmissive_lua(sol::object value) {
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

	//
	// VertexColorProperty
	//

	VertexColorProperty::VertexColorProperty() {
		vTable.asProperty = (Property_vTable*)0x7464F8;
		source = 0;
		lighting = 1;
	}

	VertexColorProperty::~VertexColorProperty() {
	}

	Pointer<VertexColorProperty> VertexColorProperty::create() {
		return new VertexColorProperty();
	}

	//
	// NiZBufferProperty
	//

	ZBufferProperty::ZBufferProperty() {
		Property::Property();
		vTable.asProperty = (Property_vTable*)0x74652C;
		setFlag(false, 0);
		setFlag(false, 1);
		testFunction = TestFunction::LESS_EQUAL;
	}

	ZBufferProperty::~ZBufferProperty() {

	}

	void ZBufferProperty::loadBinary(Stream* stream) {
		// We don't want to do the normal NiProperty deserialization here.
		ObjectNET::_loadBinary(this, stream);

		// Get our raw flags.
		unsigned short rawFlags = 0;
		stream->inStream->read(&rawFlags, sizeof(rawFlags));

		// Assign the first two bits to property flags;
		flags = rawFlags & 0x3;

		// Check for the custom test function bit.
		if (rawFlags & 0x40) {
			testFunction = static_cast<TestFunction>((rawFlags >> 2) & 0xF);
		}
	}

	void ZBufferProperty::saveBinary(Stream* stream) const {
		// We don't want to do the normal NiProperty serialization here.
		ObjectNET::_saveBinary(this, stream);

		// Pack the flags with the test function.
		unsigned short serializedFlags = flags & 0x3;

		// If we're using a non-default test function, serialize it in the flags.
		if (testFunction != TestFunction::LESS_EQUAL) {
			serializedFlags |= (DWORD(testFunction) & 0xF) << 2;
			
			// We also need to set the custom "we're using a new test function" bit.
			serializedFlags |= 0x40;
		}

		// Write the property flags with the custom masking, instead of the usual field.
		stream->outStream->write(&serializedFlags, sizeof(serializedFlags));
	}

	Pointer<ZBufferProperty> ZBufferProperty::create() {
		return new ZBufferProperty();
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::Property)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::AlphaProperty)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::FogProperty)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::MaterialProperty)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::StencilProperty)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::TexturingProperty)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::VertexColorProperty)
MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_NI(NI::ZBufferProperty)
