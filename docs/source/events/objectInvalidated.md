# objectInvalidated

This event is raised when reference is invalidated. This includes being removed from memory. This event can be used to safely remove references from tables.

```lua
--- @param e objectInvalidatedEventData
local function objectInvalidatedCallback(e)
end
event.register(tes3.event.objectInvalidated, objectInvalidatedCallback)
```

!!! tip
	This event can be filtered based on the **`object`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `object` ([tes3baseObject](../../types/tes3baseObject)): *Read-only*. The object being invalidated. Can be a tes3reference.

