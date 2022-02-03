# tes3uiFillBar

A structure containing properties specific to fillbars.

## Properties

### `current`

The current value. The size of the filled portion is determined by dividing `current` by `max`.

**Returns**:

* `result` (number)

***

### `fillAlpha`

The alpha value of `fillColor`. Setting this will also set the alpha value of `fillColor`.

**Returns**:

* `result` (number)

***

### `fillColor`

The RGB color of the filled portion. An array of 3 floats with value range [0.0, 1.0]. Does not affect the background or the border.

**Returns**:

* `result` (table)

***

### `max`

The maximum value. The size of the filled portion is determined by dividing `current` by `max`.

**Returns**:

* `result` (number)

***

### `showText`

If `true`, shows a centered text with the format `current/max` inside the fillbar.

**Returns**:

* `result` (boolean)

***

