# cellChanged

The cellChanged event is occurs when the player changes cells. This might occur from going through a door, using intervention or recall spells, or from scripted repositioning.

```lua
--- @param e cellChangedEventData
local function cellChangedCallback(e)
end
event.register("cellChanged", cellChangedCallback)
```

!!! tip
	This event can be filtered based on the **`cell`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `cell` ([tes3cell](../../types/tes3cell)): *Read-only*. The new cell that the player has entered.
* `previousCell` ([tes3cell](../../types/tes3cell)): *Read-only*. The previous cell that the player came from. This will be nil when loading a game.

