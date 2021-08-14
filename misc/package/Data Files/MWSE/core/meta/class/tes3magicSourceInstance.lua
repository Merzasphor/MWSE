--- @meta

--- A game structure that keeps track of a magic source on an object.
--- @class tes3magicSourceInstance : tes3baseObject
--- @field castChanceOverride number No description yet available.
--- @field caster tes3reference *Read-only*. No description yet available.
--- @field item tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. No description yet available.
--- @field itemData tes3itemData *Read-only*. No description yet available.
--- @field itemID string *Read-only*. No description yet available.
--- @field magicID string *Read-only*. No description yet available.
--- @field projectile tes3mobileProjectile|tes3mobileSpellProjectile *Read-only*. No description yet available.
--- @field serialNumber number *Read-only*. Unique indentifier for just this magic source.
--- @field source tes3alchemy|tes3enchantment|tes3spell *Read-only*. No description yet available.
--- @field sourceEffects table *Read-only*. An array-style table holding spell effects this magic source has.
--- @field sourceType number *Read-only*. The type of this magic source. Maps to tes3.magicSourceType.* constants.
--- @field state number Shows if the state is pre-cast, cast, beginning, working, ending, retired, etc.
--- @field target tes3reference *Read-only*. No description yet available.
--- @field timestampCastBegin number No description yet available.
tes3magicSourceInstance = {}

--- Gets the magic effect instance for a given effect index and target reference. Effect instances may not all be active on a target, due to reflect, absorption, dispels, different durations and other factors.
--- @param index number The index in the effect list to fetch, between 0 and 7.
--- @param target tes3reference The target actor for the effect.
--- @return tes3magicEffectInstance result No description yet available.
function tes3magicSourceInstance:getEffectInstance(index, target) end

--- Gets the magnitude from the casting source for a given effect index.
--- @param index number The index in the effect list to fetch, between 0 and 7.
--- @return number result No description yet available.
function tes3magicSourceInstance:getMagnitudeForIndex(index) end

--- This function plays an effect from tes3magicSourceInstance of a given index.
function tes3magicSourceInstance:playVisualEffect() end

