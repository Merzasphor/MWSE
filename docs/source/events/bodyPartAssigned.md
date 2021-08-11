# bodyPartAssigned



```lua
--- @param e bodyPartAssignedEventData
local function bodyPartAssignedCallback(e)
end
event.register("bodyPartAssigned", bodyPartAssignedCallback)
```

## Event Data

* `manager` (tes3bodyPartManager): 
* `bodyPart` ([tes3bodyPart](../../types/tes3bodyPart)): 
* `index` (number): 
* `reference` ([tes3reference](../../types/tes3reference)): 
* `isFirstPerson` (boolean): 
* `object` ([tes3bodyPart](../../types/tes3bodyPart)): 

