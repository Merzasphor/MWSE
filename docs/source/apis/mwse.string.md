# mwse.string

The mwse string library provides functions for interacting with mwscript string storage.

## Functions

### `mwse.string.create`

Creates a string in storage, and returns the numerical key for it.

If the string is already in storage, the previous key will be returned.

```lua
local result = mwse.string.create(unknown)
```

**Parameters**:

* `unnamed` (string)

**Returns**:

* `result` (number)

***

### `mwse.string.get`

Returns the numerical key for a given string in storage, or nil if the string isn't in storage.

```lua
local unnamed1 = mwse.string.get(unknown)
```

**Parameters**:

* `unnamed` (string)

**Returns**:

* `unnamed` (number): *Optional*.

***

