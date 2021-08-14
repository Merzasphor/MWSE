# niStencilProperty

A rendering property that controls the use of a stencil buffer when rendering. It also includes a draw-mode setting to allows the game engine to control the culling mode of a set of geometry.

This type inherits the following: [niProperty](../../types/niProperty), [niObjectNET](../../types/niObjectNET), [niObject](../../types/niObject)
## Properties

### `drawMode`

The drawing mode used to draw the object.

**Returns**:

* `result` (number)

***

### `enabled`

The value of the stencil buffer enable flag.

**Returns**:

* `result` (boolean)

***

### `failAction`

The action that is taken in the stencil buffer when the stencil test fails.

**Returns**:

* `result` (number)

***

### `mask`

The mask value of the stencil buffer.

**Returns**:

* `result` (number)

***

### `name`

The human-facing name of the given object.

**Returns**:

* `result` (string)

***

### `passAction`

The action that is taken in the stencil buffer when the stencil test passes and the pixel passes the Z-buffer test.

**Returns**:

* `result` (number)

***

### `reference`

The stencil reference.

**Returns**:

* `result` (number)

***

### `references`

*Read-only*. The number of references that exist for the given object. When this value hits zero, the object's memory is freed.

**Returns**:

* `result` (string)

***

### `runTimeTypeInformation`

The runtime type information for this object.

**Returns**:

* `result` ([niRTTI](../../types/niRTTI))

***

### `testFunc`

The stencil buffer test function used to test the reference value against the buffer value.

**Returns**:

* `result` (number)

***

### `type`

The unique class identifier number of the given rendering property.

**Returns**:

* `result` (niPropertyType)

***

### `zFailAction`

The action that is taken in the stencil buffer when the stencil test passes but the pixel fails the Z-buffer test.

**Returns**:

* `result` (number)

***

## Methods

### `clone`

Creates a copy of this object.

```lua
local result = niObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

***

### `isInstanceOfType`

Determines if the object is of a given type, or of a type derived from the given type. Types can be found in the tes3.niType table.

```lua
local result = niObject:isInstanceOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `isOfType`

Determines if the object is of a given type. Types can be found in the tes3.niType table.

```lua
local result = niObject:isOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `prependController`

Add a controller to the object as the first controller.

```lua
niObjectNET:prependController(type)
```

**Parameters**:

* `type` ([niTimeController](../../types/niTimeController))

***

### `removeAllControllers`

Removes all controllers.

```lua
niObjectNET:removeAllControllers()
```

***

### `removeController`

Removes a controller from the object.

```lua
niObjectNET:removeController(type)
```

**Parameters**:

* `type` ([niTimeController](../../types/niTimeController))

***

