# tes3matrix33

A 3 by 3 matrix. You can perform following arithmetic with this type: `+`, `-`, `*`, and `==`.

## Properties

### `x`

The first row of the matrix.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `y`

The second row of the matrix.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `z`

The third row of the matrix.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

## Methods

### `copy`

Creates a copy of the matrix.

```lua
local result = myObject:copy()
```

**Returns**:

* `result` ([tes3matrix33](../../types/tes3matrix33))

***

### `fromEulerXYZ`

Fills the matrix with values from euler coordinates.

```lua
myObject:fromEulerXYZ(x, y, z)
```

**Parameters**:

* `x` (number)
* `y` (number)
* `z` (number)

***

### `fromEulerZYX`

Fills the matrix with values from euler coordinates.

```lua
myObject:fromEulerZYX(z, y, x)
```

**Parameters**:

* `z` (number)
* `y` (number)
* `x` (number)

***

### `fromQuaternion`

Fill the matrix by converting a quaternion.

```lua
myObject:fromQuaternion(quaternion)
```

**Parameters**:

* `quaternion` ([niQuaternion](../../types/niQuaternion))

***

### `invert`

Inverts the matrix.

```lua
local matrix, valid = myObject:invert()
```

**Returns**:

* `matrix` ([tes3matrix33](../../types/tes3matrix33))
* `valid` (boolean)

***

### `reorthogonalize`

Reorthogonalizes the matrix.

```lua
local result = myObject:reorthogonalize()
```

**Returns**:

* `result` (boolean)

***

### `toEulerXYZ`

Converts the matrix to a vector with 3 Euler angles.

```lua
local isUnique, vector3 = myObject:toEulerXYZ()
```

**Returns**:

* `isUnique` (boolean)
* `vector3` ([tes3vector3](../../types/tes3vector3))

***

### `toEulerZYX`

Converts the matrix to a vector with 3 Euler angles.

```lua
local isUnique, vector3 = myObject:toEulerZYX()
```

**Returns**:

* `isUnique` (boolean)
* `vector3` ([tes3vector3](../../types/tes3vector3))

***

### `toIdentity`

Converts the matrix to the identity matrix's values.

```lua
myObject:toIdentity()
```

***

### `toQuaternion`

Convert the matrix into a quaternion.

```lua
local result = myObject:toQuaternion()
```

**Returns**:

* `result` ([niQuaternion](../../types/niQuaternion))

***

### `toRotation`

No description yet available.

```lua
myObject:toRotation(angle, x, y, z)
```

**Parameters**:

* `angle` (number)
* `x` (number)
* `y` (number)
* `z` (number)

***

### `toRotationX`

No description yet available.

```lua
myObject:toRotationX(x)
```

**Parameters**:

* `x` (number)

***

### `toRotationY`

No description yet available.

```lua
myObject:toRotationY(y)
```

**Parameters**:

* `y` (number)

***

### `toRotationZ`

No description yet available.

```lua
myObject:toRotationZ(z)
```

**Parameters**:

* `z` (number)

***

### `toZero`

Zeroes out all values in the matrix.

```lua
myObject:toZero()
```

***

### `transpose`

No description yet available.

```lua
local result = myObject:transpose()
```

**Returns**:

* `result` ([tes3matrix33](../../types/tes3matrix33))

***

## Functions

### `new`

Creates a new 3 by 3 matrix from 3 provided vectors, 9 numbers or creates an empty matrix if nothing is provided.

```lua
local matrix = tes3matrix33.new(x0, y0, z0, x1, y1, z1, x2, y2, z2, x, y, z)
```

**Parameters**:

* `x0` (number): *Optional*.
* `y0` (number): *Optional*.
* `z0` (number): *Optional*.
* `x1` (number): *Optional*.
* `y1` (number): *Optional*.
* `z1` (number): *Optional*.
* `x2` (number): *Optional*.
* `y2` (number): *Optional*.
* `z2` (number): *Optional*.
* `x` ([tes3vector3](../../types/tes3vector3)): *Optional*.
* `y` ([tes3vector3](../../types/tes3vector3)): *Optional*.
* `z` ([tes3vector3](../../types/tes3vector3)): *Optional*.

**Returns**:

* `matrix` ([tes3matrix33](../../types/tes3matrix33))

***

