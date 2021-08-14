# levelUp

This even is called whenever the player successfully finishes leveling up.

```lua
--- @param e levelUpEventData
local function levelUpCallback(e)
end
event.register("levelUp", levelUpCallback)
```

!!! tip
	This event can be filtered based on the **`level`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `level` (number): *Read-only*. The new level obtained.

