--- @meta

--- This event fires when an item is dropped.
--- @class itemDroppedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference The reference.
itemDropped = {}

