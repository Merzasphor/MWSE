# tes3misc

A core miscellaneous object.

This type inherits the following: [tes3item](../../types/tes3item), [tes3physicalObject](../../types/tes3physicalObject), [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

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

The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `icon`

The path to the object's icon.

**Returns**:

* `result` (string)

***

### `id`

The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `isKey`

Access to the flag determining if this item is recognized as a key.

**Returns**:

* `result` (boolean)

***

### `isSoulGem`

Determines if this item is a soul gem.

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

The raw flags of the object.

**Returns**:

* `result` (number)

***

### `objectType`

The type of object. Maps to values in tes3.objectType.

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

* `result` (tes3script)

***

### `soulGemCapacity`

Fetches capacity of the soul gem, if this item is a soul gem.

**Returns**:

* `result` (number)

***

### `soulGemData`

Fetches related soul gem data, if this item is a soul gem.

**Returns**:

* `result` ([tes3soulGemData](../../types/tes3soulGemData))

***

### `sourceless`

The soruceless flag of the object.

**Returns**:

* `result` (boolean)

***

### `sourceMod`

The filename of the mod that owns this object.

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

The value of the object.

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

### `isGold`

Returns true if the misc item is gold.

```lua
local isGold = tes3misc:isGold()
```

**Returns**:

* `isGold` (boolean)

***

## Functions

### `create`

Creates a new misc item object, which will be stored as part of the current saved game.

```lua
tes3misc.create({ id = ..., name = ..., script = ..., mesh = ..., objectFlags = ..., weight  = ..., value  = ..., flags  = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string): The new object's ID. Must be unique if provided.
	* `name` (string): The new object's name.
	* `script` (tes3script): A script to attach to the object.
	* `mesh` (string): The mesh to use for the object.
	* `objectFlags` (number): The object flags initially set. Force set as modified.
	* `weight ` (tes3script): The weight of the object.
	* `value ` (string): The value of the object.
	* `flags ` (number): The object flags initially set.

***

