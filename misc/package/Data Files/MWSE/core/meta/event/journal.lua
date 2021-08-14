--- @meta

--- The journal event is invoked when a journal state progresses.
--- @class journalEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field index number *Read-only*. The new index of the journal state.
--- @field new boolean *Read-only*. If true, the journal is newly added to the player. This effectively means that index has increased past 0.
--- @field previousIndex number *Read-only*. The previous index of the journal state.
--- @field topic tes3dialogue *Read-only*. The topic that dictates the journal entry.
