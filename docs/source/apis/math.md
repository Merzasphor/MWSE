# math

This library is an interface to the standard C math library. This library has been further extended by MWSE. The functions implemented by MWSE are listed here. It provides all its functions inside the table math.

## Properties

### `math.epsilon`

The *machine* epsilon available for double-precision numbers. This is the difference between 1.0 and the next representable value using lua numbers.

**Returns**:

* `result` (number)

***

### `math.fepsilon`

The *machine* epsilon available for single-precision numbers. This is the difference between 1.0 and the next representable value for many Morrowind structures.

**Returns**:

* `result` (number)

***

## Functions

### `math.clamp`

Returns a value, limited by upper and lower bounds.

```lua
local result = math.clamp(value, min, max)
```

**Parameters**:

* `value` (number)
* `min` (number)
* `max` (number)

**Returns**:

* `result` (number)

***

### `math.isclose`

This function compares `a` and `b` and returns true if they are close together. This can be useful when comparing floating-point numbers with some degree of tolerance.

```lua
local result = math.isclose(a, b, absoluteTolerance, relativeTolerance)
```

**Parameters**:

* `a` (number): First value.
* `b` (number): Second value.
* `absoluteTolerance` (number): *Default*: `math.epsilon`. The absolute difference allowed between the two numbers. A value of 0.01 will only allow the values to differ by 0.01.
* `relativeTolerance` (number): *Default*: `1e-09`. The relative difference allowed between the two numbers. A value of 0.01 will only allow the values to differ by 1%.

**Returns**:

* `result` (number)

***

### `math.lerp`

Performs linear interpolation between values v0 and v1. Returns a value that is t percent between them.

```lua
local result = math.lerp(v0, v1, t)
```

**Parameters**:

* `v0` (number): First value.
* `v1` (number): Second value.
* `t` (number): The decimal percentage used to calculate a point between v0 and v1.

**Returns**:

* `result` (number)

***

### `math.remap`

Returns a value, scaled from expected values [lowIn, highIn] to [lowOut, highOut].

For example, a value of 7 remapped from [0,10] to [0,100] would be 70.

```lua
local result = math.remap(value, lowIn, highIn, lowOut, highOut)
```

**Parameters**:

* `value` (number)
* `lowIn` (number)
* `highIn` (number)
* `lowOut` (number)
* `highOut` (number)

**Returns**:

* `result` (number)

***

### `math.round`

Rounds a number to a given count of digits.

```lua
local result = math.round(value, digits)
```

**Parameters**:

* `value` (number)
* `digits` (number)

**Returns**:

* `result` (number)

***

