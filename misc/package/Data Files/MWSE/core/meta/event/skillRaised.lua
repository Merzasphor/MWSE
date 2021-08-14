--- @meta

--- This event is invoked whenever the player naturally gains a new level a skill. This is typically through exercise, training, or reading books.
--- @class skillRaisedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field level number *Read-only*. The new level of the skill.
--- @field skill number *Read-only*. The skill that gained a new level experience.
--- @field source  
