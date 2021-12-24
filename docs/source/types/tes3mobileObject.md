# tes3mobileObject

The base object from which all other mobiles (AI/movement using) structures derive.

## Properties

### `boundSize`

A vector that shows the size of the bounding box in each direction. Note that this is a convenience feature, and delivers the `x` and `y` values from `boundSize2D` with the `z` value of the mobile's `height`. Editing the values of the returned vector will not change the values that they came from, though setting the property itself will work.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `boundSize2D`

A vector that shows the size of the bounding box in X and Y directions. `boundSize` is a convenience property that exposes the bounding in 3 dimensions.

**Returns**:

* `result` ([tes3vector2](../../types/tes3vector2))

***

### `cellX`

*Read-only*. The X grid coordinate of the cell the mobile is in.

**Returns**:

* `result` (number)

***

### `cellY`

*Read-only*. The Y grid coordinate of the cell the mobile is in.

**Returns**:

* `result` (number)

***

### `flags`

Access to the root mobile object flags, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `height`

The height of the mobile above the ground.

**Returns**:

* `result` (number)

***

### `impulseVelocity`

A vector that represents the 3D acceleration of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `movementCollision`

Controls if the mobile has movement collision active. When false, the mobile can move through any object, but can still block other mobiles, and can still be hit in combat. Actors will still follow pathgrids, ramps and stairs when navigating.

**Returns**:

* `result` (boolean)

***

### `movementFlags`

Access to the root mobile object movement flags, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `objectType`

*Read-only*. The type of mobile object. Maps to values in [`tes3.objectType`](https://mwse.github.io/MWSE/references/object-types/) namespace.

**Returns**:

* `result` (number)

***

### `playerDistance`

The distance to the player. Updated every frame when the mobile is in an active cell.

**Returns**:

* `result` (number)

***

### `position`

A vector that represents the 3D position of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `prevMovementFlags`

Access to the root mobile object movement flags from the previous frame, represented as an integer. Should not be accessed directly.

**Returns**:

* `result` (number)

***

### `reference`

*Read-only*. Access to the reference object for the mobile, if any.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `velocity`

A vector that represents the 3D velocity of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

