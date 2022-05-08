# mwseSafeObjectHandle

A handle to safely operate on ([tes3object](https://mwse.github.io/MWSE/types/tes3object/)).

## Methods

### `getObject`

Returns the object of this handle.

```lua
local result = myObject:getObject()
```

**Returns**:

* `result` ([tes3object](../../types/tes3object))

***

### `valid`

Returns true if the object of this handle is still valid. Objects that are invalid do no longer exist and cannot be used.

```lua
myObject:valid()
```

***

