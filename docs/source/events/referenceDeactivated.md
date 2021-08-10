# referenceDeactivated

This event is triggered when a reference is deactivated.

```lua
--- @type e event.referenceDeactivated
local function referenceDeactivatedCallback(e)
end
event.register("referenceDeactivated", referenceDeactivatedCallback)
```

This event can be filtered based on the **`reference`** event data.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): The reference which was deactivated.

