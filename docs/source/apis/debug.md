# debug

This is an extension of Lua Debug library.

## Functions

### `debug.clearLogCacheForFile`

Clears any prefix information from cache for use with `debug.log`. This is useful if your file loads dynamically via `dofile`, and is subject to change during development.

```lua
debug.clearLogCacheForFile(file)
```

**Parameters**:

* `file` (string?): The path to the file. If omitted, the calling file will have its associated log cache removed.

***

### `debug.log`

Logs a message to `MWSE.log` file. The output format is `[path] "msg" = msg`, where the `path` is the path and line at which the function was called.

```lua
local value = debug.log(value)
```

**Parameters**:

* `value` (string): The message to log.

**Returns**:

* `value` (string)

***

