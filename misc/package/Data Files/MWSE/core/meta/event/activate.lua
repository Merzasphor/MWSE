--- @meta

--- This event is invoked whenever something is activated, typically by the player. Activation is usually done with the associated activate/use key, but may also be forced by scripts.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/events/activate).
--- @class activateEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field activator tes3reference The actor attempting to trigger the event.
--- @field target tes3reference The reference that is being activated.
