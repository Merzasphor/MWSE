# bodyPartAssigned



```lua
--- @param e bodyPartAssignedEventData
local function bodyPartAssignedCallback(e)
end
event.register("bodyPartAssigned", bodyPartAssignedCallback)
```

!!! tip
	This event supports blocking by setting `e.block` to `true` or returning `false`. Blocking the event prevents vanilla behavior from happening. For example, blocking an `equip` event prevents the item from being equipped.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `bodyPart` ([tes3bodyPart](../../types/tes3bodyPart)): 
* `index` (number): 
* `isFirstPerson` (boolean): 
* `manager` (tes3bodyPartManager): 
* `object` ([tes3bodyPart](../../types/tes3bodyPart)): 
* `reference` ([tes3reference](../../types/tes3reference)): 

