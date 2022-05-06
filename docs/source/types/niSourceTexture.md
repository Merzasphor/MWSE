# niSourceTexture

A texture that represent both static and dynamic content, as NiSourceTexture data objects can have their pixel data modified on the fly to implement dynamic texture behavior.

This type inherits the following: [niTexture](../../types/niTexture), [niObjectNET](../../types/niObjectNET), [niObject](../../types/niObject)
## Properties

### `controller`

*Read-only*. The first controller available on the object.

**Returns**:

* `result` ([niTimeController](../../types/niTimeController))

***

### `extraData`

*Read-only*. The first extra data available on the object.

**Returns**:

* `result` (niExtraData)

***

### `fileName`

*Read-only*. The platform-independent version of the filename from which the image was created, or NULL if the image was created from pixel data.

**Returns**:

* `result` (string)

***

### `formatPrefs`

The `NiFormatPrefs` of the texture.

**Returns**:

* `result` ([niFormatPrefs](../../types/niFormatPrefs))

***

### `height`

*Read-only*. The height of the texture.

**Returns**:

* `result` (number)

***

### `isStatic`

The static flag.

**Returns**:

* `result` (boolean)

***

### `name`

The human-facing name of the given object.

**Returns**:

* `result` (string)

***

### `pixelData`

The app-level pixel data.

**Returns**:

* `result` ([niPixelData](../../types/niPixelData))

***

### `platformFilename`

*Read-only*. The platform-specific version of the filename.

**Returns**:

* `result` (string)

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

### `width`

*Read-only*. The width of the texture.

**Returns**:

* `result` (number)

***

## Methods

### `clearPixelData`

Detaches any pixel data associated with this texture. Any render-specific data will be maintained, and remain in the GPU's memory.

```lua
myObject:clearPixelData()
```

***

### `clone`

Creates a copy of this object.

```lua
local result = myObject:clone()
```

**Returns**:

* `result` ([niObject](../../types/niObject))

***

### `getGameReference`

Searches for an niExtraData on this object to see if it has one that holds a related reference.

```lua
local reference = myObject:getGameReference(searchParents)
```

**Parameters**:

* `searchParents` (boolean): *Default*: `false`. If true, all parent objects (if applicable) are also searched.

**Returns**:

* `reference` ([tes3reference](../../types/tes3reference))

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

### `loadPixelDataFromFile`

Loads the file associated with the texture into memory, and makes it accessible from the pixelData property.

```lua
myObject:loadPixelDataFromFile()
```

***

### `prependController`

Add a controller to the object as the first controller.

```lua
myObject:prependController(type)
```

**Parameters**:

* `type` ([niTimeController](../../types/niTimeController))

***

### `removeAllControllers`

Removes all controllers.

```lua
myObject:removeAllControllers()
```

***

### `removeController`

Removes a controller from the object.

```lua
myObject:removeController(controller)
```

**Parameters**:

* `controller` ([niTimeController](../../types/niTimeController))

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

### `setFlag`

Sets a given flag in the niObjectNET flag data. The specifics use of the flag is dependent on the real underlying type.

```lua
myObject:setFlag(state, index)
```

**Parameters**:

* `state` (boolean)
* `index` (number)

***

## Functions

### `createFromPath`

Creates an NiSourceTexture from the given filepath.

```lua
niSourceTexture.createFromPath(path, useCached)
```

**Parameters**:

* `path` (string): The filepath of the texture to load.
* `useCached` (boolean): *Default*: `true`. If true, the texture will be stored in the normal texture source cache, so that multiple calls to the same path will return the same object. This behavior can be disabled if necessary.

***

