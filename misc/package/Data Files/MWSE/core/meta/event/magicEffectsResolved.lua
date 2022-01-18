--- @meta

--- This event triggers after all magic effect links have been resolved. This event is used to add new spell effect by using [`tes3.addSpellEffect()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addmagiceffect) function. For examples of this event in practice see [`tes3.addMagicEffect()`](https://mwse.github.io/MWSE/apis/tes3/#tes3addmagiceffect) example.
--- @class magicEffectsResolvedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
