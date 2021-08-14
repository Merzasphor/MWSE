--- @meta

--- This event fires when a SceneNode is created for a reference.
--- @class referenceSceneNodeCreatedEventData
--- @field claim boolean If set to `true`, any lower-priority event callbacks will be skipped. Returning `false` will set this to `true`.
--- @field reference tes3reference *Read-only*. Reference that the SceneNode was created for.
