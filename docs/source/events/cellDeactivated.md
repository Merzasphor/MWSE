# cellDeactivated

This event is triggered when a cell is deactivated.

```lua
--- @type e event.cellDeactivated
local function cellDeactivatedCallback(e)
end
event.register("cellDeactivated", cellDeactivatedCallback)
```

This event can be filtered based on the **`cell`** event data.

## Event Data

* `cell` ([tes3cell](../../types/tes3cell)): The cell which was deactivated.

