# itemDropped

This event fires when an item is dropped.

```lua
--- @type e event.itemDropped
local function itemDroppedCallback(e)
end
event.register("itemDropped", itemDroppedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): The reference.

