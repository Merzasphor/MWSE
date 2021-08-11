# soundObjectPlay



```lua
--- @type e event.soundObjectPlay
local function soundObjectPlayCallback(e)
end
event.register("soundObjectPlay", soundObjectPlayCallback)
```

This event can be filtered based on the **`sound`** event data.

## Event Data

* `pitch` (number): 
* `flags` (number): 
* `sound` ([tes3sound](../../types/tes3sound)): 
* `volume` (number): 
* `isNot3D` (boolean): 

