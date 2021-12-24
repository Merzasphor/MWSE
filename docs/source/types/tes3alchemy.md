# tes3alchemy

An alchemy game object.

This type inherits the following: [tes3item](../../types/tes3item), [tes3physicalObject](../../types/tes3physicalObject), [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `autoCalc`

If set, the value of the object is automatically calculated.

**Returns**:

* `result` (boolean)

***

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `boundingBox`

The bounding box for the object.

**Returns**:

* `result` ([tes3boundingBox](../../types/tes3boundingBox))

***

### `deleted`

*Read-only*. The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

*Read-only*. The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `effects`

*Read-only*. An array-style table of the [`tes3effect`](https://mwse.github.io/MWSE/types/tes3effect/) data on the object.

**Returns**:

* `result` (table)

***

### `flags`

The alchemy item's flags.

**Returns**:

* `result` (number)

***

### `icon`

The path to the object's icon.

**Returns**:

* `result` (string)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `isLocationMarker`

True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.

**Returns**:

* `result` (boolean)

***

### `mesh`

The path to the object's mesh.

**Returns**:

* `result` (string)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `name`

The player-facing name for the object.

**Returns**:

* `result` (string)

***

### `nextInCollection`

The next object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `objectFlags`

*Read-only*. The raw flags of the object.

**Returns**:

* `result` (number)

***

### `objectType`

*Read-only*. The type of object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/).

**Returns**:

* `result` (number)

***

### `owningCollection`

The collection responsible for holding this object.

**Returns**:

* `result` ([tes3referenceList](../../types/tes3referenceList))

***

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `previousInCollection`

The previous object in parent collection's list.

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `scale`

The object's scale.

**Returns**:

* `result` (number)

***

### `sceneCollisionRoot`

The scene graph node for this object's physics collision, if its mesh has a root collision node.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneNode`

The scene graph node for this object.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `sceneReference`

The scene graph reference node for this object.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `script`

The script that runs on the object.

**Returns**:

* `result` ([tes3script](../../types/tes3script))

***

### `sourceless`

The soruceless flag of the object.

**Returns**:

* `result` (boolean)

***

### `sourceMod`

*Read-only*. The filename of the mod that owns this object.

**Returns**:

* `result` (string)

***

### `stolenList`

A list of actors that the object has been stolen from.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `value`

The value of the object. For this object type, its maximum value is 65535. Larger numbers will overflow.

**Returns**:

* `result` (number)

***

### `weight`

The weight of the object.

**Returns**:

* `result` (number)

***

## Methods

### `__tojson`

Serializes the object to json.

```lua
local string = tes3baseObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `getActiveEffectCount`

Returns the amount of effects the tes3alchemy object has.

```lua
local count = tes3alchemy:getActiveEffectCount()
```

**Returns**:

* `count` (number)

***

### `getFirstIndexOfEffect`

Returns the index of a first effect of a given effectId in the parent tes3alchemy object.

```lua
local index = tes3alchemy:getFirstIndexOfEffect(effectId)
```

**Parameters**:

* `effectId` (number): The effectId to perform a check for. Maps to [`tes3.effect`](https://mwse.github.io/MWSE/references/magic-effects/) constants.

**Returns**:

* `index` (number)

***

## Functions

### `create`

Creates a new alchemy item, which will be stored as part of the current saved game. If there is already an alchemy item with matching effects, name, weight, value, and script, that will be returned instead of creating a new item.

```lua
tes3alchemy.create({ id = ..., name = ..., script = ..., mesh = ..., icon = ..., objectFlags = ..., weight = ..., value = ..., flags = ..., effects = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string): The new object's ID. Must be unique.
	* `name` (string): *Default*: `"Potion"`. The new item's name.
	* `script` ([tes3script](../../types/tes3script)): *Optional*. A script to attach to the object.
	* `mesh` (string): *Default*: `"m\Misc_Potion_Bargain_01.nif"`. The mesh to use for the object.
	* `icon` (string): *Default*: `"m\Tx_potion_bargain_01.nif"`. The icon to use for the object.
	* `objectFlags` (number): *Default*: `8`. The object flags initially set. Force set as modified.
	* `weight` (number): *Default*: `0`. The new item's weight.
	* `value` (number): *Default*: `0`. The new item's value.
	* `flags` (number): *Default*: `0`. The new alchemy item's flags.
	* `effects` (table): A table of effects described, providing values for id, skill, attribute, range, radius, duration, min, and/or max.

***

