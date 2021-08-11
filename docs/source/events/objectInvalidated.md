# objectInvalidated

This event is raised when reference is invalidated. This includes being removed from memory. This event can be used to safely remove references from tables.

```lua
--- @type e event.objectInvalidated
local function objectInvalidatedCallback(e)
end
event.register("objectInvalidated", objectInvalidatedCallback)
```

This event can be filtered based on the **`object`** event data.

## Event Data

* `object` (solObject): The object being invalidated. Can be a tes3reference.

