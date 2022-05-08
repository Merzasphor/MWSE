# tes3vector4

A set of 4 floating-point numbers. You can perform following arithmetic with this type: `+`, `-`, and `*`.

## Properties

### `w`

The 1st value in the vector.

**Returns**:

* `result` (number)

***

### `x`

The 2nd value in the vector.

**Returns**:

* `result` (number)

***

### `y`

The 3rd value in the vector.

**Returns**:

* `result` (number)

***

### `z`

The 4th value in the vector.

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

* `result` ([tes3vector4](../../types/tes3vector4))

***

### `length`

Calculates the length of the vector.

```lua
local result = myObject:length()
```

**Returns**:

* `result` (number)

***

## Functions

### `new`

Creates a new vector. If no parameters are provided, an empty set will be constructed.

```lua
local vector = tes3vector4.new(x, y, z, w)
```

**Parameters**:

* `x` (number): *Optional*.
* `y` (number): *Optional*.
* `z` (number): *Optional*.
* `w` (number): *Optional*.

**Returns**:

* `vector` ([tes3vector4](../../types/tes3vector4))

***

