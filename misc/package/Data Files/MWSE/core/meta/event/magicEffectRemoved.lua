--- @meta
--- @diagnostic disable:undefined-doc-name

--- This event triggers when a magic effect has been removed from an actor. This includes magic effects that have been resisted.
--- @class magicEffectRemovedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field caster tes3reference *Read-only*. The caster of the magic source that contained the magic effect. Can be `nil`.
--- @field effect tes3effect *Read-only*. The specific magic effect that triggered the event. This is equal to `e.source.effects[effectIndex]`. Can be `nil`.
--- @field effectIndex number *Read-only*. The index of the magic effect in the magic source's effects list.
--- @field mobile tes3mobileActor|tes3mobileCreature|tes3mobileNPC|tes3mobilePlayer *Read-only*. The mobile actor the magic effect is removed from.
--- @field reference tes3reference *Read-only*. The reference of the mobile actor the magic effect is removed from.
--- @field source tes3alchemy|tes3enchantment|tes3spell *Read-only*. The magic source that contains the effect.
--- @field sourceInstance tes3magicSourceInstance *Read-only*. The unique instance of the magic source that contains the effect.
--- @field target tes3reference *Read-only*. The target of the magic source that contained the magic effect. Can be `nil`.
