# playGroup



```lua
--- @param e playGroupEventData
local function playGroupCallback(e)
end
event.register("playGroup", playGroupCallback)
```

!!! tip
	This event can be filtered based on the **`reference`** event data.

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `animationData` (tes3animationData): 
* `flags` (number): 
* `group` (number): 
* `index` (number): 
* `loopCount` (number): 
* `reference` ([tes3reference](../../types/tes3reference)): 

