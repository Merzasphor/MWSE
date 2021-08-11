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

* `text` (string, nil): The text to put in the clipboard. If nil is provided instead, then the clipboard will be cleared.

**Returns**:

* `result` (boolean)

***

