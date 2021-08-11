# initialized

The initialized event fires when game code has finished initializing, and all .esm and .esp files have been loaded.

```lua
--- @param e initializedEventData
local function initializedCallback(e)
end
event.register("initialized", initializedCallback)
```

