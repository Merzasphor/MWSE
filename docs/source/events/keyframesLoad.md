# keyframesLoad

This event is triggered before a keyframes file is loaded. The path can be changed to instead load a different keyframes file.

```lua
--- @param e keyframesLoadEventData
local function keyframesLoadCallback(e)
end
event.register(tes3.event.keyframesLoad, keyframesLoadCallback)
```

!!! tip
	This event can be filtered based on the **`path`** event data.

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `path` (string): The path to the keyframes file, relative to Data Files\Meshes.
* `sequenceName` (string): The name of the associated NiSequence object.

