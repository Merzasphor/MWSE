# niPickRecord

A nested class of NiPick that stores the results of previous picking operations for use by the game engine.

## Properties

### `color`

The vertex color at the point of intersection. The color is valid only when `returnColor = true`.

**Returns**:

* `result` (number)

***

### `distance`

The distance of the triangle intersection from the ray origin.

**Returns**:

* `result` (number)

***

### `intersection`

The intersection point on the triangle.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `normal`

The normal vector at the point of intersection. The normal is valid only when `returnNormal = true`.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `object`

*Read-only*. The object of the record.

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `parent`

*Read-only*. The parent of the record.

**Returns**:

* `result` ([niAVObject](../../types/niAVObject))

***

### `reference`

Quick reference to the associated object's reference.

**Returns**:

* `result` ([tes3reference](../../types/tes3reference))

***

### `texture`

The texture coordinates at the point of intersection. The coordinates are valid only when `returnTexture = true`.

**Returns**:

* `result` ([tes3vector2](../../types/tes3vector2))

***

### `triangleIndex`

The index of the intersected triangle.

**Returns**:

* `result` (number)

***

### `vertexIndex`

The index of the vertex of the intersected triangle.

**Returns**:

* `result` (number)

***

