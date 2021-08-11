# weatherTransitionImmediate

The weatherChangedImmediate event occurs when the currently simulated weather is changed without transition.

```lua
--- @param e weatherTransitionImmediateEventData
local function weatherTransitionImmediateCallback(e)
end
event.register("weatherTransitionImmediate", weatherTransitionImmediateCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `to` ([tes3weather](../../types/tes3weather)): The weather object that is the new current weather.

