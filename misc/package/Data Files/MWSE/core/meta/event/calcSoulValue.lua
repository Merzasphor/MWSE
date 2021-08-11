--- @meta

--- This event is raised when determining the value of a soul, unmodified by GMSTs. The value can be modified, or used to provide a soul value to NPCs who would normally not be allowed one.
--- @class calcSoulValueEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field value number The value of the actor's soul.
--- @field actor tes3creature|tes3npc The actor whose soul is being evaluated.
calcSoulValue = {}

