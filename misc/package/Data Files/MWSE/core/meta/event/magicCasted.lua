--- @meta

--- This event is triggered when any spell or enchant is cast successfully, or when any alchemy item is used. This includes spells cast via scripts. For spells, this occurs at the end of the casting animation. For spells and enchants, it is just after the magic projectile has been constructed.
--- @class magicCastedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field source tes3alchemy|tes3enchantment|tes3spell The magic source.
--- @field target tes3reference The target of the spell. For self-targeted spells, this matches caster.
--- @field caster tes3reference The caster of the spell.
--- @field sourceInstance tes3magicSourceInstance The unique instance of the magic source.
