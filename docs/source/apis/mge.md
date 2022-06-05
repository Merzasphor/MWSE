# mge

The mge library accesses MGE XE functionality, including control over shaders. Many older functions have been deprecated.

## Functions

### `mge.enabled`

Determines if the MGE XE interface is enabled.

```lua
local enabled = mge.enabled()
```

**Returns**:

* `enabled` (boolean)

***

### `mge.getGUIScale`

Returns the exact GUI scaling used by MGE XE.

```lua
local result = mge.getGUIScale()
```

**Returns**:

* `result` (number)

***

### `mge.getScreenHeight`

Gets the window's vertical resolution. Wrapper for mwscript's MGEGetHeight.

```lua
local result = mge.getScreenHeight()
```

**Returns**:

* `result` (number)

***

### `mge.getScreenWidth`

Gets the window's horizontal resolution. Wrapper for mwscript's MGEGetWidth.

```lua
local result = mge.getScreenWidth()
```

**Returns**:

* `result` (number)

***

### `mge.getVersion`

Gets the MGE version. Wrapper for MGEGetVersion.

```lua
local result = mge.getVersion()
```

**Returns**:

* `result` (number)

***

