--- @meta

--- Contains information from a standard UI callback. This is the parameter passed to callbacks when using `:register`, `:registerBefore`, or `:registerAfter`.
--- @class tes3uiEventData
--- @field forwardSource tes3uiElement *Read-only*. No description yet available.
--- @field id number *Read-only*. The ID of the event that is being triggered.
--- @field relativeX number|nil *Read-only*. For mouse-related events, this is the relative horizontal position for the current element.
--- @field relativeY number|nil *Read-only*. For mouse-related events, this is the relative vertical position for the current element.
--- @field source tes3uiElement *Read-only*. The element that owns the event.
--- @field widget tes3uiElement *Read-only*. No description yet available.
tes3uiEventData = {}

