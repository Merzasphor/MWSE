# weatherCycled

The weatherCycled event occurs when region weathers are randomized.

```lua
--- @param e weatherCycledEventData
local function weatherCycledCallback(e)
end
event.register("weatherCycled", weatherCycledCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

