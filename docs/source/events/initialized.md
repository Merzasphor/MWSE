# initialized

The initialized event fires when game code has finished initializing, and all .esm and .esp files have been loaded.

```lua
--- @param e initializedEventData
local function initializedCallback(e)
end
event.register("initialized", initializedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

