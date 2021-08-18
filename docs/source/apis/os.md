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

### `os.createProcess`

Passes command to be executed by an operating system. Unlike `os.execute`, this will not display a console prompt that interrupts the game and cannot run direct shell commands.

```lua
local executor = os.createProcess({ command = ..., async = ... })
```

**Parameters**:

* `params` (table)
	* `command` (string): The command to run.
	* `async` (boolean): *Default*: `true`. If set to false, Morrowind will halt execution until the program finishes.

**Returns**:

* `executor` ([mwseLuaExecutor](../../types/mwseLuaExecutor)): A handle to the executor. This can be used to check if the program has errored, finished, and to get the program's output.

***

### `os.execute`

Passes command to be executed by an operating system shell. To open a program to run in the background and monitor its output, use `os.createProcess`.

```lua
local exitCode = os.execute(command)
```

**Parameters**:

* `command` (string): The command to run.

**Returns**:

* `exitCode` (number): The exit code of the program.

***

### `os.getClipboardText`

Returns the current clipboard text, if any is available.

```lua
local result = os.getClipboardText()
```

**Returns**:

* `result` (string, nil)

***

### `os.openURL`

Opens the given `url` in the default browser. This has an advantage over using `os.execute("show https://my.url")` in that it does not create a command prompt window.

```lua
os.openURL(url)
```

**Parameters**:

* `url` (string): The URL to open.

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

