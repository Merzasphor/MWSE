--- @meta

--- Orients an axis of the controlled object towards a lookAt target. The axis is selectable.
--- 
--- Warning: The lookAt property is not reference counted, so this controller must be removed, or lookAt set to nil before the lookAt object is deleted.
--- @class niLookAtController : niTimeController, niObject
--- @field axis number A number representing the axis that points at the lookAt object. `flip` determines which end of this axis points at the target.
--- `0` X axis
--- `1` Y axis
--- `2` Z axis
--- @field flip boolean Determines which end of the chosen axis points towards the lookAt target.
--- @field lookAt niAmbientLight|niBillboardNode|niCamera|niCollisionSwitch|niDirectionalLight|niDynamicEffect|niGeometry|niLight|niNode|niPointLight|niSpotLight|niSwitchNode|niTriBasedGeometry|niTriShape The object that this controller will point towards. This is not a reference counted pointer, so this controller must be removed or lookAt set to nil before the lookAt object is deleted. This was probably designed to avoid reference cycles where controllers keep an ancestor node alive.
niLookAtController = {}

