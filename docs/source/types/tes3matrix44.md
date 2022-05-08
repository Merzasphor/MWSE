# tes3matrix44

A 4 by 4 matrix. You can perform following arithmetic with this type: `+`, `-`, `*`, and `==`.

## Properties

### `w`

The 1st row of the matrix.

**Returns**:

* `result` ([tes3vector4](../../types/tes3vector4))

***

### `x`

The 2nd row of the matrix.

**Returns**:

* `result` ([tes3vector4](../../types/tes3vector4))

***

### `y`

The 3rd row of the matrix.

**Returns**:

* `result` ([tes3vector4](../../types/tes3vector4))

***

### `z`

The 4th row of the matrix.

**Returns**:

* `result` ([tes3vector4](../../types/tes3vector4))

***

## Methods

### `copy`

Creates a copy of the matrix.

```lua
local result = myObject:copy()
```

**Returns**:

* `result` ([tes3matrix44](../../types/tes3matrix44))

***

### `toZero`

Zeroes out all values in the matrix.

```lua
myObject:toZero()
```

***

## Functions

### `new`

Creates a new 4 by 4 matrix from 4 provided vectors, 16 numbers or creates an empty matrix if nothing is provided.

```lua
local matrix = tes3matrix44.new(x0, y0, z0, w0, x1, y1, z1, w1, x2, y2, z2, w2, x3, y3, z3, w3, x, y, z, w)
```

**Parameters**:

* `x0` (number): *Optional*.
* `y0` (number): *Optional*.
* `z0` (number): *Optional*.
* `w0` (number): *Optional*.
* `x1` (number): *Optional*.
* `y1` (number): *Optional*.
* `z1` (number): *Optional*.
* `w1` (number): *Optional*.
* `x2` (number): *Optional*.
* `y2` (number): *Optional*.
* `z2` (number): *Optional*.
* `w2` (number): *Optional*.
* `x3` (number): *Optional*.
* `y3` (number): *Optional*.
* `z3` (number): *Optional*.
* `w3` (number): *Optional*.
* `x` ([tes3vector4](../../types/tes3vector4)): *Optional*.
* `y` ([tes3vector4](../../types/tes3vector4)): *Optional*.
* `z` ([tes3vector4](../../types/tes3vector4)): *Optional*.
* `w` ([tes3vector4](../../types/tes3vector4)): *Optional*.

**Returns**:

* `matrix` ([tes3matrix44](../../types/tes3matrix44))

***

