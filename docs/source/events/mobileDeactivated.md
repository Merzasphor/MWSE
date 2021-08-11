# mobileDeactivated

This event is called when a Mobile Actor is deactivated. Typically this happens when transitioning through cells. When the player enters a cell, the mobileActivated event will fire for each new actor. When the player leaves the cell, the mobileDeactivated event is called.

```lua
--- @type e event.mobileDeactivated
local function mobileDeactivatedCallback(e)
end
event.register("mobileDeactivated", mobileDeactivatedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): The reference that the mobile has been deactivated for.

