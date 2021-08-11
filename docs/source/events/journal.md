# journal

The journal event is invoked when a journal state progresses.

```lua
--- @param e journalEventData
local function journalCallback(e)
end
event.register("journal", journalCallback)
```

## Event Data

* `topic` ([tes3dialogue](../../types/tes3dialogue)): The topic that dictates the journal entry.
* `previousIndex` (number): The previous index of the journal state.
* `index` (number): The new index of the journal state.
* `new` (boolean): If true, the journal is newly added to the player. This effectively means that index has increased past 0.

