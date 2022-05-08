# tes3vector3

A simple trio of floating-point numbers. You can perform following arithmetic with this type: `+`, `-`, and `*`.

## Properties

### `angle`

The angle between the vector and the water plane.

**Returns**:

* `result` (number)

***

### `b`

The third value in the vector. An alias for `z`.

**Returns**:

* `result` (number)

***

### `g`

The second value in the vector. An alias for `y`.

**Returns**:

* `result` (number)

***

### `r`

The first value in the vector. An alias for `x`.

**Returns**:

* `result` (number)

***

### `x`

The first value in the vector.

**Returns**:

* `result` (number)

***

### `y`

The second value in the vector.

**Returns**:

* `result` (number)

***

### `z`

The third value in the vector.

**Returns**:

* `result` (number)

***

## Methods

### `copy`

Creates a copy of the vector.

```lua
local result = myObject:copy()
```

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `cross`

Calculates the cross product with another vector.

```lua
local result = myObject:cross(vec)
```

**Parameters**:

* `vec` ([tes3vector3](../../types/tes3vector3))

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `distance`

Calculates the distance to another vector.

```lua
local result = myObject:distance(vec)
```

**Parameters**:

* `vec` ([tes3vector3](../../types/tes3vector3))

**Returns**:

* `result` (number)

***

### `dot`

Calculates the dot product with another vector.

```lua
local result = myObject:dot(vec)
```

**Parameters**:

* `vec` ([tes3vector3](../../types/tes3vector3))

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `heightDifference`

Calculates the vertical distance to another vector.

```lua
local result = myObject:heightDifference(vec)
```

**Parameters**:

* `vec` ([tes3vector3](../../types/tes3vector3))

**Returns**:

* `result` (number)

***

### `interpolate`

Calculates the interpolated position against the target vector using the `distance` parameter.

```lua
local result = myObject:interpolate(targetPoint, distance)
```

**Parameters**:

* `targetPoint` ([tes3vector3](../../types/tes3vector3))
* `distance` (number)

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `length`

Calculates the length of the vector.

```lua
local result = myObject:length()
```

**Returns**:

* `result` (number)

***

### `lerp`

Calculates the interpolated vector between this vector and another, given a transition.

```lua
local lerpedVector = myObject:lerp(toVector, transition)
```

**Parameters**:

* `toVector` ([tes3vector3](../../types/tes3vector3)): The vector to interpolate towards.
* `transition` (number): The interpolation value. Must be between `0.0` (closer to this vector) and `1.0` (closer to the other vector).

**Returns**:

* `lerpedVector` ([tes3vector3](../../types/tes3vector3)): The calculated value.

***

### `negate`

Negates all values in the vector.

```lua
myObject:negate()
```

***

### `normalize`

Normalize the vector in-place, or set its components to zero if normalization is not possible. Returns `true` if the vector was successfully normalized.

```lua
local result = myObject:normalize()
```

**Returns**:

* `result` (boolean)

***

### `normalized`

Get a normalized copy of the vector.

```lua
local result = myObject:normalized()
```

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `outerProduct`

Calculates the outer product with another vector.

```lua
local result = myObject:outerProduct(vec)
```

**Parameters**:

* `vec` ([tes3vector3](../../types/tes3vector3))

**Returns**:

* `result` ([tes3matrix33](../../types/tes3matrix33))

***

### `toColor`

Converts the vector to `niColor` object.

```lua
local result = myObject:toColor()
```

**Returns**:

* `result` ([niColor](../../types/niColor))

***

## Functions

### `new`

Creates a new vector. If no parameters are provided, an empty set will be constructed.

```lua
local vector = tes3vector3.new(x, y, z)
```

**Parameters**:

* `x` (number): *Optional*.
* `y` (number): *Optional*.
* `z` (number): *Optional*.

**Returns**:

* `vector` ([tes3vector3](../../types/tes3vector3))

***

