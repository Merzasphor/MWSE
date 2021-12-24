# tes3light

A core light object. This isn't actually a light in the rendering engine, but something like a lamp or torch.

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

### `canCarry`

Access to the light's flags, determining if the light can be carried.

**Returns**:

* `result` (boolean)

***

### `color`

*Read-only*. Access to the light's base colors, in an array-style table of four values. The values can range from 0 to 255.

**Returns**:

* `result` (table)

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

### `flickers`

Access to the light's flags, determining if the light attenuation flickers.

**Returns**:

* `result` (boolean)

***

### `flickersSlowly`

Access to the light's flags, determining if the light attenuation flickers slowly.

**Returns**:

* `result` (boolean)

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

### `isDynamic`

Access to the light's flags, determining if the light affects dynamically moving objects.

**Returns**:

* `result` (boolean)

***

### `isFire`

Access to the light's flags, determining if the light represents flame.

**Returns**:

* `result` (boolean)

***

### `isLocationMarker`

True if this object is an editor marker for a gameplay location. These include travel, intervention, prison, door, and interior north markers. Markers are invisible in-game.

**Returns**:

* `result` (boolean)

***

### `isNegative`

Access to the light's flags, determining if the object creates darkness.

**Returns**:

* `result` (boolean)

***

### `isOffByDefault`

Access to the light's flags, determining if the light won't be active initially.

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

### `pulses`

Access to the light's flags, determining if the light attenuation pulses.

**Returns**:

* `result` (boolean)

***

### `pulsesSlowly`

Access to the light's flags, determining if the light attenuation pulses slowly.

**Returns**:

* `result` (boolean)

***

### `radius`

The base radius of the light.

**Returns**:

* `result` (number)

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

*Read-only*. The script that runs on the object.

**Returns**:

* `result` ([tes3script](../../types/tes3script))

***

### `sound`

*Read-only*. The sound that runs on the object.

**Returns**:

* `result` ([tes3sound](../../types/tes3sound))

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

### `time`

The amount of time that the light will last.

**Returns**:

* `result` (number)

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

### `getTimeLeft`

Gets the time remaining for a light, given a `tes3itemData`, `tes3reference`, or `tes3equipmentStack`.

```lua
local result = tes3light:getTimeLeft(data)
```

**Parameters**:

* `data` ([tes3reference](../../types/tes3reference), [tes3itemData](../../types/tes3itemData), [tes3equipmentStack](../../types/tes3equipmentStack))

**Returns**:

* `result` (number)

***

