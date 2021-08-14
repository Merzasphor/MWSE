# niSourceTexture

Represents all texture objects that are created from a file or a block of in-memory pixel data. NiSourceTexture objects represent both static and dynamic content, as NiSourceTexture data objects can have their pixel data modified on the fly to implement dynamic texture behavior.

This type inherits the following: [niObjectNET](../../types/niObjectNET), [niObject](../../types/niObject)
## Properties

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

### `width`

*Read-only*. The width of the texture.

**Returns**:

* `result` (number)

***

## Methods

### `clearPixelData`

Detaches any pixel data associated with this texture. Any render-specific data will be maintained, and remain in the GPU's memory.

```lua
niSourceTexture:clearPixelData()
```

***

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

### `loadPixelDataFromFile`

Loads the file associated with the texture into memory, and makes it accessible from the pixelData property.

```lua
niSourceTexture:loadPixelDataFromFile()
```

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

## Functions

### `createFromPath`

Creates an NiSourceTexture from the given filepath.

```lua
niSourceTexture.createFromPath(path)
```

**Parameters**:

* `path` (string): The filepath of the texture to load.

***

