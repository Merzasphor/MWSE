# preLevelUp

This event is triggered just before the player levels up.

```lua
--- @param e preLevelUpEventData
local function preLevelUpCallback(e)
end
event.register(tes3.event.preLevelUp, preLevelUpCallback)
```

!!! tip
	This event can be filtered based on the **`level`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `level` (number): *Read-only*. The new level about to be obtained.

