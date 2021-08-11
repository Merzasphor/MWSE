# spellCreated



```lua
--- @param e spellCreatedEventData
local function spellCreatedCallback(e)
end
event.register("spellCreated", spellCreatedCallback)
```

!!! tip
	This event can be filtered based on the **`source`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `source` (): 
* `spell` ([tes3spell](../../types/tes3spell)): 

