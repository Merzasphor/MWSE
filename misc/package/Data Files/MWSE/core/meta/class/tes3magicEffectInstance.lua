--- @meta
--- @diagnostic disable:undefined-doc-name

--- Represents an individual instance of a magic effect being applied to a reference.
--- @class tes3magicEffectInstance
--- @field createdData tes3equipmentStack *Read-only*. The bound or summoned data associated with the instance, for summoned creatures or items. The stack's object will be a reference in the case of summoned creatures.
--- @field cumulativeMagnitude number No description yet available.
--- @field effectiveMagnitude number The effective magnitude of the effect, after all resistances are applied.
--- @field lastUsedArmor tes3armor *Read-only*. No description yet available.
--- @field lastUsedEnchItem tes3alchemy|tes3apparatus|tes3armor|tes3book|tes3clothing|tes3ingredient|tes3light|tes3lockpick|tes3misc|tes3probe|tes3repairTool|tes3weapon *Read-only*. No description yet available.
--- @field lastUsedLight tes3light *Read-only*. No description yet available.
--- @field lastUsedShield tes3armor *Read-only*. No description yet available.
--- @field lastUsedWeapon tes3weapon *Read-only*. No description yet available.
--- @field magnitude number The magnitude of the effect, before any resistances are applied.
--- @field resistedPercent number The percentage of the magic effect that has been resisted. A value of `100` indicates that the magic effect has been completely resisted, whereas a value of `0` indicates it has not been resisted and is applied with its full magnitude. Values over `100` cause the magic effect to heal the actor instead of harming it, if it is a damaging magic effect.
--- @field state number The state of this magic effect instance. Maps to [`tes3.spellState`](https://mwse.github.io/MWSE/references/spell-states/) constants.
--- @field target tes3reference No description yet available.
--- @field timeActive number No description yet available.
--- @field visual number No description yet available.
tes3magicEffectInstance = {}

