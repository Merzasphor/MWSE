--- @meta

--- This event is raised when a container is closed.
--- @class containerClosedEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference The reference of the container that was closed.
containerClosed = {}

