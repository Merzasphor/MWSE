# mge.shaders

Allows control of MGE shaders from MWSE. Features include dynamically adding shaders and setting variables.

## Properties

### `mge.shaders.hdrReactionSpeed`

The HDR exposure reaction speed, in seconds.

**Returns**:

* `result` (number)

***

### `mge.shaders.list`

Lists the currently loaded shaders.

**Returns**:

* `result` ([mgeShaderHandle](../../types/mgeShaderHandle)[])

***

## Functions

### `mge.shaders.find`

Finds a shader by name.

```lua
local result = mge.shaders.find(name)
```

**Parameters**:

* `name` (string): The shader name.

**Returns**:

* `result` ([mgeShaderHandle](../../types/mgeShaderHandle))

***

### `mge.shaders.load`

Loads a shader by name, from the `Data Files/shaders/XEshaders directory`. Adds the shader to the existing shader list, or returns the existing shader if it is already loaded.
	
	If the shader has a category annotation, it is inserted into a position that preserves the category ordering. e.g. A shader containing
	```... technique T < string MGEinterface = "MGE XE 0"; string category = "scene"; > ...``` has the "scene" category. Shaders without a category will be added to the end of the list.
	
	Summary of category sort order:
	scene - Additional objects rendered into the scene.
	atmosphere - Atmosphere effects that render over all objects, such as mist.
	lens - Lens effects such as depth of field.
	sensor - Sensor effects such as bloom.
	tone - Tone mapping and color grading.
	final - Any effects that need to run last.

```lua
local result = mge.shaders.load(name)
```

**Parameters**:

* `name` (string): The shader name.

**Returns**:

* `result` ([mgeShaderHandle](../../types/mgeShaderHandle))

***

