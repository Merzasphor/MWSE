# referenceSceneNodeCreated

This event fires when a SceneNode is created for a reference.

```lua
--- @param e referenceSceneNodeCreatedEventData
local function referenceSceneNodeCreatedCallback(e)
end
event.register("referenceSceneNodeCreated", referenceSceneNodeCreatedCallback)
```

## Event Data

* `reference` ([tes3reference](../../types/tes3reference)): Reference that the SceneNode was created for.

