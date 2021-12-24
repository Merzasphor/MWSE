--- @meta

--- A static game object. A non-animated object like a building or rock.
--- 
--- There are special-case marker statics used for gameplay purposes, such as travel and intervention. Use the ``object.isLocationMarker`` property to detect these markers.
--- @class tes3static : tes3physicalObject, tes3object, tes3baseObject
--- @field mesh string The path to the object's mesh.
tes3static = {}

--- Use [`tes3.createObject()`](https://mwse.github.io/MWSE/apis/tes3/#tes3createobject) instead. This function creates a new static object, which will be stored as part of the current saved game.
--- @deprecated
--- @param params tes3static.create.params This table accepts the following values:
--- 
--- `id`: string — *Optional*. The new object's ID. Must be unique if provided.
--- 
--- `mesh`: string — *Default*: ``. The mesh to use for the object.
--- 
--- `objectFlags`: number — *Default*: `0`. The object flags initially set. Force set as modified.
function tes3static.create(params) end

---Table parameter definitions for `tes3static.create`.
--- @class tes3static.create.params
--- @field id string *Optional*. The new object's ID. Must be unique if provided.
--- @field mesh string *Default*: ``. The mesh to use for the object.
--- @field objectFlags number *Default*: `0`. The object flags initially set. Force set as modified.

