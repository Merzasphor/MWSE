--- @meta

--- This event is triggered when a reference is deactivated.
--- @class referenceDeactivatedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference The reference which was deactivated.
referenceDeactivated = {}

