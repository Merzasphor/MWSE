--- @meta

--- This event is triggered when a reference is deactivated.
--- @class referenceDeactivatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference The reference which was deactivated.
