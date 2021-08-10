# playItemSound



```lua
--- @type e event.playItemSound
local function playItemSoundCallback(e)
end
event.register("playItemSound", playItemSoundCallback)
```

This event can be filtered based on the **`table: 0x00e60a20`** event data.

## Event Data

* `state` (number): 
* `item` ([tes3baseObject](../../types/tes3baseObject)): 
* `reference` ([tes3reference](../../types/tes3reference)): 

