# debug

This is an extension of Lua Debug library.

## Functions

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

