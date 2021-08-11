--- @meta

--- This event is used when calculating a creature's spell resistance, and allows Lua scripts to override the behavior of spell resistance by changing the resistedPercent value. This can be used to enable willpower-based resistance checks, provide specific resistances to specific spells, spells that heal instead of harm, and a variety of new mechanics.
--- @class spellResistEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field effectInstance tes3magicEffectInstance The unique instance of the magic effect.
--- @field target tes3reference The target of the spell. For self-targeted spells, this matches caster.
--- @field caster tes3reference The caster of the spell.
--- @field effectIndex number The index of the effect in source's effects list.
--- @field source tes3alchemy|tes3enchantment|tes3spell The magic source.
--- @field resistedPercent number The percent of the spell that has been resisted. This can be modified, but a value outside the range of 0 to 100 does not have consistent effects. For fire damage, for example, a value over 100 causes the spell to heal the target instead of harming them.
--- @field resistAttribute number The attribute resisted. This is an index into a tes3mobileActor.effectAttributes. Note that the index here is 0-based, while Lua is 1-based.
--- @field sourceInstance tes3magicSourceInstance The unique instance of the magic source.
spellResist = {}

