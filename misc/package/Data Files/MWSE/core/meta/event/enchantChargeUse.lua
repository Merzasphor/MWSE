--- @meta

--- This event is triggered just before an on-strike or on-use enchantment is used by any actor, and also by the UI system to label enchant charges. It allows modification of the charge required to use an enchantment.
--- @class enchantChargeUseEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field isCast boolean True if the calculation is for a on-strike or on-use action, false if for UI enchant charge display. The type of action is found at e.source.castType.
--- @field charge number The charge required to cast the enchantment. May be modified.
--- @field caster tes3reference The caster of the enchantment.
--- @field source tes3enchantment The enchantment being used or examined by the UI.
