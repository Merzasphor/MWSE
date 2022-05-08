# tes3fader

An object that applies a graphical effect on the screen, such as screen glare or damage coloring.

## Properties

### `active`

The activation state for the fader. Setting this effectively calls activate/deactivate.

**Returns**:

* `result` (boolean)

***

## Methods

### `activate`

Activates a deactivated fader.

```lua
myObject:activate()
```

***

### `deactivate`

Deactivates an activated fader.

```lua
myObject:deactivate()
```

***

### `fadeIn`

Transitions the fader to a value of `1` over a given duration.

```lua
myObject:fadeIn({ duration = ... })
```

**Parameters**:

* `params` (table)
	* `duration` (number): *Default*: `1`. The time it takes to fade, in seconds.

***

### `fadeOut`

Transitions the fader to a value of `0` over a given duration.

```lua
myObject:fadeOut({ duration = ... })
```

**Parameters**:

* `params` (table)
	* `duration` (number): *Default*: `1`. The time it takes to fade, in seconds.

***

### `fadeTo`

Transitions the fader to a value over a given duration.

```lua
myObject:fadeTo({ value = ..., duration = ... })
```

**Parameters**:

* `params` (table)
	* `value` (number): *Default*: `1`. The value to fade to.
	* `duration` (number): *Default*: `1`. The time it takes to fade, in seconds.

***

### `setColor`

Applies a coloring effect to the fader.

```lua
local result = myObject:setColor({ color = ..., flag = ... })
```

**Parameters**:

* `params` (table)
	* `color` ([tes3vector3](../../types/tes3vector3), table): The RGB values to set.
	* `flag` (boolean)

**Returns**:

* `result` (boolean)

***

### `setTexture`

This method allows changing the texture of the fader.

```lua
myObject:setTexture(path)
```

**Parameters**:

* `path` (string): A path for the texture that will be displayed on screen.

***

### `update`

Updates the fader for the current frame.

```lua
myObject:update()
```

***

### `updateMaterialProperty`

Updates the fader for the current frame.

```lua
myObject:updateMaterialProperty(value)
```

**Parameters**:

* `value` (number)

***

## Functions

### `new`

Creates a new fader, and adds it to the fader system.

```lua
local result = tes3fader.new()
```

**Returns**:

* `result` ([tes3fader](../../types/tes3fader))

***

