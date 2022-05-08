# niKeyframeData

A collection of position, rotation, and scale keys used on NiKeyframeControllers.

This type inherits the following: [niObject](../../types/niObject)
## Properties

### `positionKeyCount`

*Read-only*. The number of position keys available.

**Returns**:

* `result` (number)

***

### `positionKeys`

*Read-only*. The available position keys.

**Returns**:

* `result` ([niPosKey](../../types/niPosKey)[])

***

### `positionType`

*Read-only*. The type of animation key used for position keys.

**Returns**:

* `result` (number)

***

### `refCount`

*Read-only*. The number of references that exist for this object. When this value reaches zero, the object will be deleted.

**Returns**:

* `result` (number)

***

### `references`

*Read-only*. The number of references that exist for the given object. When this value hits zero, the object's memory is freed.

**Returns**:

* `result` (string)

***

### `rotationKeyCount`

*Read-only*. The number of rotation keys available.

**Returns**:

* `result` (number)

***

### `rotationKeys`

*Read-only*. The available rotation keys.

**Returns**:

* `result` ([niRotKey](../../types/niRotKey)[])

***

### `rotationType`

*Read-only*. The type of animation key used for rotation keys.

**Returns**:

* `result` (number)

***

### `RTTI`

*Read-only*. The runtime type information for this object. This is an alias for the `.runTimeTypeInformation` property.

**Returns**:

* `result` ([niRTTI](../../types/niRTTI))

***

### `runTimeTypeInformation`

*Read-only*. The runtime type information for this object.

**Returns**:

* `result` ([niRTTI](../../types/niRTTI))

***

### `scaleKeyCount`

*Read-only*. The number of scale keys available.

**Returns**:

* `result` (number)

***

### `scaleKeys`

*Read-only*. The available scale keys.

**Returns**:

* `result` ([niFloatKey](../../types/niFloatKey)[])

***

### `scaleType`

*Read-only*. The type of animation key used for scale keys.

**Returns**:

* `result` (number)

***

## Methods

### `clone`

Creates a copy of this object.

```lua
local result = myObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

***

### `isInstanceOfType`

Determines if the object is of a given type, or of a type derived from the given type. Types can be found in the tes3.niType table.

```lua
local result = myObject:isInstanceOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `isOfType`

Determines if the object is of a given type. Types can be found in the tes3.niType table.

```lua
local result = myObject:isOfType(type)
```

**Parameters**:

* `type` (number)

**Returns**:

* `result` (boolean)

***

### `saveBinary`

Serializes the object, and writes it to the given file.

```lua
local success = myObject:saveBinary(path)
```

**Parameters**:

* `path` (string): The path to write the file at, relative to the Morrowind installation folder.

**Returns**:

* `success` (boolean): If true the object was successfully serialized.

***

