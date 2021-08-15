--- @meta

--- An active magic effect.
--- @class tes3activeMagicEffect
--- @field attributeId number *Read-only*. The attribute ID (note that this may be the skill ID if the effect affects skills).
--- @field duration number *Read-only*. The total duration of this specific effect.
--- @field effectId number *Read-only*. The magic effect ID.
--- @field effectIndex number *Read-only*. The index of the effect inside the magic source instance.
--- @field effectInstance tes3magicEffectInstance *Read-only*. The magic effect instance for this effect.
--- @field harmful boolean *Read-only*. This flag that determines if this effect is counted as a hostile action.
--- @field instance tes3magicSourceInstance *Read-only*. The magic source instance for this effect.
--- @field isSummon boolean *Read-only*. No description yet available.
--- @field magnitude number *Read-only*. The unresisted magnitude of the magic effect, that is the magnitude before resistance attributes are applied. This is always an integer number. To find the actual applied magnitude, you must check the magic effect instance.
--- @field magnitudeMin number *Read-only*. Deprecated.
--- @field mobile tes3magicSourceInstance *Read-only*. The mobile affected by the magic effect.
--- @field next tes3activeMagicEffect *Read-only*. Deprecated.
--- @field previous tes3activeMagicEffect *Read-only*. Deprecated.
--- @field serial number *Read-only*. The magic source instance serial number. See the `instance` and `effectInstance` properties to easily access the magic and effect instances.
--- @field skillId number *Read-only*. The skill ID (note that this may be the attribute ID if the effect affects attributes).
tes3activeMagicEffect = {}

