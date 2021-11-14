# tes3armor

An armor game object.

This type inherits the following: [tes3item](../../types/tes3item), [tes3physicalObject](../../types/tes3physicalObject), [tes3object](../../types/tes3object), [tes3baseObject](../../types/tes3baseObject)
## Properties

### `armorRating`

The armor's defensive rating.

**Returns**:

* `result` (number)

***

### `armorScalar`

*Read-only*. No description yet available.

**Returns**:

* `result` (number)

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

### `maxCondition`

The object's maximum condition.

**Returns**:

* `result` (number)

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

*Read-only*. The type of object. Maps to values in tes3.objectType.

**Returns**:

* `result` (number)

***

### `owningCollection`

The collection responsible for holding this object.

**Returns**:

* `result` ([tes3referenceList](../../types/tes3referenceList))

***

### `parts`

*Read-only*. An array-style table of the tes3wearablePart data on the object.

**Returns**:

* `result` (table)

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

The slot used by the armor.

**Returns**:

* `result` (number)

***

### `slotName`

*Read-only*. The name of the slot used by the armor.

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

The value of the object.

**Returns**:

* `result` (number)

***

### `weight`

The weight of the object.

**Returns**:

* `result` (number)

***

### `weightClass`

*Read-only*. The weight class of the armor. This value maps to tes3.armorWeightClass.* constants.

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

### `calculateArmorRating`

Calculates what armor rating is provided for a given mobile actor.

```lua
tes3armor:calculateArmorRating(mobile)
```

**Parameters**:

* `mobile` ([tes3mobileActor](../../types/tes3mobileActor))

***

