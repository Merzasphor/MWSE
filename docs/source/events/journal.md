# journal

The journal event is invoked when a journal state progresses.

```lua
--- @param e journalEventData
local function journalCallback(e)
end
event.register(tes3.event.journal, journalCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `index` (number): *Read-only*. The new index of the journal state.
* `info` ([tes3dialogueInfo](../../types/tes3dialogueInfo)): *Read-only*. The info for the newly set journal index.
* `new` (boolean): *Read-only*. If true, the journal is newly added to the player. This effectively means that index has increased past 0.
* `previousIndex` (number): *Read-only*. The previous index of the journal state.
* `previousInfo` ([tes3dialogueInfo](../../types/tes3dialogueInfo), nil): *Read-only*. The info for the previously set journal index. If the journal entry is `new`ly added, this will be `nil`.
* `topic` ([tes3dialogue](../../types/tes3dialogue)): *Read-only*. The topic that dictates the journal entry.

