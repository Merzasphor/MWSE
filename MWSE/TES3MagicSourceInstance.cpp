#include "TES3MagicSourceInstance.h"

#include "LuaUtil.h"

namespace TES3 {
	MagicSourceCombo::MagicSourceCombo() {
		source.asGeneric = nullptr;
		sourceType = MagicSourceType::Invalid;
	}

	MagicSourceCombo::MagicSourceCombo(Object* object) : MagicSourceCombo() {
		if (object == nullptr) {
			return;
		}

		switch (object->objectType) {
		case TES3::ObjectType::Alchemy:
			sourceType = MagicSourceType::Alchemy;
			break;
		case TES3::ObjectType::Enchantment:
			sourceType = MagicSourceType::Enchantment;
			break;
		case TES3::ObjectType::Spell:
			sourceType = MagicSourceType::Spell;
			break;
		default:
			return;
		}
		source.asGeneric = object;
	}

	const auto TES3_MagicSourceCombo_getSourceEffects = reinterpret_cast<Effect * (__thiscall*)(const MagicSourceCombo *)>(0x496FA0);
	Effect * MagicSourceCombo::getSourceEffects() const {
		return TES3_MagicSourceCombo_getSourceEffects(this);
	}

	nonstd::span<Effect> MagicSourceCombo::getEffectSpan() const {
		auto result = TES3_MagicSourceCombo_getSourceEffects(this);
		if (result) {
			return nonstd::span(result, 8);
		}
		return {};
	}

	const auto TES3_MagicSourceInstance_getMagnitudeForIndex = reinterpret_cast<int(__thiscall*)(const MagicSourceInstance *, int)>(0x518380);
	int MagicSourceInstance::getMagnitude(int effectIndex) const {
		return TES3_MagicSourceInstance_getMagnitudeForIndex(this, effectIndex);
	}

	const auto TES3_PlaySpellVFX = reinterpret_cast<void(__cdecl *)(MagicSourceInstance *, float, Vector3, Reference*, int, PhysicalObject*, int, int)>(0x515D60);
	void MagicSourceInstance::playSpellVFX(float duration, Vector3 position, Reference* attachedReference, int unknown0, PhysicalObject* effectVisual, int effectIndex, int unknown1) {
		TES3_PlaySpellVFX(this, duration, position, attachedReference, unknown0, effectVisual, effectIndex, unknown1);
	}

	const auto TES3_MagicSourceInstance_retire = reinterpret_cast<void(__thiscall*)(MagicSourceInstance*, TES3::Reference*)>(0x512940);
	void MagicSourceInstance::retire(TES3::Reference* reference) {
		TES3_MagicSourceInstance_retire(this, reference);
	}

	Object* MagicSourceInstance::getSourceObject() const {
		return sourceCombo.source.asGeneric;
	}

	MagicSourceType MagicSourceInstance::getSourceType() const {
		return sourceCombo.sourceType;
	}

	nonstd::span<Effect> MagicSourceInstance::getSourceEffects() const {
		return sourceCombo.getEffectSpan();
	}

	void MagicSourceInstance::playSpellVFX_lua(sol::table params) {
		int effectIndex = mwse::lua::getOptionalParam<int>(params, "effectIndex", -1);
		if (effectIndex < 0 || effectIndex > 7) {
			throw std::invalid_argument("Invalid 'effectIndex' parameter. Must be a number between 0 and 7.");
		}

		auto position = mwse::lua::getOptionalParamVector3(params, "position");
		if (!position) {
			throw std::invalid_argument("Invalid 'position' parameter. Must be a table[3] or tes3vector3.");
		}

		auto visual = mwse::lua::getOptionalParamObject<PhysicalObject>(params, "visual");
		if (visual == nullptr) {
			throw std::invalid_argument("Invalid 'visual' parameter. Must be a valid tes3physicalObject or string that can resolve into one.");
		}

		float duration = mwse::lua::getOptionalParam<float>(params, "duration", 1.0f);
		TES3::Reference* reference = mwse::lua::getOptionalParamExecutionReference(params);

		playSpellVFX(duration, position.value(), reference, 0, visual, effectIndex, 0);
	}
}

MWSE_SOL_CUSTOMIZED_PUSHER_DEFINE_TES3(TES3::MagicSourceInstance)
