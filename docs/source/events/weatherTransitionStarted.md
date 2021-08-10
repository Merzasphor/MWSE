# weatherTransitionStarted

The weatherTransitionStarted event occurs when the currently simulated weather has started to gradually transition to a new weather.

```lua
--- @type e event.weatherTransitionStarted
local function weatherTransitionStartedCallback(e)
end
event.register("weatherTransitionStarted", weatherTransitionStartedCallback)
```

## Event Data

* `to` ([tes3weather](../../types/tes3weather)): The weather object that will be transitioned to.
* `from` ([tes3weather](../../types/tes3weather)): The weather object that is the current weather.

