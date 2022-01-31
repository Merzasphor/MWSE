# spellCreated

This event is triggered when a new spell is created using spellmaking services or by a script using `tes3spell.create()`.

```lua
--- @param e spellCreatedEventData
local function spellCreatedCallback(e)
end
event.register(tes3.event.spellCreated, spellCreatedCallback)
```

!!! tip
	This event can be filtered based on the **`source`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `source` (string): Was the origin of the spell spellmaker or a script?  Maps to values in [`tes3.spellSource`](https://mwse.github.io/MWSE/references/spell-sources/) namespace.
* `spell` ([tes3spell](../../types/tes3spell)): A spell which was created.

