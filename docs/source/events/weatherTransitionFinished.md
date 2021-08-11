# weatherTransitionFinished

The weatherTransitionFinished event occurs when the currently simulated weather finished transitioning to a new weather.

```lua
--- @param e weatherTransitionFinishedEventData
local function weatherTransitionFinishedCallback(e)
end
event.register("weatherTransitionFinished", weatherTransitionFinishedCallback)
```

## Event Data

* `to` ([tes3weather](../../types/tes3weather)): The weather object that will be transitioned to.

