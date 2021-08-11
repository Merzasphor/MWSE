# weatherChangedImmediate

The weatherChangedImmediate event occurs when the currently simulated weather is changed without transition. This can occur when going from an interior to an exterior in a new region, or while resting. This can interrupt weather transitions, which means the weatherTransitionFinished event will not be triggered.

```lua
--- @param e weatherChangedImmediateEventData
local function weatherChangedImmediateCallback(e)
end
event.register("weatherChangedImmediate", weatherChangedImmediateCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `to` ([tes3weather](../../types/tes3weather)): The weather object that is the new current weather. Can be modified to change behavior.

