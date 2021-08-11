--- @meta

--- This event is raised when reference is invalidated. This includes being removed from memory. This event can be used to safely remove references from tables.
--- @class objectInvalidatedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field object solObject The object being invalidated. Can be a tes3reference.
objectInvalidated = {}

