# debug

This is an extension of Lua Debug library.

## Properties

### `debug.logCache`

An table containing all the output values of `debug.log()`. The table index is `path` with the line number appended, while the table key is the message.

**Returns**:

* `result` (table)

***

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

