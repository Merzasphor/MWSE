# mwseLuaExecutor

A handle to a command excuted using `os.execute` configured to run asynchronously.

## Properties

### `command`

The command originally passed to `os.execute`.

**Returns**:

* `result` (string)

***

### `errorCode`

The error code of the program, or 0 if there was no error.

**Returns**:

* `result` (number)

***

### `exitCode`

The exit code of the program, or nil if the program has not yet finished.

**Returns**:

* `result` (number, nil)

***

### `ready`

If true, the program is no longer running and output can be read.

**Returns**:

* `result` (boolean)

***

## Methods

### `getOutput`

Reads the current output of the program, and clears the output buffer.

```lua
local output = mwseLuaExecutor:getOutput()
```

**Returns**:

* `output` (string): The output written to stdout by the program.

***

### `wait`

Pauses the main thread, locking up the program until the program has finished.

```lua
mwseLuaExecutor:wait()
```

***

