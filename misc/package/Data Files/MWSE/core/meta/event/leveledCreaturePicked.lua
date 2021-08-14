--- @meta

--- This event is called after any leveled creature list is resolved. The event may be filtered by its list, and its pick can be overwritten. While this event allows for customization, the leveled list may be altered directly as well.
--- @class leveledCreaturePickedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field list tes3leveledCreature *Read-only*. The list responsible for creating a pick.
--- @field pick tes3creature The result of the pick by vanilla mechanism. This can be modified to change the result to something else.
