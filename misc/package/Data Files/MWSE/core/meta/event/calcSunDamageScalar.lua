--- @meta

--- calcSunDamageScalar is used when calculating the amount of damage to apply for the Sun Damage magic effect.
--- @class calcSunDamageScalarEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field damage number The previously calculated sun damage.
calcSunDamageScalar = {}

