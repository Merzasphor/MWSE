--- @meta
--- @diagnostic disable:undefined-doc-name

--- A container object that has not been cloned. Typically represents the raw information edited in the construction set.
--- @class tes3container : tes3actor, tes3physicalObject, tes3object, tes3baseObject
--- @field capacity number The amount of weight that the container can hold.
--- @field isInstance boolean Always returns false.
--- @field mesh string The path to the object's mesh.
--- @field name string The player-facing name for the object.
--- @field organic boolean Determines if the container's organic flag is enabled.
--- @field respawns boolean Determines if the container's respawn flag is enabled.
--- @field script tes3script The script that runs on the object.
tes3container = {}

--- Creates a copy of this object.
--- @param params tes3container.createCopy.params This table accepts the following values:
--- 
--- `id`: string? — *Optional*. The new object's ID. If one is not provided, a randomly generated one will be used.
--- 
--- `addToObjectList`: boolean? — *Default*: `true`. If true, the object will be added to the data handler. If this is false, the new object may not have a randomly generated ID. Do not use this without knowing the implications.
--- 
--- `sourceless`: boolean? — *Default*: `false`. If true, the object will be made sourceless, and will not be serialized to the save game. If the object is copied outside of a save game, the object will **always** be sourceless.
--- @return tes3container newObject No description yet available.
function tes3container:createCopy(params) end

---Table parameter definitions for `tes3container.createCopy`.
--- @class tes3container.createCopy.params
--- @field id string? *Optional*. The new object's ID. If one is not provided, a randomly generated one will be used.
--- @field addToObjectList boolean? *Default*: `true`. If true, the object will be added to the data handler. If this is false, the new object may not have a randomly generated ID. Do not use this without knowing the implications.
--- @field sourceless boolean? *Default*: `false`. If true, the object will be made sourceless, and will not be serialized to the save game. If the object is copied outside of a save game, the object will **always** be sourceless.

