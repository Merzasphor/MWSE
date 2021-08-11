# playGroup



```lua
--- @type e event.playGroup
local function playGroupCallback(e)
end
event.register("playGroup", playGroupCallback)
```

This event can be filtered based on the **`reference`** event data.

## Event Data

* `animationData` (tes3animationData): 
* `index` (number): 
* `reference` ([tes3reference](../../types/tes3reference)): 
* `group` (number): 
* `flags` (number): 
* `loopCount` (number): 

