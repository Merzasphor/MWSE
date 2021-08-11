# meshLoaded



```lua
--- @type e event.meshLoaded
local function meshLoadedCallback(e)
end
event.register("meshLoaded", meshLoadedCallback)
```

This event can be filtered based on the **`path`** event data.

## Event Data

* `path` (string): The path to the mesh, relative to Data Files\Meshes
* `node` ([niAVObject](../../types/niAVObject)): 

