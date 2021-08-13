# soundObjectPlay



```lua
--- @param e soundObjectPlayEventData
local function soundObjectPlayCallback(e)
end
event.register("soundObjectPlay", soundObjectPlayCallback)
```

!!! tip
	This event can be filtered based on the **`sound`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `flags` (number): 
* `isNot3D` (boolean): 
* `pitch` (number): 
* `sound` ([tes3sound](../../types/tes3sound)): 
* `volume` (number): 

