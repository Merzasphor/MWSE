--- @meta

--- The journal event is invoked when a journal state progresses.
--- @class journalEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field topic tes3dialogue The topic that dictates the journal entry.
--- @field previousIndex number The previous index of the journal state.
--- @field index number The new index of the journal state.
--- @field new boolean If true, the journal is newly added to the player. This effectively means that index has increased past 0.
