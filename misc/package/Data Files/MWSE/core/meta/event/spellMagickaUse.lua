--- @meta

--- This event is triggered just before a spell or power is used by any actor. It allows modification of the magicka required to cast the spell. Magicka cost change is not reflected in the UI system, because the UI does not expect spell costs to change.
--- @class spellMagickaUseEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field caster tes3reference *Read-only*. The caster of the spell.
--- @field cost number The magicka cost required to cast the spell. May be modified. This value is rounded to an integer when used by the engine.
--- @field instance tes3magicSourceInstance The magic source instance.
--- @field spell tes3spell *Read-only*. The spell being cast.
