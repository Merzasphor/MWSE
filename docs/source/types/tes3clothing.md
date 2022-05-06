# tes3clothing

A clothing game object.

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

*Read-only*. The deleted state of the object.

**Returns**:

* `result` (boolean)

***

### `disabled`

*Read-only*. The disabled state of the object.

**Returns**:

* `result` (boolean)

***

### `enchantCapacity`

The object's enchantment capacity.

**Returns**:

* `result` (number)

***

### `enchantment`

The enchantment used by the object.

**Returns**:

* `result` ([tes3enchantment](../../types/tes3enchantment))

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

### `isLeftPart`

Determines if the armor is the left part of a pair.

**Returns**:

* `result` (boolean)

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

### `parts`

An array-style table of the [`tes3wearablePart`](https://mwse.github.io/MWSE/types/tes3wearablePart/) data on the object.

**Returns**:

* `result` ([tes3wearablePart](../../types/tes3wearablePart)[])

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

### `slot`

The slot used by the clothing object. Maps to values in [`tes3.clothingSlot`](https://mwse.github.io/MWSE/references/clothing-slots/) namespace.

**Returns**:

* `result` (number)

***

### `slotName`

The name of the slot used by the clothing object.

**Returns**:

* `result` (string)

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
local string = myObject:__tojson()
```

**Returns**:

* `string` (string)

***

### `createCopy`

Creates a copy of this object.

```lua
local newObject = myObject:createCopy({ id = ..., addToObjectList = ..., sourceless = ... })
```

**Parameters**:

* `params` (table)
	* `id` (string): *Optional*. The new object's ID. If one is not provided, a randomly generated one will be used.
	* `addToObjectList` (boolean): *Default*: `true`. If true, the object will be added to the data handler. If this is false, the new object may not have a randomly generated ID. Do not use this without knowing the implications.
	* `sourceless` (boolean): *Default*: `false`. If true, the object will be made sourceless, and will not be serialized to the save game. If the object is copied outside of a save game, the object will **always** be sourceless.

**Returns**:

* `newObject` ([tes3clothing](../../types/tes3clothing))

***

