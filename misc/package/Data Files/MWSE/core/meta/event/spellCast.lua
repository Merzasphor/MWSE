--- @meta

--- This event is triggered just before a spell cast is resolved, at the end of the casting animation. It can control the success chance of the spell cast.
--- @class spellCastEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field source tes3spell The magic source.
--- @field weakestSchool number Of all the magic effects in the spell, there is a magic school which the caster has the lowest skill at casting. This school determines which skill will gain experience on a successful cast.
--- @field caster tes3reference The caster of the spell.
--- @field castChance number The percentage chance of the caster successfully casting the spell. May be modified. Setting it to 0 will cause the cast to fail.
spellCast = {}

