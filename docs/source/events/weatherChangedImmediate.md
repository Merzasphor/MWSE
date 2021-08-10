# weatherChangedImmediate

The weatherChangedImmediate event occurs when the currently simulated weather is changed without transition. This can occur when going from an interior to an exterior in a new region, or while resting. This can interrupt weather transitions, which means the weatherTransitionFinished event will not be triggered.

```lua
--- @type e event.weatherChangedImmediate
local function weatherChangedImmediateCallback(e)
end
event.register("weatherChangedImmediate", weatherChangedImmediateCallback)
```

## Event Data

* `to` ([tes3weather](../../types/tes3weather)): The weather object that is the new current weather. Can be modified to change behavior.

