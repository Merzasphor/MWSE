# niColorA

An object that represents a RGB color with alpha channel support.

## Properties

### `a`

The alpha value of the color.

**Returns**:

* `result` (number)

***

### `alpha`

The alpha value of the color.

**Returns**:

* `result` (number)

***

### `b`

The blue value of the color.

**Returns**:

* `result` (number)

***

### `blue`

Alias for the blue value of the color.

**Returns**:

* `result` (number)

***

### `g`

The green value of the color.

**Returns**:

* `result` (number)

***

### `green`

Alias for the green value of the color.

**Returns**:

* `result` (number)

***

### `r`

The red value of the color.

**Returns**:

* `result` (number)

***

### `red`

Alias for the red value of the color.

**Returns**:

* `result` (number)

***

## Methods

### `copy`

Creates a copy of the color object.

```lua
local result = niColorA:copy()
```

**Returns**:

* `result` ([niColorA](../../types/niColorA))

***

### `lerp`

Calculates the interpolated color between this color and another, given a transition.

```lua
local lerpedcolor = niColorA:lerp(tocolor, transition)
```

**Parameters**:

* `tocolor` ([niColorA](../../types/niColorA)): The color to interpolate towards.
* `transition` (number): The interpolation value. Must be between 0.0 (closer to this color) and 1.0 (closer to the other color).

**Returns**:

* `lerpedcolor` ([niColorA](../../types/niColorA)): The calculated value.

***

