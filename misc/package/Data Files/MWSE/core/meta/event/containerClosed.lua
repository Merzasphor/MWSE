--- @meta

--- This event is raised when a container is closed.
--- @class containerClosedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference *Read-only*. The reference of the container that was closed.
