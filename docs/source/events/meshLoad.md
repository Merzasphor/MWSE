# meshLoad

This event is triggered before a mesh is loaded. The path can be changed to instead load a different mesh.

```lua
--- @param e meshLoadEventData
local function meshLoadCallback(e)
end
event.register(tes3.event.meshLoad, meshLoadCallback)
```

!!! tip
	This event can be filtered based on the **`path`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `path` (string): The path to the mesh, relative to Data Files\Meshes

