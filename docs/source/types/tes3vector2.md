# tes3vector2

A simple pair of floating-point numbers. You can perform following arithmetic with this type: `+`, `-`, and `*`.

## Properties

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

## Methods

### `copy`

Creates a copy of the vector.

```lua
local result = myObject:copy()
```

**Returns**:

* `result` ([tes3vector2](../../types/tes3vector2))

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
local vector = tes3vector2.new(x, y)
```

**Parameters**:

* `x` (number): *Optional*.
* `y` (number): *Optional*.

**Returns**:

* `vector` ([tes3vector2](../../types/tes3vector2))

***

