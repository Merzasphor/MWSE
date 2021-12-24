--- @meta

--- An alchemy game object.
--- @class tes3alchemy : tes3item, tes3physicalObject, tes3object, tes3baseObject
--- @field autoCalc boolean If set, the value of the object is automatically calculated.
--- @field effects table *Read-only*. An array-style table of the [`tes3effect`](https://mwse.github.io/MWSE/types/tes3effect/) data on the object.
--- @field flags number The alchemy item's flags.
--- @field icon string The path to the object's icon.
--- @field mesh string The path to the object's mesh.
--- @field name string The player-facing name for the object.
--- @field script tes3script The script that runs on the object.
--- @field value number The value of the object. For this object type, its maximum value is 65535. Larger numbers will overflow.
--- @field weight number The weight of the object.
tes3alchemy = {}

--- Creates a new alchemy item, which will be stored as part of the current saved game. If there is already an alchemy item with matching effects, name, weight, value, and script, that will be returned instead of creating a new item.
--- @param params tes3alchemy.create.params This table accepts the following values:
--- 
--- `id`: string — The new object's ID. Must be unique.
--- 
--- `name`: string — *Default*: `"Potion"`. The new item's name.
--- 
--- `script`: tes3script — *Optional*. A script to attach to the object.
--- 
--- `mesh`: string — *Default*: `"m\Misc_Potion_Bargain_01.nif"`. The mesh to use for the object.
--- 
--- `icon`: string — *Default*: `"m\Tx_potion_bargain_01.nif"`. The icon to use for the object.
--- 
--- `objectFlags`: number — *Default*: `8`. The object flags initially set. Force set as modified.
--- 
--- `weight`: number — *Default*: `0`. The new item's weight.
--- 
--- `value`: number — *Default*: `0`. The new item's value.
--- 
--- `flags`: number — *Default*: `0`. The new alchemy item's flags.
--- 
--- `effects`: table — A table of effects described, providing values for id, skill, attribute, range, radius, duration, min, and/or max.
function tes3alchemy.create(params) end

---Table parameter definitions for `tes3alchemy.create`.
--- @class tes3alchemy.create.params
--- @field id string The new object's ID. Must be unique.
--- @field name string *Default*: `"Potion"`. The new item's name.
--- @field script tes3script *Optional*. A script to attach to the object.
--- @field mesh string *Default*: `"m\Misc_Potion_Bargain_01.nif"`. The mesh to use for the object.
--- @field icon string *Default*: `"m\Tx_potion_bargain_01.nif"`. The icon to use for the object.
--- @field objectFlags number *Default*: `8`. The object flags initially set. Force set as modified.
--- @field weight number *Default*: `0`. The new item's weight.
--- @field value number *Default*: `0`. The new item's value.
--- @field flags number *Default*: `0`. The new alchemy item's flags.
--- @field effects table A table of effects described, providing values for id, skill, attribute, range, radius, duration, min, and/or max.

--- Returns the amount of effects the tes3alchemy object has.
--- @return number count No description yet available.
function tes3alchemy:getActiveEffectCount() end

--- Returns the index of a first effect of a given effectId in the parent tes3alchemy object.
--- @param effectId number The effectId to perform a check for. Maps to [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) constants.
--- @return number index No description yet available.
function tes3alchemy:getFirstIndexOfEffect(effectId) end

