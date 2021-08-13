# playItemSound



```lua
--- @param e playItemSoundEventData
local function playItemSoundCallback(e)
end
event.register("playItemSound", playItemSoundCallback)
```

!!! tip
	This event can be filtered based on the **`item`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `item` ([tes3baseObject](../../types/tes3baseObject)): 
* `reference` ([tes3reference](../../types/tes3reference)): 
* `state` (number): 

