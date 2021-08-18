# os

Provides various OS-specific functions.

## Functions

### `os.clock`

Return CPU time since Lua started in seconds.

```lua
local result = os.clock()
```

**Returns**:

* `result` (number)

***

### `os.execute`

Passes command to be executed by an operating system shell. This will not display a console prompt that interrupts the game.

```lua
local exitCode, executor = os.execute(command, async)
```

**Parameters**:

* `command` (string): The command to run.
* `async` (boolean): *Default*: `false`. If set to true, the program will be run in a separate thread. The second return value, `executor`, can be used to monitor its execution.

**Returns**:

* `exitCode` (number): The exit code of the program. If running with `async` and if successful, the exit code will be STILL_ACTIVE (259).
* `executor` ([mwseLuaExecutor](../../types/mwseLuaExecutor), nil): If running with `async`, and if successful, this is a handle to the executor. This can be used to check if the program has finished running and to get the program's output.

***

### `os.getClipboardText`

Returns the current clipboard text, if any is available.

```lua
local result = os.getClipboardText()
```

**Returns**:

* `result` (string, nil)

***

### `os.setClipboardText`

Sets the current clipboard text. If nil is passed, the clipboard will be cleared instead. If either operation fails, the function returns false.

```lua
local result = os.setClipboardText(text)
```

**Parameters**:

* `text` (string, nil): *Optional*. The text to put in the clipboard. If nil is provided instead, then the clipboard will be cleared.

**Returns**:

* `result` (boolean)

***

