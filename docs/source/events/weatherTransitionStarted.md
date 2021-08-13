# weatherTransitionStarted

The weatherTransitionStarted event occurs when the currently simulated weather has started to gradually transition to a new weather.

```lua
--- @param e weatherTransitionStartedEventData
local function weatherTransitionStartedCallback(e)
end
event.register("weatherTransitionStarted", weatherTransitionStartedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `from` ([tes3weather](../../types/tes3weather)): The weather object that is the current weather.
* `to` ([tes3weather](../../types/tes3weather)): The weather object that will be transitioned to.

