# vfxCreated

The vfxCreated event fires when a managed visual effect is created by the game engine or through `tes3.createVisualEffect`.

```lua
--- @param e vfxCreatedEventData
local function vfxCreatedCallback(e)
end
event.register(tes3.event.vfxCreated, vfxCreatedCallback)
```

!!! tip
	An event can be claimed by setting `e.claim` to `true`, or by returning `false` from the callback. Claiming the event prevents any lower priority callbacks from being called.

## Event Data

* `context` (string): *Read-only*. Context for what type of VFX this was created at. For example, if the VFX was created at a position the value will be `tes3.vfxContext.position`, while an effect created onto the caster's hands will be created with the context of a `tes3.vfxContext.niNode`. This maps to the values in `tes3.vfxContext`.
* `vfx` ([tes3vfx](../../types/tes3vfx)): *Read-only*. The created visual effect.

