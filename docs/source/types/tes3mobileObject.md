# tes3mobileObject

The base object from which all other mobiles (AI/movement using) structures derive.

## Properties

### `boundSize`

A vector that shows the size of the bounding box in each direction.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `cellX`

The X grid coordinate of the cell the mobile is in.

**Returns**:

* `result` (number)

***

### `cellY`

The Y grid coordinate of the cell the mobile is in.

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

The type of mobile object. Maps to values in tes3.objectType.

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

Access to the reference object for the mobile, if any.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `velocity`

A vector that represents the 3D velocity of the object.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

