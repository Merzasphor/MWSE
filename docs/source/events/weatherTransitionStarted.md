# weatherTransitionStarted

The **weatherTransitionStarted** event occurs when the currently simulated weather has started to gradually transition to a new weather. This can occur when moving between regions, or when the weather cycles.

Weather will not start transitioning in interiors, but will continue transitioning, and may finish while in an interior. The transition may be interrupted at any time by the [weatherChangedImmediate](https://mwse.github.io/MWSE/events/weatherChangedImmediate) event, and the [weatherTransitionFinished](https://mwse.github.io/MWSE/events/weatherTransitionFinished) event will not occur.

```lua
--- @param e weatherTransitionStartedEventData
local function weatherTransitionStartedCallback(e)
end
event.register(tes3.event.weatherTransitionStarted, weatherTransitionStartedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `from` ([tes3weather](../../types/tes3weather)): *Read-only*. The weather object that is the current weather.
* `to` ([tes3weather](../../types/tes3weather)): The weather object that will be transitioned to.

