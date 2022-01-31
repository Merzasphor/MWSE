# containerClosed

This event is raised when a container is closed.

```lua
--- @param e containerClosedEventData
local function containerClosedCallback(e)
end
event.register(tes3.event.containerClosed, containerClosedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. The reference of the container that was closed.

