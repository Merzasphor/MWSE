# convertReferenceToItem

This event is raised when an in-world tes3reference for an item is about to be converted to fit into a tes3itemStack.

```lua
--- @param e convertReferenceToItemEventData
local function convertReferenceToItemCallback(e)
end
event.register("convertReferenceToItem", convertReferenceToItemCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): The reference about to be converted.

