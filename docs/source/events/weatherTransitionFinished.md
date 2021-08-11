# weatherTransitionFinished

The weatherTransitionFinished event occurs when the currently simulated weather finished transitioning to a new weather.

```lua
--- @param e weatherTransitionFinishedEventData
local function weatherTransitionFinishedCallback(e)
end
event.register("weatherTransitionFinished", weatherTransitionFinishedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `to` ([tes3weather](../../types/tes3weather)): The weather object that will be transitioned to.

