# cellActivated

This event is triggered when a cell is activated.

```lua
--- @type e event.cellActivated
local function cellActivatedCallback(e)
end
event.register("cellActivated", cellActivatedCallback)
```

This event can be filtered based on the **`cell`** event data.

## Event Data

* `cell` ([tes3cell](../../types/tes3cell)): The cell which was activated.

