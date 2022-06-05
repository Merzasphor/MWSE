# mge.camera

Allows control of the camera.

## Properties

### `mge.camera.fov`

Horizontal FOV, in degrees.

**Returns**:

* `result` (number)

***

### `mge.camera.shakeAcceleration`

Camera shake acceleration. Camera shake must be enabled to see an effect.

**Returns**:

* `result` (number)

***

### `mge.camera.shakeEnable`

Set if camera shake is active.

**Returns**:

* `result` (boolean)

***

### `mge.camera.shakeMagnitude`

Camera shake magnitude. Camera shake must be enabled to see an effect.

**Returns**:

* `result` (number)

***

### `mge.camera.thirdPersonOffset`

The position offset (from the character) of the third person camera.

**Returns**:

* `result` ([tes3vector3](../../types/tes3vector3))

***

### `mge.camera.zoom`

Camera zoom multiplier. Default is 1.0. Camera zoom must be enabled to see an effect.

**Returns**:

* `result` (number)

***

### `mge.camera.zoomEnable`

Set if camera zoom is enabled.

**Returns**:

* `result` (number)

***

## Functions

### `mge.camera.stopZoom`

Stops any continuous camera zoom.

```lua
mge.camera.stopZoom()
```

***

### `mge.camera.zoomContinuous`

Sets up continuous camera zoom. The zoom speed starts at `rate`. The speed will approach `targetRate` over time, if provided.

```lua
mge.camera.zoomContinuous({ rate = ..., targetRate = ... })
```

**Parameters**:

* `params` (table)
	* `rate` (number): *Optional*.
	* `targetRate` (number): *Optional*.

***

### `mge.camera.zoomIn`

Zooms in by the specified amount, or by a small amount if no amount is provided.

```lua
mge.camera.zoomIn({ amount = ... })
```

**Parameters**:

* `params` (table)
	* `amount` (number): *Optional*.

***

### `mge.camera.zoomOut`

Zooms out by the specified amount, or by a small amount if no amount is provided.

```lua
mge.camera.zoomOut({ amount = ... })
```

**Parameters**:

* `params` (table)
	* `amount` (number): *Optional*.

***

