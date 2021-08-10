# tes3transform

A rotation matrix, translation vector, and scale that marks an object's transformation.

## Properties

### `rotation`

The transform's rotation matrix.

**Returns**:

* `result` ([tes3matrix33](../../types/tes3matrix33))

***

### `scale`

The transform's scale.

**Returns**:

* `result` (number)

***

### `translation`

The transform's translation vector.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

## Methods

### `copy`

Creates a copy of the transform.

```lua
local result = tes3transform:copy()
```

**Returns**:

* `result` ([tes3transform](../../types/tes3transform))

***

