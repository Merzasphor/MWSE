# meshLoaded

This event is triggered when a mesh is loaded.

```lua
--- @param e meshLoadedEventData
local function meshLoadedCallback(e)
end
event.register(tes3.event.meshLoaded, meshLoadedCallback)
```

!!! tip
	This event can be filtered based on the **`path`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `node` ([niAVObject](../../types/niAVObject)): The niAVObject-derived object of the loaded mesh.
* `path` (string): The path to the mesh, relative to Data Files\Meshes

