# referenceActivated

This event is triggered when a reference is activated.

```lua
--- @param e referenceActivatedEventData
local function referenceActivatedCallback(e)
end
event.register("referenceActivated", referenceActivatedCallback)
```

This event can be filtered based on the **`reference`** event data.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): The reference which was deactivated.

