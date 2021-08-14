# niMaterialProperty

A rendering property that controls the surface properties of objects affected by the property. These surface properties include translucency, ambient reflective color, diffuse reflective color, emissive color intensity, and specular color.

This type inherits the following: [niProperty](../../types/niProperty), [niObjectNET](../../types/niObjectNET), [niObject](../../types/niObject)
## Properties

### `alpha`

The alpha value of the material. Value should be between 0 - 1.

**Returns**:

* `result` (number)

***

### `ambient`

The ambient material color.

**Returns**:

* `result` ([niColor](../../types/niColor))

***

### `diffuse`

The diffuse material color.

**Returns**:

* `result` ([niColor](../../types/niColor))

***

### `emissive`

The emissive material color.

**Returns**:

* `result` ([niColor](../../types/niColor))

***

### `name`

The human-facing name of the given object.

**Returns**:

* `result` (string)

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

### `shininess`

The shine of the material. Value should be >= 0.

**Returns**:

* `result` (number)

***

### `specular`

The specular material color.

**Returns**:

* `result` ([niColor](../../types/niColor))

***

### `type`

The unique class identifier number of the given rendering property.

**Returns**:

* `result` (niPropertyType)

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

