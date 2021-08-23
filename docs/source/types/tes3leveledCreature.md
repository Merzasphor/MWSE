# tes3leveledCreature

A leveled creature game object.

This type inherits the following: [tes3physicalObject](../../types/tes3physicalObject), [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
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

### `calculateFromAllLevels`

If true, the leveled list is picked from the entire level range, instead of just the highest.

**Returns**:

* `result` (boolean)

***

### `chanceForNothing`

The percent chance, from 0 to 100, for no object to be chosen.

**Returns**:

* `result` (number)

***

### `count`

*Read-only*. The number of possible options in the leveled object container.

**Returns**:

* `result` (number)

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

### `flags`

A numerical representation of bit flags for the object.

**Returns**:

* `result` (number)

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

### `list`

*Read-only*. The collection that itself, containing tes3leveledListNodes.

**Returns**:

* `result` ([tes3iterator](../../types/tes3iterator))

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

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

*Read-only*. The type of object. Maps to values in tes3.objectType.

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

## Methods

### `__tojson`

Serializes the object to json.

```lua
local string = tes3baseObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `insert`

This function inserts given creature in the creature leveled list. True is returned if the operation was successful.

```lua
local result = tes3leveledCreature:insert(entry, level)
```

**Parameters**:

* `entry` ([tes3baseObject](../../types/tes3baseObject)): A creature to insert.
* `level` (number): At which player level the creature can be resolved from the leveled list.

**Returns**:

* `result` (boolean)

***

### `pickFrom`

Chooses a random item from the list, based on the player's level.

```lua
local result = tes3leveledCreature:pickFrom()
```

**Returns**:

* `result` ([tes3creature](../../types/tes3creature))

***

### `remove`

This function removes a creature from the creature leveled list. True is returned if the operation was successful.

```lua
local result = tes3leveledCreature:remove(entry, level)
```

**Parameters**:

* `entry` ([tes3baseObject](../../types/tes3baseObject)): A creature to remove.
* `level` (number): At which player level the creature could be resolved from the leveled list.

**Returns**:

* `result` (boolean)

***

