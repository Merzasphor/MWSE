--- @meta

--- This event is raised when determining the value of a soul, unmodified by GMSTs. The value can be modified, or used to provide a soul value to NPCs who would normally not be allowed one.
--- @class calcSoulValueEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field actor tes3creature|tes3npc *Read-only*. The actor whose soul is being evaluated.
--- @field value number|nil The value of the actor's soul. This may be `nil` for NPCs.
