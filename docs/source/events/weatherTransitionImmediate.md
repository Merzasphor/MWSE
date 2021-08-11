# weatherTransitionImmediate

The weatherChangedImmediate event occurs when the currently simulated weather is changed without transition.

```lua
--- @type e event.weatherTransitionImmediate
local function weatherTransitionImmediateCallback(e)
end
event.register("weatherTransitionImmediate", weatherTransitionImmediateCallback)
```

## Event Data

* `to` ([tes3weather](../../types/tes3weather)): The weather object that is the new current weather.

