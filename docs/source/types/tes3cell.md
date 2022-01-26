# tes3cell

An exterior or interior game area.

This type inherits the following: [tes3baseObject](../../types/tes3baseObject)
## Properties

### `activators`

*Read-only*. One of the three reference collections for a cell.

**Returns**:

* `result` ([tes3referenceList](../../types/tes3referenceList))

***

### `actors`

*Read-only*. One of the three reference collections for a cell.

**Returns**:

* `result` ([tes3referenceList](../../types/tes3referenceList))

***

### `ambientColor`

The cell's ambient color. Only available on interior cells.

**Returns**:

* `result` ([tes3packedColor](../../types/tes3packedColor))

***

### `behavesAsExterior`

If true, the cell behaves as an exterior instead of an interior for certain properties. Only available on interior cells.

**Returns**:

* `result` (boolean)

***

### `blocked`

The blocked state of the object.

**Returns**:

* `result` (boolean)

***

### `cellFlags`

A numeric representation of the packed bit flags for the cell, typically accessed from other properties.

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

### `displayName`

The name of the cell as displayed on the in-game UI. For exterior cells without an assigned name, this is the region name.

**Returns**:

* `result` (string)

***

### `editorName`

The name of the cell as displayed in the Construction Set. For exterior cells, this includes the cell coordinates.

**Returns**:

* `result` (string)

***

### `fogColor`

The cell's fog color. Only available on interior cells.

**Returns**:

* `result` ([tes3packedColor](../../types/tes3packedColor))

***

### `fogDensity`

The cell's fog density. Only available on interior cells.

**Returns**:

* `result` (number)

***

### `gridX`

The cell's X grid coordinate. Only available on exterior cells.

**Returns**:

* `result` (number)

***

### `gridY`

The cell's Y grid coordinate. Only available on exterior cells.

**Returns**:

* `result` (number)

***

### `hasMapMarker`

*Read-only*. If true, the cell will have be marked on the player's map. This does not take into account if the player has been to that cell.

**Returns**:

* `result` (boolean)

***

### `hasWater`

If true, the cell has water. Only applies to interior cells.

**Returns**:

* `result` (boolean)

***

### `id`

*Read-only*. The unique identifier for the object.

**Returns**:

* `result` (string)

***

### `isInterior`

If true, the cell is an interior.

**Returns**:

* `result` (boolean)

***

### `isOrBehavesAsExterior`

*Read-only*. `true` if the cell is not an interior or if it behaves as an exterior.

**Returns**:

* `result` (boolean)

***

### `modified`

The modification state of the object since the last save.

**Returns**:

* `result` (boolean)

***

### `name`

The name and id of the cell. See also `displayName` and `editorName`.

**Returns**:

* `result` (string)

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

### `persistent`

The persistent flag of the object.

**Returns**:

* `result` (boolean)

***

### `pickObjectsRoot`

The scenegraph node containing player-interactable objects from this cell.

**Returns**:

* `result` ([niNode](../../types/niNode))

***

### `region`

The region associated with the cell. Only available on exterior cells, or interior cells that behave as exterior cells.

**Returns**:

* `result` ([tes3region](../../types/tes3region))

***

### `restingIsIllegal`

If true, the player may not rest in the cell.

**Returns**:

* `result` (boolean)

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

### `staticObjectsRoot`

The scenegraph node containing static non-player-interactable objects from this cell.

**Returns**:

* `result` ([tes3region](../../types/tes3region))

***

### `statics`

*Read-only*. One of the three reference collections for a cell.

**Returns**:

* `result` ([tes3referenceList](../../types/tes3referenceList))

***

### `sunColor`

The cell's sun color. Only available on interior cells.

**Returns**:

* `result` ([tes3packedColor](../../types/tes3packedColor))

***

### `supportsLuaData`

If true, references of this object can store temporary or persistent lua data.

**Returns**:

* `result` (boolean)

***

### `waterLevel`

The water level in the cell. Only available on interior cells.

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

### `isPointInCell`

Determines if a given X/Y coordinate falls in the given cell. This will always be true for interior cells.

```lua
local inCell = tes3cell:isPointInCell(x, y)
```

**Parameters**:

* `x` (number): The X position to test.
* `y` (number): The Y position to test.

**Returns**:

* `inCell` (boolean): true, if the point is found in the cell.

***

### `iterateReferences`

Used in a for loop, iterates over objects in the cell.

```lua
tes3cell:iterateReferences(filter)
```

**Parameters**:

* `filter` (number): *Optional*. The TES3 object type to filter results by. Those are stored in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) namespace.

***

