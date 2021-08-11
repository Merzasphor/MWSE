--- @meta

--- This event is raised when an in-world tes3reference for an item is about to be converted to fit into a tes3itemStack.
--- @class convertReferenceToItemEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference The reference about to be converted.
convertReferenceToItem = {}

