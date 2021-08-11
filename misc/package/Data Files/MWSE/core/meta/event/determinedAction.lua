--- @meta

--- This event fires when an actor has determined an action in a combat session.
--- @class determinedActionEventData
--- @field block boolean If set to `true`, vanilla logic will be suppressed. Returning `false` will set this to `true`.
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field session tes3combatSession The combat session the action has been determined for.
determinedAction = {}

