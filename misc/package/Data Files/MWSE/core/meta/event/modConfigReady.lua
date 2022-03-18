--- @meta

--- This event fires once MWSE's internal mod configuration menu code has initialized. This event is used in mods to register settings configuration menu using MCM API.
---
--- [Examples available in online documentation](https://mwse.github.io/MWSE/events/modConfigReady).
--- @class modConfigReadyEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
