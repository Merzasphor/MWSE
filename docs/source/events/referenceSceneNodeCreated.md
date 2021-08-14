# referenceSceneNodeCreated

This event fires when a SceneNode is created for a reference.

```lua
--- @param e referenceSceneNodeCreatedEventData
local function referenceSceneNodeCreatedCallback(e)
end
event.register("referenceSceneNodeCreated", referenceSceneNodeCreatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): *Read-only*. Reference that the SceneNode was created for.

