# preLevelUp

This event is triggered just before the player levels up.

```lua
--- @param e preLevelUpEventData
local function preLevelUpCallback(e)
end
event.register("preLevelUp", preLevelUpCallback)
```

This event can be filtered based on the **`level`** event data.

## Event Data

* `level` (number): The new level about to be obtained.

