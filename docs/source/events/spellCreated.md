# spellCreated



```lua
--- @param e spellCreatedEventData
local function spellCreatedCallback(e)
end
event.register("spellCreated", spellCreatedCallback)
```

This event can be filtered based on the **`source`** event data.

## Event Data

* `source` (): 
* `spell` ([tes3spell](../../types/tes3spell)): 

