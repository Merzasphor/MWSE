--- @meta

--- A core miscellaneous object.
--- @class tes3misc : tes3item, tes3physicalObject, tes3object, tes3baseObject
--- @field icon string The path to the object's icon.
--- @field isGold boolean True if the misc item is a valid form of gold.
--- @field isKey boolean Access to the flag determining if this item is recognized as a key.
--- @field isSoulGem boolean *Read-only*. Determines if this item is a soul gem.
--- @field mesh string The path to the object's mesh.
--- @field name string The player-facing name for the object.
--- @field script tes3script *Read-only*. The script that runs on the object.
--- @field soulGemCapacity number *Read-only*. Fetches capacity of the soul gem, if this item is a soul gem.
--- @field soulGemData tes3soulGemData *Read-only*. Fetches related soul gem data, if this item is a soul gem.
--- @field value number The value of the object.
--- @field weight number The weight of the object.
tes3misc = {}

--- Use `tes3.createObject` instead. This function created a new misc item object, which will be stored as part of the current saved game.
--- @deprecated
--- @param params tes3misc.create.params This table accepts the following values:
--- 
--- `id`: string — *Optional*. The new object's ID. Must be unique if provided.
--- 
--- `name`: string — *Default*: `Miscellaneous item`. The new object's name.
--- 
--- `script`: tes3script — *Optional*. A script to attach to the object.
--- 
--- `mesh`: string — *Default*: ``. The mesh to use for the object.
--- 
--- `objectFlags`: number — *Default*: `0`. The object flags initially set. Force set as modified.
--- 
--- `weight `: tes3script — *Default*: `0`. The weight of the object.
--- 
--- `value `: string — *Default*: `0`. The value of the object.
--- 
--- `flags `: number — *Default*: `0`. The object flags initially set.
function tes3misc.create(params) end

---Table parameter definitions for `tes3misc.create`.
--- @class tes3misc.create.params
--- @field id string *Optional*. The new object's ID. Must be unique if provided.
--- @field name string *Default*: `Miscellaneous item`. The new object's name.
--- @field script tes3script *Optional*. A script to attach to the object.
--- @field mesh string *Default*: ``. The mesh to use for the object.
--- @field objectFlags number *Default*: `0`. The object flags initially set. Force set as modified.
--- @field weight  tes3script *Default*: `0`. The weight of the object.
--- @field value  string *Default*: `0`. The value of the object.
--- @field flags  number *Default*: `0`. The object flags initially set.

