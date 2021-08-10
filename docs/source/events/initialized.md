# initialized

The initialized event fires when game code has finished initializing, and all .esm and .esp files have been loaded.

```lua
--- @type e event.initialized
local function initializedCallback(e)
end
event.register("initialized", initializedCallback)
```

