--- @meta

--- A body part game object.
--- @class tes3bodyPart : tes3physicalObject, tes3object, tes3baseObject
--- @field female boolean A flag that marks this body part as used for female actors.
--- @field mesh string The path to the object's mesh.
--- @field part number The part of the body occupied. Maps to values in [`tes3.partIndex`](https://mwse.github.io/MWSE/references/part-indices/) namespace.
--- @field partType number The layer the body part occupies. Maps to values in [`tes3.activeBodyPartLayer`](https://mwse.github.io/MWSE/references/active-body-part-layers/) namespace.
--- @field playable boolean A flag that marks this body part as selectable during character generation.
--- @field raceName string *Read-only*. The name of the race associated with this body part.
--- @field sceneNode niBillboardNode|niCollisionSwitch|niNode|niSwitchNode The NiNode-derived object for the object's loaded mesh.
--- @field vampiric boolean A flag that marks this body part as used for vampires.
tes3bodyPart = {}

