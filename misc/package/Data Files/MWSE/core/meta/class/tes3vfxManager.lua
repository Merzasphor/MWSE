--- @meta
--- @diagnostic disable:undefined-doc-name

--- A manager for VFX lifetime and rendering. VFXs can be created through script with `tes3.createVisualEffect` and destroyed with `tes3.removeVisualEffect`.
--- @class tes3vfxManager
--- @field data tes3vfx[] A collection of active managed visual effects.
--- @field worldVFXRoot niBillboardNode|niCollisionSwitch|niNode|niSwitchNode The root node that general VFXs are attached to.
tes3vfxManager = {}

